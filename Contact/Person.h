#ifndef PERSON_H
#define PERSON_H
class CDatabase;
class CBaseInfor
{
protected:
	CString name;        //����
	CString birthday;    //����
	CString province;    //����
	CString sex;         //�Ա�
	CString team;        //��������
	CString position;    //ְ��
public:
	CBaseInfor();
	void SetName(CString &);        //��������
	void SetBirthday(CString &);    //��������
	void SetProvince(CString &);    //���ü���
	void SetSex(CString &);         //�����Ա�
	void SetTeam(CString &);        //������������
	void SetPosition(CString &);    //����ְ��
	CString GetName();        //����
	CString GetBirthday();    //����
	CString GetProvince();    //����
	CString GetSex();         //�Ա�
	CString GetTeam();        //��������
	CString GetPosition();    //ְ��
	friend bool SaveCSVFile(CDatabase &d,CString &fn);
};
class CStudyInfor
{
protected:
	CString major;     //רҵ
	CString school;    //ѧУ
	CString Class;     //�༶
	CString college;   //Ժϵ
	CString grade;     //�꼶
public:
	CStudyInfor();
	void SetMajor(CString &);     //רҵ
	void SetSchool(CString &);    //ѧУ
	void SetClass(CString &);     //�༶
	void SetCollege(CString &);   //Ժϵ
	void SetGrade(CString &);     //�꼶
	CString GetMajor();     //רҵ
	CString GetSchool();    //ѧУ
	CString GetClass();     //�༶
	CString GetCollege();   //Ժϵ
	CString GetGrade();     //�꼶
	friend bool SaveCSVFile(CDatabase &d,CString &fn);
};

class CContactInfor
{
protected:
	CString phone;       //�绰
	CString mobi;        //�ֻ�
	CString address;     //��ַ
	CString postcode;    //�ʱ�
	CString qq;          //QQ
	CString email;       //��������
	CString fax;         //����
public:
	CContactInfor();
	void SetPhone(CString &);       //�绰
	void SetMobi(CString &);        //�ֻ�
	void SetAddress(CString &);     //��ַ
	void SetPostcode(CString &);    //�ʱ�
	void SetQQ(CString &);          //QQ
	void SetEmail(CString &);       //��������
	void SetFax(CString &);         //����
	CString GetPhone();       //�绰
	CString GetMobi();        //�ֻ�
	CString GetAddress();     //��ַ
	CString GetPostcode();    //�ʱ�
	CString GetQQ();          //QQ
	CString GetEmail();       //��������
	CString GetFax();         //����
	friend bool SaveCSVFile(CDatabase &d,CString &fn);
};
class COtherInfor
{
protected:
	CString homepage;   //������ҳ
	CString memo;       //��ע
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
	int ID;   //��ϵ�˱��
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
