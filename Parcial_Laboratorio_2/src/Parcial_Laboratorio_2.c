#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"
#include "pokemon.h"
#include "parser.h"
#include "controller.h"
#include "LinkedList.h"

/* 1) Cargar archivo pokemones: Se pedirá el nombre del archivo csv y se cargará en un
LinkedList los elementos del mismo.

2) Eliminar Pokemon: Se le pedirá al usuario el ingreso de un pokemon y se procederá a
eliminarlo de la mochila. Una vez eliminado deberá mostrarlo por pantalla.

3) Imprimir Pokemones: Se imprimirá por pantalla la tabla con los datos de todos los
pokemones.

4) Filtrar de tipo Agua variocolor: Generar un listado en pantalla que solo incluya los
pokemones tipo Water shiny.

5) Mapear ataque cargado: Dado el tiempo atmosférico que favorece a ciertos pokemones,
realizaremos la modificación del valor del ataque cargado según el siguiente criterio:
Como el dia esta despejado, los pokemones de tipo Fire, Ground y Grass

aumentarán su poder un 10%*/

int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	int flagLoadText = 0;
	int flagMap1 = 0;
	int flagMap2 = 0;

	LinkedList* listaPokemones = ll_newLinkedList();
	LinkedList* listaPokemonesAuxiliar = ll_newLinkedList();

	do{
		opcion = PedirEntero("================================================\n"
				"1- Cargar archivo pokemones.\n"
				"2- Eliminar Pokemon.\n"
				"3- Imprimir pokemones.\n"
				"4- Filtrar de tipo Agua variocolor.\n"
				"5- Mapear ataque cargado.\n"
				"6- Mapear Bug, Fire y Grass.\n"
				"7- Batalla pokemon.\n"
				"8- Salir\n"
				"================================================\n","Error.\nVuelva a ingresar alguna de las opciones anteriores.",1,8);
		switch(opcion)
		{
		case 1:
			if(ll_isEmpty(listaPokemones) && flagLoadText == 0)
			{
					Hernandez_controller_loadFromText("src/Data_Pokemones.csv",listaPokemones);
					flagLoadText = 1;
					printf("Datos cargados con éxito!\n");
			}
		break;

		case 2:
			if(flagLoadText == 1)
			{
				Hernandez_controller_ListPokemones(listaPokemones);
				Hernandez_controller_removePokemon(listaPokemones);
			}
			else
			{
				printf("No se cargó ningún pokemon.\n");
			}
		break;

		case 3:
			if(flagLoadText == 1)
			{
				Hernandez_controller_ListPokemones(listaPokemones);
			}
			else
			{
				printf("No se cargó ningún pokemon.\n");
			}
		break;

		case 4:
			if(flagLoadText == 1)
			{
				listaPokemonesAuxiliar = ll_filter(listaPokemones,Pokemon_FiltroWaterColor);
				Hernandez_controller_ListPokemones(listaPokemonesAuxiliar);
			}
			else
			{
				printf("No se cargó ningún pokemon.\n");
			}
		break;

		case 5:
			if(flagLoadText == 1)
			{
				if(flagMap1==0)
				{
					flagMap1 = 1;
					listaPokemones = ll_map(listaPokemones, Pokemon_MapAtaque);
					Hernandez_controller_ListPokemones(listaPokemones);
					printf("Ataque mejorado!\n");
				}
				else
				{
					printf("Ya se mapearon.\n");
				}
			}
			else
			{
				printf("No se cargó ningun pokemon.\n");
			}
		break;

		case 6:
			if(flagLoadText == 1)
			{
				if(flagMap2==0)
				{
				flagMap2 = 1;
				listaPokemones = ll_map(listaPokemones, Pokemon_MapAtaque2);
				Hernandez_controller_ListPokemones(listaPokemones);
				printf("Ataque mejorado!\n");
				}
				else
				{
					printf("Ya se mapearon.\n");
				}
			}
			else
			{
				printf("No se cargó ningún pokemon.\n");
			}
		break;

		case 7:
			if(flagLoadText == 1)
			{
				Hernandez_controller_Count(listaPokemones);
			}
			else
			{
				printf("No se cargó ningún pokemon.\n");
			}
		break;
		}

	}while(opcion!=8);
}
