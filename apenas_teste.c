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
    double vendas_decrescente[TAM]; // Vetor para armazenar o valor total das compras e ordená-los em ordem decrescente.
    double faturamento_bruto = 0.0; // Guardar a soma das vendas.
    int cliente = 0; //sempre que uma compra for finalizada, será adicionado 1 cliente à variável "cliente".

    item camisa = {9087523, "Camisa Polo", "Abidas", 129.90, 0, 1};
    item blusa = {1094576, "Blusa Regata", "Nice", 89.90, 0, 1};
    item calca = {8346290, "Calça Targo", "Lupa", 130.90, 0, 1};
    item shorts = {1806931, "Shorts Praia", "Lua", 45.90, 0, 1};
    item vestido = {9763250, "Girasol", "Lora", 120.90, 0, 1};
    item meia = {6590342, "Meia Cano Alto", "Nice", 15.90, 0, 2};

    char op[TAM]; // Será usado como parte do loop ("Digite 'S' se deseja continuar ou aperte 'X' para encerrar o dia.").

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
            scanf("%d", &camisa.quantidade);
            blusa.quantidade = 0;
            calca.quantidade = 0;
            shorts.quantidade = 0;
            vestido.quantidade = 0;
            meia.quantidade = 0;

            switch (escolha_produto) {
                case 1:
                    camisa.preco_total = camisa.quantidade * camisa.preco_unitario;
                    itens_vendidos += camisa.quantidade;
                    faturamento_bruto += camisa.preco_total;
                    break;
                case 2:
                    blusa.preco_total = blusa.quantidade * blusa.preco_unitario;
                    itens_vendidos += blusa.quantidade;
                    faturamento_bruto += blusa.preco_total;
                    break;
                case 3:
                    calca.preco_total = calca.quantidade * calca.preco_unitario;
                    itens_vendidos += calca.quantidade;
                    faturamento_bruto += calca.preco_total;
                    break;
                case 4:
                    shorts.preco_total = shorts.quantidade * shorts.preco_unitario;
                    itens_vendidos += shorts.quantidade;
                    faturamento_bruto += shorts.preco_total;
                    break;
                case 5:
                    vestido.preco_total = vestido.quantidade * vestido.preco_unitario;
                    itens_vendidos += vestido.quantidade;
                    faturamento_bruto += vestido.preco_total;
                    break;
                case 6:
                    meia.preco_total = meia.quantidade * meia.preco_unitario;
                    itens_vendidos += meia.quantidade;
                    faturamento_bruto += meia.preco_total;
                    break;
                default:
                    printf("Opção inválida! Tente novamente.\n");
                    break;
            }

            vendas_decrescente[cliente] = camisa.preco_total + blusa.preco_total + calca.preco_total + shorts.preco_total + vestido.preco_total + meia.preco_total;
            cliente++;

        } else if (strcmp(op, "x") != 0) {
            printf("Opção inválida! Tente novamente.\n");
        }

        // Exibir as estatísticas
        printf("\nRelatório Gerencial\n\n");
        printf("Quantidade total de itens vendidos no dia: %d\n\n", itens_vendidos);
        printf("Vendas do dia em ordem decrescente: \n");
        for (int i = cliente - 1; i >= 0; i--) {
            printf("[%d] R$ %.2f\n", i + 1, vendas_decrescente[i]);
        }
        printf("Faturamento Bruto: %.2f\n\n", faturamento_bruto);
        printf("Quantidade de clientes que realizaram compras: %d\n", cliente);
        printf("Item mais vendido: \n");
        int contagem[6] = {0};
        int max = 0;
        for (int i = 0; i < cliente; i++) {
            contagem[(int)vendas_decrescente[i]]++;
            if (contagem[(int)vendas_decrescente[i]] > max) {
                max = contagem[(int)vendas_decrescente[i]];
            }
        }
        for (int i = 0; i < 6; i++) {
            if (contagem[i] == max) {
                switch (i) {
                    case 1:
                        printf("Camisa Polo\n");
                        break;
                    case 2:
                        printf("Blusa Regata\n");
                        break;
                    case 3:
                        printf("Calça Targo\n");
                        break;
                    case 4:
                        printf("Shorts Praia\n");
                        break;
                    case 5:
                        printf("Girasol\n");
                        break;
                    case 6:
                        printf("Meia Cano Alto\n");
                        break;
                }
            }
        }
        printf("Item menos vendido: ");
        max = 0;
        for (int i = 0; i < 6; i++) {
            if (contagem[i] > 0 && contagem[i] < max) {
                max = contagem[i];
            }
        }
        for (int i = 0; i < 6; i++) {
            if (contagem[i] == max) {
                switch (i) {
                    case 1:
                        printf("Camisa Polo\n");
                        break;
                    case 2:
                        printf("Blusa Regata\n");
                        break;
                    case 3:
                        printf("Calça Targo\n");
                        break;
                    case 4:
                        printf("Shorts Praia\n");
                        break;
                    case 5:
                        printf("Girasol\n");
                        break;
                    case 6:
                        printf("Meia Cano Alto\n");
                        break;
                }
            }
        }
        printf("\n"); 

    }

    return 0;
}