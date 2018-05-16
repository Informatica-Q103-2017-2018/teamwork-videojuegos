/*				Trabajo Final de Informática
				Creadores:
					Javier Tudanca Vincueria
					Pablo López Reyes
					Álvaro Pérez García
					Manuel Alejandro Taboada da Silva
*/

# include <stdio.h>
# include <windows.h>
# include <time.h>

//PROTOTIPOS FUNCIONES TRES EN RAYA
void tresenralla ();
void tresenrallaloop (char c [3][3]);
void comienzo();
void intro_primera (char c[3][3]);
void tablero (char c [3][3]);
void intro_IA (char c [3][3]);
void jugador1 ( char c [3][3]);
void jugador2 ( char c [3][3]);
int ganador ( char c[3][3]);
//FIN DE PROTOTIPOS FUNCIONES TRES EN RAYA

//PROTOTIPOS FUNCIONES PONG
void pong ();
void ponginicio (char campo[V][H], int pelX, int pelY, int inijug, int finjug, int iniia, int finia);
void pongborde ( char campo [V][H], int gol1, int gol2 );
void raqjug ( char campo[V][H], int inijug, int finjug);
void raqjug2 ( char campo[V][H], int inijug2, int finjug2);
void pel ( char campo[V][H], int pelX, int pelY);
void draw ( char campo[V][H]);
void ponginput ( char campo[V][H],  int *pelX, int *pelY, int *inijug, int *finjug, int *iniia, int *finia,int *modX,int *modY,int *modia, int *gol1, int *gol2, int *k);

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
					intro_IA (c);				//"inteligencia artificial"  juega la maquina
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

	if ( n == 2) {
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
					jugador2(c);
				}
			
				j = ganador (c);
				i++;
			
			} while ( i < 9 && j == 2);
	
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
		
		// Cuenta atrás  
		
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
void jugador1 ( char c [3][3]) {
	
	int i, j, k;
	char aux;
	
	do {
		do {
			printf ("Coloca una ficha: ");
			fflush (stdin);
			scanf ("%c", &aux);
		} while ( aux < '1' || aux > '9' );
		
		k = 0;
		
		switch (aux) {
			case '1': {
				i = 0;
				j = 0; 
				if ( c[i][j] == 'X' || c[i][j] == 'O'){
					k = 1;
					printf ("La casilla esta ocupada! Intentalo con otro numero!!\n\n");
				}
				break;}
				
			case '2': {
				i = 0;
				j = 1; 
				if ( c[i][j] == 'X' || c[i][j] == 'O'){
					k = 1;
					printf ("La casilla esta ocupada! Intentalo con otro numero!!\n\n");
				}
				break;}
				
			case '3': {
				i = 0;
				j = 2; 
				if ( c[i][j] == 'X' || c[i][j] == 'O'){
					k = 1;
					printf ("La casilla esta ocupada! Intentalo con otro numero!!\n\n");
				}
				break;}
				
			case '4': {
				i = 1;
				j = 0; 
				if ( c[i][j] == 'X' || c[i][j] == 'O'){
					k = 1;
					printf ("La casilla esta ocupada! Intentalo con otro numero!!\n\n");
				}
				break;}
				
			case '5': {
				i = 1;
				j = 1; 
				if ( c[i][j] == 'X' || c[i][j] == 'O'){
					k = 1;
					printf ("La casilla esta ocupada! Intentalo con otro numero!!\n\n");
				}
				break;}
				
			case '6': {
				i = 1;
				j = 2; 
				if ( c[i][j] == 'X' || c[i][j] == 'O'){
					k = 1;
					printf ("La casilla esta ocupada! Intentalo con otro numero!!\n\n");
				}
				break;}
				
			case '7': {
				i = 2;
				j = 0; 
				if ( c[i][j] == 'X' || c[i][j] == 'O'){
					k = 1;
					printf ("La casilla esta ocupada! Intentalo con otro numero!!\n\n");
				}
				break;}
				
			case '8': {
				i = 2;
				j = 1; 
				if ( c[i][j] == 'X' || c[i][j] == 'O'){
					k = 1;
					printf ("La casilla esta ocupada! Intentalo con otro numero!!\n\n");
				}
				break;}
				
			case '9': {
				i = 2;
				j = 2; 
				if ( c[i][j] == 'X' || c[i][j] == 'O'){
					k = 1;
					printf ("La casilla esta ocupada! Intentalo con otro numero!!\n\n");
				}
				break;}
			
		}
	} while ( k == 1 );
	
	c[i][j] = 'X';
}

