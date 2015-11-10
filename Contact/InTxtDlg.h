#if !defined(AFX_INTXTDLG_H__1897DF65_2771_4D1B_8BC0_44D7864A85AA__INCLUDED_)
#define AFX_INTXTDLG_H__1897DF65_2771_4D1B_8BC0_44D7864A85AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InTxtDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInTxtDlg dialog

class CInTxtDlg : public CDialog
{
// Construction
public:
	CInTxtDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CInTxtDlg)
	enum { IDD = IDD_IN_TXT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInTxtDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CInTxtDlg)
	afx_msg void OnTxtBrowse();
	afx_msg void OnChangeTxtFile();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INTXTDLG_H__1897DF65_2771_4D1B_8BC0_44D7864A85AA__INCLUDED_)
