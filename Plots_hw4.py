#Andres Laverde - Plots de HW4

import numpy as np
import matplotlib.pyplot as plt

############### ODE #######################
ode45=np.genfromtxt("ode-45.dat")
ode45_x=ode45[:,0]
ode45_y=ode45[:,1]

plt.figure()
plt.plot(ode45_x, ode45_y)
plt.title("Proyectil a 45 grados")
plt.xlabel("x(m)")
plt.ylabel("y(m)")
plt.savefig("ODE1.png")

ode2=np.genfromtxt("ode-otros.dat")
ode10_x=ode2[:,0]
ode10_y=ode2[:,1]

ode20_x=ode2[:,2]
ode20_y=ode2[:,3]

plt.figure()
plt.plot(ode10_x, ode10_y, label="10 grados")
plt.plot(ode20_x, ode20_y, label="20 grados")
plt.legend()
plt.xlabel("x(m)")
plt.ylabel("y(m)")
plt.savefig("ODE2.png")

############### PDE #######################
datos1=np.genfromtxt("pde-fijas.dat", delimiter=',') #Importa los datos de pde-fijas y los grafica en una matriz bidimensional de forma m x n donde las filas m son el transcurso de tiempo y n son las columnas de la distancia x del cuerpo
datos2=np.genfromtxt("pde-abiertas.dat", delimiter=',')

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
