//
// Created by nikoly on 09/04/24.
//

#ifndef TURING_MACHINE_SIMULATOR_MODEL_H
#define TURING_MACHINE_SIMULATOR_MODEL_H

#define MAX 100
#define MAX_TAPE_SIZE 1024

typedef struct {
    char * current_state;
    char symbol;
    char * next_state;
    char write_symbol;
    char direction;
} Transition;

typedef struct {
    Transition transitions[MAX];
} State;

typedef  struct  {
    State **states;
    int states_size;
    char **final_states;
    int final_states_size;
    char tape[MAX_TAPE_SIZE];
    int tapeHead;
    char **alphabet;
    int alphabet_size;
} Machine;

#endif //TURING_MACHINE_SIMULATOR_MODEL_H
