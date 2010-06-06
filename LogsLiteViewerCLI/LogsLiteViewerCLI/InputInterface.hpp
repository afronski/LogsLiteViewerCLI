#pragma once

using namespace System;

namespace LogViewer
{
namespace Logic
{
namespace Inputs
{	

	public ref class InputInterface
	{
		public:
			InputInterface(): _name("") {}
			InputInterface(String^ name): _name(name) {}						
			
			virtual ~InputInterface() {}						
			
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