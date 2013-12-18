/*
 * CWindow.h
 *
 *  Created on: 18 дек. 2013 г.
 *      Author: karpachevnk
 */

#ifndef CWINDOW_H_
#define CWINDOW_H_

#include <string>
#include <windows.h>

#include "CWindowClass.h"
#include "CMenu.h"

namespace SimpleGUI
{

class CWindow
{
protected:
	HWND m_hWnd;		// описатель окна
	HINSTANCE m_hInst;	// описатель модул€

public:
	CWindow(const string &_class_name, DWORD _style, DWORD _exstyle, const string &_name, CWindow *_parent, CMenu *_menu,
			HINSTANCE _hinst, int _x, int _y, int _cx, int _cy, LPVOID _data);
	virtual ~CWindow();

	void Show() { ::ShowWindow(m_hWnd, SW_SHOW); }
	void Hide() { ::ShowWindow(m_hWnd, SW_HIDE); }
	void Minimize() { ::ShowWindow(m_hWnd, SW_MINIMIZE); }
	void Maximize() { ::ShowWindow(m_hWnd, SW_MAXIMIZE); }
	void Destroy() { ::DestroyWindow(m_hWnd); }
	void Destroy_IfExists() { if (::IsWindow(m_hWnd)) Destroy(); }

private:
	//
	// запрещаем копирование и присваивание экземпл€ров данного класса
	//
	CWindow(const CWindow &);
	void operator=(const CWindow &);
};

} /* namespace SimpleGUI */

#endif /* CWINDOW_H_ */
