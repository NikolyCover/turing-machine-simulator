//
// Created by nikoly on 10/04/24.
//

#ifndef TURING_MACHINE_SIMULATOR_SERVICE_H
#define TURING_MACHINE_SIMULATOR_SERVICE_H

#include "model.h"

// Pega os dados (estados/alfabeto) de uma cadeia de caracteres (linha)
// Pré-condição: linha, array a ser preenchido com os dados e tamanho do array a ser preenchido
// Pós-condição: dados extraídos da linha no array e tamanho do array preenchido
void getData(char *line, char **array, int *size);

// Lê AFD de um arquivo
// Pré-condição: nome do arquivo e afd vazio
// Pós-condição: afd preenchido
void read_machine(const char * filename, Machine * machine);

#endif //TURING_MACHINE_SIMULATOR_SERVICE_H
