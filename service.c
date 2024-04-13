//
// Created by nikoly on 10/04/24.
//

#include "service.h"

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

// Pega os dados (estados/alfabeto) de uma cadeia de caracteres (linha)
// Pré-condição: linha, array a ser preenchido com os dados e tamanho do array a ser preenchido
// Pós-condição: dados extraídos da linha no array e tamanho do array preenchido
void getData(char *line, char **array, int *size) {
    char *start = strchr(line, '{');
    char *end = strchr(line, '}');
    *size = 0;

    if (start != NULL && end != NULL) {
        start++;  // Pular o '{'
        *end = '\0';  // Substituir '}' por '\0' para terminar a string no local certo

        char *token = strtok(start, ",");
        while (token != NULL) {
            if (strcmp(token, "")) { //se não é "" retorna verdadeiro
                array[*size] = strdup(token); // strdup cria uma cópia independente da string line
                (*size)++;
            }
            token = strtok(NULL, ",");
        }
    }
}

// Lê AFD de um arquivo
// Pré-condição: nome do arquivo e afd vazio
// Pós-condição: afd preenchido
void read_machine(const char * filename, Machine * machine) {
    FILE * file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LENGTH];

    while (fgets(line, MAX_LENGTH, file) != NULL) {
        int test;
        if(strstr(line, "Q=")) {
            sscanf(line, "Q=%d", &machine->states_size);
        }
        else if (strstr(line, "F={") != NULL) {
            getData(line, machine->final_states, &(machine->final_states_size));
        }

        else if (strstr(line, "alfabeto") != NULL) {
            getData(line, machine->alphabet, &(machine->alphabet_size));
        }
        else {
            // Linha de transição
            if (machine->transitions_size == 0) {
                machine->transitions = malloc(sizeof(Transition));
            } else {
                machine->transitions = realloc(machine->transitions, (machine->transitions_size + 1) * sizeof(Transition));
            }

            char current_state[MAX_STRING_LENGTH], next_state[MAX_STRING_LENGTH];
            char read_symbol, write_symbol, direction;
            sscanf(line, "(%[^,],%c)=(%[^,],%c,%c)", current_state, &read_symbol, next_state, &write_symbol, &direction);

            Transition t = machine->transitions[machine->transitions_size];
            t.current_state = strdup(current_state);
            t.read_symbol = read_symbol;
            t.next_state = strdup(next_state);
            t.write_symbol = write_symbol;
            t.direction = direction;
            machine->transitions[machine->transitions_size] = t;
            machine->transitions_size++;
        }
    }

    fclose(file);
}