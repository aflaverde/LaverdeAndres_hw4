##### PUNTO 2 #####

##PUNTO 2G
open: sin.png
	display sin.png
	
##PUNTO 2F
#Crea la figura desde el .py que depende de sin.txt
sin.png: sin.txt plotea.py
	#Ejecuta el .py
	python plotea.py sin.txt
	
#Crea el sin.txt a partir de funcion.cpp que depende de output.txt
sin.txt: output.txt
	##PUNTO 2C
	g++ funcion.cpp -o sin_x
	##PUNTO 2E
	./sin_x

	
#Crea el output.txt a partir de datos.cpp
output.txt: datos.cpp
	##PUNTO 2B
	g++ datos.cpp -o datos_x ##Compila
	##PUNTO 2D
	./datos_x			     ##Ejecuta

##PUNTO 2A	
#Remueve todos los .txt y .png
clean:
	rm *.txt
	rm *.png
	

