#include "stdafx.h"
#include <fstream>
#include "Person.h"
#include <iomanip>
using namespace std;

const CString CSV_Title = "\"����\",\"��������\",\"����\",\"�Ա�\",\"��������\",\"ְ��\",\"רҵ\",\"ѧУ\",\"�༶\",\"Ժϵ\",\"�꼶\",\"��ͥ�绰\",\"�ֻ�\",\"��ͥסַ\",\"�ʱ�\",\"QQ\",\"��������\",\"����\",\"������ҳ\",\"��ע\"";
CDatabase nowData;
////////////////////////////////////////��ϵ�˻�����Ϣ��//////////////////////////////////////////////////
CBaseInfor::CBaseInfor()
{
}
void CBaseInfor::SetName(CString &n)
{
	name=n;
}
void CBaseInfor::SetBirthday(CString &n)
{
	birthday=n;
}
void CBaseInfor::SetProvince(CString &n)
{
	province=n;
}
void CBaseInfor::SetSex(CString &n)
{
	sex=n;
}
void CBaseInfor::SetTeam(CString &n)
{
	team=n;
}
void CBaseInfor::SetPosition(CString &n)
{
	position=n;
}
CString CBaseInfor::GetName()
{
	return name;
}
CString CBaseInfor::GetBirthday()
{
	return birthday;
}
CString CBaseInfor::GetProvince()
{
	return province;
}
CString CBaseInfor::GetSex()
{
	return sex;
}
CString CBaseInfor::GetTeam()
{
	return team;
}
CString CBaseInfor::GetPosition()
{
	return position;
}
//////////////////////////////////////////��ϵ��ѧ����Ϣ��////////////////////////////////////////////
CStudyInfor::CStudyInfor()
{
}
void CStudyInfor::SetMajor(CString &n)
{
	major=n;
}
void CStudyInfor::SetSchool(CString &n)
{
	school=n;
}
void CStudyInfor::SetClass(CString &n)
{
	Class=n;
}
void CStudyInfor::SetCollege(CString &n)
{
	college=n;
}
void CStudyInfor::SetGrade(CString &n)
{
	grade=n;
}
CString CStudyInfor::GetMajor()
{
	return major;
}
CString CStudyInfor::GetSchool()
{
	return school;
}
CString CStudyInfor::GetClass()
{
	return Class;
}
CString CStudyInfor::GetCollege()
{
	return college;
}
CString CStudyInfor::GetGrade()
{
	return grade;
}
////////////////////////////////////////////��ϵ����ϵ��ʽ��////////////////////////////////////////////
CContactInfor::CContactInfor()
{
}
void CContactInfor::SetPhone(CString &n)
{
	phone=n;
}
void CContactInfor::SetMobi(CString &n)
{
	mobi=n;
}
void CContactInfor::SetAddress(CString &n)
{
	address=n;
}
void CContactInfor::SetPostcode(CString &n)
{
	postcode=n;
}
void CContactInfor::SetQQ(CString &n)
{
	qq=n;
}
void CContactInfor::SetEmail(CString &n)
{
	email=n;
}
void CContactInfor::SetFax(CString &n)
{
	fax=n;
}
CString CContactInfor::GetPhone()
{
	return phone;
}
CString CContactInfor::GetMobi()
{
	return mobi;
}
CString CContactInfor::GetAddress()
{
	return address;
}
CString CContactInfor::GetPostcode()
{
	return postcode;
}
CString CContactInfor::GetQQ()
{
	return qq;
}
CString CContactInfor::GetEmail()
{
	return email;
}
CString CContactInfor::GetFax()
{
	return fax;
}
//////////////////////////////////////////��ϵ��������Ϣ��////////////////////////////////////////////////////
COtherInfor::COtherInfor()
{
}
void COtherInfor::SetHomepage(CString &n)
{
	homepage=n;
}
void COtherInfor::SetMemo(CString &n)
{
	memo=n;
}
CString COtherInfor::GetHomepage()
{
	return homepage;
}
CString COtherInfor::GetMemo()
{
	return memo;
}
///////////////////////////////////////////////////��ϵ����///////////////////////////////////////////////////////
CPerson::CPerson()
{
	next=NULL;
}
void CPerson::SetBase(CBaseInfor &b)
{
	name=b.GetName();
	birthday=b.GetBirthday();
	position=b.GetPosition();
	province=b.GetProvince();
	sex=b.GetSex();
	team=b.GetTeam();
}
void CPerson::SetStudy(CStudyInfor &s)
{
	Class=s.GetClass();
	college=s.GetCollege();
	grade=s.GetGrade();
	major=s.GetMajor();
	school=s.GetSchool();
}
void CPerson::SetContact(CContactInfor &c)
{
	address=c.GetAddress();
	email=c.GetEmail();
	fax=c.GetFax();
	mobi=c.GetMobi();
	phone=c.GetPhone();
	postcode=c.GetPostcode();
	qq=c.GetQQ();
}
void CPerson::SetOther(COtherInfor &o)
{
	homepage=o.GetHomepage();
	memo=o.GetMemo();
}
CBaseInfor CPerson::GetBase()
{
	CBaseInfor tb;
	tb.SetName(name);
	tb.SetBirthday(birthday);
	tb.SetProvince(province);
	tb.SetSex(sex);
	tb.SetPosition(position);
	tb.SetTeam(team);
	return tb;
	
}
CStudyInfor CPerson::GetStudy()
{
	CStudyInfor ts;
	ts.SetClass(Class);
	ts.SetCollege(college);
	ts.SetGrade(grade);
	ts.SetMajor(major);
	ts.SetSchool(school);
	return ts;
}
CContactInfor CPerson::GetContact()
{
	CContactInfor tc;
	tc.SetAddress(address);
	tc.SetEmail(email);
	tc.SetFax(fax);
	tc.SetMobi(mobi);
	tc.SetPhone(phone);
	tc.SetPostcode(postcode);
	tc.SetQQ(qq);
	return tc;
}
COtherInfor CPerson::GetOther()
{
	COtherInfor to;
	to.SetHomepage(homepage);
	to.SetMemo(memo);
	return to;
}
void CPerson::SetID(int n)
{
	ID=n;
}
int CPerson::GetID()
{ 
	return ID;
}
bool CPerson::operator == (CPerson &p)
{
	if(ID==p.ID)
		return true;
	else
		return false;
}
int CPerson::CmpMebValue(CString h,CString v)
{
	if(h=="����")
		return name.Find(v);
	else if(h=="��������")
		return birthday.Find(v);
	else if(h=="����")
		return province.Find(v);
	else if(h=="�Ա�")
		return sex.Find(v);
	else if(h=="��������")
		return team.Find(v);
	else if(h=="ְ��")
		return position.Find(v);
	else if(h=="רҵ")
		return major.Find(v);
	else if(h=="ѧУ")
		return school.Find(v);
	else if(h=="�༶")
		return Class.Find(v);
	else if(h=="Ժϵ")
		return college.Find(v);
	else if(h=="�꼶")
		return grade.Find(v);
	else if(h=="��ͥ�绰")
		return phone.Find(v);
	else if(h=="�ֻ�")
		return mobi.Find(v);
	else if(h=="��ͥסַ")
		return address.Find(v);
	else if(h=="�ʱ�")
		return postcode.Find(v);
	else if(h=="QQ")
		return qq.Find(v);
	else if(h=="��������")
		return email.Find(v);
	else if(h=="����")
		return fax.Find(v);
	else if(h=="������ҳ")
		return homepage.Find(v);
	else if(h=="��ע")
		return memo.Find(v);
	return -1;
}
CString CPerson::GetMebValue(CString h)
{
	if(h=="����")
		return name;
	else if(h=="��������")
		return birthday;
	else if(h=="����")
		return province;
	else if(h=="�Ա�")
		return sex;
	else if(h=="��������")
		return team;
	else if(h=="ְ��")
		return position;
	else if(h=="רҵ")
		return major;
	else if(h=="ѧУ")
		return school;
	else if(h=="�༶")
		return Class;
	else if(h=="Ժϵ")
		return college;
	else if(h=="�꼶")
		return grade;
	else if(h=="��ͥ�绰")
		return phone;
	else if(h=="�ֻ�")
		return mobi;
	else if(h=="��ͥסַ")
		return address;
	else if(h=="�ʱ�")
		return postcode;
	else if(h=="QQ")
		return qq;
	else if(h=="��������")
		return email;
	else if(h=="����")
		return fax;
	else if(h=="������ҳ")
		return homepage;
	else if(h=="��ע")
		return memo;
	return "error";
}

