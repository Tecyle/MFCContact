// FPTeamDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contact.h"
#include "FPTeamDlg.h"
#include "Person.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFPTeamDlg dialog


CFPTeamDlg::CFPTeamDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFPTeamDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFPTeamDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFPTeamDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFPTeamDlg)
	DDX_Control(pDX, IDC_LIST2, m_list2);
	DDX_Control(pDX, IDC_LIST1, m_list1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFPTeamDlg, CDialog)
	//{{AFX_MSG_MAP(CFPTeamDlg)
	ON_CBN_SELCHANGE(IDC_CMB_GLIST1, OnSelchangeCmbGlist1)
	ON_CBN_SELCHANGE(IDC_CMB_GLIST2, OnSelchangeCmbGlist2)
	ON_BN_CLICKED(IDC_BTN_TORIGHT, OnBtnToright)
	ON_BN_CLICKED(IDC_BTN_TOLEFT, OnBtnToleft)
	ON_BN_CLICKED(IDC_ALL_TORIGHT, OnAllToright)
	ON_BN_CLICKED(IDC_ALL_TOLEFT, OnAllToleft)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFPTeamDlg message handlers

BOOL CFPTeamDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CPGroup *g;
	CComboBox *p1=(CComboBox *)GetDlgItem(IDC_CMB_GLIST1);
	CComboBox *p2=(CComboBox *)GetDlgItem(IDC_CMB_GLIST2);
	p1->AddString("δ����");
	p2->AddString("δ����");
	if(nowData.ghead!=NULL)
	{
		g=nowData.ghead;
		p1->AddString(g->GetName());
		p2->AddString(g->GetName());
		while(g->next!=NULL)
		{
			g=g->next;
			p1->AddString(g->GetName());
			p2->AddString(g->GetName());
		}
	}
	p1->SetCurSel(0);
	p2->SetCurSel(0);
	ListPerson1();
	ListPerson2();
	return TRUE;
}

void CFPTeamDlg::ListPerson1()
{
	CString s;
	CPerson *p;
	GetDlgItemText(IDC_CMB_GLIST1,s);
	m_list1.ResetContent();
	if(nowData.phead!=NULL)
	{
		p=nowData.phead;
		if("δ����"==s)
		{
			if(p->GetTeam()=="")
				m_list1.AddString(p->GetName());
		}
		else if(p->GetTeam()==s)
			m_list1.AddString(p->GetName());
		while(p->next!=NULL)
		{
			p=p->next;
			if("δ����"==s)
			{
				if(p->GetTeam()=="")
					m_list1.AddString(p->GetName());
			}
			else if(p->GetTeam()==s)
				m_list1.AddString(p->GetName());
		}
	}
}

void CFPTeamDlg::ListPerson2()
{
	CString s;
	CPerson *p;
	GetDlgItemText(IDC_CMB_GLIST2,s);
	m_list2.ResetContent();
	if(nowData.phead!=NULL)
	{
		p=nowData.phead;
		if("δ����"==s)
		{
			if(p->GetTeam()=="") 
				m_list2.AddString(p->GetName());
		}
		else if(p->GetTeam()==s)
			m_list2.AddString(p->GetName());
		while(p->next!=NULL)
		{
			p=p->next;
			if("δ����"==s)
			{
				if(p->GetTeam()=="")
					m_list2.AddString(p->GetName());
			}
			else if(p->GetTeam()==s)
				m_list2.AddString(p->GetName());
		}
	}
}

void CFPTeamDlg::OnSelchangeCmbGlist1() 
{
	ListPerson1();	
}

void CFPTeamDlg::OnSelchangeCmbGlist2() 
{
	ListPerson2();	
}

void CFPTeamDlg::OnBtnToright() 
{
	CString s1,s2,s3;
	CPerson *p;
	int i=m_list1.GetCount();
	
	GetDlgItemText(IDC_CMB_GLIST1,s1);
	GetDlgItemText(IDC_CMB_GLIST2,s2);
	if(s1=="δ����") s1="";
	if(s2=="δ����") s2="";
	if(s1==s2)
	{
		MessageBox("-_-!������ͬһ�����ڲ�����û�����壬�������Բ�ͬ��֮��ĳ�Ա�����ɡ�","���Ա����",MB_ICONSTOP);
		return ;
	}
	if(nowData.phead!=NULL)
	{
		p=nowData.phead;
		if(i>0)
		{
			for(i=0;i<m_list1.GetCount();i++)
			{
				if(m_list1.GetSel(i))
				{
					m_list1.GetText(i,s3);
					if(p->GetName()==s3 && p->GetTeam()==s1)
						p->SetTeam(s2);
					while(p->next!=NULL)
					{
						p=p->next;
						if(p->GetName()==s3 && p->GetTeam()==s1)
							p->SetTeam(s2);
					}
				}
			}
		}else{
			s3.Format("[%s]�������һ����ԱҲû��Ŷ�������Ͳ��ܽ������Ʋ����ˡ�",s1);
			MessageBox(s3,"���Ա����",MB_ICONSTOP);
			return;
		}
	ListPerson1();
	ListPerson2();
	}
}

