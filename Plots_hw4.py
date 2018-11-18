import numpy as np
import matplotlib.pyplot as plt

datos=np.genfromtxt("pde.dat", delimiter=',') #Importa los datos de laplace-calor y los grafica en una matriz bidimensional de forma m x n donde las filas m son el transcurso de tiempo y n son las columnas de la distancia x

n=100
plt.imshow(datos[:n,:])	#Muestra una grafica con los primeros n instantes de tiempo
plt.savefig("PDE.png")
