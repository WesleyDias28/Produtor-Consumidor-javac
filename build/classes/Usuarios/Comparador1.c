#include <stdio.h>
#include <string.h>
#include <process.h>
#include <stdlib.h>
#include <windows.h>

main()
{
    FILE *arquivo, *arquivo2, *retornoJ;
    char caractere, usuario[20]="", senha[20]="", status[1]="", usuario2[20]="", senha2[20]="", status2[1]="";
    int i = 0;
    int resultado;
    //remove("usertemp.txt");
    //remove("aut.txt");
    do
    {
        arquivo2 = fopen("usertemp.txt","rt");
        if(arquivo2 == NULL);
    }
    while(arquivo2 == NULL);
    arquivo = fopen("usuario.txt","rt");
    retornoJ = fopen("aut.txt","wt+");

    while (!feof(arquivo2))
    {
        i = 0;
        do
        {
            caractere = fgetc(arquivo2);
            if (caractere != '=' && !feof(arquivo2))
            {
                usuario[i] = caractere;
                i++;
            }
        }
        while (caractere != '=' && !feof(arquivo2));

        i = 0;
        do
        {
            caractere = fgetc(arquivo2);
            if (caractere != '-' && !feof(arquivo2))
            {
                senha[i] = caractere;
                i++;
            }
        }
        while (caractere != '-' && !feof(arquivo2));

        i = 0;
        do
        {
            caractere = fgetc(arquivo2);
            if (caractere != ';' && !feof(arquivo2))
            {
                status[i] = caractere;
                i++;
            }
        }
        while (caractere != ';' && !feof(arquivo2));
    }

    while (!feof(arquivo))
    {

        i = 0;
        do
        {
            caractere = fgetc(arquivo);
            if (caractere != '=' && !feof(arquivo))
            {
                usuario2[i] = caractere;
                i++;
            }
        }
        while (caractere != '=' && !feof(arquivo));
        usuario2[i] = '\0';


        i = 0;
        do
        {
            caractere = fgetc(arquivo);
            if (caractere != '-' && !feof(arquivo))
            {
                senha2[i] = caractere;
                i++;
            }
        }
        while (caractere != '-' && !feof(arquivo));
        senha2[i] = '\0';

        i = 0;
        do
        {
            caractere = fgetc(arquivo);
            if (caractere != ';' && !feof(arquivo))
            {
                status2[i] = caractere;
                i++;
            }
        }
        while (caractere != ';' && !feof(arquivo));

        printf("usuario %s %s\n", usuario, usuario2);
        printf("senha %s %s\n",senha, senha2);

        if ((strcmp(usuario,usuario2) == 0) && (strcmp(senha,senha2) == 0) && (strcmp(status,status2) == 0))
        {
            resultado = 1;
            break;
        }
        else
        {
            resultado = 0;
        }
    }
    if (resultado == 1)
    {
            printf("Usuario Correto\n");
            fprintf(retornoJ,"correto");
    }
    else
    {
            printf("Usuario Incorreto\n");
            fprintf(retornoJ,"invalido");
    }

    fclose(retornoJ);
    fclose(arquivo);
    fclose(arquivo2);
}

