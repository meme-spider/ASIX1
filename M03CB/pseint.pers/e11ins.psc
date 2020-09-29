Algoritmo e11
	Escribir "How many numbers do you wish to sort?"
	Leer nn
	dimension numbers[nn]
	Escribir "gimme ", nn, " numbers"
	para z=1 hasta nn hacer
		Leer numbers[z]
	FinPara
	
	smallest=numbers[1]
	
	Para i=2 Hasta nn Con Paso 1 Hacer
		temp = numbers[i]
		j=i-1
		mientras j>0 & temp < numbers[j]  Hacer
			numbers[j+1]=numbers[j]
			j=j-1
		fin mientras
		numbers[j+1]=temp
	Fin Para
	
	Escribir "Ordered numbers coming up: "
	endChain=""
	para z=1 hasta nn hacer
		endChain= concatenar(endChain, concatenar(ConvertirATexto(numbers[z])," "))
	FinPara
	escribir endChain
FinAlgoritmo
