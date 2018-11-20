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


//--------------------MAIN-----------------------//
int main(){	
	double x_pos[100];
	double g=10.0;	//Gravedad
	double c=0.2;	//Coef. de friccion
	double m=0.2;	//Masa
	double x0=0.0;	//Pos. inicial
	double y0=0.0;
	double v0=300.0;//Velocidad inicial m/s
	double ang=45*PI/180.0;	//Angulo en radianes
	double h=0.01;	//Delta de tiempo
	int N=100;
	
	
	//////////////45 GRADOS///////////////////
	FILE *output;      //Abre el archivo y guarda los datos en el archivo ode-45.dat
	output = fopen("ode-45.dat","w");
	
	//Escribe los datos en el archivo ode.dat
	for (int i=0; i<N; i++){
		//i=tiempo
		double k1x, k1y, k2x, k2y, k3x, k3y, k4x, k4y, rkx, rky;
		
		k1x=pos_x(g,c,m,x0,v0,ang,i);
		k1y=pos_y(g,c,m,x0,v0,ang,i);
		
		k2x=pos_x(g,c,m,(x0+h*k1x/2.0),v0,ang,i+h/2.0);
		k2y=pos_y(g,c,m,(x0+h*k1y/2.0),v0,ang,i+h/2.0);
		
		k3x=pos_x(g,c,m,(x0+h*k2x/2.0),v0,ang,i+h/2.0);
		k3y=pos_y(g,c,m,(x0+h*k2y/2.0),v0,ang,i+h/2.0);
		
		k4x=pos_x(g,c,m,(x0+h*k3x),v0,ang,i+h);
		k4y=pos_y(g,c,m,(x0+h*k3y),v0,ang,i+h);
		
		rkx=x0+(h/6.0)*(abs(k1x)+2.0*abs(k2x)+2.0*abs(k3x)+abs(k4x));
		rky=y0+(h/6.0)*(abs(k1y)+2.0*abs(k2y)+2.0*abs(k3y)+abs(k4y));
		
		fprintf(output, "%f %f\n",rkx, rky);
	}
	printf("Datos guardados en ode-45.dat\n");
	fclose(output);
	
	
	//////////////// OTROS ANGULOS //////////////////////
	
	FILE *output2;      //Abre el archivo y guarda los datos en el archivo ode-otros.dat
	output2 = fopen("ode-otros.dat","w");
	
	double ang10, ang20, ang30, ang40, ang50, ang60, ang70;
	ang10=10*PI/180.0;
	ang20=20*PI/180.0;
	ang30=30*PI/180.0;
	ang40=40*PI/180.0;
	ang50=50*PI/180.0;
	ang60=60*PI/180.0;
	ang70=70*PI/180.0;
	
	for (int i=0; i<N; i++){
		//i=tiempo
		//////////  10
		double k1x_10, k1y_10, k2x_10, k2y_10, k3x_10, k3y_10, k4x_10, k4y_10, rkx_10, rky_10;
		
		k1x_10=pos_x(g,c,m,x0,v0,ang10,i);
		k1y_10=pos_y(g,c,m,x0,v0,ang10,i);
		
		k2x_10=pos_x(g,c,m,(x0+h*k1x_10/2.0),v0,ang10,i+h/2.0);
		k2y_10=pos_y(g,c,m,(x0+h*k1y_10/2.0),v0,ang10,i+h/2.0);
		
		k3x_10=pos_x(g,c,m,(x0+h*k2x_10/2.0),v0,ang10,i+h/2.0);
		k3y_10=pos_y(g,c,m,(x0+h*k2y_10/2.0),v0,ang10,i+h/2.0);
		
		k4x_10=pos_x(g,c,m,(x0+h*k3x_10),v0,ang10,i+h);
		k4y_10=pos_y(g,c,m,(x0+h*k3y_10),v0,ang10,i+h);
		
		rkx_10=x0+(h/6.0)*(abs(k1x_10)+2.0*abs(k2x_10)+2.0*abs(k3x_10)+abs(k4x_10));
		rky_10=y0+(h/6.0)*(abs(k1y_10)+2.0*abs(k2y_10)+2.0*abs(k3y_10)+abs(k4y_10));
		
		/////////  20
		double k1x_20, k1y_20, k2x_20, k2y_20, k3x_20, k3y_20, k4x_20, k4y_20, rkx_20, rky_20;
		
		k1x_20=pos_x(g,c,m,x0,v0,ang20,i);
		k1y_20=pos_y(g,c,m,x0,v0,ang20,i);
		
		k2x_20=pos_x(g,c,m,(x0+h*k1x_20/2.0),v0,ang20,i+h/2.0);
		k2y_20=pos_y(g,c,m,(x0+h*k1y_20/2.0),v0,ang20,i+h/2.0);
		
		k3x_20=pos_x(g,c,m,(x0+h*k2x_20/2.0),v0,ang20,i+h/2.0);
		k3y_20=pos_y(g,c,m,(x0+h*k2y_20/2.0),v0,ang20,i+h/2.0);
		
		k4x_20=pos_x(g,c,m,(x0+h*k3x_20),v0,ang20,i+h);
		k4y_20=pos_y(g,c,m,(x0+h*k3y_20),v0,ang20,i+h);
		
		rkx_20=x0+(h/6.0)*(abs(k1x_20)+2.0*abs(k2x_20)+2.0*abs(k3x_20)+abs(k4x_20));
		rky_20=y0+(h/6.0)*(abs(k1y_20)+2.0*abs(k2y_20)+2.0*abs(k3y_20)+abs(k4y_20));
		
		fprintf(output2, "%f %f %f %f\n",rkx_10, rky_10, rkx_20, rky_20);
	}
	printf("Datos guardados en ode-otros.dat\n");
	fclose(output2);
	
	return 0;
}//MAIN
