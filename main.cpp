#include"func.h"

int main() 
{	
	list* l;
	schoolyear scy;
	createschoolyear(scy);
	addacourses(scy, 1, l);
	cout << l[1].head->s->fname;
}