#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	
	
	typedef struct _Endereco Endereco;
	
	struct _Endereco
	{
	  char logradouro[72];
	  char bairro[72];
	  char cidade[72];
	  char uf[72];
	  char sigla[2];
	  char cep[8];
	  char lixo[2];
	};
	
	int compara(const void *e1, const void *e2){
	  return strncmp(((Endereco*)e1)->cep,((Endereco*)e2)->cep,8);
	}
	
	int main(int argc, char**argv)
	{
	  FILE *buffer1, *buffer2;
	  Endereco *e;
	  long posicao, reg, arq;
	  char nome [25];
	  int qtd;
	  buffer1 = fopen("cep.dat","rb");
	  fseek(buffer1,0,SEEK_END);
	  posicao = ftell(buffer1);
	  reg = posicao/sizeof(Endereco);

  	printf("O arquivo será dividido em quantos? (Quantidade Par)\n");
	  scanf("%d", &qtd);
	  arq = reg/qtd;
	
	  rewind(buffer1);
	
	  for(int i = 1; i < qtd; i++)
    {
	    e = (Endereco*) malloc(arq*sizeof(Endereco));
	    if(fread(e,sizeof(Endereco),arq,buffer1) == arq)
      {
	      printf("BlocoCEP_%d.dat lido\n",i);
	    }
	    qsort(e,arq,sizeof(Endereco),compara);
	    printf("BlocoCEP_%d.dat ordenado\n",i);
	    sprintf(nome, "BlocoCEP_%d.dat", i);
	    buffer2 = fopen(nome,"wb");
	    fwrite(e,sizeof(Endereco),arq,buffer2);
	    printf("BlocoCEP_%d.dat Escrito\n",i);
	    fclose(buffer2);
	    free(e);
	  }
	
	  long resto = reg - arq * (qtd-1);
	
	  e = (Endereco*) malloc((resto)*sizeof(Endereco));
	  if(fread(e,sizeof(Endereco),resto,buffer1) == arq)
    {
      printf("BlocoCEP_%d.dat lido\n",qtd);
	  }
	  qsort(e,arq,sizeof(Endereco),compara);
	  printf("BlocoCEP_%d.dat ordenado\n",qtd);
	  sprintf(nome, "BlocoCEP_%d.dat", qtd);
	  buffer2 = fopen(nome,"wb");
	  fwrite(e,sizeof(Endereco),resto,buffer2);
	  printf("BlocoCEP_%d.dat Escrito\n",qtd);
	  fclose(buffer2);
	  free(e);
	
	  fclose(buffer1);
	}
