// PosDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contact.h"
#include "PosDlg.h"
#include "Person.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPosDlg dialog


CPosDlg::CPosDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPosDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPosDlg)
	m_cpos = 0;
	//}}AFX_DATA_INIT
}


void CPosDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPosDlg)
	DDX_Text(pDX, IDC_FIND_POS, m_cpos);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPosDlg, CDialog)
	//{{AFX_MSG_MAP(CPosDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPosDlg message handlers

BOOL CPosDlg::OnInitDialog()
{
	CString s;
	CDialog::OnInitDialog();

	s.Format("[%s]数据库中共有%d个联系人。",nowData.GetTitle(),CPerson::mCount);
	SetDlgItemText(IDC_BASE_INFOR,s);

	return TRUE;
}

void CPosDlg::OnOK() 
{
	PlaySound((LPCTSTR)IDR_WAVE1, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
	CDialog::OnOK();
}

void CPosDlg::OnCancel() 
{
	PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);	
	CDialog::OnCancel();
}
