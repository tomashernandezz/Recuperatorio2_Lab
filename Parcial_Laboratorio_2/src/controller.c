#include "parser.h"
#include "pokemon.h"
#include "controller.h"
#include "LinkedList.h"
#include "input.h"

int controller_loadFromText(char* path , LinkedList* listaPokemones)
{
	FILE* pArchivo;
	int validacion = 0;

	if(path != NULL && listaPokemones != NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo != NULL)
		{
			parser_PokemonFromText(pArchivo,listaPokemones);
			validacion = 1;
		}

		fclose(pArchivo);
	}

    return validacion;
}

int controller_removePokemon(LinkedList* listaPokemones)
{
	int tam;
	int id;
	int index;
	int retorno = 0;
	char respuesta;
	sPokemon* PasajeroAEliminar;

	if(listaPokemones != NULL)
		{
			tam = ll_len(listaPokemones);
			id = PedirEntero("Ingrese el numero del pokemon que desea eliminar: ","Error.\nIngrese el id del pasajero que desea eliminar: ",1,tam);
			index = Pokemon_findID(listaPokemones,id);

			PasajeroAEliminar = (sPokemon*)ll_get(listaPokemones,index);

			printf("¿Está seguro de eliminar este pokemon?\ns Si\nn No    ");
			scanf("%s",&respuesta);

			if(respuesta == 's')
			{
				Pokemon_delete(PasajeroAEliminar);
				ll_remove(listaPokemones,index);
				printf("Pokemon eliminado con éxito.\n");
				retorno = 1;
			}
			else
			{
				printf("Usted no ha eliminado al Pokemon.\n");
			}

		}
	return retorno;
}

int controller_ListPokemones(LinkedList* listaPokemones)
{
	int auxNumero;
	char auxNombre[51];
	char auxTipo[51];
	char auxTamanio[50];
	char auxAtaqueCargado[50];
	int auxValorAtaque;
	int auxVarioColor;
	sPokemon* auxPokemon = NULL;
	int retorno = 0;
	int len;

	if(listaPokemones!=NULL)
	{
		len = ll_len(listaPokemones);
		if(len > 0)
		{
			printf("|-----------------------------------------------------------------------------|\n");
			printf("|Nro |Nombre              |Tipo      |Tamaño |Atk Cargado    |Atk |Variocolor |\n");
			printf("|-----------------------------------------------------------------------------|\n");
			for(int i=0;i<len;i++)
			{
				auxPokemon = (sPokemon*)ll_get(listaPokemones,i);

				if(auxPokemon != NULL)
				{
					if(Pokemon_getters(auxPokemon, &auxNumero,auxNombre,auxTipo,auxTamanio,auxAtaqueCargado,&auxValorAtaque,&auxVarioColor)==1)
					{
						printf("|%-4d|%-20s|%-10s|%-7s|%-15s|%-4d|",auxNumero,auxNombre,auxTipo,auxTamanio,auxAtaqueCargado,auxValorAtaque);

						if(auxVarioColor == 1)
						{
							printf("%-11s|\n", "Si");
						}
						else
						{
							printf("%-11s|\n", "No");
						}
						retorno = 1;
					}
				}
			}

			printf("|-----------------------------------------------------------------------------|\n");
		}
	}

	return retorno;
}
