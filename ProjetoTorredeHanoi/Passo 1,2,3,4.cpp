#include <iostream>
#include <stdlib.h>

using namespace std;

int n, x, dificuldade;
int matriz[7][3]= {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{1,0,0},{2,0,0},{3,0,0}};
int cont0, disco, coluna;
char str1[4]= {'1','2','3','\0'};
bool emcima, vercoluna, verdisco, fim, vernumero, vernumero1, vernumero2;
int jogada=-1;

void menu()
{

    cout << ".___  ___.  _______ .__   __.  __    __\n"
         << "|   \\/   | |   ____||  \\ |  | |  |  |  |\n"
         << "|  \\  /  | |  |__   |   \\|  | |  |  |  |\n"
         << "|  |\\/|  | |   __|  |  . `  | |  |  |  |\n"
         << "|  |  |  | |  |____ |  |\\   | |  `--'  |\n"
         << "|__|  |__| |_______||__| \\__|  \\______/ \n\n\n"
         << "          1-JOGAR          2-INSTRUÇÕES\n\n"
         << "                  3-SAIR\n\n";

    cin >> n;
}
void jogar()
{

    system("cls");
    cout << "\n\n  NIVEL DE DIFICULDADE\n\n"
         << "  1- Fácil    (3 discos)\n"
         << "  2- Médio    (5 discos)\n"
         << "  3- Difícil  (7 discos)\n\n";

    cin >> dificuldade;

    while (dificuldade!=1 && dificuldade!=2 && dificuldade!=3)
    {
        cout<< "\n\nComando Inválido! Por favor digite novamente: ";
        cin >> dificuldade;
    }
}
void terminou()
{
    system("cls");
    cout << "\n\n";

    for(int i=0; i<7; i++)
    {

        for(int j=0; j<3; j++)
        {

            cout << "              "<< matriz[i][j] << "  ";

        }

        cout << "  ["<< i+1<<"]"<< endl;
    }

    cout<<"\n";

    for (int i=0; str1[i]!='\0'; i++)
    {
        cout << "             ["<< str1[i] << "] ";
    }

}
void jogo()
{
    system("cls");
    cout << "\n\n";

    for(int i=0; i<7; i++)
    {

        for(int j=0; j<3; j++)
        {

            cout << "              "<< matriz[i][j] << "  ";

        }

        cout << endl;
    }

    cout<<"\n";

    for (int i=0; str1[i]!='\0'; i++)
    {
        cout << "             ["<< str1[i] << "] ";
    }
    jogada++;
    cout<< "\n\n\nNúmero de Jogadas: " << jogada;
    do
    {
        cout << "\n\nDigite o disco que deseja mudar de lugar: ";
        cin >> disco;
        if(dificuldade==1)
        {
            while (disco!=1 && disco!=2 && disco!=3)
            {
                cout<< "\n\nComando Inválido! Por favor digite novamente: ";
                cin>> disco;
            }
        }
        else if (dificuldade==2)
        {
            while (disco!=1 && disco!=2 && disco!=3 && disco!=4 && disco!=5)
            {
                cout<< "\n\nComando Inválido! Por favor digite novamente: ";
                cin>> disco;
            }
        }
        else
        {
            while (disco!=1 && disco!=2 && disco!=3 && disco!=4 && disco!=5 && disco!=6 && disco!=7)
            {
                cout<< "\n\nComando Inválido! Por favor digite novamente: ";
                cin>> disco;
            }
        }
        emcima=true;
        for(int i=0; i<7; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(matriz[i][j]==disco)
                {
                    for(int z=1; i-z>=0; z++)
                    {
                        if(matriz[i-z][j]!=0)
                            emcima=false;


                    }

                }
            }
        }
        vernumero=true;
        cont0=0;
        for(int i=0; i<7; i++)
        {
            if(matriz[i][0]==disco)
            {
                i=7;
            }
            else if (matriz[i][0]==0)
            {
                cont0++;
            }
            else if(disco>matriz[i][0])
            {
                vernumero=false;
            }
            if(cont0==7)
            {
                vernumero=true;
            }
        }
        vernumero1=true;
        cont0=0;
        for(int i=0; i<7; i++)
        {
            if(matriz[i][1]==disco)
            {
                i=7;
            }
            else if (matriz[i][1]==0)
            {
                cont0++;
            }
            else if(disco>matriz[i][1])
            {
                vernumero1=false;
            }
            if(cont0==7)
            {
                vernumero1=true;
            }
        }
        vernumero2=true;
        cont0=0;
        for(int i=0; i<7; i++)
        {
            if(matriz[i][2]==disco)
            {
                i=7;
            }
            else if (matriz[i][2]==0)
            {
                cont0++;
            }
            else if(disco>matriz[i][2])
            {
                vernumero2=false;
            }
            if(cont0==7)
            {
                vernumero2=true;
            }
        }

        if(emcima==false || (vernumero==false && vernumero1==false)||(vernumero1==false && vernumero2==false)||(vernumero==false &&vernumero2==false))
        {
            cout << "\nEsse disco não pode ser movido! Digite outro.";
        }
    }
    while(emcima==false|| (vernumero==false && vernumero1==false)||(vernumero1==false && vernumero2==false)||(vernumero==false &&vernumero2==false));
    do
    {
        do
        {
            cout << "\n\nDigite a coluna que deseja coloca-lo: ";
            cin >> coluna;

            while (coluna!=1 && coluna!=2 && coluna!=3)
            {
                cout<< "\n\nComando Inválido! Por favor digite novamente: ";
                cin>> coluna;
            }
            vercoluna=true;

            cont0=0;
            for(int i=0; i<7; i++)
            {

                if(matriz[i][coluna-1]==0)
                {
                    cont0++;
                }
            }
            if(cont0<7)
            {
                if(matriz[cont0][coluna-1]==disco)
                {
                    vercoluna=false;
                }
            }
            if(vercoluna==false)
            {
                cout<< "\nVocê esta colocando na mesma coluna.";
            }

        }
        while(vercoluna==false);

        verdisco=true;

        for(int i=0; i<7; i++)
        {
            if(matriz[i][coluna-1]!=0)
            {
                if(matriz[i][coluna-1]<disco)
                {
                    verdisco=false;
                }
            }
        }
        if(verdisco==false)
        {
            cout<< "\nJogada Invalida. Há um disco menor nessa coluna.";
        }


    }
    while(verdisco==false);

    for(int i=0; i<7; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(matriz[i][j]==disco)
            {
                matriz[i][j]=0;
            }
        }
    }
    cont0=0;
    for(int i=0; i<7; i++)
    {

        if(matriz[i][coluna-1]==0)
        {
            cont0++;
        }

    }

    matriz[cont0-1][coluna-1]=disco;

}


