# 📦 CRUD em C — Cadastro de Produtos Eletrônicos

Este projeto foi desenvolvido como parte da disciplina de **Lógica de Programação** na FATEC. Ele simula um sistema de CRUD (Create, Read, Update, Delete) para o cadastro de produtos eletrônicos, utilizando exclusivamente a linguagem C.

---

## 🛠️ Funcionalidades

- 📥 **Cadastrar** um novo produto
- 📃 **Listar** produtos cadastrados
- ✏️ **Editar** informações de um produto
- 🗑️ **Excluir** um produto

---

## 🧠 Conceitos Trabalhados

Durante o desenvolvimento, utilizamos diversos conceitos fundamentais da linguagem C e da lógica de programação:

- ✅ **Modularização com Funções**  
  O sistema foi dividido em funções como `cadastro()`, `exibir()`, `editar()` e `excluir()`, facilitando a organização e a manutenção do código.

- ✅ **Vetores de Strings (Arrays Multidimensionais)**  
  Os nomes e descrições dos produtos foram armazenados em arrays de strings (`char nomeItem[100][120]`, `char descricao[100][220]`), reforçando o uso de matrizes e manipulação de texto.

- ✅ **Entrada e Validação de Dados**  
  O programa usa `fgets`, `scanf` e `getchar` para ler dados, com validações importantes como impedir nomes vazios ou quantidades inválidas.

- ✅ **Laços e Condições**  
  O uso de `for`, `do-while` e `switch` possibilitou controle de fluxo e interações com o usuário.

- ✅ **Comparação e Manipulação de Strings**  
  Funções como `strcmp` e `strcspn` foram aplicadas para localizar e tratar strings com segurança.

- ✅ **Remoção Lógica de Elementos**  
  Ao excluir itens, o vetor é reorganizado com `strcpy` para preencher o espaço removido, garantindo integridade da lista.

- ✅ **Gerenciamento de Estado com Variáveis e Ponteiros**  
  O controle do número de itens (`x`) foi feito por meio de ponteiros, permitindo modificar seu valor entre funções.

---


