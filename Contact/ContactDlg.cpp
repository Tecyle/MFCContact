// ContactDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contact.h"
#include "ContactDlg.h"
#include "NewDlg.h"
#include "NewPsnDlg.h"
#include "ChkPswdDlg.h"
#include "Person.h"
#include "PosDlg.h"
#include "FindDlg.h"
#include "NewTeamDlg.h"
#include "EditTeamDlg.h"
#include "FPTeamDlg.h"
#include "EditPersonDlg.h"
#include "KillPsnDlg.h"
#include "KillGrpDlg.h"
#include "ReplaceDlg.h"
#include "EditPswdDlg.h"
#include "InCsvDlg.h"
#include "InTxtDlg.h"
#include "WelcomeDlg.h"
#include "SwAllDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

void doEvents()   
{
	MSG msg;
	HACCEL hAccelTable;
	if(GetMessage(&msg,NULL,0,0))     
	{   
		if(!TranslateAccelerator(msg.hwnd,hAccelTable,&msg))
		{   
			TranslateMessage(&msg);   
			DispatchMessage(&msg);   
		}   
	}   
} 
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CContactDlg dialog

CContactDlg::CContactDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CContactDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CContactDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON10);
}

void CContactDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CContactDlg)
	DDX_Control(pDX, IDC_TREE1, m_ctree1);
	DDX_Control(pDX, IDC_TAB1, m_mtab);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CContactDlg, CDialog)
	//{{AFX_MSG_MAP(CContactDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_HELP_ABOUT, OnHelpAbout)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnSelchangeTab1)
	ON_COMMAND(IDM_FILE_NEW, OnFileNew)
	ON_COMMAND(IDM_FILE_OPEN, OnFileOpen)
	ON_COMMAND(IDM_FILE_EXIT, OnFileExit)
	ON_COMMAND(IDM_PERSON_NEW, OnPersonNew)
	ON_COMMAND(IDM_FILE_SAVE, OnFileSave)
	ON_BN_CLICKED(IDC_BTN_SEARCH, OnBtnSearch)
	ON_COMMAND(IDM_EDIT_REFRESH, OnEditRefresh)
	ON_COMMAND(IDM_FILE_SAVEAS, OnFileSaveas)
	ON_COMMAND(IDM_FILE_PACK, OnFilePack)
	ON_COMMAND(IDM_TOOL_NOTEPAD, OnToolNotepad)
	ON_COMMAND(IDM_TOOL_CALC, OnToolCalc)
	ON_COMMAND(IDM_SHOW_GOTO, OnShowGoto)
	ON_COMMAND(IDM_SHOW_FIRST, OnShowFirst)
	ON_COMMAND(IDM_SHOW_LAST, OnShowLast)
	ON_COMMAND(IDM_SHOW_NEXT, OnShowNext)
	ON_COMMAND(IDM_SHOW_PREVIOUS, OnShowPrevious)
	ON_COMMAND(IDM_SHOW_MAIN, OnShowMain)
	ON_COMMAND(IDM_SHOW_BASEINFOR, OnShowBaseinfor)
	ON_COMMAND(IDM_SHOW_STUDY, OnShowStudy)
	ON_COMMAND(IDM_SHOW_CONTACT, OnShowContact)
	ON_COMMAND(IDM_SHOW_OTHER, OnShowOther)
	ON_COMMAND(IDM_SHOW_TREEVIEW, OnShowTreeview)
	ON_COMMAND(IDM_FILE_FIND, OnFileFind)
	ON_COMMAND(IDM_GROUP_NEW, OnGroupNew)
	ON_COMMAND(IDM_GROUP_EDIT, OnGroupEdit)
	ON_COMMAND(IDM_GROUP_MEMBER, OnGroupMember)
	ON_COMMAND(IDM_PERSON_EDIT, OnPersonEdit)
	ON_COMMAND(IDM_PERSON_DEL, OnPersonDel)
	ON_COMMAND(IDM_GROUP_DEL, OnGroupDel)
	ON_COMMAND(IDM_HELP_WEB, OnHelpWeb)
	ON_COMMAND(IDM_EDIT_REPLACE, OnEditReplace)
	ON_COMMAND(IDM_TOOL_PSWD, OnToolPswd)
	ON_COMMAND(IDM_OUT_CSV, OnOutCsv)
	ON_COMMAND(IDM_OUT_TXT, OnOutTxt)
	ON_COMMAND(ID_IN_CSV, OnInCsv)
	ON_COMMAND(IDM_FILE_CLOSE, OnFileClose)
	ON_COMMAND(IDM_IN_TXT, OnInTxt)
	ON_COMMAND(IDM_TOOL_BIRTH, OnToolBirth)
	ON_COMMAND(IDM_TOOL_SHOWALL, OnToolShowall)
	ON_COMMAND(IDM_HELP_MEMO, OnHelpMemo)
	ON_COMMAND(IDM_HELP_CONTENT, OnHelpContent)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CContactDlg message handlers

