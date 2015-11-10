#if !defined(AFX_POSDLG_H__005A8D93_EDBE_4372_BBDC_727550248F34__INCLUDED_)
#define AFX_POSDLG_H__005A8D93_EDBE_4372_BBDC_727550248F34__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PosDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPosDlg dialog

class CPosDlg : public CDialog
{
// Construction
public:
	BOOL OnInitDialog(void);
	CPosDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPosDlg)
	enum { IDD = IDD_D };
	int		m_cpos;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPosDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPosDlg)
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POSDLG_H__005A8D93_EDBE_4372_BBDC_727550248F34__INCLUDED_)
