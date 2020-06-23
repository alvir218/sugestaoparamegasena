/*

programadores:
allan stuart virmond
julho cesar radicheski da costa

professor: winston sen lun fung

instituição de ensino: escola superior politécnica uninter

ide: microsoft visual studio community 2019

algoritmo
encontra e ordena os numeros mais sorteados da mega sena
tendo um arquivo de uma planilha.csv como entrada

utilizacao:
use a função EncontrarOsNumerosMaisSorteados
passando o endereço 0 dos vetores 1 e 2 que armazenarão
1 - quantas vezes saiu cada número com 61 valores
e
2 - quais foram os mais sorteados também com 61 posições

o indice 0 de ambos os vetores armazenam por padrão o valor 0

exemplo:
EncontrarOsNumerosMaisSorteados(&QuantasVezesSaiu[0], &MaisSorteados[0]);

o tipo de dados do ponteiro para esse vetor na função está calibrado para o tipo unsigned int

o uso posterior desses dados pode ser por exemplo usado nos vetores
QuantasVezesSaiu[61]
MaisSorteados[61]

QuantasVezesSaiu[61] armazena quantas vezes saiu cada bola,
sendo o indice 0 ignorado tendo como padrão o número 0
o número do índice corresponde ao numero da bola sendo por exemplo:
QuantasVezesSaiu[26] tendo o valor de quantas vezes saiu a bola número 26.

MaisSorteados[61] armazena em ordem crescente do 1 para o 60 qual a bola mais sorteada
nesse caso o indice significa o rank da bola mais sorteada
onde MaisSorteados[1] contém o valor da bola com o maior numero de sorteios
e MaisSorteados[60] contém o valor da bola menos sorteada
por exemplo:
MaisSorteados[1] = 10;
significa que a bola mais sorteada foi a bola número 10
MaisSorteados[60] = 59;
significa que a bola menos sorteada foi a bola número 59


*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


unsigned int EncontrarOsNumerosMaisSorteados(unsigned int* pQuantasVezesSaiu, unsigned int* pMaisSorteados);
bool JaEstaNaListaMaisSorteados(unsigned int NumeroNaListaMaisSorteados, unsigned int* pMaisSorteados);



int main(void) {

    unsigned int QuantasVezesSaiu[61] = { 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0 };
    unsigned int MaisSorteados[61] = { 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0, 0 };

    EncontrarOsNumerosMaisSorteados(&QuantasVezesSaiu[0], &MaisSorteados[0]);



    printf("\n\n\n");
    system("pause");

    return 0;
}



unsigned int EncontrarOsNumerosMaisSorteados(unsigned int* pQuantasVezesSaiu, unsigned int* pMaisSorteados) {
    unsigned int Temporaria = 0;
    unsigned int QuantasBolasParesSairam = 0;
    unsigned int QuatasBolasImparesSairam = 0;

    FILE* pPlanilha;

    errno_t TesteDeErro;

    TesteDeErro = fopen_s(&pPlanilha, "mega_sena_2266.csv", "r");

    //     = fopen_s("C:\Aula\Prova\temp.csv", "r");

    if (TesteDeErro != 0) {
        printf("Erro: Nao foi possivel abrir o arquivo.\n");
        return 0;
    }

    char Buffer[10352];
    int LinhaDaPlanilha = 0;
    int ColunaDaPlanilha = 0;
    char* ProximaCelula = NULL;

    while (fgets(Buffer, sizeof(Buffer), pPlanilha)) {
        ColunaDaPlanilha = 0;
        LinhaDaPlanilha = LinhaDaPlanilha + 1;

        if (LinhaDaPlanilha == 1) {
            continue;
        }

        char* Celula = strtok_s(Buffer, " /;\t\n", &ProximaCelula);
        while (Celula) {

            //bola1
            if (ColunaDaPlanilha == 4) {

                Temporaria = atoi(Celula);

                pQuantasVezesSaiu[Temporaria] = pQuantasVezesSaiu[Temporaria] + 1;

                if (Temporaria % 2 == 0) {
                    QuantasBolasParesSairam = QuantasBolasParesSairam + 1;
                }
                else {
                    QuatasBolasImparesSairam = QuatasBolasImparesSairam + 1;
                }

            }

            //bola2
            if (ColunaDaPlanilha == 5) {

                Temporaria = atoi(Celula);

                pQuantasVezesSaiu[Temporaria] = pQuantasVezesSaiu[Temporaria] + 1;

                if (Temporaria % 2 == 0) {
                    QuantasBolasParesSairam = QuantasBolasParesSairam + 1;
                }
                else {
                    QuatasBolasImparesSairam = QuatasBolasImparesSairam + 1;
                }
            }

            //bola3
            if (ColunaDaPlanilha == 6) {

                Temporaria = atoi(Celula);

                pQuantasVezesSaiu[Temporaria] = pQuantasVezesSaiu[Temporaria] + 1;

                if (Temporaria % 2 == 0) {
                    QuantasBolasParesSairam = QuantasBolasParesSairam + 1;
                }
                else {
                    QuatasBolasImparesSairam = QuatasBolasImparesSairam + 1;
                }
            }

            //bola4
            if (ColunaDaPlanilha == 7) {

                Temporaria = atoi(Celula);

                pQuantasVezesSaiu[Temporaria] = pQuantasVezesSaiu[Temporaria] + 1;

                if (Temporaria % 2 == 0) {
                    QuantasBolasParesSairam = QuantasBolasParesSairam + 1;
                }
                else {
                    QuatasBolasImparesSairam = QuatasBolasImparesSairam + 1;
                }
            }

            //bola5
            if (ColunaDaPlanilha == 8) {

                Temporaria = atoi(Celula);

                pQuantasVezesSaiu[Temporaria] = pQuantasVezesSaiu[Temporaria] + 1;

                if (Temporaria % 2 == 0) {
                    QuantasBolasParesSairam = QuantasBolasParesSairam + 1;
                }
                else {
                    QuatasBolasImparesSairam = QuatasBolasImparesSairam + 1;
                }
            }

            //bola6
            if (ColunaDaPlanilha == 9) {

                Temporaria = atoi(Celula);

                pQuantasVezesSaiu[Temporaria] = pQuantasVezesSaiu[Temporaria] + 1;

                if (Temporaria % 2 == 0) {
                    QuantasBolasParesSairam = QuantasBolasParesSairam + 1;
                }
                else {
                    QuatasBolasImparesSairam = QuatasBolasImparesSairam + 1;
                }
            }

            Celula = strtok_s(NULL, " /;\t\n", &ProximaCelula);

            ColunaDaPlanilha = ColunaDaPlanilha + 1;

            //fim do loop celula (concurso)
        }

        //fim do loop fgets
    }

    unsigned int TemporarioMaiorNumeroDeVezesSorteado = 0;
    unsigned int IteracaoMaisSorteados = 1;
    unsigned int IteracaoQuantasVezesSaiu = 1;
    while (IteracaoMaisSorteados < 61) {

        TemporarioMaiorNumeroDeVezesSorteado = 0;

        IteracaoQuantasVezesSaiu = 1;

        while (IteracaoQuantasVezesSaiu < 61) {

            if (pQuantasVezesSaiu[IteracaoQuantasVezesSaiu] > TemporarioMaiorNumeroDeVezesSorteado && JaEstaNaListaMaisSorteados(IteracaoQuantasVezesSaiu, pMaisSorteados) == 0) { //&& nao estiver na lista de mais sorteados

                pMaisSorteados[IteracaoMaisSorteados] = IteracaoQuantasVezesSaiu;
                TemporarioMaiorNumeroDeVezesSorteado = pQuantasVezesSaiu[IteracaoQuantasVezesSaiu];
            }

            IteracaoQuantasVezesSaiu = IteracaoQuantasVezesSaiu + 1;

            //fim do loop ordenar a lista crescentemente auxiliar
        }

        IteracaoMaisSorteados = IteracaoMaisSorteados + 1;
        //fim do loop ordenar a lista crescentemente
    }

    printf("\n\nVeja o numero de vezes que saiu cada bola:\n\n");

    for (int iteracao = 1; iteracao < 61; iteracao = iteracao + 1) {
        printf("%i : %i \n", iteracao, pQuantasVezesSaiu[iteracao]);
    }

    printf("\n\n");

    printf("\n\nVeja quais as bolas mais sorteadas:\n\n");

    for (int iteracao = 1; iteracao < 61; iteracao = iteracao + 1) {
        printf("%i : %i \n", iteracao, pMaisSorteados[iteracao]);
    }

    printf("\n\nSairam %i bolas pares.", QuantasBolasParesSairam);

    printf("\n\nSairam %i bolas impares", QuatasBolasImparesSairam);

    if (QuantasBolasParesSairam > QuatasBolasImparesSairam) {
        printf("\n\nSairam mais bolas pares.\n\n");
    }
    else if (QuatasBolasImparesSairam > QuantasBolasParesSairam) {
        printf("\n\nSairam mais bolas impares.\n\n");
    }
    else if (QuatasBolasImparesSairam == QuantasBolasParesSairam) {
        printf("\n\nO numero de bolas parares que sairam e igual ao numero de bolas impares\n\n");
    }

    return 0;

    //fim da funcao EncontrarOsNumerosMaisSorteados
}



bool JaEstaNaListaMaisSorteados(unsigned int NumeroNaListaMaisSorteados, unsigned int* pMaisSorteados) {
    bool JaFoiAdicionadoNaLista = 0;
    for (int iteracao = 0; iteracao < 61; iteracao = iteracao + 1) {
        if (pMaisSorteados[iteracao] == NumeroNaListaMaisSorteados) {
            JaFoiAdicionadoNaLista = 1;
        }
    }
    if (JaFoiAdicionadoNaLista == 1) {
        return 1;
    }
    else {
        return 0;
    }

    //fim da funcao JaEstaNaListaMaisSorteados
}