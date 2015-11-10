// MPage2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contact.h"
#include "MPage2Dlg.h"
#include "Person.h"
#include "NewTeamDlg.h"
#include "KillGrpDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMPage2Dlg dialog


CMPage2Dlg::CMPage2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMPage2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMPage2Dlg)
	m_iyear = 1900;
	m_imonth = 1;
	m_iday = 1;
	//}}AFX_DATA_INIT
}


void CMPage2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMPage2Dlg)
	DDX_Control(pDX, IDC_TLIST, m_tlist);
	DDX_Text(pDX, IDC_EDIT_YEAR, m_iyear);
	DDV_MinMaxInt(pDX, m_iyear, 1900, 2100);
	DDX_Text(pDX, IDC_EDIT_MONTH, m_imonth);
	DDV_MinMaxInt(pDX, m_imonth, 1, 12);
	DDX_Text(pDX, IDC_EDIT_DAY, m_iday);
	DDV_MinMaxInt(pDX, m_iday, 1, 31);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMPage2Dlg, CDialog)
	//{{AFX_MSG_MAP(CMPage2Dlg)
	ON_CBN_EDITCHANGE(IDC_CMB_TEAM, OnEditchangeCmbTeam)
	ON_CBN_SELCHANGE(IDC_CMB_TEAM, OnSelchangeCmbTeam)
	ON_BN_CLICKED(IDC_PG2_UPDATE, OnPg2Update)
	ON_BN_CLICKED(IDC_SAVE_EDIT2, OnSaveEdit2)
	ON_EN_CHANGE(IDC_B_INPUTNAME, OnChangeBInputname)
	ON_EN_CHANGE(IDC_EDIT_YEAR, OnChangeEditYear)
	ON_EN_CHANGE(IDC_EDIT_MONTH, OnChangeEditMonth)
	ON_EN_CHANGE(IDC_EDIT_DAY, OnChangeEditDay)
	ON_EN_CHANGE(IDC_B_INPUTPROV, OnChangeBInputprov)
	ON_BN_CLICKED(IDC_B_MAN, OnBMan)
	ON_BN_CLICKED(IDC_B_WOMAN, OnBWoman)
	ON_CBN_SELCHANGE(IDC_CMB_INPUTTEAM, OnSelchangeCmbInputteam)
	ON_EN_CHANGE(IDC_B_INPUTPOSIT, OnChangeBInputposit)
	ON_BN_CLICKED(IDC_M_NTEAM, OnMNteam)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_NOTIFY(NM_DBLCLK, IDC_TLIST, OnDblclkTlist)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMPage2Dlg message handlers

BOOL CMPage2Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_tlist.InsertColumn(0,_T("姓名"),LVCFMT_LEFT,70);
	m_tlist.InsertColumn(1,_T("性别"),LVCFMT_LEFT,40);
	m_tlist.InsertColumn(2,_T("手机"),LVCFMT_LEFT,100);
	m_tlist.InsertColumn(3,_T("邮箱"),LVCFMT_LEFT,100);
	//创建图像列表
	m_images.Create(16,16,ILC_COLORDDB,1,1);
	m_images.Add(AfxGetApp()->LoadIcon(IDI_ICON6));
	//建立关联
	m_tlist.SetImageList(&m_images,LVSIL_SMALL);
	m_tlist.SetImageList(&m_images,LVSIL_NORMAL);

	m_tlist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	return TRUE;
}

void CMPage2Dlg::UpdateLists()
{
	CComboBox *ptn=(CComboBox *)GetDlgItem(IDC_CMB_TEAM);
	CPGroup *g1;
	//刷新下拉列表
	ptn->ResetContent();
	ptn->AddString("所有");
	ptn->AddString("未分组联系人");
	if(nowData.ghead!=NULL)
	{
		g1=nowData.ghead;
		ptn->AddString(g1->GetName());
		while(g1->next!=NULL)
		{
			g1=g1->next;
			ptn->AddString(g1->GetName());
		}
	}
	ptn->SetCurSel(0);
	ptn=(CComboBox *)GetDlgItem(IDC_CMB_INPUTTEAM);
	ptn->ResetContent();
	ptn->AddString(_T(""));
	if(nowData.ghead!=NULL)
	{
		g1=nowData.ghead;
		ptn->AddString(g1->GetName());
		while(g1->next!=NULL)
		{
			g1=g1->next;
			ptn->AddString(g1->GetName());
		}
	}
}