BOOL CContactDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	int i;
	DWORD lastcount=GetTickCount();
	CWelcomeDlg dlg;
	dlg.Create(IDD_WELCOME);
	dlg.OnInitDialog();
	dlg.ShowWindow(SW_SHOW);
	doEvents();
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	//初始化菜单项
	m_listshow=true;
	m_findshow=true;
	GetMenu()->CheckMenuItem(IDM_SHOW_MAIN,MF_CHECKED);
	GetMenu()->CheckMenuItem(IDM_SHOW_BASEINFOR,0);
	GetMenu()->CheckMenuItem(IDM_SHOW_STUDY,0);
	GetMenu()->CheckMenuItem(IDM_SHOW_CONTACT,0);
	GetMenu()->CheckMenuItem(IDM_SHOW_OTHER,0);

	m_images.Create(16,16,ILC_COLORDDB,3,3);
	m_images.Add(AfxGetApp()->LoadIcon(IDI_ICON15));
	m_images.Add(AfxGetApp()->LoadIcon(IDI_ICON14));
	m_images.Add(AfxGetApp()->LoadIcon(IDI_ICON6));
	m_ctree1.SetImageList(&m_images,0);
	//选择初始查找选项
	CComboBox *ptn=(CComboBox *)GetDlgItem(IDC_CMB_IF);
	ptn->SetCurSel(0);
	//初始化列表框
	m_mtab.InsertItem(0,"常规");
	m_mtab.InsertItem(1,"基本信息");
	m_mtab.InsertItem(2,"学籍信息");
	m_mtab.InsertItem(3,"联系方式");
	m_mtab.InsertItem(4,"其它信息");

	m_tab1.Create(MAKEINTRESOURCE(IDD_MAIN_PAGE1),&m_mtab);
	m_tab2.Create(MAKEINTRESOURCE(IDD_MAIN_PAGE2),&m_mtab);
	m_tab3.Create(MAKEINTRESOURCE(IDD_MAIN_PAGE3),&m_mtab);
	m_tab4.Create(MAKEINTRESOURCE(IDD_MAIN_PAGE4),&m_mtab);
	m_tab5.Create(MAKEINTRESOURCE(IDD_MAIN_PAGE5),&m_mtab);

	CRect rc;
	m_mtab.GetClientRect(rc);
	rc.top+=30;
	rc.left+=8;
	rc.right-=8;
	rc.bottom-=8;

	m_tab1.MoveWindow(rc);
	m_tab2.MoveWindow(rc);
	m_tab3.MoveWindow(rc);
	m_tab4.MoveWindow(rc);
	m_tab5.MoveWindow(rc);

	m_tab1.ShowWindow(SW_SHOW);
	
	EnableControls(nowData.FileOpened);

	PlaySound((LPCTSTR)IDR_WAVE3, AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
	while(1500>GetTickCount()-lastcount)
		doEvents();
	dlg.DestroyWindow();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CContactDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CContactDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CContactDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CContactDlg::OnHelpAbout() 
{
	CAboutDlg dlg;
	dlg.DoModal();
}

void CContactDlg::OnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	GetMenu()->CheckMenuItem(IDM_SHOW_MAIN,0);
	GetMenu()->CheckMenuItem(IDM_SHOW_BASEINFOR,0);
	GetMenu()->CheckMenuItem(IDM_SHOW_STUDY,0);
	GetMenu()->CheckMenuItem(IDM_SHOW_CONTACT,0);
	GetMenu()->CheckMenuItem(IDM_SHOW_OTHER,0);
	switch(m_mtab.GetCurSel())
	{
	case 0:
		m_tab1.ShowWindow(SW_SHOW);
		m_tab2.ShowWindow(SW_HIDE);
		m_tab3.ShowWindow(SW_HIDE);
		m_tab4.ShowWindow(SW_HIDE);
		m_tab5.ShowWindow(SW_HIDE);
		GetMenu()->CheckMenuItem(IDM_SHOW_MAIN,MF_CHECKED);
		break;
	case 1:
		m_tab1.ShowWindow(SW_HIDE);
		m_tab2.ShowWindow(SW_SHOW);
		m_tab3.ShowWindow(SW_HIDE);
		m_tab4.ShowWindow(SW_HIDE);
		m_tab5.ShowWindow(SW_HIDE);
		GetMenu()->CheckMenuItem(IDM_SHOW_BASEINFOR,MF_CHECKED);
		break;
	case 2:
		m_tab1.ShowWindow(SW_HIDE);
		m_tab2.ShowWindow(SW_HIDE);
		m_tab3.ShowWindow(SW_SHOW);
		m_tab4.ShowWindow(SW_HIDE);
		m_tab5.ShowWindow(SW_HIDE);
		GetMenu()->CheckMenuItem(IDM_SHOW_STUDY,MF_CHECKED);
		break;
	case 3:
		m_tab1.ShowWindow(SW_HIDE);
		m_tab2.ShowWindow(SW_HIDE);
		m_tab3.ShowWindow(SW_HIDE);
		m_tab4.ShowWindow(SW_SHOW);
		m_tab5.ShowWindow(SW_HIDE);
		GetMenu()->CheckMenuItem(IDM_SHOW_CONTACT,MF_CHECKED);
		break;
	case 4:
		m_tab1.ShowWindow(SW_HIDE);
		m_tab2.ShowWindow(SW_HIDE);
		m_tab3.ShowWindow(SW_HIDE);
		m_tab4.ShowWindow(SW_HIDE);
		m_tab5.ShowWindow(SW_SHOW);
		GetMenu()->CheckMenuItem(IDM_SHOW_OTHER,MF_CHECKED);
		break;
	}
	*pResult = 0;
}

