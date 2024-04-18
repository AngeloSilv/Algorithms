#include<stdio.h>
#include<time.h>
#include<string.h>
#include<locale.h>
#include<stdlib.h>
#include<ctype.h> // Incluir a biblioteca ctype.h para usar a função tolower()

#define TAM 50

typedef struct 
{
    int codigo;
    char nome[TAM];
    char marca[TAM];
    float preco_unitario;
    float preco_total;
    int quantidade;
} item;

int main() {

    int escolha_produto;
    double valor_total_compra = 0.0; // Armazenar o valor total da compra.
    int itens_vendidos = 0; // Guardar a quantidade de itens vendidos.
    double vendas_decrescente[] = {}; // Vetor para armazenar o valor total das compras e ordená-los em ordem decrescente.
    double faturamento_bruto = 0.0; // Guardar a soma das vendas.
    int quantidade; // Guarda a quantidade de produtos escolhidos.
    int carrinho = 0; // Guarda os produtos escolhidos.
    char op[TAM]; // Será usado como parte do loop ("Digite 'S' se deseja continuar ou aperte 'X' para encerrar o dia.").
    int cliente = 0; //sempre que uma compra for finalizada, será adicionado 1 cliente à variável "cliente".

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
    blusa.quantidade = 1;

    calca.codigo = 8346290;
    strcpy(calca.marca, "Lupa");
    strcpy(calca.nome, "Calça Targo");
    calca.preco_unitario = 130.90;
    calca.quantidade = 1;

    shorts.codigo = 1806931;
    strcpy(shorts.marca, "Lua");
    strcpy(shorts.nome, "Shorts Praia");
    shorts.preco_unitario = 45.90;
    shorts.quantidade = 1; 

    vestido.codigo = 9763250;
    strcpy(vestido.marca, "Lora"); 
    strcpy(vestido.nome, "Girasol");
    vestido.preco_unitario = 120.90;
    vestido.quantidade = 1;

    meia.codigo = 6590342;
    strcpy(meia.marca, "Nice");
    strcpy(meia.nome, "Meia Cano Alto");
    meia.preco_unitario = 15.90;
    meia.quantidade = 2;

    while (strcmp(op, "x") != 0) {

        printf("Deseja registrar uma venda ?\n");
        printf("Digite 'S' se deseja continuar ou aperte 'X' para encerrar o dia.\n");
        scanf("%s", op);

        // Converter a entrada do usuário para letras minúsculas
        op[0] = tolower(op[0]);

        if (strcmp(op, "s") == 0) {

        op[0] = tolower(op[0]);

            printf("Digite o número referente ao produto escolhido\n\n");
            printf("[1] %s %s - %.2f R$\n", camisa.nome, camisa.marca, camisa.preco_unitario);
            printf("[2] %s %s - %.2f R$\n", blusa.nome, blusa.marca, blusa.preco_unitario);
            printf("[3] %s %s - %.2f R$\n", calca.nome, calca.marca, calca.preco_unitario);
            printf("[4] %s %s - %.2f R$\n", shorts.nome, shorts.marca, shorts.preco_unitario);
            printf("[5] %s %s - %.2f R$\n", vestido.nome, vestido.marca, vestido.preco_unitario);
            printf("[6] %s %s - %.2f R$\n", meia.nome, meia.marca, meia.preco_unitario);
            scanf("%d", &escolha_produto);

            printf("\nDigite abaixo quantas unidades deseja:\n");

            
        } else if (strcmp(op, "x") != 0) {
            printf("Opção inválida! Tente novamente.\n");
        }

        /* Exibir as estatísticas
        printf("\nRelatório Gerencial\n\n");
        printf("Quantidade total de itens vendidos no dia: %d\n\n", itens_vendidos);
        printf("Vendas do dia em ordem descrescente: \n"); // Implementar a lógica para exibir as vendas em ordem decrescente
        printf("Faturamento Bruto: %.2f\n\n", faturamento_bruto);
        printf("Quantidade de clientes que realizaram compras: \n"); // Implementar a lógica para contar a quantidade de clientes
        printf("Item mais vendido: \n"); // Implementar a lógica para determinar o item mais vendido
        printf("Item menos vendido: \n\n"); // Implementar a lógica para determinar o item menos vendido */

    }

    fclose(arq);
    return 0;
}