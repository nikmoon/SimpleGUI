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
public:
	CWindow_EventInterface(const string &_class_name, DWORD _style, DWORD _exstyle, const string &_name, CWindow *_parent, CMenu *_menu,
			HINSTANCE _hinst, int _x, int _y, int _cx, int _cy, LPVOID _data);
	virtual ~CWindow_EventInterface();

private:
	//
	// запрещаем копирование и присваивание экземпляров данного класса
	//
	CWindow_EventInterface(const CWindow_EventInterface &);
	void operator=(const CWindow_EventInterface &);

};

} /* namespace SimpleGUI */

#endif /* CWINDOWEVENTINTERFACE_H_ */
