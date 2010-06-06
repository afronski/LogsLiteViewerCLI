#pragma once 

using namespace System;
using namespace System::ComponentModel;
using namespace System::Windows::Forms;
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
			
			void appendInput(Inputs::InputInterface^ in);
			void removeInput(String^ name);
			
			// Name accessor.
			String^	%Name();
			
			unsigned int inputsCount()		{ return _inputs->Count; }

			Inputs::InputInterface^ operator[] (int idx)	{ return _inputs[idx]; }
			Inputs::InputInterface^ operator[] (String^ name)	
			{ 
				Inputs::InputInterface^ iter;
				for each(Inputs::InputInterface^ i in _inputs)
				{
					if (i->Name() == name)
					{
						iter = i;
						break;
					}
				}
				
				return iter;
			}				
		
		protected:
			String^ _name;
			List<Inputs::InputInterface^>^ _inputs;			
	};
	
}
}