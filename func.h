#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>

using namespace std;

struct courses {
	string id, namecr, clsname, teachername, dow, namefilestudent, nocre, scoreboard = "ScoreBoard\\";
	bool publishscore = false;
};

struct semester {
	string startdate{}, enddate{};
	courses* cr;
	int numofclass = 0;
};

struct classes {
	string name;
	string namefile;
};

struct schoolyear {
	string name{};
	int quantity = 0;
	classes *c;
	semester s[4];
};

struct student {
	string fname, lname, gender, birth, socialid, no, studentid, password;
	bool staf = false;
	float ttmark = NULL, fnmark = NULL, mtmark = NULL, omark = NULL;
};

struct staff {
	string id, password, lname, fname, gender, birth;
	bool staf = true;
};

struct node {
	node* next;
	student*s;
	staff* y;
};

struct list {
	node* head;
};

void init(list*& p);
void createschoolyear(schoolyear& scy);
void createclasses(schoolyear& scy);
void addstudent(schoolyear& scy);
void createsemester(schoolyear& scy,int k);
void addacourses(schoolyear& scy, int k, list*& l);
void allo(semester& a, list*& l);
void listofcourses(schoolyear scy, int q);
void updatecourse(schoolyear& scy, int q, int a);
node* createnode(string stt, string mssv,string ho, string ten, string gt, string sinhnhat, string cccd);
node* addelements(node*p,string stt, string mssv,string ho, string ten, string gt, string sinhnhat, string cccd);
node* createnode1(string ms,string mk, string ho, string ten, string gt,string sn);
node* addelements1(node* p, string ms, string mk, string ho, string ten, string gt,string sn);
void addastudent(int k, list*& l, courses s);
void delstudent(int k, list*& l, courses s);
void deletecourse(semester& s, list*& l, int k);
void myinformation(node* temp);
void changeinfo(node* temp, int k);
void listofclasses(schoolyear scy, int q);
void viewlistofstudent(schoolyear scy, int k, int l,int q);
void exportscoreboard(schoolyear scy,  list* l, int q, int a);
void viewscoreboard(schoolyear scy, int q, int a);
void updateresult(schoolyear scy,list*& l,int q, int a);
void myinformation1(node* temp);
void changeinfo1(node* temp, int k);
void viewlistofcourses1(schoolyear scy, int q, list* l, node* temp);