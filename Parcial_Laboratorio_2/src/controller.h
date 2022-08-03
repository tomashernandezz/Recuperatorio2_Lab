#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"

/// @brief Carga el archivo que se va a utilizar.
///
/// @param path Par�metro de la ubicaci�n del archivo
/// @param listaPokemones Par�metro de la lista que se va a utilizar
/// @return Retorna 1 si se carg� el archivo correctamente
int controller_loadFromText(char* path , LinkedList* listaPokemones);

/// @brief Remueve alg�n pokemon de la lista
///
/// @param listaPokemones Lista que se va a utilizar
/// @return Retorna 1 si se elimin� correctamente el pokemon de la lista
int controller_removePokemon(LinkedList* listaPokemones);

/// @brief Muestra todos los pokemones
///
/// @param listaPokemones Lista que se va a utilizar
/// @return Retorna 1 si se cargaron todos los datos de los pokemones.
int controller_ListPokemones(LinkedList* listaPokemones);

#endif /* CONTROLLER_H_ */
