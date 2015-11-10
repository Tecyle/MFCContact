// Page3Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contact.h"
#include "Page3Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPage3Dlg dialog


CPage3Dlg::CPage3Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPage3Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPage3Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPage3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage3Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPage3Dlg, CDialog)
	//{{AFX_MSG_MAP(CPage3Dlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage3Dlg message handlers
