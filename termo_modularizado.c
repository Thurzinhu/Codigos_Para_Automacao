#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define GREEN_BG "\033[42;37m"
#define RED_BG "\033[41;37m"
#define YELLOW_BG "\033[43;37m"
#define RESET "\033[0m"

void colocarPalavraEmCaixaAlta(char *str);
int verificarPalavra(char *tentativa, char *palavraSecreta);
void gerarFeedback(char *tentativa, char *palavraSecreta);

int main() {
    char palavraSecreta[] = "TERMO";
    char tentativa[50];
    int maxTentativas = 6;

    printf("Bem-vindo ao jogo Termo!\n");
    printf("Você tem %d tentativas para adivinhar a palavra secreta.\n", maxTentativas);

    int tentativaAtual = 0;
    while (tentativaAtual < maxTentativas) {
        printf("\nTentativa %d: Digite sua palavra: ", tentativaAtual + 1);
        scanf("%s", tentativa);

        colocarPalavraEmCaixaAlta(tentativa);

        if (verificarPalavra(tentativa, palavraSecreta)) {
            printf("Parabéns! Você acertou a palavra secreta!\n");
            return 0;
        }

        printf("Feedback: ");
        gerarFeedback(tentativa, palavraSecreta);

        tentativaAtual++;
    }

    printf("Você perdeu! A palavra secreta era: %s\n", palavraSecreta);
    return 0;
}

void colocarPalavraEmCaixaAlta(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

int verificarPalavra(char *tentativa, char *palavraSecreta) {
    return strcmp(tentativa, palavraSecreta) == 0;
}

void gerarFeedback(char *tentativa, char *palavraSecreta) {
    for (int i = 0; i < strlen(palavraSecreta); i++) {
        if (tentativa[i] == palavraSecreta[i]) {
            printf(GREEN_BG " %c " RESET, tentativa[i]);
        } else if (strchr(palavraSecreta, tentativa[i])) {
            printf(YELLOW_BG " %c " RESET, tentativa[i]);
        } else {
            printf(RED_BG " %c " RESET, tentativa[i]);
        }
    }
    printf("\n");
}