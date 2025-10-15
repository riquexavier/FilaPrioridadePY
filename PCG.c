#include <stdio.h>
#include <string.h>

struct Paciente {
    char nome[50];
    int idade;
};

void inserirPaciente(struct Paciente fila[], int *tamanho, struct Paciente novoPaciente) {
    int i = *tamanho - 1;

    while (i >= 0 && fila[i].idade < novoPaciente.idade) {
        fila[i + 1] = fila[i];
        i--;
    }

    fila[i + 1] = novoPaciente;
    (*tamanho)++;
}

int main() {
    int qnt;

    printf("Quantos pacientes deseja cadastrar? ");
    scanf("%d", &qnt);

    struct Paciente lista[100];
    int tamanho = 0;

    if (qnt <= 0 || qnt > 100) {
        printf("Quantidade invalida! Use entre 1 e 100 pacientes.\n");
        return 1;
    }
    int i = 0;
    while (i < qnt) {
        struct Paciente novoPaciente;

        printf("\nPaciente %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", novoPaciente.nome);

        printf("Idade: ");
        scanf("%d", &novoPaciente.idade);

        inserirPaciente(lista, &tamanho, novoPaciente);
        i++;
    }

    printf("\n=== ORDEM DE ATENDIMENTO (por prioridade de idade) ===\n");
    int j = 0;
    while (j < tamanho) {
        printf("%d. %s - %d anos\n", j + 1, lista[j].nome, lista[j].idade);
        j++;
    }
    return 0;
}
