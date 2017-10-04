#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct node
{
int data;
struct node* next;
}NODE,*PNODE,**PPNODE;


class SinglyLinkedList
{
private:
	PNODE head;
public:
	SinglyLinkedList();
	void InsertFirst(int);
	void InsertLast(int);
	void InsertAtPosition(int,int);
	void Display();
	void DisplayN(int);
	//void DisplayReverse();
	//void DisplayForward();//recursively 
	int llCount();

	void DeleteFirst();
	void DeleteAtPosition(int);
	void DeleteLast();
	void DeleteAll();
	void DeleteNode(int);
};