#include "stdafx.h"

using namespace LogViewer::Logic;

void InputWatcher::createNewWatcher(String^ path, InputWatcher::FileType ft, bool activateNow, System::IO::FileSystemEventHandler^ eventHandler)
{
	String^ filter;

	switch(ft)
	{ 
		case InputWatcher::FileType::FileType_Txt:
			filter = "*.txt";
			break;
		
		case InputWatcher::FileType::FileType_Xml:
			filter = "*.xml";
			break;
	}
	
	_eventHandler = eventHandler;

	_fileWatcher = gcnew FileSystemWatcher(path, filter);
	_fileWatcher->EnableRaisingEvents = activateNow;
	_fileWatcher->NotifyFilter = System::IO::NotifyFilters::LastWrite;
	_fileWatcher->Changed += _eventHandler;
}			

void InputWatcher::suspendWatcher()
{
	if (_fileWatcher)
	{
		_fileWatcher->EnableRaisingEvents = false;
	}
}

void InputWatcher::resumeWatcher()
{
	if (_fileWatcher)
	{
		_fileWatcher->EnableRaisingEvents = true;
	}	
}