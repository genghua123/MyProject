#include<stdio.h>

typedef struct _dates
{
	int years, month, day;

}dates;

typedef struct _order
{
	char num[11];
	dates date;
	int amount;
}order;