// MPage1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contact.h"
#include "MPage1Dlg.h"
#include "Person.h"
#include "NewPsnDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

void FirstLetter(int nCode, CString& strLetter)
{
   if(nCode >= 1601 && nCode < 1637) strLetter = _T("A");
   if(nCode >= 1637 && nCode < 1833) strLetter = _T("B");
   if(nCode >= 1833 && nCode < 2078) strLetter = _T("C");
   if(nCode >= 2078 && nCode < 2274) strLetter = _T("D");
   if(nCode >= 2274 && nCode < 2302) strLetter = _T("E");
   if(nCode >= 2302 && nCode < 2433) strLetter = _T("F");
   if(nCode >= 2433 && nCode < 2594) strLetter = _T("G");
   if(nCode >= 2594 && nCode < 2787) strLetter = _T("H");
   if(nCode >= 2787 && nCode < 3106) strLetter = _T("J");
   if(nCode >= 3106 && nCode < 3212) strLetter = _T("K");
   if(nCode >= 3212 && nCode < 3472) strLetter = _T("L");
   if(nCode >= 3472 && nCode < 3635) strLetter = _T("M");
   if(nCode >= 3635 && nCode < 3722) strLetter = _T("N");
   if(nCode >= 3722 && nCode < 3730) strLetter = _T("O");
   if(nCode >= 3730 && nCode < 3858) strLetter = _T("P");
   if(nCode >= 3858 && nCode < 4027) strLetter = _T("Q");
   if(nCode >= 4027 && nCode < 4086) strLetter = _T("R");
   if(nCode >= 4086 && nCode < 4390) strLetter = _T("S");
   if(nCode >= 4390 && nCode < 4558) strLetter = _T("T");
   if(nCode >= 4558 && nCode < 4684) strLetter = _T("W");
   if(nCode >= 4684 && nCode < 4925) strLetter = _T("X");
   if(nCode >= 4925 && nCode < 5249) strLetter = _T("Y");
   if(nCode >= 5249 && nCode < 5590) strLetter = _T("Z");
}
void GetFirstLetter(CString strName, CString& strFirstLetter)
{
    TBYTE ucHigh, ucLow;
    int  nCode;
    CString strRet;

    strFirstLetter.Empty();

    for (int i=0; i<strName.GetLength(); i++)
    {
        if ( (TBYTE)strName[i] < 0x80 )
            continue;

        ucHigh = (TBYTE)strName[i];
        ucLow  = (TBYTE)strName[i+1];
        if ( ucHigh < 0xa1 || ucLow < 0xa1)
            continue;
        else
            // Treat code by section-position as an int type parameter,
            // so make following change to nCode.
            nCode = (ucHigh - 0xa0) * 100 + ucLow - 0xa0;

        FirstLetter(nCode, strRet);
        strFirstLetter += strRet;
        i++;
    }
}


/////////////////////////////////////////////////////////////////////////////
// CMPage1Dlg dialog


CMPage1Dlg::CMPage1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMPage1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMPage1Dlg)
	//}}AFX_DATA_INIT
}


void CMPage1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMPage1Dlg)
	DDX_Control(pDX, IDC_CTCLIST, m_list1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMPage1Dlg, CDialog)
	//{{AFX_MSG_MAP(CMPage1Dlg)
	ON_BN_CLICKED(IDC_NPAGE_NEXT, OnNpageNext)
	ON_BN_CLICKED(IDC_NPAGE_PREV, OnNpagePrev)
	ON_BN_CLICKED(IDC_NPAGE_FIRST, OnNpageFirst)
	ON_BN_CLICKED(IDC_NPAGE_LAST, OnNpageLast)
	ON_BN_CLICKED(IDC_BTN_ADDP, OnBtnAddP)
	ON_BN_CLICKED(IDC_PG1_UPDATE, OnPg1Update)
	ON_EN_CHANGE(IDC_INPUT_NAME, OnChangeInputName)
	ON_EN_CHANGE(IDC_INPUT_MAJOR, OnChangeInputMajor)
	ON_EN_CHANGE(IDC_INPUT_MOBI, OnChangeInputMobi)
	ON_EN_CHANGE(IDC_INPUT_ADDR, OnChangeInputAddr)
	ON_EN_CHANGE(IDC_INPUT_HOME, OnChangeInputHome)
	ON_EN_CHANGE(IDC_INPUT_MEMO, OnChangeInputMemo)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_SAVE_EDIT1, OnSaveEdit1)
	ON_BN_CLICKED(IDC_DEL_NOWPSN, OnDelNowpsn)
	ON_CBN_SELCHANGE(IDC_NAME_LIST, OnSelchangeNameList)
	ON_NOTIFY(NM_DBLCLK, IDC_CTCLIST, OnDblclkCtclist)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMPage1Dlg message handlers

