#include "stdafx.h"
#include <fstream>
#include "Person.h"
#include <iomanip>
using namespace std;

const CString CSV_Title = "\"姓名\",\"出生日期\",\"籍贯\",\"性别\",\"所属分组\",\"职务\",\"专业\",\"学校\",\"班级\",\"院系\",\"年级\",\"家庭电话\",\"手机\",\"家庭住址\",\"邮编\",\"QQ\",\"电子邮箱\",\"传真\",\"个人主页\",\"备注\"";
CDatabase nowData;
////////////////////////////////////////联系人基本信息类//////////////////////////////////////////////////
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
//////////////////////////////////////////联系人学籍信息类////////////////////////////////////////////
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
////////////////////////////////////////////联系人联系方式类////////////////////////////////////////////
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
//////////////////////////////////////////联系人其他信息类////////////////////////////////////////////////////
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
///////////////////////////////////////////////////联系人类///////////////////////////////////////////////////////
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
	if(h=="姓名")
		return name.Find(v);
	else if(h=="出生日期")
		return birthday.Find(v);
	else if(h=="籍贯")
		return province.Find(v);
	else if(h=="性别")
		return sex.Find(v);
	else if(h=="所属分组")
		return team.Find(v);
	else if(h=="职务")
		return position.Find(v);
	else if(h=="专业")
		return major.Find(v);
	else if(h=="学校")
		return school.Find(v);
	else if(h=="班级")
		return Class.Find(v);
	else if(h=="院系")
		return college.Find(v);
	else if(h=="年级")
		return grade.Find(v);
	else if(h=="家庭电话")
		return phone.Find(v);
	else if(h=="手机")
		return mobi.Find(v);
	else if(h=="家庭住址")
		return address.Find(v);
	else if(h=="邮编")
		return postcode.Find(v);
	else if(h=="QQ")
		return qq.Find(v);
	else if(h=="电子邮箱")
		return email.Find(v);
	else if(h=="传真")
		return fax.Find(v);
	else if(h=="个人主页")
		return homepage.Find(v);
	else if(h=="备注")
		return memo.Find(v);
	return -1;
}
CString CPerson::GetMebValue(CString h)
{
	if(h=="姓名")
		return name;
	else if(h=="出生日期")
		return birthday;
	else if(h=="籍贯")
		return province;
	else if(h=="性别")
		return sex;
	else if(h=="所属分组")
		return team;
	else if(h=="职务")
		return position;
	else if(h=="专业")
		return major;
	else if(h=="学校")
		return school;
	else if(h=="班级")
		return Class;
	else if(h=="院系")
		return college;
	else if(h=="年级")
		return grade;
	else if(h=="家庭电话")
		return phone;
	else if(h=="手机")
		return mobi;
	else if(h=="家庭住址")
		return address;
	else if(h=="邮编")
		return postcode;
	else if(h=="QQ")
		return qq;
	else if(h=="电子邮箱")
		return email;
	else if(h=="传真")
		return fax;
	else if(h=="个人主页")
		return homepage;
	else if(h=="备注")
		return memo;
	return "error";
}

void CPerson::SetMebValue(CString h, CString v)
{
	if(h=="姓名")
		name=v;
	else if(h=="出生日期")
		birthday=v;
	else if(h=="籍贯")
		province=v;
	else if(h=="性别")
		sex=v;
	else if(h=="所属分组")
		team=v;
	else if(h=="职务")
		position=v;
	else if(h=="专业")
		major=v;
	else if(h=="学校")
		school=v;
	else if(h=="班级")
		Class=v;
	else if(h=="院系")
		college=v;
	else if(h=="年级")
		grade=v;
	else if(h=="家庭电话")
		phone=v;
	else if(h=="手机")
		mobi=v;
	else if(h=="家庭住址")
		address=v;
	else if(h=="邮编")
		postcode=v;
	else if(h=="QQ")
		qq=v;
	else if(h=="电子邮箱")
		email=v;
	else if(h=="传真")
		fax=v;
	else if(h=="个人主页")
		homepage=v;
	else if(h=="备注")
		memo=v;
}
int CPerson::mCount=0;
/////////////////////////////////////////////////分组类//////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////未分组成员//////////////////////////////////////////////////////////
CNoneGroup::CNoneGroup()
{
	name="未分组联系人";
}
bool CNoneGroup::IsInThisTeam(CPerson &p)
{
	return p.GetTeam()==""?true:false;
}
//////////////////////////////////////////////////联系人数据库类/////////////////////////////////////////////////////////
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
void CDatabase::operator += (CPerson &p)		//重载+=运算符，实现 数据库变量+=联系人; 语句
{
	CPerson *p1=new CPerson,*p2;				//新建立一块内存空间用来存储联系人信息
	*p1=p;										//将联系人信息写入新建立的内存中
	CPerson::mCount++;							//联系人总数增加一
	p1->SetID(CPerson::mCount);					//设置新建立的联系人的ID号
	if(phead==NULL)								//判断当前新建的联系人是不是第一个联系人
	{
		phead=p1;								//如果是第一个联系人的话，将链表头指针赋值
		p1->prev=NULL;							//并设定联系人的前后指针
		nowp=phead;								//将当前指针定在链表的开始处
		return;
	}else{
		p2=phead;								//如果链表不是空的
		while((p2->next)!=NULL)					//就p2移动到链表的末尾
		{
			p2=p2->next;
		}
		p2->next=p1;							//通过设定前后指针的指向，将联系人信息插入链表
		p1->prev=p2;
		return;
	}
}

