// MPage4Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contact.h"
#include "MPage4Dlg.h"
#include "Person.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMPage4Dlg dialog


CMPage4Dlg::CMPage4Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMPage4Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMPage4Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMPage4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMPage4Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMPage4Dlg, CDialog)
	//{{AFX_MSG_MAP(CMPage4Dlg)
	ON_BN_CLICKED(IDC_SEND_EMAIL, OnSendEmail)
	ON_BN_CLICKED(IDC_PG4_UPDATE, OnPg4Update)
	ON_EN_CHANGE(IDC_C_PHONE, OnChangeCPhone)
	ON_EN_CHANGE(IDC_C_MOBI, OnChangeCMobi)
	ON_EN_CHANGE(IDC_C_ADDRESS, OnChangeCAddress)
	ON_EN_CHANGE(IDC_C_POSTCODE, OnChangeCPostcode)
	ON_EN_CHANGE(IDC_C_QQ, OnChangeCQq)
	ON_EN_CHANGE(IDC_C_EMAIL, OnChangeCEmail)
	ON_EN_CHANGE(IDC_C_FAX, OnChangeCFax)
	ON_BN_CLICKED(IDC_SAVE_EDIT4, OnSaveEdit4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMPage4Dlg message handlers

void CMPage4Dlg::OnSendEmail() 
{
	CString s,s1;
	GetDlgItemText(IDC_C_EMAIL,s);
	if(0!=s.GetLength())
	{
		s1.Format("mailto:%s",s);
		ShellExecute(NULL,"open",s1,NULL,NULL,SW_SHOW);
	}
}

void CMPage4Dlg::UpdatePerson()
{
	if(nowData.phead!=NULL)
	{
		SetDlgItemText(IDC_C_PHONE,nowData.nowp->GetPhone());
		SetDlgItemText(IDC_C_MOBI,nowData.nowp->GetMobi());
		SetDlgItemText(IDC_C_ADDRESS,nowData.nowp->GetAddress());
		SetDlgItemText(IDC_C_EMAIL,nowData.nowp->GetEmail());
		SetDlgItemText(IDC_C_QQ,nowData.nowp->GetQQ());
		SetDlgItemText(IDC_C_FAX,nowData.nowp->GetFax());
		SetDlgItemText(IDC_C_POSTCODE,nowData.nowp->GetPostcode());
	}
	CButton *b=(CButton *)GetDlgItem(IDC_SAVE_EDIT4);
	b->EnableWindow(FALSE);
}

void CMPage4Dlg::OnPg4Update() 
{
	UpdatePerson();	
}

void CMPage4Dlg::OnChangeCPhone() 
{
	CButton *p=(CButton *)GetDlgItem(IDC_SAVE_EDIT4);
	p->EnableWindow(TRUE);
}

void CMPage4Dlg::OnChangeCMobi() 
{
	CButton *p=(CButton *)GetDlgItem(IDC_SAVE_EDIT4);
	p->EnableWindow(TRUE);
}

void CMPage4Dlg::OnChangeCAddress() 
{
	CButton *p=(CButton *)GetDlgItem(IDC_SAVE_EDIT4);
	p->EnableWindow(TRUE);
}

void CMPage4Dlg::OnChangeCPostcode() 
{
	CButton *p=(CButton *)GetDlgItem(IDC_SAVE_EDIT4);
	p->EnableWindow(TRUE);
}

void CMPage4Dlg::OnChangeCQq() 
{
	CButton *p=(CButton *)GetDlgItem(IDC_SAVE_EDIT4);
	p->EnableWindow(TRUE);
}

void CMPage4Dlg::OnChangeCEmail() 
{
	CButton *p=(CButton *)GetDlgItem(IDC_SAVE_EDIT4);
	p->EnableWindow(TRUE);
}

void CMPage4Dlg::OnChangeCFax() 
{
	CButton *p=(CButton *)GetDlgItem(IDC_SAVE_EDIT4);
	p->EnableWindow(TRUE);
}

void CMPage4Dlg::OnSaveEdit4() 
{
	CString s;
	if(nowData.phead!=NULL)
	{
		GetDlgItemText(IDC_C_PHONE,s);
		nowData.nowp->SetPhone(s);
		GetDlgItemText(IDC_C_MOBI,s);
		nowData.nowp->SetMobi(s);
		GetDlgItemText(IDC_C_ADDRESS,s);
		nowData.nowp->SetAddress(s);
		GetDlgItemText(IDC_C_QQ,s);
		nowData.nowp->SetQQ(s);
		GetDlgItemText(IDC_C_FAX,s);
		nowData.nowp->SetFax(s);
		GetDlgItemText(IDC_C_EMAIL,s);
		nowData.nowp->SetEmail(s);
		GetDlgItemText(IDC_C_POSTCODE,s);
		nowData.nowp->SetPostcode(s);
		MessageBox("联系方式已经成功保存！","联系方式",MB_ICONINFORMATION);
	}
	UpdatePerson();
}

void CMPage4Dlg::EnableControls()
{
	bool e,f;
	e=nowData.FileOpened;
	f=(nowData.phead==NULL)?false:true;
	CEdit *pe=(CEdit *)GetDlgItem(IDC_C_PHONE);
	CButton *pt=(CButton *)GetDlgItem(IDC_SEND_EMAIL);
	pt->EnableWindow(f?TRUE:FALSE);
	pt=(CButton *)GetDlgItem(IDC_SAVE_EDIT4);
	pt->EnableWindow(f?TRUE:FALSE);
	pt=(CButton *)GetDlgItem(IDC_PG4_UPDATE);
	pt->EnableWindow(f?TRUE:FALSE);
	
	pe->EnableWindow(f?TRUE:FALSE);
	pe=(CEdit *)GetDlgItem(IDC_C_MOBI);
	pe->EnableWindow(f?TRUE:FALSE);
	pe=(CEdit *)GetDlgItem(IDC_C_ADDRESS);
	pe->EnableWindow(f?TRUE:FALSE);
	pe=(CEdit *)GetDlgItem(IDC_C_POSTCODE);
	pe->EnableWindow(f?TRUE:FALSE);
	pe=(CEdit *)GetDlgItem(IDC_C_QQ);
	pe->EnableWindow(f?TRUE:FALSE);
	pe=(CEdit *)GetDlgItem(IDC_C_EMAIL);
	pe->EnableWindow(f?TRUE:FALSE);
	pe=(CEdit *)GetDlgItem(IDC_C_FAX);
	pe->EnableWindow(f?TRUE:FALSE);
}

BOOL CMPage4Dlg::PreTranslateMessage(MSG *pMsg)
{
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_ESCAPE) return TRUE; 
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN) return TRUE; 
	else 
		return CDialog::PreTranslateMessage(pMsg); 
}
