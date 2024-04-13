//
// Created by nikoly on 09/04/24.
//

#ifndef AFD_SIMULATOR_CONTROLLER_H
#define AFD_SIMULATOR_CONTROLLER_H

#include "service.h"
#include "model.h"
#include "view.h"
#include <stdlib.h>
#include <string.h>

// Inicia aplicação
// Pré-condição: nenhuma
// Pós-condição: aplicação finalizada
void start();

// Inicia simulador
// Pré-condição: maquina de turing preenchida
// Pós-condição: aplicação finalizada
void run_simulator(Machine machine);

// Valida uma palavra com uma maquina de turing
// Pré-condição: palavra e maquina
// Pós-condição: palavra validada
int validate_word(char * word, Machine machine);

// Libera espaçp alocado em um maquina
// Pré-condição: maquina
// Pós-condição: espaço liberado
void free_machine(Machine machine);

// Diz se um estado é final
// Pré-condição: estado e maquina de turing
// Pós-condição: diz se é estado final
int is_final_state(char * state, Machine machine);

// Inicia maquina
// Pré-condição: maquina alocada
// Pós-condição: maquina preenchida
void init_machine(Machine * machine);

// Encontra transição com em um estado e simbolo lido de uma maquina
// Pré-condição: estado, simbolo e maquina
// Pós-condição: transição retornada caso exista e NULL caso não exista
Transition * find_transition(char * curr_state, char symbol, Machine machine);

#endif //AFD_SIMULATOR_CONTROLLER_H
