/*Fecha de creación: 04 de Febrero de 2019
Creador: Guillermo Naranjo Ferrara
Descripción: Obtiene el inverso multiplicativo de un número con base en el algoritmo extendido de Euclides 
*/

/*Función que recibe como parámetros
	z: dividendo
	a: divisor
	Tome en cuenta que se trabajará con operaciones del tipo "dividendo/divisor" y "divisor mod dividendo"
*/
int inverse(int z, int a);

//Función que retorna el gcd de dos números
int gcd(int a, int b);

//Función recursiva que calcula el inverso multiplicativo del número a de la función "inverse"
int extendedAlgorithm(int **ecuaciones, int numEc);