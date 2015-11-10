#if !defined(AFX_KILLPSNDLG_H__BB476CC7_D479_42A3_9D87_855D025695FF__INCLUDED_)
#define AFX_KILLPSNDLG_H__BB476CC7_D479_42A3_9D87_855D025695FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// KillPsnDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CKillPsnDlg dialog

class CKillPsnDlg : public CDialog
{
// Construction
public:
	BOOL OnInitDialog();
	CKillPsnDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CKillPsnDlg)
	enum { IDD = IDD_KILL_PERSON };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKillPsnDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CKillPsnDlg)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KILLPSNDLG_H__BB476CC7_D479_42A3_9D87_855D025695FF__INCLUDED_)
