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
	
}
