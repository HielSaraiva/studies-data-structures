// Fila Simplesmente Encadeada:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s_dados
{
   char matricula[30]; // chave
   char nome[255];
   char fone[15];
   float notas[2];
};

struct no
{
   struct s_dados dados;
   struct no *prox;
};

// Prototipos de funcoes:
void inserir(struct no **, struct s_dados);
int remover(struct no **);
int espiar(struct no *);
int listarTodos(struct no *);
int estaVazia(struct no *);
int tamanho(struct no *);
int limpar(struct no **);

int main()
{
   // Iniciando fila:
   struct no *fila = NULL;

   // Iniciando dados1:
   struct s_dados dados1;
   strcpy(dados1.nome, "Hiel Saraiva");
   strcpy(dados1.matricula, "202301");
   strcpy(dados1.fone, "85996852901");
   dados1.notas[0] = 7.8f;
   dados1.notas[1] = 9.6f;

   // Iniciando dados2:
   struct s_dados dados2;
   strcpy(dados2.nome, "Geni Saraiva");
   strcpy(dados2.matricula, "202302");
   strcpy(dados2.fone, "85988441830");
   dados2.notas[0] = 10.0f;
   dados2.notas[1] = 8.5f;

   // Iniciando dados3:
   struct s_dados dados3;
   strcpy(dados3.nome, "Rodrigo");
   strcpy(dados3.matricula, "202303");
   strcpy(dados3.fone, "85988442342");
   dados3.notas[0] = 1.0f;
   dados3.notas[1] = 3.5f;

   // Iniciando dados4:
   struct s_dados dados4;
   strcpy(dados4.nome, "Conrado");
   strcpy(dados4.matricula, "202304");
   strcpy(dados4.fone, "85988442233");
   dados4.notas[0] = 5.0f;
   dados4.notas[1] = 4.5f;

   // Iniciando dados5:
   struct s_dados dados5;
   strcpy(dados5.nome, "Alanis");
   strcpy(dados5.matricula, "202305");
   strcpy(dados5.fone, "85988442233");
   dados5.notas[0] = 5.0f;
   dados5.notas[1] = 4.5f;

   // Iniciando dados6:
   struct s_dados dados6;
   strcpy(dados6.nome, "Wellington");
   strcpy(dados6.matricula, "202306");
   strcpy(dados6.fone, "85988442233");
   dados6.notas[0] = 5.0f;
   dados6.notas[1] = 4.5f;

   // Iniciando dados7:
   struct s_dados dados7;
   strcpy(dados7.nome, "Hala");
   strcpy(dados7.matricula, "202307");
   strcpy(dados7.fone, "85988442233");
   dados7.notas[0] = 5.0f;
   dados7.notas[1] = 4.5f;

   // Testando funcoes:
   // printf("%d", listarTodos(fila));
   printf("%d\n", estaVazia(fila));
   printf("%d\n", tamanho(fila));

   inserir(&fila, dados1);
   inserir(&fila, dados2);
   inserir(&fila, dados3);
   inserir(&fila, dados4);
   listarTodos(fila);

   printf("%d\n", estaVazia(fila));
   printf("%d\n", tamanho(fila));

   remover(&fila);
   listarTodos(fila);

   printf("%d\n", estaVazia(fila));
   printf("%d\n", tamanho(fila));

   espiar(fila);

   limpar(&fila);

   printf("%d\n", estaVazia(fila));
   printf("%d\n", tamanho(fila));

   inserir(&fila, dados1);
   inserir(&fila, dados2);

   espiar(fila);
   return 0;
}

void inserir(struct no **fila, struct s_dados dados)
{
   if (*fila == NULL)
   {
      // Se nao houver nenhum no:
      struct no *aux = malloc(sizeof(struct no));
      aux->prox = NULL;
      aux->dados = dados;
      *fila = aux;
   }
   else
   {
      // Se ja houver algum no:
      struct no *aux1 = malloc(sizeof(struct no));
      aux1->prox = NULL;
      aux1->dados = dados;

      // aux2 percorre a lista ate o ultimo dado:
      struct no *aux2 = *fila;
      while (aux2->prox != NULL)
      {
         aux2 = aux2->prox;
      }
      (aux2->prox) = aux1;
   }
}

int remover(struct no **fila)
{
   // Se nao houver o que remover, retorna -1
   // Se houver, retorna 0
   if (*fila != NULL)
   {
      struct no *aux = *fila;
      *fila = (*fila)->prox;
      free(aux);
      return 0;
   }
   return -1;
}

int espiar(struct no *fila)
{
   // Se nao houver o que espiar, retorna -1
   // Se houver, retorna 0
   if (fila != NULL)
   {
      struct no *aux = fila;
      printf("\n%s\n", aux->dados.nome);
      printf("%s\n", aux->dados.matricula);
      printf("%s\n", aux->dados.fone);
      printf("%.2f %.2f\n", aux->dados.notas[0], aux->dados.notas[1]);
      return 0;
   }
   return -1;
}

int listarTodos(struct no *fila)
{
   // Se nao houver o que listar, retorna -1
   // Se houver, retorna 0
   if (fila != NULL)
   {
      struct no *aux = fila;
      while (aux != NULL)
      {
         printf("\n%s\n", aux->dados.nome);
         printf("%s\n", aux->dados.matricula);
         printf("%s\n", aux->dados.fone);
         printf("%.2f %.2f\n", aux->dados.notas[0], aux->dados.notas[1]);
         aux = aux->prox;
      }
      return 0;
   }
   return -1;
}

int estaVazia(struct no *fila)
{
   // A funcao retornara -1 se nao estiver vazia e 0 caso esteja vazia
   if (fila == NULL)
   {
      return 0;
   }
   return -1;
}

int tamanho(struct no *fila)
{
   int cont = 0;
   while (fila != NULL)
   {
      ++cont;
      fila = fila->prox;
   }
   return cont;
}

int limpar(struct no **fila)
{
   // A funcao retornara -1 se a pilha ja estiver vazia, e 0 quando for totalmente limpa
   if ((*fila) != NULL)
   {
      while ((*fila) != NULL)
      {
         remover(fila);
      }
      return 0;
   }
   return -1;
}