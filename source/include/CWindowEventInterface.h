/*
 * CWindowEventInterface.h
 *
 *  Created on: 19 дек. 2013 г.
 *      Author: karpachevnk
 */

#ifndef CWINDOWEVENTINTERFACE_H_
#define CWINDOWEVENTINTERFACE_H_


#include <CWindow.h>

namespace SimpleGUI
{

class CWindow_EventInterface : virtual public CWindow
{
protected:
	WNDPROC m_ClassWndProc;		// классова€ оконна€ процедура
	virtual LRESULT OnMessage(UINT _msg, WPARAM _wp, LPARAM _lp);	// обработчик сообщений
	virtual LRESULT OnMessage_Destroy(WPARAM _wp, LPARAM _lp);

private:
	static LRESULT CALLBACK EventWndProc(HWND _hwnd, UINT _msg, WPARAM _wp, LPARAM _lp);

public:
	CWindow_EventInterface(const string &_class_name, DWORD _style, DWORD _exstyle, const string &_name, CWindow *_parent, CMenu *_menu,
			HINSTANCE _hinst, int _x, int _y, int _cx, int _cy, LPVOID _data);
	virtual ~CWindow_EventInterface();

private:
	//
	// запрещаем копирование и присваивание экземпл€ров данного класса
	//
	CWindow_EventInterface(const CWindow_EventInterface &);
	void operator=(const CWindow_EventInterface &);

};

} /* namespace SimpleGUI */

#endif /* CWINDOWEVENTINTERFACE_H_ */
