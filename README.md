# Projeto de Análise Numérica
Trabalho de Análise Numérica onde foi analisado a diferença de desempenho entre alguns algoritmos para resoluções de sistemas do tipo AX=B.
* Gauss
* Cholewski
* Jacobi (Sem otimização na multiplicação)
* Jacobi (Com otimização na multiplicação)
* Gauss-Seidel
* Gradientes Conjugados

## Pré-requisitos
Os algoritmos utilizam a biblioteca time.h para medir o tempo, em SO Windows pode acontecer de o algoritmo não calcular o tempo em um valor coerente.

## Função de Análise
A função de análise é y''(x)= pi²sen(pi*x), caso seja necessário alterar modifique o código no arquivo Grid_Vec_gen.c:
```
Código teste
```

## Compilando
Para gerar os arquivos binários basta rodar make :)
```
make
```

## Populando os dados a serem analisados
Para gerar os arquivos com as matrizes e vetores a serem analizados:
```
./gendata.sh
```
