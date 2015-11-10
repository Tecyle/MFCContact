// SwAllDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contact.h"
#include "SwAllDlg.h"
#include "Person.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSwAllDlg dialog


CSwAllDlg::CSwAllDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSwAllDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSwAllDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSwAllDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSwAllDlg)
	DDX_Control(pDX, IDC_LIST2, m_plist);
	DDX_Control(pDX, IDC_LIST1, m_glist);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSwAllDlg, CDialog)
	//{{AFX_MSG_MAP(CSwAllDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSwAllDlg message handlers

BOOL CSwAllDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_glist.InsertColumn(0,"分组名",LVCFMT_LEFT,150);
	m_glist.InsertColumn(1,"包含成员个数",LVCFMT_LEFT,150);
	m_plist.InsertColumn(0,"ID",LVCFMT_LEFT,30);
	m_plist.InsertColumn(1,"姓名",LVCFMT_LEFT,100);
	m_plist.InsertColumn(2,"出生日期",LVCFMT_LEFT,80);
	m_plist.InsertColumn(3,"籍贯",LVCFMT_LEFT,80);
	m_plist.InsertColumn(4,"性别",LVCFMT_LEFT,30);
	m_plist.InsertColumn(5,"所属分组",LVCFMT_LEFT,80);
	m_plist.InsertColumn(6,"职务",LVCFMT_LEFT,80);
	m_plist.InsertColumn(7,"专业",LVCFMT_LEFT,80);
	m_plist.InsertColumn(8,"学校",LVCFMT_LEFT,100);
	m_plist.InsertColumn(9,"班级",LVCFMT_LEFT,80);
	m_plist.InsertColumn(10,"院系",LVCFMT_LEFT,100);
	m_plist.InsertColumn(11,"年级",LVCFMT_LEFT,40);
	m_plist.InsertColumn(12,"家庭电话",LVCFMT_LEFT,60);
	m_plist.InsertColumn(13,"手机",LVCFMT_LEFT,60);
	m_plist.InsertColumn(14,"家庭住址",LVCFMT_LEFT,120);
	m_plist.InsertColumn(15,"邮编",LVCFMT_LEFT,60);
	m_plist.InsertColumn(16,"QQ",LVCFMT_LEFT,60);
	m_plist.InsertColumn(17,"电子邮箱",LVCFMT_LEFT,100);
	m_plist.InsertColumn(18,"传真",LVCFMT_LEFT,60);
	m_plist.InsertColumn(19,"个人主页",LVCFMT_LEFT,120);
	m_plist.InsertColumn(20,"备注",LVCFMT_LEFT,150);
	m_plist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	m_glist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	UpdateLists();
	return TRUE;
}