void CPerson::SetMebValue(CString h, CString v)
{
	if(h=="����")
		name=v;
	else if(h=="��������")
		birthday=v;
	else if(h=="����")
		province=v;
	else if(h=="�Ա�")
		sex=v;
	else if(h=="��������")
		team=v;
	else if(h=="ְ��")
		position=v;
	else if(h=="רҵ")
		major=v;
	else if(h=="ѧУ")
		school=v;
	else if(h=="�༶")
		Class=v;
	else if(h=="Ժϵ")
		college=v;
	else if(h=="�꼶")
		grade=v;
	else if(h=="��ͥ�绰")
		phone=v;
	else if(h=="�ֻ�")
		mobi=v;
	else if(h=="��ͥסַ")
		address=v;
	else if(h=="�ʱ�")
		postcode=v;
	else if(h=="QQ")
		qq=v;
	else if(h=="��������")
		email=v;
	else if(h=="����")
		fax=v;
	else if(h=="������ҳ")
		homepage=v;
	else if(h=="��ע")
		memo=v;
}
int CPerson::mCount=0;
/////////////////////////////////////////////////������//////////////////////////////////////////////////////////
CPGroup::CPGroup()
{
	next=NULL;
}
CString CPGroup::GetName()
{
	return name;
}
void CPGroup::SetName(CString &n)
{
	name=n;
}
bool CPGroup::IsInThisTeam(CPerson &p)
{
	return p.GetTeam()==name?true:false;
}
int CPGroup::memNum=0;
///////////////////////////////////////////////////δ�����Ա//////////////////////////////////////////////////////////
CNoneGroup::CNoneGroup()
{
	name="δ������ϵ��";
}
bool CNoneGroup::IsInThisTeam(CPerson &p)
{
	return p.GetTeam()==""?true:false;
}
//////////////////////////////////////////////////��ϵ�����ݿ���/////////////////////////////////////////////////////////
CDatabase::CDatabase()
{
	title="";
	password="";
	FileName="";
	phead=NULL;
	ghead=NULL;
	nowp=NULL;
	CPerson::mCount=0;
	CPGroup::memNum=0;
	FileOpened=false;
}
CDatabase::~CDatabase()
{
	ClearPerson();
	ClearGroup();
}
void CDatabase::operator += (CPerson &p)		//����+=�������ʵ�� ���ݿ����+=��ϵ��; ���
{
	CPerson *p1=new CPerson,*p2;				//�½���һ���ڴ�ռ������洢��ϵ����Ϣ
	*p1=p;										//����ϵ����Ϣд���½������ڴ���
	CPerson::mCount++;							//��ϵ����������һ
	p1->SetID(CPerson::mCount);					//�����½�������ϵ�˵�ID��
	if(phead==NULL)								//�жϵ�ǰ�½�����ϵ���ǲ��ǵ�һ����ϵ��
	{
		phead=p1;								//����ǵ�һ����ϵ�˵Ļ���������ͷָ�븳ֵ
		p1->prev=NULL;							//���趨��ϵ�˵�ǰ��ָ��
		nowp=phead;								//����ǰָ�붨������Ŀ�ʼ��
		return;
	}else{
		p2=phead;								//��������ǿյ�
		while((p2->next)!=NULL)					//��p2�ƶ��������ĩβ
		{
			p2=p2->next;
		}
		p2->next=p1;							//ͨ���趨ǰ��ָ���ָ�򣬽���ϵ����Ϣ��������
		p1->prev=p2;
		return;
	}
}