bool CDatabase::operator -= (CPerson &p)		//重载-=运算符，用以实现对联系人的删除
{
	CPerson *p1=&p,*p2,*p3;						//p1指针定位要删除的联系人，p2、p3作前后指向
	int n_id=nowp->GetID();						//获取当前指向联系人ID，为了防止nowp指向无效内存
	bool del=false;								//标记是否已经删除，为重设ID提供依据
	if(phead==NULL)								//如果链表是空的
		return false;							//也就不存在什么删除问题了
	else{
		CPerson::mCount-=1;						//联系人总数减一
		p2=phead;								//开始搜索要删除的联系
		if(p2->GetID()==p1->GetID())			//判断联系人是否该被删除的依据是ID号
		{
			phead=p2->next;						//要删除的联系人在链表头，则要重设链表头
			if(phead!=NULL)						//测试新的链表头是否是空的
				phead->prev=NULL;				//不是空的话重设前指针
			if(p1->GetID()==n_id)				//如果删除的联系人正好是当前指针指向的联系人
				nowp=phead;						//将当前指针指向新的链表头，以防错误发生
			delete p2;							//释放要删除的联系人的内存
			p2=phead;							//重新定向p2，为了以后的重编ID号
			del=true;							//标记已经删除
		}		
		if(p2!=NULL)							//先确保链表中不止一个联系人
		{
			while(p2->next!=NULL)				//对每一个联系人都进行操作
			{
				p3=p2->next;
				if(del)							//如果已经删除了联系人
					p2->SetID(p2->GetID()-1);	//新编的ID号因比原来的少一
				if(p3->GetID()==p1->GetID())	//如果之前没有删除过（由ID号的唯一性确定）
				{
					p2->next=p3->next;			//重设后指针，将要删除的联系人脱离出来
					if(p3->next!=NULL)
						p3->next->prev=p2;		//重设前指针
					if(p1->GetID()==n_id)		//排除当前指针指向无效内存的问题
						nowp=p2;
					delete p3;					//释放删除联系人占有的内存
					del=true;
				}
				p2=p2->next;
				if(p2==NULL)					//防止循环纰漏
					return del;					//返回是否成功删除
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
bool CDatabase::OpenFile(CString pswd/*=""*/)	//OpenFile函数实现文件打开功能
{
	ifstream f;							//使用ifstream对象对文件进行操作
	CString s,s2;							//定义一系列临时变量
	CPerson p;
	CPGroup g;
	char s1[2048];
	int i=0,k=0,j=0;
	f.open(FileName,ios::in);				//打开文件
	if(!f)
	{
		return false;						//文件打开失败则退出函数，返回false
	}
	else{
		Close();							//自定义的关闭函数，关闭当前已经打开的数据库
		if(!f.eof()) 						//先读入标题信息
		{
			f.getline(s1,256,'\n');
			title.Format("%s",s1);			//转换成CString类型
		}
		else{
			f.close();						//容错处理，遇到意外的文件格式
			return false;
		}
		if(!f.eof())						//再读入密码信息
		{
			f.getline(s1,256,'\n');
			password.Format("%s",s1);		//转换成CString类型并存入password变量中
		}
		else{
			f.close();
			return false;					//容错处理，遇到意外的文件格式
		}
		f.getline(s1,256,'\n');				//读入分组信息
		s.Format("%s",s1);
		if(s=="[Group Information]")			//分组开始标记
		{
			f.getline(s1,2047,'\n');
			s.Format("%s",s1);
			while(s!="[End Group]")		//以读到分组结束标记为结束位置
			{
				g.SetName(s);
				this->operator += (g);		//添加新读入的分组到数据库管理类中
				f.getline(s1,2047,'\n');
				s.Format("%s",s1);
			}
		}
		i=j=0;s="";
		while(!f.eof())						//最后读入联系人信息
		{
			f.getline(s1,2047,'\n');
			s.Format("%s",s1);
			j=i=k=0;
			if(0!=s.GetLength())			//去掉空行
			{
				s+='\0';					//以常规字符串的形式处理CString字符串
				while(s.GetAt(i)!='\0')
				{
					if(s[i]=='|')			//提取分隔标记"|"
					{
						s2=s.Mid(j,i-j);	//分离出两个"|"之间的字符串
						j=i+1;			//重新设置"|"出现的位置号
						k++;				//标记这是第几个分离出来的值
						switch(k)			//按照值的序数一次对新建联系人的各个属性赋值
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
				this->operator += (p);			//将新建的联系人添加到数据库管理类中
			}
		}
	}
	f.close();
	nowp=phead;								//定位nowp指针的指向
	FileOpened=true;							//标记文件已经打开
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
		//输出分组
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
		//开始输出链表
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
			//输出最后一个
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
		f<<"同学"<<endl;
		f<<"老师"<<endl;
		f<<"亲人"<<endl;
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
		f<<"    姓名:"<<(LPCTSTR)p->GetName()<<endl;
		f<<"出生日期:"<<(LPCTSTR)p->GetBirthday()<<endl;
		f<<"    籍贯:"<<(LPCTSTR)p->GetProvince()<<endl;
		f<<"    性别:"<<(LPCTSTR)p->GetSex()<<endl;
		f<<"所属分组:"<<(LPCTSTR)p->GetTeam()<<endl;
		f<<"    职务:"<<(LPCTSTR)p->GetPosition()<<endl;
		f<<"    专业:"<<(LPCTSTR)p->GetMajor()<<endl;
		f<<"    学校:"<<(LPCTSTR)p->GetSchool()<<endl;
		f<<"    班级:"<<(LPCTSTR)p->GetClass()<<endl;
		f<<"    院系:"<<(LPCTSTR)p->GetCollege()<<endl;
		f<<"    年级:"<<(LPCTSTR)p->GetGrade()<<endl;
		f<<"家庭电话:"<<(LPCTSTR)p->GetPhone()<<endl;
		f<<"    手机:"<<(LPCTSTR)p->GetMobi()<<endl;
		f<<"家庭住址:"<<(LPCTSTR)p->GetAddress()<<endl;
		f<<"    邮编:"<<(LPCTSTR)p->GetPostcode()<<endl;
		f<<"      QQ:"<<(LPCTSTR)p->GetQQ()<<endl;
		f<<"电子邮箱:"<<(LPCTSTR)p->GetEmail()<<endl;
		f<<"    传真:"<<(LPCTSTR)p->GetFax()<<endl;
		f<<"个人主页:"<<(LPCTSTR)p->GetHomepage()<<endl;
		f<<"    备注:"<<(LPCTSTR)p->GetMemo()<<endl;
		while(p->next!=NULL)
		{
			p=p->next;
			f<<"--------------------------------------------------------------"<<endl;
			f<<"    姓名:"<<(LPCTSTR)p->GetName()<<endl;
			f<<"出生日期:"<<(LPCTSTR)p->GetBirthday()<<endl;
			f<<"    籍贯:"<<(LPCTSTR)p->GetProvince()<<endl;
			f<<"    性别:"<<(LPCTSTR)p->GetSex()<<endl;
			f<<"所属分组:"<<(LPCTSTR)p->GetTeam()<<endl;
			f<<"    职务:"<<(LPCTSTR)p->GetPosition()<<endl;
			f<<"    专业:"<<(LPCTSTR)p->GetMajor()<<endl;
			f<<"    学校:"<<(LPCTSTR)p->GetSchool()<<endl;
			f<<"    班级:"<<(LPCTSTR)p->GetClass()<<endl;
			f<<"    院系:"<<(LPCTSTR)p->GetCollege()<<endl;
			f<<"    年级:"<<(LPCTSTR)p->GetGrade()<<endl;
			f<<"家庭电话:"<<(LPCTSTR)p->GetPhone()<<endl;
			f<<"    手机:"<<(LPCTSTR)p->GetMobi()<<endl;
			f<<"家庭住址:"<<(LPCTSTR)p->GetAddress()<<endl;
			f<<"    邮编:"<<(LPCTSTR)p->GetPostcode()<<endl;
			f<<"      QQ:"<<(LPCTSTR)p->GetQQ()<<endl;
			f<<"电子邮箱:"<<(LPCTSTR)p->GetEmail()<<endl;
			f<<"    传真:"<<(LPCTSTR)p->GetFax()<<endl;
			f<<"个人主页:"<<(LPCTSTR)p->GetHomepage()<<endl;
			f<<"    备注:"<<(LPCTSTR)p->GetMemo()<<endl;
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

