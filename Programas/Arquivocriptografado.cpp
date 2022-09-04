#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int criptografar_arquivo()
{
    int i;
    char texto[1000], linha[1000];

    FILE *arquivo;

    arquivo = fopen("texto.txt","r+");


    if (arquivo==NULL)
    {
        printf(" ERRO ao abrir o arquivo!! \n");
        return 0;
    }

    strcpy(texto,""); 


    while(fgets(linha,1000,arquivo)!=NULL) 
    {
       strcat(texto,linha);
    }


    for(int i=0;texto[i]!='\0';i++) 
    {
        texto[i]=texto[i]+3;
    }

    arquivo = fopen("texto.txt","w"); 
    fprintf(arquivo, "%s", texto); 
    fclose(arquivo);

    return 0;
} 

char descriptografar_arquivo()
{
    int i;
    char texto[1000], linha[1000];

    FILE *arquivo;

    arquivo = fopen("texto.txt","r+");


    if (arquivo==NULL)
    {
        printf("Problema ao abrir o arquivo \n");
        return 0;
    }

    strcpy(texto,""); 

    while(fgets(linha,1000,arquivo)!=NULL) 
    {
       strcat(texto,linha); 
    }

    fscanf(arquivo, "%s", &texto); 

    for(int i=0;texto[i]!='\0';i++) 
    {
        texto[i]=texto[i]-3;
    }

    arquivo = fopen("texto.txt","r+"); 
    fprintf(arquivo, "%s", texto); 
    fclose(arquivo); 

    return 0;
}

char visualizar_arquivo()
{
    char texto[1000], linha[1000];

    FILE *arquivo;

    arquivo = fopen("texto.txt","r+"); 

    if (arquivo==NULL) 
    {
        printf("\nProblema ao abrir o arquivo\n\n");
        return 0;
    }
    strcpy(texto,"");

    while(fgets(linha,1000,arquivo)!=NULL)
    {
        strcat(texto,linha);
    }
    printf("\n %s \n",texto);
    fclose(arquivo);

    return 0;

}
int main() {

    setlocale(LC_ALL, "Portuguese");

    int opc;
    FILE *arquivo;

    arquivo = fopen("texto.txt","r+");

    if(arquivo==NULL)
    {
            printf ( "\n NÃO FOI POSSIVEL ABRIR O ARQUIVO!!\n\n");
            return 0;
    }

    fprintf(arquivo, "%s" ,"Giovana");
    fclose(arquivo);

    system("pause");
 
     do
    {
        system("cls");
        cout << "           MENU CRIPTOGRAFIA           \n\n";
        cout << "\n 1 - CRIPTOGRAFAR O ARQUIVO";
        cout << "\n 2 - VISUALIZAR O ARQUIVO";
        cout << "\n 3 - DESCRIPTOGRAFAR ARQUIVO";
        cout << "\n 9 - Sair";
        cout << "\n\n  Digite a sua opcao: ";
        cin >> opc;

    switch(opc)
            {
                case 1 : system("cls");
                        criptografar_arquivo();
                        cout << " ARQUIVO CRIPTOGRAFADO, VOLTE AO MENU PARA VISUALIZAR O AQUIVO\n\n";
                        system("pause");
                        break;

                case 2 : system("cls");
                        visualizar_arquivo();
                        cout << "\n\n";
                        system("pause");
                        break;

                case 3 : system("cls");
                        cout << " ARQUIVO DESCRIPTOGRAFADO, VOLTE AO MENU PARA CONFERIR O AQUIVO DESCRIPTOGRAFADO\n\n";
                        system("pause");
                        descriptografar_arquivo();
                        system("cls");
                        system("pause");
                        break;
                
                default: system("cls");
                        cout << " OPCAO INVALIDA!!!\n\n";
                        system("pause");
                        break;

            }
            
        }while(opc!=9);
        return 0;
}