#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca para utiliza��o das strings
#include <stdbool.h> //biblioteca de inclusao de vari�veis booleanas



int registraUsuario () { // Fun��o para registrar usu�rios no sistema
char arquivo [40]; // Declara��o de vari�veis
char cpf[40];
char nome[40];
char sobrenome[40];
char cargo[40];
//fim declara��o vari�veis da fun��o

printf("Digite o CPF a ser cadastrado: ");
scanf("%s",&cpf);
strcpy(arquivo,cpf); //funcao para copiar string para arquivo

FILE *file; //cria o arquivo
file = fopen(arquivo, "w"); //cria o arquivo
fprintf(file,cpf); //salva no arquivo a variavel cpf
fclose(file); //fecha o arquivo

file = fopen(arquivo, "a"); // acessa o arquivo novamente
fprintf(file,","); //escreve virgula para separar o dado cpf do pr�ximo dado no arquivo
fclose(file);

printf("Digite o nome a ser cadastrado:");
scanf("%s",&nome);
file = fopen(arquivo, "a");
fprintf(file,nome);
fclose(file);

file = fopen(arquivo, "a");
fprintf(file,",");
fclose(file);


printf("Digite o sobrenome a ser cadastrado:");
scanf("%s",&sobrenome);
file = fopen(arquivo, "a");
fprintf(file,sobrenome);
fclose(file);

file = fopen(arquivo, "a");
fprintf(file,",");
fclose(file);


printf("Digite o cargo a ser cadastrado:");
scanf("%s",&cargo);
file = fopen(arquivo, "a");
fprintf(file,cargo);
fclose(file);

printf("\n\nUsu�rio Cadastrado com Sucesso!\n\n");
system("pause");

}

int consultaUsuario () { //fun��o para consulta de dados de usu�rios cadastrados

char cpf[40];
char conteudo[200];
int contador = 0; // variavel para contar posi��o dos caracteres da string conteudo
int posicaoVirgula = 0; //variavel para localizar posi��o da virgula
setlocale (LC_ALL, "Portuguese_Brazil.1252"); //comando para utilizar a biblioteca de caracteres em portugu�s

printf("Digite o CPF a ser consultado:");
scanf("%s",&cpf);

FILE *file;
file = fopen(cpf,"r"); //ler o arquivo e procura o cpf

if(file == NULL) { //Caso n�o encontre no arquivo

    printf("\nN�o foi poss�vel localizar o usu�rio\n\n\n");
    system("pause");

}
printf("Dados do Usu�rio encontrados:\n\n");
while (fgets(conteudo,200,file) != NULL){ //enquanto tiver informa��o, busca no arquivo

    for(contador = 0; contador <= strlen(conteudo); contador++){ // exibi��o dos dados de forma organizada

                if (posicaoVirgula == 0){
                printf("CPF:");
                posicaoVirgula++;       }

                if(conteudo[contador] == ',')      {
                printf("\n");

                    if (posicaoVirgula == 1){
                    printf("Nome:");
                    posicaoVirgula++;
                    continue;      }

                    if (posicaoVirgula == 2){
                    printf("Sobrenome:");
                    posicaoVirgula++;
                    continue;        }

                    if (posicaoVirgula == 3){
                    printf("Cargo:");
                    posicaoVirgula++;
                    continue;        }
                                                    }

       printf("%c",conteudo[contador]);

    }

    printf("\n");

   fclose(file);
   system("pause");
}

}


int deletaUsuario () { // fun��o para deletar o usu�rio

char cpf[40];
int confirmacao;


printf("Digite o CPF do usu�rio a ser deletado:");
scanf("%s",&cpf);

FILE *file;
file = fopen(cpf,"r");


if (file == NULL){

   printf("\n\nO usu�rio digitado n�o existe no cadastro\n\n");
   system("pause");
   return 0;

}
fclose(file);
//Evolutiva para confirma��o de exclus�o de Cadastro d
printf("Voc� tem certeza que quer deletar o usu�rio de cpf %s?\n\n Digite 1 para confirmar ou qualquer outro comando para cancelar\n\n\n",cpf);
scanf("%d",&confirmacao);


if (confirmacao == 1){
    remove(cpf);
    printf("Usu�rio deletado com sucesso");
    system("pause");
                                       }
else  {
    printf("\n\nOpera��o de Exclus�o Cancelada, retornando ao Menu Inicial...\n\n");
    system("pause");
      }


}


int main()
{


    int opcao = 0;
    bool lacoMenuInicial = true;

setlocale (LC_ALL, "Portuguese_Brazil.1252"); //comando para utilizar a biblioteca de caracteres em portugu�s


while (lacoMenuInicial == true){ //Repete enquanto a variavel booleana lacoMenuInicial for verdadeira.


printf("==================================== Cart�rio da EBAC ==============================================\n\n");


printf("===================================== Menu Principal ===============================================\n\n\n\n");


printf("\t1 - Registrar Usu�rios\t\n");
printf("\t2 - Consultar Usu�rios\t\n");
printf("\t3 - Deletar Usu�rios\t\n");
printf("\nDigite a op��o desejada:");

scanf("%d",&opcao); // armazena a op��oo do usu�rio

system("cls"); //limpa a tela

switch(opcao) { //melhor op��o para menus desse tipo

case 1:

    registraUsuario();
    system("cls");
    break;


case 2:

    consultaUsuario();
    system("cls");
    break;


case 3:

    deletaUsuario();
    system("cls");
    break;

default:

printf("\nEscolha uma op��o v�lida\n");
system("pause");
system("cls");

break;
//fim da sele��o
              }
                        }
}
