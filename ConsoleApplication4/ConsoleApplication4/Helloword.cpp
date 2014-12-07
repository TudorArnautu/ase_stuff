# include <stdio.h>
# include <stdlib.h>
# include <conio.h>

void main(void)
{
	char student[15];
	printf_s("VA RUGAM INTRODUCETI NUMELE DUMNEAVOSTRA:");
	gets_s(student);
	printf_s(" \n Felicitari %s pentru primul program in C++ \n",student);
	_getch();
}