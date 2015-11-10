// EditPswdDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contact.h"
#include "EditPswdDlg.h"
#include "Person.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditPswdDlg dialog


CEditPswdDlg::CEditPswdDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditPswdDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEditPswdDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CEditPswdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditPswdDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEditPswdDlg, CDialog)
	//{{AFX_MSG_MAP(CEditPswdDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditPswdDlg message handlers

void CEditPswdDlg::OnOK() 
{
	CString s1,s2,s3;
	GetDlgItemText(IDC_OLD_PSWD,s1);
	GetDlgItemText(IDC_NEW_PSWD1,s2);
	GetDlgItemText(IDC_NEW_PSWD2,s3);
	if(0==s2.GetLength())
	{
		if(IDNO==MessageBox("您当前把新的密码设置为空，这样对您的数据库安全会造成隐患，您确定要这么做吗？\n选“是”设置空密码，选“否”设置其它密码。","修改密码",MB_YESNO|MB_ICONQUESTION))
			return ;
	}
	if(s1!=nowData.GetPswd())
	{
		MessageBox("您输入的旧密码不正确，无法修改密码！请确认后重新输入。","修改密码",MB_ICONERROR);
		return ;
	}
	if(s2!=s3)
	{
		MessageBox("-_-！您两次输入的密码不一致，请检查之后重新输入。密码严格区分大小写。","修改密码",MB_ICONERROR);
		return ;
	}
	nowData.SetPswd(s2);
	MessageBox("密码修改成功！请记住您新设置的密码。","修改密码",MB_ICONINFORMATION);
	PlaySound((LPCTSTR)IDR_WAVE1, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
	CDialog::OnOK();
}

void CEditPswdDlg::OnCancel() 
{
	PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);	
	CDialog::OnCancel();
}
