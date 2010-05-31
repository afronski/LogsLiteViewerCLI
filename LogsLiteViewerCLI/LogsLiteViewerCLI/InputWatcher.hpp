#pragma once 

using namespace System::IO;

namespace LogViewer
{
namespace Logic
{

	public ref class InputWatcher
	{
		public:		
			enum class FileType
			{
				FileType_Xml = 0,
				FileType_Txt
			};
		
			// Constructors & destructors.
			InputWatcher() {}			
			~InputWatcher() 
			{
				_fileWatcher->Changed -= _eventHandler;
			}
			
			// Create method.
			void createNewWatcher(String^ path, InputWatcher::FileType ft, bool activateNow, System::IO::FileSystemEventHandler^ eventHandler);
			
			// Watcher state management methods.
			void suspendWatcher();
			void resumeWatcher();
			
		private:
			FileSystemWatcher^ _fileWatcher;
			System::IO::FileSystemEventHandler^ _eventHandler;
	};
	
}
}