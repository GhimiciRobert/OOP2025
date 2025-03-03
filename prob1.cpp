#include <stdio.h>
int Atoi(const char* str)
{
    int sign = 1, num = 0, i = 0;

    while (str[i] == ' ')
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        num = num * 10 + (str[i] - '0');
        i++;
    }
    return sign * num;
}
int main()
{
    FILE* file;
    errno_t err = fopen_s(&file, "in.txt", "r");
    if (err != 0) {
        printf("Eroare la deschiderea fișierului!\n");
        return 1;
    }
    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        int sum = 0, num;
        char* ptr = line;
        while (*ptr)
        {
            if (*ptr == '-' || *ptr == '+' || (*ptr >= '0' && *ptr <= '9'))
            {
                num = Atoi(ptr);
                sum = sum + num;
                while (*ptr >= '0' && *ptr <= '9')
                    ptr++;
            }
            else
                ptr++;
        }
        printf("Suma pe aceasta linie este: %d\n", sum);
    }

    fclose(file);
    return 0;

}