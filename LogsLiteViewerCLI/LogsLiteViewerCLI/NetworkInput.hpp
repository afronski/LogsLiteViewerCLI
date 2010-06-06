#pragma once
#pragma warning(disable:4947)

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
			NetworkInput(String^ address, unsigned int port, unsigned int idx): 
				_address(address), _port(port), _tabIndex(idx)
			{
				IPHostEntry^ entry = Dns::GetHostByName(_address);
		
				// IPEndPoint object will allow us to read datagrams sent from specified port and address.
				_remoteIpEndPoint = gcnew IPEndPoint(entry->AddressList[0], _port);
	
				_listener = gcnew Socket(AddressFamily::InterNetwork, SocketType::Dgram, ProtocolType::Udp);
				_listener->Bind(_remoteIpEndPoint);			
			}			
			
			virtual ~NetworkInput() {}				
			
			virtual String^ Type() override			
			{ 
				return "NetworkInput"; 
			}
						
			// Methods for receiving & sending bytes.
			void receive();
			bool send(String^ toSend);
			
		public: 
			delegate Void ReceivedDelegate(System::Object^  sender, LogViewer::Events::SimpleChangedDataEventArgs^  e);
			
		public:
			event ReceivedDelegate^ OnReceived;
			
		private:
			String^ _address;
			unsigned int _port;	
		
			unsigned int _tabIndex;
								
			Socket^ _listener;
			IPEndPoint^ _remoteIpEndPoint;
	};

}	
}	
}