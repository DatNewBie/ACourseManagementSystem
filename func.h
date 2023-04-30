#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct courses {
	string id, namecr, clsname, teachername, dow, namefilestudent, nocre;
};

struct semester {
	string startdate, enddate;
	courses *cr;
	int numofclass = 0;
};

struct classes {
	string name;
	string namefile;
};

struct schoolyear {
	string name;
	int quantity;
	classes *c;
	semester s[4];
};

struct student {
	string fname,lname, gender, birth, socialid, no, studentid;
};

struct node {
	node* next;
	student*s;
};

struct list {
	node* head;
};

void createschoolyear(schoolyear& scy);
void createclasses(schoolyear& scy);
void addstudent(schoolyear& scy);
void addacourses(schoolyear& scy, int k, list*& l);
void allo(semester& a, list*& l);
node* createnode(string stt, string mssv,string ho, string ten, string gt, string sinhnhat, string cccd);
node* addelements(node*p,string stt, string mssv,string ho, string ten, string gt, string sinhnhat, string cccd);