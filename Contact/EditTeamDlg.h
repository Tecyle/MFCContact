#if !defined(AFX_EDITTEAMDLG_H__84CCC6BB_346F_4614_88AF_E4E36274BAF6__INCLUDED_)
#define AFX_EDITTEAMDLG_H__84CCC6BB_346F_4614_88AF_E4E36274BAF6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EditTeamDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEditTeamDlg dialog

class CEditTeamDlg : public CDialog
{
// Construction
public:
	BOOL OnInitDialog();
	CEditTeamDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEditTeamDlg)
	enum { IDD = IDD_EDIT_TEAM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditTeamDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEditTeamDlg)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITTEAMDLG_H__84CCC6BB_346F_4614_88AF_E4E36274BAF6__INCLUDED_)