void jugador2 ( char c [3][3]) {
	
	int i, j, k;
	char aux;
	
	do {
		do {
			printf ("Coloca una ficha: ");
			fflush (stdin);
			scanf ("%c", &aux);
		} while ( aux < '1' || aux > '9' );
		
		k = 0;
		
		switch (aux) {
			case '1': {
				i = 0;
				j = 0; 
				if ( c[i][j] == 'X' || c[i][j] == 'O'){
					k = 1;
					printf ("La casilla esta ocupada! Intentalo con otro numero!!\n\n");
				}
				break;}
				
			case '2': {
				i = 0;
				j = 1; 
				if ( c[i][j] == 'X' || c[i][j] == 'O'){
					k = 1;
					printf ("La casilla esta ocupada! Intentalo con otro numero!!\n\n");
				}
				break;}
				
			case '3': {
				i = 0;
				j = 2; 
				if ( c[i][j] == 'X' || c[i][j] == 'O'){
					k = 1;
					printf ("La casilla esta ocupada! Intentalo con otro numero!!\n\n");
				}
				break;}
				
			case '4': {
				i = 1;
				j = 0; 
				if ( c[i][j] == 'X' || c[i][j] == 'O'){
					k = 1;
					printf ("La casilla esta ocupada! Intentalo con otro numero!!\n\n");
				}
				break;}
				
			case '5': {
				i = 1;
				j = 1; 
				if ( c[i][j] == 'X' || c[i][j] == 'O'){
					k = 1;
					printf ("La casilla esta ocupada! Intentalo con otro numero!!\n\n");
				}
				break;}
				
			case '6': {
				i = 1;
				j = 2; 
				if ( c[i][j] == 'X' || c[i][j] == 'O'){
					k = 1;
					printf ("La casilla esta ocupada! Intentalo con otro numero!!\n\n");
				}
				break;}
				
			case '7': {
				i = 2;
				j = 0; 
				if ( c[i][j] == 'X' || c[i][j] == 'O'){
					k = 1;
					printf ("La casilla esta ocupada! Intentalo con otro numero!!\n\n");
				}
				break;}
				
			case '8': {
				i = 2;
				j = 1; 
				if ( c[i][j] == 'X' || c[i][j] == 'O'){
					k = 1;
					printf ("La casilla esta ocupada! Intentalo con otro numero!!\n\n");
				}
				break;}
				
			case '9': {
				i = 2;
				j = 2; 
				if ( c[i][j] == 'X' || c[i][j] == 'O'){
					k = 1;
					printf ("La casilla esta ocupada! Intentalo con otro numero!!\n\n");
				}
				break;}
			
		}
	} while ( k == 1 );
	
	c[i][j] = 'O';
}


void intro_IA (char c [3][3]) {
	
	int i, j, k;
	
	srand (time(NULL));
	
	do {
		
		i = rand() % 3;
		j = rand () % 3;
		k = 0;
		
		if ( c[i][j] == 'X' || c[i][j] == 'O') {
			k = 1;
		}
	} while (k == 1);
	
	c[i][j] = 'O';

}

