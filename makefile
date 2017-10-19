default:
	gcc Gauss.c -o gauss
	gcc Cholewski.c -lm -o cholewski
	gcc Jacobi.c -lm -o jacobi
	gcc Gauss-Seidel.c -lm -o gauss-seidel
	gcc GradConj.c -lm -o gradconj
	gcc Grid_Vec_gen.c -lm -o gridvecgen
clean:
	rm gauss cholewski jacobi gauss-seidel gradconj gridvecgen
totalclean:
	rm gauss cholewski jacobi gauss-seidel gradconj gridvecgen *.txt
