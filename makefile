default:
	gcc Gauss.c -o gauss
	gcc Cholewski.c -lm -o cholewski
	gcc Jacobi.c -o jacobi
	gcc Gauss-Seidei.c -o gauss-seidel
	gcc GradConj.c -lm -o gradconj
clean:
	rm gauss jacobi cholewski gauss-seidel gradconj
