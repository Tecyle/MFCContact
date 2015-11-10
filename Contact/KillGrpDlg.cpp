// KillGrpDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contact.h"
#include "KillGrpDlg.h"
#include "Person.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKillGrpDlg dialog


CKillGrpDlg::CKillGrpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CKillGrpDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CKillGrpDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CKillGrpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CKillGrpDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CKillGrpDlg, CDialog)
	//{{AFX_MSG_MAP(CKillGrpDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKillGrpDlg message handlers

BOOL CKillGrpDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CComboBox *pt=(CComboBox *)GetDlgItem(IDC_KILL_GLIST);
	CPGroup *p;
	if(nowData.ghead!=NULL)
	{
		p=nowData.ghead;
		pt->AddString(p->GetName());
		while(p->next!=NULL)
		{
			p=p->next;
			pt->AddString(p->GetName());
		}
		pt->SetCurSel(0);
	}
	return TRUE;
}

void CKillGrpDlg::OnOK() 
{
	CString s,s1="";
	CPGroup g;
	CPerson *p;
	if(IDYES==MessageBox("您确定要删除这个分组信息吗？一旦删除之后就不可恢复。","确认删除",MB_ICONQUESTION|MB_YESNO))
	{
		GetDlgItemText(IDC_KILL_GLIST,s);
		g.SetName(s);
		nowData-=g;
		if(nowData.phead!=NULL)
		{
			p=nowData.phead;
			if(p->GetTeam()==s)
				p->SetTeam(s1);
			while(p->next!=NULL)
			{
				p=p->next;
				if(p->GetTeam()==s)
					p->SetTeam(s1);
			}
		}
		MessageBox("["+s+"]联系组已经从数据库中删除，组中的成员被移动至[未分组的联系人]。","删除联系组",MB_ICONINFORMATION);
		PlaySound((LPCTSTR)IDR_WAVE1, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
		CDialog::OnOK();
	}
}

void CKillGrpDlg::OnCancel() 
{
	PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
	CDialog::OnCancel();
}