void CContactDlg::OnFileNew() 
{
	CNewDlg dlg;
	dlg.DoModal();
	EnableControls(nowData.FileOpened);
	OnEditRefresh();
}

void CContactDlg::OnFileOpen() 
{
	int i;
	if(nowData.FileOpened)
	{
		if(IDYES==(i=MessageBox(_T("您要保存您对数据库所做的修改吗？\n选“是”保存，选“否”不保存，选“取消”取消当前操作。"),_T("保存"),MB_YESNOCANCEL|MB_ICONINFORMATION)))
		{
			OnFileSave();
		}else if(IDCANCEL==i)
			return ;
	}
	CFileDialog dlg(TRUE,NULL,NULL,OFN_PATHMUSTEXIST|OFN_FILEMUSTEXIST,_T("通讯录数据库文件(*.txl)|*.txl||"),this);
	CChkPswdDlg pdlg;

	if(!(dlg.DoModal()==IDOK))
		return;
	nowData.SetFileName(dlg.GetPathName());
	if(!pdlg.CheckPswd())
		return;
	nowData.OpenFile();
	MessageBox(nowData.GetFileName());
	EnableControls(nowData.FileOpened);
	OnEditRefresh();
}

void CContactDlg::OnFileExit() 
{
	OnCancel();
}

//DEL void CContactDlg::OnClose()
//DEL {
//DEL 	if(IDYES==MessageBox(_T("您要保存您对数据库所做的修改吗？\n选“是”保存，选“否”不保存，选“取消”不退出程序。"),_T("保存"),MB_YESNOCANCEL|MB_ICONINFORMATION))
//DEL 		MessageBox("已经保存");
//DEL 	CDialog::OnDestroy();
//DEL }

void CContactDlg::OnDestroy()
{
	if(IDYES==MessageBox(_T("您要保存您对数据库所做的修改吗？\n选“是”保存，选“否”不保存，选“取消”不退出程序。"),_T("保存"),MB_YESNOCANCEL|MB_ICONINFORMATION))
		MessageBox("已经保存");
	CDialog::OnDestroy();
}

void CContactDlg::UpdateTree()
{
	CPGroup *g1;
	CPerson *p1;
	m_ctree1.DeleteAllItems();

	CString s1,s2,s3;
	s1.Format("联系组(%d)",CPGroup::memNum+1);
	HTREEITEM hItem=TVI_ROOT;
	HTREEITEM subItem;

	hItem=m_ctree1.InsertItem(s1,1,1,hItem);
	//建立未分组
	s1.Format("未分组的联系人(%d)",GetTeamMebCount(""));
	subItem=m_ctree1.InsertItem(s1,0,0,hItem);
	if(nowData.phead!=NULL)
	{
		p1=nowData.phead;
		if(nowData.nGroup.IsInThisTeam(*p1))
		{
			m_ctree1.InsertItem(p1->GetName(),2,2,subItem);
		}while(p1->next!=NULL){
			p1=p1->next;
			if(nowData.nGroup.IsInThisTeam(*p1))
			{
				m_ctree1.InsertItem(p1->GetName(),2,2,subItem);
			}
		}
	}
	//建立分组
	if(nowData.ghead!=NULL)
	{
		g1=nowData.ghead;
		s1.Format("%s(%d)",g1->GetName(),GetTeamMebCount(g1->GetName()));
		subItem=m_ctree1.InsertItem(s1,0,0,hItem);
		if(nowData.phead!=NULL)   //添加联系人
		{
			p1=nowData.phead;
			if(g1->IsInThisTeam(*p1))
			{
				m_ctree1.InsertItem(p1->GetName(),2,2,subItem);
			}while(p1->next!=NULL){
				p1=p1->next;
				if(g1->IsInThisTeam(*p1))
				{
					m_ctree1.InsertItem(p1->GetName(),2,2,subItem);
				}
			}
		}
		while(g1->next!=NULL)
		{
			g1=g1->next;
			s1.Format("%s(%d)",g1->GetName(),GetTeamMebCount(g1->GetName()));
			subItem=m_ctree1.InsertItem(s1,0,0,hItem);
			if(nowData.phead!=NULL)   //添加联系人
			{
				p1=nowData.phead;
				if(g1->IsInThisTeam(*p1))
				{
					m_ctree1.InsertItem(p1->GetName(),2,2,subItem);
				}while(p1->next!=NULL){
					p1=p1->next;
					if(g1->IsInThisTeam(*p1))
					{
						m_ctree1.InsertItem(p1->GetName(),2,2,subItem);
					}
				}
			}
		}
	}
}

