#if !defined(AFX_CHKPSWDDLG_H__84AD9C70_731C_4FD3_8DAD_48CC93744306__INCLUDED_)
#define AFX_CHKPSWDDLG_H__84AD9C70_731C_4FD3_8DAD_48CC93744306__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChkPswdDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChkPswdDlg dialog

class CChkPswdDlg : public CDialog
{
// Construction
public:
	BOOL OnInitDialog();
	bool CheckPswd();
	CChkPswdDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CChkPswdDlg)
	enum { IDD = IDD_CHECKPSWD };
	CString	m_userpswd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChkPswdDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CString m_dataname;

	// Generated message map functions
	//{{AFX_MSG(CChkPswdDlg)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHKPSWDDLG_H__84AD9C70_731C_4FD3_8DAD_48CC93744306__INCLUDED_)
