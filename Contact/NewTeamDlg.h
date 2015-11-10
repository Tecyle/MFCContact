#if !defined(AFX_NEWTEAMDLG_H__5E88418D_8F35_4BB9_BC16_0C6026B80AA5__INCLUDED_)
#define AFX_NEWTEAMDLG_H__5E88418D_8F35_4BB9_BC16_0C6026B80AA5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewTeamDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNewTeamDlg dialog

class CNewTeamDlg : public CDialog
{
// Construction
public:
	CNewTeamDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNewTeamDlg)
	enum { IDD = IDD_NEW_TEAM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewTeamDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewTeamDlg)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWTEAMDLG_H__5E88418D_8F35_4BB9_BC16_0C6026B80AA5__INCLUDED_)
