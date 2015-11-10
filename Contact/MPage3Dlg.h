#if !defined(AFX_MPAGE3DLG_H__C7EA50BF_F76D_4626_88A6_FC6379189576__INCLUDED_)
#define AFX_MPAGE3DLG_H__C7EA50BF_F76D_4626_88A6_FC6379189576__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MPage3Dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMPage3Dlg dialog

class CMPage3Dlg : public CDialog
{
// Construction
public:
	BOOL PreTranslateMessage(MSG *pMsg);
	void EnableControls();
	void UpdatePerson();
	CMPage3Dlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMPage3Dlg)
	enum { IDD = IDD_MAIN_PAGE3 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMPage3Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMPage3Dlg)
	afx_msg void OnPg3Update();
	afx_msg void OnSaveEdit3();
	afx_msg void OnChangeSMajor();
	afx_msg void OnChangeSSchool();
	afx_msg void OnChangeSClass();
	afx_msg void OnChangeSCollege();
	afx_msg void OnChangeSGrade();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MPAGE3DLG_H__C7EA50BF_F76D_4626_88A6_FC6379189576__INCLUDED_)
