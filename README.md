# Projeto de Análise Numérica
Trabalho de Análise Numérica onde foi analisado a diferença de desempenho entre alguns algoritmos para resoluções de sistemas do tipo AX=B.
* Gauss
* Cholewski
* Jacobi (Sem otimização na multiplicação)
* Jacobi (Com otimização na multiplicação)
* Gauss-Seidel
* Gradientes Conjugados

### Pré-requisitos
Os algoritmos utilizam a biblioteca time.h para medir o tempo, em SO Windows pode acontecer de o algoritmo não calcular o tempo em um valor coerente.

### Função de Análise
A função de análise é y''(x)= pi²sen(pi*x), caso seja necessário alterar modifique o código no arquivo Grid_Vec_gen.c:
```
Código teste
```

### Compilando
Para gerar os arquivos binários basta rodar make :)
```
make
```

### Populando os dados a serem analisados
Para gerar os arquivos com as matrizes e vetores a serem analizados:
```
./gendata.sh
```
Esse shell script o binary da seguinte forma:
```
./gridvecgen n a b alpha beta
```
onde
*n = número de partições
*a e b tal que a<b. [a,b] é o domínio que será analizado.
*alpha -> y''(a) = alpha
*beta -> y''(b) = beta

Executa o trecho acima para n=[50;100;150;200;250;300;350;400;450;500].

### Analisando os dados
Para fazer a análise dos dados basta fazer a passagem do arquivo contendo a matriz e o vetor.

#### Gauss
```
./gauss opt < data
```
Onde opt = Y ou N
data está no formato:
k
a(1,1)\ta(1,2) ... a(1,k)
a(2,1)  a(2,2) ...    .
  .       .    ...    .
  .       .    ...    .
a(k,1)  a(k,2) ... a(k,k)
b(1)
b(2)
.
.
.
b(k)