void CMPage1Dlg::InitCmb()
{
	/*CString s;
	int i;
	i=1;
	m_cmb_sort.AddString("所有");
	i=2;
	for(i='A';i<='Z';i++)
	{
		s.Format("%c",i);
		m_cmb_sort.AddString(s);
	}
	m_cmb_sort.SetCurSel(0);*/
}

BOOL CMPage1Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	CComboBox *ptn=(CComboBox *)GetDlgItem(IDC_COMBO1);
	ptn->SetCurSel(0);
	m_list1.InsertColumn(0,_T("姓名"),LVCFMT_LEFT,70);
	m_list1.InsertColumn(1,_T("性别"),LVCFMT_LEFT,40);
	m_list1.InsertColumn(2,_T("手机"),LVCFMT_LEFT,100);
	m_list1.InsertColumn(3,_T("邮箱"),LVCFMT_LEFT,100);
	//创建图像列表
	m_images.Create(16,16,ILC_COLORDDB,1,1);
	m_images.Add(AfxGetApp()->LoadIcon(IDI_ICON6));
	//建立关联
	m_list1.SetImageList(&m_images,LVSIL_SMALL);
	m_list1.SetImageList(&m_images,LVSIL_NORMAL);
	m_list1.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	return TRUE;
}

void CMPage1Dlg::UpdateLists()
{
	OnSelchangeNameList();
}

void CMPage1Dlg::UpdatePerson()
{
	CPerson *p;
	CButton *ptn;
	if(nowData.phead!=NULL)
	{
		p=nowData.nowp;
		SetDlgItemText(IDC_INPUT_NAME,p->GetName());
		SetDlgItemText(IDC_INPUT_MAJOR,p->GetMajor());
		SetDlgItemText(IDC_INPUT_MOBI,p->GetMobi());
		SetDlgItemText(IDC_INPUT_ADDR,p->GetAddress());
		SetDlgItemText(IDC_INPUT_HOME,p->GetHomepage());
		SetDlgItemText(IDC_INPUT_MEMO,p->GetMemo());
		ptn=(CButton *)GetDlgItem(IDC_RADIO1);
		ptn->SetCheck("男"==p->GetSex()?1:0);
		ptn=(CButton *)GetDlgItem(IDC_RADIO2);
		ptn->SetCheck("女"==p->GetSex()?1:0);
	}
	ptn=(CButton *)GetDlgItem(IDC_SAVE_EDIT1);
	ptn->EnableWindow(FALSE);
}

void CMPage1Dlg::OnNpageNext() 
{
	CButton *btn=(CButton *)GetDlgItem(IDC_SAVE_EDIT1);
	if(nowData.phead!=NULL)
	{
		if(nowData.nowp->next==NULL)
		{
			MessageBox(_T("当前已经是最后一条记录,将转到第一跳记录。"),_T("记录查询"),MB_ICONINFORMATION);
			nowData.nowp=nowData.phead;
		}else
			nowData.nowp=nowData.nowp->next;
		UpdatePerson();
	}
	btn->EnableWindow(FALSE);
}

