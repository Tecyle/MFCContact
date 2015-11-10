// MPage3Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contact.h"
#include "MPage3Dlg.h"
#include "Person.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMPage3Dlg dialog


CMPage3Dlg::CMPage3Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMPage3Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMPage3Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMPage3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMPage3Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMPage3Dlg, CDialog)
	//{{AFX_MSG_MAP(CMPage3Dlg)
	ON_BN_CLICKED(IDC_PG3_UPDATE, OnPg3Update)
	ON_BN_CLICKED(IDC_SAVE_EDIT3, OnSaveEdit3)
	ON_EN_CHANGE(IDC_S_MAJOR, OnChangeSMajor)
	ON_EN_CHANGE(IDC_S_SCHOOL, OnChangeSSchool)
	ON_EN_CHANGE(IDC_S_CLASS, OnChangeSClass)
	ON_EN_CHANGE(IDC_S_COLLEGE, OnChangeSCollege)
	ON_EN_CHANGE(IDC_S_GRADE, OnChangeSGrade)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMPage3Dlg message handlers

void CMPage3Dlg::UpdatePerson()
{
	if(nowData.phead!=NULL)
	{
		SetDlgItemText(IDC_S_MAJOR,nowData.nowp->GetMajor());
		SetDlgItemText(IDC_S_SCHOOL,nowData.nowp->GetSchool());
		SetDlgItemText(IDC_S_GRADE,nowData.nowp->GetGrade());
		SetDlgItemText(IDC_S_CLASS,nowData.nowp->GetClass());
		SetDlgItemText(IDC_S_COLLEGE,nowData.nowp->GetCollege());
	}
	CButton *p=(CButton *)GetDlgItem(IDC_SAVE_EDIT3);
	p->EnableWindow(FALSE);
}

void CMPage3Dlg::OnPg3Update() 
{
	UpdatePerson();	
}

void CMPage3Dlg::OnSaveEdit3() 
{
	CString s;
	if(nowData.phead!=NULL)
	{
		GetDlgItemText(IDC_S_MAJOR,s);
		nowData.nowp->SetMajor(s);
		GetDlgItemText(IDC_S_COLLEGE,s);
		nowData.nowp->SetCollege(s);
		GetDlgItemText(IDC_S_SCHOOL,s);
		nowData.nowp->SetSchool(s);
		GetDlgItemText(IDC_S_GRADE,s);
		nowData.nowp->SetGrade(s);
		GetDlgItemText(IDC_S_CLASS,s);
		nowData.nowp->SetClass(s);
		MessageBox("学籍信息已经成功保存！","学籍信息",MB_ICONINFORMATION);
	}
	CButton *p=(CButton *)GetDlgItem(IDC_SAVE_EDIT3);
	p->EnableWindow(FALSE);
}

void CMPage3Dlg::OnChangeSMajor() 
{
	CButton *p=(CButton *)GetDlgItem(IDC_SAVE_EDIT3);
	p->EnableWindow(TRUE);
}

void CMPage3Dlg::OnChangeSSchool() 
{
	CButton *p=(CButton *)GetDlgItem(IDC_SAVE_EDIT3);
	p->EnableWindow(TRUE);
}

void CMPage3Dlg::OnChangeSClass() 
{
	CButton *p=(CButton *)GetDlgItem(IDC_SAVE_EDIT3);
	p->EnableWindow(TRUE);
}

void CMPage3Dlg::OnChangeSCollege() 
{
	CButton *p=(CButton *)GetDlgItem(IDC_SAVE_EDIT3);
	p->EnableWindow(TRUE);
}

void CMPage3Dlg::OnChangeSGrade() 
{
	CButton *p=(CButton *)GetDlgItem(IDC_SAVE_EDIT3);
	p->EnableWindow(TRUE);
}

void CMPage3Dlg::EnableControls()
{
	bool e,f;
	e=nowData.FileOpened;
	f=(nowData.phead==NULL)?false:true;
	CEdit *pe=(CEdit *)GetDlgItem(IDC_S_MAJOR);
	CButton *pt=(CButton *)GetDlgItem(IDC_SAVE_EDIT3);
	pt->EnableWindow(f?TRUE:FALSE);
	pt=(CButton *)GetDlgItem(IDC_PG3_UPDATE);
	pt->EnableWindow(f?TRUE:FALSE);
	
	pe->EnableWindow(f?TRUE:FALSE);
	pe=(CEdit *)GetDlgItem(IDC_S_SCHOOL);
	pe->EnableWindow(f?TRUE:FALSE);
	pe=(CEdit *)GetDlgItem(IDC_S_CLASS);
	pe->EnableWindow(f?TRUE:FALSE);
	pe=(CEdit *)GetDlgItem(IDC_S_COLLEGE);
	pe->EnableWindow(f?TRUE:FALSE);
	pe=(CEdit *)GetDlgItem(IDC_S_GRADE);
	pe->EnableWindow(f?TRUE:FALSE);
}

BOOL CMPage3Dlg::PreTranslateMessage(MSG *pMsg)
{
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_ESCAPE) return TRUE; 
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN) return TRUE; 
	else 
		return CDialog::PreTranslateMessage(pMsg); 
}
