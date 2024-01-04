#include <stdio.h> //biblioteca de comunicação com o usuário

#include <stdlib.h> //biblioteca de alocação de espaço em memória

#include <locale.h> //biblioteca de alocações de texto por região

#include <string.h> //biblioteca responsável pela criação de strings

// printf ("Software by Ronne Bispo \n" ); Linha salva para o final do cód.

  
  int registro ()
  {
  	char arquivo[40];
  	char cpf[40];
  	char nome[40];
  	char sobrenome[40];
  	char cargo[40];                                                                
  	
  	printf ("Digite o CPF a ser cadastrado:");
  	scanf("%s", cpf);
  	
  	strcpy(arquivo, cpf);// copia valores string
  	
  	FILE *file; // cria arquivo 
  	file = fopen(arquivo,"w");
  	fprintf(file,cpf);//salvo valor da variável
  	fclose(file);//fecha arquivo
  	
  	file = fopen(arquivo, "a");
  	fprintf(file, ",");
  	fclose(file);
  	
  	printf ("Digite nome a ser cadastrado:");
   	scanf("%s", nome);
   	
   	file = fopen(arquivo, "a");
   	fprintf(file,nome);
   	fclose(file);
   	
   	file = fopen(arquivo, "a");
  	fprintf(file, ",");
  	fclose(file);
   	
   	
   	printf ("Digite o sobrenome a ser cadastrado:");
   	scanf("%s", sobrenome);
   	
   	file = fopen(arquivo,"a");
   	fprintf(file,sobrenome);
   	fclose(file);
   	
   	
   	file = fopen(arquivo, "a");
  	fprintf(file, ",");
  	fclose(file);
  	
  	printf ("Digite nome o cargo ser cadastrado:");
   	scanf("%s", cargo);
   	
   	file = fopen(arquivo,"a");
   	fprintf(file,cargo);
   	fclose(file);
   	
   	
   	system("pause");
  }
  
  int consulta ()
  {
  	setlocale(LC_ALL, "Portuguese");
  	
  	char cpf[40];
  	char conteudo[200];
  	
  	printf("Digite o CPF a ser consultado:");
  	scanf("%s",cpf);
  	printf("\n");
  	
  	
  	FILE *file;
  	file = fopen(cpf,"r");
  	
  	if(file == NULL)
  	{
  		printf("CPF não cadastrado!");
  		
	  }
	  
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Dados do usuário:");
		printf("%s",conteudo);
		printf("\n\n");
	}
  	
  	system("pause");
  	
  }
  
  int deletar ()
  {
  	char cpf[40];
  	
  	printf ("Digite o CPF a ser deletado:");
  	scanf ("%s", cpf);
  	
  	remove(cpf);
  	
  	FILE *file;
  	file = fopen(cpf,"r");
  	
  	if(file == NULL);
  	{
  		printf("Usuário deletado ou não cadastrado no sistema!\n");
  		system("pause");
	}

   	
   	
  }
  
  
   int main ()
   {
   int opcao=0; //Definindo variáveis
   int laco=1;
   
   for (laco=1;laco=1;)
   {
      system("cls");
      
      setlocale (LC_ALL, "Portuguese"); //Definindo idioma
   
      printf ("### CARTÓRIO EBAC ### \n\n"); //Início do menu
      printf ("Escolha a opção desejada:\n\n");
      printf ("\t1 - Registrar \n" );
      printf ("\t2 - Consultar \n" );
      printf ("\t3 - Deletar \n" );
      printf ("\t4 - Sair do Sistema \n\n");
      printf ("opção: "); // Fim do menu

      scanf ("%d", &opcao); // linha para armazenar a opçao escolhida pelo usuário
   
      system ("cls"); //Limpar tela
      
      switch(opcao)
      {
      	case 1:
        registro();
   	    break;
   	    
   	    case 2:
      	consulta();
   	    break;
   	    
   	    case 3:
      	deletar();
   	    break;
   	    
   	    case 4:
   	    printf ("Obrigado por utilizar o Cartório EBAC");
   	    return 0;
   	    break;
   	    
   	    default:
   	    printf ("Opção inválida\n");
   	    system("pause");
   	    break;
	     }
    
     }
}
