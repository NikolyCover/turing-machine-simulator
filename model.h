//
// Created by nikoly on 09/04/24.
//

#ifndef TURING_MACHINE_SIMULATOR_MODEL_H
#define TURING_MACHINE_SIMULATOR_MODEL_H

#define MAX_STRING_LENGTH 5
#define MAX_LENGTH 1000
#define MAX_TAPE_SIZE 1024

typedef struct {
    char * current_state;
    char read_symbol;
    char * next_state;
    char write_symbol;
    char direction; // 'D' (direita) ou 'E' (esquerda)
} Transition;

typedef  struct  {
    int states_size; //Q
    char **final_states; //F
    int final_states_size;
    char **alphabet;
    int alphabet_size;
    Transition * transitions;
    int transitions_size;
} Machine;

#endif //TURING_MACHINE_SIMULATOR_MODEL_H