void CContactDlg::OnPersonNew() 
{
	CNewPsnDlg dlg;
	dlg.DoModal();
	EnableControls(nowData.FileOpened);
}

void CContactDlg::OnFileSave() 
{
	if(nowData.GetFileName()!="")
		nowData.SaveFile();
	else
		OnFileSaveas();
}

void CContactDlg::OnBtnSearch() 
{
	CPerson *p1=nowData.nowp;
	CString s,s1;
	CButton *ptn=(CButton *)GetDlgItem(IDC_CHK_FORWARD);
	GetDlgItemText(IDC_EDIT_SEARCH,s);
	GetDlgItemText(IDC_CMB_IF,s1);
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
	if(!ptn->GetCheck())  //向后查找
	{
		while(p1->next!=NULL)
		{
			p1=p1->next;
			if(p1->CmpMebValue(s1,s)>=0)
			{
				nowData.nowp=p1;
				OnEditRefresh();
				return;
			}
		}
		MessageBox("已经查找到最后一个联系人了，尚未发现可疑目标。系统将定位到第一个联系人处，以便继续查找。","查找",MB_ICONINFORMATION);
		nowData.nowp=nowData.phead;
		OnEditRefresh();
		return;
	}else{       //向前查找
		while(p1->prev != NULL)
		{
			p1=p1->prev;
			if(p1->CmpMebValue(s1,s)>=0)
			{
				nowData.nowp=p1;
				OnEditRefresh();
				return;
			}
		}
		MessageBox("已经查找到第一个联系人了，尚未发现可疑目标。系统将定位到最后一个联系人处，以便继续查找。","查找",MB_ICONINFORMATION);
		while(p1->next!=NULL) p1=p1->next;
		nowData.nowp=p1;
		OnEditRefresh();
		return;
	}
}

void CContactDlg::OnEditRefresh() 
{
	m_tab1.UpdateLists();
	m_tab1.UpdatePerson();
	m_tab2.UpdateLists();
	m_tab2.UpdateLists2();
	m_tab2.UpdatePerson();
	m_tab3.UpdatePerson();
	m_tab4.UpdatePerson();
	m_tab5.UpdatePerson();
	UpdateTree();
	if(nowData.GetTitle()!="")
		this->SetWindowText(nowData.GetTitle()+" - 通讯录软件");
}

void CContactDlg::OnFileSaveas() 
{
	CString fp;
	CFileDialog dlg(FALSE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,_T("通讯录数据库文件(*.txl)|*.txl||"),this);
	dlg.m_ofn.lpstrTitle="选择文件位置";
	//显示打开对话框
	if(dlg.DoModal()!=IDOK)
		return;
	//加载文件位置
	fp=dlg.GetPathName();
	fp.MakeLower();
	if(fp.Right(4)!=_T(".txl")) fp+=_T(".txl");
	nowData.SetFileName(fp);
	nowData.SaveFile(fp);
}

void CContactDlg::OnFilePack() 
{
	CString fp;
	CFileDialog dlg(FALSE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,_T("通讯录数据库文件(*.txl)|*.txl||"),this);
	dlg.m_ofn.lpstrTitle="选择文件位置";
	//显示打开对话框
	if(dlg.DoModal()!=IDOK)
		return;
	//加载文件位置
	fp=dlg.GetPathName();
	fp.MakeLower();
	if(fp.Right(4)!=_T(".txl")) fp+=_T(".txl");
	//nowData.SetFileName(fp);
	nowData.SaveFile(fp);	
}

void CContactDlg::OnToolNotepad() 
{
	ShellExecute(NULL,"open","notepad.exe",NULL,NULL,SW_SHOW);	
}

void CContactDlg::OnToolCalc() 
{
	ShellExecute(NULL,"open","calc.exe",NULL,NULL,SW_SHOW);	
}

void CContactDlg::OnShowGoto() 
{
	CPosDlg dlg;
	CPerson *p1;
	if(nowData.phead!=NULL)
	{
		if(IDOK==dlg.DoModal())
		{
			p1=nowData.phead;
			while(dlg.m_cpos!=p1->GetID() && p1->next!=NULL)
				p1=p1->next;
			if(dlg.m_cpos==p1->GetID())
			{
				nowData.nowp=p1;
				OnEditRefresh();
				return;
			}
			CString s;
			s.Format("本数据库中不存在索引号为%d的记录！",dlg.m_cpos);
			MessageBox(s,"定位错误",MB_ICONERROR);
			return;
		}
	}
}
//转到第一条记录
void CContactDlg::OnShowFirst() 
{
	if(nowData.phead!=NULL)
	{
		nowData.nowp=nowData.phead;
		OnEditRefresh();
	}	
}
//转到最后一条记录
void CContactDlg::OnShowLast() 
{
	if(nowData.phead!=NULL)
	{
		while(nowData.nowp->next!=NULL) nowData.nowp=nowData.nowp->next;
		OnEditRefresh();
	}	
}
//转到下一条记录
void CContactDlg::OnShowNext() 
{
	if(nowData.phead!=NULL)
	{
		if(nowData.nowp->next==NULL)
		{
			MessageBox(_T("当前已经是最后一条记录,将转到第一跳记录。"),_T("记录查询"),MB_ICONINFORMATION);
			nowData.nowp=nowData.phead;
		}else
			nowData.nowp=nowData.nowp->next;
		OnEditRefresh();
	}	
}
//转到上一条记录
void CContactDlg::OnShowPrevious() 
{
	if(nowData.phead!=NULL)
	{
		if(nowData.nowp->prev==NULL)
		{
			MessageBox(_T("当前已经是第一条记录,将转到最后一跳记录。"),_T("记录查询"),MB_ICONINFORMATION);
			while(nowData.nowp->next!=NULL) nowData.nowp=nowData.nowp->next;
		}else
			nowData.nowp=nowData.nowp->prev;
		OnEditRefresh();
	}	
}

