#if !defined(AFX_INCSVDLG_H__64FB3807_5328_46E1_8487_15E7A8C922B0__INCLUDED_)
#define AFX_INCSVDLG_H__64FB3807_5328_46E1_8487_15E7A8C922B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InCsvDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInCsvDlg dialog

class CInCsvDlg : public CDialog
{
// Construction
public:
	void SetFileName(CString &fn);
	void InitCSVInfor();
	CImageList m_images;
	BOOL OnInitDialog();
	CInCsvDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CInCsvDlg)
	enum { IDD = IDD_IN_CSV };
	CListCtrl	m_clist;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInCsvDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CInCsvDlg)
	afx_msg void OnCsvBrowse();
	afx_msg void OnItemclickRecList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickRecList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchangeCmbRec();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INCSVDLG_H__64FB3807_5328_46E1_8487_15E7A8C922B0__INCLUDED_)
