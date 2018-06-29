#include <iostream>
#include <stdlib.h>

using namespace std;

int n, x, dificuldade;
int matriz[7][3]= {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{1,0,0},{2,0,0},{3,0,0}};
int matriz2[7][3]= {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{1,0,0},{2,0,0},{3,0,0}};
int cont0, disco, coluna;
char str1[4]= {'1','2','3','\0'};
bool emcima, vercoluna, verdisco, fim, vernumero, vernumero1, vernumero2;
int jogada=-1, jogada2=-1, vitoria=0, vitoria2=0, rodada=1;
char nome1 [30], nome2 [30], mult;

void menu()
{

    cout << "    .___  ___.  _______ .__   __.  __    __\n"
         << "    |   \\/   | |   ____||  \\ |  | |  |  |  |\n"
         << "    |  \\  /  | |  |__   |   \\|  | |  |  |  |\n"
         << "    |  |\\/|  | |   __|  |  . `  | |  |  |  |\n"
         << "    |  |  |  | |  |____ |  |\\   | |  `--'  |\n"
         << "    |__|  |__| |_______||__| \\__|  \\______/ \n\n\n"
         << "          1-JOGAR          2-INSTRUÇÕES\n\n"
         << "                  3-SAIR\n\n";

    cout<< "\n    Digite a opção desejada: ";
    cin >> n;
}
void jogar()
{
    system("cls");
    cout <<"\n\n  "<<nome1<<", ESCOLHA O NIVEL DE DIFICULDADE\n\n"
         << "  1- Fácil    (3 discos)\n"
         << "  2- Médio    (5 discos)\n"
         << "  3- Difícil  (7 discos)\n\n";
    cout<< "\n  Digite a opção desejada: ";
    cin >> dificuldade;

    while (dificuldade!=1 && dificuldade!=2 && dificuldade!=3)
    {
        cout<< "\n\n  Comando Inválido! Por favor digite novamente: ";
        cin >> dificuldade;
    }
}
void jogar2()
{
    system("cls");
    cout <<"\n\n  "<<nome1<<" e "<<nome2<<", ESCOLHAM O NIVEL DE DIFICULDADE\n\n"
         << "  1- Fácil    (3 discos)\n"
         << "  2- Médio    (5 discos)\n"
         << "  3- Difícil  (7 discos)\n\n";
    cout<<  "\n  Digite a opção desejada: ";
    cin >> dificuldade;

    while (dificuldade!=1 && dificuldade!=2 && dificuldade!=3)
    {
        cout<< "\n\n  Comando Inválido! Por favor digite novamente: ";
        cin >> dificuldade;
    }
}
void terminou()
{
    system("cls");
    cout << "\n\n";

    if(dificuldade==1)
    {
        for(int i=4; i<7; i++)
        {

            for(int j=0; j<3; j++)
            {

                cout << "              "<< matriz[i][j] << "  ";

            }

            cout << endl;
        }

    }
    else if(dificuldade==2)
    {
        for(int i=2; i<7; i++)
        {

            for(int j=0; j<3; j++)
            {

                cout << "              "<< matriz[i][j] << "  ";

            }

            cout << endl;
        }

    }
    else if(dificuldade==3)
    {
        for(int i=0; i<7; i++)
        {

            for(int j=0; j<3; j++)
            {

                cout << "              "<< matriz[i][j] << "  ";

            }

            cout << endl;
        }

    }
        cout<<"\n";

        for (int i=0; str1[i]!='\0'; i++)
        {
            cout << "             ["<< str1[i] << "] ";
        }

}
void terminou2()
{
    system("cls");
    cout << "\n\n";

    if(dificuldade==1)
    {
        for(int i=4; i<7; i++)
        {

            for(int j=0; j<3; j++)
            {

                cout << "              "<< matriz2[i][j] << "  ";

            }

            cout << endl;
        }

    }
    else if(dificuldade==2)
    {
        for(int i=2; i<7; i++)
        {

            for(int j=0; j<3; j++)
            {

                cout << "              "<< matriz2[i][j] << "  ";

            }

            cout << endl;
        }

    }
    else if(dificuldade==3)
    {
        for(int i=0; i<7; i++)
        {

            for(int j=0; j<3; j++)
            {

                cout << "              "<< matriz2[i][j] << "  ";

            }

            cout << endl;
        }

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
    if(mult!='N' && mult!='n')
    {
        cout << "  RODADA "<< rodada
             << "\n  --------"
             <<"\n\n  Vez de "<<nome1<<" jogar: "<<"\n\n";
    }
    else
    {
        cout<< "\n\n\n";

    }
    if(dificuldade==1)
    {
        for(int i=4; i<7; i++)
        {

            for(int j=0; j<3; j++)
            {

                cout << "              "<< matriz[i][j] << "  ";

            }

            cout << endl;
        }

    }
    else if(dificuldade==2)
    {
        for(int i=2; i<7; i++)
        {

            for(int j=0; j<3; j++)
            {

                cout << "              "<< matriz[i][j] << "  ";

            }

            cout << endl;
        }

    }
    else if(dificuldade==3)
    {
        for(int i=0; i<7; i++)
        {

            for(int j=0; j<3; j++)
            {

                cout << "              "<< matriz[i][j] << "  ";

            }

            cout << endl;
        }

    }
    cout<<"\n";

        for (int i=0; str1[i]!='\0'; i++)
        {
            cout << "             ["<< str1[i] << "] ";
        }
    jogada++;
    cout<< "\n\n\n  Número de Jogadas: " << jogada;


    //  VERIFICAÇOES DO DISCO  //


    do
    {
        cout << "\n\n  "<<nome1<<", digite o DISCO que deseja mudar de lugar: ";
        cin >> disco;
        if(dificuldade==1)
        {
            while (disco!=1 && disco!=2 && disco!=3)
            {
                cout<< "\n\n  Comando Inválido! Por favor digite novamente: ";
                cin>> disco;
            }
        }
        else if (dificuldade==2)
        {
            while (disco!=1 && disco!=2 && disco!=3 && disco!=4 && disco!=5)
            {
                cout<< "\n\n  Comando Inválido! Por favor digite novamente: ";
                cin>> disco;
            }
        }
        else
        {
            while (disco!=1 && disco!=2 && disco!=3 && disco!=4 && disco!=5 && disco!=6 && disco!=7)
            {
                cout<< "\n\n  Comando Inválido! Por favor digite novamente: ";
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
            cout << "\n  Esse DISCO não pode ser movido! Digite outro.";
        }
    }
    while(emcima==false|| (vernumero==false && vernumero1==false)||(vernumero1==false && vernumero2==false)||(vernumero==false &&vernumero2==false));


    //  VERIFICAÇOES DAS COLUNAS  //


    do
    {
        do
        {
            cout << "\n\n  Agora digite a coluna que deseja coloca-lo: ";
            cin >> coluna;

            while (coluna!=1 && coluna!=2 && coluna!=3)
            {
                cout<< "\n\n  Comando Inválido! Por favor digite novamente: ";
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
                cout<< "\n  "<<nome1<<", você esta colocando na mesma coluna.";
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
            cout<< "\n  Jogada Invalida. Há um DISCO menor nessa coluna.";
        }


    }
    while(verdisco==false);

    //  REALIZAÇÃO DO MOVIMENTO   //

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
void jogo2()
{
    system("cls");
    cout << "  RODADA "<< rodada
         << "\n  --------"
         << "\n\n  Vez de "<<nome2<<" jogar: "<<"\n\n";

    if(dificuldade==1)
    {
        for(int i=4; i<7; i++)
        {

            for(int j=0; j<3; j++)
            {

                cout << "              "<< matriz2[i][j] << "  ";

            }

            cout << endl;
        }

    }
    else if(dificuldade==2)
    {
        for(int i=2; i<7; i++)
        {

            for(int j=0; j<3; j++)
            {

                cout << "              "<< matriz2[i][j] << "  ";

            }

            cout << endl;
        }

    }
    else if(dificuldade==3)
    {
        for(int i=0; i<7; i++)
        {

            for(int j=0; j<3; j++)
            {

                cout << "              "<< matriz2[i][j] << "  ";

            }

            cout << endl;
        }

    }
    cout<<"\n";

        for (int i=0; str1[i]!='\0'; i++)
        {
            cout << "             ["<< str1[i] << "] ";
        }

    jogada2++;
    cout<< "\n\n\n  Número de jogadas: " << jogada2;


    //  VERIFICAÇOES DO DISCO  //

    do
    {
        cout << "\n\n  "<<nome2<<", digite o DISCO que deseja mudar de lugar: ";
        cin >> disco;
        if(dificuldade==1)
        {
            while (disco!=1 && disco!=2 && disco!=3)
            {
                cout<< "\n\n  Comando Inválido! Por favor digite novamente: ";
                cin>> disco;
            }
        }
        else if (dificuldade==2)
        {
            while (disco!=1 && disco!=2 && disco!=3 && disco!=4 && disco!=5)
            {
                cout<< "\n\n  Comando Inválido! Por favor digite novamente: ";
                cin>> disco;
            }
        }
        else
        {
            while (disco!=1 && disco!=2 && disco!=3 && disco!=4 && disco!=5 && disco!=6 && disco!=7)
            {
                cout<< "\n\n  Comando Inválido! Por favor digite novamente: ";
                cin>> disco;
            }
        }
        emcima=true;
        for(int i=0; i<7; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(matriz2[i][j]==disco)
                {
                    for(int z=1; i-z>=0; z++)
                    {
                        if(matriz2[i-z][j]!=0)
                            emcima=false;


                    }

                }
            }
        }
        vernumero=true;
        cont0=0;
        for(int i=0; i<7; i++)
        {
            if(matriz2[i][0]==disco)
            {
                i=7;
            }
            else if (matriz2[i][0]==0)
            {
                cont0++;
            }
            else if(disco>matriz2[i][0])
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
            if(matriz2[i][1]==disco)
            {
                i=7;
            }
            else if (matriz2[i][1]==0)
            {
                cont0++;
            }
            else if(disco>matriz2[i][1])
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
            if(matriz2[i][2]==disco)
            {
                i=7;
            }
            else if (matriz2[i][2]==0)
            {
                cont0++;
            }
            else if(disco>matriz2[i][2])
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
            cout << "\n  Esse DISCO não pode ser movido! Digite outro.";
        }
    }
    while(emcima==false|| (vernumero==false && vernumero1==false)||(vernumero1==false && vernumero2==false)||(vernumero==false &&vernumero2==false));

    //  VERIFICAÇÃO DAS COLUNAS   //


    do
    {
        do
        {
            cout << "\n\n  Agora digite a coluna que deseja coloca-lo: ";
            cin >> coluna;

            while (coluna!=1 && coluna!=2 && coluna!=3)
            {
                cout<< "\n\n  Comando Inválido! Por favor digite novamente: ";
                cin>> coluna;
            }
            vercoluna=true;

            cont0=0;
            for(int i=0; i<7; i++)
            {

                if(matriz2[i][coluna-1]==0)
                {
                    cont0++;
                }
            }
            if(cont0<7)
            {
                if(matriz2[cont0][coluna-1]==disco)
                {
                    vercoluna=false;
                }
            }
            if(vercoluna==false)
            {
                cout<< "\n  "<<nome2<<", você esta colocando na mesma coluna.";
            }

        }
        while(vercoluna==false);

        verdisco=true;

        for(int i=0; i<7; i++)
        {
            if(matriz2[i][coluna-1]!=0)
            {
                if(matriz2[i][coluna-1]<disco)
                {
                    verdisco=false;
                }
            }
        }
        if(verdisco==false)
        {
            cout<< "\n  Jogada Invalida. Há um DISCO menor nessa coluna.";
        }


    }
    while(verdisco==false);

    //  REALIZAÇÃO DO MOVIMENTO   //

    for(int i=0; i<7; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(matriz2[i][j]==disco)
            {
                matriz2[i][j]=0;
            }
        }
    }
    cont0=0;
    for(int i=0; i<7; i++)
    {

        if(matriz2[i][coluna-1]==0)
        {
            cont0++;
        }

    }

    matriz2[cont0-1][coluna-1]=disco;

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
            do
            {
                cont0=0;
                emcima=true, vercoluna=true, verdisco=true, fim=false, vernumero=true, vernumero1=true, vernumero2=true;
                jogada=-1, jogada2=-1,  vitoria=0, vitoria2=0, rodada=0;


                system("cls");
                cout<<"\n\n    Voce deseja jogar com mais outra pessoa?(S/N): ";
                cin>>mult;
                while (mult!='s' && mult!='S' && mult!='n' && mult!='N')
                {
                    cout<< "\n\n    Comando Inválido! Por favor digite novamente: ";
                    cin>> mult;
                }


                if(mult!='s' && mult!='S')
                {
                    system("cls");
                    cout<<"\n\n    Digite seu nome: ";
                    cin.ignore();
                    cin.getline(nome1,30);

                }
                else
                {
                    system("cls");
                    cout<<"\n\n    Jogador 1, digite seu nome: ";
                    cin.ignore();
                    cin.getline(nome1,30);
                    cout<<"\n\n    Jogador 2, digite seu nome: ";
                    cin.getline(nome2,30);
                }
                if(mult!='s' && mult!='S')
                {
                    jogar();
                }
                else
                {
                    jogar2();
                }
                if (dificuldade==1)
                {
                    matriz[0][0]=0,matriz2[0][0]=0;
                    matriz[0][1]=0,matriz2[0][1]=0;
                    matriz[0][2]=0,matriz2[0][2]=0;
                    matriz[1][0]=0,matriz2[1][0]=0;
                    matriz[1][1]=0,matriz2[1][1]=0;
                    matriz[1][2]=0,matriz2[1][2]=0;
                    matriz[2][0]=0,matriz2[2][0]=0;
                    matriz[2][1]=0,matriz2[2][1]=0;
                    matriz[2][2]=0,matriz2[2][2]=0;
                    matriz[3][0]=0,matriz2[3][0]=0;
                    matriz[3][1]=0,matriz2[3][1]=0;
                    matriz[3][2]=0,matriz2[3][2]=0;
                    matriz[4][0]=1,matriz2[4][0]=1;
                    matriz[4][1]=0,matriz2[4][1]=0;
                    matriz[4][2]=0,matriz2[4][2]=0;
                    matriz[5][0]=2,matriz2[5][0]=2;
                    matriz[5][1]=0,matriz2[5][1]=0;
                    matriz[5][2]=0,matriz2[5][2]=0;
                    matriz[6][0]=3,matriz2[6][0]=3;
                    matriz[6][1]=0,matriz2[6][1]=0;
                    matriz[6][2]=0,matriz2[6][2]=0;

                }
                else if(dificuldade==2)
                {
                    matriz[0][0]=0,matriz2[0][0]=0;
                    matriz[0][1]=0,matriz2[0][1]=0;
                    matriz[0][2]=0,matriz2[0][2]=0;
                    matriz[1][0]=0,matriz2[1][0]=0;
                    matriz[1][1]=0,matriz2[1][1]=0;
                    matriz[1][2]=0,matriz2[1][2]=0;
                    matriz[2][0]=1,matriz2[2][0]=1;
                    matriz[2][1]=0,matriz2[2][1]=0;
                    matriz[2][2]=0,matriz2[2][2]=0;
                    matriz[3][0]=2,matriz2[3][0]=2;
                    matriz[3][1]=0,matriz2[3][1]=0;
                    matriz[3][2]=0,matriz2[3][2]=0;
                    matriz[4][0]=3,matriz2[4][0]=3;
                    matriz[4][1]=0,matriz2[4][1]=0;
                    matriz[4][2]=0,matriz2[4][2]=0;
                    matriz[5][0]=4,matriz2[5][0]=4;
                    matriz[5][1]=0,matriz2[5][1]=0;
                    matriz[5][2]=0,matriz2[5][2]=0;
                    matriz[6][0]=5,matriz2[6][0]=5;
                    matriz[6][1]=0,matriz2[6][1]=0;
                    matriz[6][2]=0,matriz2[6][2]=0;


                }
                else
                {
                    matriz[0][0]=1,matriz2[0][0]=1;
                    matriz[0][1]=0,matriz2[0][1]=0;
                    matriz[0][2]=0,matriz2[0][2]=0;
                    matriz[1][0]=2,matriz2[1][0]=2;
                    matriz[1][1]=0,matriz2[1][1]=0;
                    matriz[1][2]=0,matriz2[1][2]=0;
                    matriz[2][0]=3,matriz2[2][0]=3;
                    matriz[2][1]=0,matriz2[2][1]=0;
                    matriz[2][2]=0,matriz2[2][2]=0;
                    matriz[3][0]=4,matriz2[3][0]=4;
                    matriz[3][1]=0,matriz2[3][1]=0;
                    matriz[3][2]=0,matriz2[3][2]=0;
                    matriz[4][0]=5,matriz2[4][0]=5;
                    matriz[4][1]=0,matriz2[4][1]=0;
                    matriz[4][2]=0,matriz2[4][2]=0;
                    matriz[5][0]=6,matriz2[5][0]=6;
                    matriz[5][1]=0,matriz2[5][1]=0;
                    matriz[5][2]=0,matriz2[5][2]=0;
                    matriz[6][0]=7,matriz2[6][0]=7;
                    matriz[6][1]=0,matriz2[6][1]=0;
                    matriz[6][2]=0,matriz2[6][2]=0;

                }

                while(fim==false)
                {
                    jogo();
                    if(mult!='N' && mult!='n')
                    {
                        jogo2();
                    }
                    rodada++;
                    if(dificuldade==1)
                    {
                        if((matriz[0][1]==0 && matriz[1][1]==0 && matriz[2][1]==0 && matriz[3][1]==0 && matriz[4][1]==1 && matriz[5][1]==2 && matriz[6][1]==3 ) || (matriz[0][2]==0 && matriz[1][2]==0 && matriz[2][2]==0 && matriz[3][2]==0 && matriz[4][2]==1 && matriz[5][2]==2 && matriz[6][2]==3 ))
                        {

                            terminou();
                            fim=true;
                            x=700;
                            vitoria=1;

                        }
                        if((matriz2[0][1]==0 && matriz2[1][1]==0 && matriz2[2][1]==0 && matriz2[3][1]==0 && matriz2[4][1]==1 && matriz2[5][1]==2 && matriz2[6][1]==3 ) || (matriz2[0][2]==0 && matriz2[1][2]==0 && matriz2[2][2]==0 && matriz2[3][2]==0 && matriz2[4][2]==1 && matriz2[5][2]==2 && matriz2[6][2]==3 ))
                        {

                            terminou2();
                            fim=true;
                            x=700;
                            vitoria2=1;

                        }
                    }
                    else if(dificuldade==2)
                    {
                        if((matriz[0][1]==0 && matriz[1][1]==0 && matriz[2][1]==1 && matriz[3][1]==2 && matriz[4][1]==3 && matriz[5][1]==4 && matriz[6][1]==5 ) || (matriz[0][2]==0 && matriz[1][2]==0 && matriz[2][2]==1 && matriz[3][2]==2 && matriz[4][2]==3 && matriz[5][2]==4 && matriz[6][2]==5 ))
                        {

                            terminou();
                            fim=true;
                            x=3100;
                            vitoria=1;

                        }
                        if((matriz2[0][1]==0 && matriz2[1][1]==0 && matriz2[2][1]==1 && matriz2[3][1]==2 && matriz2[4][1]==3 && matriz2[5][1]==4 && matriz2[6][1]==5 ) || (matriz2[0][2]==0 && matriz2[1][2]==0 && matriz2[2][2]==1 && matriz2[3][2]==2 && matriz2[4][2]==3 && matriz2[5][2]==4 && matriz2[6][2]==5 ))
                        {

                            terminou2();
                            fim=true;
                            x=3100;
                            vitoria2=1;

                        }
                    }
                    else
                    {
                        if((matriz[0][1]==1 && matriz[1][1]==2 && matriz[2][1]==3 && matriz[3][1]==4 && matriz[4][1]==5 && matriz[5][1]==6 && matriz[6][1]==7 ) || (matriz[0][2]==1 && matriz[1][2]==2 && matriz[2][2]==3 && matriz[3][2]==4 && matriz[4][2]==5 && matriz[5][2]==6 && matriz[6][2]==7 ))
                        {

                            terminou();
                            fim=true;
                            x=12700;
                            vitoria=1;

                        }
                        if((matriz2[0][1]==1 && matriz2[1][1]==2 && matriz2[2][1]==3 && matriz2[3][1]==4 && matriz2[4][1]==5 && matriz2[5][1]==6 && matriz2[6][1]==7 ) || (matriz2[0][2]==1 && matriz2[1][2]==2 && matriz2[2][2]==3 && matriz2[3][2]==4 && matriz2[4][2]==5 && matriz2[5][2]==6 && matriz2[6][2]==7 ))
                        {

                            terminou2();
                            fim=true;
                            x=12700;
                            vitoria2=1;

                        }
                    }
                }
                if(mult!='s' && mult!='S')
                {
                    jogada++;
                    cout<< "\n\n  Número de Jogadas: " << jogada
                        << "\n\n  Pontuação total: " << x/jogada <<"%";
                    if((x/jogada)==100)
                    {
                        cout<<"\n\n  Parabéns "<<nome1<<"!!";
                    }
                    else if((x/jogada)>=70)
                    {
                        cout<<"\n\n  Quase lá "<<nome1<<"!!";
                    }
                    else
                    {
                        cout<<"\n\n  "<<nome1<<", você conseguiu! Mas precisamos melhorar.";
                    }

                    cout<< "\n\n\n           1-VOLTAR AO MENU            3-SAIR\n"
                        << "\n                      5-JOGAR NOVAMENTE\n\n\n"
                        << "  "<<nome1<<", digite a opção desejada: ";
                    cin >> n;

                    while (n!=1 && n!=3 && n!=5)
                    {
                        cout<< "\n\n  Comando Inválido! Por favor digite novamente: ";
                        cin>> n;
                    }
                }
                else
                {
                    if(vitoria==1 && vitoria2==1)
                    {
                        jogada++;
                        cout<< "\n\n  Número de Jogadas: " << jogada
                            << "\n\n  Pontuação total: " << x/jogada <<"%";
                        cout<<"\n\n  Parabéns "<<nome1<<" e "<<nome2<<"!! Vocês empataram!\n"
                            <<"\n  Que tal irem mais uma para desempatar!?\n";

                        cout<< "\n\n\n           1-VOLTAR AO MENU            3-SAIR\n"
                            << "\n                      5-JOGAR NOVAMENTE\n\n\n"
                            << "  "<<nome1<<" e "<<nome2<<", digite a opção desejada: ";
                        cin >> n;

                        while (n!=1 && n!=3 && n!=5)
                        {
                            cout<< "\n\n  Comando Inválido! Por favor digite novamente: ";
                            cin>> n;
                        }

                    }
                    else if(vitoria==1)
                    {
                        jogada++;
                        cout<< "\n\n  Número de Jogadas: " << jogada
                            << "\n\n  Pontuação total: " << x/jogada <<"%";
                        cout<<"\n\n  Parabéns "<<nome1<<"!! Você foi o vencedor!\n"
                            <<"\n  "<<nome2<<", quem sabe na proxima ne!?\n";

                        cout<< "\n\n\n           1-VOLTAR AO MENU            3-SAIR\n"
                            << "\n                      5-JOGAR NOVAMENTE\n\n\n"
                            << "  "<<nome1<<" e "<<nome2<<", digite a opção desejada: ";
                        cin >> n;

                        while (n!=1 && n!=3 && n!=5)
                        {
                            cout<< "\n\n  Comando Inválido! Por favor digite novamente: ";
                            cin>> n;
                        }
                    }
                    else
                    {
                        jogada2++;
                        cout<< "\n\n  Número de Jogadas: " << jogada2
                            << "\n\n  Pontuação total: " << x/jogada2 <<"%";
                        cout<<"\n\n  Parabéns "<<nome2<<"!! Você foi o vencedor!\n"
                            <<"\n  "<<nome1<<", quem sabe na proxima né?!\n";

                        cout<< "\n\n\n           1-VOLTAR AO MENU            3-SAIR\n"
                            << "\n                      5-JOGAR NOVAMENTE\n\n\n"
                            << "  "<<nome1<<" e "<<nome2<<", digite a opção desejada: ";
                        cin >> n;

                        while (n!=1 && n!=3 && n!=5)
                        {
                            cout<< "\n\n  Comando Inválido! Por favor digite novamente: ";
                            cin>> n;
                        }

                    }
                }


            }
            while(n==5);

        }
        else
        {
            if(n==2)
            {
                system("cls");

                cout << "\n                         INSTRUÇÕES: \n\n"
                     << "  1- Apenas um DISCO poderia ser movido por vez\n"
                     << "  2- Nunca um DISCO maior deveria ficar por cima de um DISCO menor.\n"
                     << "  3- O numero de movimentos necessários para solucionar o jogo é:\n\n"
                     << "                -> 7 jogadas no modo fácil\n"
                     << "                -> 31 jogadas no modo médio\n"
                     << "                -> 127 jogadas no modo difícil\n\n\n"
                     << "  PARA O MODO MULTIPLAYER:\n\n"
                     << "  1- Cada jogador jogará uma vez por rodada\n"
                     << "  2- Após o segundo jogador da rodada jogar é que sera verificado \n"
                     << "     se há ganhador\n"
                     << "  3- Caso os dois jogadores vençam na mesma rodada haverá um empate.\n\n"
                     << "          1-VOLTAR AO MENU            3-SAIR\n";
                cin >> n;

                while (n!=1 && n!=3)
                {
                    cout<< "\n\n  Comando Inválido! Por favor digite novamente: ";
                    cin>> n;
                }
            }
        }

    }
    while(n!=3);

    system("cls");

    cout << "\n\n ______ _____ __  __    _____  ______         _  ____   _____  ____ \n"
         << "|  ____|_   _|  \\/  |  |  __ \\|  ____|       | |/ __ \\ / ____|/ __ \\\n"
         << "| |__    | | | \\  / |  | |  | | |__          | | |  | | |  __  |  | |\n"
         << "|  __|   | | | |\\/| |  | |  | |  __|     _   | | |  | | | |_ | |  | |\n"
         << "| |     _| |_| |  | |  | |__| | |____   | |__| | |__| | |__| | |__| |\n"
         << "|_|    |_____|_|  |_|  |_____/|______|   \\____/ \\____/ \\_____|\\____/\n\n\n\n";

    return 0;
}

