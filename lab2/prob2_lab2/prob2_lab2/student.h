#pragma once
class student
{

    float note_m[10], note_e[10], note_i[10];
    char nume[20];
    int count_m, count_e, count_i;
public:
    void Init();
    void Add_note_m(float x);
    void Add_note_e(float x);
    void Add_note_i(float x);
    void setNume(char* nume);
    char* getNume();
    float medie_finala_m();
    float medie_finala_e();
    float medie_finala_i();

};

