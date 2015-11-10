// EditTeamDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contact.h"
#include "EditTeamDlg.h"
#include "Person.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditTeamDlg dialog


CEditTeamDlg::CEditTeamDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditTeamDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEditTeamDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CEditTeamDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditTeamDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEditTeamDlg, CDialog)
	//{{AFX_MSG_MAP(CEditTeamDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditTeamDlg message handlers

BOOL CEditTeamDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CComboBox *p=(CComboBox *)GetDlgItem(IDC_CMB_TEAMDOWN);
	CPGroup *g;
	if(nowData.ghead!=NULL)
	{
		g=nowData.ghead;
		p->AddString(g->GetName());
		while(g->next!=NULL)
		{
			g=g->next;
			p->AddString(g->GetName());
		}
		p->SetCurSel(0);
	}
	return TRUE;
}

void CEditTeamDlg::OnOK() 
{
	CString s1,s2,s3;
	CPGroup *g;
	CPerson *p;
	GetDlgItemText(IDC_CMB_TEAMDOWN,s1);
	GetDlgItemText(IDC_EDIT_NEWTN,s2);
	s3=s1;
	if(0==s2.GetLength())
	{
		MessageBox("������������Ҫ�޸ĵ�����Ŷ��o(��_��)o","�༭��",MB_ICONSTOP);
		return;
	}
	//���������������Ч��
	if(nowData.ghead!=NULL)
	{
		g=nowData.ghead;
		if(g->GetName()==s2)
		{
			MessageBox("�����õ������Ѿ����ڣ�������ָ��һ��������","�༭��",MB_ICONERROR);
			return;
		}
		while(g->next!=NULL)
		{
			g=g->next;
			if(g->GetName()==s2)
			{
				MessageBox("�����õ������Ѿ����ڣ�������ָ��һ��������","�༭��",MB_ICONERROR);
				return;
			}
		}
	}
	//����������
	if(nowData.ghead!=NULL)
	{
		g=nowData.ghead;
		if(g->GetName()==s1)
		{
			g->SetName(s2);
			if(nowData.phead!=NULL)
			{
				p=nowData.phead;
				if(p->GetTeam()==s3)
					p->SetTeam(s2);
				while(p->next!=NULL)
				{
					p=p->next;
					p=nowData.phead;
					if(p->GetTeam()==s3)
						p->SetTeam(s2);
				}
			}
			CDialog::OnOK();
			return;
		}
		while(g->next!=NULL)
		{
			g=g->next;
			if(g->GetName()==s1)
			{
				g->SetName(s2);
				if(nowData.phead!=NULL)
				{
					p=nowData.phead;
					if(p->GetTeam()==s3)
						p->SetTeam(s2);
					while(p->next!=NULL)
					{
						p=p->next;
						p=nowData.phead;
						if(p->GetTeam()==s3)
							p->SetTeam(s2);
					}
				}
				PlaySound((LPCTSTR)IDR_WAVE1, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
				CDialog::OnOK();
				return;
			}
		}
	}
	CDialog::OnOK();
}

void CEditTeamDlg::OnCancel() 
{
	PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);	
	CDialog::OnCancel();
}