void CMPage2Dlg::UpdateLists2()
{
	CString s;
	CPerson *p1;

	int nCount;
	GetDlgItemText(IDC_CMB_TEAM,s);
	m_tlist.DeleteAllItems();
	if(nowData.phead!=NULL)
	{
		if(_T("所有")==s)
		{
			p1=nowData.phead;
			m_tlist.InsertItem(0,p1->GetName(),0);
			m_tlist.SetItemText(0,1,p1->GetSex());
			m_tlist.SetItemText(0,2,p1->GetMobi());
			m_tlist.SetItemText(0,3,p1->GetEmail());
			while(p1->next!=NULL)
			{
				p1=p1->next;
				nCount=m_tlist.GetItemCount();
				m_tlist.InsertItem(nCount,p1->GetName(),0);
				m_tlist.SetItemText(nCount,1,p1->GetSex());
				m_tlist.SetItemText(nCount,2,p1->GetMobi());
				m_tlist.SetItemText(nCount,3,p1->GetEmail());
			}
		}else if(_T("未分组联系人")==s){
			p1=nowData.phead;
			if(nowData.nGroup.IsInThisTeam(*p1)){
				m_tlist.InsertItem(0,p1->GetName(),0);
				m_tlist.SetItemText(0,1,p1->GetSex());
				m_tlist.SetItemText(0,2,p1->GetMobi());
				m_tlist.SetItemText(0,3,p1->GetEmail());
			}
			while(p1->next!=NULL)
			{
				p1=p1->next;
				if(nowData.nGroup.IsInThisTeam(*p1)){
					nCount=m_tlist.GetItemCount();
					m_tlist.InsertItem(nCount,p1->GetName(),0);
					m_tlist.SetItemText(nCount,1,p1->GetSex());
					m_tlist.SetItemText(nCount,2,p1->GetMobi());
					m_tlist.SetItemText(nCount,3,p1->GetEmail());
				}
			}
		}else{
			p1=nowData.phead;
			if(p1->GetTeam()==s){
				m_tlist.InsertItem(0,p1->GetName(),0);
				m_tlist.SetItemText(0,1,p1->GetSex());
				m_tlist.SetItemText(0,2,p1->GetMobi());
				m_tlist.SetItemText(0,3,p1->GetEmail());
			}
			while(p1->next!=NULL)
			{
				p1=p1->next;
				if(p1->GetTeam()==s){
					nCount=m_tlist.GetItemCount();
					m_tlist.InsertItem(nCount,p1->GetName(),0);
					m_tlist.SetItemText(nCount,1,p1->GetSex());
					m_tlist.SetItemText(nCount,2,p1->GetMobi());
					m_tlist.SetItemText(nCount,3,p1->GetEmail());
				}
			}
		}
	}
}

void CMPage2Dlg::OnEditchangeCmbTeam() 
{
	UpdateLists2();	
}

void CMPage2Dlg::OnSelchangeCmbTeam() 
{
	UpdateLists2();	
}

void CMPage2Dlg::UpdatePerson()
{
	CString s;
	if(nowData.phead!=NULL)
	{
		SetDlgItemText(IDC_B_INPUTNAME,nowData.nowp->GetName());
		SetDlgItemText(IDC_B_INPUTPROV,nowData.nowp->GetProvince());
		CComboBox *ptr=(CComboBox *)GetDlgItem(IDC_CMB_INPUTTEAM);
		ptr->SetCurSel(ptr->FindString(0,nowData.nowp->GetTeam()));
		SetDlgItemText(IDC_B_INPUTPOSIT,nowData.nowp->GetPosition());
		CButton *ptn=(CButton *)GetDlgItem(IDC_B_MAN);
		ptn->SetCheck(nowData.nowp->GetSex()=="男"?1:0);
		ptn=(CButton *)GetDlgItem(IDC_B_WOMAN);
		ptn->SetCheck(nowData.nowp->GetSex()=="女"?1:0);
		s=nowData.nowp->GetBirthday();
		if(0!=s.GetLength())
		{
			SetDlgItemText(IDC_EDIT_YEAR,s.Left(4));
			SetDlgItemText(IDC_EDIT_MONTH,s.Mid(5,2));
			SetDlgItemText(IDC_EDIT_DAY,s.Right(2));
		}else{
			SetDlgItemText(IDC_EDIT_YEAR,_T("1900"));
			SetDlgItemText(IDC_EDIT_MONTH,_T("01"));
			SetDlgItemText(IDC_EDIT_DAY,_T("01"));
		}
	}
	CButton *ftn=(CButton *)GetDlgItem(IDC_SAVE_EDIT2);
	ftn->EnableWindow(FALSE);
}

void CMPage2Dlg::OnPg2Update() 
{
	UpdatePerson();	
}

