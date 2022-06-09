#include"miniwin.h"
using namespace miniwin;

void nave(int x, int y) {
	/*
	la nave tiene del punto central
	25 pixeles hacia la izquierda
	30 pixeles hacia la derecha
	15 pixeles hacia arriba
	35 pixeles hacia abajo
	*/
	// nave pincipal
	color_rgb(169,162,212);
	rectangulo_lleno(x, y-15, x+5, y-10);
	rectangulo_lleno(x-5, y-10, x+10, y-5);
	rectangulo_lleno(x-10, y-5, x+15, y);
	rectangulo_lleno(x-15, y, x+20, y+5);
	rectangulo_lleno(x-20, y+5, x-10, y+10);
	rectangulo_lleno(x-5, y+5, x+10, y+10);
	rectangulo_lleno(x+15, y+5, x+25, y+10);
	rectangulo_lleno(x-25, y+10, x-15, y+15);
	rectangulo_lleno(x, y+10, x+5, y+15);
	rectangulo_lleno(x+20, y+10, x+30, y+15);
	// ventana de la nave
	color_rgb(109,131,209);
	rectangulo_lleno(x, y-10, x+5, y);
	rectangulo_lleno(x-5, y-5, x+10, y);
	// cola de la nave
	color_rgb(84,49,117);
	rectangulo_lleno(x-5, y+15, x+10, y+20);
	rectangulo_lleno(x-10, y+20, x, y+25);
	rectangulo_lleno(x+5,y+20, x+15, y+25);
	// fuego principal
	color_rgb(255,158,108);
	rectangulo_lleno(x, y+20, x+5, y+30);
	rectangulo_lleno(x-10, y+5, x-5, y+15);
	rectangulo_lleno(x+10, y+5, x+15, y+15);
	// fuego secundario
	color_rgb(238,58,115);
	rectangulo_lleno(x-5, y+25, x, y+30);
	rectangulo_lleno(x, y+30, x+5, y+35);
	rectangulo_lleno(x+5, y+25, x+10, y+30);
	rectangulo_lleno(x-15, y+10, x-10, y+15);
	rectangulo_lleno(x-5, y+10, x, y+15);
	rectangulo_lleno(x-10, y+15, x-5, y+20);
	rectangulo_lleno(x+5, y+10, x+10, y+15);
	rectangulo_lleno(x+10, y+15, x+15, y+20);
	rectangulo_lleno(x+15, y+10, x+20, y+15);
}

void enemigo(int x, int y) {
	
	/*
	el enemigo tiene del punto central
	25 pixeles hacia la izquierda
	25 pixeles hacia la derecha
	20 pixeles hacia arriba
	20 pixeles hacia abajo
	*/
	
	color_rgb(247,18,86);
	rectangulo_lleno(x-10, y-15, x-5, y-10);
	rectangulo_lleno(x+5, y-15, x+10, y-10);
	rectangulo_lleno(x-15, y-10, x+15, y-5);
	rectangulo_lleno(x-20, y-5, x-10, y);
	rectangulo_lleno(x-5, y-5, x+5, y);
	rectangulo_lleno(x+10, y-5, x+20, y);
	rectangulo_lleno(x-25, y, x+25, y+5);
	rectangulo_lleno(x-25, y, x-20, y+10);
	rectangulo_lleno(x+20, y, x+25, y+10);
	rectangulo_lleno(x-15, y+5, x+15, y+10);
	rectangulo_lleno(x-15, y+5, x-10, y+15);
	rectangulo_lleno(x+10, y+5, x+15, y+15);
	rectangulo_lleno(x-10, y+15, x-5, y+20);
	rectangulo_lleno(x+5, y+15, x+10, y+20);
	color_rgb(241,193,41);
	rectangulo_lleno(x-15, y-20, x-10, y-15);
	rectangulo_lleno(x+10, y-20, x+15, y-15);
	rectangulo_lleno(x-25, y+10, x-20, y+15);
	rectangulo_lleno(x+20, y+10, x+25, y+15);
	rectangulo_lleno(x-10, y+15, x-5, y+20);
	rectangulo_lleno(x+5, y+15, x+10, y+20);
}

