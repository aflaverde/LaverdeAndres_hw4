import numpy as np
import matplotlib.pyplot as plt

datos=np.genfromtxt("laplace-calor.dat", delimiter=',') #Importa los datos de laplace-calor y los grafica en una matriz bidimensional de forma m x n donde las filas m son el transcurso de tiempo y n son las columnas de la distancia x

n=1000
plt.imshow(datos[:n,:])	#Muestra una grafica con los primeros n instantes de tiempo
plt.show()
