// ContactDlg.h : header file
//

#if !defined(AFX_CONTACTDLG_H__D151C45A_32E0_41C3_8387_E783B02DB68A__INCLUDED_)
#define AFX_CONTACTDLG_H__D151C45A_32E0_41C3_8387_E783B02DB68A__INCLUDED_

#include "MPage4Dlg.h"	// Added by ClassView
#include "MPage1Dlg.h"	// Added by ClassView
#include "MPage2Dlg.h"
#include "MPage3Dlg.h"	// Added by ClassView
#include "MPage5Dlg.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CContactDlg dialog

class CContactDlg : public CDialog
{
// Construction
public:
	void OnCancel();
	void OnOK();
	void EnableControls(bool opd);
	bool m_findshow;
	bool m_listshow;
	void UpdateTree();
	void OnDestroy();
	CContactDlg(CWnd* pParent = NULL);	// standard constructor
	BOOL PreTranslateMessage(MSG* pMsg);
// Dialog Data
	//{{AFX_DATA(CContactDlg)
	enum { IDD = IDD_CONTACT_DIALOG };
	CTreeCtrl	m_ctree1;
	CTabCtrl	m_mtab;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CContactDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CImageList m_images;
	CMPage5Dlg m_tab5;
	CMPage4Dlg m_tab4;
	CMPage3Dlg m_tab3;
	CMPage2Dlg m_tab2;
	CMPage1Dlg m_tab1;
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CContactDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnHelpAbout();
	afx_msg void OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnFileNew();
	afx_msg void OnFileOpen();
	afx_msg void OnFileExit();
	afx_msg void OnPersonNew();
	afx_msg void OnFileSave();
	afx_msg void OnBtnSearch();
	afx_msg void OnEditRefresh();
	afx_msg void OnFileSaveas();
	afx_msg void OnFilePack();
	afx_msg void OnToolNotepad();
	afx_msg void OnToolCalc();
	afx_msg void OnShowGoto();
	afx_msg void OnShowFirst();
	afx_msg void OnShowLast();
	afx_msg void OnShowNext();
	afx_msg void OnShowPrevious();
	afx_msg void OnShowMain();
	afx_msg void OnShowBaseinfor();
	afx_msg void OnShowStudy();
	afx_msg void OnShowContact();
	afx_msg void OnShowOther();
	afx_msg void OnShowTreeview();
	afx_msg void OnFileFind();
	afx_msg void OnGroupNew();
	afx_msg void OnGroupEdit();
	afx_msg void OnGroupMember();
	afx_msg void OnPersonEdit();
	afx_msg void OnPersonDel();
	afx_msg void OnGroupDel();
	afx_msg void OnHelpWeb();
	afx_msg void OnEditReplace();
	afx_msg void OnToolPswd();
	afx_msg void OnOutCsv();
	afx_msg void OnOutTxt();
	afx_msg void OnInCsv();
	afx_msg void OnFileClose();
	afx_msg void OnInTxt();
	afx_msg void OnToolBirth();
	afx_msg void OnToolShowall();
	afx_msg void OnHelpMemo();
	afx_msg void OnHelpContent();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTACTDLG_H__D151C45A_32E0_41C3_8387_E783B02DB68A__INCLUDED_)
