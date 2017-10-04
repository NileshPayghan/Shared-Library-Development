///////////////////////////////////////////////////////////////////////////////////////////////////////
//Name:
//Modified: 7-1-2017
//Author: Nilesh Payghan
//Input:
//output:
//Description:
////////////////////////////////////////////////////////////////////////////////////////////////////////


#include"header.h"
using namespace std;


addition::addition()
{
	x=20;
	y=10;
	add=0;
}
int addition::substraction()
{
	add=x-y;
	return add;
}
int addition::get_data()
{
	return add;
}
extern "C"
{
	addition* create()
	{
		return new addition;
	}
	void destroy(addition* p)
	{
		delete p;
	}
}
