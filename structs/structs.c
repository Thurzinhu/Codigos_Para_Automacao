#include <stdio.h>
#include <string.h>

struct Endereco {
    int numero;
    char nomeDaRua[100];
    int casa;
};

struct Pessoa {
    int peso;
    char nome[50];
    float altura;
    struct Endereco enderecoDaPessoa;
};

void atualizarEndereco(struct Pessoa *pessoa, int numero, const char *nomeDaRua, int casa) { //pra quem vou apontar, qual é o numero, rua e casa
    pessoa->enderecoDaPessoa.numero = numero;
    strcpy(pessoa->enderecoDaPessoa.nomeDaRua, nomeDaRua);
    pessoa->enderecoDaPessoa.casa = casa;
}

void atualizarPeso(struct Pessoa *pessoa, int novoPeso) { //pra quem eu vou apontar e qual o novo peso  
    pessoa->peso = novoPeso;
}

void imprimirPessoa(const struct Pessoa *pessoa) {
    printf("Peso: %d kg\n", pessoa->peso);
    printf("Nome: %s\n", pessoa->nome);
    printf("Altura: %.2f m\n", pessoa->altura);
    printf("Número da Casa: %d\n", pessoa->enderecoDaPessoa.numero);
    printf("Nome da Rua: %s\n", pessoa->enderecoDaPessoa.nomeDaRua);
    printf("Casa: %d\n", pessoa->enderecoDaPessoa.casa);
    printf("------------------\n");
}

void criarPessoa(struct Pessoa *pessoa) {
    printf("Digite o nome: ");
    scanf(" %[^\n]s", pessoa->nome);

    printf("Digite o peso (kg): ");
    scanf("%d", &pessoa->peso);

    printf("Digite a altura (m): ");
    scanf("%f", &pessoa->altura);

    printf("Digite o número da casa: ");
    scanf("%d", &pessoa->enderecoDaPessoa.numero);

    printf("Digite o nome da rua: ");
    scanf(" %[^\n]s", pessoa->enderecoDaPessoa.nomeDaRua);

    printf("Digite o número da casa: ");
    scanf("%d", &pessoa->enderecoDaPessoa.casa);

    printf("Funcionário criado com sucesso!\n");
    printf("------------------\n");
}

int main() {
    // Criando dois funcionários
    struct Endereco enderecoDaPessoa1 = {2, "Rua das Flores", 1};
    struct Pessoa victor = {80, "Victor Hugo", 1.90, enderecoDaPessoa1};

    struct Endereco enderecoDaPessoa2 = {40, "Rua das Margaridas", 10};
    struct Pessoa joao = {100, "João Victor", 1.38, enderecoDaPessoa2};

    printf("ANTES DAS ALTERAÇÕES:\n");
    imprimirPessoa(&victor);
    imprimirPessoa(&joao);

    // Atualizando informações usando funções
    atualizarEndereco(&victor, 50, "Rua Nova", 20);
    atualizarPeso(&joao, 110);

    // Criando um novo funcionário
    struct Pessoa novoFuncionario;
    criarPessoa(&novoFuncionario);

    // Imprimindo informações atualizadas
    printf("DEPOIS DAS ALTERAÇÕES:\n");
    imprimirPessoa(&victor);
    imprimirPessoa(&joao);
    imprimirPessoa(&novoFuncionario);

    return 0;
}