int main()
{
    setlocale(LC_ALL,"Portuguese");

    do
    {
        system("cls");
        menu();

        if(n==1)
        {
            cont0=0;
            emcima=true, vercoluna=true, verdisco=true, fim=false, vernumero=true, vernumero1=true, vernumero2=true;
            jogada=-1;

            jogar();
            if (dificuldade==1)
            {
                matriz[0][0]=0;
                matriz[0][1]=0;
                matriz[0][2]=0;
                matriz[1][0]=0;
                matriz[1][1]=0;
                matriz[1][2]=0;
                matriz[2][0]=0;
                matriz[2][1]=0;
                matriz[2][2]=0;
                matriz[3][0]=0;
                matriz[3][1]=0;
                matriz[3][2]=0;
                matriz[4][0]=1;
                matriz[4][1]=0;
                matriz[4][2]=0;
                matriz[5][0]=2;
                matriz[5][1]=0;
                matriz[5][2]=0;
                matriz[6][0]=3;
                matriz[6][1]=0;
                matriz[6][2]=0;

            }
            else if(dificuldade==2)
            {
                matriz[0][0]=0;
                matriz[0][1]=0;
                matriz[0][2]=0;
                matriz[1][0]=0;
                matriz[1][1]=0;
                matriz[1][2]=0;
                matriz[2][0]=1;
                matriz[2][1]=0;
                matriz[2][2]=0;
                matriz[3][0]=2;
                matriz[3][1]=0;
                matriz[3][2]=0;
                matriz[4][0]=3;
                matriz[4][1]=0;
                matriz[4][2]=0;
                matriz[5][0]=4;
                matriz[5][1]=0;
                matriz[5][2]=0;
                matriz[6][0]=5;
                matriz[6][1]=0;
                matriz[6][2]=0;

            }
            else
            {
                matriz[0][0]=1;
                matriz[0][1]=0;
                matriz[0][2]=0;
                matriz[1][0]=2;
                matriz[1][1]=0;
                matriz[1][2]=0;
                matriz[2][0]=3;
                matriz[2][1]=0;
                matriz[2][2]=0;
                matriz[3][0]=4;
                matriz[3][1]=0;
                matriz[3][2]=0;
                matriz[4][0]=5;
                matriz[4][1]=0;
                matriz[4][2]=0;
                matriz[5][0]=6;
                matriz[5][1]=0;
                matriz[5][2]=0;
                matriz[6][0]=7;
                matriz[6][1]=0;
                matriz[6][2]=0;

            }

            while(fim==false)
            {
                jogo();

                if(dificuldade==1)
                {
                    if((matriz[0][1]==0 && matriz[1][1]==0 && matriz[2][1]==0 && matriz[3][1]==0 && matriz[4][1]==1 && matriz[5][1]==2 && matriz[6][1]==3 ) || (matriz[0][2]==0 && matriz[1][2]==0 && matriz[2][2]==0 && matriz[3][2]==0 && matriz[4][2]==1 && matriz[5][2]==2 && matriz[6][2]==3 ))
                    {

                        terminou();
                        fim=true;
                        x=700;

                    }
                }
                else if(dificuldade==2)
                {
                    if((matriz[0][1]==0 && matriz[1][1]==0 && matriz[2][1]==1 && matriz[3][1]==2 && matriz[4][1]==3 && matriz[5][1]==4 && matriz[6][1]==5 ) || (matriz[0][2]==0 && matriz[1][2]==0 && matriz[2][2]==1 && matriz[3][2]==2 && matriz[4][2]==3 && matriz[5][2]==4 && matriz[6][2]==5 ))
                    {

                        terminou();
                        fim=true;
                        x=3100;

                    }
                }
                else
                {
                    if((matriz[0][1]==1 && matriz[1][1]==2 && matriz[2][1]==3 && matriz[3][1]==4 && matriz[4][1]==5 && matriz[5][1]==6 && matriz[6][1]==7 ) || (matriz[0][2]==1 && matriz[1][2]==2 && matriz[2][2]==3 && matriz[3][2]==4 && matriz[4][2]==5 && matriz[5][2]==6 && matriz[6][2]==7 ))
                    {

                        terminou();
                        fim=true;
                        x=12700;

                    }
                }
            }
            jogada++;
            cout<< "\n\nNúmero de Jogadas: " << jogada
                << "\n\nPontuação total: " << x/jogada <<" Pontos";

            cout<< "\n\n\n           1-VOLTAR AO MENU            3-SAIR\n";
            cin >> n;

            while (n!=1 && n!=3)
            {
                cout<< "\n\nComando Inválido! Por favor digite novamente: ";
                cin>> n;
            }

        }
        else
        {
            if(n==2)
            {
                system("cls");

                cout << "\n\n\n  1- Apenas um disco poderia ser movido por vez\n"
                     << "  2- Nunca um disco maior deveria ficar por cima de um disco menor.\n\n"
                     << "          1-VOLTAR AO MENU            3-SAIR\n";
                cin >> n;

                while (n!=1 && n!=3)
                {
                    cout<< "\n\nComando Inválido! Por favor digite novamente: ";
                    cin>> n;
                }
            }
        }

    }
    while(n!=3);

    system("cls");

    cout << "\n\n  FIM DE JOGO\n\n";

    return 0;
}

