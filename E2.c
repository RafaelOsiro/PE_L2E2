/*
UNIVERSIDADE CATÓLICA DE BRASÍLIA
CURSO: ANÁLISE E DESENVOLVIMENTO DE SISTEMAS
DISCIPLINA: PROGRAMAÇÃO ESTRUTURADA
DOCENTE: JOYCE SIQUEIRA
DISCENTE: RAFAEL RIKI OGAWA OSIRO (UC21100716)

Exercício: 2. Desenvolva um programa que solicite o nome de cinco equipamentos de informática. Compare os cinco 
nomes fornecidos para verificar se existe algum solicitado em duplicidade e informe o usuário somente o nome 
duplicado.
*/

//!LIBRARIES _______________________________________________________________________________________________
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<stdbool.h>
#include<ctype.h>

struct Equipment
{
    bool print;
    char name[50];
};

//! MESSAGES OF THE SYSTEM ____________________________________________________________________________________
void messageTitle();
void messageMenu();
void messageNameInput(int index);
void messageConfirmExit();
void messageExit();
void messageName(struct Equipment *object);


//! ERROR MESSAGES OF THE SYSTEM ______________________________________________________________________________
void errorMessageInput(int quantityOfError, int option);
void errorExit();

//! VALIDATION INPUT __________________________________________________________________________________________
bool validationString(char *string);

//! FUNCTION OF THE SYSTEM ____________________________________________________________________________________
int functionOptionInput();
void functionInputString(struct Equipment *object);
void functionIsEqual(struct Equipment *equipments);

int main()
{
    int option, quantityOfError = 0;
    struct Equipment equipments[5];
    bool validation = false, exitValidation = false;

    do
    {
        messageTitle();
        messageMenu();
        option = functionOptionInput();

        switch (option)
        {
        case 1:
            system("cls");
            quantityOfError = 0;
            
            functionInputString(equipments);
            functionIsEqual(equipments);
            messageName(equipments);
            break;
        
        case 2:
            system("cls");
            quantityOfError = 0;
            
            do
            {
                messageConfirmExit();
                option = functionOptionInput();

                if (option == 1)
                {
                    exitValidation = true;
                    validation = true; 
                }
                else if(option == 2)
                {
                    exitValidation = true;
                    validation = false;
                }
                else
                {
                    exitValidation = false;
                    system("cls");
                    quantityOfError++;
                    errorMessageInput(quantityOfError, 1);

                    if (quantityOfError == 3)
                    {
                        errorExit();
                        exit(EXIT_FAILURE);
                    }    
                }

            } while (exitValidation == false);


            system("cls");
            quantityOfError = 0;
            
            break;

        default:
            system("cls");
            quantityOfError++;
            errorMessageInput(quantityOfError, 1);

            if (quantityOfError == 3)
            {
                errorExit();
                exit(EXIT_FAILURE);
            }
            break;
        }
    
    } while (validation == false);
    
    messageExit();
    exit(EXIT_SUCCESS);
}

//! MESSAGES OF THE SYSTEM ____________________________________________________________________________________

//  MESSAGE TITLE OF THE SYSTEM
void messageTitle()
{
    printf("SISTEMA PARA LISTAR OS EQUIPAMENTOS DE INFORM\265TICA REPETIDO\n\n\n");
}

//  MESSAGE MENU
void messageMenu()
{
    printf("---------------------------------\n");
    printf("[1] ENTRADA DE EQUPAMENTOS DE INFORM\265TICA\n");
    printf("[2] SAIR DO PROGRAMA\n");
    printf("---------------------------------\n\n");
    printf("DIGITE A OP\200\307O DESEJADA: ");
}

//  MESSAGE ASK NAME INPUT
void messageNameInput(int index)
{
    printf("DIGITE O EQUIPAMENTO DE INFORM\265TICA %d: ", index);
}

