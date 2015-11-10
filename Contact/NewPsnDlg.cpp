// NewPsnDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contact.h"
#include "NewPsnDlg.h"
#include "Person.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewPsnDlg dialog


CNewPsnDlg::CNewPsnDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNewPsnDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewPsnDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CNewPsnDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewPsnDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewPsnDlg, CDialog)
	//{{AFX_MSG_MAP(CNewPsnDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewPsnDlg message handlers

void CNewPsnDlg::OnOK() 
{
	PlaySound((LPCTSTR)IDR_WAVE1, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
	CString str;
	GetDlgItemText(IDC_NP_NAME,str);
	if(!str.GetLength())
	{
		MessageBox(_T("您没有输入您要新建的联系人的姓名，新建的过程无法继续！"),_T("新建联系人"),MB_ICONERROR);
		return;
	}
	CPerson p,*p1;
	if(nowData.phead!=NULL)
	{
		p1=nowData.phead;
		if(str==p1->GetName())
		{
			MessageBox("当前联系人已经存在于数据库，您还是另外想一个名字吧！(*^__^*) ","新建联系人",MB_ICONERROR);
			return ;
		}
		while(p1->next!=NULL)
		{
			p1=p1->next;
			if(str==p1->GetName())
			{
				MessageBox("当前联系人已经存在于数据库，您还是另外想一个名字吧！(*^__^*) ","新建联系人",MB_ICONERROR);
				return ;
			}
		}
	}
	CButton *ptn=(CButton *)GetDlgItem(IDC_NP_R1);
	p.SetName(str);
	str=ptn->GetCheck()?_T("男"):_T("女");
	p.SetSex(str);
	GetDlgItemText(IDC_NP_MAJOR,str);
	p.SetMajor(str);
	GetDlgItemText(IDC_NP_MOBI,str);
	p.SetMobi(str);
	GetDlgItemText(IDC_NP_ADDRESS,str);
	p.SetAddress(str);
	GetDlgItemText(IDC_NP_HOME,str);
	p.SetHomepage(str);
	GetDlgItemText(IDC_NP_MEMO,str);
	p.SetMemo(str);
	nowData+=p;
	str.Format("%s的信息已经成功添加到数据库[%s]中!",p.GetName(),nowData.GetTitle());
	MessageBox(str,"添加成功",MB_ICONINFORMATION);
	CDialog::OnOK();
}

BOOL CNewPsnDlg::OnInitDialog()
{
	CButton *ptn=(CButton *)GetDlgItem(IDC_NP_R1);
	ptn->SetCheck(1);
	CDialog::OnInitDialog();
	return TRUE;
}

void CNewPsnDlg::OnCancel() 
{
	PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
	
	CDialog::OnCancel();
}
