# External-Merge-Sort

Baixar arquivo cep.rar (cep.dat 209.8MB)

Baixar arquivos divide.c e aglutina.c

Ir para o Terminal:

cd Downloads

gcc -o divide divide.c
gcc -o aglutina aglutina.c

./divide 

Digite a quantidade desejada de blocos para dividir (Quantidade par) EX: 20.

./aglutina

Digite a quantidade de blocos que foram divididos a serem aglutinados EX: 20.

Perceba que mesmo com a presença de uma mensagem de Segmentation Fault, o arquivo foi aglutinado e nenhum byte foi perdido. Além de estar ordenado.
