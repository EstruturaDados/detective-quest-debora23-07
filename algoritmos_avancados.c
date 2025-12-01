#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
typedef struct No {
        char nome[30];
        struct No* esquerda;
        struct No* direita;

    } No;

    No* criarNo(const char* nome) {
        No* novo = (No*)malloc(sizeof(No));
        if (novo == NULL) {
            printf("Erro\n");
            exit(1);
        }
        strcpy(novo->nome, nome);
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;

    }
No* inserir(No* raiz, const char* nome) {
    if (raiz == NULL) {
        return criarNo(nome);
    }
    if (strcmp(nome, raiz->nome) < 0) {
        raiz->esquerda = inserir(raiz->esquerda, nome);

    } else {
        raiz->direita = inserir(raiz->direita, nome);
    }
    return raiz;
}
    void preOrdem(No* raiz) {
        if (raiz != NULL) {
           printf("%s ", raiz->nome);
           preOrdem(raiz->esquerda);
           preOrdem(raiz->direita);
        }
    }
    void emOrdem(No* raiz) {
        if (raiz != NULL) {
            emOrdem(raiz->esquerda);
            printf("%s", raiz->nome);
            emOrdem(raiz->direita);
        }
    }
void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%s ", raiz->nome);
    }
}

void liberar(No* raiz) {
    if(raiz != NULL) {
        liberar(raiz->esquerda);
        liberar(raiz->direita);
        free(raiz);
    }
}

int main() {
    No* raiz = NULL;

    raiz = inserir(raiz, "Hall de Entrada\n");

    raiz = inserir(raiz, "Sala de Estar\n");
    raiz = inserir(raiz, "Biblioteca\n");
    raiz = inserir(raiz, "Quarto\n");

    printf("Pre-ordem: \n");
    preOrdem(raiz);

    printf("\n");

int opcao;
do {
    printf("Vamos explorar a mansao\n");
    printf("1. Ir para direita\n");
    printf("2. Ir para esquerda\n");
    printf("3. Liberar data\n");
    printf("4. Sair\n");
    scanf(" %d", &opcao);
    
    switch(opcao) {
        case 1:
        printf("Em ordem: \n");
    emOrdem(raiz);

        break;

        case 2:
        printf("Pós-ordem: \n");
    posOrdem(raiz);

        break;

        case 3:
        liberar(raiz);
        break;

        case 4:
        break;

    }
} while ( opcao != 4);

    return 0;
}
