// EditPsnDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contact.h"
#include "EditPsnDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditPsnDlg dialog


CEditPsnDlg::CEditPsnDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditPsnDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEditPsnDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CEditPsnDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditPsnDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEditPsnDlg, CDialog)
	//{{AFX_MSG_MAP(CEditPsnDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditPsnDlg message handlers