void CMPage2Dlg::OnSaveEdit2() 
{
	CString s,s1,s2,s3;
	int i,m;
	//年份有效性判断
	GetDlgItemText(IDC_EDIT_YEAR,s);
	if(s.GetAt(0)=='0')
		s=s.Right(s.GetLength()-1);
	if(s.GetLength()!=4)
	{
		MessageBox("您输入的年份有问题，请确认后重新输入。年份应该是一个四位整数。","基本信息",MB_ICONERROR);
		return;
	}
	for(i=0;i<4;i++)
	{
		if(s.GetAt(i)<'0' || s.GetAt(i)>'9')
		{
			MessageBox("您输入的年份有问题，请确认后重新输入。年份应该是一个四位整数。","基本信息",MB_ICONERROR);
			return;
		}
	}
	//月份有效性判断
	GetDlgItemText(IDC_EDIT_MONTH,s);
	if(s.GetLength()>2 || s.GetLength()==0)
	{
		MessageBox("您输入的月份有问题，请确认后重新输入。月份应该是一个1 ~ 12之间整数。","基本信息",MB_ICONERROR);
		return;
	}
	if(s.GetLength()==1) s.Format("0%c",s.GetAt(0));
	for(i=0;i<2;i++)
	{
		if(s.GetAt(i)<'0' || s.GetAt(i)>'9')
		{
			MessageBox("您输入的月份有问题，请确认后重新输入。月份应该是一个1 ~ 12之间整数。","基本信息",MB_ICONERROR);
			return;
		}
	}
	m=atoi((LPCTSTR)s);
	if(m<1 || m>12)
	{
		MessageBox("您输入的月份有问题，请确认后重新输入。月份应该是一个1 ~ 12之间整数。",s);//"基本信息",MB_ICONERROR);
		return;
	}
	SetDlgItemText(IDC_EDIT_MONTH,s);
	//日的有效性判断
	GetDlgItemText(IDC_EDIT_DAY,s);
	if(s.GetLength()>2 || s.GetLength()==0)
	{
		MessageBox("您输入的日数有问题，请确认后重新输入。日数应该是一个1 ~ 31之间整数。","基本信息",MB_ICONERROR);
		return;
	}
	if(s.GetLength()==1) s.Format("0%c",s.GetAt(0));
	for(i=0;i<2;i++)
	{
		if(s.GetAt(i)<'0' || s.GetAt(i)>'9')
		{
			MessageBox("您输入的日数有问题，请确认后重新输入。日数应该是一个1 ~ 31之间整数。","基本信息",MB_ICONERROR);
			return;
		}
	}
	m=atoi((LPCTSTR)s);
	if(m<1 || m>31)
	{
		MessageBox("您输入的日数有问题，请确认后重新输入。日数应该是一个1 ~ 31之间整数。","基本信息",MB_ICONERROR);
		return;
	}
	SetDlgItemText(IDC_EDIT_DAY,s);
	//保存数据
	if(nowData.phead!=NULL)
	{
		GetDlgItemText(IDC_B_INPUTNAME,s);
		nowData.nowp->SetName(s);
		GetDlgItemText(IDC_B_INPUTPROV,s);
		nowData.nowp->SetProvince(s);
		GetDlgItemText(IDC_CMB_INPUTTEAM,s);
		nowData.nowp->SetTeam(s);
		GetDlgItemText(IDC_B_INPUTPOSIT,s);
		nowData.nowp->SetPosition(s);
		GetDlgItemText(IDC_EDIT_YEAR,s);
		GetDlgItemText(IDC_EDIT_MONTH,s1);
		GetDlgItemText(IDC_EDIT_DAY,s2);
		s3.Format("%s-%s-%s",s,s1,s2);
		nowData.nowp->SetBirthday(s3);
		CButton *ptn=(CButton *)GetDlgItem(IDC_B_MAN);
		s=ptn->GetCheck()?"男":"女";
		nowData.nowp->SetSex(s);
		MessageBox("基本信息已经成功保存！","基本信息",MB_ICONINFORMATION);
	}
	UpdatePerson();
}

void CMPage2Dlg::OnChangeBInputname() 
{
	CButton *p=(CButton *)GetDlgItem(IDC_SAVE_EDIT2);
	p->EnableWindow(TRUE);
}

void CMPage2Dlg::OnChangeEditYear() 
{
	CButton *p=(CButton *)GetDlgItem(IDC_SAVE_EDIT2);
	p->EnableWindow(TRUE);
}

void CMPage2Dlg::OnChangeEditMonth() 
{
	CButton *p=(CButton *)GetDlgItem(IDC_SAVE_EDIT2);
	p->EnableWindow(TRUE);
}

void CMPage2Dlg::OnChangeEditDay() 
{
	CButton *p=(CButton *)GetDlgItem(IDC_SAVE_EDIT2);
	p->EnableWindow(TRUE);
}

