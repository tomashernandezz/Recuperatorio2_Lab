#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pokemon.h"


sPokemon* Pokemon_new()
{
	sPokemon* UnPokemon= NULL;

	UnPokemon = (sPokemon*) malloc(sizeof(sPokemon)*1);

	return UnPokemon;
}

sPokemon* Pokemon_newParametros(char* numero, char* nombre, char* tipo, char* tamanio, char* ataqueCargado, char* valorAtaque, char* varioColor)
{
	sPokemon* UnPokemon= NULL;

	UnPokemon = Pokemon_new();

	if(UnPokemon != NULL && numero != NULL && nombre != NULL && tipo != NULL && tamanio != NULL && ataqueCargado != NULL && valorAtaque != NULL && varioColor != NULL)
	{
		Pokemon_setNumero(UnPokemon,atoi(numero));
		Pokemon_setNombre(UnPokemon,nombre);
		Pokemon_setTipo(UnPokemon,tipo);
		Pokemon_setTamanio(UnPokemon,tamanio);
		Pokemon_setAtaqueCargado(UnPokemon,ataqueCargado);
		Pokemon_setValorAtaque(UnPokemon,atoi(valorAtaque));
		Pokemon_setVarioColor(UnPokemon,atoi(varioColor));
	}

	return UnPokemon;
}

int Pokemon_setNumero(sPokemon* this, int numero)
{
	int retorno = 0;

	if(this != NULL)
	{
		this->numero = numero;
		retorno = 1;
	}
	return retorno;
}

int Pokemon_setNombre(sPokemon* this, char* nombre)
{
	int retorno = 0;

	if(this != NULL)
	{
		strcpy(this->nombre,nombre);
		retorno = 1;
	}
	return retorno;
}

int Pokemon_setTipo(sPokemon* this, char* tipo)
{
	int retorno = 0;

	if(this != NULL)
	{
		strcpy(this->tipo,tipo);
		retorno = 1;
	}
	return retorno;
}

int Pokemon_setTamanio(sPokemon* this, char* tamanio)
{
	int retorno = 0;

	if(this != NULL)
	{
		strcpy(this->tamanio,tamanio);
		retorno = 1;
	}
	return retorno;
}

int Pokemon_setAtaqueCargado(sPokemon* this, char* AtaqueCargado)
{
	int retorno = 0;

	if(this != NULL)
	{
		strcpy(this->ataqueCargado,AtaqueCargado);
		retorno = 1;
	}
	return retorno;
}

int Pokemon_setValorAtaque(sPokemon* this, int valorAtaque)
{
	int retorno = 0;

	if(this != NULL)
	{
		this->valorAtaque = valorAtaque;
		retorno = 1;
	}
	return retorno;
}

int Pokemon_setVarioColor(sPokemon* this, int VarioColor)
{
	int retorno = 0;

	if(this != NULL)
	{
		this->varioColor = VarioColor;
		retorno = 1;
	}
	return retorno;
}

void pokemonLoadTextId(int numero)
{
	FILE* pArchivo;

	pArchivo = fopen("Data_Pokemones.csv","w");

	if(pArchivo!=NULL)
	{
		fprintf(pArchivo,"%d\n",numero);
	}

	fclose(pArchivo);
}

void Pokemon_delete(sPokemon* this)
{
	if(this!=NULL)
		{
			free(this);
			this=NULL;
		}
}

int Pokemon_findID(LinkedList* listaPokemones, int id)
{
	int i;
	int len;
	int index;
	sPokemon* auxiliar;

	if(listaPokemones!=NULL)
	{
		len = ll_len(listaPokemones);

		if(len>0)
		{
			for(i=0; i<len ;i++)
			{
				auxiliar = (sPokemon*)ll_get(listaPokemones,i);
				if(auxiliar->numero==id)
				{
					index=i;
					break;
				}
			}
		}
	}

	return index;
}

int Pokemon_getNumero(sPokemon* this,int* numero)
{
	int retorno = 0;
	if(this!=NULL && numero != NULL)
	{
		*numero = this->numero;
		retorno = 1;
	}
	return retorno;
}

int Pokemon_getNombre(sPokemon* this, char* nombre)
{
	int retorno = 0;
	if(this!=NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = 1;
	}
	return retorno;
}

int Pokemon_getTipo(sPokemon* this, char* tipo)
{
	int retorno = 0;
	if(this!=NULL && tipo != NULL)
	{
		strcpy(tipo,this->tipo);
		retorno = 1;
	}
	return retorno;
}

int Pokemon_getTamanio(sPokemon* this, char* tamanio)
{
	int retorno = 0;
	if(this!=NULL && tamanio != NULL)
	{
		strcpy(tamanio,this->tamanio);
		retorno = 1;
	}
	return retorno;
}

