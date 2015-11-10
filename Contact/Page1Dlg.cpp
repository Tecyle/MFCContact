// Page1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contact.h"
#include "Page1Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPage1Dlg dialog


CPage1Dlg::CPage1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPage1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPage1Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPage1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage1Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPage1Dlg, CDialog)
	//{{AFX_MSG_MAP(CPage1Dlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage1Dlg message handlers
