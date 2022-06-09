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
	int posenemigo1X = 25;
	int posenemigo1Y = 200;
	int posenemigo2X = 200;
	int posenemigo2Y = 50;
	int posenemigo3X = 230;
	int posenemigo3Y = 200;
	int posenemigo4X = 500;
	int posenemigo4Y = 120;
	
	//inicio del movimiento (hacia la derecha)
	bool direcenemigo1 = true;
	bool direcenemigo2 = true;
	bool direcenemigo3 = true;
	bool direcenemigo4 = false;
	
	// enemigo
	enemigo(posenemigo1X, posenemigo1Y);
	enemigo(posenemigo2X, posenemigo2Y);
	enemigo(posenemigo3X, posenemigo3Y);
	enemigo(posenemigo4X, posenemigo4Y);
	
	// dibujamos todo
	refresca();
	
	// capturando la tecla presionada
	int t = tecla();
	
	while(t!=ESCAPE) {
		
		switch(t) {
			case ARRIBA:
				posnaveY -= (posnaveY >= 45)?10:0;
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
		posenemigo1X += (direcenemigo1) ? 10: -10;
		if(posenemigo1X == 205) direcenemigo1 = false;
		if(posenemigo1X == 45) direcenemigo1 = true;
		
		posenemigo2X += (direcenemigo2) ? 10: -10;
		if(posenemigo2X == 500) direcenemigo2 = false;
		if(posenemigo2X == 50) direcenemigo2 = true;
		
		posenemigo3X += (direcenemigo3) ? 10: -10;
		if(posenemigo3X == 500) direcenemigo3 = false;
		if(posenemigo3X == 270) direcenemigo3 = true;
		
		posenemigo4X += (direcenemigo4) ? 10: -10;
		if(posenemigo4X == 500) direcenemigo4 = false;
		if(posenemigo4X == 50) direcenemigo4 = true;
		
		
		/*
		mantiene la imagen de la nave en las siguientes posiciones
		y borra el buffer de lo dibujado en la posicion anterior
		*/
		espera(50);
		borra();
		// dibujamos el enemigo despues de cada posicion
		enemigo(posenemigo1X, posenemigo1Y);
		enemigo(posenemigo2X, posenemigo2Y);
		enemigo(posenemigo3X, posenemigo3Y);
		enemigo(posenemigo4X, posenemigo4Y);
		// mostando la nave
		nave(posnaveX, posnaveY);
		
		
		/*
		LA COLISION
		el condicional toma desde el punto centro de cada elemento osea un ejemplo sería el primer caso
		cuando la posicion central de la nave menos 25 pixeles sea menor o igual a la posicion central del enemigo  mas 25 pixeles colapsaran
		esto se sucere porqué estarían chocando la posicion izquiera de la nave con el lado derecho del enemigo
		*/
		if(posnaveX-25 <= posenemigo1X+25 && posnaveX+30 >= posenemigo1X-25 && posnaveY+35 >= posenemigo1Y-20 && posnaveY-15 <= posenemigo1Y+20) {
			colision(posnaveX, posnaveY);
			refresca();
			espera(100);
			mensaje("GAME OVER");
			vcierra();
		}
		
		if(posnaveX-25 <= posenemigo2X+25 && posnaveX+30 >= posenemigo2X-25 && posnaveY+35 >= posenemigo2Y-20 && posnaveY-15 <= posenemigo2Y+20) {
			colision(posnaveX, posnaveY);
			refresca();
			espera(100);
			mensaje("GAME OVER");
			vcierra();
		}
		
		if(posnaveX-25 <= posenemigo3X+25 && posnaveX+30 >= posenemigo3X-25 && posnaveY+35 >= posenemigo3Y-20 && posnaveY-15 <= posenemigo3Y+20) {
			colision(posnaveX, posnaveY);
			refresca();
			espera(100);
			mensaje("GAME OVER");
			vcierra();
		}
		
		if(posnaveX-25 <= posenemigo4X+25 && posnaveX+30 >= posenemigo4X-25 && posnaveY+35 >= posenemigo4Y-20 && posnaveY-15 <= posenemigo4Y+20) {
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
