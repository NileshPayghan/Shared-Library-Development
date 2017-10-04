///////////////////////////////////////////////////////////////////////////////////////////////////////
//Name:
//Modified:2017
//Author: Nilesh Payghan
//Input:
//output:
//Description:
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<dlfcn.h>
#include<stdlib.h>
#include"header.h"
using namespace std;

int main()
{

	void *p=NULL;
	addition* ptr=NULL;
	addition*(*fp1)()=NULL;
	void(*fp2)(addition*)=NULL;

	p=dlopen("/home/nilesh/Desktop/Projects/data structures shared Library Development/basic addition/myclass.so",RTLD_LAZY);
	if(!p)
	{
		cout<<"unable to load Library";
		return -1;
	}
	fp1=(addition*(*)())dlsym(p,"create");
	fp2=(void(*)(addition*))dlsym(p,"destroy");
	ptr=fp1();

	int sub=ptr->substraction();
	cout<<"substraction is"<<sub;
	fp2(ptr);
	dlclose(p);

	return 0;
}