int ganador ( char c[3][3]) {
	
	if (c[0][0] == 'X' || c[0][0] == 'O') {
		if (c[0][0] == c[0][1] && c[0][0] == c[0][2]){					//Comprueba si hay linea en la primera fila
			if (c[0][0] == 'X'){
				return 0; //He ganado 	
			}
			
			else {
				return 1; // He perdido
			}
		}
		if (c[0][0] == c[1][0] && c[0][0] == c[2][0]){					//Comprueba si hay linea en la primera columna
			if (c[0][0] == 'X'){
				return 0; //He ganado 	
			}
			
			else {
				return 1; // He perdido
			}
		}
	}
	
	if (c[1][1] == 'X' || c[1][1] == 'O') {
		if (c[1][1] == c[0][0] && c[1][1] == c[2][2]){					//Comprueba si hay linea en la primera diagonal
			if (c[1][1] == 'X'){
				return 0; //He ganado 	
			}
			
			else {
				return 1; // He perdido
			}
		}
		if (c[1][1] == c[1][0] && c[1][1] == c[1][2]){					//Comprueba si hay linea en la segunda fila
			if (c[1][1] == 'X'){
				return 0; //He ganado 	
			}
			
			else {
				return 1; // He perdido
			}
		}
		if (c[1][1] == c[2][0] && c[1][1] == c[0][2]){					//Comprueba si hay linea en la segunda diagonal
			if (c[1][1] == 'X'){
				return 0; //He ganado 	
			}
			
			else {
				return 1; // He perdido
			}
		}
		if (c[1][1] == c[0][1] && c[1][1] == c[2][1]){					//Comprueba si hay linea en la segunda columna
			if (c[1][1] == 'X'){
				return 0; //He ganado 	
			}
			
			else {
				return 1; // He perdido
			}
		}
	}
	
	if (c[2][2] == 'X' || c[2][2] == 'O') {
		if (c[2][2] == c[2][0] && c[2][2] == c[2][1]){					//Comprueba si hay linea en la tercera fila
			if (c[2][2] == 'X'){
				return 0; //He ganado 	
			}
			
			else {
				return 1; // He perdido
			}
		}
		if (c[2][2] == c[0][2] && c[2][2] == c[1][2]){					//Comprueba si hay linea en la tercera columna
			if (c[2][2] == 'X'){
				return 0; //He ganado 	
			}
			
			else {
				return 1; // He perdido
			}
		}
	}
	return 2;
}

//JUEGO DEL PONG

void pong () {
	
	int pelX, pelY, inijug, finjug, iniia, finia, inijug2, finjug2, n, k;
	int modX, modY, modia;
	char campo [V][H];
	
	//Varaibles de Posición
	pelX = 37;
	pelY = 10;
	
	inijug = 8;
	finjug = 12;
	
	inijug2 = 8;
	finjug2 = 12;
	
	iniia = 3;
	finia = 17;
	
	//Varaiables de Modificación
	
	modX = 1;
	modY = 1;
	modia = -1;
	
	n = menu();
	
	if ( n == 1 ) {
	do {
		system ("cls");
		printf ("\n\n Presione W para subir la raqueta y S para bajar la raqueta\n\n");
		system ("pause");
		
		ponginicio ( campo, pelX, pelY, inijug, finjug, iniia, finia); 
		k = pongloop ( campo, pelX, pelY, inijug, finjug, iniia, finia,  modX, modY, modia );
		
	}while( k == 0);	
		
	}
	
	else {
		do{
		
		system ("cls"); 
		printf ("\n\n Jugador 1 : Presione W para subir la raqueta y S para bajar la raqueta\n\n Jugador 2 : Presione O para subir la raqueta y L para bajar la raqueta\n\n");
		system ("pause");
		
		ponginicio ( campo, pelX, pelY, inijug, finjug, inijug2, finjug2);
		k = pongloop2 ( campo, pelX, pelY, inijug, finjug, inijug2, finjug2, modX, modY);
	}while ( k == 0 );	
	}
}

