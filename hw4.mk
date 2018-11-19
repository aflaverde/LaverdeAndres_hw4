#Andres Laverde - makefile HW4

Resultados_hw4.pdf: ODE1.png PDE1.png Resultados_hw.tex
	pdflatex Resultados_hw.tex

#Genera la imagen 1 de PDE
PDE1.png: pde.dat Plots_hw4.py
	python3 Plots_hw4.py

#Genera la imagen 1 de ODE
ODE1.png: ode.dat Plots_hw4.py
	python3 Plots_hw4.py

#Genera los datos de PDE
pde.dat: PDE.cpp
	g++ PDE.cpp -o pde.out
	./pde.out

#Genera los datos de ODE
ode.dat: ODE.cpp
	g++ ODE.cpp -o ode.out
	./ode.out