void CSwAllDlg::UpdateLists()
{
	CPerson *p;
	CPGroup *g;
	CString s;
	m_plist.DeleteAllItems();
	m_glist.DeleteAllItems();
	//获得分组信息
	m_glist.InsertItem(0,"未分组",0);
	s.Format("%d",GetTeamMebCount(""));
	m_glist.SetItemText(0,1,s);
	if(nowData.ghead!=NULL)
	{
		g=nowData.ghead;
		m_glist.InsertItem(m_glist.GetItemCount(),g->GetName(),0);
		s.Format("%d",GetTeamMebCount(g->GetName()));
		m_glist.SetItemText(m_glist.GetItemCount()-1,1,s);
		while(g->next!=NULL)
		{
			g=g->next;
			m_glist.InsertItem(m_glist.GetItemCount(),g->GetName(),0);
			s.Format("%d",GetTeamMebCount(g->GetName()));
			m_glist.SetItemText(m_glist.GetItemCount()-1,1,s);
		}
	}
	//获取成员信息
	if(nowData.phead!=NULL)
	{
		p=nowData.phead;
		s.Format("%d",p->GetID());
		m_plist.InsertItem(m_plist.GetItemCount(),s,0);
		m_plist.SetItemText(m_plist.GetItemCount()-1,1,p->GetName());
		m_plist.SetItemText(m_plist.GetItemCount()-1,2,p->GetBirthday());
		m_plist.SetItemText(m_plist.GetItemCount()-1,3,p->GetProvince());
		m_plist.SetItemText(m_plist.GetItemCount()-1,4,p->GetSex());
		m_plist.SetItemText(m_plist.GetItemCount()-1,5,p->GetTeam());
		m_plist.SetItemText(m_plist.GetItemCount()-1,6,p->GetPosition());
		m_plist.SetItemText(m_plist.GetItemCount()-1,7,p->GetMajor());
		m_plist.SetItemText(m_plist.GetItemCount()-1,8,p->GetSchool());
		m_plist.SetItemText(m_plist.GetItemCount()-1,9,p->GetClass());
		m_plist.SetItemText(m_plist.GetItemCount()-1,10,p->GetCollege());
		m_plist.SetItemText(m_plist.GetItemCount()-1,11,p->GetGrade());
		m_plist.SetItemText(m_plist.GetItemCount()-1,12,p->GetPhone());
		m_plist.SetItemText(m_plist.GetItemCount()-1,13,p->GetMobi());
		m_plist.SetItemText(m_plist.GetItemCount()-1,14,p->GetAddress());
		m_plist.SetItemText(m_plist.GetItemCount()-1,15,p->GetPostcode());
		m_plist.SetItemText(m_plist.GetItemCount()-1,16,p->GetQQ());
		m_plist.SetItemText(m_plist.GetItemCount()-1,17,p->GetEmail());
		m_plist.SetItemText(m_plist.GetItemCount()-1,18,p->GetFax());
		m_plist.SetItemText(m_plist.GetItemCount()-1,19,p->GetHomepage());
		m_plist.SetItemText(m_plist.GetItemCount()-1,20,p->GetMemo());
		while(p->next!=NULL)
		{
			p=p->next;
			s.Format("%d",p->GetID());
			m_plist.InsertItem(m_plist.GetItemCount(),s,0);
			m_plist.SetItemText(m_plist.GetItemCount()-1,1,p->GetName());
			m_plist.SetItemText(m_plist.GetItemCount()-1,2,p->GetBirthday());
			m_plist.SetItemText(m_plist.GetItemCount()-1,3,p->GetProvince());
			m_plist.SetItemText(m_plist.GetItemCount()-1,4,p->GetSex());
			m_plist.SetItemText(m_plist.GetItemCount()-1,5,p->GetTeam());
			m_plist.SetItemText(m_plist.GetItemCount()-1,6,p->GetPosition());
			m_plist.SetItemText(m_plist.GetItemCount()-1,7,p->GetMajor());
			m_plist.SetItemText(m_plist.GetItemCount()-1,8,p->GetSchool());
			m_plist.SetItemText(m_plist.GetItemCount()-1,9,p->GetClass());
			m_plist.SetItemText(m_plist.GetItemCount()-1,10,p->GetCollege());
			m_plist.SetItemText(m_plist.GetItemCount()-1,11,p->GetGrade());
			m_plist.SetItemText(m_plist.GetItemCount()-1,12,p->GetPhone());
			m_plist.SetItemText(m_plist.GetItemCount()-1,13,p->GetMobi());
			m_plist.SetItemText(m_plist.GetItemCount()-1,14,p->GetAddress());
			m_plist.SetItemText(m_plist.GetItemCount()-1,15,p->GetPostcode());
			m_plist.SetItemText(m_plist.GetItemCount()-1,16,p->GetQQ());
			m_plist.SetItemText(m_plist.GetItemCount()-1,17,p->GetEmail());
			m_plist.SetItemText(m_plist.GetItemCount()-1,18,p->GetFax());
			m_plist.SetItemText(m_plist.GetItemCount()-1,19,p->GetHomepage());
			m_plist.SetItemText(m_plist.GetItemCount()-1,20,p->GetMemo());
		}
	}
	//数据库信息
	SetDlgItemText(IDC_DATA_NAME,nowData.GetTitle());
	s.Format("%d",CPGroup::memNum);
	SetDlgItemText(IDC_TEAM_COUNT,s);
	s.Format("%d",CPerson::mCount);
	SetDlgItemText(IDC_REC_COUNT,s);
}

void CSwAllDlg::OnCancel() 
{
	PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
	
	CDialog::OnCancel();
}
