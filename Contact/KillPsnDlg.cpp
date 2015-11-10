// KillPsnDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contact.h"
#include "KillPsnDlg.h"
#include "Person.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKillPsnDlg dialog


CKillPsnDlg::CKillPsnDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CKillPsnDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CKillPsnDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CKillPsnDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CKillPsnDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CKillPsnDlg, CDialog)
	//{{AFX_MSG_MAP(CKillPsnDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKillPsnDlg message handlers

BOOL CKillPsnDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CPerson *p;
	CComboBox *pt=(CComboBox *)GetDlgItem(IDC_KILL_LIST);
	if(nowData.phead!=NULL)
	{
		p=nowData.phead;
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

void CKillPsnDlg::OnOK() 
{
	CPerson *p;
	CString s;
	GetDlgItemText(IDC_KILL_LIST,s);
	if(IDYES==MessageBox("��ȷ��Ҫɾ��������¼��һ��ɾ��֮��Ͳ��ɻָ���","ȷ��ɾ��",MB_ICONQUESTION|MB_YESNO))
	{
		PlaySound((LPCTSTR)IDR_WAVE1, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
		if(nowData.phead!=NULL)
		{
			p=nowData.phead;
			if(p->GetName()==s)
			{
				nowData-=*p;
				MessageBox(s+"��Ա�Ѿ����б���ɾ����","ɾ����Ա",MB_ICONINFORMATION);
				CDialog::OnOK();
				return ;
			}
			while(p->next!=NULL)
			{
				p=p->next;
				if(p->GetName()==s)
				{
					nowData-=*p;
					MessageBox(s+"��Ա�Ѿ����б���ɾ����","ɾ����Ա",MB_ICONINFORMATION);
					CDialog::OnOK();
					return ;
				}
			}
		}
	}
}

void CKillPsnDlg::OnCancel() 
{
	PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
	
	CDialog::OnCancel();
}