void CContactDlg::OnShowMain() 
{
	m_mtab.SetCurSel(0);
	GetMenu()->CheckMenuItem(IDM_SHOW_MAIN,MF_CHECKED);
	GetMenu()->CheckMenuItem(IDM_SHOW_BASEINFOR,0);
	GetMenu()->CheckMenuItem(IDM_SHOW_STUDY,0);
	GetMenu()->CheckMenuItem(IDM_SHOW_CONTACT,0);
	GetMenu()->CheckMenuItem(IDM_SHOW_OTHER,0);
	m_tab1.ShowWindow(SW_SHOW);
	m_tab2.ShowWindow(SW_HIDE);
	m_tab3.ShowWindow(SW_HIDE);
	m_tab4.ShowWindow(SW_HIDE);
	m_tab5.ShowWindow(SW_HIDE);
}

void CContactDlg::OnShowBaseinfor() 
{
	m_mtab.SetCurSel(1);	
	GetMenu()->CheckMenuItem(IDM_SHOW_MAIN,0);
	GetMenu()->CheckMenuItem(IDM_SHOW_BASEINFOR,MF_CHECKED);
	GetMenu()->CheckMenuItem(IDM_SHOW_STUDY,0);
	GetMenu()->CheckMenuItem(IDM_SHOW_CONTACT,0);
	GetMenu()->CheckMenuItem(IDM_SHOW_OTHER,0);
	m_tab1.ShowWindow(SW_HIDE);
	m_tab2.ShowWindow(SW_SHOW);
	m_tab3.ShowWindow(SW_HIDE);
	m_tab4.ShowWindow(SW_HIDE);
	m_tab5.ShowWindow(SW_HIDE);
}

void CContactDlg::OnShowStudy() 
{
	m_mtab.SetCurSel(2);	
	GetMenu()->CheckMenuItem(IDM_SHOW_MAIN,0);
	GetMenu()->CheckMenuItem(IDM_SHOW_BASEINFOR,0);
	GetMenu()->CheckMenuItem(IDM_SHOW_STUDY,MF_CHECKED);
	GetMenu()->CheckMenuItem(IDM_SHOW_CONTACT,0);
	GetMenu()->CheckMenuItem(IDM_SHOW_OTHER,0);
	m_tab1.ShowWindow(SW_HIDE);
	m_tab2.ShowWindow(SW_HIDE);
	m_tab3.ShowWindow(SW_SHOW);
	m_tab4.ShowWindow(SW_HIDE);
	m_tab5.ShowWindow(SW_HIDE);
}

void CContactDlg::OnShowContact() 
{
	m_mtab.SetCurSel(3);	
	GetMenu()->CheckMenuItem(IDM_SHOW_MAIN,0);
	GetMenu()->CheckMenuItem(IDM_SHOW_BASEINFOR,0);
	GetMenu()->CheckMenuItem(IDM_SHOW_STUDY,0);
	GetMenu()->CheckMenuItem(IDM_SHOW_CONTACT,MF_CHECKED);
	GetMenu()->CheckMenuItem(IDM_SHOW_OTHER,0);
	m_tab1.ShowWindow(SW_HIDE);
	m_tab2.ShowWindow(SW_HIDE);
	m_tab3.ShowWindow(SW_HIDE);
	m_tab4.ShowWindow(SW_SHOW);
	m_tab5.ShowWindow(SW_HIDE);
}

void CContactDlg::OnShowOther() 
{
	m_mtab.SetCurSel(4);	
	GetMenu()->CheckMenuItem(IDM_SHOW_MAIN,0);
	GetMenu()->CheckMenuItem(IDM_SHOW_BASEINFOR,0);
	GetMenu()->CheckMenuItem(IDM_SHOW_STUDY,0);
	GetMenu()->CheckMenuItem(IDM_SHOW_CONTACT,0);
	GetMenu()->CheckMenuItem(IDM_SHOW_OTHER,MF_CHECKED);
	m_tab1.ShowWindow(SW_HIDE);
	m_tab2.ShowWindow(SW_HIDE);
	m_tab3.ShowWindow(SW_HIDE);
	m_tab4.ShowWindow(SW_HIDE);
	m_tab5.ShowWindow(SW_SHOW);
}

