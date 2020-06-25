/*

programador: winston sen lun fung

instituição de ensino: escola superior politécnica uninter

ide: visual studio

exemplo que le um arquivo.csv menor que 16 Kby em modo string 
e converte os campos da tabela em dados do tipo int para posterior uso

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void menosSorteadosAno(void);
extern void menosSorteados(void);

int main(void) {
    FILE* fp;

    errno_t err;

    err = fopen_s(&fp, "temp.csv", "r");

    if (err!=0) {
        printf("Can't open file\n");
        return 0;
    }

    char buf[16384];
    int row_count = 0;
    int field_count = 0;
    char* next_token1 = NULL;
    int dia = 0;

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

    fclose(fp);
    system("pause");

    return 0;
}