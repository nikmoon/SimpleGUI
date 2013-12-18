/*
 * CWindowClass.cpp
 *
 *  Created on: 18 ���. 2013 �.
 *      Author: karpachevnk
 */

#include "CWindowClass.h"

namespace SimpleGUI
{


CWindowClass::CWindowClass(const string &_name, UINT _style, WNDPROC _proc, HINSTANCE _hinst, HICON _hicon, HICON _hiconsm,
		HCURSOR _hcursor, HBRUSH _hbgbrush, LPCTSTR _menu_name)
{
	//
	// �������������� ������ ��� ����������� �������� ������
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
	// ������� ���������������� ������� �����
	//
	if (!::RegisterClassEx(&wc))
	{
		//
		// ����������� �� ������, ���������� ���������� � ����� ������
		//
		throw ::GetLastError();
	}
	//
	// �������������� ���� ����������
	//
	m_Name = _name;
	m_hInst = _hinst;
}


CWindowClass::~CWindowClass()
{
	//
	// ������� �������� ����������� �������� ������
	//
	if (!::UnregisterClass(m_Name.c_str(), ::GetModuleHandle(NULL)))
	{
		//
		// ��������� ������, ���������� ���������� � ����� ������
		//
		throw ::GetLastError();
	}
}

} /* namespace SimpleGUI */
