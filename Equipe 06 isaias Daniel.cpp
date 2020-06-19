
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

void jogosanual()
{
    FILE* fp;

    errno_t err;

    err = fopen_s(&fp, "temp.csv", "r");

    //     = fopen_s("C:\Aula\Prova\temp.csv", "r");

    if (err != 0) {
        printf("Can't open file\n");
        return;
    }
    char buf[CHAR_MAX];
    int row_count = 0;
    int field_count = 0;
    char* next_token1 = NULL;
    int ano = 0;
    int vetor[60], i, j, maior[6], posição, vetormaior[60];
    for (i = 0; i < 60; i++)
    {
        vetor[i] = 0;
        vetormaior[i] = 0;
        if (i < 6)
        {
            maior[i] = 0;
        }
    }
    ano = 2020;
    while (fgets(buf, sizeof(buf), fp)) {
        field_count = 0;
        row_count++;

        if (row_count == 1) {
            continue;
        }

        char* field = strtok_s(buf, " /;\t\n", &next_token1);
        while (field)
        {
            if (field_count == 3)
            {
                if (!(atof(field) == ano))
                {
                    for (i = 0; i < 60; i++)
                    {
                        for (j = 0; j < 6; j++)
                        {
                            if (vetor[i] > maior[j])
                            {
                                maior[j] = i;
                                break;
                            }
                        }
                    }
                    printf("ANO: %d\n", ano);
                    for (i = 0; i < 6; i++)
                    {
                        printf("BOLA %d : %d\n", i + 1, maior[i]);
                    }
                    printf("\n\n");
                    for (i = 0; i < 60; i++)
                    {
                        vetor[i] = 0;
                        if (i < 6)
                        {
                            maior[i] = 0;
                        }
                    }
                    ano--;
                }
            }
            if ((field_count > 3) && (field_count < 10))
            {
                posição = atoi(field);
                if (posição > 0)
                {
                    vetor[posição - 1] ++;
                    vetormaior[posição - 1] ++;
                }
            }
            field = strtok_s(NULL, " /;\t\n", &next_token1);
            field_count++;
        }
        // system("pause");
    }
    system("Pause");
    printf("---------- AGORA ANALISE COM CAUTELA A QUANTIDADE DE CADA BOLA DE 1996 ATÉ 2020 ---------- \n");
    for (i = 0; i < 60; i++)
    {
        printf("BOLA %.2d FOI RETIRADA %d VEZES\n", i + 1, vetormaior[i]);
    }
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
        jogosanual();
    }

    fclose(fp);
    system("pause");

    return 0;
}