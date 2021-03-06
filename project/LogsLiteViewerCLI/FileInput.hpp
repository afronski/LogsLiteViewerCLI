#pragma once 

#include "InputInterface.hpp"
#include "InputWatcher.hpp"

using namespace System;

namespace LogViewer
{
namespace Logic
{
namespace Inputs
{	

	public ref class FileInput : public InputInterface
	{
		public:
			FileInput(String^ path, InputWatcher::FileType ft, unsigned int idx, InputWatcher::ProxyFileSystemDelegate^ eventHandler);
			virtual ~FileInput() {}		
			
			virtual String^ Type() override  		 
			{ 
				return "FileInput"; 
			}
			
		private:
			unsigned int _tabIndex;
		
			String^ _path;			
			InputWatcher^ _watcher;
	};
	
}
}
}