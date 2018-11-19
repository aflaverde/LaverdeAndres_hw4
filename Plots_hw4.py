#Andres Laverde - Plots de HW4

import numpy as np
import matplotlib.pyplot as plt

datos1=np.genfromtxt("pde-fijas.dat", delimiter=',') #Importa los datos de pde-fijas y los grafica en una matriz bidimensional de forma m x n donde las filas m son el transcurso de tiempo y n son las columnas de la distancia x del cuerpo
datos2=np.genfromtxt("pde-abiertas.dat", delimiter=',')
datos3=np.genfromtxt("pde-period.dat", delimiter=',')


n1=100
plt.figure()
plt.imshow(datos1[:n1,:])  #Muestra una grafica con los primeros n instantes de tiempo
plt.colorbar()
plt.savefig("PDE1.png")

n2=100
plt.figure()
plt.imshow(datos2[:n2,:])
plt.colorbar()
plt.savefig("PDE2.png")

n3=1000
plt.figure()
plt.imshow(datos3[:n3,:])
plt.colorbar()
plt.savefig("PDE3.png")
