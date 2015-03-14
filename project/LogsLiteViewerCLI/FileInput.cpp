#include "stdafx.h"

using namespace LogViewer::Logic;
using namespace LogViewer::Logic::Inputs;

FileInput::FileInput(String^ path, InputWatcher::FileType ft, unsigned int idx, InputWatcher::ProxyFileSystemDelegate^ eventHandler): 
	_path(path), _tabIndex(idx), InputInterface(String::Format("{0} - {1}", _path, ft.ToString()))
{
	_watcher = gcnew InputWatcher();		
	_watcher->createNewWatcher(path, ft, idx, true, eventHandler);
}