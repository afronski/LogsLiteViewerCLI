#include "stdafx.h"

using namespace System;
using namespace System::Net;
using namespace System::Text;
using namespace System::Windows::Forms;
using namespace LogViewer::Logic;
using namespace LogViewer::Logic::Inputs;

void NetworkInput::receive()
{
	try
	{	
		// Block until a message returns on this socket from a remote host.
		array<Byte>^ receiveBytes = gcnew array<Byte>(1024);
		int count = _listener->Receive(receiveBytes, 1024, SocketFlags::None);
		String^ returnData = Encoding::ASCII->GetString(receiveBytes, 0, count);
				
		LogViewer::Events::SimpleChangedDataEventArgs^ simple = gcnew LogViewer::Events::SimpleChangedDataEventArgs(_tabIndex, returnData);
		
		OnReceived(this, simple);
	}
	catch(SocketException^ e)
	{
		MessageBox::Show(e->ToString() + "\n From address: " + _remoteIpEndPoint->Address->ToString(), ":: SocketException", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	catch(ObjectDisposedException^ e)
	{
		MessageBox::Show(e->ToString() + "\n From address: " + _remoteIpEndPoint->Address->ToString(), ":: Socket was closed faster than receive!", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}			
}

bool NetworkInput::send(String^ toSend)
{
	try
	{
		// Create new object, send and close.
		UdpClient^ _udpClientB = gcnew UdpClient();
		array<Byte>^ sendBytes = Encoding::ASCII->GetBytes(toSend);
		_udpClientB->Send(sendBytes, sendBytes->Length, _address, _port);
		_udpClientB->Close();	
		return true;
	}
	catch(SocketException^ e)
	{
		MessageBox::Show(e->ToString(), ":: SocketException", MessageBoxButtons::OK, MessageBoxIcon::Error);		
	}
	catch(ObjectDisposedException^ e)
	{
		MessageBox::Show(e->ToString(), ":: Socket was closed faster than send!", MessageBoxButtons::OK, MessageBoxIcon::Error);		
	}		
	
	return false;
}