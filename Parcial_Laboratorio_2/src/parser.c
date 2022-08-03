#include "parser.h"
#include "pokemon.h"
#include "controller.h"
#include "LinkedList.h"

int parser_PokemonFromText(FILE* pFile , LinkedList* listaPokemones)
{
	char auxNumero[20];
	char auxNombre[51];
	char auxTipo[51];
	char auxTamanio[50];
	char auxAtaqueCargado[50];
	char auxValorAtaque[50];
	char auxVarioColor[50];
	int retorno = 0;
	sPokemon* auxPokemon = NULL;

	if(pFile != NULL && listaPokemones != NULL)
	{
		do
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxNumero,auxNombre,auxTipo,auxTamanio,auxAtaqueCargado,auxValorAtaque,auxVarioColor);
			auxPokemon = Pokemon_newParametros(auxNumero,auxNombre,auxTipo,auxTamanio,auxAtaqueCargado,auxValorAtaque,auxVarioColor);
			if(auxPokemon != NULL)
			{
				ll_add(listaPokemones,auxPokemon);
				retorno = 1;
			}
		}while(!feof(pFile));
		pokemonLoadTextId(atoi(auxNumero));
	}

    return retorno;
}
