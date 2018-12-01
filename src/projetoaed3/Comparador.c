#include <stdio.h>
#include <string.h>
#include <process.h>
#include <stdlib.h>
#include <windows.h>

main()
{
    FILE *arquivo, *arquivo2;
    char caractere, usuario[20], senha[20], usuario2[20], senha2[20], chamadaSistema[50];
    int i = 0, encontrou = 0;

    arquivo = fopen("C:\\Users\\Wesley\\Documents\\NetBeansProjects\\ProjetoAED3\\build\\classes\\passwords\\usuario.txt","rt");
    if(arquivo == NULL)
    {
        printf( "Erro na abertura do arquivo");

    }

    arquivo2 = fopen("C:\\Users\\Wesley\\Documents\\NetBeansProjects\\ProjetoAED3\\build\\classes\\passwords\\usertemp.txt","rt");
    if(arquivo2 == NULL)
    {
        printf( "Erro na abertura do arquivo1");

    }
    while (!feof(arquivo2))
    {
        i = 0;
        do
        {
            caractere = fgetc(arquivo2);
            if (caractere != '=' && caractere != 20 && !feof(arquivo))
            {
                usuario[i] = caractere;
                i++;
            }
        }
        while (caractere != '=' && !feof(arquivo2));
        usuario[i] = '\0';

        i = 0;
        do
        {
            caractere = fgetc(arquivo2);
            if (caractere != ';' && caractere != 20 && !feof(arquivo))
            {
                senha[i] = caractere;
                i++;
            }
        }
        while (caractere != ';' && !feof(arquivo2));
        senha[i] = '\0';

        i = 0;
        do
        {
            caractere = fgetc(arquivo);
            if (caractere != '=' && caractere != 20 && !feof(arquivo))
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
            if (caractere != '-' && caractere != 20 && !feof(arquivo))
            {
                senha2[i] = caractere;
                i++;
            }
        }
        while (caractere != '-' && !feof(arquivo));
        senha2[i] = '\0';

        if (!feof(arquivo) && strcmp(usuario,usuario2)==0 && strcmp(senha,senha2)==0)
        {
            strcpy(chamadaSistema,"java ProjetoAED3");
            printf("Comando = %s\n",chamadaSistema);
            system(chamadaSistema);

            getchar();
            encontrou = 1;
            break;
        }
    }
    if (!encontrou)
        printf("Estado inexistente...");

    fclose(arquivo);
    fclose(arquivo2);
}

