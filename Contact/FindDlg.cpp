// FindDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contact.h"
#include "FindDlg.h"
#include "Person.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFindDlg dialog


CFindDlg::CFindDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFindDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFindDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFindDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFindDlg, CDialog)
	//{{AFX_MSG_MAP(CFindDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFindDlg message handlers

BOOL CFindDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CComboBox *p1=(CComboBox *)GetDlgItem(IDC_FCMB_IF);
	CButton *p2=(CButton *)GetDlgItem(IDC_F_RA1);
	CString s;
	p1->SetCurSel(0);
	p2->SetCheck(1);
	if(nowData.phead!=NULL)
		s.Format("当前: %d / %d ",nowData.nowp->GetID(),CPerson::mCount);
	else
		s="没有数据！";
	SetDlgItemText(IDC_F_INFOR,s);
	return TRUE;
}

void CFindDlg::OnOK() 
{
	CPerson *p1=nowData.nowp;
	CString s,s1;
	CButton *ptn=(CButton *)GetDlgItem(IDC_F_RA1);
	GetDlgItemText(IDC_F_FINDEDIT,s);
	GetDlgItemText(IDC_FCMB_IF,s1);
	if(0==s.GetLength())
	{
		MessageBox("请输入查找内容，有了查找内容，我们就可以为您查找了！","查找",MB_ICONERROR);
		return;
	}
	if(nowData.phead==NULL)
	{
		MessageBox("当前数据库尚未保存任何联系人信息！","查找",MB_ICONERROR);
		return;
	}
	PlaySound((LPCTSTR)IDR_WAVE1, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
	if(ptn->GetCheck())  //向后查找
	{
		while(p1->next!=NULL)
		{
			p1=p1->next;
			if(p1->CmpMebValue(s1,s)>=0)
			{
				nowData.nowp=p1;
				CDialog::OnOK();
				return;
			}
		}
		MessageBox("已经查找到最后一个联系人了，尚未发现可疑目标。系统将定位到第一个联系人处，以便继续查找。","查找",MB_ICONINFORMATION);
		nowData.nowp=nowData.phead;
		CDialog::OnOK();
		return;
	}else{       //向前查找
		while(p1->prev != NULL)
		{
			p1=p1->prev;
			if(p1->CmpMebValue(s1,s)>=0)
			{
				nowData.nowp=p1;
				CDialog::OnOK();
				return;
			}
		}
		MessageBox("已经查找到第一个联系人了，尚未发现可疑目标。系统将定位到最后一个联系人处，以便继续查找。","查找",MB_ICONINFORMATION);
		while(p1->next!=NULL) p1=p1->next;
		nowData.nowp=p1;
		CDialog::OnOK();
		return;
	}	
	CDialog::OnOK();
}

void CFindDlg::OnCancel() 
{
	PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
	
	CDialog::OnCancel();
}
