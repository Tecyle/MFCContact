#if !defined(AFX_MPAGE5DLG_H__73E3EE17_613D_4978_8DD1_274297724A47__INCLUDED_)
#define AFX_MPAGE5DLG_H__73E3EE17_613D_4978_8DD1_274297724A47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MPage5Dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMPage5Dlg dialog

class CMPage5Dlg : public CDialog
{
// Construction
public:
	BOOL PreTranslateMessage(MSG *pMsg);
	void EnableControls();
	void UpdatePerson();
	CMPage5Dlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMPage5Dlg)
	enum { IDD = IDD_MAIN_PAGE5 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMPage5Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMPage5Dlg)
	afx_msg void OnPg5Update();
	afx_msg void OnVisit();
	afx_msg void OnSaveEdit5();
	afx_msg void OnChangeMHome();
	afx_msg void OnChangeMMemo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MPAGE5DLG_H__73E3EE17_613D_4978_8DD1_274297724A47__INCLUDED_)
