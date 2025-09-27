#include <stdio.h>
#include <string.h>
#define MAX_PACIENTES 100
struct Paciente {
    char nome[50];
    int idade;
};
void inserirPaciente(struct Paciente fila[], int *tamanho, struct Paciente novoPaciente) {
    if (*tamanho >= MAX_PACIENTES) {
        printf("Erro: Fila de prioridade cheia.\n");
        return;
    }

    int i = *tamanho - 1;
    while (i >= 0 && fila[i].idade < novoPaciente.idade) {
        fila[i + 1] = fila[i];
        i--;
    }
    fila[i + 1] = novoPaciente;
    (*tamanho)++;
}
struct Paciente removerPaciente(struct Paciente fila[], int *tamanho) {
    if (*tamanho == 0) {
        struct Paciente vazio = {"", -1};
        return vazio;
    }

    struct Paciente pacienteRemovido = fila[0];

    for (int i = 0; i < *tamanho - 1; i++) {
        fila[i] = fila[i + 1];
    }
    (*tamanho)--;
    return pacienteRemovido;
}
int main() {
    struct Paciente lista[MAX_PACIENTES];
    int tamanho = 0;

    struct Paciente p1 = {"Fulano", 18};
    inserirPaciente(lista, &tamanho, p1);
    struct Paciente p2 = {"Ciclano", 26};
    inserirPaciente(lista, &tamanho, p2);
    struct Paciente p3 = {"Beltrano", 47};
    inserirPaciente(lista, &tamanho, p3);

    int qnt;
    printf("Numero de pacientes: ");
    scanf("%d", &qnt);

    for (int i = 0; i < qnt; i++) {
        struct Paciente novoPaciente;
        printf("Nome do paciente (sem espacos): ");
        scanf("%s", novoPaciente.nome);

        printf("Idade do paciente: ");
        scanf("%d", &novoPaciente.idade);

        inserirPaciente(lista, &tamanho, novoPaciente);
    }
    printf("\nLista de prioridade: \n");

    while (tamanho > 0) {
        struct Paciente paciente = removerPaciente(lista, &tamanho);
        printf("%s\n", paciente.nome);
    }
    return 0;
}