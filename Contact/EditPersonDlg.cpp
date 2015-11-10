// EditPersonDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contact.h"
#include "EditPersonDlg.h"
#include "Person.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEditPersonDlg dialog


CEditPersonDlg::CEditPersonDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEditPersonDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEditPersonDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CEditPersonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEditPersonDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEditPersonDlg, CDialog)
	//{{AFX_MSG_MAP(CEditPersonDlg)
	ON_CBN_SELCHANGE(IDC_EP_NAME, OnSelchangeEpName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEditPersonDlg message handlers

BOOL CEditPersonDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CPerson *p;
	CComboBox *ptn=(CComboBox *)GetDlgItem(IDC_EP_NAME);
	CButton *p2=(CButton *)GetDlgItem(IDC_EP_RA1);
	p2->SetCheck(1);
	if(nowData.phead!=NULL)
	{
		p=nowData.phead;
		ptn->AddString(p->GetName());
		while(p->next!=NULL)
		{
			p=p->next;
			ptn->AddString(p->GetName());
		}
	}
	ptn->SetCurSel(0);
	ListPerson();
	return TRUE;
}

void CEditPersonDlg::OnOK() 
{
	CButton *pt=(CButton *)GetDlgItem(IDC_EP_RA1);
	CString s;
	CPerson *p;
	GetDlgItemText(IDC_EP_NAME,s);
	if(nowData.phead!=NULL)
	{
		p=nowData.phead;
		if(p->GetName()==s)
		{
			GetDlgItemText(IDC_EP_MAJOR,s);
			p->SetMajor(s);
			GetDlgItemText(IDC_EP_MOBI,s);
			p->SetMobi(s);
			GetDlgItemText(IDC_EP_HOME,s);
			p->SetHomepage(s);
			GetDlgItemText(IDC_EP_MEMO,s);
			p->SetMemo(s);
			GetDlgItemText(IDC_EP_ADDRESS,s);
			p->SetAddress(s);
			s=pt->GetCheck()?"男":"女";
			p->SetSex(s);
			MessageBox("已经成功保存！","编辑联系人",MB_ICONINFORMATION);
			CDialog::OnOK();
			return ;
		}
		while(p->next!=NULL)
		{
			p=p->next;
			if(p->GetName()==s)
			{
				GetDlgItemText(IDC_EP_MAJOR,s);
				p->SetMajor(s);
				GetDlgItemText(IDC_EP_MOBI,s);
				p->SetMobi(s);
				GetDlgItemText(IDC_EP_HOME,s);
				p->SetHomepage(s);
				GetDlgItemText(IDC_EP_MEMO,s);
				p->SetMemo(s);
				GetDlgItemText(IDC_EP_ADDRESS,s);
				p->SetAddress(s);
				s=pt->GetCheck()?"男":"女";
				p->SetSex(s);
				MessageBox("已经成功保存！","编辑联系人",MB_ICONINFORMATION);
				PlaySound((LPCTSTR)IDR_WAVE1, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
				CDialog::OnOK();
				return ;
			}
		}
	}
}

void CEditPersonDlg::ListPerson()
{
	CString s;
	CPerson *p;
	CButton *pt=(CButton *)GetDlgItem(IDC_EP_RA1);
	GetDlgItemText(IDC_EP_NAME,s);
	if(nowData.phead!=NULL)
	{
		p=nowData.phead;
		if(p->GetName()==s)
		{
			SetDlgItemText(IDC_EP_MAJOR,p->GetMajor());
			SetDlgItemText(IDC_EP_MOBI,p->GetMobi());
			SetDlgItemText(IDC_EP_HOME,p->GetHomepage());
			SetDlgItemText(IDC_EP_MEMO,p->GetMemo());
			SetDlgItemText(IDC_EP_ADDRESS,p->GetAddress());
			SetDlgItemText(IDC_EP_MAJOR,p->GetMajor());
			pt=(CButton *)GetDlgItem(IDC_EP_RA1);
			pt->SetCheck(p->GetSex()=="男"?1:0);
			pt=(CButton *)GetDlgItem(IDC_EP_RA2);
			pt->SetCheck(p->GetSex()=="女"?1:0);
			return;
		}
		while(p->next!=NULL)
		{
			p=p->next;
			if(p->GetName()==s)
			{
				SetDlgItemText(IDC_EP_MAJOR,p->GetMajor());
				SetDlgItemText(IDC_EP_MOBI,p->GetMobi());
				SetDlgItemText(IDC_EP_HOME,p->GetHomepage());
				SetDlgItemText(IDC_EP_MEMO,p->GetMemo());
				SetDlgItemText(IDC_EP_ADDRESS,p->GetAddress());
				SetDlgItemText(IDC_EP_MAJOR,p->GetMajor());
				pt=(CButton *)GetDlgItem(IDC_EP_RA1);
				pt->SetCheck(p->GetSex()=="男"?1:0);
				pt=(CButton *)GetDlgItem(IDC_EP_RA2);
				pt->SetCheck(p->GetSex()=="女"?1:0);
				return;
			}
		}
	}
}

void CEditPersonDlg::OnSelchangeEpName() 
{
	ListPerson();	
}

void CEditPersonDlg::OnCancel() 
{
	PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);	
	CDialog::OnCancel();
}
