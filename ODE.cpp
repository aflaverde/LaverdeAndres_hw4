#include<iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

#define PI 3.14159

//Aceleracion en x
double acc_x(double g, double c, double m, double x0, double v0, double ang, double dt){
	/* dvx/dt = -c/m(raiz(vx**2+vy**2)*vx)*/
	double x=x0+v0*dt;
	double v=v0+x/dt;
	double vx=v*cos(ang);	//Vel. en x
	double vy=v*sin(ang);	//Vel. en y
	double a_x = -(c/m)*(sqrt(vx*vx + vy*vy)*vx);
	return a_x;
}//acc_x

int main(){	
	double a_max;
		
	double x_pos[100];
	double g=10.0;	//Gravedad
	double c=0.2;	//Coef. de friccion
	double m=0.2;	//Masa
	double x0=0.0;	//Pos. inicial
	double v0=300.0;//Velocidad inicial m/s
	double ang=45*PI/180.0;	//Angulo en radianes
	double dt=0.01;	//Delta de tiempo
	
	a_max=acc_x(g, c, m, x0, v0, ang, dt);
	
	FILE *output;      //Abre el archivo y guarda los datos en el archivo ode.dat
	output = fopen("ode.dat","w");
	
	//Escribe los datos en el archivo ode.dat
	for (int i=0; i<100; i++){
		fprintf(output, "%f,",x_pos[i]);
	}
	printf("Datos guardados en ode.dat\n");
	fclose(output);
	
	return 0;
}//MAIN