int menu () {
	
	int z;
	
	do {
		system("cls");
	
		printf ("\n			        EPIC   PONG!!!");
		printf ("\n\nMenu: ");
		printf ("\n\n[1] Individual");
		printf ("\n[2] Partida Compartida");
		printf ("\n\nSeleciona una Modalidad de Juego: ");
	
		scanf ("%i", &z);
		
	} while ( z != 1 && z != 2);
	
	return z;
	
}

void ponginicio (char campo[V][H], int pelX, int pelY, int inijug, int finjug, int iniia, int finia ){
	
	int gol1, gol2;
	
	gol1 = 0;
	gol2 = 0; 
	
	pongborde (campo, gol1, gol2);
	raqjug (campo, inijug, finjug);
	raqjug2 ( campo, iniia, finia );
	pel ( campo, pelX, pelY);
	marcador ( campo, gol1, gol2 );
}

void pongborde ( char campo [V][H], int gol1, int gol2){
	
	int i, j;
	
	for ( i = 0; i < V; i++) {
		for ( j = 0; j < H; j++) {
			
			if ( i == 0 || i == V-1 ) {
				campo[i][j] = '#';
			}
			
			else if ( j == 0 || j == H-1 ){
				campo[i][j] = '#';
			}
			
			
			else {
				campo[i][j] = ' ';
			}
			marcador ( campo, gol1, gol2 );
		}
	}
	j = (H + 1)/2;
	for ( i = 1; i < V -1; i++) {
		campo[i][j] = '.'; 
	}
}

void raqjug ( char campo[V][H], int inijug, int finjug) {
	int i, j;
	
	for ( i = inijug; i<= finjug; i++) {
		for ( j = 2; j <= 3; j++){
			campo[i][j] = 'X';
		}
	}	
}

void raqjug2 ( char campo[V][H], int inijug2, int finjug2 ) {
	int i, j;
	
	for ( i = inijug2; i<= finjug2; i++) {
		for ( j = H - 4; j < H - 2; j++){
			campo[i][j] = 'X';
		}
	}	
}

void pel ( char campo[V][H], int pelX, int pelY) {
	campo[pelY][pelX] = 'O';
}

void draw ( char campo[V][H]) {
	int i, j;
	
	system ("cls");   //Limpiar la pantalla
	
	for ( i = 0; i < V; i++) {
		for ( j = 0; j < H ; j++) {
			printf ("%c", campo[i][j]);
		}
		printf ("\n");
	}
}

