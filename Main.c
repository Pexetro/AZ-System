#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cadastro(int *x, int quantidade[100], char nomeItem[100][120], char descricao[100][220]) {
    if (*x >= 100) {
        printf("Limite de itens atingido.\n----------------------------------\n");
        return *x;
    }

    printf("Qual o item quer cadastrar?\n");
    fgets(nomeItem[*x], 120, stdin);
    nomeItem[*x][strcspn(nomeItem[*x], "\n")] = '\0';
    
    if (strlen(nomeItem[*x]) == 0) {
        printf("Nome do item inválido. Este item não pode ser cadastrado.\n");
        return *x;
    }

    printf("Qual a quantidade?\n");
    scanf("%d", &quantidade[*x]);
    getchar();

    if (quantidade[*x] <= 0) {
        printf("Quantidade inválida. Não é possível adicionar 0 ou menos unidades.\n----------------------------------\n");
        return *x;
    }

    printf("Descrição:\n");
    fgets(descricao[*x], 220, stdin);
    descricao[*x][strcspn(descricao[*x], "\n")] = '\0';

    printf("Item cadastrado com sucesso! (ID: %d)\n----------------------------------\n", *x + 1);
    (*x)++;
    return *x;
}

void exibir(int x, char nomeItem[100][120], int quantidade[100], char descricao[100][220]) {
    if (x == 0) {
        printf("Nenhum item cadastrado ainda.\n----------------------------------\n");
        return;
    }
    for (int i = 0; i < x; i++) {
        printf("\nItem %d:\n", i + 1);
        printf("Nome: %s\n", nomeItem[i]);
        printf("Quantidade: %d\n", quantidade[i]);
        printf("Descrição: %s\n", descricao[i]);
    }
    printf("----------------------------------\n");
}

void excluir(int *x, char nomeItem[100][120], int quantidade[100], char descricao[100][220]) {
    int deleteId = 0;
    
    if (*x == 0) {
        printf("Nenhum item para excluir.\n----------------------------------\n");
        return;
    }
    
    printf("----------------------------------\nItens cadastrados:\n");
    for (int i = 0; i < *x; i++) {
        printf("[%d] %s\n", i + 1, nomeItem[i]);
    }
    
    printf("\nDigite o ID do item a ser deletado: ");
    scanf("%d", &deleteId);
    getchar();

    if (deleteId < 1 || deleteId > *x) {
        printf("ID inválido!\n----------------------------------\n");
        return;
    }
    
    deleteId--;
    
    for (int i = deleteId; i < *x - 1; i++) {
        strcpy(nomeItem[i], nomeItem[i + 1]);
        strcpy(descricao[i], descricao[i + 1]);
        quantidade[i] = quantidade[i + 1];
    }
    (*x)--;
    printf("Item removido com sucesso!\n----------------------------------\n");
}

int main() {
    int x = 0; // número de itens
    int escolha;

    char nomeItem[100][120];
    char descricao[100][220];
    int quantidade[100];

    do {
        printf("\n--MENU DO SISTEMA-- \n");
        printf("[1] Cadastrar item \n");
        printf("[2] Listar itens \n");
        printf("[3] Excluir itens \n");
        printf("[4] Sair \n");
        printf("Escolha: ");
        scanf("%d", &escolha);
        getchar();

        switch (escolha) {
            case 1:
                cadastro(&x, quantidade, nomeItem, descricao);
                break;

            case 2:
                exibir(x, nomeItem, quantidade, descricao);
                break;

            case 3:
                excluir(&x, nomeItem, quantidade, descricao);
                break;

            case 4:
                printf("Saindo do sistema...\n----------------------------------\n");
                break;

            default:
                printf("Escolha inválida, tente novamente.\n----------------------------------\n");
                break;
        }
    } while (escolha != 4);

    return 0;
}