// ReplaceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contact.h"
#include "ReplaceDlg.h"
#include "Person.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReplaceDlg dialog


CReplaceDlg::CReplaceDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReplaceDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReplaceDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CReplaceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReplaceDlg)
	DDX_Control(pDX, IDC_FIND_LIST, m_flist1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CReplaceDlg, CDialog)
	//{{AFX_MSG_MAP(CReplaceDlg)
	ON_EN_CHANGE(IDC_RP_FIND, OnChangeRpFind)
	ON_BN_CLICKED(IDC_REPLACE, OnReplace)
	ON_BN_CLICKED(IDC_REPLACE_ALL, OnReplaceAll)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReplaceDlg message handlers

BOOL CReplaceDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CComboBox *p=(CComboBox *)GetDlgItem(IDC_REP_IF);
	p->SetCurSel(0);
	//创建图像列表
	m_images.Create(16,16,ILC_COLORDDB,1,1);
	m_images.Add(AfxGetApp()->LoadIcon(IDI_ICON6));
	//建立关联
	m_flist1.SetImageList(&m_images,LVSIL_SMALL);
	m_flist1.SetImageList(&m_images,LVSIL_NORMAL);
	m_flist1.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	return TRUE;
}

void CReplaceDlg::OnOK() 
{
	CPerson *p;
	CString s1,s2;
	GetDlgItemText(IDC_REP_IF,s1);
	GetDlgItemText(IDC_RP_FIND,s2);
	//创建列表控件
	m_flist1.DeleteAllItems();
	while(m_flist1.DeleteColumn(0));
	m_flist1.InsertColumn(0,_T("姓名"),LVCFMT_LEFT,100);
	m_flist1.InsertColumn(1,s1,LVCFMT_LEFT,150);
	m_flist1.SetWindowText(s1);
	if(nowData.phead!=NULL)
	{
		p=nowData.phead;
		if(p->CmpMebValue(s1,s2)>=0)
		{
			m_flist1.InsertItem(m_flist1.GetItemCount(),p->GetName(),0);
			m_flist1.SetItemText(m_flist1.GetItemCount()-1,1,p->GetMebValue(s1));
		}
		while(p->next!=NULL)
		{
			p=p->next;
			if(p->CmpMebValue(s1,s2)>=0)
			{
				m_flist1.InsertItem(m_flist1.GetItemCount(),p->GetName(),0);
				m_flist1.SetItemText(m_flist1.GetItemCount()-1,1,p->GetMebValue(s1));
			}
		}
		if(m_flist1.GetItemCount()>0)
		{
			CButton *bt=(CButton *)GetDlgItem(IDC_REPLACE_ALL);
			bt->EnableWindow(TRUE);
			bt=(CButton *)GetDlgItem(IDC_REPLACE);
			bt->EnableWindow(TRUE);
		}
	}
}

void CReplaceDlg::OnChangeRpFind() 
{
	;
}

void CReplaceDlg::OnReplace() 
{
	CString s1,s2;
	CPerson *p1;
	m_flist1.GetWindowText(s1);
	GetDlgItemText(IDC_RP_REPL,s2);
	if(m_flist1.GetItemCount()>0)
	{
		p1=nowData.phead;
		if(p1->GetName()==m_flist1.GetItemText(m_flist1.GetSelectionMark(),0))
			p1->SetMebValue(s1,s2);
		while(p1->next!=NULL)
		{
			p1=p1->next;
			if(p1->GetName()==m_flist1.GetItemText(m_flist1.GetSelectionMark(),0))
				p1->SetMebValue(s1,s2);
		}
		m_flist1.SetItemText(m_flist1.GetSelectionMark(),1,s2);
	}
}

void CReplaceDlg::OnReplaceAll() 
{
	CPerson *p;
	CString s1,s2,s3;
	GetDlgItemText(IDC_RP_REPL,s1);
	GetDlgItemText(IDC_RP_FIND,s3);
	m_flist1.GetWindowText(s2);
	m_flist1.DeleteAllItems();
	if(nowData.phead!=NULL)
	{
		p=nowData.phead;
		if(p->CmpMebValue(s2,s3)>=0)
		{
			p->SetMebValue(s2,s1);
			m_flist1.InsertItem(m_flist1.GetItemCount(),p->GetName(),0);
			m_flist1.SetItemText(m_flist1.GetItemCount()-1,1,s1);
		}
		while(p->next!=NULL)
		{
			p=p->next;
			if(p->CmpMebValue(s2,s3)>=0)
			{
				p->SetMebValue(s2,s1);
				m_flist1.InsertItem(m_flist1.GetItemCount(),p->GetName(),0);
				m_flist1.SetItemText(m_flist1.GetItemCount()-1,1,s1);
			}
		}
	}
}

void CReplaceDlg::OnCancel() 
{
	PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
	
	CDialog::OnCancel();
}
