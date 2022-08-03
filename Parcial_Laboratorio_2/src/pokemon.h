#ifndef POKEMON_H_
#define POKEMON_H_
#include "LinkedList.h"

struct{
	int numero;
	char nombre[50];
	char tipo[50];
	char tamanio[50];
	char ataqueCargado[50];
	int valorAtaque;
	int varioColor;
}typedef sPokemon;

/// @brief Constructor genérico
///
/// @return Retorna el espacio de memoria de un pokemon.
sPokemon* Pokemon_new();

/// @brief Constructor parametrizado
///
/// @param numero Numero del pokemon
/// @param nombre Nombre del pokemon
/// @param tipo Tipo del pokemon
/// @param tamanio Tamaño del pokemon
/// @param ataqueCargado Ataque cargado del pokemon
/// @param valorAtaque Valor de ataque del pokemon
/// @param varioColor Color del pokemon
/// @return Retorna un pokemon
sPokemon* Pokemon_newParametros(char* numero, char* nombre, char* tipo, char* tamanio, char* ataqueCargado, char* valorAtaque, char* varioColor);

//SETTERS
/// @brief Asigna el número del pokemon
///
/// @param this Lista que se va a utilizar
/// @param numero
/// @return Retorna 1 si se asigno correctamente
int Pokemon_setNumero(sPokemon* this, int numero);

/// @brief Asigna el nombre del pokemon
///
/// @param this Lista que se va a utilizar
/// @param nombre
/// @return Retorna 1 si se asigno correctamente
int Pokemon_setNombre(sPokemon* this, char* nombre);

/// @brief Asigna el tipo del pokemon
///
/// @param this Lista que se va a utilizar
/// @param tipo
/// @return Retorna 1 si se asignó correctamente
int Pokemon_setTipo(sPokemon* this, char* tipo);

/// @brief Asigna el tamaño del pokemon
///
/// @param this Lista que se va a utilizar
/// @param tamanio
/// @return Retorna 1 si se asignó correctamente
int Pokemon_setTamanio(sPokemon* this, char* tamanio);

/// @brief Retorna el valor del ataque cargado del pokemon
///
/// @param this Lista que se va a utilizar
/// @param AtaqueCargado
/// @return Retorna 1 si se asignó correctamente
int Pokemon_setAtaqueCargado(sPokemon* this, char* AtaqueCargado);

/// @brief Asigna el valor de ataque del pokemon
///
/// @param this Lista que se va a utilizar
/// @param valorAtaque
/// @return Retorna 1 si se asignó correctamente
int Pokemon_setValorAtaque(sPokemon* this, int valorAtaque);

/// @brief Asigna el color del pokemon
///
/// @param this Lista que se va a utilizar
/// @param VarioColor
/// @return Retorna 1 si se asignó correctamente
int Pokemon_setVarioColor(sPokemon* this, int VarioColor);

//GETTERS
/// @brief Consigue el número del pokemon
///
/// @param this Lista que se va a utilizar
/// @param numero
/// @return Retorna 1 si se asignó correctamente
int Pokemon_getNumero(sPokemon* this, int* numero);

/// @brief Consigue el nombre del pokemon
///
/// @param this Lista que se va a utilizar
/// @param nombre
/// @return Retorna 1 si se asignó correctamente
int Pokemon_getNombre(sPokemon* this, char* nombre);

/// @brief Consigue el tipo del pokemon
///
/// @param this Lista que se va a utilizar
/// @param tipo
/// @return Retorna 1 si se asignó correctamente
int Pokemon_getTipo(sPokemon* this, char* tipo);

/// @brief Consigue el tamaño del pokemon
///
/// @param this Lista que se va a utilizar
/// @param tamanio
/// @return Retorna 1 si se asignó correctamente
int Pokemon_getTamanio(sPokemon* this, char* tamanio);

/// @brief Consigue el valor de ataque cargado del pokemon
///
/// @param this Lista que se va a utilizar
/// @param AtaqueCargado
/// @return Retorna 1 si se asignó correctamente
int Pokemon_getAtaqueCargado(sPokemon* this, char* AtaqueCargado);

/// @brief Consigue el valor de ataque del pokemon
///
/// @param this Lista que se va a utilizar
/// @param valorAtaque
/// @return Retorna 1 si se asignó correctamente
int Pokemon_getValorAtaque(sPokemon* this, int* valorAtaque);

/// @brief Consigue el color del pokemon
///
/// @param this Lista que se va a utilizar
/// @param VarioColor
/// @return Retorna 1 si se asignó correctamente
int Pokemon_getVarioColor(sPokemon* this, int* VarioColor);


/// @brief Carga el archivo para leer la ID
///
/// @param numero
void pokemonLoadTextId(int numero);

/// @brief Elimina un pokemon de la lista
///
/// @param this
void Pokemon_delete(sPokemon* this);

/// @brief Encuentra la ID de un pokemon, su lugar en la lista
///
/// @param listaPokemones
/// @param id Paramétro de la ID que se le va a pasar
/// @return Retorna el index del pokemon
int Pokemon_findID(LinkedList* listaPokemones, int id);

/// @brief Consigue todos los datos de un pokemon en una sola función
///
/// @param this
/// @param numero
/// @param nombre
/// @param tipo
/// @param tamanio
/// @param ataqueCargado
/// @param valorAtaque
/// @param varioColor
/// @return
int Pokemon_getters(sPokemon* this, int* numero, char* nombre, char* tipo, char* tamanio, char* ataqueCargado, int* valorAtaque, int* varioColor);

/// @brief Filtra todos los pokemones según el criterio que se le asigne, en este caso los de Agua
///
/// @param unPokemon
/// @return Retorna que se haya hecho correctamente
int Pokemon_FiltroWaterColor(void* unPokemon);

/// @brief Mapea los datos de un Pokemon
///
/// @param unPokemon Puntero a función de los pokemones que se van a modificar
void Pokemon_MapAtaque(void* unPokemon);
#endif
