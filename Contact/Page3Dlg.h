#if !defined(AFX_PAGE3DLG_H__E9E74CBB_8C6F_4FE9_9A67_B60C13A1FC19__INCLUDED_)
#define AFX_PAGE3DLG_H__E9E74CBB_8C6F_4FE9_9A67_B60C13A1FC19__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Page3Dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPage3Dlg dialog

class CPage3Dlg : public CDialog
{
// Construction
public:
	CPage3Dlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPage3Dlg)
	enum { IDD = IDD_MAIN_PAGE3 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPage3Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPage3Dlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE3DLG_H__E9E74CBB_8C6F_4FE9_9A67_B60C13A1FC19__INCLUDED_)
