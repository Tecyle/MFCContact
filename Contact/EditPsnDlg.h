#if !defined(AFX_EDITPSNDLG_H__6E3596CE_CEB9_4A01_B505_A9060EEE5D5D__INCLUDED_)
#define AFX_EDITPSNDLG_H__6E3596CE_CEB9_4A01_B505_A9060EEE5D5D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EditPsnDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEditPsnDlg dialog

class CEditPsnDlg : public CDialog
{
// Construction
public:
	CEditPsnDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEditPsnDlg)
	enum { IDD = IDD_EDIT_PERSON };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditPsnDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEditPsnDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITPSNDLG_H__6E3596CE_CEB9_4A01_B505_A9060EEE5D5D__INCLUDED_)
