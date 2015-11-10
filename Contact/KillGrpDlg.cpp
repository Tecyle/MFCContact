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
	if(IDYES==MessageBox("��ȷ��Ҫɾ�����������Ϣ��һ��ɾ��֮��Ͳ��ɻָ���","ȷ��ɾ��",MB_ICONQUESTION|MB_YESNO))
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
		MessageBox("["+s+"]��ϵ���Ѿ������ݿ���ɾ�������еĳ�Ա���ƶ���[δ�������ϵ��]��","ɾ����ϵ��",MB_ICONINFORMATION);
		PlaySound((LPCTSTR)IDR_WAVE1, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
		CDialog::OnOK();
	}
}

void CKillGrpDlg::OnCancel() 
{
	PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
	CDialog::OnCancel();
}
