//Andres Laverde - ODE.cpp HW4

#include<iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

#define PI 3.14159

//Posicion en x
double pos_x(double g, double c, double m, double x0, double v0, double ang, double dt){
	double v0x=v0*cos(ang*PI/180);
	double x=(v0x/c)*(1-exp(-c*dt));

	return x;
}//pos_x

//Posicion en y
double pos_y(double g, double c, double m, double x0, double v0, double ang, double dt){
	double v0y=v0*sin(ang*PI/180);
	double y=(1/c)*(g/c+v0y)*(1-exp(-c*dt))-(g*dt/c);

	return y;
}//pos_y

//Velocidad en x
double vel_x(double g, double c, double m, double x0, double v0, double ang, double dt){
	double v0x=v0*cos(ang*PI/180);
	double vx=v0x*(exp(-c*dt));

	return vx;
}//vel_x

//Velocidad en y
double vel_y(double g, double c, double m, double x0, double v0, double ang, double dt){
	double v0y=v0*cos(ang*PI/180);
	double vy=(g/c+v0y)*(exp(-c*dt)-(g/c));

	return vy;
}//vel_y

double rk4(double func, double g, double c, double m, double x0, double v0, double ang, double dt){
}//rk4


//--------------------MAIN-----------------------//
int main(){	
	double x_pos[100];
	double g=10.0;	//Gravedad
	double c=0.2;	//Coef. de friccion
	double m=0.2;	//Masa
	double x0=0.0;	//Pos. inicial
	double v0=300.0;//Velocidad inicial m/s
	double ang=45*PI/180.0;	//Angulo en radianes
	double dt=0.01;	//Delta de tiempo
	
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
