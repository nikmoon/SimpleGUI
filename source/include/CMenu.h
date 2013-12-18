/*
 * CMenu.h
 *
 *  Created on: 18 дек. 2013 г.
 *      Author: karpachevnk
 */

#ifndef CMENU_H_
#define CMENU_H_

#include <windows.h>

namespace SimpleGUI
{

class CMenu
{
protected:
	HMENU m_hMenu;

public:
	CMenu();
	virtual ~CMenu();

	HMENU g_hMenu() const { return m_hMenu; }
};

} /* namespace SimpleGUI */

#endif /* CMENU_H_ */
