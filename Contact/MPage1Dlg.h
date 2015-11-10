#if !defined(AFX_MPAGE1DLG_H__284EB99B_9789_4F78_9C32_A92448B51B24__INCLUDED_)
#define AFX_MPAGE1DLG_H__284EB99B_9789_4F78_9C32_A92448B51B24__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MPage1Dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMPage1Dlg dialog

class CMPage1Dlg : public CDialog
{
// Construction
public:
	BOOL PreTranslateMessage(MSG* pMsg);
	void EnableControls();
	void UpdatePerson();
	void UpdateLists();
	BOOL OnInitDialog();
	void InitCmb(void);
	CMPage1Dlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMPage1Dlg)
	enum { IDD = IDD_MAIN_PAGE1 };
	CListCtrl	m_list1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMPage1Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CImageList m_images;

	// Generated message map functions
	//{{AFX_MSG(CMPage1Dlg)
	afx_msg void OnNpageNext();
	afx_msg void OnNpagePrev();
	afx_msg void OnNpageFirst();
	afx_msg void OnNpageLast();
	afx_msg void OnBtnAddP();
	afx_msg void OnPg1Update();
	afx_msg void OnChangeInputName();
	afx_msg void OnChangeInputMajor();
	afx_msg void OnChangeInputMobi();
	afx_msg void OnChangeInputAddr();
	afx_msg void OnChangeInputHome();
	afx_msg void OnChangeInputMemo();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnSaveEdit1();
	afx_msg void OnDelNowpsn();
	afx_msg void OnSelchangeNameList();
	afx_msg void OnDblclkCtclist(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MPAGE1DLG_H__284EB99B_9789_4F78_9C32_A92448B51B24__INCLUDED_)
