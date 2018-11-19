//Andres Laverde - PDE.cpp HW4

#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

#define max 51		//Longitud maxima
#define tmax 3000	//tiempo maximo de propagacion
#define PI 3.14159

//Funciones
void fronteras10(double *T);

int main()
{
	int i, j, iter, y;
	double T[tmax][max]; //La forma es: en filas es el tiempo y en columnas la posicion del cuerpo
   
   //i: tiempo
   //j: posicion

	double dx=0.03;
	double K=162;		//Conductividad termica
	double C=820;		//calor especifico
	double rho=2710;	//Densidad
	double eta=(K)/(C*rho*dx*dx);

/////////////////////////////////////////////////////////////////////
					/*Caso 1 - fijas a 10*/
						
	FILE *output1;      //Abre el archivo y guarda los datos en el archivo pde-fijas.dat
	output1 = fopen("pde-fijas.dat","w");

	for(i=0; i<tmax; i++)	// limpia el array dejando todo en 0
	{   
		for (j=0; j<max; j++) T[i][j] = 0;
	}

	for(j=0; j<max; j++){
		if(j>=20 && j<=30) {
			T[0][j] = 100.0;	// Condiciones iniciales
		}
	}

	/*Caso 1*/
	for(iter=0; iter<1000; iter++)	//iteraciones
	{
		//i=tiempo
		//j=x
		for(i=0; i<tmax; i++)	// avance del tiempo
		{
			for(j=0; j<max; j++)	// direccion de x
			{
				T[i][0]=10;		//Condiciones de frontera
				T[i][max-1]=10;
				T[i+1][j] = T[i][j]+(eta*(T[i][j+1]+T[i][j-1]-2.0*T[i][j]));
			}
		}
	}
   
	for (i=0; i<tmax ; i++)
	{
		for (j=0; j<max; j++) 
		{
			fprintf(output1, "%f,",T[i][j]);
		}
		fprintf(output1, "\n");
	}
	printf("Datos guardados en pde-fijas.dat\n");
	fclose(output1);

/////////////////////////////////////////////////////////////////////
					/*Caso 2 - abiertas*/
	
	FILE *output2;      //Abre el archivo y guarda los datos en el archivo pde-abiertas.dat
	output2 = fopen("pde-abiertas.dat","w");

	for(i=0; i<tmax; i++)	// limpia el array dejando todo en 0
	{   
		for (j=0; j<max; j++) T[i][j] = 0;
	}

	for(j=0; j<max; j++){
		if(j>=20 && j<=30) {
			T[0][j] = 100.0;	// Condiciones iniciales
		}
	}

	/*Caso 1*/
	for(iter=0; iter<1000; iter++)	//iteraciones
	{
		//i=tiempo
		//j=x
		for(i=0; i<tmax; i++)	// avance del tiempo
		{
			for(j=0; j<max; j++)	// direccion de x
			{
				T[i+1][j] = T[i][j]+(eta*(T[i][j+1]+T[i][j-1]-2.0*T[i][j]));
			}
		}
	}
   
	for (i=0; i<tmax ; i++)         // write data gnuplot 3D format 
	{
		for (j=0; j<max; j++) 
		{
			fprintf(output2, "%f,",T[i][j]);
		}
		fprintf(output2, "\n");    // empty line for gnuplot
	}
	printf("Datos guardados en pde-abiertas.dat\n");
	fclose(output2);
	
/////////////////////////////////////////////////////////////////////
					/*Caso 3 - periodicas*/
	
	FILE *output3;      //Abre el archivo y guarda los datos en el archivo pde-periodicas.dat
	output3 = fopen("pde-period.dat","w");

	for(i=0; i<tmax; i++)	// limpia el array dejando todo en 0
	{   
		for (j=0; j<max; j++) T[i][j] = 0;
	}

	for(j=0; j<max; j++){
		if(j>=20 && j<=30) {
			T[0][j] = 100.0;	// Condiciones iniciales
		}
	}

	/*Caso 1*/
	for(iter=0; iter<1000; iter++)	//iteraciones
	{
		//i=tiempo
		//j=x
		for(i=0; i<tmax; i++)	// avance del tiempo
		{
			for(j=0; j<max; j++)	// direccion de x
			{
				T[i][0]=cos(i*PI/180)*50;	//Condiciones periodicas de -50 a 50
				T[i+1][j] = T[i][j]+(eta*(T[i][j+1]+T[i][j-1]-2.0*T[i][j]));
			}
		}
	}
   
	for (i=0; i<tmax ; i++)         // write data gnuplot 3D format 
	{
		for (j=0; j<max; j++) 
		{
			fprintf(output3, "%f,",T[i][j]);
		}
		fprintf(output3, "\n");    // empty line for gnuplot
	}
	printf("Datos guardados en pde-period.dat\n");
	fclose(output3);
}//MAIN

