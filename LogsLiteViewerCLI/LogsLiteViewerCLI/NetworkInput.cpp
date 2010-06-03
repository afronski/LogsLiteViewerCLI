#include "stdafx.h"

using namespace System;
using namespace System::Net;
using namespace System::Text;
using namespace System::Windows::Forms;
using namespace LogViewer::Logic;
using namespace LogViewer::Logic::Inputs;

String^ NetworkInput::receive()
{
	try
	{
		// IPEndPoint object will allow us to read datagrams sent from specified port and address.
		_remoteIpEndPoint = gcnew IPEndPoint(Dns::GetHostEntry(_address)->AddressList[0], _port);
	
		// Block until a message returns on this socket from a remote host.
		array<Byte>^ receiveBytes = _udpClient->Receive(_remoteIpEndPoint);
		String^ returnData = Encoding::ASCII->GetString(receiveBytes);
		return returnData;
	}
	catch(SocketException^ e)
	{
		MessageBox::Show(":: SocketException", e->ToString() + "\n From address: " + _remoteIpEndPoint->Address->ToString(), MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	catch(ObjectDisposedException^ e)
	{
		MessageBox::Show(":: Socket was closed faster than receive!", e->ToString() + "\n From address: " + _remoteIpEndPoint->Address->ToString(), MessageBoxButtons::OK, MessageBoxIcon::Error);
	}	
	
	return "";
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
		MessageBox::Show(":: SocketException", e->ToString(), MessageBoxButtons::OK, MessageBoxIcon::Error);		
	}
	catch(ObjectDisposedException^ e)
	{
		MessageBox::Show(":: Socket was closed faster than send!", e->ToString(), MessageBoxButtons::OK, MessageBoxIcon::Error);		
	}		
	
	return false;
}