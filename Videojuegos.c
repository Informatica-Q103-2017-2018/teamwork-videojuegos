/*				Trabajo Final de Informática
				Creadores:
					Javier Tudanca Vincueria
					Pablo López Reyes
					Álvaro Pérez García
					Manuel Alejandro Taboada da Silva
*/

# include <stdio.h>

void tresenralla ();

void tresenrallaloop (char c [3][3]);

int main(){
	
	int k, power;
	
	power = 1;
	do {
		do {
			system("cls");
			printf ("\n\n\t\t  LOS JUEGOS MAS CLASICOS !!!!");
			printf ("\n\n\n Menu:\n\n	[1]: Tres en Ralla\n	[2]: Snake\n	[3]: Epic Pong\n	[4]: Salir del Juego");
			printf ("\n\n Selecciona una Modalidad de Juego: "); 
			scanf ("%i", &k);
		}while ( k < 1 || k > 4);
	
	switch ( k ){
		case 1: tresenralla (); break;
		case 2: snake (); break;
		case 3: pong (); break;
		case 4: power = 0; break;
		}
	}while ( power == 1);
	return 0;

}

void tresenralla() {
	
	char c [3][3];
		
	tresenrallaloop (c);		//Llama a todas las funciones elementales y hace un refresco de pantalla
	
}

void tresenrallaloop (char c [3][3]){
	
	int n, i, j, k;
	
	do{
		system ("cls");
		
		printf("\n\t\t\tTRES EN RALLA!!!!");
		printf ("\nMenu:");
		printf ("\n\n [1] Contra la maquina ");
		printf ("\n [2] Dos Jugadores ");
		
		printf ("\n\nSelecciona un Modalidad de Juego: ");
		scanf ("%i", &n);
		
	} while ( n != 1 && n !=2);

	if ( n == 1 ) {
		do {
	
			i = 0;
			
			comienzo ();    					//Creacion funcion comienzo
				
			intro_primera (c);					//Creacion funcion intro_primera

			do {
				system ("cls");					//Esto borra todo lo que hay en pantalla ("clear")
				tablero (c);					//Creacion funcion tablero
		
				if ( i % 2 == 0) {
					jugador1(c);				//Creacion funcion jugador1
				}
		
				else {
					intro_IA (c);				//Creacion funcion intro_IA    "inteligencia artificial"  juega la maquina
				}
		
				j = ganador (c);				//Creacion funcion ganador
				i++;
		
			} while ( i <= 9 && j == 2);
		}
	}	
}


