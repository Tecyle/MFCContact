#if !defined(AFX_REPLACEDLG_H__C4AA924C_7D56_45AB_BDE6_4E179A9AA961__INCLUDED_)
#define AFX_REPLACEDLG_H__C4AA924C_7D56_45AB_BDE6_4E179A9AA961__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ReplaceDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CReplaceDlg dialog

class CReplaceDlg : public CDialog
{
// Construction
public:
	BOOL OnInitDialog();
	CReplaceDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CReplaceDlg)
	enum { IDD = IDD_REPLACE_BOX };
	CListCtrl	m_flist1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReplaceDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CImageList m_images;

	// Generated message map functions
	//{{AFX_MSG(CReplaceDlg)
	virtual void OnOK();
	afx_msg void OnChangeRpFind();
	afx_msg void OnReplace();
	afx_msg void OnReplaceAll();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REPLACEDLG_H__C4AA924C_7D56_45AB_BDE6_4E179A9AA961__INCLUDED_)