void CContactDlg::OnShowTreeview() 
{
	if(m_listshow)
	{
		m_listshow=false;
		GetMenu()->CheckMenuItem(IDM_SHOW_TREEVIEW,0);
		m_ctree1.ShowWindow(SW_HIDE);
	}else{
		m_listshow=true;
		GetMenu()->CheckMenuItem(IDM_SHOW_TREEVIEW,MF_CHECKED);
		m_ctree1.ShowWindow(SW_SHOW);
	}
}

void CContactDlg::OnFileFind() 
{
	CFindDlg dlg;
	if(nowData.phead!=NULL)
		dlg.DoModal();
	OnEditRefresh();
}

void CContactDlg::OnGroupNew() 
{
	CNewTeamDlg dlg;
	if(IDOK==dlg.DoModal())
		OnEditRefresh();
	EnableControls(nowData.FileOpened);
}

void CContactDlg::OnGroupEdit() 
{
	CEditTeamDlg dlg;
	if(nowData.ghead!=NULL)
		dlg.DoModal();
}

void CContactDlg::OnGroupMember() 
{
	CFPTeamDlg dlg;
	dlg.DoModal();
	OnEditRefresh();
}

void CContactDlg::OnPersonEdit() 
{
	CEditPersonDlg dlg;
	dlg.DoModal();
}

void CContactDlg::OnPersonDel() 
{
	CKillPsnDlg dlg;
	if(IDOK==dlg.DoModal())
		OnEditRefresh();
	EnableControls(nowData.FileOpened);
}

void CContactDlg::OnGroupDel() 
{
	CKillGrpDlg dlg;
	if(IDOK==dlg.DoModal())
		OnEditRefresh();
	EnableControls(nowData.FileOpened);
}

void CContactDlg::OnHelpWeb() 
{
	ShellExecute(NULL,"open","http://blog.163.com/ciee097",NULL,NULL,SW_SHOW);	
}

void CContactDlg::OnEditReplace() 
{
	CReplaceDlg dlg;
	dlg.DoModal();
	OnEditRefresh();
}

void CContactDlg::OnToolPswd() 
{
	CEditPswdDlg dlg;
	dlg.DoModal();
}

void CContactDlg::OnOutCsv() 
{
	CString fp;
	CFileDialog dlg(FALSE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,_T("CSV逗点分隔文件(*.csv)|*.csv||"),this);
	dlg.m_ofn.lpstrTitle="导出文件";
	//显示打开对话框
	if(dlg.DoModal()!=IDOK)
		return;
	fp=dlg.GetFileName();
	fp.MakeLower();
	if(".csv"!=fp.Right(4))
		fp+=".csv";
	if(SaveCSVFile(nowData,fp))
		MessageBox("导出CSV文件成功！","导出文件",MB_ICONINFORMATION);
}

void CContactDlg::OnOutTxt() 
{
	CString fp;
	CFileDialog dlg(FALSE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,_T("文本文件(*.txt)|*.txt||"),this);
	dlg.m_ofn.lpstrTitle="导出文件";
	//显示打开对话框
	if(dlg.DoModal()!=IDOK)
		return;
	fp=dlg.GetFileName();
	fp.MakeLower();
	if(".txt"!=fp.Right(4))
		fp+=".txt";
	if(SaveTXTFile(nowData,fp))
		MessageBox("导出TXT文件成功！","导出文件",MB_ICONINFORMATION);
}

void CContactDlg::OnInCsv() 
{
	int i;
	if(nowData.FileOpened)
	{
		if(IDYES==(i=MessageBox(_T("您要保存您对数据库所做的修改吗？\n选“是”保存，选“否”不保存，选“取消”取消当前操作。"),_T("保存"),MB_YESNOCANCEL|MB_ICONINFORMATION)))
		{
			OnFileSave();
		}else if(IDCANCEL==i)
			return;
	}
	CInCsvDlg dlg1;
	dlg1.DoModal();
	EnableControls(nowData.FileOpened);
}

