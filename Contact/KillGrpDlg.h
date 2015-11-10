#if !defined(AFX_KILLGRPDLG_H__F7B59AD7_A078_4ABE_9584_A34381A9CB9E__INCLUDED_)
#define AFX_KILLGRPDLG_H__F7B59AD7_A078_4ABE_9584_A34381A9CB9E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// KillGrpDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CKillGrpDlg dialog

class CKillGrpDlg : public CDialog
{
// Construction
public:
	BOOL OnInitDialog();
	CKillGrpDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CKillGrpDlg)
	enum { IDD = IDD_KILL_GROUP };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKillGrpDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CKillGrpDlg)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KILLGRPDLG_H__F7B59AD7_A078_4ABE_9584_A34381A9CB9E__INCLUDED_)
