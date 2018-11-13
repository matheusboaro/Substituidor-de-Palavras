#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

typedef struct _node_{
    char *palavra;//palavra principal
    struct _node_ *next;//link para uma proxima palavra principal;
    struct _node_ *prev;//link para uma palavra principal anterior;
    struct _lista_ *sin;//lista de sinonimos de uma palavra principar
    int rep;//repetições dessa palavra pela lista;
}node;

typedef struct _lista_{
    node *head;//cabeça da lista;
    node *last;//final da lista
}lista;

lista *createlista();//@função de criar uma lista duplamente encadeada;
node *createNode();//função de criar um no;
void addPalavra(node *no,char *s);//função de adicionar uma palavra nesse nó;
/*parametros:
  @node * no;
  @char * s;
  A função adiciona em um nó já criado o dado passado (char *);
  */
int addlista(lista *l, char *c);//função de adionar uma palavra em uma lista;
/*parametros:
  @lista * l;
  @char * c;
  A função adiciona em uma lista já criada o dado passado (char *);
  */
node *compareWords(lista *l, char *c);//função de busca em uma lista;
/*parametros:
  @lista * l;
  @char * c;
  A função busca em uma lista já criada o dado passado (char*);
  */
int removelista(lista *l, char *c);//remoção da lista por dado;
/*parametros:
  @lista * l;
  @char * c;
  A função busca em uma lista já criada e remove o dado passado,caso ele exista (char*);
  */
int countLine( char *n_arq);//contar as linhas de uma aquivo;
/*parametros:
  @FILE *n_arq;
  A função conta as linhas escritas de um arquivo (FILE*) com o nome passado por parametro (char*);
  */
lista *addSin(char *n_arq);//adicionar um arquivo de sinonimos em uma lsita;
/*parametros:
  @FILE *n_arq;
  *Retorno:
  @lsita*;
  A função criar e retorna uma lista, adicionando nela os dados de um arquivo .csv já existente e informado pelo usuario;
  */
int countCarct( char *n_arq);//contar caracteres de um arquivo;
/*parametros:
  @FILE *n_arq;
  *Retorno:
  @int;
  A função conta os caracteres de um arquivo já existente e informado e retorna para o usuario;
  */
void countRep(lista *l);//contar a reptição de sinonimos dentro de uma lista de sinonimos;
/*parametros:
  @lsita *l;
  *Retorno:
  @void
  A função procura as repetições entre palavras principais dentro da lista e atualiza o contador de repetições dessa determinada palavra;
  */
node *seachRare(node *no);//procurar pelo sinomo menos repetido;
/*parametros:
  @node *no;
  *Retorno:
  @node *;
  A função procura o sinonimo menos reptido de uma palavra principal e retorna o seu no em uma lista;
  */
void subText(char *text,char *text_final,lista *l);//substituir em um texto os sinomos cadastrados;
/*parametros:
  @char* text;
  @char *text_final;
  @lista *l;
  *Retorno:
  @void;
  A função procura o sinonimo menos reptido de uma palavra principal e retorna o seu no em uma lista;
  */

#endif // FUNCOES_H_INCLUDED
