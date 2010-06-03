#pragma once

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;

namespace LogViewer
{
namespace Logic
{
namespace Inputs
{	

	public ref class NetworkInput : public InputInterface
	{
		public:
			NetworkInput(String^ address, unsigned int port, unsigned int idx): _address(address), _port(port), _tabIndex(idx)
			{
				_udpClient = gcnew UdpClient();				
			}			
			
			virtual ~NetworkInput() {}
						
			// TODO: Threads & OnReceived invoking.							
						
			// Methods for receiving & sending bytes.
			String^ receive();
			bool send(String^ toSend);
			
		public: 
			delegate Void ReceivedDelegate(System::Object^  sender, LogViewer::Events::SimpleChangedDataEventArgs^  e);
			
		public:
			event ReceivedDelegate^ OnReceived;
			
		private:
			String^ _address;
			unsigned int _port;	
		
			unsigned int _tabIndex;
		
			UdpClient^ _udpClient;
			IPEndPoint^ _remoteIpEndPoint;
	};

}	
}	
}