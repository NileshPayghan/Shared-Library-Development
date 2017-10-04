///////////////////////////////////////////////////////////////////////////////////////////////////////
//Name:
//Modified: 2017
//Author: Nilesh Payghan
//Input:
//output:
//Description:
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<stdlib.h>

#include"sharedheader.h"


SinglyLinkedList::SinglyLinkedList()
{
	head=NULL;
}

/////////////////////////////////////////////////////////////////////////////////////////////
void SinglyLinkedList::InsertFirst(int data)
{

	PNODE newn=NULL;
	newn=(PNODE)malloc(sizeof(NODE));
	
	//copy data to node
	newn->data=data;
	//copy the address of head node of linked list into newn->next
	newn->next=head;
	//copy the address of newn element into *head
	head=newn;
}
//////////////////////////////////////////////////////////////////////////////////////////////

void SinglyLinkedList::InsertLast(int data)
{
	
	PNODE newn=NULL;
	PNODE temp=head;
	newn=(PNODE)malloc(sizeof(NODE));
	if(newn==NULL)
	{
		return;
	}
	newn->data=data;
	newn->next=NULL;
	//if linked is empty
	if(head==NULL)
	{
		head=newn;
	}
	//if linked list contains at least single element
	else
	{
		//go till end of linked list
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		//copy address of newn into end of the linked list
		temp->next=newn;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////
void SinglyLinkedList::Display()
{
	PNODE first=head;
	//traversing the whole linked list elements
	while(first!=NULL)
	{
		cout<<(first->data)<<endl;
		first=first->next;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////
int SinglyLinkedList::llCount()
{
if(head==NULL)
	return 0;
int cnt=0;
PNODE temp=head;
	//traversing the whole linked list elements
	while(temp!=NULL)
	{
		temp=temp->next;
		cnt++;
	}
return cnt;
}
///////////////////////////////////////////////////////////////////////////////////////////
void SinglyLinkedList::InsertAtPosition(int data,int pos)
{
if(pos<=0 || pos>(llCount()+1))
	return;
if(head==NULL && pos>1)
	return;
	
	int i=1;
	PNODE newn=NULL;
	PNODE temp=head;
	newn=(PNODE)malloc(sizeof(NODE));
	if(newn==NULL)
	{
		return;
	}

	newn->data=data;
	newn->next=NULL;
	if(temp==NULL && pos==1)
	{
		temp=newn;
		newn->next=NULL;
	}
	else
	{
		while(i<pos-1 && temp->next!=NULL)
		{	
			temp=temp->next;
			i++;
		}
		newn->next=temp->next;
		temp->next=newn;
	}
}
////////////////////////////////////////////////////////////////////////////////////

void SinglyLinkedList::DisplayN(int no)
{
if(head==NULL || no<=0)
	return;
PNODE first=head;
	//traversing the whole linked list elements
	while(first!=NULL && no>0)
	{
		cout<<(first->data)<<endl;
		first=first->next;
		no--;
	}
}
/*////////////////////////////////////////////////////////////////////////////////
void SinglyLinkedList::DisplayReverse()
{
	PNODE first=head;
if(first==NULL)
	return;
	// recursive call to the function
		first=first->next;
		DisplayReverse();
		cout<<(first->data)<<endl;
}
*//////////////////////////////////////////////////////////////////////////
void SinglyLinkedList::DeleteFirst()
{
	PNODE temp=head;
	if(temp==NULL)
		return;
	head=temp->next;
	temp->next=NULL;
	delete(temp);
}
//////////////////////////////////////////////////////////////////////////
void SinglyLinkedList::DeleteLast()
{
	PNODE temp=head;
	PNODE temp2=NULL;
	if(temp==NULL)
		return;
	if(temp->next==NULL)
	{
		delete(temp);
		head=NULL;
	}
	else
	{
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		temp2=temp->next;
		temp->next=NULL;
		delete(temp2);
	}
}
///////////////////////////////////////////////////////////////////////////////
void SinglyLinkedList::DeleteAll()
{
	if(head==NULL)
		return;
	PNODE temp=head;
	delete(temp);
	head=NULL;
}
///////////////////////////////////////////////////////////////////////////////
void SinglyLinkedList::DeleteNode(int data)
{
	PNODE temp=head;
	PNODE temp2=head;
	if(head==NULL)
		return;
	while(temp->next!=NULL)
	{
		if(temp->data==data)
			break;
		temp2=temp;
		temp=temp->next;
	}
	if(temp->data==data)
	{
		temp2=temp->next;
		temp->next=NULL;
		delete(temp);
	}
}
extern "C"
{
	SinglyLinkedList* create()
	{
		return new SinglyLinkedList;
	}
	void destroy(SinglyLinkedList* p)
	{
		delete p;
	}
}


