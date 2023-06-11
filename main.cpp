#include"login.h"

int main() {
	string tk, mk;
	int i = -1, x, q = 1;
	list* l, * p;
	schoolyear scy;
	init(p);
	while (i != 0) {
		cout << "user name: ";
		cin >> tk;
		cout << "password: ";
		cin >> mk;
		if (loginstaf(tk, mk, p) != NULL) {
			node* temp = loginstaf(tk, mk, p);
			cout << "0) log out" << endl;
			cout << "1) my information" << endl;
			cout << "2) create a school year" << endl;
			cout << "3) create several classes for 1st-year student" << endl;
			cout << "4) add new 1st year student to 1st-year classes" << endl;
			cout << "5) create a semester" << endl;
			cout << "6) add a course to this semester" << endl;
			cout << "7) view list of courses" << endl;
			cout << "8) update course information" << endl;
			cout << "9) add a student to the course" << endl;
			cout << "10) remove a student from the course" << endl;
			cout << "11) delete a course" << endl;
			cout << "12) view list of classes" << endl;
			cout << "13) view list of student" << endl;
			cout << "14) export the scoreboard of a course" << endl;
			cout << "15) view the scoreboard of a course" << endl;
			cout << "16) update a student's result" << endl;
			cout << "your choice: ";
			cin >> x;
			while (x != 0) {
				switch (x) {
				case 1: {
					system("cls");
					myinformation(temp);
					cout << "0) back" << endl;
					cout << "1) change information" << endl;
					cout << "your choice: " << endl;
					int k;
					cin >> k;
					while (k != 0) {
						switch (k) {
						case 1: {
							system("cls");
							cout << "0) back" << endl;
							cout << "1) change password" << endl;
							cout << "2) change last name" << endl;
							cout << "3) change first name" << endl;
							cout << "4) change gender" << endl;
							cout << "5) change birth" << endl;
							cout << "your choice: " << endl;
							int l;
							cin >> l;
							while (l != 0) {
								switch (l) {
								case 1: {
									changeinfo(temp, l);
									break;
								}
								case 2: {
									changeinfo(temp, l);
									break;
								}
								case 3: {
									changeinfo(temp, l);
									break;
								}
								case 4: {
									changeinfo(temp, l);
									break;
								}
								case 5: {
									changeinfo(temp, l);
									break;
								}
								}
								cout << "your choice: ";
								cin >> l;
							}
						}
						}
						system("cls");
						cout << "id: " << temp->y->id << endl;
						cout << "name :" << temp->y->lname << " " << temp->y->fname << endl;
						cout << "gender: " << temp->y->gender << endl;
						cout << "birth: " << temp->y->birth << endl;
						cout << "staff: true" << endl << endl;
						cout << "0) back" << endl;
						cout << "1) change information";
						cout << "your choice: ";
						cin >> k;
					}
					break;
				}
				case 2: {
					createschoolyear(scy);
					break;
				}
				case 3: {
					createclasses(scy);
					break;
				}
				case 4: {
					addstudent(scy);
					break;
				}
				case 5: {
					cout << "the semester you want to create: ";
					cin >> q;
					createsemester(scy, q);
					break;
				}
				case 6: {
					addacourses(scy, q, l);
					break;
				}
				case 7: {
					listofcourses(scy, q);
					break;
				}
				case 8: {
					listofcourses(scy, q);
					cout << "number of course which you want to update information: ";
					int a;
					cin >> a;
					updatecourse(scy, q, a);
					break;
				}
				case 9: {
					listofcourses(scy, q);
					cout << "number of course which you want to add a student: ";
					int a;
					cin >> a;
					addastudent(a, l, scy.s[q].cr[a]);
					break;
				}
				case 10: {
					listofcourses(scy, q);
					cout << "number of course which you want to remove a student: ";
					int a;
					cin >> a;
					delstudent(a, l, scy.s[q].cr[a]);
					break;
				}
				case 11: {
					listofcourses(scy, q);
					cout << "number of course which you want to delete: ";
					int a;
					cin >> a;
					deletecourse(scy.s[q], l, a);
					break;
				}
				case 12: {
					listofclasses(scy, q);
					break;
				}
				case 13: {
					cout << "0) exit" << endl;
					cout << "1) view list of student in class" << endl;
					cout << "2) view list of student in course" << endl;
					int k;
					cout << "your choice: ";
					cin >> k;
					while (k != 0) {
						switch (k) {
						case 1: {
							listofclasses(scy, q);
							cout << "number of class: ";
							int l;
							cin >> l;
							viewlistofstudent(scy, k, l, q);
							break;
						}
						case 2: {
							listofcourses(scy, q);
							cout << "number of course: ";
							int l;
							cin >> l;
							viewlistofstudent(scy, k, l, q);
							break;
						}
						}
						cout << "your choice: ";
						cin >> k;
					}
				}
				case 14: {
					listofcourses(scy, q);
					cout << "your choice: ";
					int a;
					cin >> a;
					exportscoreboard(scy, l, q, a);
					break;
				}
				case 15: {
					listofcourses(scy, q);
					cout << "your choice: ";
					int a;
					cin >> a;
					viewscoreboard(scy, q, a);
					break;
				}
				case 16: {

				}
				}
				system("cls");
				cout << "0) log out" << endl;
				cout << "1) my information" << endl;
				cout << "2) create a school year" << endl;
				cout << "3) create several classes for 1st-year student" << endl;
				cout << "4) add new 1st year student to 1st-year classes" << endl;
				cout << "5) create a semester" << endl;
				cout << "6) add a course to this semester" << endl;
				cout << "7) view list of courses" << endl;
				cout << "8) update course information" << endl;
				cout << "9) add a student to the course" << endl;
				cout << "10) remove a student from the course" << endl;
				cout << "11) delete a course" << endl;
				cout << "12) view list of classes" << endl;
				cout << "13) view list of student" << endl;
				cout << "14) export the scoreboard of a course" << endl;
				cout << "15) view a scoreboard of a course" << endl;
				cout << "16) update a student's result" << endl;
				cout << "your choice: ";
				cin >> x;
			}
		}
		else cout << "user name or password incorrect" << endl;
	}
}