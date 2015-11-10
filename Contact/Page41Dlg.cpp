// Page41Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contact.h"
#include "Page41Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPage41Dlg dialog


CPage41Dlg::CPage41Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPage41Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPage41Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPage41Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage41Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPage41Dlg, CDialog)
	//{{AFX_MSG_MAP(CPage41Dlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage41Dlg message handlers
