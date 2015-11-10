#if !defined(AFX_PAGE2DLG_H__56CCB613_9C9A_49CE_B256_7B03447C8FBD__INCLUDED_)
#define AFX_PAGE2DLG_H__56CCB613_9C9A_49CE_B256_7B03447C8FBD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Page2Dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPage2Dlg dialog

class CPage2Dlg : public CDialog
{
// Construction
public:
	CPage2Dlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPage2Dlg)
	enum { IDD = IDD_MAIN_PAGE2 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPage2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPage2Dlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE2DLG_H__56CCB613_9C9A_49CE_B256_7B03447C8FBD__INCLUDED_)