void CMPage1Dlg::OnNpagePrev() 
{
	CButton *btn=(CButton *)GetDlgItem(IDC_SAVE_EDIT1);
	if(nowData.phead!=NULL)
	{
		if(nowData.nowp->prev==NULL)
		{
			MessageBox(_T("当前已经是第一条记录,将转到最后一跳记录。"),_T("记录查询"),MB_ICONINFORMATION);
			while(nowData.nowp->next!=NULL) nowData.nowp=nowData.nowp->next;
		}else
			nowData.nowp=nowData.nowp->prev;
		UpdatePerson();
	}
	btn->EnableWindow(FALSE);
}

void CMPage1Dlg::OnNpageFirst() 
{
	CButton *btn=(CButton *)GetDlgItem(IDC_SAVE_EDIT1);
	if(nowData.phead!=NULL)
	{
		nowData.nowp=nowData.phead;
		UpdatePerson();
	}
	btn->EnableWindow(FALSE);
}

void CMPage1Dlg::OnNpageLast() 
{
	CButton *btn=(CButton *)GetDlgItem(IDC_SAVE_EDIT1);
	if(nowData.phead!=NULL)
	{
		while(nowData.nowp->next!=NULL) nowData.nowp=nowData.nowp->next;
		UpdatePerson();
	}
	btn->EnableWindow(FALSE);	
}

void CMPage1Dlg::OnBtnAddP() 
{
	CNewPsnDlg dlg;
	dlg.DoModal();	
}

void CMPage1Dlg::OnPg1Update() 
{
	CString s1,s2;
	s1="Tecyle";
	GetFirstLetter(s1,s2);
	MessageBox(s2);
	UpdateLists();
	UpdatePerson();
}

void CMPage1Dlg::OnChangeInputName() 
{
	CButton *pbt=(CButton *)GetDlgItem(IDC_SAVE_EDIT1);
	pbt->EnableWindow(TRUE);
}

void CMPage1Dlg::OnChangeInputMajor() 
{
	CButton *pbt=(CButton *)GetDlgItem(IDC_SAVE_EDIT1);
	pbt->EnableWindow(TRUE);	
}

void CMPage1Dlg::OnChangeInputMobi() 
{
	CButton *pbt=(CButton *)GetDlgItem(IDC_SAVE_EDIT1);
	pbt->EnableWindow(TRUE);
}

void CMPage1Dlg::OnChangeInputAddr() 
{
	CButton *pbt=(CButton *)GetDlgItem(IDC_SAVE_EDIT1);
	pbt->EnableWindow(TRUE);
}

void CMPage1Dlg::OnChangeInputHome() 
{
	CButton *pbt=(CButton *)GetDlgItem(IDC_SAVE_EDIT1);
	pbt->EnableWindow(TRUE);
}

void CMPage1Dlg::OnChangeInputMemo() 
{
	CButton *pbt=(CButton *)GetDlgItem(IDC_SAVE_EDIT1);
	pbt->EnableWindow(TRUE);
}

void CMPage1Dlg::OnRadio1() 
{
	CButton *pbt=(CButton *)GetDlgItem(IDC_SAVE_EDIT1);
	pbt->EnableWindow(TRUE);	
}

void CMPage1Dlg::OnRadio2() 
{
	CButton *pbt=(CButton *)GetDlgItem(IDC_SAVE_EDIT1);
	pbt->EnableWindow(TRUE);	
}

void CMPage1Dlg::OnSaveEdit1() 
{
	CString s;
	CButton *ptn=(CButton *)GetDlgItem(IDC_RADIO1);
	GetDlgItemText(IDC_INPUT_NAME,s);
	nowData.nowp->SetName(s);
	GetDlgItemText(IDC_INPUT_MAJOR,s);
	nowData.nowp->SetMajor(s);
	GetDlgItemText(IDC_INPUT_ADDR,s);
	nowData.nowp->SetAddress(s);
	GetDlgItemText(IDC_INPUT_MOBI,s);
	nowData.nowp->SetMobi(s);
	GetDlgItemText(IDC_INPUT_HOME,s);
	nowData.nowp->SetHomepage(s);
	GetDlgItemText(IDC_INPUT_MEMO,s);
	nowData.nowp->SetMemo(s);
	s=ptn->GetCheck()?"男":"女";
	nowData.nowp->SetSex(s);
	UpdateLists();
	UpdatePerson();
	MessageBox("当前记录已经成功保存！","保存",MB_ICONINFORMATION);
}

