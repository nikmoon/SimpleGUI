/*
 * CWindow.cpp
 *
 *  Created on: 18 ���. 2013 �.
 *      Author: karpachevnk
 */

#include "CWindow.h"

namespace SimpleGUI
{


CWindow::CWindow(const string &_class_name, DWORD _style, DWORD _exstyle, const string &_name, CWindow *_parent, CMenu *_menu,
		HINSTANCE _hinst, int _x, int _y, int _cx, int _cy, LPVOID _data)
{
	//
	// ���������� ������ ��� ������ CreateWindowEx
	//
	HWND _hparent = (_parent == NULL) ? NULL : _parent->m_hWnd;
	HMENU _hmenu = (_menu == NULL) ? NULL : _menu->g_hMenu();
	//
	// ������� ������� ����
	//
	m_hWnd = ::CreateWindowEx
		(
			_exstyle,
			_class_name.c_str(),
			_name.c_str(),
			_style,
			_x,
			_y,
			_cx,
			_cy,
			_hparent,
			_hmenu,
			_hinst,
			_data
		);
	//
	// ���� �� ������� ������� ����
	//
	if (m_hWnd == NULL)
	{
		//
		// ���������� ���������� � ����� ������
		//
		throw ::GetLastError();
	}
	//
	// �������������� ���� ����������
	//
	m_hInst = _hinst;
}

CWindow::~CWindow()
{
	//
	// ���� � ������� ������ ���� ���������� ������ ������ �����������
	//
}

} /* namespace SimpleGUI */
