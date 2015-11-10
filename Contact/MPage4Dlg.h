#if !defined(AFX_MPAGE4DLG_H__2FA4F988_EC88_4693_A0F1_4C4A68926745__INCLUDED_)
#define AFX_MPAGE4DLG_H__2FA4F988_EC88_4693_A0F1_4C4A68926745__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MPage4Dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMPage4Dlg dialog

class CMPage4Dlg : public CDialog
{
// Construction
public:
	BOOL PreTranslateMessage(MSG *pMsg);
	void EnableControls();
	void UpdatePerson();
	CMPage4Dlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMPage4Dlg)
	enum { IDD = IDD_MAIN_PAGE4 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMPage4Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMPage4Dlg)
	afx_msg void OnSendEmail();
	afx_msg void OnPg4Update();
	afx_msg void OnChangeCPhone();
	afx_msg void OnChangeCMobi();
	afx_msg void OnChangeCAddress();
	afx_msg void OnChangeCPostcode();
	afx_msg void OnChangeCQq();
	afx_msg void OnChangeCEmail();
	afx_msg void OnChangeCFax();
	afx_msg void OnSaveEdit4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MPAGE4DLG_H__2FA4F988_EC88_4693_A0F1_4C4A68926745__INCLUDED_)
