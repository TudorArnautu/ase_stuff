#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>


typedef struct {
	int length;
	char *value;
	bool isNegative;
} BigNumber;

BigNumber buildNumber(char *);
void toString(BigNumber);


	BigNumber buildNumber(char *number) {

		BigNumber number1 = buildNumber("2461855\0");
		BigNumber number2 = buildNumber("81681530\0");

		int len;

		len = strlen(number);
		printf("strlen(number) : %d\n", len);

		strcmp(number1, number2);
}
	
	void toString(BigNumber number){
	
		if (number.isNegative){
			printf("-%s", number.value);
		}
		else{
			printf("%s", number.value);
		}
	}


	int main(){

		
	}