bool CDatabase::operator -= (CPerson &p)		//����-=�����������ʵ�ֶ���ϵ�˵�ɾ��
{
	CPerson *p1=&p,*p2,*p3;						//p1ָ�붨λҪɾ������ϵ�ˣ�p2��p3��ǰ��ָ��
	int n_id=nowp->GetID();						//��ȡ��ǰָ����ϵ��ID��Ϊ�˷�ֹnowpָ����Ч�ڴ�
	bool del=false;								//����Ƿ��Ѿ�ɾ����Ϊ����ID�ṩ����
	if(phead==NULL)								//��������ǿյ�
		return false;							//Ҳ�Ͳ�����ʲôɾ��������
	else{
		CPerson::mCount-=1;						//��ϵ��������һ
		p2=phead;								//��ʼ����Ҫɾ������ϵ
		if(p2->GetID()==p1->GetID())			//�ж���ϵ���Ƿ�ñ�ɾ����������ID��
		{
			phead=p2->next;						//Ҫɾ������ϵ��������ͷ����Ҫ��������ͷ
			if(phead!=NULL)						//�����µ�����ͷ�Ƿ��ǿյ�
				phead->prev=NULL;				//���ǿյĻ�����ǰָ��
			if(p1->GetID()==n_id)				//���ɾ������ϵ�������ǵ�ǰָ��ָ�����ϵ��
				nowp=phead;						//����ǰָ��ָ���µ�����ͷ���Է�������
			delete p2;							//�ͷ�Ҫɾ������ϵ�˵��ڴ�
			p2=phead;							//���¶���p2��Ϊ���Ժ���ر�ID��
			del=true;							//����Ѿ�ɾ��
		}		
		if(p2!=NULL)							//��ȷ�������в�ֹһ����ϵ��
		{
			while(p2->next!=NULL)				//��ÿһ����ϵ�˶����в���
			{
				p3=p2->next;
				if(del)							//����Ѿ�ɾ������ϵ��
					p2->SetID(p2->GetID()-1);	//�±��ID�����ԭ������һ
				if(p3->GetID()==p1->GetID())	//���֮ǰû��ɾ��������ID�ŵ�Ψһ��ȷ����
				{
					p2->next=p3->next;			//�����ָ�룬��Ҫɾ������ϵ���������
					if(p3->next!=NULL)
						p3->next->prev=p2;		//����ǰָ��
					if(p1->GetID()==n_id)		//�ų���ǰָ��ָ����Ч�ڴ������
						nowp=p2;
					delete p3;					//�ͷ�ɾ����ϵ��ռ�е��ڴ�
					del=true;
				}
				p2=p2->next;
				if(p2==NULL)					//��ֹѭ���©
					return del;					//�����Ƿ�ɹ�ɾ��
			}
		}
		return del;
	}
}
void CDatabase::operator += (CPGroup &g)
{
	CPGroup *p1=new CPGroup,*p2;
	*p1=g;
	CPGroup::memNum+=1;
	if(ghead==NULL)
	{
		ghead=p1;
		return;
	}else{
		p2=ghead;
		while(p2->next!=NULL)
			p2=p2->next;
		p2->next=p1;
		return;
	}
}
bool CDatabase::operator -= (CPGroup &g)
{
	CPGroup *p1=&g,*p2,*p3;
	bool del=false;
	if(ghead==NULL)
		return false;
	else{
		CPGroup::memNum-=1;
		p2=ghead;
		if(p2->GetName()==p1->GetName())
		{
			ghead=p2->next;
			delete p2;
			return true;
		}
		if(p2!=NULL)
		{
			while(p2->next!=NULL)
			{
				p3=p2->next;
				if(p3->GetName()==p1->GetName())
				{
					p2->next=p3->next;
					delete p3;
					return true;
				}
				p2=p2->next;
				if(p2==NULL)
					return true;
			}
			return false;
		}
	}
	return false;
}
bool CDatabase::OpenFile(CString pswd/*=""*/)	//OpenFile����ʵ���ļ��򿪹���
{
	ifstream f;							//ʹ��ifstream������ļ����в���
	CString s,s2;							//����һϵ����ʱ����
	CPerson p;
	CPGroup g;
	char s1[2048];
	int i=0,k=0,j=0;
	f.open(FileName,ios::in);				//���ļ�
	if(!f)
	{
		return false;						//�ļ���ʧ�����˳�����������false
	}
	else{
		Close();							//�Զ���Ĺرպ������رյ�ǰ�Ѿ��򿪵����ݿ�
		if(!f.eof()) 						//�ȶ��������Ϣ
		{
			f.getline(s1,256,'\n');
			title.Format("%s",s1);			//ת����CString����
		}
		else{
			f.close();						//�ݴ�������������ļ���ʽ
			return false;
		}
		if(!f.eof())						//�ٶ���������Ϣ
		{
			f.getline(s1,256,'\n');
			password.Format("%s",s1);		//ת����CString���Ͳ�����password������
		}
		else{
			f.close();
			return false;					//�ݴ�������������ļ���ʽ
		}
		f.getline(s1,256,'\n');				//���������Ϣ
		s.Format("%s",s1);
		if(s=="[Group Information]")			//���鿪ʼ���
		{
			f.getline(s1,2047,'\n');
			s.Format("%s",s1);
			while(s!="[End Group]")		//�Զ�������������Ϊ����λ��
			{
				g.SetName(s);
				this->operator += (g);		//����¶���ķ��鵽���ݿ��������
				f.getline(s1,2047,'\n');
				s.Format("%s",s1);
			}
		}
		i=j=0;s="";
		while(!f.eof())						//��������ϵ����Ϣ
		{
			f.getline(s1,2047,'\n');
			s.Format("%s",s1);
			j=i=k=0;
			if(0!=s.GetLength())			//ȥ������
			{
				s+='\0';					//�Գ����ַ�������ʽ����CString�ַ���
				while(s.GetAt(i)!='\0')
				{
					if(s[i]=='|')			//��ȡ�ָ����"|"
					{
						s2=s.Mid(j,i-j);	//���������"|"֮����ַ���
						j=i+1;			//��������"|"���ֵ�λ�ú�
						k++;				//������ǵڼ������������ֵ
						switch(k)			//����ֵ������һ�ζ��½���ϵ�˵ĸ������Ը�ֵ
						{
						case 1:
							p.SetName(s2);break;
						case 2:
							p.SetBirthday(s2);break;
						case 3:
							p.SetProvince(s2);break;
						case 4:
							p.SetSex(s2);break;
						case 5:
							p.SetTeam(s2);break;
						case 6:
							p.SetPosition(s2);break;
						case 7:
							p.SetMajor(s2);break;
						case 8:
							p.SetSchool(s2);break;
						case 9:
							p.SetClass(s2);break;
						case 10:
							p.SetCollege(s2);break;
						case 11:
							p.SetGrade(s2);break;
						case 12:
							p.SetPhone(s2);break;
						case 13:
							p.SetMobi(s2);break;
						case 14:
							p.SetAddress(s2);break;
						case 15:
							p.SetPostcode(s2);break;
						case 16:
							p.SetQQ(s2);break;
						case 17:
							p.SetEmail(s2);break;
						case 18:
							p.SetFax(s2);break;
						case 19:
							p.SetHomepage(s2);break;
						case 20:
							p.SetMemo(s2);break;
						}
					}
					i++;
				}
				this->operator += (p);			//���½�����ϵ����ӵ����ݿ��������
			}
		}
	}
	f.close();
	nowp=phead;								//��λnowpָ���ָ��
	FileOpened=true;							//����ļ��Ѿ���
	return true;
}
void CDatabase::SetFileName(CString &fn)
{
	FileName=fn;
}
CString CDatabase::GetFileName()
{
	return FileName;
}
bool CDatabase::SaveFile(CString fn/*=""*/)
{
	ofstream f;
	CPerson *p1;
	CPGroup *g1;
	if(fn="") fn=FileName;
	f.open(fn);
	if(!f)
		return false;
	else{
		f<<(LPCTSTR)title<<endl;
		f<<(LPCTSTR)password<<endl;
		//�������
		f<<"[Group Information]"<<endl;
		if(ghead!=NULL)
		{
			g1=ghead;
			if(g1!=NULL) f<<(LPCTSTR)g1->GetName()<<endl;
			while(g1->next!=NULL)
			{
				g1=g1->next;
				f<<(LPCTSTR)g1->GetName()<<endl;
			}
		}
		f<<"[End Group]"<<endl;
		//��ʼ�������
		if(phead!=NULL)
		{
			p1=phead;
			while(p1->next!=NULL)
			{
				f<<(LPCTSTR)p1->GetName()<<'|'
					<<(LPCTSTR)p1->GetBirthday()<<'|'
					<<(LPCTSTR)p1->GetProvince()<<'|'
					<<(LPCTSTR)p1->GetSex()<<'|'
					<<(LPCTSTR)p1->GetTeam()<<'|'
					<<(LPCTSTR)p1->GetPosition()<<'|'
					<<(LPCTSTR)p1->GetMajor()<<'|'
					<<(LPCTSTR)p1->GetSchool()<<'|'
					<<(LPCTSTR)p1->GetClass()<<'|'
					<<(LPCTSTR)p1->GetCollege()<<'|'
					<<(LPCTSTR)p1->GetGrade()<<'|'
					<<(LPCTSTR)p1->GetPhone()<<'|'
					<<(LPCTSTR)p1->GetMobi()<<'|'
					<<(LPCTSTR)p1->GetAddress()<<'|'
					<<(LPCTSTR)p1->GetPostcode()<<'|'
					<<(LPCTSTR)p1->GetQQ()<<'|'
					<<(LPCTSTR)p1->GetEmail()<<'|'
					<<(LPCTSTR)p1->GetFax()<<'|'
					<<(LPCTSTR)p1->GetHomepage()<<'|'
					<<(LPCTSTR)p1->GetMemo()<<'|'<<endl;
				p1=p1->next;
			}
			//������һ��
			f<<(LPCTSTR)p1->GetName()<<'|'
				<<(LPCTSTR)p1->GetBirthday()<<'|'
				<<(LPCTSTR)p1->GetProvince()<<'|'
				<<(LPCTSTR)p1->GetSex()<<'|'
				<<(LPCTSTR)p1->GetTeam()<<'|'
				<<(LPCTSTR)p1->GetPosition()<<'|'
				<<(LPCTSTR)p1->GetMajor()<<'|'
				<<(LPCTSTR)p1->GetSchool()<<'|'
				<<(LPCTSTR)p1->GetClass()<<'|'
				<<(LPCTSTR)p1->GetCollege()<<'|'
				<<(LPCTSTR)p1->GetGrade()<<'|'
				<<(LPCTSTR)p1->GetPhone()<<'|'
				<<(LPCTSTR)p1->GetMobi()<<'|'
				<<(LPCTSTR)p1->GetAddress()<<'|'
				<<(LPCTSTR)p1->GetPostcode()<<'|'
				<<(LPCTSTR)p1->GetQQ()<<'|'
				<<(LPCTSTR)p1->GetEmail()<<'|'
				<<(LPCTSTR)p1->GetFax()<<'|'
				<<(LPCTSTR)p1->GetHomepage()<<'|'
				<<(LPCTSTR)p1->GetMemo()<<'|'<<endl;
		}
		f.close();
		return true;
	}
}

