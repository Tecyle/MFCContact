// Contact.h : main header file for the CONTACT application
//

#if !defined(AFX_CONTACT_H__60A2018B_5061_4CCE_AAC6_663B7B02D702__INCLUDED_)
#define AFX_CONTACT_H__60A2018B_5061_4CCE_AAC6_663B7B02D702__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CContactApp:
// See Contact.cpp for the implementation of this class
//

class CContactApp : public CWinApp
{
public:
	CContactApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CContactApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CContactApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTACT_H__60A2018B_5061_4CCE_AAC6_663B7B02D702__INCLUDED_)
