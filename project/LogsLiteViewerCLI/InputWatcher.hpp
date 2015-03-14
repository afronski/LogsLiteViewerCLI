#pragma once 

using namespace System::IO;

namespace LogViewer
{
namespace Logic
{

	public ref class InputWatcher
	{
		public:
			delegate System::Void ProxyFileSystemDelegate(System::Object^  sender, LogViewer::Events::SimpleChangedDataEventArgs^  e);
	
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
				this->ProxyFileSystemEvent -= _additionalEventHandler;
			}
			
			// Create method.
			void createNewWatcher(String^ path, InputWatcher::FileType ft, unsigned int idx, bool activateNow, ProxyFileSystemDelegate^ eventHandler);
			
			// Watcher state management methods.
			void suspendWatcher();
			void resumeWatcher();			
			
		public:
			event ProxyFileSystemDelegate^ ProxyFileSystemEvent;
			
		private:
			System::Void ProxyFileSystemDelgateImpl(System::Object^  sender, System::IO::FileSystemEventArgs^  e)
			{			
				if (e->ChangeType == System::IO::WatcherChangeTypes::Changed)
				{		
					ProxyFileSystemEvent(sender, gcnew LogViewer::Events::SimpleChangedDataEventArgs(_tabIndex, e->FullPath));
				}
			}
			
		private:
			unsigned int _tabIndex;
		
			FileSystemWatcher^ _fileWatcher;
			System::IO::FileSystemEventHandler^ _eventHandler;
			ProxyFileSystemDelegate^ _additionalEventHandler;
	};
	
}
}