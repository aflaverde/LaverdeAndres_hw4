#Andres Laverde - makefile HW4

Resultados_hw4.pdf: Resultados_hw4.tex
	pdflatex Resultados_hw4.tex

#Genera la imagen 3 de PDE
Esultados_hw4.tex: pde-period.dat Plots_hw4.py
	python3 Plots_hw4.py

#Genera los datos de PDE
pde.dat: PDE.cpp
	g++ PDE.cpp -o pde.out
	./pde.out

#Genera los datos de ODE
ode.dat: ODE.cpp
	g++ ODE.cpp -o ode.out
	./ode.out

clean: 
	rm *.png *.aux *.log *.out *.txt *.dat
