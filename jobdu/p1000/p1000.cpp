/******************************************************************************
Copyright (C), 2015, dploop
FileName: p1000.cpp
Author: dploop
Date: 2015/10/27
Description: http://ac.jobdu.com/problem.php?pid=1000
******************************************************************************/
#include <stdio.h>

int main()
{
	int a, b;
	for (;EOF!=scanf("%d%d",&a,&b);) {
		printf("%d\n", a + b);
	}
	return 0;
}
