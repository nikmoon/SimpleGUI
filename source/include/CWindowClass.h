/*
 * CWindowClass.h
 *
 *  Created on: 18 дек. 2013 г.
 *      Author: karpachevnk
 */

#ifndef CWINDOWCLASS_H_
#define CWINDOWCLASS_H_

#include <string>
#include <windows.h>

using namespace std;

namespace SimpleGUI
{

class CWindowClass
{
protected:
	string m_Name;		// им€ зарегистрированного оконного класса
	HINSTANCE m_hInst;	// описатель модул€

public:
	CWindowClass(const string &_name, UINT _style, WNDPROC _proc, HINSTANCE _hinst,  HICON _hicon, HICON _hiconsm,
			HCURSOR _hcursor, HBRUSH _hbgbrush, LPCTSTR _menu_name);
	virtual ~CWindowClass();

	const string &g_Name() const { return m_Name; }

private:
	//
	// запрещаем копирование и присваивание экземпл€ров данного класса
	//
	CWindowClass(const CWindowClass &);
	void operator=(const CWindowClass &);
};

} /* namespace SimpleGUI */

#endif /* CWINDOWCLASS_H_ */
