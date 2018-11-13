#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "funcoes.h"

int main(){
    int i;
    FILE *arq_final,*arq_ini;
    char *sino,*texto,*text_final,c;
    lista *sinonimos;

    sino=(char*)malloc(100 *sizeof(char));
    texto=(char*)malloc(100 *sizeof(char));
    text_final=(char*)malloc(100 *sizeof(char));
    printf("DIGITE O DIRETORIO DO SEU ARQUIVO DE SINONIMOS (JÁ HÁ UM ARQUIVO CHAMADO TESTE \"sinonimos.csv\"):\n");
    scanf("%[^\n]s", sino);
    setbuf(stdin, NULL);
    sinonimos=addSin(sino);
    printf("DIGITE O DIRETORIO DO SEU TEXTO (JÁ HÁ UM ARQUIVO TESTE CHAMADO \"text.txt\"):\n");
    scanf("%[^\n]s", texto);
    setbuf(stdin, NULL);
    printf("DIGITE O NOME DO ARQUIVO FINAL:\n");
    scanf("%[^\n]s", text_final);
    setbuf(stdin, NULL);
    subText(texto,text_final, sinonimos);
    arq_ini=fopen(texto,"r");
    arq_final=fopen(text_final,"r");

    while((c=fgetc(arq_ini))!=EOF){
        printf("%c",c);
    }
    printf("\n");
    printf("----------------------------------------------------------------------------------------\n");
    printf("-----------------------------------TEXTO MODIFICADO-------------------------------------\n");
    printf("----------------------------------------------------------------------------------------\n");
    while((c=fgetc(arq_final))!=EOF){
        printf("%c",c);
    }
    fclose(arq_final);
    fclose(arq_ini);
}