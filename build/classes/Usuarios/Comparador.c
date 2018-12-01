#include <stdio.h>
#include <string.h>
#include <process.h>
#include <stdlib.h>
#include <windows.h>

main()
{
    FILE *arquivo, *arquivo2;
    char caractere, usuario[20]="", senha[20]="", status[1]="", usuario2[20]="", senha2[20]="", status2[1]="", chamadaSistema[50];
    int i = 0;

    do
    {
        arquivo2 = fopen("usertemp.txt","rt");
        if(arquivo2 == NULL)
        {
            printf( "Aguardando arquivo\n");

        }
    }

        while(arquivo2 == NULL);
            arquivo = fopen("usuario.txt","rt");


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

            if ((strcmp(usuario,usuario2) == 0) && (strcmp(senha,senha2) == 0) && (strcmp(status,status2) == 0))
            {
                printf("\nO Usuario e %s e a senha e %s",
                       usuario2, senha2);
                break;
            }
            else
            {
                printf("\nEstado Inexistente");
            }
        }


        fclose(arquivo);
        fclose(arquivo2);
    }

