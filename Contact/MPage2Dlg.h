#if !defined(AFX_MPAGE2DLG_H__430556FF_BDEB_42BC_BB25_1E9AAD85170F__INCLUDED_)
#define AFX_MPAGE2DLG_H__430556FF_BDEB_42BC_BB25_1E9AAD85170F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MPage2Dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMPage2Dlg dialog

class CMPage2Dlg : public CDialog
{
// Construction
public:
	BOOL PreTranslateMessage(MSG *pMsg);
	void EnableControls();
	void UpdatePerson();
	void UpdateLists2();
	void UpdateLists();
	BOOL OnInitDialog();
	CMPage2Dlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMPage2Dlg)
	enum { IDD = IDD_MAIN_PAGE2 };
	CListCtrl	m_tlist;
	int		m_iyear;
	int		m_imonth;
	int		m_iday;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMPage2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CImageList m_images;

	// Generated message map functions
	//{{AFX_MSG(CMPage2Dlg)
	afx_msg void OnEditchangeCmbTeam();
	afx_msg void OnSelchangeCmbTeam();
	afx_msg void OnPg2Update();
	afx_msg void OnSaveEdit2();
	afx_msg void OnChangeBInputname();
	afx_msg void OnChangeEditYear();
	afx_msg void OnChangeEditMonth();
	afx_msg void OnChangeEditDay();
	afx_msg void OnChangeBInputprov();
	afx_msg void OnBMan();
	afx_msg void OnBWoman();
	afx_msg void OnSelchangeCmbInputteam();
	afx_msg void OnChangeBInputposit();
	afx_msg void OnMNteam();
	afx_msg void OnButton4();
	afx_msg void OnDblclkTlist(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MPAGE2DLG_H__430556FF_BDEB_42BC_BB25_1E9AAD85170F__INCLUDED_)
