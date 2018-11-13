#include "funcoes.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

lista *createlista(){
    lista *l;
    l=(lista*)malloc(sizeof(lista));
    if(l!=NULL){
        l->head=NULL;
        l->last=NULL;
        return l;
    }
    return NULL;
}

node *createNode(){
    node *no;
    no=(node*)malloc(sizeof(node));
    if(no!=NULL){
        no->prev=NULL;
        no->next=NULL;
        no->palavra=NULL;
        no->sin=createlista();
        no->rep=0;
        return no;
    }
    return NULL;
}

void addPalavra(node *no,char *s){
    if(no!=NULL && s!=NULL){
        int tam;
        tam=strlen(s)+1;
        no->palavra=(char*)malloc(tam  * sizeof(char));
        strcpy(no->palavra,s);
    }
}

int addlista(lista *l, char *c){
    if(l!=NULL && c!=NULL){
        node *no;
        no=createNode();
        addPalavra(no,c);
        if(l->head==NULL){
            l->head=no;
            l->last=no;
        }else{
            no->prev=l->last;
            l->last->next=no;
            l->last=no;
        }
        return 1;
    }
    return 0;
}

node *compareWords(lista *l, char *c){
    if(l!=NULL && c!=NULL){
        node *aux;
        aux=l->head;
        while(aux!=NULL){
            if(strcmp(aux->palavra,c)==0){
                return aux;
            }
            aux=aux->next;
        }
        return NULL;
    }
}
int removelista(lista *l, char *c){
    if(l!=NULL && c!=NULL){
        node *aux;
        aux=compareWords(l,c);
        if(aux!=NULL){
            if(aux->prev==NULL){
                aux->next->prev=NULL;
                l->head=l->head->next;
            }else if(aux->next==NULL){
                aux->prev->next=NULL;
                l->last=l->last->prev;
            }else{
                aux->prev->next=aux->next;
                aux->next->prev=aux->prev;
            }
            return 1;
        }
    }
    return 0;
}

int countLine( char *n_arq){
    FILE *f;
    f=fopen(n_arq,"r");
    char c;
    int count=0;

    while((c=fgetc(f))!=EOF){
        if(c=='\n')
            count++;
    }
    fclose(f);
    return count;
}

lista *addSin(char *n_arq){
    FILE *f;
    f=fopen(n_arq,"r");
    if(f==NULL){
        printf("AQRUIVO INEXISTENTE \n");
        return NULL;
    }
    char *buffer;
    //buffer=(char*)malloc(500*sizeof(char));
    char *an;

    int lines,i;

    lista *l;

    l=createlista();
    an=NULL;
    lines=countLine(n_arq);

    for(i=0;i<=lines;i++){
        buffer=(char*)malloc(500*sizeof(char));
        fgets(buffer,500,f);

        an=strstr(buffer,";");
        *an='\0';
        addlista(l,buffer);
        buffer=an+1;

        an=strstr(buffer,";");
        while(an!=NULL){
            *an='\0';
            addlista(l->last->sin,buffer);
            buffer=an +1;
            an=strstr(buffer,";");
        }

    }
    fclose(f);
    return l;
}

int countCarct( char *n_arq){
    FILE *f;
    f=fopen(n_arq,"r");
    char c;
    int count=0;

    while((c=fgetc(f))!=EOF){

            count++;
    }
    fclose(f);
    return count;
}

void countRep(lista *l){
    if(l!=NULL){
        char *aux1,*aux2;
        node *word, *sin, *runL;
        aux1=(char*)malloc(50*sizeof(char));
        aux2=(char*)malloc(50*sizeof(char));
        word=l->head;
        runL=l->head;

        while(word!=NULL){
            sin=l->head->sin->head;
            while(sin!=NULL){
                if(strcmp(word->palavra,sin->palavra)==0){
                    word->rep++;
                    sin->rep++;
                }
                sin=sin->next;
                if(sin== NULL && word!=NULL){
                    runL=runL->next;
                    if(runL!=NULL)
                        sin=runL->sin->head;
                }
            }
            word=word->next;
            runL=l->head;
        }
    }
}




node *seachRare(node *no){
    if(no!=NULL){
        node *aux,*rara;
        aux=no->sin->head;
        rara=aux;
        while(aux!=NULL){
            if(aux->rep<rara->rep){
                rara=aux;
            }
            aux=aux->next;
        }
        return rara;
    }
}

void subText(char *text,char *text_final,lista *l){
    if(l!=NULL && text!=NULL){
        node *aux,*aux_sin;
        aux=l->head;
        FILE *texto, *textoF;
        texto=fopen(text,"r");
        if(text==NULL){
            printf("AQRUIVO INEXISTENTE \n");

        }
        textoF=fopen(text_final,"a");
        int tam;
        char *buffer1,*buffer2, *an, *buffer_aux;
        tam=countCarct(text) +500;
        buffer1=(char*)malloc(tam*sizeof(char));
        buffer2=(char*)malloc(tam*sizeof(char));
        int tam2;
        tam2=countLine(text);
        int i;
        for(i=0;i<=tam2;i++){
            fgets(buffer1,tam,texto);
            aux=l->head;
            while(aux!=NULL){
                    buffer_aux=(char*)malloc(tam*sizeof(char));
                    an=strstr(buffer1,aux->palavra);

                while(an!=NULL){
                    *an='\0';
                    aux_sin=seachRare(aux);
                    aux_sin->rep++;
                    buffer_aux=an+ strlen(aux->palavra);
                    strcpy(buffer2,buffer_aux);
                    strcat(buffer1,aux_sin->palavra);
                    strcat(buffer1,buffer2);
                    an=strstr(buffer1,aux->palavra);
                }
                aux=aux->next;
            }
            //printf("%s",buffer1);
           // printf("\n");
            fprintf(textoF,"%s",buffer1);
        }
        fclose(texto);
        fclose(textoF);
    }

}