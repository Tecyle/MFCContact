// NewTeamDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contact.h"
#include "NewTeamDlg.h"
#include "Person.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewTeamDlg dialog


CNewTeamDlg::CNewTeamDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNewTeamDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewTeamDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CNewTeamDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewTeamDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewTeamDlg, CDialog)
	//{{AFX_MSG_MAP(CNewTeamDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewTeamDlg message handlers

void CNewTeamDlg::OnOK() 
{
	PlaySound((LPCTSTR)IDR_WAVE1, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
	CString s,s1;
	CPGroup *g1;
	GetDlgItemText(IDC_EDIT_NTEAM,s);
	if(nowData.ghead!=NULL)
	{
		g1=nowData.ghead;
		if(g1->GetName()==s)
		{
			s1.Format("[%s]组已经存在与当前数据库中，请另外再想一个组名。",s);
			MessageBox(s1,"新建分组",MB_ICONERROR);
			return;
		}
		while(g1->next!=NULL)
		{
			g1=g1->next;
			if(g1->GetName()==s)
			{
				s1.Format("[%s]组已经存在与当前数据库中，请另外再想一个组名。",s);
				MessageBox(s1,"新建分组",MB_ICONERROR);
				return;
			}
		}
	}
	g1=new CPGroup;
	g1->SetName(s);
	nowData+=(*g1);
	CDialog::OnOK();
}

void CNewTeamDlg::OnCancel() 
{
	PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
	
	CDialog::OnCancel();
}
