default:
	gcc Gauss.c -o gauss
	gcc Cholewski.c -lm -o cholewski
	gcc Jacobi.c -lm -o jacobi
	gcc Jacobi_otimizado.c -lm -o jacobi_otimizado
	gcc Gauss-Seidel.c -lm -o gauss-seidel
	gcc GradConj.c -lm -o gradconj
	gcc Grid_Vec_gen.c -lm -o gridvecgen
clean:
	rm gauss cholewski jacobi jacobi_otimizado gauss-seidel gradconj gridvecgen