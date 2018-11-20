#Andres Laverde - makefile HW4

Resultados_hw4.pdf: Resultados_hw4.tex PDE1.png PDE2.png ODE1.png
	pdflatex Resultados_hw4.tex

#Genera la imagen 3 de PDE
PDE1.png PDE2.png ODE1.png ODE2.png: pde-fijas.dat pde-abiertas.dat ode-45.dat ode-otros.dat Plots_hw4.py
	python3 Plots_hw4.py

#Genera los datos de PDE
pde-fijas.dat pde-abiertas.dat: PDE.cpp
	g++ PDE.cpp -o pde.out
	./pde.out

#Genera los datos de ODE
ode-45.dat ode-otros.dat: ODE.cpp
	g++ ODE.cpp -o ode.out
	./ode.out

clean:
	rm *.dat *.out
