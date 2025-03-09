#include "global.h"
#include <cstring>

int comparare_nume(student* s1, student* s2)
{
    if (strcmp(s1->getNume(), s2->getNume()) == 0)
        return 0;
    if (strcmp(s1->getNume(), s2->getNume()) < 0)
        return -1;
    return 1;



}

int comparare_nota_m(student* s1, student* s2)
{
    if (s1->medie_finala_m() == s2->medie_finala_m())
        return 0;
    if (s1->medie_finala_m() < s2->medie_finala_m())
        return -1;
    return 1;

}

int comparare_nota_e(student* s1, student* s2)
{
    if (s1->medie_finala_e() == s2->medie_finala_e())
        return 0;
    if (s1->medie_finala_e() < s2->medie_finala_e())
        return -1;
    return 1;
}

int comparare_nota_i(student* s1, student* s2)
{
    if (s1->medie_finala_i() == s2->medie_finala_i())
        return 0;
    if (s1->medie_finala_i() < s2->medie_finala_i())
        return -1;
    return 1;
}

int comparare_nota_finala(student* s1, student* s2)
{
    if (s1->medie_finala_m() + s1->medie_finala_e() + s1->medie_finala_i() == s2->medie_finala_m() + s2->medie_finala_e() + s2->medie_finala_i())
        return 0;
    if (s1->medie_finala_m() + s1->medie_finala_e() + s1->medie_finala_i() < s2->medie_finala_m() + s2->medie_finala_e() + s2->medie_finala_i())
        return -1;
    return 1;
}