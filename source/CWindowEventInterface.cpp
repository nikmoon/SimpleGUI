/*
 * CWindowEventInterface.cpp
 *
 *  Created on: 19 ���. 2013 �.
 *      Author: karpachevnk
 */

#include "CWindowEventInterface.h"

namespace SimpleGUI
{


CWindow_EventInterface::CWindow_EventInterface(const string &_class_name, DWORD _style, DWORD _exstyle, const string &_name,
		CWindow *_parent, CMenu *_menu, HINSTANCE _hinst, int _x, int _y, int _cx, int _cy, LPVOID _data)
	: CWindow(_class_name, _style, _exstyle, _name, _parent, _menu, _hinst, _x, _y, _cx, _cy, _data)
{
	//
	// ��������� ���������� ���������� ���� � ������ �����������
	//
	::SetWindowLongPtr(m_hWnd, GWLP_USERDATA, (LONG_PTR)this);
	//
	// ��������� ����� ��������� ������� ���������
	// � �������� �� �� ����
	//
	m_ClassWndProc = (WNDPROC)::SetWindowLongPtr(m_hWnd, GWLP_WNDPROC, (LONG_PTR)&EventWndProc);

}

CWindow_EventInterface::~CWindow_EventInterface()
{

}

LRESULT CALLBACK
CWindow_EventInterface::EventWndProc(HWND _hwnd, UINT _msg, WPARAM _wp, LPARAM _lp)
{
	//
	// ������� ��������� � ������ ��������� ����� ��������� ������� ����
	//
	CWindow_EventInterface *pWindow = (CWindow_EventInterface*)::GetWindowLongPtr(_hwnd, GWLP_USERDATA);
	//
	// ���� ��������� ����
	//
	if (pWindow == NULL)
	{
		//
		// �������� ��������� ��������� ������� ���������
		//
		return ::DefWindowProc(_hwnd, _msg, _wp, _lp);
	}
	else
	{
		//
		// �������� ���������� ���������, ��������� � ����������� ������� ����
		//
		LRESULT ev_result= pWindow->OnMessage(_msg, _wp, _lp);
		//
		// ���� ���� ������������
		//
		if (_msg == WM_DESTROY)
		{
			//
			// ��������������� ��������� ������� ���������
			//
			::SetWindowLongPtr(_hwnd, GWLP_WNDPROC, (LONG_PTR)pWindow->m_ClassWndProc);
			//
			// ��������� ����� ���������� ������� � ��������� �����
			//
			::SetWindowLongPtr(_hwnd, GWLP_USERDATA, (LONG_PTR)NULL);
		}
		//
		// ���������� ��������� ��������� ���������
		//
		return ev_result;
	}
}


LRESULT
CWindow_EventInterface::OnMessage(UINT _msg, WPARAM _wp, LPARAM _lp)
{
	LRESULT ev_result;	// ��������� ��������� ���������

	switch (_msg)
	{
		case WM_DESTROY:
			ev_result = OnMessage_Destroy(_wp, _lp);
			break;
		default:
			ev_result = m_ClassWndProc(m_hWnd, _msg, _wp, _lp);
			break;
	}

	return ev_result;
}


LRESULT
CWindow_EventInterface::OnMessage_Destroy(WPARAM _wp, LPARAM _lp)
{
	return m_ClassWndProc(m_hWnd, WM_DESTROY, _wp, _lp);
}

} /* namespace SimpleGUI */
