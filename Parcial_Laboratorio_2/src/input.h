#ifndef INPUT_H_
#define INPUT_H_

/// @brief Pide una cadena.
///
/// @param cadena Par�metro de la variable a la que se le asignar� la cadena
/// @param mensaje Mensaje para pedir la cadena
/// @param mensajeError Mensaje de error si la cadena pedida no es ingresada correctamente
/// @param validar Si es 1, validar� que se ingrese una cadena, sin n�meros, ni caracteres especiales,
/// si es 0, no se validar� y el usuario podr� ingresar cualquier tipo de variable.
/// @return Retorna si se asign� correctamente
int PedirCadena(char* cadena, char* mensaje, char* mensajeError,int validar);

/// @brief Valida la cadena seg�n lo que se haya ingresado en el �ltimo par�metro de la funci�n anterior
///
/// @param cadena Par�metro de la cadena que se quiere validar
/// @return Retorna si la validaci�n es correcta o no.
int ValidacionDeCaracteres (char cadena[]);

/// @brief Valida si lo que recibio en las funciones PedirFloat o PedirEntero es el tipo de variable correctamente.
///
/// @param numeros Numero que se quiere validar
/// @return Retorna si la validaci�n es correcta o no.
int ValidarNumero (char numeros[]);

/// @brief Pide un flotante.
///
/// @param mensaje Mensaje para pedir el flotante
/// @param error Mensaje de error para pedir el flotante
/// @param minimo M�nimo del flotante
/// @param maximo M�ximo del flotante
/// @return Retorna el flotante ingresado.
float PedirFloat(char mensaje[],char error[],int minimo,int maximo);

/// @brief Pide un entero.
///
/// @param mensaje Mensaje para pedir el entero
/// @param error Mensaje de error para pedir el entero
/// @param minimo M�nimo del entero
/// @param maximo M�ximo del entero
/// @return Retorna el entero ingresado.
int PedirEntero(char mensaje[],char error[],int minimo,int maximo);

/// @brief Pasa a may�scula la primera letra de una cadena
///
/// @param name Par�metro de la cadena a modificar.
void Mayuscula(char name []);

#endif /* INPUT_H_ */
