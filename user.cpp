#include<iostream>
#include<stdlib.h>

#include"sharedheader.h"
#include<dlfcn.h>
int main()
{
	
	//SinglyLinkedList sll;
	void* p=NULL;
	SinglyLinkedList* ptr=NULL;
	SinglyLinkedList*(*fp1)()=NULL;
	void (*fp2)(SinglyLinkedList*)=NULL;
	p=dlopen("library.so",RTLD_LAZY);
	if(!p)
	{
		cout<<"unable to load library";
		return -1;
	}
	fp1=(SinglyLinkedList*(*)())dlsym(p,"create");
	fp2=(void(*)(SinglyLinkedList*))dlsym(p,"destroy");
	ptr=fp1();
	cout<<ptr;

	ptr->InsertFirst(10);
	ptr->InsertLast(20);
	ptr->InsertLast(20);
	ptr->InsertLast(20);
	ptr->InsertAtPosition(30,2);
	ptr->DeleteFirst();
	ptr->Display();
	//ptr->DeleteLast();
	//ptr->DisplayN(2);
	ptr->DeleteNode(20);
	//ptr->DeleteAll();
	ptr->Display();	
	fp2(ptr);
	dlclose(p);

cout<<"main";

return 0;
}
