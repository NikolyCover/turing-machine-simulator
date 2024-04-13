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
    char curr_state[MAX_STRING_LENGTH] = "q0"; //assumimos q0 como estado inicial
    char tape[MAX_TAPE_SIZE];
    int tape_indicator = 1; //começa após o caracter de início de fita

    //inicializando fita
    tape[0] = '*';//marcador de início de fita
    strcpy(tape + 1, word);
    strcat(tape, "$"); //marcador de fim de fita

    show_processing_header(word);
    show_processing_step(tape, tape_indicator, curr_state);

    Transition * t = find_transition(curr_state, tape[tape_indicator], machine);
    while (t != NULL) {
        strcpy(curr_state, t->next_state);
        tape[tape_indicator] =  t->write_symbol;
        tape_indicator += t->direction == 'D' ? 1 : -1;

        free(t); // a cada chamada de find_transition t é alocado

        show_processing_step(tape, tape_indicator, curr_state);
        t = find_transition(curr_state, tape[tape_indicator], machine);
    }

    if (is_final_state(curr_state, machine)) return 1;
    return 0;
}

// Encontra transição com em um estado e simbolo lido de uma maquina
// Pré-condição: estado, simbolo e maquina
// Pós-condição: transição retornada caso exista e NULL caso não exista
Transition * find_transition(char * curr_state, char symbol, Machine machine) {
    Transition * t = (Transition *) malloc(sizeof(Transition));

    for(int i = 0; i < machine.transitions_size; i++) {
        *t = machine.transitions[i];
        if(strcmp(curr_state, t->current_state) == 0 && t->read_symbol == symbol) {
            return t;
        }
    }

    return NULL;
}

// Inicia simulador
// Pré-condição: maquina de turing preenchida
// Pós-condição: aplicação finalizada
void run_simulator(Machine machine) {
    char word[MAX_LENGTH];

    input_word(word);

    while(strcmp(word, "sair") != 0) {
        show_result(validate_word(word, machine));

        print_divider();
        input_word(word);
    }
}

// Inicia aplicação
// Pré-condição: nenhuma
// Pós-condição: aplicação finalizada
void start() {
    char filename[100];
    Machine machine;
    init_machine(&machine);

    input_filename(filename);

    read_machine(filename, &machine);
    show_machine(machine);

    run_simulator(machine);

    free_machine(machine);
}