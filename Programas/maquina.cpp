#include <iostream>
#include <locale.h>
#include <string>
#include <cstdlib>

using namespace std;

int main(){

    setlocale(LC_ALL, "Portuguese");

    //declaração variáveis
    int i = 10;
    int j = 0;
    string produtos[20] = {"ÁGUA", "SUCO", "BISCOITO", "GUARANÁ", "CHÁ", "BOLINHO", "CHIPS", "BOLACHA", "CHOCOLATE", "CHICLETES", "BALAS"};
    int quantidade[20] = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    float preco[20] = {2, 5, 6.7, 5.5, 7, 7.2, 4.5, 3, 1.6, 1.5};
    char confirm;
    int remover;
    int opcrepor,qntrepor;
    int opcadm, opcus, opcao = 0;
    double faturamentoatual = 0, faturamentofuturo = 0;
    int quantus;
    double valorpago = 0, valortotal;

    do{
        system("cls");
        cout << "\n          VOCÊ É?" << endl;
        cout << "-------------------------------------" << endl;
        cout << " [1] - ADMINISTRADOR \n [2] - CLIENTE\n [3] - ENCERRAR PROGRAMA " << endl;
        cout << "-------------------------------------" << endl;
        cout << " RESPOSTA: ";
        cin >> opcao;

        while(opcao != 1 && opcao != 2 && opcao != 3){
            cout << " OPÇÃO INVÁLIDA! DIGITE A OPÇÃO NOVAMENTE: " << endl;
            cin >> opcao;
        }

        //MODO ADM:
        if(opcao == 1){
            system("cls");

            cout << "      SEJA BEM-VINDO, ADMINISTRADOR!" << endl;
            cout << "\n\n     ESCOLHA UMA DAS OPÇÕES: " << endl;
            cout << "---------------------------------------" << endl;
            cout << " [1] - ADICIONAR PRODUTOS \n [2] - REPOSIÇÃO DO ESTOQUE \n [3] - REMOVER PRODUTO \n [4] - FATURAMENTO DA MÁQUINA \n [5] - LISTA DE PRODUTOS" << endl;
            cout << "----------------------------------------" << endl;
            cout << " OPÇÃO: ";
            cin >> opcadm;

            while(opcadm != 1 && opcadm != 2 && opcadm != 3 && opcadm != 4 && opcadm != 5){
                cout << "\n OPÇÃO INVÁLIDA! DIGITE UMA DAS OPÇÕES ACIMA NOVAMENTE: " << endl;
                cout << " OPÇÃO: ";
                cin >> opcadm;
            }

            switch(opcadm){
               case 1:
                   do{

                      system("cls");
                      j = 0;

                      cout << "-------------------------" << endl;
                      cout << "  ADICIONAR PRODUTOS" << endl;
                      cout << "-------------------------" << endl;

                      cout << "\n DIGITE O NOME DO PRODUTO: ";
                      cin >> produtos[i];

                      cout << " DIGITE A QUANTIDADE DO PRODUTO: ";
                      cin >> quantidade[i];

                      cout << " DIGITE O PREÇO UNITÁRIO DO PRODUTO: R$";
                      cin >> preco[i];

                      i++;

                      cout << "\n DESEJA ADICIONAR MAIS PRODUTOS? " << endl;
                      cout << " [S] - SIM \n [N] - NÃO" << endl;
                      cout << " RESPOSTA: ";
                      cin >> confirm;

                      while(confirm != 's' && confirm != 'S' && confirm != 'n' && confirm != 'N'){
                         cout << " OPÇÃO INVÁLIDA. TENTE NOVAMENTE: " << endl;
                         cout << "\n DESEJA ADICIONAR MAIS PRODUTOS? " << endl;
                         cout << " [S] - SIM \n [N] - NÃO\n RESPOSTA: ";
                         cin >> confirm;
                      }

                   }while(confirm == 'S' || confirm == 's');

                   cout << "\n              PRODUTOS CADASTRADOS: \n";
                   cout << " _______________________________________________________" << endl;
                   cout << "|                                                       |" << endl;
                   cout << "|CÓDIGO |   PRODUTO \t|    PREÇO      |   QUANTIDADE \t|" << endl;
                   cout << "|_______________________________________________________|" << endl;

                   while(j <= i - 1){
                      cout << "| " << j << "\t|  " << produtos[j] << "   \t|\t " << preco[j] << "   \t|      " << quantidade[j] << "      \t| "<< endl;
                      cout << "|_______________________________________________________|" << endl;
                      j++;
                   }

                   cout << "\n   OPERAÇÃO REALIZADA COM SUCESSO!" << endl;
                   system("pause");
               break;


               case 2:
                   do{
                      system("cls");

                      cout << "-----------------------" << endl;
                      cout << "  REPONDO PRODUTOS" << endl;
                      cout << "-----------------------" << endl;

                      cout << "\n           PRODUTOS CADASTRADOS: \n";
                      cout << " _______________________________________________________" << endl;
                      cout << "|                                                       |" << endl;
                      cout << "|CÓDIGO |   PRODUTO \t|    PREÇO      |   QUANTIDADE \t|" << endl;
                      cout << "|_______________________________________________________|" << endl;

                     //exibição dos valores na tabela, j recebe real o valor do vetor
                      for(j = 0; j<= i - 1; j++){
                         cout << "| " << j << "\t|  " << produtos[j] << "   \t|\t " << preco[j] << "   \t|      " << quantidade[j] << "      \t| "<< endl;
                         cout << "|_______________________________________________________|" << endl;
                      }

                       cout <<"\n DIGITE O CÓDIGO DO PRODUTO QUE DESEJA REPOR: ";
                       cin >> opcrepor;
                       cout << "\n DIGITE A QUANTIDADE QUE DESEJA AUMENTAR OU REMOVER (PARA REMOVER DIGITE UM NÚMERO NEGATIVO): ";
                       cin >> qntrepor;

                       quantidade[opcrepor] += qntrepor;

                       if(quantidade[opcrepor] < 0){
                          quantidade[opcrepor] = 0;
                       }

                       cout << "\n DESEJA REPOR MAIS PRODUTOS? \n [S]- SIM\n [N]- NÃO\n RESPOSTA: ";
                       cin >> confirm;

                       while(confirm != 's' && confirm != 'S' && confirm != 'n' && confirm != 'N'){
                          cout << "\n OPÇÃO INVÁLIDA. TENTE NOVAMENTE: " << endl;
                          cout << "\n DESEJA REPOR MAIS PRODUTOS? " << endl;
                          cout << " [S] - SIM \n [N] - NÃO\n RESPOSTA: ";
                          cin >> confirm;
                       }


                    }while(confirm == 'S' || confirm == 's');

                     cout << "\n   OPERAÇÃO REALIZADA COM SUCESSO!" << endl;
                     system("pause");
               break;

               case 3:
                   do{
                      system("cls");

                      cout << "-----------------------" << endl;
                      cout << "  REMOVENDO PRODUTOS" << endl;
                      cout << "-----------------------" << endl;

                      cout << "\n              PRODUTOS CADASTRADOS: \n";
                      cout << " _______________________________________________________" << endl;
                      cout << "|                                                       |" << endl;
                      cout << "|CÓDIGO |   PRODUTO \t|    PREÇO      |   QUANTIDADE \t|" << endl;
                      cout << "|_______________________________________________________|" << endl;

                      for(j = 0; j<= i - 1; j++){
                         cout << "| " << j << "\t|  " << produtos[j] << "   \t|\t " << preco[j] << "   \t|      " << quantidade[j] << "      \t| "<< endl;
                         cout << "|_______________________________________________________|" << endl;
                      }

                      cout << "\n DIGITE O CÓDIGO DO PRODUTO QUE DESEJA REMOVER (CASO QUEIRA CANCELAR, DIGITE -1):  ";
                      cin >> remover;

                      if(remover == -1){
                         break;
                      }

                      while(remover <= 1){
                         produtos[remover] = produtos[remover + 1];
                         quantidade[remover] = quantidade[remover + 1];
                         preco[remover] = preco[remover + 1];
                         remover++;
                      }

                      cout << "\n DESEJA REMOVER MAIS PRODUTOS? \n [S]- SIM \n [N]- NÃO\n RESPOSTA: ";
                      cin >> confirm;

                      while(confirm != 's' && confirm != 'S' && confirm != 'n' && confirm != 'N'){
                          cout << "\n OPÇÃO INVÁLIDA. TENTE NOVAMENTE: " << endl;
                          cout << "\n DESEJA REMOVER MAIS PRODUTOS? " << endl;
                          cout << " [S] - SIM \n [N] - NÃO\n RESPOSTA: ";
                          cin >> confirm;
                      }

                   }while(confirm == 'S' || confirm  == 's');

                   cout << "\n   OPERAÇÃO REALIZADA COM SUCESSO! " << endl;
                   system("pause");
               break;

               case 4:
                   system("cls");


                    cout << "---------------------" << endl;
                    cout << "   FATURAMENTO" << endl;
                    cout << "---------------------" << endl;

                    cout << "\n FATURAMENTO ATUAL: R$" << faturamentoatual << endl;

                    for(j = 0; j <= i - 1; j++){
                        faturamentofuturo += (quantidade[j] * preco[j]);
                    }

                    cout << "\n A MÁQUINA AINDA PODE FATURAR: R$" << faturamentofuturo << endl;
                    cout << endl;

                    system("pause");
               break;

               case 5:
                     system("cls");

                     cout << "--------------------------" << endl;
                     cout << "  LISTAGEM DOS PRODUTOS" << endl;
                     cout << "--------------------------" << endl;


                     cout << "\n             PRODUTOS CADASTRADOS: \n";
                     cout << " _______________________________________________________" << endl;
                     cout << "|                                                       |" << endl;
                     cout << "|CÓDIGO |   PRODUTO \t|    PREÇO      |   QUANTIDADE \t|" << endl;
                     cout << "|_______________________________________________________|" << endl;

                   //exibição dos valores na tabela, j recebe real o valor do vetor
                     for(j = 0; j<= i - 1; j++){
                         cout << "| " << j << "\t|  " << produtos[j] << "   \t|\t " << preco[j] << "   \t|      " << quantidade[j] << "      \t| "<< endl;
                         cout << "|_______________________________________________________|" << endl;
                      }

                     system("pause");

                break;

            }
        }

        //MODO USUÁRIO:
        if(opcao == 2){
           do{
             system("cls");

             confirm = ' ';

             cout << "---------------" << endl;
             cout << "    PEDIDO   " << endl;
             cout << "---------------" << endl;

             cout << "\n              SEJA BEM-VINDO, CLIENTE!" << endl;

             cout << "\n                     PRODUTOS: \n";
             cout << " _______________________________________________________" << endl;
             cout << "|                                                       |" << endl;
             cout << "|CÓDIGO |   PRODUTO \t|    PREÇO      |   QUANTIDADE \t|" << endl;
             cout << "|_______________________________________________________|" << endl;

             for(j = 0; j<= i - 1; j++){
                cout << "| " << j << "\t|  " << produtos[j] << "   \t|\t " << preco[j] << "   \t|      " << quantidade[j] << "      \t| "<< endl;
                cout << "|_______________________________________________________|" << endl;
             }

             cout << "\n\n               REALIZAÇÃO DA COMPRA: " << endl;
             cout << "              =========================" << endl;
             cout << "\n    [CASO QUEIRA CANCELAR A COMPRA, DIGITE: -1 NO CÓDIGO]" << endl;
             cout << "\n  DIGITE O CÓDIGO DO PRODUTO QUE DESEJA: ";
             cin >> opcus;

             while(opcus > i - 1 || opcus < -1){
                 cout << "\n  OPÇÃO INVÁLIDA. ESCOLHA OUTRO PRODUTO. \n CÓDIGO DO PRODUTO: ";
                 cin >> opcus;
             }

             if(opcus == -1){
                break;
             }

             while(quantidade[opcus] <= 0){
                cout << "\n  ESTOQUE ZERADO. ESCOLHA OUTRO PRODUTO: ";
                cin >> opcus;

                if(opcus == -1){
                    break;
                }
             }

             if(opcus == -1){
                break;
             }

             cout << "  QUANTIDADE QUE DESEJA COMPRAR: ";
             cin >> quantus;


             while(quantidade[opcus] < quantus){
                 cout << "\n  QUANTIDADE DE ESTOQUE INSUFICIENTE. \n\n  DESEJA CANCELAR A COMPRA? \n [S]- SIM \n [N]- NÃO\n RESPOSTA: ";
                 cin >> confirm;

                 while(confirm != 'S'&& confirm != 's' && confirm != 'N' && confirm != 'n'){
                    cout << "\n  OPÇÃO INVÁLIDA. TENTE NOVAMENTE." << endl;
                    cout << "\n  DESEJA CANCELAR A COMPRA? \n [S]- SIM \n [N]- NÃO\n RESPOSTA: ";
                    cin >> confirm;

                    if(confirm == 'N ' || confirm == 'n'){
                        break;
                    }
                 }

                 if(confirm == 'S' || confirm == 's'){
                    break;
                 }


                if(confirm == 'N' || confirm == 'n'){
                   cout << "\n  DIGITE A QUANTIDADE DO PRODUTO QUE DESEJA COMPRAR: ";
                   cin >> quantus;
                }
             }


             system("pause");
             system("cls");
             cout << "-------------------" << endl;
             cout << "    PAGAMENTO   " << endl;
             cout << "-------------------" << endl;

             valortotal = preco[opcus] * quantus;

             cout << " ________________________" << endl;
             cout << "| PRODUTO: " << produtos[opcus] << "  \t|" << endl;
             cout << "| QUANTIDADE: " << quantus << "      \t|" << endl;
             cout << "| PREÇO TOTAL: " << valortotal <<"    \t|"<<  endl;
             cout << "|_______________________|" << endl;
             cout << "\n VALOR QUE SERÁ DADO PARA O PAGAMENTO: ";
             cin >> valorpago;

             while(valorpago < valortotal){
                cout << "\n DINHEIRO INSUFICIENTE! \n\n DESEJA CANCELAR A PROVA? \n [S]- SIM \n [N]- NÃO\n RESPOSTA: ";
                cin >> confirm;

                while(confirm != 'S' && confirm != 's' && confirm != 'N' && confirm != 'n'){
                     cout << "\n OPÇÃO INVÁLIDA! TENTE NOVAMENTE. \n\n DESEJA CANCELAR A COMPRA? [S]- SIM\n [N]- NÃO\n RESPOSTA: ";
                     cin >> confirm;
                }

                if(confirm == 'S' || confirm == 's'){
                    break;
                }

                if(confirm == 'N' || confirm == 'n'){
                    cout << "\n VALOR QUE SERÁ DADO PARA O PAGAMENTO: ";
                    cin >> valorpago;
                }
              }

             if(confirm == 'S' || confirm == 's'){
                break;
             }

             cout << "\n TROCO: R$" << valorpago - valortotal;

             faturamentoatual += (quantus * preco[opcus]);
             quantidade[opcus] -= quantus;

             cout << "\n\n DESEJA COMPRAR MAIS ALGUMA COISA? \n [S]- SIM \n [N]- NÃO\n RESPOSTA: ";
             cin >> confirm;


          }while(confirm == 'S' || confirm == 's');

        }

    }while(opcao != 3);

    cout << "\n\n      VOLTE SEMPRE!" << endl;


return 0;
}