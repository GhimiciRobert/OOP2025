#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "student.h"
#include "global.h"
using namespace std;
float nota_matematica, nota_engleza, nota_istorie;
float nota_matematica_2, nota_engleza_2, nota_istorie_2;
int main()
{
    student s1;
    student s2;

    s1.setNume((char*)"Andrei");
    s1.Init();
    s1.Add_note_m(10);
    s1.Add_note_m(10);
    s1.Add_note_m(10);
    s1.Add_note_m(10);
    nota_matematica = s1.medie_finala_m();

    s1.Add_note_e(10);
    s1.Add_note_e(10);
    s1.Add_note_e(10);
    nota_engleza = s1.medie_finala_e();

    s1.Add_note_i(10);
    s1.Add_note_i(10);
    s1.Add_note_i(10);
    nota_istorie = s1.medie_finala_i();

    s2.setNume((char*)"Robert");
    s2.Init();
    s2.Add_note_m(6);
    s2.Add_note_m(4);
    s2.Add_note_m(7);
    s2.Add_note_m(2);
    nota_matematica_2 = s2.medie_finala_m();

    s2.Add_note_e(1);
    s2.Add_note_e(2);
    s2.Add_note_e(7);
    nota_engleza_2 = s2.medie_finala_e();

    s2.Add_note_i(4);
    s2.Add_note_i(4);
    s2.Add_note_i(4);
    s2.Add_note_i(2);
    nota_istorie_2 = s2.medie_finala_i();

    printf("F1; nume: %s | media matematica pentru primul student: %f\n", s1.getNume(), nota_matematica);
    printf("F1; nume: %s | media limba engleza pentru primul student: %f\n", s1.getNume(), nota_engleza);
    printf("F1; nume: %s | media istorie pentru primul student: %f\n", s1.getNume(), nota_istorie);

    printf("\n");

    printf("F1; nume: %s | media matematica pentru primul student: %f\n", s2.getNume(), nota_matematica_2);
    printf("F1; nume: %s | media limba engleza pentru primul student: %f\n", s2.getNume(), nota_engleza_2);
    printf("F1; nume: %s | media istorie pentru primul student: %f\n", s2.getNume(), nota_istorie_2);

    printf("\n");

    printf("Compararea celor 2 studenti dupa nume: %d\n", comparare_nume(&s1, &s2));
    printf("Compararea celor 2 studenti dupa media la matematica: %d\n", comparare_nota_m(&s1, &s2));
    printf("Compararea celor 2 studenti dupa media la limba engleza: %d\n", comparare_nota_e(&s1, &s2));
    printf("Compararea celor 2 studenti dupa media la istorie: %d\n", comparare_nota_i(&s1, &s2));
    printf("Compararea celor 2 studenti dupa media generala: %d\n", comparare_nota_finala(&s1, &s2));


    return 0;


}