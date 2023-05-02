#include"login.h"

bool login(string tk, string mk,list*&l,list*&p,schoolyear scy,int k) {
	node* temp = p->head;
	while (temp != NULL) {
		if (temp->y->id == tk && temp->y->password == mk) {
			return true;
		}
		temp = temp->next;
	}
	if (k == -1) return false;
	else {
		for (int i = 1; i <= scy.s[k].numofclass; i++) {
			node* temp1 = l[i].head;
			while (temp1 != NULL) {
				if (tk == temp1->s->studentid && temp1->s->password == mk) {
					return true;
				}
				temp1 = temp1->next;
			}
		}
		return false;
	}
}
