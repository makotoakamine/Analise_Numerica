default:
	gcc Gauss.c -o gauss
	gcc Jacobi.c -o jacobi
clean:
	rm gauss jacobi