void colision(int x, int y) {
	color(BLANCO);
	rectangulo_lleno(x-5, y-5, x, y);
	rectangulo_lleno(x-10, y-10, x-5, y-5);
	rectangulo_lleno(x-15, y-15, x-10, y-10);
	rectangulo_lleno(x, y-10, x+5, y-5);
	rectangulo_lleno(x+5, y-15, x+10, y-10);
	rectangulo_lleno(x-10, y, x-5, y+5);
	rectangulo_lleno(x-15, y+5, x-10, y+10);
	rectangulo_lleno(x, y, x+5, y+5);
	rectangulo_lleno(x+5, y+5, x+10, y+10);
}

void movimientoEnemigo(int x, int z) {
	x += (z) ? 10: -10;
	if(x == 515) z = false;
	if(x == 35) z = true;
}

int main() {
	// redimensionando la pantalla de juego
	vredimensiona(550, 800);
	
	// posicion inicial de la nave
	int posnaveX = 275;
	int posnaveY = 750;
	
	// nave
	nave(posnaveX, posnaveY);
	
	// posicion inicial del enemigo
	int posenemigoX = 25;
	int posenemigoY = 100;
	
	//inicio del movimiento (hacia la derecha)
	bool direcenemigo = true;
	
	// enemigo
	enemigo(posenemigoX, posenemigoY);
	
	// dibujamos todo
	refresca();
	
	// capturando la tecla presionada
	int t = tecla();
	
	while(t!=ESCAPE) {
		
		switch(t) {
			case ARRIBA:
				posnaveY -= (posnaveY >= 400)?10:0;
				break;
			case ABAJO:
				posnaveY += (posnaveY <= 745)?10:0;
				break;
			case DERECHA:
				posnaveX += (posnaveX <= 500)?10:0;
				break;
			case IZQUIERDA:
				posnaveX -= (posnaveX >= 40)?10:0;
				break;
		}
		
		
		/*
		MOVIMIENTO DEL ENEMIGO
		LOS NUMEROS 515 Y 35 SE PONEN PORQUÉ LA NAVE AVANZA DE 10 EN 10 ENTONCES NO ERA COMPATIBLE CON 500 QUE ERA EN EL CASO DEL PROFESOR
		POR ESO SE OPTARON POR PARAMETROS DISTINTOS EN ESTE CASO
		*/
		posenemigoX += (direcenemigo) ? 10: -10;
		if(posenemigoX == 515) direcenemigo = false;
		if(posenemigoX == 35) direcenemigo = true;
		
		
		/*
		mantiene la imagen de la nave en las siguientes posiciones
		y borra el buffer de lo dibujado en la posicion anterior
		*/
		espera(50);
		borra();
		// dibujamos el enemigo despues de cada posicion
		enemigo(posenemigoX, posenemigoY);
		// mostando la nave
		nave(posnaveX, posnaveY);
		
		
		/*
		LA COLISION
		el condicional toma desde el punto centro de cada elemento osea un ejemplo sería el primer caso
		cuando la posicion central de la nave menos 25 pixeles sea menor o igual a la posicion central del enemigo  mas 25 pixeles colapsaran
		esto se sucere porqué estarían chocando la posicion izquiera de la nave con el lado derecho del enemigo
		*/
		if(posnaveX-25 <= posenemigoX+25 && posnaveX+30 >= posenemigoX-25 && posnaveY+35 >= posenemigoY-20 && posnaveY-15 <= posenemigoY+20) {
			colision(posnaveX, posnaveY);
			refresca();
			espera(100);
			mensaje("GAME OVER");
			vcierra();
		}
		
		// BORDES DEL JUEGO
		color_rgb(168,20,84);
		rectangulo(5, 5, 545, 795);
		rectangulo(10, 10, 540, 790);
		
		refresca();
		t = tecla();
	}
	
	
	vcierra();
	return 0;
}
