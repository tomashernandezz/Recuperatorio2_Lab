#ifndef PARSER_H_
#define PARSER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"

/// @brief Lee los datos de un pokemon
///
/// @param pFile Archivo csv de pokemones
/// @param listaPokemones Lista que se va a utilizar
/// @return Retorna 1 si se hizo correctamente
int parser_PokemonFromText(FILE* pFile , LinkedList* listaPokemones);

#endif /* PARSER_H_ */
