#if !defined(AFX_FPTEAMDLG_H__6E3D0F97_301E_4339_A4D7_839892367D73__INCLUDED_)
#define AFX_FPTEAMDLG_H__6E3D0F97_301E_4339_A4D7_839892367D73__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FPTeamDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFPTeamDlg dialog

class CFPTeamDlg : public CDialog
{
// Construction
public:
	void ListPerson2();
	void ListPerson1();
	BOOL OnInitDialog();
	CFPTeamDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CFPTeamDlg)
	enum { IDD = IDD_FP_TEAM };
	CListBox	m_list2;
	CListBox	m_list1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFPTeamDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CFPTeamDlg)
	afx_msg void OnSelchangeCmbGlist1();
	afx_msg void OnSelchangeCmbGlist2();
	afx_msg void OnBtnToright();
	afx_msg void OnBtnToleft();
	afx_msg void OnAllToright();
	afx_msg void OnAllToleft();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FPTEAMDLG_H__6E3D0F97_301E_4339_A4D7_839892367D73__INCLUDED_)
