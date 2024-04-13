//
// Created by nikoly on 10/04/24.
//

#include "view.h"

// Mostra um divisor
// Pré-condição: nenhuma
// Pós-condição: um divisor é mostrado no terminal
void print_divider() {
    printf("\n-------------------------------------------------------------------------\n\n");
}

// Mostra todas as informações de uma maquina de turing
// Pré-condição: estrutura do tipo maquina de turing preenchida
// Pós-condição: informações mostradas no terminal
void show_machine(Machine machine) {
    print_divider();
    printf("MAQUINA DE TURING:\n");
    printf("\nQuantidade de estados: %d", machine.states_size);

    printf("\nFinais: ");
    for (int i = 0; i < machine.final_states_size; i++) {
        printf("%s ", machine.final_states[i]);
    }

    printf("\nAlfabeto: ");
    for (int i = 0; i < machine.alphabet_size; i++) {
        printf("%s ", machine.alphabet[i]);
    }

    printf("\nTransições:\n");
    Transition t;
    for (int i = 0; i < machine.transitions_size; i++) {
        t = machine.transitions[i];
        printf("(%s, %c) = (%s, %c, %c)\n", t.current_state, t.read_symbol, t.next_state, t.write_symbol, t.direction);
    }

    print_divider();
}

// Pega uma palavra digitada pelo usuário
// Pré-condição: ponteiro de char
// Pós-condição: ponteiro de char preenchido com o que o usuário digitou
void input_word(char * word) {
    printf("Digite uma palavra para ser testada (ou 'sair' para sair do sistema): ");
    scanf("%s", word);
}

// Mostra uma mensagem em verde
// Pré-condição: mensagem
// Pós-condição: mensagem é mostrada
void show_green_message(char * message) {
    printf("\033[1;32m");

    printf(message);

    printf("\033[0m");
}

// Mostra uma mensagem em vermelho
// Pré-condição: mensagem
// Pós-condição: mensagem é mostrada
void show_red_message(char * message) {
    printf("\033[1;31m");

    printf(message);

    printf("\033[0m");
}

// Mostra REJEITA caso result seja 0 e ACEITA caso seja 1
// Pré-condição: número de resultado (1 ou 0)
// Pós-condição: resultado é mostrado
void show_result(int result) {
    if(result) {
        show_green_message("ACEITA\n");
    } else {
        show_red_message("REJEITA\n");
    }
}

// Mostra um passo do processamento da mensagem
// Pré-condição: fita, cabeça da fita e estado atual
// Pós-condição: passo mostrado
void show_processing_step(char * tape, int tape_indicator, char *curr_state) {
    for (int i = 0; tape[i] != '\0'; i++) {
        if (i == tape_indicator) printf("[%s]", curr_state);
        printf("%c", tape[i]);
    }
    printf("\n");
}

// Mostra cabeçalho do processamento
// Pré-condição: palavra
// Pós-condição: cabeçalho é mostrado
void show_processing_header(char * word) {
    printf("\nProcessamento de '%s':\n", word);
}

// Pega o nome do arquivo do usuário
// Pré-condição: ponteiro de char
// Pós-condição: ponteiro de char preenchido com o que o usuário digitou
void input_filename(char * filename) {
    printf("-------------------------------------------- TURING MACHINE SIMULATOR --------------------------------------------\n");
    printf("\nDigite o nome do arquivo que contém a definição da maquina de turing: ");
    scanf("%s", filename);
}