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
			cout << "8) add a student to the course" << endl;
			cout << "9) remove a student from the course" << endl;
			cout << "10) delete a course" << endl;
			cout << "number of order: ";
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
							cout << "number of order: " << endl;
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
				cout << "8) add a student to the course" << endl;
				cout << "9) remove a student from the course" << endl;
				cout << "10) delete a course" << endl;
				cout << "your choice: ";
				cin >> x;
			}
		}
		else cout << "user name or password incorrect" << endl;
	}
}