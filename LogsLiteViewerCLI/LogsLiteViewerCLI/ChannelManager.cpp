#include "stdafx.h"

using namespace LogViewer::Logic;

ChannelManager::ChannelManager()
{
	_channels = gcnew List<Channel^>();
}

void ChannelManager::appendChannel(Channel^ toAppend)
{
	_channels->Add(toAppend);
}

void ChannelManager::removeChannel(String^ nameToDelete)
{	
	Channel^ iter = nullptr;
	for each(Channel^ chan in _channels)
	{
		if (chan->Name() == nameToDelete)
		{
			iter = chan;
			break;
		}
	}
	
	if (iter)
	{
		_channels->Remove(iter);
	}
}