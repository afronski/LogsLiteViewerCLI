#include "stdafx.h"

using namespace LogViewer::Logic;

void InputWatcher::createNewWatcher(String^ path, InputWatcher::FileType ft, unsigned int idx, bool activateNow, ProxyFileSystemDelegate^ eventHandler)
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
	
	_tabIndex = idx;
	
	_additionalEventHandler = eventHandler;		
	this->ProxyFileSystemEvent += _additionalEventHandler;
	
	_eventHandler = gcnew System::IO::FileSystemEventHandler(this, &InputWatcher::ProxyFileSystemDelgateImpl);

	_fileWatcher = gcnew FileSystemWatcher(path, filter);
	_fileWatcher->Changed += _eventHandler;
	_fileWatcher->EnableRaisingEvents = activateNow;
	_fileWatcher->NotifyFilter = System::IO::NotifyFilters::LastWrite;	
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