void CMPage1Dlg::OnDelNowpsn() 
{
	if(nowData.phead!=NULL)
	{
		if(IDYES==MessageBox("您确定要删除"+nowData.nowp->GetName()+"的所有信息吗？","删除记录",MB_YESNO|MB_ICONQUESTION))
		{
			nowData.KillNowPerson();
			UpdatePerson();
		}
	}
}

void CMPage1Dlg::EnableControls()
{
	bool e,f;
	e=nowData.FileOpened;
	f=(nowData.phead==NULL)?false:true;
	CComboBox *pb=(CComboBox *)GetDlgItem(IDC_NAME_LIST);
	CListCtrl *pl=(CListCtrl *)GetDlgItem(IDC_CTCLIST);
	CEdit *pe=(CEdit *)GetDlgItem(IDC_INPUT_NAME);
	CButton *pt=(CButton *)GetDlgItem(IDC_NPAGE_FIRST);
	pb->EnableWindow(e?TRUE:FALSE);
	pl->EnableWindow(e?TRUE:FALSE);
	pt->EnableWindow(f?TRUE:FALSE);
	pt=(CButton *)GetDlgItem(IDC_NPAGE_PREV);
	pt->EnableWindow(f?TRUE:FALSE);
	pt=(CButton *)GetDlgItem(IDC_NPAGE_NEXT);
	pt->EnableWindow(f?TRUE:FALSE);
	pt=(CButton *)GetDlgItem(IDC_NPAGE_LAST);
	pt->EnableWindow(f?TRUE:FALSE);	 
	pt=(CButton *)GetDlgItem(IDC_RADIO1);
	pt->EnableWindow(f?TRUE:FALSE);	
	pt=(CButton *)GetDlgItem(IDC_RADIO2);
	pt->EnableWindow(f?TRUE:FALSE);	
	pt=(CButton *)GetDlgItem(IDC_BTN_ADDP);
	pt->EnableWindow(e?TRUE:FALSE);
	pt=(CButton *)GetDlgItem(IDC_SAVE_EDIT1);
	pt->EnableWindow(f?TRUE:FALSE);
	pt=(CButton *)GetDlgItem(IDC_DEL_NOWPSN);
	pt->EnableWindow(f?TRUE:FALSE);
	pt=(CButton *)GetDlgItem(IDC_PG1_UPDATE);
	pt->EnableWindow(f?TRUE:FALSE);
	pe->EnableWindow(f?TRUE:FALSE);
	pe=(CEdit *)GetDlgItem(IDC_INPUT_MAJOR);
	pe->EnableWindow(f?TRUE:FALSE);
	pe=(CEdit *)GetDlgItem(IDC_INPUT_MOBI);
	pe->EnableWindow(f?TRUE:FALSE);
	pe=(CEdit *)GetDlgItem(IDC_INPUT_ADDR);
	pe->EnableWindow(f?TRUE:FALSE);
	pe=(CEdit *)GetDlgItem(IDC_INPUT_HOME);
	pe->EnableWindow(f?TRUE:FALSE);
	pe=(CEdit *)GetDlgItem(IDC_INPUT_MEMO);
	pe->EnableWindow(f?TRUE:FALSE);
}

BOOL CMPage1Dlg::PreTranslateMessage(MSG *pMsg)
{
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_ESCAPE) return TRUE; 
	if(pMsg->message==WM_KEYDOWN && pMsg->wParam==VK_RETURN) return TRUE; 
	else 
		return CDialog::PreTranslateMessage(pMsg); 
}

