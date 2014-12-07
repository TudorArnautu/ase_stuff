#include<iostream>
using namespace std;

typedef struct facultate{
	char *materii;
	int numar_materii;
	char profesori[20][20];
	char studenti[20][20];

}EX;

void write(EX add){
	cout << "CSIE are " << add.numar_materii << ", se vor da examene la materiile: " << add.materii << " cu urmatorii profesori coordonatori: " << add.profesori << "\n";
	cout << "La examen se vor prezenta urmatorii studenti: " << add.studenti << "\n";
	cout << "Studentii care nu au dreptul sa intre in examen sunt urmatorii: " << add.studenti <<
}
