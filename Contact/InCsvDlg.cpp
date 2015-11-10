// InCsvDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contact.h"
#include "InCsvDlg.h"
#include <fstream>
#include "Person.h"
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInCsvDlg dialog


CInCsvDlg::CInCsvDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInCsvDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInCsvDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CInCsvDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInCsvDlg)
	DDX_Control(pDX, IDC_REC_LIST, m_clist);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInCsvDlg, CDialog)
	//{{AFX_MSG_MAP(CInCsvDlg)
	ON_BN_CLICKED(IDC_CSV_BROWSE, OnCsvBrowse)
	ON_NOTIFY(HDN_ITEMCLICK, IDC_REC_LIST, OnItemclickRecList)
	ON_NOTIFY(NM_CLICK, IDC_REC_LIST, OnClickRecList)
	ON_CBN_SELCHANGE(IDC_CMB_REC, OnSelchangeCmbRec)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInCsvDlg message handlers

BOOL CInCsvDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	//建立列表
	m_clist.InsertColumn(0,"数据表中的字段",LVCFMT_LEFT,150);
	m_clist.InsertColumn(1,"要绑定的字段",LVCFMT_LEFT,150);
	//创建图像列表
	m_images.Create(16,16,ILC_COLORDDB,1,1);
	m_images.Add(AfxGetApp()->LoadIcon(IDI_ICON6));
	//建立关联
	m_clist.SetImageList(&m_images,LVSIL_SMALL);
	m_clist.SetImageList(&m_images,LVSIL_NORMAL);
	m_clist.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	OnCsvBrowse();
	return TRUE;
}

CString GetBDString(CString s)
{
	CString cs[20];
	cs[0]="姓名";
	cs[1]="出生日期";
	cs[2]="籍贯";
	cs[3]="性别";
	cs[4]="所属分组";
	cs[5]="职务";
	cs[6]="专业";
	cs[7]="学校";
	cs[8]="班级";
	cs[9]="院系";
	cs[10]="年级";
	cs[11]="家庭电话";
	cs[12]="手机";
	cs[13]="家庭住址";
	cs[14]="邮编";
	cs[15]="QQ";
	cs[16]="电子邮箱";
	cs[17]="传真";
	cs[18]="个人主页";
	cs[19]="备注";
	int i;
	for(i=0;i<20;i++)
		if(cs[i].Find(s)>=0 || s.Find(cs[i])>=0)
			return cs[i];
	return "";
}

void CInCsvDlg::InitCSVInfor()
{
	CString s1,s2,s3;
	char ch[2048];
	int i=0,j=0,k=0;
	ifstream f;
	GetDlgItemText(IDC_CSV_FILE,s1);
	if(s1.GetLength()>0)
	{
		s2=s1.Right(s1.GetLength()-s1.ReverseFind('\\')-1);
		SetDlgItemText(IDC_CSV_NAME,s2.Left(s2.GetLength()-4));
		f.open(s1);
		f.getline(ch,2047,'\n');
		f.close();
		s2.Format("%s",ch);
		s2+=',';
		m_clist.DeleteAllItems();
		for(i=0;i<s2.GetLength();i++)
		{
			if(s2.GetAt(i)==',')
			{
				s3=s2.Mid(j,i-j);
				j=i+1;
				if(s3.GetLength()>0)
				{
					if(s3.GetAt(0)=='\"')
						s3=s3.Mid(1,s3.GetLength()-2);
					m_clist.InsertItem(m_clist.GetItemCount(),s3,0);
					m_clist.SetItemText(m_clist.GetItemCount()-1,1,GetBDString(s3));
				}
			}
		}
	}
}



void CInCsvDlg::OnCsvBrowse() 
{
	CString fp;
	CFileDialog dlg(TRUE,NULL,NULL,OFN_PATHMUSTEXIST|OFN_FILEMUSTEXIST,_T("逗点分隔文件(*.csv)|*.csv||"),this);
	dlg.m_ofn.lpstrTitle="选择文件位置";
	//显示打开对话框
	if(dlg.DoModal()!=IDOK)
		return;
	//加载文件位置
	fp=dlg.GetPathName();
	SetDlgItemText(IDC_CSV_FILE,fp);
	InitCSVInfor();
}

