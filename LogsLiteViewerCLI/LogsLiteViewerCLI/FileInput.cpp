#include "stdafx.h"

using namespace LogViewer::Logic;
using namespace LogViewer::Logic::Inputs;

FileInput::FileInput(): _path("")
{
	_watcher = gcnew InputWatcher();
}

FileInput::FileInput(String^ path, InputWatcher::FileType ft, System::IO::FileSystemEventHandler^ eventHandler): _path(path)
{
	_watcher = gcnew InputWatcher();		
	_watcher->createNewWatcher(path, ft, true, eventHandler);
}