int Pokemon_getAtaqueCargado(sPokemon* this, char* ataqueCargado)
{
	int retorno = 0;
	if(this!=NULL && ataqueCargado != NULL)
	{
		strcpy(ataqueCargado,this->ataqueCargado);
		retorno = 1;
	}
	return retorno;
}

int Pokemon_getValorAtaque(sPokemon* this, int* valorAtaque)
{
	int retorno = 0;
	if(this!=NULL && valorAtaque != NULL)
	{
		*valorAtaque = this->valorAtaque;
		retorno = 1;
	}
	return retorno;
}

int Pokemon_getVarioColor(sPokemon* this, int* VarioColor)
{
	int retorno = 0;
	if(this!=NULL && VarioColor != NULL)
	{
		*VarioColor = this->varioColor;
		retorno = 1;
	}
	return retorno;
}

int Pokemon_getters(sPokemon* this, int* numero, char* nombre, char* tipo, char* tamanio, char* ataqueCargado, int* valorAtaque, int* varioColor)
{
	int retorno = 0;
	if(Pokemon_getNumero(this,numero)==1 &&
	Pokemon_getNombre(this,nombre)==1 &&
	Pokemon_getTipo(this,tipo)==1 &&
	Pokemon_getTamanio(this,tamanio) == 1 &&
	Pokemon_getAtaqueCargado(this,ataqueCargado)==1 &&
	Pokemon_getValorAtaque(this,valorAtaque)==1 &&
	Pokemon_getVarioColor(this,varioColor)==1)
	{
		retorno = 1;
	}
	return retorno;
}

int Pokemon_FiltroWaterColor(void* unPokemon)
{
	int validacion = 0;
	int esVariocolor;
	char tipo[50];

	Pokemon_getVarioColor(unPokemon, &esVariocolor);
	Pokemon_getTipo(unPokemon, tipo);

	if((strcmp(tipo, "Water") == 0) && (esVariocolor == 1))
	{
		validacion = 1;
	}

	return validacion;
}

void Pokemon_MapAtaque(void* unPokemon)
{
	char tipo[50];
	int valorAtaque;
	int MapAtaque;

	Pokemon_getTipo(unPokemon, tipo);
	Pokemon_getValorAtaque(unPokemon, &valorAtaque);

	if((strcmp(tipo, "Ground") == 0) || (strcmp(tipo, "Fire") == 0) || (strcmp(tipo, "Grass") == 0))
	{
		MapAtaque = valorAtaque*10/100;
		valorAtaque = valorAtaque + MapAtaque;

		Pokemon_setValorAtaque(unPokemon, valorAtaque);
	}
}

void Pokemon_MapAtaque2(void* unPokemon)
{
	char tipo[50];
	char tamanio[50];
	int valorAtaque;
	int MapAtaque;

	Pokemon_getTipo(unPokemon, tipo);
	Pokemon_getTamanio(unPokemon,tamanio);
	Pokemon_getValorAtaque(unPokemon, &valorAtaque);

	if((strcmp(tipo, "Bug") == 0) || (strcmp(tipo, "Fire") == 0) || (strcmp(tipo, "Grass") == 0))
	{
		if(strcmp(tamanio,"XL") == 0)
		{
			MapAtaque = valorAtaque*20/100;
			valorAtaque = valorAtaque + MapAtaque;
		}
		else
		{
			if(strcmp(tamanio,"L") == 0)
			{
				MapAtaque = valorAtaque*10/100;
				valorAtaque = valorAtaque + MapAtaque;
			}
			else
			{
				MapAtaque = valorAtaque*5/100;
				valorAtaque = valorAtaque + MapAtaque;
			}
		}

		Pokemon_setValorAtaque(unPokemon, valorAtaque);
	}
}

int Pokemon_Cont(void* UnPokemon)
{
	char tipo[50];
	char tamanio[50];
	char atqCargado[50];
	int valorAtaque;
	char nombrePokemon[50];
	int rtrn = 0;

	Pokemon_getTipo(UnPokemon, tipo);
	Pokemon_getTamanio(UnPokemon,tamanio);
	Pokemon_getAtaqueCargado(UnPokemon,atqCargado);
	Pokemon_getValorAtaque(UnPokemon, &valorAtaque);

	if(((strcmp(tipo,"Fire") == 0)&& ((strcmp(tamanio,"XL") == 0) && (strcmp(atqCargado,"Lanzallamas")==0)) && (valorAtaque>80))
	||((strcmp(tipo,"Water") == 0) && ((strcmp(tamanio,"L") == 0) && (strcmp(atqCargado,"Hidrobomba")==0)) && (valorAtaque>80)))
	{
		Pokemon_getNombre(UnPokemon,nombrePokemon);
		printf("%s\n",nombrePokemon);
		rtrn = 1;
	}

	return rtrn;
}
