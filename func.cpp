#include"func.h"

void init(list*& p) {
	fstream f;
	string ms, mk, ho, ten, gt,sn;
	string details;
	f.open("staffaccount.txt", ios::in);
	getline(f, details);
	p = new list;
	p->head = new node;
	p->head->y = new staff;
	int i = 0;
	while (i < details.size()) {
		if (details[i] != 44) {
			p->head->y->id += details[i];
			i++;
		}
		else {
			i++;
			while (i < details.size()) {
				if (details[i] != 44) {
					p->head->y->password += details[i];
					i++;
				}
				else {
					i++;
					while (i < details.size()) {
						if (details[i] != 44) {
							p->head->y->lname += details[i];
							i++;
						}
						else {
							i++;
							while (i < details.size()) {
								if (details[i] != 44) {
									p->head->y->fname += details[i];
									i++;
								}
								else {
									i++;
									while (i < details.size()) {
										if (details[i] != 44) {
											p->head->y->gender += details[i];
											i++;
										}
										else {
											i++;
											while (i < details.size()) {
												if (details[i] != 44) {
													p->head->y->birth += details[i];
													i++;
												}
												else {
													i++;
													while (i < details.size()) {
														if (details[i] != 44) {
															p->head->y->staff = true;
															i++;
														}
														else i = details.size();
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	node* temp = p->head;
	while (!f.eof()) {
		i = 0;
		getline(f, details);
		while (i < details.size()) {
			if (details[i] != 44) {
				ms += details[i];
				i++;
			}
			else {
				i++;
				while (i < details.size()) {
					if (details[i] != 44) {
						mk += details[i];
						i++;
					}
					else {
						i++;
						while (i < details.size()) {
							if (details[i] != 44) {
								ho += details[i];
								i++;
							}
							else {
								i++;
								while (i < details.size()) {
									if (details[i] != 44) {
										ten += details[i];
										i++;
									}
									else {
										i++;
										while (i < details.size()) {
											if (details[i] != 44) {
												gt += details[i];
												i++;
											}
											else {
												i++;
												while (i < details.size()) {
													if (details[i] != 44) {
														sn += details[i];
														i++;
													}
													else {
														i++;
														while (i < details.size()) {
															if (details[i] != 44) {
																p->head->y->staff = true;
																i++;
															}
															else  i = details.size();
														}	
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		temp = addelements1(temp, ms, mk, ho, ten, gt,sn);
		ms = "";
		mk = "";
		ho = "";
		ten = "";
		gt = "";
		sn = "";
	}
}

void createschoolyear(schoolyear& scy) {
	cin.ignore();
	cout << "new schoolyear: ";
	getline(cin, scy.name);
	system("pause");
}

void createclasses(schoolyear& scy) {
	cout << "quantity of class: ";
	cin >> scy.quantity;
	scy.c = new classes[scy.quantity + 1];
	cin.ignore();
	cout << "name of class: " << endl;
	for (int i = 1; i <= scy.quantity; i++) {
		cout << i << ") ";
		getline(cin, scy.c[i].name);
	}
	system("pause");
}

void addstudent(schoolyear& scy) {
	fstream f, f1;
	int k = 0;
	string details, temp;
	for (int i = 1; i <= scy.quantity; i++) {
		cout <<i<<") "<< scy.c[i].name << endl;
	}
	cout << "the number of class which need to add student: ";
	cin >> k;
	scy.c[k].namefile = scy.c[k].name;
	scy.c[k].namefile += ".csv";
	f.open(scy.c[k].namefile, ios::app);
	cout << "link data student: ";
	cin >> temp;
	f1.open(temp, ios::in);
	while (!f1.eof()) {
		getline(f1, details);
		f << details << endl;
	}
	f.close();
	f1.close();
	system("pause");
}

void createsemester(schoolyear& scy,int k) {
	cin.ignore();
	cout << "start date: ";
	getline(cin, scy.s[k].startdate);
	cout << "end date: ";
	getline(cin, scy.s[k].enddate);
	system("pause");
}

void allo(semester& a, list*&l) {
	if (a.numofclass != 0) {
		courses* temp = new courses[a.numofclass+2];
		list* temp1 = new list[a.numofclass+2];
		for (int i = 1; i <= a.numofclass; i++) {
			temp[i].id = a.cr[i].id;
			temp[i].namecr = a.cr[i].namecr;
			temp[i].clsname = a.cr[i].clsname;
			temp[i].teachername = a.cr[i].teachername;
			temp[i].dow = a.cr[i].dow;
			temp[i].namefilestudent = a.cr[i].namefilestudent;
			temp[i].nocre = a.cr[i].nocre;
		}
		for (int i = 1; i <= a.numofclass; i++) {
			temp1[i].head = new node;
			temp1[i].head = l[i].head;
		}
		a.cr = new courses[a.numofclass + 2];
		l = new list[a.numofclass + 2];
		for (int i = 1; i <= a.numofclass; i++) {
			a.cr[i].id = temp[i].id;
			a.cr[i].namecr = temp[i].namecr;
			a.cr[i].clsname = temp[i].clsname;
			a.cr[i].teachername = temp[i].teachername;
			a.cr[i].dow = temp[i].dow;
			a.cr[i].namefilestudent = temp[i].namefilestudent;
			a.cr[i].nocre = temp[i].nocre;;
		}
		for (int i = 1; i <= a.numofclass; i++) {
			l[i].head = new node;
			l[i].head = temp1[i].head;
		}
		a.numofclass++;
	}
	else {
		a.numofclass = 1;
		a.cr = new courses[2];
		l = new list[2];
	}
}

void addacourses(schoolyear& scy, int k, list*& l) {
	string temp, temp1, details,stt,ho,ten,mssv,sinhnhat,gt,cccd;
	allo( scy.s[k], l);
	cout << "course id: ";
	cin.ignore();
	getline(cin,scy.s[k].cr[scy.s[k].numofclass].id);
	cout << "course name: ";
	getline(cin,scy.s[k].cr[scy.s[k].numofclass].namecr);
	cout << "class name: ";
	getline(cin,scy.s[k].cr[scy.s[k].numofclass].clsname);
	cout << "teacher name: ";
	getline(cin,scy.s[k].cr[scy.s[k].numofclass].teachername);
	cout << "number of credits: ";
	getline(cin,scy.s[k].cr[scy.s[k].numofclass].nocre);
	cout << "day of the week and the session that the course will be performed: ";
	getline(cin, scy.s[k].cr[scy.s[k].numofclass].dow);
	cout << "link data student: ";
	cin >> temp;
	cin.ignore();
	scy.s[k].cr[scy.s[k].numofclass].namefilestudent = scy.s[k].cr[scy.s[k].numofclass].namecr;
	fstream f, f1;
	f.open(temp, ios::in);
	scy.s[k].cr[scy.s[k].numofclass].namefilestudent += ".csv";
	f1.open(scy.s[k].cr[scy.s[k].numofclass].namefilestudent, ios::app);
	getline(f, details);
	f1 << details << endl;
	getline(f, details);
	f1 << details << endl;
	int i = 0;
	l[scy.s[k].numofclass].head = new node;
	l[scy.s[k].numofclass].head->s = new student;
	while (i < details.size()) {
		if (details[i] != 44) {
			l[scy.s[k].numofclass].head->s->no += details[i];
			i++;
		}
		else {
			i++;
			while (i < details.size()) {
				if (details[i] != 44) {
					l[scy.s[k].numofclass].head->s->studentid+= details[i];
					i++;
				}
				else {
					i++;
					while (i < details.size()) {
						if (details[i] != 44) {
							l[scy.s[k].numofclass].head->s->lname += details[i];
							i++;
						}
						else {
							i++;
							while (i < details.size()) {
								if (details[i] != 44) {
									l[scy.s[k].numofclass].head->s->fname += details[i];
									i++;
								}
								else {
									i++;
									while (i < details.size()) {
										if (details[i] != 44) {
											l[scy.s[k].numofclass].head->s->gender += details[i];
											i++;
										}
										else {
											i++;
											while (i < details.size()) {
												if (details[i] != 44) {
													l[scy.s[k].numofclass].head->s->birth += details[i];
													i++;
												}
												else {
													i++;
													while (i < details.size()) {
														if (details[i] != 44) {
															l[scy.s[k].numofclass].head->s->socialid += details[i];
															i++;
														}
														else i = details.size();
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	l[scy.s[k].numofclass].head->s->staff = false;
	l[scy.s[k].numofclass].head->s->password="123456@";
	node* p = new node;
	fstream f2;
	f2.open("studentaccount.txt", ios::app);
	f2 << endl<< l[scy.s[k].numofclass].head->s->studentid << "," << l[scy.s[k].numofclass].head->s->password << "," << l[scy.s[k].numofclass].head->s->lname << "," << l[scy.s[k].numofclass].head->s->fname << "," << l[scy.s[k].numofclass].head->s->gender << "," << l[scy.s[k].numofclass].head->s->staff << endl;
	p = l[scy.s[k].numofclass].head;
	while (!f.eof()) {
		getline(f, details);
		f1 << details << endl;
		int i = 0;
		while (i < details.size()) {
			if (details[i] != 44) {
				stt += details[i];
				i++; 
			}
			else {
				i++;
				while (i < details.size()) {
					if (details[i] != 44) {
						mssv += details[i];
						i++; 
					}
					else {
						i++;
						while (i < details.size()) {
							if (details[i] != 44) {
								ho += details[i];
								i++; 
							}
							else {
								i++;
								while (i < details.size()) {
									if (details[i] != 44) {
										ten += details[i];
										i++;
									}
									else {
										i++;
										while (i < details.size()) {
											if (details[i] != 44) {
												gt += details[i];
												i++;
											}
											else {
												i++;
												while (i < details.size()) {
													if (details[i] != 44) {
														sinhnhat += details[i];
														i++;
													}
													else {
														i++;
														while (i < details.size()) {
															if (details[i] != 44) {
																cccd += details[i];
																i++;
															}
															else i = details.size();
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		p = addelements(p, stt, mssv,ho, ten, gt, sinhnhat, cccd);
		f2 << mssv << "," << "123456@" << "," << ho << "," << ten << "," << gt << "," << "0" << endl;
		stt = "";
		mssv = "";
		ten = "";
		ho = "";
		gt = "";
		sinhnhat = "";
		cccd = "";
	}
	l[scy.s[k].numofclass + 1].head = NULL;
	f.close();
	f1.close();
	f2.close();
	system("pause");
}

void listofcourses(schoolyear scy,int q) {
	cout << "list of courses in this semester: " << endl;
	for (int i = 1; i <= scy.s[q].numofclass; i++) {
		cout << i << ") " << scy.s[q].cr[i].namecr << endl;
	}
	system("pause");
}

node* createnode(string stt, string mssv,string ho, string ten, string gt, string sinhnhat, string cccd) {
	node* temp1 = new node;
	temp1->s = new student;
	temp1->next = NULL;
	temp1->s->no = stt;
	temp1->s->studentid = mssv;
	temp1->s->lname = ho;
	temp1->s->fname = ten;
	temp1->s->gender = gt;
	temp1->s->birth = sinhnhat;
	temp1->s->socialid = cccd;
	temp1->s->staff = false;
	temp1->s->password = "123456@";
	return temp1;
}

node* addelements(node* p, string stt, string mssv,string ho, string ten, string gt, string sinhnhat, string cccd) {
	node*temp1 = createnode(stt, mssv,ho, ten, gt, sinhnhat, cccd);
	p->next = temp1;
	return temp1;
}

node* createnode1(string ms, string mk, string ho, string ten, string gt,string sn) {
	node* temp1 = new node;
	temp1->y = new staff;
	temp1->next = NULL;
	temp1->y->id = ms;
	temp1->y->password = mk;
	temp1->y->lname = ho;
	temp1->y->fname = ten;
	temp1->y->gender = gt;
	temp1->y->birth = sn;
	temp1->y->staff = true;
	return temp1;
}

node* addelements1(node* p, string ms, string mk, string ho, string ten, string gt,string sn) {
	node* temp1 = createnode1(ms, mk, ho, ten, gt,sn);
	p->next = temp1;
	return temp1;
}

void addastudent(int k,list*& l, courses s) {
	fstream f;
	f.open(s.namefilestudent, ios::out|ios::app);
	string stt, ms, ho, ten, gt, sn, cccd;
	node* temp1 = new node;
	node* temp = l[k].head;
	while (l[k].head->next != NULL) {
		l[k].head = l[k].head->next;
	}
	int n = stoi(l[k].head->s->no);
	n++;
	temp1->s = new student;
	temp1->s->no = to_string(n);
	cout << "id: ";
	getline(cin, temp1->s->studentid);
	cout << "last name: ";
	getline(cin, temp1->s->lname);
	cout << "first name: ";
	getline(cin, temp1->s->fname);
	cout << "gender: ";
	getline(cin, temp1->s->gender);
	cout << "date of birth: ";
	getline(cin, temp1->s->birth);
	cout << "social id: ";
	getline(cin, temp1->s->socialid);
	temp1->s->password = "123456@";
	temp1->s->staff = false;
	l[k].head->next = temp1;
	temp1->next = NULL;
	l[k].head = temp;
	f << temp1->s->no << "," << temp1->s->studentid << "," << temp1->s->lname << "," << temp1->s->fname << "," << temp1->s->gender << "," << temp1->s->birth << "," << temp1->s->socialid << endl;
}

void delstudent(int k, list*& l, courses s) {
	string ms;
	cout << "student's id need to delete: ";
	getline(cin, ms);
	node*temp = l[k].head;
	fstream f;
	f.open(s.namefilestudent, ios::out);
	while (temp != NULL) {
		if (temp->s->studentid != ms)
			f << temp->s->no << "," << temp->s->studentid << "," << temp->s->lname << "," << temp->s->fname << "," << temp->s->gender << "," << temp->s->birth << "," << temp->s->socialid << endl;
		temp = temp->next;
	}
	f.close();
	if (l[k].head!=NULL&&l[k].head->s->studentid == ms) {
		node* temp1 = l[k].head;
		l[k].head = l[k].head->next;
		delete temp1;
		return;
	}
	else {
		if (l[k].head != NULL) {
			node* temp1 = l[k].head;
			l[k].head = l[k].head->next;
			if (l[k].head != NULL) {
				while (l[k].head->next != NULL) {
					if (l[k].head->s->studentid == ms) {
						temp1->next = l[k].head->next;
						l[k].head = temp;
						return;
					}
					temp1 = l[k].head;
					l[k].head = l[k].head->next;
				}
				if (l[k].head->s->studentid == ms) {
					l[k].head = temp1;
					l[k].head->next = NULL;
					l[k].head = temp;
					return;
				}
			}
		}
	}
}

void deletecourse(semester& s, list*& l, int k) {
	for (int i = k; i <= s.numofclass; i++) {
		l[i].head = l[i + 1].head;
	}
	s.numofclass--;
}

void myinformation(node* temp) {
	cout << "id: " << temp->y->id << endl;
	cout << "name :" << temp->y->lname << " " << temp->y->fname << endl;
	cout << "gender: " << temp->y->gender << endl;
	cout << "birth: " << temp->y->birth << endl;
	if(temp->y->staff==true) cout << "staff: true" << endl << endl;
	else cout << "staff: false" << endl << endl;
}

void changeinfo(node* temp, int k) {
	if (k == 1) {
		string mk;
		cout << "input your current password: ";
		cin >> mk;
		if (mk != temp->y->password) cout << "wrong password" << endl;
		else {
			cout << "input your new password: ";
			cin >> mk;
			cout << "input your new password again: ";
			string mk1;
			cin >> mk1;
			if (mk == mk1) {
				temp->y->password = mk;
				cout << "change password successfully" << endl;
			}
			else cout << "password incorrect" << endl;
		}
		return;
	}
	if (k == 2) {
		string ho;
		cout << "input your new last name: ";
		cin.ignore();
		getline(cin, ho);
		temp->y->lname = ho;
		cout << "change your last name successfully" << endl;
		return;
	}
	if (k == 3) {
		string ten;
		cout << "input your new first name: ";
		cin.ignore();
		getline(cin, ten);
		temp->y->fname = ten;
		cout << "change your first name successfully" << endl;
		return;
	}
	if (k == 4) {
		int k;
		cout << "1) male" << endl;
		cout << "2) female" << endl;
		cout << "your choice: " << endl;
		cin >> k;
		if (k == 1) {
			temp->y->gender = "male";
			cout << "change your gender successfully" << endl;
		}
		if (k == 2) {
			temp->y->gender = "female";
			cout << "change your gender successfully" << endl;
		}
		return;
	}
	if (k == 5) {
		string ns;
		cout << "input your new birth: ";
		cin >> ns;
		temp->y->birth = ns;
		cout << "change your birth successfully" << endl;
		return;
	}
}

void updatecourse(schoolyear&scy, int q, int a) {
	cout << "1) id course: " << scy.s[q].cr[a].id << endl;
	cout << "2) name course: " << scy.s[q].cr[a].namecr << endl;
	cout << "3) class name: " << scy.s[q].cr[a].clsname << endl;
	cout << "4) teacher name: " << scy.s[q].cr[a].teachername << endl;
	cout << "5) number of credits: " << scy.s[q].cr[a].nocre << endl;
	cout << "6) day and the session that the course will be performed: " << scy.s[q].cr[a].dow << endl;
	cout << "you want to update(input 0 to stop update): ";
	int x;
	string temp;
	cin >> x;
	while (x != 0) {
		switch (x) {
		case 1: {
			cout << "new id course: ";
			cin.ignore();
			getline(cin, temp);
			scy.s[q].cr[a].id = temp;
			break;
		}
		case 2: {
			cout << "new name course: ";
			cin.ignore();
			getline(cin, temp);
			scy.s[q].cr[a].namecr = temp;
			temp += ".csv";
			const char* oldname = scy.s[q].cr[a].namefilestudent.c_str();
			const char* newname = temp.c_str();
			rename(oldname, newname);
			break;
		}
		case 3: {
			cout << "new class name: ";
			cin.ignore();
			getline(cin, temp);
			scy.s[q].cr[a].clsname = temp;
			break;
		}
		case 4: {
			cout << "new teacher name: ";
			cin.ignore();
			getline(cin, temp);
			scy.s[q].cr[a].teachername = temp;
			break;
		}
		case 5: {
			cout << "new number of credits: ";
			cin.ignore();
			getline(cin, temp);
			scy.s[q].cr[a].nocre = temp;
			break;
		}
		case 6: {
			cout << "new day and the session that the course will be performed: ";
			cin.ignore();
			getline(cin, temp);
			scy.s[q].cr[a].dow = temp;
			break;
		}
		}
		cout << "you want to update(input 0 to stop update): ";
		cin >> x;
	}
}