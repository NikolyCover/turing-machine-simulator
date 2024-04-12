//
// Created by nikoly on 09/04/24.
//
#include "controller.h"

/*
// Inicia maquina
// Pré-condição: maquina alocada
// Pós-condição: maquina preenchida
void init_machine(Machine * afd) {
    afd->alphabet_size = 0;
    afd->states_size = 0;
    afd->final_states_size = 0;
    afd->transitions_size = 0;
    afd->alphabet = malloc(sizeof(char *) * MAX_LENGTH);
    afd->states = malloc(sizeof(char *) * MAX_LENGTH);
    afd->final_states = malloc(sizeof(char *) * MAX_LENGTH);
    afd->transitions = NULL;
}

// Diz se um estado é final
// Pré-condição: estado e maquina de turing
// Pós-condição: diz se é estado final
int is_final_state(char * state, Machine afd) {
    for (int i = 0; i < afd.final_states_size; ++i) {
        if(strcmp(state, afd.final_states[i]) == 0)
            return 1;
    }

    return 0;
}

// Libera espaçp alocado em um maquina
// Pré-condição: maquina
// Pós-condição: espaço liberado
void free_machine(Machine afd) {
    for (int i = 0; i < afd.alphabet_size; i++) {
        free(afd.alphabet[i]);
    }

    for (int i = 0; i < afd.states_size; i++) {
        free(afd.states[i]);
    }

    for (int i = 0; i < afd.final_states_size; i++) {
        free(afd.final_states[i]);
    }

    for (int i = 0; i < afd.transitions_size; i++) {
        free(afd.transitions[i].current_state);
        free(afd.transitions[i].next_state);
    }

    free(afd.alphabet);
    free(afd.states);
    free(afd.final_states);
    free(afd.transitions);
}

// Valida uma palavra com uma maquina de turing
// Pré-condição: palavra e maquina
// Pós-condição: palavra validada
int validate_word(char * word, Machine afd) {
    char curr_state[MAX_STRING_LENGTH] = "q0"; //assumimos q0 como estado inicial

    show_processing_header(word);
    show_processing_step(curr_state, word);

    int i = 0;
    while (word[i] != '\0') {
        char read_symbol = word[i];
        int found_transition = 0;

        for (int j = 0; j < afd.transitions_size; j++) {
            if (strcmp(afd.transitions[j].current_state, curr_state) == 0 && afd.transitions[j].read_symbol == read_symbol) {
                strcpy(curr_state, afd.transitions[j].next_state);
                found_transition = 1;
                break;
            }
        }

        if (!found_transition) {
            return 0;
        }

        show_processing_step(curr_state, word + i + 1);

        i++;
    }

    if (is_final_state(curr_state, afd)) return 1;
    return 0;
}

// Inicia simulador
// Pré-condição: maquina de turing preenchida
// Pós-condição: aplicação finalizada
void run_simulator(Machine afd) {
    char word[MAX_LENGTH];

    input_word(word);

    while(strcmp(word, "sair") != 0) {
        show_result(validate_word(word, afd));

        print_divider();
        input_word(word);
    }
}
 */

// Inicia aplicação
// Pré-condição: nenhuma
// Pós-condição: aplicação finalizada
void start() {
    Machine afd;
    //init_machine(&afd);

    //read_afd("afd.txt", &afd);
    //show_machine(afd);

    ///run_simulator(afd);

    //free_machine(afd);
}
