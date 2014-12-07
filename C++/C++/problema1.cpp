#include<iostream>
#include<string>

using namespace std;

typedef struct examen {
	char *materie;
	int zi;
	int numar_studenti;
	int numar_credite;
	char stud[20][20];
}EX;

void write(EX inreg) {
	cout << " Examenul la materia " << inreg.materie << " se tine in ziua " << inreg.zi << " si are " << inreg.numar_credite << " credite sustinut de urmatorii studenti:" << inreg.stud << " \n";
	for (int i=0; i < inreg.numar_studenti; i++){
		cout << i + 1 << inreg.stud[i] << "\n";
	}
}

int credit(EX inreg) {
	return inreg.numar_credite * inreg.numar_studenti;
}

int main(){

	EX inreg1, inreg2;
	char s[20];
	
	/*inreg1.materie = (char*)malloc(sizeof(char));
	strcpy(inreg1.materie,"fizica");
	inreg1.zi = 3;
	inreg1.numar_credite = 5;
	inreg1.numar_studenti = 3;
	strcpy(inreg1.stud[0], " Adrian");
	strcpy(inreg1.stud[1], " Tudor");
	strcpy(inreg1.stud[2], " Alex");
	write(inreg1);
	*/

	cout << "Dati materia: ", cin.get(s,20);
	inreg2.materie = (char *)malloc(sizeof(char)*strlen(s));
	strcpy(inreg2.materie, s);

	cout << "Ziua examenului: "; cin >> inreg2.zi;
	cout << "Numarul de credite: "; cin >> inreg2.numar_credite;
	cout << "Numarul de studenti: "; cin >> inreg2.numar_studenti;
	cout << "Nume studenti: \n";
	for (int i = 0; i < inreg2.numar_studenti; i++){
		cin.get();
		cin.get(inreg2.stud[i], 20);

	}
	char aux[20];
	int i, j;
	for (i = 0; i < inreg2.numar_studenti - 1; i++){
		for (j = i + 1; j < inreg2.numar_studenti; j++)
			if (strcmp(inreg2.stud[i], inreg2.stud[j])>0){
				strcpy(aux, inreg2.stud[i]);
				strcpy(inreg2.stud[i], inreg2.stud[j]);
				strcpy(inreg2.stud[j], aux);
			}

	}
	write(inreg2);

	cout << "\n La materia " << inreg2.materie << " s-au acordat " << inreg2.numar_credite << " credite.\n";

	return 0;
}