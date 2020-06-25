#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

void menosSorteadosAno() {
    FILE* fp;

    errno_t err;

    err = fopen_s(&fp, "temp.csv", "r");

    if (err != 0) {
        printf("Can't open file\n");
        return;
    }
    char buf[CHAR_MAX];
    int row_count = 0;
    int field_count = 0;
    char* next_token1 = NULL;
    int vetorSorteados[61], i, j;
    int ano = 2020;
    int anoAnterior = 0;
    int position = 0;
    int menor[61];

    for (i = 0; i < 61; i++)
    {
        vetorSorteados[i] = 0;
    }

    while (fgets(buf, sizeof(buf), fp)) {
        field_count = 0;
        row_count++;

        if (row_count == 1) {
            continue;
        }

        char* field = strtok_s(buf, " /;\t\n", &next_token1);
        while (field)
        {
            if (field_count == 3) {
                anoAnterior = atoi(field);
                if (atoi(field) == ano) {
                    field_count++;

                    field = strtok_s(NULL, " /;\t\n", &next_token1);
                    while ((field_count > 3) && (field_count < 10)) {
                        position = atoi(field);
                        vetorSorteados[position] = vetorSorteados[position] + 1;

                        if (field_count < 9) {
                            field = strtok_s(NULL, " /;\t\n", &next_token1);
                            field_count++;
                        }
                        else {
                            field_count = 0;
                            field = strtok_s(NULL, " /;\t\n", &next_token1);

                            break;
                        }
                    }
                }
                else {
                    printf("\t\t\nAno: %d\t\t\n\t", ano);
                    for (i = 1; i < 61; i++) {
                        if (vetorSorteados[i] < 6) {
                            printf_s("\t%d\n\t", i);
                        }
                    }
                    ano = anoAnterior;
                    for (i = 0; i < 61; i++) {
                        vetorSorteados[i] = 0;
                    }
                }
            }
            field = strtok_s(NULL, " /;\t\n", &next_token1);
            field_count++;
        }
    }
    fclose(fp);
    system("Pause");
}

void menosSorteados()
{
    FILE* fp;

    errno_t err;

    err = fopen_s(&fp, "temp.csv", "r");

    if (err != 0) {
        printf("Can't open file\n");
        return;
    }
    char buf[CHAR_MAX];
    int row_count = 0;
    int field_count = 0;
    char* next_token1 = NULL;
    int vetorSorteados[61], i;
    int ano = 1996;
    int position = 0;


    for (i = 0; i < 61; i++)
    {
        vetorSorteados[i] = 0;
    }

    while (fgets(buf, sizeof(buf), fp)) {
        field_count = 0;
        row_count++;

        if (row_count == 1) {
            continue;
        }

        char* field = strtok_s(buf, " /;\t\n", &next_token1);
        while (field)
        {
            if ((field_count > 3) && (field_count < 10))
            {
                position = atoi(field);
                if (position > 0)
                {
                    vetorSorteados[position] = vetorSorteados[position] + 1;
                }
            }
            field = strtok_s(NULL, " /;\t\n", &next_token1);
            field_count++;
        }
    }
    fclose(fp);

    for (i = 1; i < 61; i++) {
        if (vetorSorteados[i] < 200) {
            printf_s("%d\n", i);
        }
    }
    system("Pause");
}