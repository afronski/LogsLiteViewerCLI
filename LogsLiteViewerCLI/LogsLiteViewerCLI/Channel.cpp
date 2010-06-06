#include "stdafx.h"

using namespace LogViewer::Logic;

// Accessor implementation.
String^% Channel::Name()
{
	return _name;
}

void Channel::appendInput(Inputs::InputInterface^ in)
{
	_inputs->Add(in);
}

void Channel::removeInput(String^ name)
{
	Inputs::InputInterface^ iter = nullptr;
	for each(Inputs::InputInterface^ i in _inputs)
	{
		if (i->Name() == name)
		{
			iter = i;
			break;
		}			
	}
	
	if (iter)
	{
		_inputs->Remove(iter);
	}
}