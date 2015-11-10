// NewDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contact.h"
#include "NewDlg.h"
#include "Person.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewDlg dialog


CNewDlg::CNewDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNewDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CNewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewDlg, CDialog)
	//{{AFX_MSG_MAP(CNewDlg)
	ON_BN_CLICKED(IDC_BROWSE, OnBrowse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewDlg message handlers

void CNewDlg::OnBrowse() 
{
	CString fp;
	CFileDialog dlg(FALSE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,_T("ͨѶ¼���ݿ��ļ�(*.txl)|*.txl||"),this);
	dlg.m_ofn.lpstrTitle="ѡ���ļ�λ��";
	//��ʾ�򿪶Ի���
	if(dlg.DoModal()!=IDOK)
		return;
	//�����ļ�λ��
	fp=dlg.GetPathName();
	fp.MakeLower();
	if(fp.Right(4)!=_T(".txl")) fp+=_T(".txl");
	SetDlgItemText(IDC_NEW_PATH,fp);
}

void CNewDlg::OnOK() 
{
	CString str,str2,str3;
	GetDlgItemText(IDC_NEW_TITLE,str);
	if(str.GetLength()==0){
		MessageBox(_T("����δָ���µ����ݿ�����֣�����ָ�����ݿ�����֣�"),_T("����"),MB_OK|MB_ICONERROR);
		return;
	}
	GetDlgItemText(IDC_NEW_PSWD2,str3);
	GetDlgItemText(IDC_NEW_PSWD,str2);
	if(!(str2==str3)){
		MessageBox(_T("��������������벻һ�£���ȷ�Ϻ������������롣�������ʾ��ʹ�����롣"),_T("������֤"),MB_ICONSTOP);
		SetDlgItemText(IDC_NEW_PSWD,_T(""));
		SetDlgItemText(IDC_NEW_PSWD2,_T(""));
		return;
	}
	GetDlgItemText(IDC_NEW_PATH,str2);
	if(str2.GetLength()==0){
		MessageBox(_T("����δѡ���µ����ݿ���ļ�λ�ã�����ָ���ļ�λ�ã�"),_T("����"),MB_OK|MB_ICONERROR);
		return;
	}
	PlaySound((LPCTSTR)IDR_WAVE1, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
	nowData.SetFileName(str2);
	nowData.SetTitle(str);
	GetDlgItemText(IDC_NEW_PSWD,str);
	nowData.SetPswd(str);
	if(!nowData.CreateDatabase(str2)){
		MessageBox(_T("�ļ�д��ʧ�ܣ�"),_T("���ش���"),MB_OK|MB_ICONERROR);
		return ;
	}
	MessageBox(_T("���ݿ��Ѿ��ɹ�������"),_T("��ϲ"),MB_ICONINFORMATION);
	nowData.SetFileName(str2);
	nowData.OpenFile();
	CDialog::OnOK();
}

void CNewDlg::OnCancel() 
{
	PlaySound((LPCTSTR)IDR_WAVE2, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
	
	CDialog::OnCancel();
}
