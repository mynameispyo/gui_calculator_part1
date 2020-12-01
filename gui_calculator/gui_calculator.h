
// gui_calculator.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CguicalculatorApp:
// See gui_calculator.cpp for the implementation of this class
//

class CguicalculatorApp : public CWinApp
{
public:
	CguicalculatorApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CguicalculatorApp theApp;
