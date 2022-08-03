#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"
#include "pokemon.h"
#include "parser.h"
#include "controller.h"
#include "LinkedList.h"

/* 1) Cargar archivo pokemones: Se pedir� el nombre del archivo csv y se cargar� en un
LinkedList los elementos del mismo.

2) Eliminar Pokemon: Se le pedir� al usuario el ingreso de un pokemon y se proceder� a
eliminarlo de la mochila. Una vez eliminado deber� mostrarlo por pantalla.

3) Imprimir Pokemones: Se imprimir� por pantalla la tabla con los datos de todos los
pokemones.

4) Filtrar de tipo Agua variocolor: Generar un listado en pantalla que solo incluya los
pokemones tipo Water shiny.

5) Mapear ataque cargado: Dado el tiempo atmosf�rico que favorece a ciertos pokemones,
realizaremos la modificaci�n del valor del ataque cargado seg�n el siguiente criterio:
Como el dia esta despejado, los pokemones de tipo Fire, Ground y Grass

aumentar�n su poder un 10%*/

int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	int flagLoadText = 0;

	LinkedList* listaPokemones = ll_newLinkedList();
	LinkedList* listaPokemonesAuxiliar = ll_newLinkedList();

	do{
		opcion = PedirEntero("================================================\n"
				"1- Cargar archivo pokemones.\n"
				"2- Eliminar Pokemon.\n"
				"3- Imprimir pokemones.\n"
				"4- Filtrar de tipo Agua variocolor.\n"
				"5- Mapear ataque cargado.\n"
				"6- Salir\n"
				"================================================\n","Error\n Vuelva a ingresar alguna de las opciones anteriores.",1,6);
		switch(opcion)
		{
		case 1:
			if(ll_isEmpty(listaPokemones) && flagLoadText == 0)
			{
					controller_loadFromText("C:\\Users\\PC\\Downloads\\Data_Pokemones.csv",listaPokemones);
					flagLoadText = 1;
					printf("Datos cargados con �xito!\n");
			}
		break;

		case 2:
			if(flagLoadText == 1)
			{
				controller_removePokemon(listaPokemones);
			}
			else
			{
				printf("No se carg� ning�n pokemon.\n");
			}
		break;

		case 3:
			if(flagLoadText == 1)
			{
				controller_ListPokemones(listaPokemones);
			}
			else
			{
				printf("No se carg� ning�n pokemon.\n");
			}
		break;

		case 4:
			if(flagLoadText == 1)
			{
				listaPokemonesAuxiliar = ll_filter(listaPokemones,Pokemon_FiltroWaterColor);
				controller_ListPokemones(listaPokemonesAuxiliar);
			}
			else
			{
				printf("No se carg� ning�n pokemon.\n");
			}
		break;

		case 5:
			if(flagLoadText == 1)
			{
				listaPokemones = ll_map(listaPokemones, Pokemon_MapAtaque);
				controller_ListPokemones(listaPokemones);
			}
			else
			{
				printf("No se carg� ning�n pokemon.\n");
			}
		break;
		}

	}while(opcion!=6);
}