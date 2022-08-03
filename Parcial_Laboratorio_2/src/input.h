#ifndef INPUT_H_
#define INPUT_H_

/// @brief Pide una cadena.
///
/// @param cadena Parámetro de la variable a la que se le asignará la cadena
/// @param mensaje Mensaje para pedir la cadena
/// @param mensajeError Mensaje de error si la cadena pedida no es ingresada correctamente
/// @param validar Si es 1, validará que se ingrese una cadena, sin números, ni caracteres especiales,
/// si es 0, no se validará y el usuario podrá ingresar cualquier tipo de variable.
/// @return Retorna si se asignó correctamente
int PedirCadena(char* cadena, char* mensaje, char* mensajeError,int validar);

/// @brief Valida la cadena según lo que se haya ingresado en el último parámetro de la función anterior
///
/// @param cadena Parámetro de la cadena que se quiere validar
/// @return Retorna si la validación es correcta o no.
int ValidacionDeCaracteres (char cadena[]);

/// @brief Valida si lo que recibio en las funciones PedirFloat o PedirEntero es el tipo de variable correctamente.
///
/// @param numeros Numero que se quiere validar
/// @return Retorna si la validación es correcta o no.
int ValidarNumero (char numeros[]);

/// @brief Pide un flotante.
///
/// @param mensaje Mensaje para pedir el flotante
/// @param error Mensaje de error para pedir el flotante
/// @param minimo Mínimo del flotante
/// @param maximo Máximo del flotante
/// @return Retorna el flotante ingresado.
float PedirFloat(char mensaje[],char error[],int minimo,int maximo);

/// @brief Pide un entero.
///
/// @param mensaje Mensaje para pedir el entero
/// @param error Mensaje de error para pedir el entero
/// @param minimo Mínimo del entero
/// @param maximo Máximo del entero
/// @return Retorna el entero ingresado.
int PedirEntero(char mensaje[],char error[],int minimo,int maximo);

/// @brief Pasa a mayúscula la primera letra de una cadena
///
/// @param name Parámetro de la cadena a modificar.
void Mayuscula(char name []);

#endif /* INPUT_H_ */
