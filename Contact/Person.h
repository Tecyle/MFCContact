#ifndef PERSON_H
#define PERSON_H
class CDatabase;
class CBaseInfor
{
protected:
	CString name;        //姓名
	CString birthday;    //生日
	CString province;    //籍贯
	CString sex;         //性别
	CString team;        //所属分组
	CString position;    //职务
public:
	CBaseInfor();
	void SetName(CString &);        //设置姓名
	void SetBirthday(CString &);    //设置生日
	void SetProvince(CString &);    //设置籍贯
	void SetSex(CString &);         //设置性别
	void SetTeam(CString &);        //设置所属分组
	void SetPosition(CString &);    //设置职务
	CString GetName();        //姓名
	CString GetBirthday();    //生日
	CString GetProvince();    //籍贯
	CString GetSex();         //性别
	CString GetTeam();        //所属分组
	CString GetPosition();    //职务
	friend bool SaveCSVFile(CDatabase &d,CString &fn);
};
class CStudyInfor
{
protected:
	CString major;     //专业
	CString school;    //学校
	CString Class;     //班级
	CString college;   //院系
	CString grade;     //年级
public:
	CStudyInfor();
	void SetMajor(CString &);     //专业
	void SetSchool(CString &);    //学校
	void SetClass(CString &);     //班级
	void SetCollege(CString &);   //院系
	void SetGrade(CString &);     //年级
	CString GetMajor();     //专业
	CString GetSchool();    //学校
	CString GetClass();     //班级
	CString GetCollege();   //院系
	CString GetGrade();     //年级
	friend bool SaveCSVFile(CDatabase &d,CString &fn);
};

class CContactInfor
{
protected:
	CString phone;       //电话
	CString mobi;        //手机
	CString address;     //地址
	CString postcode;    //邮编
	CString qq;          //QQ
	CString email;       //电子邮箱
	CString fax;         //传真
public:
	CContactInfor();
	void SetPhone(CString &);       //电话
	void SetMobi(CString &);        //手机
	void SetAddress(CString &);     //地址
	void SetPostcode(CString &);    //邮编
	void SetQQ(CString &);          //QQ
	void SetEmail(CString &);       //电子邮箱
	void SetFax(CString &);         //传真
	CString GetPhone();       //电话
	CString GetMobi();        //手机
	CString GetAddress();     //地址
	CString GetPostcode();    //邮编
	CString GetQQ();          //QQ
	CString GetEmail();       //电子邮箱
	CString GetFax();         //传真
	friend bool SaveCSVFile(CDatabase &d,CString &fn);
};
class COtherInfor
{
protected:
	CString homepage;   //个人主页
	CString memo;       //备注
public:
	COtherInfor();
	void SetHomepage(CString &);
	void SetMemo(CString &);
	CString GetHomepage();
	CString GetMemo();
	friend bool SaveCSVFile(CDatabase &d,CString &fn);
};
class CPerson : public CBaseInfor, public CStudyInfor, public CContactInfor, public COtherInfor
{
protected:
	int ID;   //联系人编号
public:
	void SetMebValue(CString h,CString v);
	CString GetMebValue(CString h);
	static int mCount;
	CPerson *next;
	CPerson *prev;
	CPerson();
	void SetBase(CBaseInfor &);
	void SetStudy(CStudyInfor &);
	void SetContact(CContactInfor &);
	void SetOther(COtherInfor &);
	CBaseInfor GetBase();
	CStudyInfor GetStudy();
	CContactInfor GetContact();
	COtherInfor GetOther();
	void SetID(int);
	int GetID();
	bool operator == (CPerson &);
	int CmpMebValue(CString,CString);
	friend bool SaveCSVFile(CDatabase &d,CString &fn);
};
class CPGroup
{
protected:
	CString name;
public:
	CPGroup *next;
	static int memNum;
	CPGroup();
	CString GetName();
	void SetName(CString &);
	virtual bool IsInThisTeam(CPerson &);
};
class CNoneGroup : public CPGroup
{
protected:

public:
	CNoneGroup();
	bool IsInThisTeam(CPerson &);
};
class CDatabase
{
protected:
	CString FileName;
	CString title;
	CString password;
public:
	bool FileOpened;
	void Close();
	void KillNowPerson();
	void ClearGroup();
	void ClearPerson();
	CPerson * nowp;
	CPerson *phead;
	CPGroup *ghead;
	CNoneGroup nGroup;
	bool GetHeadInfor(CString *t,CString *p);
	CString GetPswd();
	void SetPswd(CString &pswd);
	void SetTitle(CString &t);
	CString GetTitle();
	bool CreateDatabase(CString &fn);
	CDatabase();
	~CDatabase();
	void operator += (CPerson &);
	void operator += (CPGroup &);
	bool operator -= (CPerson &);
	bool operator -= (CPGroup &);
	bool OpenFile(CString pswd="");
	bool SaveFile(CString fn="");
	void SetFileName(CString &);
	CString GetFileName();
};
bool SaveTXTFile(CDatabase &d,CString &fn);
int GetTeamMebCount(CString tn);
extern CDatabase nowData;
#endif
