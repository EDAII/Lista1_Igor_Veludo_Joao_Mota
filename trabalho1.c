//Alunos: Joao Pedro Mota Jardim       16/0031982
//        Igor Veludo                  13/0028240

#include <stdio.h>
#include <stdlib.h>

#define MAX 10000
void preencheVetor(int *numeros);
int mostraMenu();
void imprimeVetor(int *numeros);
int verificaEspacoVazio(int *numeros);
void insereValor(int *numeros);
void removeValor(int *numeros);
void buscaSequencial(int *numeros);
void buscaBinaria(int *numeros);
void buscaInterpolacao(int *numeros);

int main(){
  int numeros[MAX],opcao;
  preencheVetor(numeros);
  do{
    opcao = mostraMenu();
    switch(opcao){
      case 1:
        imprimeVetor(numeros);
        break;
      case 2:
        if (verificaEspacoVazio(numeros)){
          insereValor(numeros);
        }
        else
          printf("Vetor esta cheio\n");
        break;
      case 3:
        removeValor(numeros);
        break;
      case 4:
        buscaSequencial(numeros);
        break;
      case 5:
        buscaBinaria(numeros);
        break;
      case 6:
        buscaInterpolacao(numeros);
    }
  }while(opcao != 0);

  return 0;
}

void preencheVetor(int *numeros){
  int i;
  // preenche metade do vetor seguindo de 10 em 10, e o resto preenche com -1 (invalido ou livre)
  for(i=0;i < MAX/2; i++)
    numeros[i] = i*10;
  for(i=MAX/2;i < MAX; i++)
    numeros[i] = -1;
}

int mostraMenu(){
  int opcao;
  //system("clear");
  printf("\n");
  printf(" ========================================\n");
  printf("|         >>>>>>>>> Menu <<<<<<<<<       |\n");
  printf("| 1 - Imprimir vetor                     |\n");
  printf("| 2 - Inserir valor                      |\n");
  printf("| 3 - Remover valor                      |\n");
  printf("| 4 - Busca sequencial                   |\n");
  printf("| 5 - Busca binaria                      |\n");
  printf("| 6 - Busca por interpolacao             |\n");
  printf("| 0 - Sair                               |\n");
  printf(" ========================================\n");
  printf("Sua opcao: ");
  scanf("%d",&opcao);
  return opcao;
}

//Funcao para imprimir os numeros preenchidos do vetor
void imprimeVetor(int *numeros){
  int i = 0;
  while(numeros[i] != -1 && i < MAX){
    printf("| %d ",numeros[i]);
    i++;
  }

  printf("|\n");
}
//Funcao para verificar se ainda tem espaco para inserir um novo valor
int verificaEspacoVazio(int *numeros){
  int i = 0;
  while(i < MAX){
    if(numeros[i] == -1){
      return 1;
    }
    i++;
  }
  return 0;
}

// Funcao para inserir um valor escolhendo sua posicao por uma busca sequencial
void insereValor(int *numeros){
  int i = 0,j,valor;
  printf("Informe o valor a ser inserido: ");
  scanf("%d",&valor);
  while(valor > numeros[i] && numeros[i] != -1){
    i++;
  }
  // se o numero for -1, ele chegou em um espaco vago, sem necessidade de deslocamento
  if(numeros[i] == -1){
    numeros[i] = valor;
  }
  else{
    //vai ate a primeira posicao livre e move todos os elementos uma casa pra direita pra poder inserir
    j = i;
    while(numeros[j] != -1){
      j++;
    }
    while(j >= i){
      numeros[j] = numeros[j-1];
      j--;
    }
    numeros[i] = valor;
  }
  printf("Elemento inserido com sucesso \n");
}
// Funcao para remover um valor encontrando sua posicao por uma busca sequencial
void removeValor(int *numeros){
  int i = 0,valor;
  printf("Informe o valor a ser removido: ");
  scanf("%d",&valor);
  while(valor != numeros[i] && i < MAX){
    i++;
  }
  if(numeros[i] == valor){
    //move todos os elementos depois do elemento que se deseja remover,uma casa para a esquerda, o apagando
    while(numeros[i] != -1 && i+1 < MAX){
      numeros[i] = numeros[i+1];
      i++;
    }
    numeros[i] = -1;
    printf("Elemento removido com sucesso \n");
  }
  else{
    printf("Elemento nao encontrado \n");
  }
}

// Funcao para encontrar um valor e sua posicao por uma busca sequencial
void buscaSequencial(int *numeros){
  int i = 0,valor;
  printf("Informe o valor a ser encontrado: ");
  scanf("%d",&valor);
  while(valor != numeros[i] && i < MAX){
    i++;
  }
  if(numeros[i] == valor){
    printf("O numero %d foi encontrado na %do posicao \n",valor, i + 1 );
  }
  else{
    printf("Elemento nao encontrado \n");
  }
}

// Funcao para encontrar um valor e sua posicao por uma busca binaria
void buscaBinaria(int *numeros){
  int valor,limSup = 0, limInf = 0, meio, aux;
  while(numeros[limSup] != -1 && limSup < MAX - 1){
    limSup++;
  }
  aux = limSup;
  printf("Informe o valor a ser encontrado: ");
  scanf("%d",&valor);
  do{
    meio = (limSup + limInf) / 2;
    if(valor == numeros[meio]){
      printf("O numero %d foi encontrado na %do posicao \n",valor, meio + 1 );
      return;
    }
    else{
      //printf("2\n");
      if(valor > numeros[meio]){
        //printf("3\n");
        limInf = meio;
      }
      else{
        //printf("4\n");
        limSup = meio;
      }
    }
    if(aux == 1){
      printf("Elemento nao encontrado \n");
      return;
    }
    aux--;
  }while(numeros[meio] != valor && aux > 0);
}

// Funcao para encontrar um valor e sua posicao por uma busca por interpolacao
void buscaInterpolacao(int *numeros){
  int valor,limSup = 0, limInf = 0, meio, aux;
  while(numeros[limSup] != -1 && limSup < MAX - 1){
    limSup++;
  }
  limSup--;
  aux = limSup;
  printf("Informe o valor a ser encontrado: ");
  scanf("%d",&valor);
  do{
    if((numeros[limSup] - numeros[limInf]) == 0){
      printf("Elemento nao encontrado \n");
      return;
    }
    meio = limInf + (limSup - limInf) * (valor - numeros[limInf]) / (numeros[limSup] - numeros[limInf]);
    if(valor == numeros[meio]){
      printf("O numero %d foi encontrado na %do posicao \n",valor, meio + 1 );
      return;
    }
    else{
      if(valor > numeros[meio]){
        limInf = meio;
      }
      else{
        limSup = meio;
      }
    }
    if(aux == 1){
      printf("Elemento nao encontrado \n");
      return;
    }
    aux--;

  }while(numeros[meio] != valor && aux > 0);
}
