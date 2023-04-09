#include"login.h"

void createacc()
{	
	char username[100], password[100], temp[100];
	bool ok = false; int dem = 0;
	cout << "ten tai khoan: ";
	cin.getline(username, 100);
	while (!ok)
	{
		fstream f;
		f.open("accstudents.txt", ios::in);
		dem = 0;
		while (!f.eof()) {
			f.getline(temp, 100);
			if (strcmp(temp, username) == 0)
			{
				cout << "ten tai khoan da ton tai, nhap ten khac" << endl;
				dem++;
				break;
			} 
			f.getline(temp, 100);
		}
		if (dem != 0)
		{
			cout << "ten tai khoan: ";
			cin.getline(username, 100);
		}
		else 
		{
			ok = true;
			f.close();
		}
	}
	fstream f;
	cout << "nhap vao mat khau: ";
	cin.getline(password, 100);
	f.open("accstudents.txt", ios::app);
	f << username << endl;
	f << password << endl;
	f.close();
}
