// Page4Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contact.h"
#include "Page4Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPage4Dlg dialog


CPage4Dlg::CPage4Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPage4Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPage4Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPage4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage4Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPage4Dlg, CDialog)
	//{{AFX_MSG_MAP(CPage4Dlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage4Dlg message handlers
