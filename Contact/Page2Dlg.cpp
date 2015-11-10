// Page2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contact.h"
#include "Page2Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPage2Dlg dialog


CPage2Dlg::CPage2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPage2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPage2Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPage2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage2Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPage2Dlg, CDialog)
	//{{AFX_MSG_MAP(CPage2Dlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage2Dlg message handlers
