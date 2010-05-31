#pragma once 

using namespace System;
using namespace System::Collections::Generic;

namespace LogViewer
{
namespace Logic
{

	public ref class Channel
	{
		public:
			// Contructors.
			Channel(): _name("")	
			{
				_inputs = gcnew List<Inputs::InputInterface^>();
			}
						
			Channel(String^ name): _name(name)			
			{
				_inputs = gcnew List<Inputs::InputInterface^>();
			}
			
			// Name accessor.
			String^	%Name();
		
		protected:
			String^ _name;
			List<Inputs::InputInterface^>^ _inputs;
	};
	
}
}