void CInCsvDlg::OnItemclickRecList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	HD_NOTIFY *phdn = (HD_NOTIFY *) pNMHDR;

	*pResult = 0;
}

void CInCsvDlg::OnClickRecList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CString s;
	CComboBox *ptn=(CComboBox *)GetDlgItem(IDC_CMB_REC);
	if(m_clist.GetItemCount()>0)
	{
		s=m_clist.GetItemText(m_clist.GetSelectionMark(),1);
		ptn->SetCurSel(ptn->FindString(0,s));
	}	
	*pResult = 0;
}

void CInCsvDlg::OnSelchangeCmbRec() 
{
	CString s;
	GetDlgItemText(IDC_CMB_REC,s);
	if(m_clist.GetSelectionMark()>0)
	{
		m_clist.SetItemText(m_clist.GetSelectionMark(),1,s);
	}
}

void CInCsvDlg::OnOK() 
{
	CString s1,s2,s3;
	ifstream f;
	CPerson p,*p1;
	int i,j=0,k=0;
	char ch[2048];
	GetDlgItemText(IDC_CSV_FILE,s1);
	if(s1.GetLength()==0)
	{
		MessageBox("您没有指定要导入的数据库文件！","导入CSV",MB_ICONERROR);
		return ;
	}
	PlaySound((LPCTSTR)IDR_WAVE1, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
	f.open(s1);
	if(f)
	{
		nowData.Close();
		GetDlgItemText(IDC_CSV_NAME,s1);
		nowData.SetTitle(s1);
		f.getline(ch,2047,'\n');
		while(!f.eof())
		{
			f.getline(ch,2047,'\n');
			s1.Format("%s",ch);
			if(s1.GetLength()>0)
			{
				s1+=',';
				j=k=0;
				for(i=0;i<s1.GetLength();i++)
				{
					if(s1.GetAt(i)==',')
					{
						s2=s1.Mid(j,i-j);
						j=i+1;
						if(s2.GetLength()>0)
						{
							if(s2.GetAt(0)=='\"')
								s2=s2.Mid(1,s2.GetLength()-2);
							s3=m_clist.GetItemText(k,1);
							if(s3.GetLength()>0)
							{
								p.SetMebValue(s3,s2);
							}
						}
						k+=1;
					}
				}
				nowData+=p;
			}
		}
		f.close();
		//分离出分组信息
		if(nowData.phead!=NULL)
		{
			CPGroup *g,g1;
			p1=nowData.phead;
			if(p1->GetTeam()!="")
			{
				if(nowData.ghead!=NULL)
				{
					g=nowData.ghead;
					if(g->GetName()==p1->GetTeam())
						goto gnext;
					while(g->next!=NULL)
					{
						g=g->next;
						if(g->GetName()==p1->GetTeam())
							goto gnext;
					}
				}
				g1.SetName(p1->GetTeam());
				nowData+=g1;
			}
gnext:
			while(p1->next!=NULL)
			{
				p1=p1->next;
				if(p1->GetTeam()!="")
				{
					if(nowData.ghead!=NULL)
					{
						g=nowData.ghead;
						if(g->GetName()==p1->GetTeam())
							goto gnext;
						while(g->next!=NULL)
						{
							g=g->next;
							if(g->GetName()==p1->GetTeam())
								goto gnext;
						}
					}
					g1.SetName(p1->GetTeam());
					nowData+=g1;
				}
			}
		}
		nowData.FileOpened=true;
		s1="";
		nowData.SetFileName(s1);
		MessageBox("导入指令成功完成！","CSV",MB_ICONINFORMATION);
	}
	CDialog::OnOK();
}

void CInCsvDlg::SetFileName(CString &fn)
{
	SetDlgItemText(IDC_CSV_FILE,fn);
	InitCSVInfor();
}

void CInCsvDlg::OnCancel() 
{
	PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
	
	CDialog::OnCancel();
}
