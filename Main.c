#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int x = 0; // número de itens
    int escolha;
    int deleteId = 0;

    char nomeItem[100][120];    // até 100 itens, nome com até 119 caracteres
    char descricao[100][220];   // até 100 itens, descrição com até 219 caracteres
    int quantidade[100];        // até 100 quantidades

    do {
        printf("\n--MENU DO SISTEMA-- \n");
        printf("[1] Cadastrar item \n");
        printf("[2] Listar itens \n");
        printf("[3] Excluir itens \n");
        printf("[4] Sair \n");
        printf("Escolha: ");
        scanf("%d", &escolha);
        getchar(); // limpa o '\n' do buffer

        switch (escolha) {
            case 1:
                if (x >= 100) {
                    printf("Limite de itens atingido.\n----------------------------------\n");
                    break;
                }

                printf("Qual o item quer cadastrar?\n");
                fgets(nomeItem[x], 120, stdin);
                nomeItem[x][strcspn(nomeItem[x], "\n")] = '\0'; // remove o '\n'
                
                if (strlen(nomeItem[x]) == 0) {
                    printf("Nome do item inválido. Este item não pode ser cadastrado.\n");
                    break;
                }

                printf("Qual a quantidade?\n");
                scanf("%d", &quantidade[x]);
                getchar(); // limpa o ENTER

                if (quantidade[x] <= 0) {
                    printf("Quantidade inválida. Não é possível adicionar 0 ou menos unidades.\n----------------------------------\n");
                    break;
                }

                printf("Descrição:\n");
                fgets(descricao[x], 220, stdin);
                descricao[x][strcspn(descricao[x], "\n")] = '\0'; // remove o '\n'

                printf("Item cadastrado com sucesso! (ID: %d)\n----------------------------------\n", x + 1);
                x++; // incrementa número de itens
                break;

            case 2:
                if (x == 0) {
                    printf("Nenhum item cadastrado ainda.\n----------------------------------\n");
                    break;
                }
                for (int i = 0; i < x; i++) {
                    printf("\nItem %d:\n", i + 1);
                    printf("Nome: %s\n", nomeItem[i]);
                    printf("Quantidade: %d\n", quantidade[i]);
                    printf("Descrição: %s\n", descricao[i]);
                }
                break;

            case 3:
                if (x == 0) {
                    printf("Nenhum item para excluir.\n----------------------------------\n");
                    break;
                }
                printf("----------------------------------\nItens cadastrados:\n");
                for (int i = 0; i < x; i++) {
                    printf("[%d] %s\n", i + 1, nomeItem[i]);
                }
                printf("\nDigite o ID do item a ser deletado: ");
                scanf("%d", &deleteId);
                getchar();

                if (deleteId < 1 || deleteId > x) {
                    printf("ID inválido!\n----------------------------------\n");
                    break;
                }
                
                deleteId--;   // ajusta o índice (IDs começam em 1, array em 0)
                
                for (int i = deleteId; i < x - 1; i++) {
                    strcpy(nomeItem[i], nomeItem[i + 1]);
                    strcpy(descricao[i], descricao[i + 1]);
                    quantidade[i] = quantidade[i + 1];    // remove o item deslocando os próximos pra trás
                }
                x--;
                printf("Item removido com sucesso!\n----------------------------------\n");
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