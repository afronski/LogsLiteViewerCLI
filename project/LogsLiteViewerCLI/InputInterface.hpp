#pragma once

using namespace System;

namespace LogViewer
{
namespace Logic
{
namespace Inputs
{	

	public ref class InputInterface abstract
	{
		public:			
			InputInterface(String^ name): _name(name) {}						
			
			virtual ~InputInterface() {}						
			
			virtual String^ Type() abstract;
			
			// Public accessor.
			String^% Name()
			{
				return _name;
			}
			
		protected:
			String^ _name;
	};
	
}
}
}