//  MESSAGE ASK CONFIRM EXIT OF THE SYSTEM
void messageConfirmExit()
{
    printf("DESEJA CONFIRMAR A SA\326DA DO SISTEMA?\n\n");
    printf("-------\n");
    printf("[1] SIM\n");
    printf("[2] N\307O\n");
    printf("-------\n\n");
    printf("DIGITE A OP\200\307O DESEJADA: ");
}

//  MESSAGE TO EXIT SYSTEM
void messageExit()
{
    printf("O SISTEMA IR\265 FINALIZAR\n");
}

//  MESSAGE TO PRINT THE NAMES
void messageName(struct Equipment *equipments)
{
    for (int i = 0; i < (sizeof(equipments) + 1); i++)
    {
        if (equipments[i].print == true)
        {
            printf("%s\n", equipments[i].name);
        }
    }
}

//! ERROR MESSAGES OF THE SYSTEM ______________________________________________________________________________

//  ERROR MESSAGE INPUT
void errorMessageInput(int quantityOfError, int option)
{
    switch (option)
    {
    case 1:
        printf("ERRO %d de 3!\n", quantityOfError);
        printf("DIGITE UMA OP\200\307O V\265LIDA\n\n\n");
        break;
    
    case 2:
        printf("ERRO %d de 3!\n", quantityOfError);
        printf("DIGITE UM NOME V\265LIDO\n\n\n");
        break;

    default:
        break;
    }
}

//  ERROR EXIT SYSTEM
void errorExit()
{
    printf("QUANTIDADE DE ERROS ATINGIDO!\n");
    printf("O SISTEMA IR\265 FINALIZAR!\n\n\n");
}

//! VALIDATION INPUT __________________________________________________________________________________________

//  FUNCTION TO VALIDATE A STRING
bool validationString(char *string)
{
    int index = 0;

    if (strlen(string) == 1)
    {
        if (string[index] == "\n" || string[index] == " " || string[index] == "\0" || string[index] == "\r" || 
        string[index] == "\r\n" || !isalpha(string[index] || !isdigit(string[index])))
        {
            return false;
        }
    }
    else
    {
        while (index < strlen(string))
        {
            if (string[index] != "\n" && string[index] != " " && string[index] != "\0" && string[index] != "\r" && 
            string[index] != "\r\n" && !isspace(string[index]) && (isalpha(string[index]) || isdigit(string[index])))
            {
                return true;
            }
            index++;
        }

        return false;
    }

    return false;
}

//! FUNCTION OF THE SYSTEM ____________________________________________________________________________________

//  FUNCTION OPTION INPUT
int functionOptionInput()
{
    int number;

    fflush(stdin);
    scanf("%d", &number);

    return number;
}

//  FUNCTION INPUT STRING
void functionInputString(struct Equipment *equipments)
{
    int size = (sizeof(equipments) + 1), quantityOfError = 0, count = 0;
    bool validation = false;

    for (int i = 0; i < size; i++)
    {
        messageTitle();
        while (validation == false)
        {
            messageNameInput(i+1);
            fflush(stdin);
            fgets(equipments[i].name, sizeof(equipments[0].name), stdin);
            validation = validationString(equipments[i].name);

            if (strlen(equipments[i].name) == 50-1)
            {
                char charactere;
                while ((charactere = getchar()) != '\n' && charactere != EOF);
            }

            if (validation == false)
            {
                system("cls");
                quantityOfError++;
                errorMessageInput(quantityOfError, 2);

                if (quantityOfError == 3)
                {
                    errorExit();
                    exit(EXIT_FAILURE);
                }
            }
        }
        system("cls");
        count = 0;
        validation = false;
    }
}

//  FUNCTION TO CHECK IF IS EQUAL
void functionIsEqual(struct Equipment *equipments)
{
    int size = (sizeof(equipments) + 1);

    for (int i = 0; i < size; i++)
    {
        equipments[i].print = false;
    }

    for (int i = 0; i < (size - 1); i++)
    {
        for (int j = (i+1); j < size; j++)
        {
            if (strcmp(equipments[i].name, equipments[j].name) == 0)
            {
                equipments[i].print = true;
            }
        }
    }
}