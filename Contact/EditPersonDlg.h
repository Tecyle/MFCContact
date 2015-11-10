#if !defined(AFX_EDITPERSONDLG_H__2FDCD6D6_0444_4193_8840_F54947708B50__INCLUDED_)
#define AFX_EDITPERSONDLG_H__2FDCD6D6_0444_4193_8840_F54947708B50__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EditPersonDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEditPersonDlg dialog

class CEditPersonDlg : public CDialog
{
// Construction
public:
	void ListPerson();
	BOOL OnInitDialog();
	CEditPersonDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEditPersonDlg)
	enum { IDD = IDD_EDIT_PERSON };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEditPersonDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEditPersonDlg)
	virtual void OnOK();
	afx_msg void OnSelchangeEpName();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EDITPERSONDLG_H__2FDCD6D6_0444_4193_8840_F54947708B50__INCLUDED_)
