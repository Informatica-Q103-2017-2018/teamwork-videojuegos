/*				Trabajo Final de Inform�tica
				Creadores:
					Javier Tudanca Vincueria
					Pablo L�pez Reyes
					�lvaro P�rez Garc�a
					Manuel Alejandro Taboada da Silva
*/

# include <stdio.h>

void tresenralla ();
void tresenrallaloop (char c [3][3]);
void comienzo();
void intro_primera (char c[3][3]);
void tablero (char c [3][3]);


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
			
			comienzo ();    					
				
			intro_primera (c);					

			do {
				system ("cls");					//Esto borra todo lo que hay en pantalla ("clear")
				tablero (c);					
		
				if ( i % 2 == 0) {
					jugador1(c);				
				}
		
				else {
					intro_IA (c);				//Creacion funcion intro_IA    "inteligencia artificial"  juega la maquina
				}
		
				j = ganador (c);				//Creacion funcion ganador
				i++;
		
			} while ( i <= 9 && j == 2);
				
			system ("cls");				
			tablero (c);
		
			if ( j == 0){
				printf ("Enhorabuena!! Han Ganado las X !!!\n\n");
			}
	
			else if ( j == 1 ){
				printf ("Enhorabuena!! Han Ganado las O !!!\n\n");
			}
		
			else {
				printf ("Habeis empetado!! Intentalo de nuevo!!\n\n");
			}
			
			printf ("Presione 1 para comenzar otra partida, cualquier otro para terminar: ");
			scanf ("%i", &k);
			
		} while ( k == 1);
	}
	
	printf ("\n\nEl Juego ha terminado\n\n");

	// if(n == 2)    hacer luego
	
}

void intro_primera (char c[3][3]) {
	
	int i, j;
	char aux;
	
	aux = '1';
	
	for ( i = 0; i < 3; i++) {
		for ( j = 0; j < 3; j++) {
			c[i][j] = aux++;
		}
	}
}


void tablero (char c [3][3]) {
	
	int i, j;
	
	printf ("\n");
	
	for ( i = 0; i < 3; i++) {
		for ( j = 0; j < 3; j++) {
			
			if ( j < 1 ){
				printf ("\t\t\t\t\t\t\t");
			}
			
			if ( j < 2 ){
				printf (" %c |", c[i][j]);
			}
			
			else {
				printf (" %c ", c[i][j]);
			}
		}
		
		if ( i < 2 ) {
			printf ("\n\t\t\t\t\t\t\t-----------\n");
		}
		
		else {
			printf ("\n\n");
		}
	}
}

void comienzo() {
	
	char campo[V][H];
	int i, j, k;
	int posicion[2];
	
	posicion [1] = 2;
	posicion [0] = 39;

	for ( k = 3; k > 0; k--){
	
		system ("cls"); 
		for ( i = 0; i < V; i++) {
			for ( j = 0; j < H; j++) {
				campo[i][j] = ' ';
			}
		} 
		
		// Cuenta atr�s  
		
		drawnumber ( campo, posicion, k); 			//Crear funcion drawnumber
		
		for ( i = 0; i < V; i++) {
			for ( j = 0; j < H ; j++) {
				printf ("%c", campo[i][j]);
			}
			printf ("\n");
		}
		
			Sleep ( 1000 );			
	
	}
	
}


