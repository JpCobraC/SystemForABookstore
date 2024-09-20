#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct livro {
  int code;
  char title[30];
  char autor[30];
  char style[30];
  float price;
};

int main() {
  struct livro vetLivros[50];
  int i, pos = 0, cont = 0;
  char opt, opt1, busca[30];
  float soma;
  
  do {
    printf("(a) - Incluir um livro\n");
    printf("(b) - Listar o titulo de todos os livros\n");
    printf("(c) - Buscar por autor\n");
    printf("(d) - Buscar por titulo\n");
    printf("(e) - Buscar por estilo\n");
    printf("(f) - Média dos preços\n");
    printf("(g) - Sair\n");
  
    printf("Informe a opção: ");
    scanf(" %c", &opt);
  
   switch (opt) {
    case 'a':
     do {
      if (pos < 50) {
        printf("Insira o código do livro: ");
        scanf("%d", &vetLivros[pos].code);

        printf("Insira o título do livro: ");
        scanf(" %[^\n]s", &vetLivros[pos].title);

        printf("Insira o autor do livro: ");
        scanf(" %[^\n]s", &vetLivros[pos].autor);

        printf("Insira o estilo do livro: ");
        scanf(" %[^\n]s", &vetLivros[pos].style);

        printf("Insira o preço do livro: ");
        scanf("%f", &vetLivros[pos].price);

        pos++;
        printf("Cadastrado com sucesso!\n");
      } else {
        printf("Limite de livros atingido!\n");
       }
       printf("Deseja cadastrar outro livro? (s/n): ");
       scanf(" %c", &opt1);

     } while (opt1 == 's'); 
    break;
    
    case 'b':
      for (i = 0; i < pos; i++) {
        printf("Titulo: %s\n", vetLivros[i].title);
      }
      break;

    case 'c':
      printf("Insira o titulo para busca: ");
      scanf(" %[^\n]s", &busca);

      for (i = 0; i < pos; i++) {
        if (strcmp(busca, vetLivros[i].title) == 0) {
          printf("%c", vetLivros[i].autor);
          printf("%c", vetLivros[i].style);
          printf("%.2f", vetLivros[i].price);
        } else {
          printf("Não existe livro com esse titulo");
        }
      }
      break;

    case 'd':
      printf("Insíra o titulo para buscar");
      scanf(" %[^/n]s", &busca);

    for(i = 0; i < pos; i++){
      if(strcmp(busca, vetLivros[i].autor)==0){

        printf("%d", vetLivros[i].code);
        printf("%c", vetLivros[i].style);
        printf("%.2f", vetLivros[i].price);
       }
      }
    break;

    case 'e':
      printf("Insira o estilo para busca: ");
      scanf(" %[^\n]s", &busca);

      for (i = 0; i < pos; i++) {
        if (strcmp(busca, vetLivros[i].style) == 0) {
          printf("%c", vetLivros[i].title);
          printf("%c", vetLivros[i].autor);
          printf("%c", vetLivros[i].style);
          printf("%.2f", vetLivros[i].price);
        } else {
          printf("Não existem livros deste estilo");
        }
      }
    break;

    case 'f':
      for (i = 0; i < pos; i++) {
        soma += vetLivros[i].price;
        cont++;
      }
      printf("A média dos preços é: %.2f", (soma / cont));
      break;

    case 'g':
      printf("Saindo...");
      break;

    default:
       printf("Opção inválida!\n");
    break;
    }
  } while (opt != 'g');
}