void CContactDlg::EnableControls(bool opd)
{
	GetMenu()->EnableMenuItem(IDM_FILE_SAVE,opd?MF_ENABLED:MF_GRAYED);
	GetMenu()->EnableMenuItem(IDM_FILE_SAVEAS,opd?MF_ENABLED:MF_GRAYED);
	GetMenu()->EnableMenuItem(IDM_OUT_TXT,opd?MF_ENABLED:MF_GRAYED);
	GetMenu()->EnableMenuItem(IDM_OUT_CSV,opd?MF_ENABLED:MF_GRAYED);
	GetMenu()->EnableMenuItem(IDM_FILE_PACK,opd?MF_ENABLED:MF_GRAYED);
	GetMenu()->EnableMenuItem(IDM_FILE_CLOSE,opd?MF_ENABLED:MF_GRAYED);
	GetMenu()->EnableMenuItem(IDM_EDIT_REFRESH,opd?MF_ENABLED:MF_GRAYED);
	GetMenu()->EnableMenuItem(IDM_PERSON_NEW,opd?MF_ENABLED:MF_GRAYED);
	GetMenu()->EnableMenuItem(IDM_PERSON_EDIT,opd?MF_ENABLED:MF_GRAYED);
	GetMenu()->EnableMenuItem(IDM_PERSON_DEL,opd?MF_ENABLED:MF_GRAYED);
	GetMenu()->EnableMenuItem(IDM_GROUP_NEW,opd?MF_ENABLED:MF_GRAYED);
	GetMenu()->EnableMenuItem(IDM_GROUP_EDIT,opd?MF_ENABLED:MF_GRAYED);
	GetMenu()->EnableMenuItem(IDM_GROUP_DEL,opd?MF_ENABLED:MF_GRAYED);
	GetMenu()->EnableMenuItem(IDM_GROUP_MEMBER,opd?MF_ENABLED:MF_GRAYED);
	GetMenu()->EnableMenuItem(IDM_FILE_FIND,opd?MF_ENABLED:MF_GRAYED);
	GetMenu()->EnableMenuItem(IDM_EDIT_REPLACE,opd?MF_ENABLED:MF_GRAYED);
	GetMenu()->EnableMenuItem(IDM_SHOW_GOTO,opd?MF_ENABLED:MF_GRAYED);
	GetMenu()->EnableMenuItem(IDM_SHOW_FIRST,opd?MF_ENABLED:MF_GRAYED);
	GetMenu()->EnableMenuItem(IDM_SHOW_LAST,opd?MF_ENABLED:MF_GRAYED);
	GetMenu()->EnableMenuItem(IDM_SHOW_NEXT,opd?MF_ENABLED:MF_GRAYED);
	GetMenu()->EnableMenuItem(IDM_SHOW_PREVIOUS,opd?MF_ENABLED:MF_GRAYED);
	GetMenu()->EnableMenuItem(IDM_TOOL_PSWD,opd?MF_ENABLED:MF_GRAYED);
	GetMenu()->EnableMenuItem(IDM_TOOL_BIRTH,opd?MF_ENABLED:MF_GRAYED);
	GetMenu()->EnableMenuItem(IDM_TOOL_SHOWALL,opd?MF_ENABLED:MF_GRAYED);
	m_ctree1.EnableWindow(opd?TRUE:FALSE);
	CButton *pt=(CButton *)GetDlgItem(IDC_BTN_SEARCH);
	pt->EnableWindow(opd?TRUE:FALSE);
	pt=(CButton *)GetDlgItem(IDC_CHK_FORWARD);
	pt->EnableWindow(opd?TRUE:FALSE);
	CComboBox *pb=(CComboBox *)GetDlgItem(IDC_CMB_IF);
	pb->EnableWindow(opd?TRUE:FALSE);
	CEdit *ce=(CEdit *)GetDlgItem(IDC_EDIT_SEARCH);
	ce->EnableWindow(opd?TRUE:FALSE);
	m_tab1.EnableControls();
	m_tab2.EnableControls();
	m_tab3.EnableControls();
	m_tab4.EnableControls();
	m_tab5.EnableControls();
	if(nowData.phead==NULL)
	{
		GetMenu()->EnableMenuItem(IDM_PERSON_EDIT,MF_GRAYED);
		GetMenu()->EnableMenuItem(IDM_PERSON_DEL,MF_GRAYED);
		GetMenu()->EnableMenuItem(IDM_FILE_FIND,MF_GRAYED);
		GetMenu()->EnableMenuItem(IDM_EDIT_REPLACE,MF_GRAYED);
		GetMenu()->EnableMenuItem(IDM_GROUP_MEMBER,MF_GRAYED);
		GetMenu()->EnableMenuItem(IDM_SHOW_GOTO,MF_GRAYED);
		GetMenu()->EnableMenuItem(IDM_SHOW_FIRST,MF_GRAYED);
		GetMenu()->EnableMenuItem(IDM_SHOW_LAST,MF_GRAYED);
		GetMenu()->EnableMenuItem(IDM_SHOW_NEXT,MF_GRAYED);
		GetMenu()->EnableMenuItem(IDM_SHOW_PREVIOUS,MF_GRAYED);
		GetMenu()->EnableMenuItem(IDM_TOOL_BIRTH,MF_GRAYED);
		pt=(CButton *)GetDlgItem(IDC_BTN_SEARCH);
		pt->EnableWindow(FALSE);
		pt=(CButton *)GetDlgItem(IDC_CHK_FORWARD);
		pt->EnableWindow(FALSE);
		CComboBox *pb=(CComboBox *)GetDlgItem(IDC_CMB_IF);
		pb->EnableWindow(FALSE);
		CEdit *ce=(CEdit *)GetDlgItem(IDC_EDIT_SEARCH);
		ce->EnableWindow(FALSE);
	}
	if(nowData.ghead==NULL)
	{
		GetMenu()->EnableMenuItem(IDM_GROUP_EDIT,MF_GRAYED);
		GetMenu()->EnableMenuItem(IDM_GROUP_DEL,MF_GRAYED);
		GetMenu()->EnableMenuItem(IDM_GROUP_MEMBER,MF_GRAYED);
	}
}

