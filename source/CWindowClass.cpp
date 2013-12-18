/*
 * CWindowClass.cpp
 *
 *  Created on: 18 дек. 2013 г.
 *      Author: karpachevnk
 */

#include "CWindowClass.h"

namespace SimpleGUI
{


CWindowClass::CWindowClass(const string &_name, UINT _style, WNDPROC _proc, HINSTANCE _hinst, HICON _hicon, HICON _hiconsm,
		HCURSOR _hcursor, HBRUSH _hbgbrush, LPCTSTR _menu_name)
{
	//
	// подготавливаем данные дл€ регистрации оконного класса
	//
	WNDCLASSEX wc =
	{
		sizeof(WNDCLASSEX),
		_style,
		_proc,
		0,
		0,
		_hinst,
		_hicon,
		_hcursor,
		_hbgbrush,
		_menu_name,
		_name.c_str(),
		_hiconsm
	};
	//
	// пробуем зарегистрировать оконный класс
	//
	if (!::RegisterClassEx(&wc))
	{
		//
		// регистраци€ не прошла, генерируем исключение с кодом ошибки
		//
		throw ::GetLastError();
	}
	//
	// инициализируем пол€ экземпл€ра
	//
	m_Name = _name;
	m_hInst = _hinst;
}


CWindowClass::~CWindowClass()
{
	//
	// пробуем отменить регистрацию оконного класса
	//
	if (!::UnregisterClass(m_Name.c_str(), ::GetModuleHandle(NULL)))
	{
		//
		// произошла ошибка, генерируем исключение с кодом ошибки
		//
		throw ::GetLastError();
	}
}

} /* namespace SimpleGUI */
