#include"login.h"

node* loginstaf(string tk, string mk,list*l) {
	node* temp = l->head;
	while (temp != NULL) {
		if (temp->y->id == tk && temp->y->password == mk) {
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}

node* loginstud(string tk, string mk, list* l) {
	if (l == NULL) return NULL;
	node* temp = l[1].head;
	int i = 1;
	while (temp != NULL) {
		for (temp = l[i].head; temp != NULL; temp = temp->next) {
			if (temp->s->studentid == tk && temp->s->password == mk) {
				return temp;
			}
			if (temp->s->studentid == tk && temp->s->password != mk) return NULL;
		}
		i++;
		temp = l[i].head;
	}
	return NULL;
}