bool CDatabase::CreateDatabase(CString &fn)
{
	ofstream f;
	FileName=fn;
	f.open(fn);
	if(!f)
		return false;
	else{
		f<<(LPCTSTR)title<<endl;
		f<<(LPCTSTR)password<<endl;
		f<<"[Group Information]"<<endl;
		f<<"ͬѧ"<<endl;
		f<<"��ʦ"<<endl;
		f<<"����"<<endl;
		f<<"[End Group]"<<endl;
		f.close();
		return true;
	}
}

CString CDatabase::GetTitle()
{
	return title;
}

void CDatabase::SetTitle(CString &t)
{
	title=t;
}

void CDatabase::SetPswd(CString &pswd)
{
	password=pswd;
}

CString CDatabase::GetPswd()
{
	return password;
}

bool CDatabase::GetHeadInfor(CString *t, CString *p)
{
	ifstream f;
	char str[1024];
	f.open(FileName);
	if(!f)
		return false;
	f.getline(str,1023,'\n');
	t->Format("%s",str);
	f.getline(str,1023,'\n');
	p->Format("%s",str);
	if(0==p->GetLength())
		return false;
	else
		return true;
}

void CDatabase::ClearPerson()
{
	CPerson *p1,*p2;
	if(phead!=NULL)
	{
		p1=phead;
		if(p1->next==NULL)
		{
			delete p1;
			return ;
		}
		while(p1->next!=NULL)
		{
			p2=p1->next;
			delete p1;
			p1=p2;
		}
		delete p1;
	}
}

