#pragma once

using namespace System;

namespace LogViewer
{
namespace Events
{
	// Event derived from specific classes - for wrapping, and adding new property - ActiveTabIndex.
	public ref class SimpleChangedDataEventArgs : public System::EventArgs
	{
		public:		
			// Constructor.
			SimpleChangedDataEventArgs(unsigned int index, String^ data): _tabIndex(index), _data(data) {}
			
			// Accessors.
			unsigned int% TabIndex()	{ return _tabIndex; }
			String^% Data()				{ return _data;		}
		
		private:
			unsigned int _tabIndex;
			String^ _data;
	};

}
}