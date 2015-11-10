#if !defined(AFX_PAGE4DLG_H__685DCB2A_CBB5_4A6C_837C_F515E283C6CE__INCLUDED_)
#define AFX_PAGE4DLG_H__685DCB2A_CBB5_4A6C_837C_F515E283C6CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Page4Dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPage4Dlg dialog

class CPage4Dlg : public CDialog
{
// Construction
public:
	CPage4Dlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPage4Dlg)
	enum { IDD = IDD_MAIN_PAGE4 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPage4Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPage4Dlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGE4DLG_H__685DCB2A_CBB5_4A6C_837C_F515E283C6CE__INCLUDED_)
