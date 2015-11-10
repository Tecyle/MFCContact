// MPage5Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contact.h"
#include "MPage5Dlg.h"
#include "Person.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMPage5Dlg dialog


CMPage5Dlg::CMPage5Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMPage5Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMPage5Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMPage5Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMPage5Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMPage5Dlg, CDialog)
	//{{AFX_MSG_MAP(CMPage5Dlg)
	ON_BN_CLICKED(IDC_PG5_UPDATE, OnPg5Update)
	ON_BN_CLICKED(IDC_VISIT, OnVisit)
	ON_BN_CLICKED(IDC_SAVE_EDIT5, OnSaveEdit5)
	ON_EN_CHANGE(IDC_M_HOME, OnChangeMHome)
	ON_EN_CHANGE(IDC_M_MEMO, OnChangeMMemo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMPage5Dlg message handlers

void CMPage5Dlg::UpdatePerson()
{
	if(nowData.phead!=NULL)
	{
		SetDlgItemText(IDC_M_HOME,nowData.nowp->GetHomepage());
		SetDlgItemText(IDC_M_MEMO,nowData.nowp->GetMemo());
	}
	CButton *p=(CButton *)GetDlgItem(IDC_SAVE_EDIT5);
	p->EnableWindow(FALSE);
}

void CMPage5Dlg::OnPg5Update() 
{
	UpdatePerson();	
}

void CMPage5Dlg::OnVisit() 
{
	CString s;
	GetDlgItemText(IDC_M_HOME,s);
	if(s.GetLength()==0)
		ShellExecute(NULL,"open","http://www.cau.edu.cn/",NULL,NULL,SW_SHOW);
	else
		ShellExecute(NULL,"open",s,NULL,NULL,SW_SHOW);
}

void CMPage5Dlg::OnSaveEdit5() 
{
	CString s;
	if(nowData.phead!=NULL)
	{
		GetDlgItemText(IDC_M_HOME,s);
		nowData.nowp->SetHomepage(s);
		GetDlgItemText(IDC_M_MEMO,s);
		nowData.nowp->SetMemo(s);
		MessageBox("其它信息已经成功保存！","其它信息",MB_ICONINFORMATION);
	}
	UpdatePerson();
}

void CMPage5Dlg::OnChangeMHome() 
{
	CButton *p=(CButton *)GetDlgItem(IDC_SAVE_EDIT5);
	p->EnableWindow(TRUE);
}

void CMPage5Dlg::OnChangeMMemo() 
{
	CButton *p=(CButton *)GetDlgItem(IDC_SAVE_EDIT5);
	p->EnableWindow(TRUE);
}

void CMPage5Dlg::EnableControls()
{
	bool e,f;
	e=nowData.FileOpened;
	f=(nowData.phead==NULL)?false:true;
	CEdit *pe=(CEdit *)GetDlgItem(IDC_M_HOME);
	CButton *pt=(CButton *)GetDlgItem(IDC_VISIT);
	pt->EnableWindow(f?TRUE:FALSE);
	pt=(CButton *)GetDlgItem(IDC_M_MEMO);
	pt->EnableWindow(f?TRUE:FALSE);
	
	pe->EnableWindow(f?TRUE:FALSE);
	pe=(CEdit *)GetDlgItem(IDC_SAVE_EDIT5);
	pe->EnableWindow(f?TRUE:FALSE);
	pe=(CEdit *)GetDlgItem(IDC_PG5_UPDATE);
	pe->EnableWindow(f?TRUE:FALSE);
}

BOOL CMPage5Dlg::PreTranslateMessage(MSG *pMsg)
{
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_ESCAPE) return TRUE; 
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN) return TRUE; 
	else 
		return CDialog::PreTranslateMessage(pMsg); 
}