void CContactDlg::OnFileClose() 
{
	if(nowData.FileOpened)
	{
		int i=MessageBox("在关闭数据库之前，您希望对数据库所作的修改进行保存吗？\n选“是”保存，选“否”不保存，选“取消”取消关闭操作。","通讯录",MB_ICONQUESTION|MB_YESNOCANCEL);
		if(i==IDYES)
		{
			OnFileSave();
			nowData.Close();
		}
		else if(i==IDNO)
		
			nowData.Close();
		else
			return ;
		OnEditRefresh();
		EnableControls(nowData.FileOpened);
	}
}

void CContactDlg::OnInTxt() 
{
	int i;
	if(nowData.FileOpened)
	{
		if(IDYES==(i=MessageBox(_T("您要保存您对数据库所做的修改吗？\n选“是”保存，选“否”不保存，选“取消”不退出程序。"),_T("保存"),MB_YESNOCANCEL|MB_ICONINFORMATION)))
		{
			OnFileSave();
		}else if(IDCANCEL==i)
			return;
	}
	CInTxtDlg dlg;
	dlg.DoModal();
	EnableControls(nowData.FileOpened);
	OnEditRefresh();
}

void CContactDlg::OnOK()
{
	;
}

BOOL CContactDlg::PreTranslateMessage(MSG* pMsg) 
{ 
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_ESCAPE) return TRUE; 
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN) return TRUE; 
	else 
		return CDialog::PreTranslateMessage(pMsg); 
}

void CContactDlg::OnCancel()
{
	int i;
	if(nowData.FileOpened)
	{
		if(IDYES==(i=MessageBox(_T("您要保存您对数据库所做的修改吗？\n选“是”保存，选“否”不保存，选“取消”不退出程序。"),_T("保存"),MB_YESNOCANCEL|MB_ICONINFORMATION)))
		{
			OnFileSave();
			CDialog::OnCancel();
		}else if(IDNO==i)
			CDialog::OnCancel();
	}else
		CDialog::OnCancel();
}

void CContactDlg::OnToolBirth() 
{
	CTime t=CTime::GetCurrentTime();
	CString sz=t.Format("%m-%d");
	CString tm=t.Format("今天是%Y年%m月%d日，在当前数据库中，");
	int bc=0;
	CPerson *p1;
	CString s1,s2,s3;
	if(nowData.phead!=NULL)
	{
		p1=nowData.phead;
		s1=p1->GetBirthday();
		if(s1.GetLength()==10)   //1990-04-10
		{
			s1=s1.Right(5);  //去掉年份
			if(s1==sz)
			{
				s2.Format("%s\t%s",p1->GetName(),p1->GetBirthday());
				s3+=s2;
				s3+='\n';
				bc++;
			}
		}
		while(p1->next!=NULL)
		{
			p1=p1->next;
			s1=p1->GetBirthday();
			if(s1.GetLength()==10)   //1990-04-10
			{
				s1=s1.Right(5);  //去掉年份
				if(s1==sz)
				{
					s2.Format("%s\t%s",p1->GetName(),p1->GetBirthday());
					s3+=s2;
					s3+='\n';
					bc++;
				}
			}
		}
	}
	s2.Format("共有成员%d个，今天生日的成员共有%d个。\n",CPerson::mCount,bc);
	s1=tm+s2+s3;
	MessageBox(s1,"生日提醒",MB_ICONINFORMATION);
}

void CContactDlg::OnToolShowall() 
{
	CSwAllDlg dlg;
	dlg.DoModal();
}

void CContactDlg::OnHelpMemo() 
{
	CString s;
	s="\n";
	s+="                            通讯录程序          \n";
	s+="                          Beta 1.0.45.126                 \n";
	s+="                                                                \n";
	s+="　                                                            \n";
	s+="　 　声明:本程序由周金辉亲自编写，绝对不是网上能找得到一模    \n";
	s+="           样的。该程序的所有权归编写者所有。                 \n";
	s+="     说明:本程序拥有以下功能：                                \n";
	s+="        1.对联系人数据库的单文件管理，支持对数据库设置密码。  \n";
	s+="        2.支持与CSV文件的相互转换，支持导入与导出文本文件。   \n";
	s+="          尤其需要注意的是导出会导致密码信息丢失。            \n";
	s+="        3.本程序支持对联系人进行分组操作，并且分组操作方便快  \n";
	s+="          捷，容易上手。                                      \n";
	s+="        4.对联系人的添加，编辑和删除操作快捷，信息完整，利用  \n";
	s+="          双向链表管理数据，安全，稳定，查询快捷。            \n";
	s+="        5.支持模糊查询，分组查询和首字母查询，快捷方便，查找  \n";
	s+="          准确。                                              \n";
	s+=" --------------------------------------------------------------------  \n";
	s+="                      我们的传统，便是颠覆所有的传统。  \n";
	s+="                                                               ";
	MessageBox(s,"信息",MB_ICONINFORMATION);	
}

void CContactDlg::OnHelpContent() 
{
	MessageBox("实践是最好的老师哦！自己摸索着用吧~o(∩_∩)o~","帮助",MB_ICONINFORMATION); 	
}