void CMPage1Dlg::OnSelchangeNameList() 
{
	CString s,sn,ch;
	CPerson *p;
	GetDlgItemText(IDC_NAME_LIST,ch);
	m_list1.DeleteAllItems();
	if(nowData.phead!=NULL)
	{
		if(ch=="所有")
		{
			p=nowData.phead;
			m_list1.InsertItem(m_list1.GetItemCount(),p->GetName(),0);
			m_list1.SetItemText(m_list1.GetItemCount()-1,1,p->GetSex());
			m_list1.SetItemText(m_list1.GetItemCount()-1,2,p->GetMobi());
			m_list1.SetItemText(m_list1.GetItemCount()-1,3,p->GetEmail());
			while(p->next!=NULL)
			{
				p=p->next;
				m_list1.InsertItem(m_list1.GetItemCount(),p->GetName(),0);
				m_list1.SetItemText(m_list1.GetItemCount()-1,1,p->GetSex());
				m_list1.SetItemText(m_list1.GetItemCount()-1,2,p->GetMobi());
				m_list1.SetItemText(m_list1.GetItemCount()-1,3,p->GetEmail());
			}
		}else{
			p=nowData.phead;
			sn=p->GetName();
			if(sn.GetLength()>0)
			{
				if((sn.GetAt(0)>='a' && sn.GetAt(0)<='z') || (sn.GetAt(0)>='A' && sn.GetAt(0)<='Z'))   //英文名
				{
					sn.MakeUpper();
					if(sn.GetAt(0)==ch)
					{
						m_list1.InsertItem(m_list1.GetItemCount(),p->GetName(),0);
						m_list1.SetItemText(m_list1.GetItemCount()-1,1,p->GetSex());
						m_list1.SetItemText(m_list1.GetItemCount()-1,2,p->GetMobi());
						m_list1.SetItemText(m_list1.GetItemCount()-1,3,p->GetEmail());
					}
				}else{             //中文名
					GetFirstLetter(p->GetName(),sn);
					if(sn.GetAt(0)==ch)
					{
						m_list1.InsertItem(m_list1.GetItemCount(),p->GetName(),0);
						m_list1.SetItemText(m_list1.GetItemCount()-1,1,p->GetSex());
						m_list1.SetItemText(m_list1.GetItemCount()-1,2,p->GetMobi());
						m_list1.SetItemText(m_list1.GetItemCount()-1,3,p->GetEmail());
					}
				}
				while(p->next!=NULL)
				{
					p=p->next;
					sn=p->GetName();
					if(sn.GetLength()>0)
					{
						if((sn.GetAt(0)>='a' && sn.GetAt(0)<='z') || (sn.GetAt(0)>='A' && sn.GetAt(0)<='Z'))   //英文名
						{
							sn.MakeUpper();
							if(sn.GetAt(0)==ch)
							{
								m_list1.InsertItem(m_list1.GetItemCount(),p->GetName(),0);
								m_list1.SetItemText(m_list1.GetItemCount()-1,1,p->GetSex());
								m_list1.SetItemText(m_list1.GetItemCount()-1,2,p->GetMobi());
								m_list1.SetItemText(m_list1.GetItemCount()-1,3,p->GetEmail());
							}
						}else{             //中文名
							GetFirstLetter(p->GetName(),sn);
							if(sn.GetAt(0)==ch)
							{
								m_list1.InsertItem(m_list1.GetItemCount(),p->GetName(),0);
								m_list1.SetItemText(m_list1.GetItemCount()-1,1,p->GetSex());
								m_list1.SetItemText(m_list1.GetItemCount()-1,2,p->GetMobi());
								m_list1.SetItemText(m_list1.GetItemCount()-1,3,p->GetEmail());
							}
						}
					}
				}
			}
		}
	}
}

void CMPage1Dlg::OnDblclkCtclist(NMHDR* pNMHDR, LRESULT* pResult) 
{
	CString s;
	*pResult = 0;
	if(m_list1.GetSelectionMark()>=0)
	{
		s=m_list1.GetItemText(m_list1.GetSelectionMark(),0);
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
