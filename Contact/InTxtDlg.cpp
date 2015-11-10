// InTxtDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contact.h"
#include "InTxtDlg.h"
#include <fstream>
#include "Person.h"
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInTxtDlg dialog


CInTxtDlg::CInTxtDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInTxtDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInTxtDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CInTxtDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInTxtDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInTxtDlg, CDialog)
	//{{AFX_MSG_MAP(CInTxtDlg)
	ON_BN_CLICKED(IDC_TXT_BROWSE, OnTxtBrowse)
	ON_EN_CHANGE(IDC_TXT_FILE, OnChangeTxtFile)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInTxtDlg message handlers

void CInTxtDlg::OnTxtBrowse() 
{
	CString fp;
	CFileDialog dlg(TRUE,NULL,NULL,OFN_PATHMUSTEXIST|OFN_FILEMUSTEXIST,_T("文本文件(*.txt)|*.txt||"),this);
	dlg.m_ofn.lpstrTitle="选择文件位置";
	//显示打开对话框
	if(dlg.DoModal()!=IDOK)
		return;
	//加载文件位置
	fp=dlg.GetPathName();
	SetDlgItemText(IDC_TXT_FILE,fp);
}

void CInTxtDlg::OnChangeTxtFile() 
{
	CString s;
	CButton *p=(CButton *)GetDlgItem(IDOK);
	GetDlgItemText(IDC_TXT_FILE,s);
	p->EnableWindow(s.GetLength()>0?TRUE:FALSE);
}

void CInTxtDlg::OnOK() 
{
	ifstream f;
	CString s1,s2,s3;
	char ch[2048];
	CPerson *p,p1;
	GetDlgItemText(IDC_TXT_FILE,s1);
	PlaySound((LPCTSTR)IDR_WAVE1, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
	if(s1.GetLength()>0)
	{
		f.open(s1);
		if(f)
		{
			nowData.Close();
			while(!f.eof())
			{
				f.getline(ch,2047,'\n');
				s1.Format("%s",ch);
				if(s1.GetLength()>0)
				{
					if(nowData.phead!=NULL)   //搜索重复记录
					{
						p=nowData.phead; 
						if(p->GetName()==s1)
							goto pnext;
						while(p->next!=NULL)
						{
							p=p->next;
							if(p->GetName()==s1)
								goto pnext;
						}
					}
					p1.SetName(s1);
					nowData+=p1;
				}
pnext:
				;
			}
		}
	}
	s2.Format("成功导入学生信息，一共导入%d条记录。",CPerson::mCount);
	s3="未命名";
	nowData.SetTitle(s3);
	s3="";
	nowData.SetFileName(s3);
	nowData.FileOpened=true;
	MessageBox(s2,"导入成功",MB_ICONINFORMATION);
	CDialog::OnOK();
}

void CInTxtDlg::OnCancel() 
{
	PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
	
	CDialog::OnCancel();
}