void CMPage2Dlg::OnChangeBInputprov() 
{
	CButton *p=(CButton *)GetDlgItem(IDC_SAVE_EDIT2);
	p->EnableWindow(TRUE);
}

void CMPage2Dlg::OnBMan() 
{
	CButton *p=(CButton *)GetDlgItem(IDC_SAVE_EDIT2);
	p->EnableWindow(TRUE);	
}

void CMPage2Dlg::OnBWoman() 
{
	CButton *p=(CButton *)GetDlgItem(IDC_SAVE_EDIT2);
	p->EnableWindow(TRUE);	
}

void CMPage2Dlg::OnSelchangeCmbInputteam() 
{
	CButton *p=(CButton *)GetDlgItem(IDC_SAVE_EDIT2);
	p->EnableWindow(TRUE);	
}

void CMPage2Dlg::OnChangeBInputposit() 
{
	CButton *p=(CButton *)GetDlgItem(IDC_SAVE_EDIT2);
	p->EnableWindow(TRUE);
}

void CMPage2Dlg::OnMNteam() 
{
	CNewTeamDlg dlg;
	if(IDOK==dlg.DoModal())
		;	
}

void CMPage2Dlg::EnableControls()
{
	bool e,f;
	e=nowData.FileOpened;
	f=(nowData.phead==NULL)?false:true;
	CComboBox *pb=(CComboBox *)GetDlgItem(IDC_CMB_TEAM);
	CListCtrl *pl=(CListCtrl *)GetDlgItem(IDC_TLIST);
	CEdit *pe=(CEdit *)GetDlgItem(IDC_B_INPUTNAME);
	CButton *pt=(CButton *)GetDlgItem(IDC_B_MAN);
	pb->EnableWindow(e?TRUE:FALSE);
	pb=(CComboBox *)GetDlgItem(IDC_CMB_INPUTTEAM);
	pb->EnableWindow(f?TRUE:FALSE);

	pl->EnableWindow(e?TRUE:FALSE);

	pt->EnableWindow(f?TRUE:FALSE);
	pt=(CButton *)GetDlgItem(IDC_B_WOMAN);
	pt->EnableWindow(f?TRUE:FALSE);
	pt=(CButton *)GetDlgItem(IDC_SAVE_EDIT2);
	pt->EnableWindow(f?TRUE:FALSE);
	pt=(CButton *)GetDlgItem(IDC_PG2_UPDATE);
	pt->EnableWindow(f?TRUE:FALSE);	 
	pt=(CButton *)GetDlgItem(IDC_M_NTEAM);
	pt->EnableWindow(e?TRUE:FALSE);	
	pt=(CButton *)GetDlgItem(IDC_BUTTON4);
	pt->EnableWindow(nowData.ghead!=NULL?TRUE:FALSE);	

	pe->EnableWindow(f?TRUE:FALSE);
	pe=(CEdit *)GetDlgItem(IDC_EDIT_YEAR);
	pe->EnableWindow(f?TRUE:FALSE);
	pe=(CEdit *)GetDlgItem(IDC_EDIT_MONTH);
	pe->EnableWindow(f?TRUE:FALSE);
	pe=(CEdit *)GetDlgItem(IDC_EDIT_DAY);
	pe->EnableWindow(f?TRUE:FALSE);
	pe=(CEdit *)GetDlgItem(IDC_B_INPUTPROV);
	pe->EnableWindow(f?TRUE:FALSE);
	pe=(CEdit *)GetDlgItem(IDC_B_INPUTPOSIT);
	pe->EnableWindow(f?TRUE:FALSE);
}

void CMPage2Dlg::OnButton4() 
{
	CKillGrpDlg dlg;
	if(IDOK==dlg.DoModal())
		UpdateLists();
	UpdatePerson();
}

BOOL CMPage2Dlg::PreTranslateMessage(MSG *pMsg)
{
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_ESCAPE) return TRUE; 
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN) return TRUE; 
	else 
		return CDialog::PreTranslateMessage(pMsg); 
}

void CMPage2Dlg::OnDblclkTlist(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CString s;
	*pResult = 0;
	if(m_tlist.GetSelectionMark()>=0)
	{
		s=m_tlist.GetItemText(m_tlist.GetSelectionMark(),0);
		if(nowData.phead!=NULL)
		{
			nowData.nowp=nowData.phead;
			if(nowData.nowp->GetName()==s)
			{
				UpdatePerson();
				return ;
			}
			while(nowData.nowp->next!=NULL)
			{
				nowData.nowp=nowData.nowp->next;
				if(nowData.nowp->GetName()==s)
				{
					UpdatePerson();
					return ;
				}
			}
		}
	}	
}
