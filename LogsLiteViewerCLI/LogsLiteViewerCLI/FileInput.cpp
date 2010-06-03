#include "stdafx.h"

using namespace LogViewer::Logic;
using namespace LogViewer::Logic::Inputs;

FileInput::FileInput(): _path("")
{
	_watcher = gcnew InputWatcher();
}

FileInput::FileInput(String^ path, InputWatcher::FileType ft, unsigned int idx, InputWatcher::ProxyFileSystemDelegate^ eventHandler): 
	_path(path), _tabIndex(idx)
{
	_watcher = gcnew InputWatcher();		
	_watcher->createNewWatcher(path, ft, idx, true, eventHandler);
}