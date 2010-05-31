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
			FileInput();
			FileInput(String^ path, InputWatcher::FileType ft, System::IO::FileSystemEventHandler^ eventHandler);
			~FileInput() {}		
			
		private:
			String^ _path;			
			InputWatcher^ _watcher;
	};
	
}
}
}