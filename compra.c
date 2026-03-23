#include <stdio.h>
#include <string.h>

int main(){

    // Definicao dos itens dos produtos fixos
    int codigos[5] = {101, 102, 103, 104, 105};
    char nomes[5][20] = {"Arroz", "Feijao", "Macarrao", "Farinha", "Acucar"};
    float precos[5] = {5.5, 7.2, 4.0, 3.8, 2.5};

    // Impressão dos dados dos produtos fixos
    int i, j;
    int itens = 0;
    float total = 0;

    printf("lista de Produtos\n");
    for (i = 0; i < 5; i++){
        printf("%d - %s - %.2f\n", codigos[i], nomes[i], precos[i]);
    }

    int codigo;
    int quantidade;
    float subtotal;

    float carrinho[10][3];

    for (i = 0; i < 10; i++){

        printf("Digite o código e a quantidade (caso queira encerrar, digite 0): ");

        scanf("%d", &codigo);

        if (codigo == 0){ // caso o usuario digite 0, a inserção de itens para.
            break;
        }

        scanf("%d", &quantidade);

        if (codigo < 101 || codigo > 105){
            printf("Código Inválido! Tente novamente.\n");

        } else {

            for (j = 0; j < 5; j++) { // comparar o código digitado com o existente para montar o carrinho.
                if (codigos[j] == codigo){
                    subtotal = precos[j] * quantidade;
                }
            }

            carrinho[itens][0] = codigo;
            carrinho[itens][1] = quantidade;
            carrinho[itens][2] = subtotal;

            itens++; // conta os itens adicionados pra imprimir somente esses depois
            total = total + subtotal;
        }
    }

    printf("\nNOTA FISCAL\n");
    printf("NOME DO PRODUTO - QUANTIDADE - PREÇO UNITÁRIO - SUBTOTAL\n\n");

    char nome[20]; // é pra pegar o nome do produto na lista fixa e imprimir
    float preco_unit;

    for (i = 0; i < itens; i++){
        for (j = 0; j < 5; j++){ // comparar o código digitado com o existente pra imprimir dps
            if (carrinho[i][0] == codigos[j]){
                strcpy(nome, nomes[j]); // nome do produto de indice j para a variavel nome
                preco_unit = precos[j];
            }
        }
        // nome, qtd, preco unitario, subtotal, total
        printf("%s - %.0f - R$%.2f - R$%.2f\n", nome, carrinho[i][1], preco_unit, carrinho[i][2]);
    }
    printf("TOTAL: R$%.2lf", total);
}
