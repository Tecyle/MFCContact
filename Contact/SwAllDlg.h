#if !defined(AFX_SWALLDLG_H__6B065324_C647_4061_9424_AE1BF92F2F08__INCLUDED_)
#define AFX_SWALLDLG_H__6B065324_C647_4061_9424_AE1BF92F2F08__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SwAllDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSwAllDlg dialog

class CSwAllDlg : public CDialog
{
// Construction
public:
	void UpdateLists();
	BOOL OnInitDialog();
	CSwAllDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSwAllDlg)
	enum { IDD = IDD_SHOW_ALLINFOR };
	CListCtrl	m_plist;
	CListCtrl	m_glist;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSwAllDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSwAllDlg)
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SWALLDLG_H__6B065324_C647_4061_9424_AE1BF92F2F08__INCLUDED_)