void CDatabase::ClearGroup()
{
	CPGroup *p1,*p2;
	if(ghead!=NULL)
	{
		p1=ghead;
		if(p1->next==NULL)
		{
			delete p1;
			return ;
		}
		while(p1->next!=NULL)
		{
			p2=p1->next;
			delete p1;
			p1=p2;
		}
		delete p1;
	}
}

void CDatabase::KillNowPerson()
{
	if(phead!=NULL)
		this->operator -= (*nowp);
}

bool SaveCSVFile(CDatabase &d,CString &fn)
{
	ofstream f;
	CPerson *p;
	CString s;
	f.open(fn);
	if(!f)
		return false;
	f<<(LPCTSTR)CSV_Title<<endl;
	if(d.phead!=NULL)
	{
		p=d.phead;
		f<<(LPCTSTR)("\""+p->name+"\",")<<(LPCTSTR)("\""+p->birthday+"\",")
			<<(LPCTSTR)("\""+p->province+"\",")<<(LPCTSTR)("\""+p->sex+"\",")
			<<(LPCTSTR)("\""+p->team+"\",")<<(LPCTSTR)("\""+p->position+"\",")
			<<(LPCTSTR)("\""+p->major+"\",")<<(LPCTSTR)("\""+p->school+"\",")
			<<(LPCTSTR)("\""+p->Class+"\",")<<(LPCTSTR)("\""+p->college+"\",")
			<<(LPCTSTR)("\""+p->grade+"\",")<<(LPCTSTR)("\""+p->phone+"\",")
			<<(LPCTSTR)("\""+p->mobi+"\",")<<(LPCTSTR)("\""+p->address+"\",")
			<<(LPCTSTR)("\""+p->postcode+"\",")<<(LPCTSTR)("\""+p->qq+"\",")
			<<(LPCTSTR)("\""+p->email+"\",")<<(LPCTSTR)("\""+p->fax+"\",")
			<<(LPCTSTR)("\""+p->homepage+"\",")<<(LPCTSTR)("\""+p->memo+"\"")<<endl;
		while(p->next!=NULL)
		{
			p=p->next;
			f<<(LPCTSTR)("\""+p->name+"\",")<<(LPCTSTR)("\""+p->birthday+"\",")
				<<(LPCTSTR)("\""+p->province+"\",")<<(LPCTSTR)("\""+p->sex+"\",")
				<<(LPCTSTR)("\""+p->team+"\",")<<(LPCTSTR)("\""+p->position+"\",")
				<<(LPCTSTR)("\""+p->major+"\",")<<(LPCTSTR)("\""+p->school+"\",")
				<<(LPCTSTR)("\""+p->Class+"\",")<<(LPCTSTR)("\""+p->college+"\",")
				<<(LPCTSTR)("\""+p->grade+"\",")<<(LPCTSTR)("\""+p->phone+"\",")
				<<(LPCTSTR)("\""+p->mobi+"\",")<<(LPCTSTR)("\""+p->address+"\",")
				<<(LPCTSTR)("\""+p->postcode+"\",")<<(LPCTSTR)("\""+p->qq+"\",")
				<<(LPCTSTR)("\""+p->email+"\",")<<(LPCTSTR)("\""+p->fax+"\",")
				<<(LPCTSTR)("\""+p->homepage+"\",")<<(LPCTSTR)("\""+p->memo+"\"")<<endl;
		}
		return true;
	}
	return false;
}
void CDatabase::Close()
{
	ClearPerson();
	ClearGroup();
	title="";
	password="";
//	FileName="";
	phead=NULL;
	ghead=NULL;
	nowp=NULL;
	FileOpened=false;
}
bool SaveTXTFile(CDatabase &d,CString &fn)
{
	ofstream f;
	CString s;
	CPerson *p;
	f.open(fn);
	if(!f)
		return false;
	f<<(LPCTSTR)d.GetTitle()<<endl;
	if(d.phead!=NULL)
	{
		p=d.phead;
		f<<"--------------------------------------------------------------"<<endl;
		f<<"    ����:"<<(LPCTSTR)p->GetName()<<endl;
		f<<"��������:"<<(LPCTSTR)p->GetBirthday()<<endl;
		f<<"    ����:"<<(LPCTSTR)p->GetProvince()<<endl;
		f<<"    �Ա�:"<<(LPCTSTR)p->GetSex()<<endl;
		f<<"��������:"<<(LPCTSTR)p->GetTeam()<<endl;
		f<<"    ְ��:"<<(LPCTSTR)p->GetPosition()<<endl;
		f<<"    רҵ:"<<(LPCTSTR)p->GetMajor()<<endl;
		f<<"    ѧУ:"<<(LPCTSTR)p->GetSchool()<<endl;
		f<<"    �༶:"<<(LPCTSTR)p->GetClass()<<endl;
		f<<"    Ժϵ:"<<(LPCTSTR)p->GetCollege()<<endl;
		f<<"    �꼶:"<<(LPCTSTR)p->GetGrade()<<endl;
		f<<"��ͥ�绰:"<<(LPCTSTR)p->GetPhone()<<endl;
		f<<"    �ֻ�:"<<(LPCTSTR)p->GetMobi()<<endl;
		f<<"��ͥסַ:"<<(LPCTSTR)p->GetAddress()<<endl;
		f<<"    �ʱ�:"<<(LPCTSTR)p->GetPostcode()<<endl;
		f<<"      QQ:"<<(LPCTSTR)p->GetQQ()<<endl;
		f<<"��������:"<<(LPCTSTR)p->GetEmail()<<endl;
		f<<"    ����:"<<(LPCTSTR)p->GetFax()<<endl;
		f<<"������ҳ:"<<(LPCTSTR)p->GetHomepage()<<endl;
		f<<"    ��ע:"<<(LPCTSTR)p->GetMemo()<<endl;
		while(p->next!=NULL)
		{
			p=p->next;
			f<<"--------------------------------------------------------------"<<endl;
			f<<"    ����:"<<(LPCTSTR)p->GetName()<<endl;
			f<<"��������:"<<(LPCTSTR)p->GetBirthday()<<endl;
			f<<"    ����:"<<(LPCTSTR)p->GetProvince()<<endl;
			f<<"    �Ա�:"<<(LPCTSTR)p->GetSex()<<endl;
			f<<"��������:"<<(LPCTSTR)p->GetTeam()<<endl;
			f<<"    ְ��:"<<(LPCTSTR)p->GetPosition()<<endl;
			f<<"    רҵ:"<<(LPCTSTR)p->GetMajor()<<endl;
			f<<"    ѧУ:"<<(LPCTSTR)p->GetSchool()<<endl;
			f<<"    �༶:"<<(LPCTSTR)p->GetClass()<<endl;
			f<<"    Ժϵ:"<<(LPCTSTR)p->GetCollege()<<endl;
			f<<"    �꼶:"<<(LPCTSTR)p->GetGrade()<<endl;
			f<<"��ͥ�绰:"<<(LPCTSTR)p->GetPhone()<<endl;
			f<<"    �ֻ�:"<<(LPCTSTR)p->GetMobi()<<endl;
			f<<"��ͥסַ:"<<(LPCTSTR)p->GetAddress()<<endl;
			f<<"    �ʱ�:"<<(LPCTSTR)p->GetPostcode()<<endl;
			f<<"      QQ:"<<(LPCTSTR)p->GetQQ()<<endl;
			f<<"��������:"<<(LPCTSTR)p->GetEmail()<<endl;
			f<<"    ����:"<<(LPCTSTR)p->GetFax()<<endl;
			f<<"������ҳ:"<<(LPCTSTR)p->GetHomepage()<<endl;
			f<<"    ��ע:"<<(LPCTSTR)p->GetMemo()<<endl;
		}
		f<<"--------------------------------------------------------------"<<endl;
	}
	f.close();
	return true;
}
int GetTeamMebCount(CString tn)
{
	CPerson *p;
	int cnt=0;
	if(nowData.phead==NULL)
		return 0;
	p=nowData.phead;
	if(p->GetTeam()==tn)
		cnt++;
	while(p->next!=NULL)
	{
		p=p->next;
		if(p->GetTeam()==tn)
			cnt++;
	}
	return cnt;
}

