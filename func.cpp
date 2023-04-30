#include"func.h"

void createschoolyear(schoolyear& scy) {
	cout << "nhap vao ten nam hoc: ";
	getline(cin, scy.name);
}

void createclasses(schoolyear& scy) {
	cout << "nhap vao so luong lop: ";
	cin >> scy.quantity;
	scy.c = new classes[scy.quantity];
	cin.ignore();
	cout << "nhap vao ten cua tung lop: " << endl;
	for (int i = 0; i < scy.quantity; i++) {
		getline(cin, scy.c[i].name);
	}
}

void addstudent(schoolyear& scy) {
	fstream f, f1;
	int k = 0;
	string details, temp;
	cout << "nhap vao so thu tu cua lop ma ban muon them sinh vien vao: ";
	cin >> k;
	scy.c[k].namefile = scy.c[k].name;
	scy.c[k].namefile += ".csv";
	f.open(scy.c[k].namefile, ios::app);
	cout << "nhap duong link du lieu sinh vien: ";
	cin >> temp;
	f1.open(temp, ios::in);
	while (!f1.eof()) {
		getline(f1, details);
		f << details << endl;
	}
	f.close();
	f1.close();
}

void allo(semester& a, list*&l) {
	if (a.numofclass != 0) {
		courses* temp = new courses[a.numofclass];
		list* temp1 = new list[a.numofclass];
		for (int i = 1; i < a.numofclass; i++) {
			temp[i].id = a.cr[i].id;
			temp[i].namecr = a.cr[i].namecr;
			temp[i].clsname = a.cr[i].clsname;
			temp[i].teachername = a.cr[i].teachername;
			temp[i].dow = a.cr[i].dow;
			temp[i].namefilestudent = a.cr[i].namefilestudent;
			temp[i].nocre = a.cr[i].nocre;
		}
		for (int i = 1; i < a.numofclass; i++) {
			temp1[i].head = l[i].head;
		}
		a.cr = new courses[a.numofclass + 1];
		l = new list[a.numofclass + 1];
		for (int i = 1; i < a.numofclass; i++) {
			a.cr[i].id = temp[i].id;
			a.cr[i].namecr = temp[i].namecr;
			a.cr[i].clsname = temp[i].clsname;
			a.cr[i].teachername = temp[i].teachername;
			a.cr[i].dow = temp[i].dow;
			a.cr[i].namefilestudent = temp[i].namefilestudent;
			a.cr[i].nocre = temp[i].nocre;;
		}
		for (int i = 1; i < a.numofclass; i++) {
			l[i].head = temp1[i].head;
		}
		a.numofclass++;
	}
	else {
		a.numofclass = 1;
		a.cr = new courses[2];
		l = new list[1];
	}
}

void addacourses(schoolyear& scy, int k, list*& l) {
	string temp, temp1, details,stt,ho,ten,mssv,sinhnhat,gt,cccd;
	allo( scy.s[k], l);
	cout << "nhap vao ngay bat dau cua khoa hoc: ";
	getline(cin, scy.s[k].startdate);
	cout << "nhap vao ngay ket thuc cua khoa hoc: ";
	getline(cin,scy.s[k].enddate);
	cout << "nhap vao ma so khoa hoc: ";
	getline(cin,scy.s[k].cr[scy.s[k].numofclass].id);
	cout << "nhap vao ten khoa hoc: ";
	getline(cin,scy.s[k].cr[scy.s[k].numofclass].namecr);
	cout << "nhap vao ten lop hoc: ";
	getline(cin,scy.s[k].cr[scy.s[k].numofclass].clsname);
	cout << "nhap vao ten giao vien: ";
	getline(cin,scy.s[k].cr[scy.s[k].numofclass].teachername);
	cout << "nhap vao so tin chi: ";
	getline(cin,scy.s[k].cr[scy.s[k].numofclass].nocre);
	cout << "nhap vao ngay va gio dien ra buoi hoc: ";
	getline(cin, scy.s[k].cr[scy.s[k].numofclass].dow);
	cout << "nhap vao du lieu sinh vien trong khoa hoc: ";
	cin >> temp;
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
	node* p = new node;
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
		stt = "";
		mssv = "";
		ten = "";
		gt = "";
		sinhnhat = "";
		cccd = "";
	}
	f.close();
	f1.close();
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
	return temp1;
}

node* addelements(node* p, string stt, string mssv,string ho, string ten, string gt, string sinhnhat, string cccd) {
	node*temp1 = createnode(stt, mssv,ho, ten, gt, sinhnhat, cccd);
	p->next = temp1;
	return temp1;
}