#pragma once 

#include "Channel.hpp"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;

namespace LogViewer
{
namespace Logic
{

	public ref class ChannelManager
	{
		public:	
			ChannelManager();
			~ChannelManager() {}		
						
			// Channel counter.
			unsigned int channelCount()		{	return _channels->Count;	}
			
			// Managing methods.
			void appendChannel(Channel^ toAppend);
			void removeChannel(String^ nameToDelete);
			
		private:
			List<Channel^>^ _channels;
	};
	
}
}