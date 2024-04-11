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
// Pré-condição: afd preenchido
// Pós-condição: aplicação finalizada
void run_simulator(Machine afd);

// Valida uma palavra com um Machine
// Pré-condição: palavra e afd
// Pós-condição: palavra validada
int validate_word(char * word, Machine afd);

// Libera espaçp alocado em um Machine
// Pré-condição: afd
// Pós-condição: espaço liberado
void free_afd(Machine afd);

// Diz se um estado é final
// Pré-condição: estado e afd
// Pós-condição: diz se é estado final
int is_final_state(char * state, Machine afd);

// Inicia Machine
// Pré-condição: afd alocado
// Pós-condição: afd preenchido
void init_afd(Machine * afd);

#endif //AFD_SIMULATOR_CONTROLLER_H