int pongloop ( char campo[V][H], int pelX, int pelY, int inijug, int finjug, int iniia, int finia, int modX, int modY, int modia ) {
	
	int gol1, gol2, k, n;
	gol1 = 0;
	gol2 = 0;
	
	do {
		
		k= 0;
		
		cuentatras ();
		                
		do {
				draw (campo);																								//Dibujar en Pantalla
				ponginput ( campo, &pelX, &pelY, &inijug, &finjug, &iniia, &finia, &modX, &modY, &modia, &gol1, &gol2, &k);		//Verificar y modificar las posiciones
				pongupdate ( campo, pelX, pelY, inijug, finjug, iniia, finia, gol1, gol2 );										//Actualizar la martiz campo
				Sleep (25);
			
		}while ( k == 0 );
		
		//Varaibles de Posición
		pelX = 37;
		pelY = 10;
	
		inijug = 8;
		finjug = 12;
	
		iniia = 3;
		finia = 17;
	
		//Varaiables de Modificación
	
		modX *= -1;
		modY *= -1;
		modia = -1;
		
	} while ( gol1 < 3 && gol2 < 3 );
	system ("cls");
	
	if ( gol1 < gol2 ){
		printf ("\n\n                      Has Perdido!!!\n\n Pulsa 1 para la Revancha, cualquier otra letra para continuar...");
		scanf ("%i", &n);
		
		if ( n == 1 ){return 0;}
		else { return 1;}
	}
	
	else {
		printf ("\n\n                      Enhorabuena!!!\n\n Has Ganado!! Pulsa 1 para repetir, cualquier otra letra para continuar...");
		scanf ("%i", &n);
		
		if ( n == 1 ){ return 0;}
		else { return 1;}
	}

}
int pongloop2 ( char campo[V][H], int pelX, int pelY, int inijug, int finjug, int inijug2, int finjug2, int modX, int modY ) {
	
	int gol1, gol2, k, n;
	gol1 = 0;
	gol2 = 0;
	
	do {
		
		k= 0;
		
		cuentatras ();
		                
		do {
				draw (campo);																								//Dibujar en Pantalla
				ponginput2 ( campo, &pelX, &pelY, &inijug, &finjug, &inijug2, &finjug2, &modX, &modY, &gol1, &gol2, &k);		//Verificar y modificar las posiciones
				pongupdate ( campo, pelX, pelY, inijug, finjug, inijug2, finjug2, gol1, gol2 );										//Actualizar la martiz campo
				Sleep (25);
			
		}while ( k == 0 );
		
		//Varaibles de Posición
		pelX = 37;
		pelY = 10;
	
		inijug = 8;
		finjug = 12;
	
		inijug2 = 8;
		finjug2 = 12;
	
		//Varaiables de Modificación
	
		modX *= -1;
		modY *= -1;
	} while ( gol1 < 3 && gol2 < 3 );
	system ("cls");
	if ( gol1 < gol2 ){
		printf ("\n\n                      Enhorabuena Jugador 2!!! Has Ganado!!\n\n Pulsa 1 para la Revancha, cualquier otra letra para continuar...");
		scanf ("%i", &n);
		
		if ( n == 1 ){ return 0; }
		else { return 1;}
	}
	
	else {
		printf ("\n\n                      Enhorabuena Jugador 1!!! Has Ganado!!\n\n Pulsa 1 para la Revancha, cualquier otra letra para continuar...");
		scanf ("%i", &n);
		
		if ( n == 1 ){ return 0;}
		else { return 1;}
	}

}

void ponginput ( char campo[V][H],  int *pelX, int *pelY, int *inijug, int *finjug, int *iniia, int *finia, int *modX, int *modY, int *modia, int *gol1, int *gol2, int *k){
	
	int i;
	char key;
	//Verificación
	
			
		if  ( *pelY == 1 || *pelY == V - 2 ) {
		
			*modY *= -1;
		}
	
		if ( *pelX == 1 ){
			
			*gol2 += 1;
			*k = 1;
		}
		
		if ( *pelX == H - 2 ){
			
			*gol1 += 1;
			*k = 1;
		}
				
		if ( *pelX == 4 ){
			for ( i = (*inijug); i <= (*finjug); i++) {
				if ( i == (*pelY)) {
					*modX *= -1;
				}
			}
		}
		
		if ( *pelX == H - 5 ){
			for ( i = (*iniia); i <= (*finia); i++) {
				if ( i == (*pelY)) {
					*modX *= -1;
				}
			}
		}

		
	//Modificación
	
 		if ( *iniia == 1 || *finia == V - 2 ) {
				*modia *= -1;
		}
	
		// Pelota
		*pelX += ( *modX);
		*pelY += ( *modY);
		
		// Raqueta de la IA
		
		*iniia += ( *modia);
		*finia += ( *modia);
		
		// Raqueta Jugador:
		
		if ( kbhit() == 1) {  		//kbhit es un funcion que obtiene el valor uno cuando se toca una tecla y 0 cuadno no
			key = getch() ; 		//getch es lo mismo que scanf solo que no hay que pulsar intro 
			
			if ( key == 'w') {
				if (*inijug != 1 ) {
					*inijug += -1;
					*finjug += -1;
				}
			}
			
			if ( key == 's') {
				if(*finjug != V-2 ){
					*inijug += 1;
					*finjug += 1;
				}
			}
		}
	
}
