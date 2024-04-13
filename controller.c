//
// Created by nikoly on 09/04/24.
//
#include "controller.h"

// Inicia maquina
// Pré-condição: maquina alocada
// Pós-condição: maquina preenchida
void init_machine(Machine * machine) {
    machine->alphabet_size = 0;
    machine->states_size = 0;
    machine->final_states_size = 0;
    machine->transitions_size = 0;
    machine->alphabet = malloc(sizeof(char *) * MAX_LENGTH);
    machine->final_states = malloc(sizeof(char *) * MAX_LENGTH);
    machine->transitions = NULL;
}

// Diz se um estado é final
// Pré-condição: estado e maquina de turing
// Pós-condição: diz se é estado final
int is_final_state(char * state, Machine machine) {
    for (int i = 0; i < machine.final_states_size; ++i) {
        if(strcmp(state, machine.final_states[i]) == 0)
            return 1;
    }

    return 0;
}

// Libera espaçp alocado em um maquina
// Pré-condição: maquina
// Pós-condição: espaço liberado
void free_machine(Machine machine) {
    for (int i = 0; i < machine.alphabet_size; i++) {
        free(machine.alphabet[i]);
    }

    for (int i = 0; i < machine.final_states_size; i++) {
        free(machine.final_states[i]);
    }

    for (int i = 0; i < machine.transitions_size; i++) {
        free(machine.transitions[i].current_state);
        free(machine.transitions[i].next_state);
    }

    free(machine.alphabet);
    free(machine.final_states);
    free(machine.transitions);
}

// Valida uma palavra com uma maquina de turing
// Pré-condição: palavra e maquina
// Pós-condição: palavra validada
int validate_word(char * word, Machine machine) {
    /*
    char curr_state[MAX_STRING_LENGTH] = "q0"; //assumimos q0 como estado inicial

    show_processing_header(word);
    show_processing_step(curr_state, word);

    int i = 0;
    while (word[i] != '\0') {
        char read_symbol = word[i];
        int found_transition = 0;

        for (int j = 0; j < machine.transitions_size; j++) {
            if (strcmp(machine.transitions[j].current_state, curr_state) == 0 && machine.transitions[j].read_symbol == read_symbol) {
                strcpy(curr_state, machine.transitions[j].next_state);
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

    if (is_final_state(curr_state, machine)) return 1;*/
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

// Inicia aplicação
// Pré-condição: nenhuma
// Pós-condição: aplicação finalizada
void start() {
    Machine machine;
    init_machine(&machine);

    read_machine("machine.txt", &machine);
    show_machine(machine);

    //run_simulator(machine);

    //free_machine(machine);
}