
#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	
	typedef struct _Endereco Endereco;
	
	struct _Endereco{
	char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2];
	};
	
	int compara(const void *e1, const void *e2){
	return strncmp(((Endereco*)e1)->cep, ((Endereco*)e2)->cep, 8);
	}
	
	int main(int argc, char** argv){
	FILE *buffer1, *buffer2, *saida;
	Endereco ea, eb;
	int qtd;
	char nome1 [25], nome2 [25], nome3[25];
	printf("Quantos arquivos deseja aglutinar? (Quantidade Par)\n");
	scanf("%d", &qtd);
	int cont = qtd;
	
	
	for(int i = 1; i <= (qtd+qtd); i += 2){
	sprintf(nome1, "BlocoCEP_%d.dat", i);
	sprintf(nome2, "BlocoCEP_%d.dat", i+1);
	printf("Arquivo a ser intercalado %s\n", nome1);
	printf("Arquivo a ser intercalado: %s\n", nome2);
	buffer1 = fopen(nome1,"r");
	buffer2 = fopen(nome2,"r");
	fread(&ea, sizeof(Endereco), 1, buffer1);
	fread(&eb, sizeof(Endereco), 1, buffer2);
	if(i <= (qtd+qtd-1)){
	sprintf(nome3, "BlocoCEP_%d.dat", (cont+1));
	printf("Arquivo intercalado: %s\n", nome3);
	saida = fopen(nome3, "w");
	}
	
	
	
	while(!feof(buffer1) && !feof(buffer2)){
	if(compara(&ea, &eb) < 0){
	fwrite(&ea, sizeof(Endereco), 1, saida);
	fread(&ea, sizeof(Endereco), 1, buffer1);
	} else {
	fwrite(&eb, sizeof(Endereco), 1, saida);
	fread(&eb, sizeof(Endereco), 1, buffer2);
	}
	}
	
	while(!feof(buffer1)){
	fwrite(&ea, sizeof(Endereco), 1, saida);
	fread(&ea, sizeof(Endereco), 1, buffer1);
	}
	
	while(!feof(buffer2)){
	fwrite(&eb, sizeof(Endereco), 1, saida);
	fread(&eb, sizeof(Endereco), 1, buffer2);
	}
	
	cont++;
	fclose(buffer1);
	fclose(buffer2);
	fclose(saida);
	
	remove(nome1);
	remove(nome2);
	}
	
}

