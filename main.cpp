#include"login.h"

int main() {
	string tk, mk;
	int i = -1, x;
	list* l, * p;
	schoolyear scy;
	init(p);
	while (i != 0) {
		cout << "user name: ";
		cin >> tk;
		cout << "password: ";
		cin >> mk;
		if (loginstaf(tk, mk, p)!=NULL) {
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
					cout << "id: " << temp->y->id << endl;
					cout << "name :" << temp->y->lname << " " << temp->y->fname << endl;
					cout << "gender: " << temp->y->gender << endl;
					cout << "birth: " << temp->y->birth << endl;
					cout << "staff: true" << endl << endl;
					cout << "0) back" << endl;
					cout << "1) change information";
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
										if (mk == mk1) cout << "change password successfully" << endl;
										else cout << "password incorrect" << endl;
									}
									break;
								}
								case 2: {
									string ho;
									cout << "input your new last name: ";
									cin.ignore();
									getline(cin, ho);
									temp->y->lname = ho;
									cout << "change your last name successfully" << endl;
									break;
								}
								case 3: {
									string ten;
									cout << "input your new first name: ";
									cin.ignore();
									getline(cin, ten);
									temp->y->fname = ten;
									cout << "change your first name successfully" << endl;
									break;
								}
								case 4: {
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
									break;
								}
								case 5: {
									string ns;
									cout << "input your new birth: ";
									cin >> ns;
									temp->y->birth = ns;
									cout << "change your birth successfully" << endl;
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
	}
}