void CFPTeamDlg::OnBtnToleft() 
{
	CString s1,s2,s3;
	CPerson *p;
	int i=m_list2.GetCount();

	if(s1=="δ����") s1="";
	if(s2=="δ����") s2="";	
	GetDlgItemText(IDC_CMB_GLIST1,s2);
	GetDlgItemText(IDC_CMB_GLIST2,s1);
	if(s1==s2)
	{
		MessageBox("-_-!������ͬһ�����ڲ�����û�����壬�������Բ�ͬ��֮��ĳ�Ա�����ɡ�","���Ա����",MB_ICONSTOP);
		return ;
	}
	if(nowData.phead!=NULL)
	{
		p=nowData.phead;
		if(i>0)
		{
			for(i=0;i<m_list2.GetCount();i++)
			{
				if(m_list2.GetSel(i))
				{
					m_list2.GetText(i,s3);
					if(p->GetName()==s3 && p->GetTeam()==s1)
						p->SetTeam(s2);
					while(p->next!=NULL)
					{
						p=p->next;
						if(p->GetName()==s3 && p->GetTeam()==s1)
							p->SetTeam(s2);
					}
				}
			}
		}else{
			s3.Format("[%s]�������һ����ԱҲû��Ŷ�������Ͳ��ܽ������Ʋ����ˡ�",s1);
			MessageBox(s3,"���Ա����",MB_ICONSTOP);
			return;
		}
	ListPerson1();
	ListPerson2();
	}	
}

void CFPTeamDlg::OnAllToright() 
{
	CString s1,s2,s3;
	CPerson *p1;
	GetDlgItemText(IDC_CMB_GLIST1,s1);
	GetDlgItemText(IDC_CMB_GLIST2,s2);
	if(s1=="δ����") s1="";
	if(s2=="δ����") s2="";
	if(s1==s2)
	{
		MessageBox("-_-!������ͬһ�����ڲ�����û�����壬�������Բ�ͬ��֮��ĳ�Ա�����ɡ�","���Ա����",MB_ICONSTOP);
		return ;
	}
	if(m_list1.GetCount()==0)
	{
		s3.Format("[%s]�������һ����ԱҲû��Ŷ�������Ͳ��ܽ������Ʋ����ˡ�",s1);
		MessageBox(s3,"���Ա����",MB_ICONSTOP);
		return;
	}
	if(nowData.phead!=NULL)
	{
		p1=nowData.phead;
		if(p1->GetTeam()==s1)
			p1->SetTeam(s2);
		while(p1->next!=NULL)
		{
			p1=p1->next;
			if(p1->GetTeam()==s1)
				p1->SetTeam(s2);
		}
	}
	ListPerson1();
	ListPerson2();
}

void CFPTeamDlg::OnAllToleft() 
{
	CString s1,s2,s3;
	CPerson *p1;
	GetDlgItemText(IDC_CMB_GLIST2,s1);
	GetDlgItemText(IDC_CMB_GLIST1,s2);
	if(s1=="δ����") s1="";
	if(s2=="δ����") s2="";
	if(s1==s2)
	{
		MessageBox("-_-!������ͬһ�����ڲ�����û�����壬�������Բ�ͬ��֮��ĳ�Ա�����ɡ�","���Ա����",MB_ICONSTOP);
		return ;
	}
	if(m_list2.GetCount()==0)
	{
		s3.Format("[%s]�������һ����ԱҲû��Ŷ�������Ͳ��ܽ������Ʋ����ˡ�",s1);
		MessageBox(s3,"���Ա����",MB_ICONSTOP);
		return;
	}
	if(nowData.phead!=NULL)
	{
		p1=nowData.phead;
		if(p1->GetTeam()==s1)
			p1->SetTeam(s2);
		while(p1->next!=NULL)
		{
			p1=p1->next;
			if(p1->GetTeam()==s1)
				p1->SetTeam(s2);
		}
	}
	ListPerson1();
	ListPerson2();	
}

void CFPTeamDlg::OnOK() 
{
	PlaySound((LPCTSTR)IDR_WAVE1, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
	
	CDialog::OnOK();
}

void CFPTeamDlg::OnCancel() 
{
	PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
	
	CDialog::OnCancel();
}
