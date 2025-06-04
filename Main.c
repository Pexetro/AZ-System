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

void editar(int *x, char nomeItem[100][120], int quantidade[100], char descricao[100][220]) {
    char nomeParaEditar[120];
    int escolha;
    int encontrado = 0;
    int indiceItem = -1;

    printf("Digite o nome do item a ser editado: ");
    scanf("%119s", nomeParaEditar);
    getchar();

    for (int i = 0; i < *x; i++) {
        if (strcmp(nomeParaEditar, nomeItem[i]) == 0) {
            encontrado = 1;
            indiceItem = i;
            break;
        }
    }

    if (encontrado) {
        printf("\n--O que deseja alterar?-- \n");
        printf("[1] Nome \n");
        printf("[2] Quantidade \n");
        printf("[3] Descricao \n");
        printf("Escolha: ");
        scanf("%d", &escolha);
        getchar();

        switch (escolha) {
            case 1:
                printf("Novo nome do item: ");
                scanf("%119s", nomeItem[indiceItem]);
                getchar();
                printf("O item agora se chama: %s\n", nomeItem[indiceItem]);
                break;
            case 2:
                printf("Nova quantidade do item: ");
                scanf("%d", &quantidade[indiceItem]);
                getchar();
                printf("A nova quantidade é: %d\n", quantidade[indiceItem]);
                break;
            case 3:
                printf("Nova descrição do item: ");
                scanf("%219[^\n]", descricao[indiceItem]);
                getchar();
                printf("A nova descrição é: %s\n", descricao[indiceItem]);
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } else {
        printf("Sem correspondência. Item não encontrado.\n");
    }
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
        printf("[3] Editar itens \n");
        printf("[4] Excluir itens \n");
        printf("[5] Sair \n");
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
                editar(&x, nomeItem, quantidade, descricao);
                break;
            case 4:
                excluir(&x, nomeItem, quantidade, descricao);
                break;
            case 5:
                printf("Saindo do sistema...\n----------------------------------\n");
                break;
            default:
                printf("Escolha inválida, tente novamente.\n----------------------------------\n");
                break;
        }
    } while (escolha != 5);

    return 0;
}
