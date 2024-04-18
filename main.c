#include<stdio.h>
#include<time.h>
#include<string.h>
#include<locale.h>
#include<stdlib.h>

#define TAM 50

typedef struct 
{
    int codigo;
    char nome[TAM];
    char marca[TAM];
    float preco_unitario;
    float preco_total;
    int quantidade;
}item;





int main () {

    double valor_total_compra; //armazenar o valor total da compra.
    int itens_vendidos; // guardar a quantidade de itens vendidos.
    double vendas_decrescente[] = {}; //vetor para armazenar o valor total das compras e ordená-los em ordem decrescente.
    double faturamento_bruto; // guardar a soma das vendas.
    int quatidade; // guarda a quantidade de produtos escolhidos.
    int carrinho; // guarda os produtos escolhidos (não sei ao certo se vou implementar).
    char op; // será usado como parte do loop ("Digite 'S' se deseja continuar ou aperte 'X' para encerrar o dia.")

    FILE *arq;

    item camisa;
    item blusa;
    item calca;
    item shorts;
    item vestido;
    item meia;

    arq = fopen("loja_roupa.dat", "wb");

    camisa.codigo = 9087523;
    strcpy(camisa.marca, "Abidas");
    strcpy(camisa.nome, "Camisa Polo");
    camisa.preco_unitario = 129.90;
    camisa.quantidade = 1; 

    blusa.codigo = 1094576;
    strcpy(blusa.marca, "Nice");
    strcpy(blusa.nome, "Blusa Regata");
    blusa.preco_unitario = 89.90;

    calca.codigo = 8346290;
    strcpy(calca.marca, "Lupa");
    strcpy(calca.nome, "Calça Targo");
    blusa.preco_unitario = 130.90;

    
    while(strcmp(op, "X") != 0) {

    printf("Deseja registrar uma venda ?\n");
    printf("Digite 'S' se deseja continuar ou aperte 'X' para encerrar o dia.\n");
    scanf("%s", &op);

    if (strcmp(op, "S") == 0) {

        //Lógica do código
    } else if (strcmp(op, "X") !=0) {
        printf("Opção inválida, tente novamente.\n");
    }

    }
    printf("Relatório Gerencial\n\n");
    printf("Quantidade total de itens vendidos no dia:\n\n");
    printf("Vendas do dia em ordem descrescente:\n\n");
    printf("Faturamento Bruto:\n\n");
    printf("Quantidade de clientes que realizaram compras:\n\n");
    printf("Item mais vendido:\n\n");
    printf("Item menos vendido:\n\n");
    

    return 0;
}