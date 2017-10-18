default:
	gcc Gauss.c -o gauss
	gcc Cholewski.c -lm -o cholewski
	gcc Jacobi.c -o jacobi
	gcc Jacobi_otimizado.c -o jacobi_otimizado
	gcc Gauss-Seidel.c -o gauss-seidel
	gcc GradConj.c -lm -o gradconj
clean:
	rm gauss cholewski jacobi jacobi_otimizado gauss-seidel gradconj
