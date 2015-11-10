#if !defined(AFX_NEWPSNDLG_H__B79C7DD5_9B98_4B0D_9287_C6859FB0DBBE__INCLUDED_)
#define AFX_NEWPSNDLG_H__B79C7DD5_9B98_4B0D_9287_C6859FB0DBBE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewPsnDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNewPsnDlg dialog

class CNewPsnDlg : public CDialog
{
// Construction
public:
	BOOL OnInitDialog();
	CNewPsnDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNewPsnDlg)
	enum { IDD = IDD_NEW_PERSON };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewPsnDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewPsnDlg)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWPSNDLG_H__B79C7DD5_9B98_4B0D_9287_C6859FB0DBBE__INCLUDED_)
