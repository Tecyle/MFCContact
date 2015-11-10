#if !defined(AFX_EDITPSWDDLG_H__BF133A84_2411_453D_8CE0_5C49730304A2__INCLUDED_)
#define AFX_EDITPSWDDLG_H__BF133A84_2411_453D_8CE0_5C49730304A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EditPswdDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEditPswdDlg dialog

class CEditPswdDlg : public CDialog
{
// Construction
public:
	CEditPswdDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEditPswdDlg)
	enum { IDD = IDD_EDIT_PSWD };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditPswdDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEditPswdDlg)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITPSWDDLG_H__BF133A84_2411_453D_8CE0_5C49730304A2__INCLUDED_)
