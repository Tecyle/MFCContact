// ChkPswdDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contact.h"
#include "ChkPswdDlg.h"
#include "Person.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChkPswdDlg dialog


CChkPswdDlg::CChkPswdDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChkPswdDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChkPswdDlg)
	m_userpswd = _T("");
	//}}AFX_DATA_INIT
}


void CChkPswdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChkPswdDlg)
	DDX_Text(pDX, IDC_CHK_PSWD, m_userpswd);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CChkPswdDlg, CDialog)
	//{{AFX_MSG_MAP(CChkPswdDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChkPswdDlg message handlers

bool CChkPswdDlg::CheckPswd()
{
	CDatabase tmp;
	tmp.SetFileName(nowData.GetFileName());
	CString str1,str2;
	if(tmp.GetHeadInfor(&m_dataname,&str2))
	{
		this->DoModal();
		if(str2==m_userpswd)
			return true;
		else{
			MessageBox(_T("您输入的密码不正确，真遗憾，本次打开操作失败！"),_T("密码验证失败"),MB_ICONERROR);
			return false;
		}
	}
	return true;
}

void CChkPswdDlg::OnOK()
{
	PlaySound((LPCTSTR)IDR_WAVE1, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
	CDialog::OnOK();
}

BOOL CChkPswdDlg::OnInitDialog()
{
	SetDlgItemText(IDC_CHK_NAME,m_dataname);
	CTreeCtrl ct1;
	return TRUE;
}

void CChkPswdDlg::OnCancel() 
{
	PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);	
	CDialog::OnCancel();
}
