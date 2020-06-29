/*
    Atividade Avaliativa 
    Sugestão para Megasena
    Quais o números menos sorteados por mês em cada ano
    Gabriel Fernandes Silva

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

void menosSorteadosPorMes() {
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
    int mes = 05;
    int mes_anterior = 0;
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
            if (field_count == 2) {
                mes_anterior = atoi(field);
                if (atoi(field) == mes) {
                    field_count++;

                    field = strtok_s(NULL, " /;\t\n", &next_token1);
                    while ((field_count > 2) && (field_count < 10)) {
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
                    printf("\t\t\nMes: %d\t\t\n\t", mes);
                    for (i = 1; i < 61; i++) {
                        if (vetorSorteados[i] < 6) {
                            printf_s("\t%d\n\t", i);
                        }
                    }
                    mes = mes_anterior;
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

int main(void) {
    setlocale(LC_ALL, "Portuguese");
    int menu;
    FILE* fp;

    errno_t err;

    err = fopen_s(&fp, "temp.csv", "r");

    //     = fopen_s("C:\Aula\Prova\temp.csv", "r");

    if (err != 0) {
        printf("Can't open file\n");
        return 0;
    }

    char buf[CHAR_MAX];
    int row_count = 0;
    int field_count = 0;
    char* next_token1 = NULL;
    int dia = 0;
    do
    {
        printf("Aperte 1 para mostrar os sorteios\n");
        printf("Aperte 2 para mostrar a função por ano\n");
        menu = _getch();
        system("CLS");
    } while ((menu < 49 || menu > 50));
    if (menu == 49)
    {
        while (fgets(buf, sizeof(buf), fp)) {
            field_count = 0;
            row_count++;

            if (row_count == 1) {
                continue;
            }

            char* field = strtok_s(buf, " /;\t\n", &next_token1);
            while (field) {
                if (field_count == 0) {
                    printf("Concurso:\t");
                }
                if (field_count == 1) {
                    printf("Dia:\t");
                    //dia = atoi(field);
                }
                if (field_count == 2) {
                    printf("Mes:\t");
                }
                if (field_count == 3) {
                    printf("Ano:\t");
                }
                if (field_count == 4) {
                    printf("Bola1:\t");
                }
                if (field_count == 5) {
                    printf("Bola2:\t");
                }
                if (field_count == 6) {
                    printf("Bola3:\t");
                }
                if (field_count == 7) {
                    printf("Bola4:\t");
                }
                if (field_count == 8) {
                    printf("Bola5:\t");
                }
                if (field_count == 9) {
                    printf("Bola6:\t");
                }


                printf("%s\n", field);
                //  printf("dia - int: %d \n\n", dia);
                field = strtok_s(NULL, " /;\t\n", &next_token1);

                field_count++;


            }
            printf("\n");
            // system("pause");
        }
    }
    else
    {
        // abrir funções;
        menosSorteadosPorMes();
    }

    fclose(fp);
    system("pause");

    return 0;
}