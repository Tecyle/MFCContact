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
	CFileDialog dlg(TRUE,NULL,NULL,OFN_PATHMUSTEXIST|OFN_FILEMUSTEXIST,_T("�ı��ļ�(*.txt)|*.txt||"),this);
	dlg.m_ofn.lpstrTitle="ѡ���ļ�λ��";
	//��ʾ�򿪶Ի���
	if(dlg.DoModal()!=IDOK)
		return;
	//�����ļ�λ��
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
					if(nowData.phead!=NULL)   //�����ظ���¼
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
	s2.Format("�ɹ�����ѧ����Ϣ��һ������%d����¼��",CPerson::mCount);
	s3="δ����";
	nowData.SetTitle(s3);
	s3="";
	nowData.SetFileName(s3);
	nowData.FileOpened=true;
	MessageBox(s2,"����ɹ�",MB_ICONINFORMATION);
	CDialog::OnOK();
}

void CInTxtDlg::OnCancel() 
{
	PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
	
	CDialog::OnCancel();
}
