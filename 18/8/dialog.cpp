#include "Dialog.h"
#include "Event.h"
#include <iostream>
#include <string>
using namespace std;

Dialog::Dialog() : Vector()
{
	EndState = 0;
}

Dialog::~Dialog() {}

void Dialog::GetEvent(TEvent& event)
{
	string operations = "m+-szq";
	string s;
	getline(cin, s);

	if (operations.find(s[0]) != -1)
	{
		event.what = evMessage;
		switch (s[0]) {
		case 'm': event.command = cmdMake; break;
		case '+': event.command = cmdAdd; break;
		case '-': event.command = cmdDel; break;
		case 's': event.command = cmdShow; break;
		case 'z': event.command = cmdName; break;
		case 'q': event.command = cmdQuit; break;
		}
		if (s.length() > 1)
		{
			string param = s.substr(1, s.length() - 1); 
			event.param = stoi(param);
		}
	}
	else
	{
		event.what = evNothing;
	}
}

void Dialog::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmdMake:  
		{
			int size = event.param;
			_begin = new Object * [size];
			_size = size;
			_current = 0;
			ClearEvent(event);
			break;
		}
		case cmdAdd:  
		{
			Add();
			ClearEvent(event);
			break;
		}
		case cmdDel: 
		{
			Del();
			ClearEvent(event);
			break;
		}
		case cmdShow:  
		{
			Show();
			ClearEvent(event);
			break;
		}
		case cmdQuit: 
		{
			EndState = 1;
			ClearEvent(event);
			break;
		}
		default: Vector::HandleEvent(event);
		}
	}
}

void Dialog::Execute()
{
	TEvent event;
	do
	{
		GetEvent(event);
		HandleEvent(event);
		if (event.what != evNothing) 
		{
			ClearEvent(event);
		}
	} while (EndState == 0);
}

void Dialog::ClearEvent(TEvent& event)
{
	event.what = evNothing;
}