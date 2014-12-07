//crearea si popularea unui fisier

#include<stdio.h>
//creez tipul fis_stud/student
typedef struct stud{
	int nr_mat;
	char nume[30];
	int an, grupa;
	struct note_stud{ int prog, mate, sport, stat, bd, scn; }nota;
}student;

void main()
{
	//(f=nume intern al fisierului)
	FILE* f;//creaza fisierul "f"(f este un fisier(pointer) de tip FILE def in stdio.h)
	student x;//creaza o data "x" de tip "STUDENT" (x va fi un articol al fisierului f)
	char fis[20];//vector cu maxim 20 de elemente de tip char(numele extern al fisierului)

	//operatii initiale 
	printf("Nume fisier: ");
	//introduc in mem numele extern al fisierului
	gets(fis);
	//spre deosebire de scanf("%s",&fis) gets(fis) poate sa contina si spatii

	//deschid si asignez pointerului f ce indica spre zona de mem la care se afla un fisier de tip FILE
	f = fopen(fis, "wb");//fis=nume extern //wb=modul de deschidere(write binary)

	//citire primul articol din fisierul conducator
	printf("Nr matricol: ");
	scanf("%d", &x.nr_mat);

	while (!feof(stdin))
	{
		printf("nume articol: ");
		gets(x.nume);//nume este un camp al articolului x de tip student
		printf("An: ");
		scanf("%d", &x.an);//an este un camp al articolului x de tip student
		printf("grupa: ");
		scanf("%d", &x.grupa);
		printf("nota probabilitati: ");
		scanf("%d", &x.nota.mate);
		printf("nota programare: ");
		scanf("%d", &x.nota.prog);
		printf("nota statistica: ");
		scanf("%d", &x.nota.stat);
		printf("nota sport: ");
		scanf("%d", &x.nota.sport);
		printf("nota bd: ");
		scanf("%d", &x.nota.bd);
		printf("nota scn: ");
		scanf("%d", &x.nota.scn);

		//scrie in fisierul f, incepand cu pozitia curenta, un nr de 1 articole, aflate la adresa &x, fiecare de dimensiuni sizeof()
		fwrite(&x, sizeof(student), 1, f);

		//citire articol urmator din fisierul coducator
		printf("nr matricol sau ctrl+z");
		scanf("%d", &x.nr_mat);
	}
	//operatii finale
	fclose(f);

}