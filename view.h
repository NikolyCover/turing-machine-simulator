//
// Created by nikoly on 10/04/24.
//

#ifndef TURING_MACHINE_SIMULATOR_VIEW_H
#define TURING_MACHINE_SIMULATOR_VIEW_H

#include "model.h"
#include <stdio.h>

// Mostra todas as informações de uma maquina de turing
// Pré-condição: estrutura do tipo maquina de turing preenchida
// Pós-condição: informações mostradas no terminal
void show_machine(Machine machine);

// Pega uma palavra digitada pelo usuário
// Pré-condição: ponteiro de char
// Pós-condição: ponteiro de char preenchido com o que o usuário digitou
void input_word(char * word);

// Mostra um divisor
// Pré-condição: nenhuma
// Pós-condição: um divisor é mostrado no terminal
void print_divider();

// Mostra REJEITA caso result seja 0 e ACEITA caso seja 1
// Pré-condição: número de resultado (1 ou 0)
// Pós-condição: resultado é mostrado
void show_result(int result);

// Mostra uma mensagem em verde
// Pré-condição: mensagem
// Pós-condição: mensagem é mostrada
void show_green_message(char * message);

// Mostra uma mensagem em vermelho
// Pré-condição: mensagem
// Pós-condição: mensagem é mostrada
void show_red_message(char * message);

// Mostra um passo do processamento da mensagem
// Pré-condição: fita, cabeça da fita e estado atual
// Pós-condição: passo mostrado
void show_processing_step(char * tape, int tape_indicator, char *curr_state);

// Mostra cabeçalho do processamento
// Pré-condição: palavra
// Pós-condição: cabeçalho é mostrado
void show_processing_header(char * word);

// Pega o nome do arquivo do usuário
// Pré-condição: ponteiro de char
// Pós-condição: ponteiro de char preenchido com o que o usuário digitou
void input_filename(char * filename);

#endif //TURING_MACHINE_SIMULATOR_VIEW_H
