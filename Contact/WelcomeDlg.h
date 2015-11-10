#if !defined(AFX_WELCOMEDLG_H__689EC2DD_0F27_44DF_877C_D2FF44A8C6B0__INCLUDED_)
#define AFX_WELCOMEDLG_H__689EC2DD_0F27_44DF_877C_D2FF44A8C6B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WelcomeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CWelcomeDlg dialog

class CWelcomeDlg : public CDialog
{
// Construction
public:
	DWORD m_lastcount;
	BOOL OnInitDialog();
	CWelcomeDlg(CWnd* pParent = NULL);   // standard constructor
	BOOL PreTranslateMessage(MSG* pMsg);
// Dialog Data
	//{{AFX_DATA(CWelcomeDlg)
	enum { IDD = IDD_WELCOME };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWelcomeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CWelcomeDlg)
	afx_msg void OnButton3();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WELCOMEDLG_H__689EC2DD_0F27_44DF_877C_D2FF44A8C6B0__INCLUDED_)
