#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca para utilização das strings
#include <stdbool.h> //biblioteca de inclusao de variáveis booleanas



int registraUsuario () { // Função para registrar usuários no sistema
char arquivo [40]; // Declaração de variáveis
char cpf[40];
char nome[40];
char sobrenome[40];
char cargo[40];
//fim declaração variáveis da função

printf("Digite o CPF a ser cadastrado: ");
scanf("%s",&cpf);
strcpy(arquivo,cpf); //funcao para copiar string para arquivo

FILE *file; //cria o arquivo
file = fopen(arquivo, "w"); //cria o arquivo
fprintf(file,cpf); //salva no arquivo a variavel cpf
fclose(file); //fecha o arquivo

file = fopen(arquivo, "a"); // acessa o arquivo novamente
fprintf(file,","); //escreve virgula para separar o dado cpf do próximo dado no arquivo
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

printf("\n\nUsuário Cadastrado com Sucesso!\n\n");
system("pause");

}

int consultaUsuario () { //função para consulta de dados de usuários cadastrados

char cpf[40];
char conteudo[200];
int contador = 0; // variavel para contar posição dos caracteres da string conteudo
int posicaoVirgula = 0; //variavel para localizar posição da virgula
setlocale (LC_ALL, "Portuguese_Brazil.1252"); //comando para utilizar a biblioteca de caracteres em português

printf("Digite o CPF a ser consultado:");
scanf("%s",&cpf);

FILE *file;
file = fopen(cpf,"r"); //ler o arquivo e procura o cpf

if(file == NULL) { //Caso não encontre no arquivo

    printf("\nNão foi possível localizar o usuário\n\n\n");
    system("pause");

}
printf("Dados do Usuário encontrados:\n\n");
while (fgets(conteudo,200,file) != NULL){ //enquanto tiver informação, busca no arquivo

    for(contador = 0; contador <= strlen(conteudo); contador++){ // exibição dos dados de forma organizada

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


int deletaUsuario () { // função para deletar o usuário

char cpf[40];
int confirmacao;


printf("Digite o CPF do usuário a ser deletado:");
scanf("%s",&cpf);

FILE *file;
file = fopen(cpf,"r");


if (file == NULL){

   printf("\n\nO usuário digitado não existe no cadastro\n\n");
   system("pause");
   return 0;

}
fclose(file);
//Evolutiva para confirmação de exclusão de Cadastro d
printf("Você tem certeza que quer deletar o usuário de cpf %s?\n\n Digite 1 para confirmar ou qualquer outro comando para cancelar\n\n\n",cpf);
scanf("%d",&confirmacao);


if (confirmacao == 1){
    remove(cpf);
    printf("Usuário deletado com sucesso");
    system("pause");
                                       }
else  {
    printf("\n\nOperação de Exclusão Cancelada, retornando ao Menu Inicial...\n\n");
    system("pause");
      }


}


int main()
{


    int opcao = 0;
    bool lacoMenuInicial = true;

setlocale (LC_ALL, "Portuguese_Brazil.1252"); //comando para utilizar a biblioteca de caracteres em português


while (lacoMenuInicial == true){ //Repete enquanto a variavel booleana lacoMenuInicial for verdadeira.


printf("==================================== Cartório da EBAC ==============================================\n\n");


printf("===================================== Menu Principal ===============================================\n\n\n\n");


printf("\t1 - Registrar Usuários\t\n");
printf("\t2 - Consultar Usuários\t\n");
printf("\t3 - Deletar Usuários\t\n");
printf("\nDigite a opção desejada:");

scanf("%d",&opcao); // armazena a opçãoo do usuário

system("cls"); //limpa a tela

switch(opcao) { //melhor opção para menus desse tipo

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

printf("\nEscolha uma opção válida\n");
system("pause");
system("cls");

break;
//fim da seleção
              }
                        }
}
