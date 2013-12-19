/*
 * CWindowEventInterface.cpp
 *
 *  Created on: 19 дек. 2013 г.
 *      Author: karpachevnk
 */

#include "CWindowEventInterface.h"

namespace SimpleGUI
{

CWindow_EventInterface::CWindow_EventInterface(const string &_class_name, DWORD _style, DWORD _exstyle, const string &_name,
		CWindow *_parent, CMenu *_menu, HINSTANCE _hinst, int _x, int _y, int _cx, int _cy, LPVOID _data)
	: CWindow(_class_name, _style, _exstyle, _name, _parent, _menu, _hinst, _x, _y, _cx, _cy, _data)
{

}

CWindow_EventInterface::~CWindow_EventInterface()
{

}

} /* namespace SimpleGUI */
