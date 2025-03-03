#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char s[101], * p, v[101][101], t[101];

int cnt = 0;
int LungimeCuvant(char* str) {
    int lg = 0, i = 0;
    while (str[i] != '\0' && str[i] != ' ' && isalpha(str[i])) {
        lg++;
        i++;
    }
    return lg;
}

int main() {
    int k = 0;


    fgets(s, 101, stdin);



    p = strtok(s, " ");
    while (p && k < 101) {
        strcpy(v[k++], p);
    }



    bool ok;
    do {
        ok = 1;
        for (int i = 0; i < k - 1; i++) {
            if (LungimeCuvant(v[i]) < LungimeCuvant(v[i + 1]) ||
                (LungimeCuvant(v[i]) == LungimeCuvant(v[i + 1]) && strcmp(v[i], v[i + 1]) < 0)) {

                strcpy(t, v[i]);
                strcpy(v[i], v[i + 1]);
                strcpy(v[i + 1], t);
                ok = 0;
            }
        }
    } while (!ok);


    for (int i = 0; i < k; i++) {
        printf("%s\n", v[i]);
    }

    return 0;
}