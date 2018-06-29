#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

class text_color  // CLASS usada no programa para modificar as cores de alguns textos (VERDE E VERMELHO)
{
public:
    enum
    {
        RED = FOREGROUND_RED,
        GREEN = FOREGROUND_GREEN,
        BLUE = FOREGROUND_BLUE,
        WHITE = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,
        GRAY = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
        BLACK = 0,
        BRIGHT = FOREGROUND_INTENSITY,
    };
public:
    text_color()
    {
        hout = GetStdHandle(STD_OUTPUT_HANDLE);
    }
    void set(int color)
    {
        SetConsoleTextAttribute(hout, color);
    }
    void reset()
    {
        SetConsoleTextAttribute(hout, GRAY);
    }
private:
    HANDLE hout;
};
struct estrutura // ESTRUTURA DA SALA. STRUCT.
{
    char filme[25]= {0};
    int Mcentro [10][10]= {};
    int MlateralE[4][10]= {};
    int MlateralD[4][10]= {};

};
void chamadadevalores(estrutura sala[]) // função que pega os valores no arquivo e atribui a variavel
{
    ifstream in;
    in.open("save.txt");
    for(int i=0; i<7; i++)
    {
        for(int j=0; j<25 ; j++)
        {
            in >> sala[i].filme[j];
            if(sala[i].filme[j]=='_'){  // NO ARQUIVO COLOCAMOS O "_" NO LUGAR DO ESPAÇO PARA NAO FICAR O VAZIO, POIS QUANDO VOLTAVAMOS PARA A
                                            //STRING ELE NAO CONSIDERAVA O VAZIO COMO UM VALOR E COLOCAVA NO LUGAR DA VARIAVEL
                                            // ASSIM QUE CHAMAMOS DE VOLTA O VALOR, ONDE TIVER "_" SUBSTITUIMOS POR ESPAÇO

                sala[i].filme[j]=' ';
            }
        }
    }



    for (int i=0; i<7; i++)
    {
        for(int j=0; j<10; j++)
        {
            for (int k=0; k<10; k++)
            {
                in >> sala[i].Mcentro[j][k];
            }
        }
    }
    for (int i=0; i<7; i++)
    {
        for(int j=0; j<4; j++)
        {
            for (int k=0; k<10; k++)
            {
                in >> sala[i].MlateralD[j][k];
                in >> sala[i].MlateralE[j][k];
            }
        }
    }
}
void retornodevalores(estrutura sala[])// função que salva no arquivo os valores das variaveis
{
    ofstream out;
    out.open("save.txt");
    for(int i=0; i<7; i++)
    {
        for(int j=0; j<25 ; j++)
        {
             if (sala[i].filme[j]==' '){
                out << "_" << endl;           // NO ARQUIVO COLOCAMOS O "_" NO LUGAR DO ESPAÇO PARA NAO FICAR O VAZIO, POIS QUANDO VOLTAVAMOS PARA A
                                            //STRING ELE NAO CONSIDERAVA O VAZIO COMO UM VALOR E COLOCAVA NO LUGAR DA VARIAVEL
                                            // ASSIM QUE CHAMAMOS DE VOLTA O VALOR, ONDE TIVER "_" SUBSTITUIMOS POR ESPAÇO
             }
             else
            out << sala[i].filme[j]<< endl;// o ENDL no final é para colocar o valor de uma variavel por linha
        }
    }
    for (int i=0; i<7; i++)
    {
        for(int j=0; j<10; j++)
        {
            for (int k=0; k<10; k++)
            {
                out << sala[i].Mcentro[j][k]<<endl;
            }
        }
    }
    for (int i=0; i<7; i++)
    {
        for(int j=0; j<4; j++)
        {
            for (int k=0; k<10; k++)
            {
                out << sala[i].MlateralD[j][k]<<endl;
                out << sala[i].MlateralE[j][k]<<endl;
            }
        }
    }// saida de uma variavel
    out.close(); // não oesqueça de fechar...

}

void reseta (estrutura sala[]) // função que reseta os assentos de uma sala especifica.
{
    for(int i=0; i<7; i++)
    {
        for(int j=0; j<10; j++)
        {
            for(int k=0; k<10; k++)
            {
                sala[i].Mcentro [j][k]= 0;
            }
        }
    }
    for(int i=0; i<7; i++)
    {
        for(int j=0; j<4; j++)
        {
            for(int k=0; k<10; k++)
            {
                sala[i].MlateralE[j][k]= 0;
                sala[i].MlateralD[j][k]= 0;
            }
        }
    }

}
void imprimir (estrutura sala[],int n) // Função que imprimir uma sala especifica completa, todas as partes.
{
    text_color con;

    cout << "\n\n       LATERAL DIREITA              CENTRO              LATERAL ESQUERDA   \n\n";

    for (int j=0; j<10; j++)
    {
        cout << "           ";
        for(int k=0; k<4; k++)
        {
            if(sala[n].MlateralD[k][j]==0)
            {
                con.set(text_color::GREEN | text_color::BRIGHT);
                cout << sala[n].MlateralD[k][j] << " ";
            }
            else
            {
                con.set(text_color::RED | text_color::BRIGHT);
                cout << sala[n].MlateralD[k][j] << " ";
            }
        }
        cout << "           ";
        for(int k=0; k<10; k++)
        {
            if(sala[n].Mcentro[k][j]==0)
            {
                con.set(text_color::GREEN | text_color::BRIGHT);
                cout << sala[n].Mcentro[k][j] << " ";
            }
            else
            {
                con.set(text_color::RED | text_color::BRIGHT);
                cout << sala[n].Mcentro[k][j] << " ";
            }
        }
        cout << "           ";
        for(int k=0; k<4; k++)
        {
            if(sala[n].MlateralE[k][j]==0)
            {
                con.set(text_color::GREEN | text_color::BRIGHT);
                cout << sala[n].MlateralE[k][j] << " ";
            }
            else
            {
                con.set(text_color::RED | text_color::BRIGHT);
                cout << sala[n].MlateralE[k][j] << " ";
            }
        }
        con.reset();
        cout << endl;

    }
}


void imprimir1 (estrutura sala[],int n) // Função que imprimir a parte LATERAL DIREITA de uma sala especifica.
{
    system("cls");

    text_color con;

    cout << "\n\n       LATERAL DIREITA\n\n";

    for (int j=0; j<10; j++)
    {
        cout << "        ["<< (char)('A'+j)<<"] ";
        for(int k=0; k<4; k++)
        {
            if(sala[n].MlateralD[k][j]==0)
            {
                con.set(text_color::GREEN | text_color::BRIGHT);
                cout << sala[n].MlateralD[k][j] << " ";
            }
            else
            {
                con.set(text_color::RED | text_color::BRIGHT);
                cout << sala[n].MlateralD[k][j] << " ";
            }
        }
        con.reset();
        cout << endl;
    }
    cout << endl;
}
void imprimir2 (estrutura sala[],int n)// Função que imprimir a parte CENTRO de uma sala especifica.
{
    system("cls");

    text_color con;

    cout << "\n\n                 CENTRO\n\n";

    for (int j=0; j<10; j++)
    {
        cout << "        ["<< (char)('A'+j)<<"] ";
        for(int k=0; k<10; k++)
        {
            if(sala[n].Mcentro[k][j]==0)
            {
                con.set(text_color::GREEN | text_color::BRIGHT);
                cout << sala[n].Mcentro[k][j] << " ";
            }
            else
            {
                con.set(text_color::RED | text_color::BRIGHT);
                cout << sala[n].Mcentro[k][j] << " ";
            }
        }
        con.reset();
        cout << endl;
    }
    cout << endl;

}
void imprimir3 (estrutura sala[],int n)// Função que imprimir a parte LATERAL ESQUERDA de uma sala especifica.
{
    system("cls");

    text_color con;

    cout << "\n\n       LATERAL ESQUERDA\n\n";

    for (int j=0; j<10; j++)
    {
        cout << "        ["<< (char)('A'+j)<<"] ";
        for(int k=0; k<4; k++)
        {
            if(sala[n].MlateralE[k][j]==0)
            {
                con.set(text_color::GREEN | text_color::BRIGHT);
                cout << sala[n].MlateralE[k][j] << " ";
            }
            else
            {
                con.set(text_color::RED | text_color::BRIGHT);
                cout << sala[n].MlateralE[k][j] << " ";
            }
        }
        con.reset();
        cout << endl;
    }
    cout << endl;
}
void filmes (estrutura sala[])// Função que imprimi a lista de filmes/sala e seu nome.
{
    cout << "   Filmes em cartaz: \n\n";
    for (int i=0; i<7; i++)
    {
        cout <<"   ";
        for(int j=0; sala[i].filme[j]!=0; j++)
        {
            cout<< sala[i].filme[j];
        }

        cout << " - Sala " << i+1 << endl;

    }

}
void gerenciar (estrutura sala[], int n, int erro)// Função para gerenciar as salas e fazer alteraçoes do tipo: MUDAR NOME DA SALA E RESETAR OS ASSENTOS.
{
    char x;
    int k;
    system("cls");

    cout << "          SALA " << n+1<<endl<<endl
         << " 1- Mudar o nome da sala "<<endl
         << " 2- Resetar os assentos da sala"<<endl
         << " 0- Voltar ao menu principal"<<endl<< " ";
    if(erro==1)
    {
        cout << "Opção Invalida!! "<< endl << " ";
        erro=0;
    }
    cin >> k;

    switch(k)
    {
    case 0:
        break;
    case 1:// MUDAR O NOME DA SALA
        system("cls");
        cout<< "Insira o Nome do Filme da Sala "<< n+1 << " : " ;
        for(int i=0; i<25; i++){
            sala[n].filme[i]=' ';
        }
        cin.ignore();
        cin.getline(sala[n].filme, 25);
        break;
    case 2:// RESETAR OS ASSENTOS DA SALA
        system("cls");
        cout<< "\n Deseja resetar a sala "<< n+1 << "? Limpar todos os assentos? (S/N): ";
        cin >> x;
        do
        {
            if(x=='S'|| x=='s')
            {
                reseta(sala);
                return;
            }
            else if(x=='n'||x=='N')
            {
                return;
            }
            else
            {
                system("cls");
                cout << " Opçao Invalida!!\n Deseja resetar a sala "<< n+1 << "? Limpar todos os assentos? (S/N): ";
                cin >> x;
            }

        }
        while(x!='S'|| x!='s'|| x!='n'||x!='N');
        break;
    default:// ERRO RECEBE 1 E CHAMA A FUNÇÃO NOVAMENTE, ASSIM QUANDO ERRO==1 IMPRIMIRA A MENSAGEM APOS O MENU DE OPÇÃO INVALIDA.
        erro=1;
        gerenciar(sala, n, erro);

    }
}
void mudanca (estrutura sala[], int n, int z, char col, int lin)// Função responsavel por reservar os assentos.
{
    int k, erro2=0;//VARIAVEL ERRO SERVE PARA SER MODIFICADA PARA 1 CASO SEJA DIGITADO UMA COISA NÃO ACEITA NO CIN E
                   //ASSIM LOGO DEPOIS SE A VARIAVEL ERRO FOR OUTRO VALOR QUE NÃO SEJA ZERO ELE EMITIRA UMA MENSAGEM
                   //DE ERRO E PEDIRA A ENTRADA NOVAMENTE

    if(z==1)// RESERVAR OS ASSENTOS DA PARTE LATERAL DIREITA DA SALA.
    {
        do
        {
            if(sala[n].MlateralD[lin-1][col-'a']==0)
            {
                sala[n].MlateralD[lin-1][col-'a']=1;
                imprimir1 (sala, n);
                cout << "   \nDeseja alterar outro assento? \n"
                     << "   1- Sim\n"
                     << "   2- Não\n";
                voltar1k:
                cin >> k;
                if(k!=1 && k!=2)// IMPRIMIR OPCAO INVALIDA
                {
                    cout << "    Opção Invalida!!\n";
                    goto voltar1k;
                }
                if(k==1)
                {
                    erro2=0;

voltar5:
                    if(erro2==1)// IMPRIMIR OPCAO INVALIDA
                    {
                        imprimir1 (sala, n);
                        cout << "    Opção Invalida!!\n";
                    }
                    cout <<"    Digite o assento que deseja reserva (Primeiro linha, depois coluna).\n";

                    cin >> col >> lin;
                    if( !(((col>='a' && col <='j') || (col>='A' && col<= 'J')) && (lin>0 && lin <5)))// IMPRIMIR OPCAO INVALIDA
                    {
                        erro2=1;
                        goto voltar5;
                    }
                }

            }
            else
            {

                k=1;
                imprimir1 (sala, n);

                cout << "   O Assento ja esta ocupado. Escola outro\n"
                     << "   Digite o assento que deseja reserva.. (Primeiro linha, depois coluna).\n";

                cin >> col >> lin;
                if( !(((col>='a' && col <='j') || (col>='A' && col<= 'J')) && (lin>0 && lin <5)))// IMPRIMIR OPCAO INVALIDA
                {
                    erro2=1;
                    goto voltar5;
                }

            }
        }
        while(k==1);

    }
    else if(z==2)// RESERVAR OS ASSENTOS DA PARTE CENTRO DA SALA.
    {
        do
        {
            if(sala[n].Mcentro[lin-1][col-'a']==0)
            {
                sala[n].Mcentro[lin-1][col-'a']=1;
                imprimir2 (sala, n);
                cout << "Deseja alterar outro assento? \n"
                     << "1- Sim\n"
                     << "2- Não\n";
voltar2k:
                cin >> k;
                if(k!=1 && k!=2)// IMPRIMIR OPCAO INVALIDA
                {
                    cout << "    Opção Invalida!!\n";
                    goto voltar2k;
                }
                if(k==1)
                {
                    erro2=0;

voltar6:
                    if(erro2==1)// IMPRIMIR OPCAO INVALIDA
                    {
                        imprimir2 (sala, n);
                        cout << "    Opção Invalida!!\n";
                    }
                    cout <<" Digite o assento que deseja reserva.. (Primeiro linha, depois coluna).\n";
                    cin >> col >> lin;
                    if( !(((col>='a' && col <='j') || (col>='A' && col<= 'J')) && (lin>0 && lin <11)))// IMPRIMIR OPCAO INVALIDA
                    {
                        erro2=1;
                        goto voltar6;
                    }
                }

            }
            else
            {
                k=1;
                imprimir2 (sala, n);
                cout << " O Assento ja esta ocupado... Escola outro\n"
                     << " Digite o assento que deseja reserva.. (Primeiro linha, depois coluna).\n";
                cin >> col >> lin;
                if( !(((col>='a' && col <='j') || (col>='A' && col<= 'J')) && (lin>0 && lin <11)))// IMPRIMIR OPCAO INVALIDA
                {
                    erro2=1;
                    goto voltar6;
                }

            }
        }
        while(k==1);

    }
    else if (z==3)// RESERVAR OS ASSENTOS DA PARTE LATERAL ESQUERDA DA SALA.
    {
        do
        {
            if(sala[n].MlateralE[lin-1][col-'a']==0)
            {
                sala[n].MlateralE[lin-1][col-'a']=1;
                imprimir3 (sala, n);
                cout << "Deseja alterar outro assento? \n"
                     << "1- Sim\n"
                     << "2- Não\n";
                voltar3k:
                cin >> k;
                if(k!=1 && k!=2)// IMPRIMIR OPCAO INVALIDA
                {
                    cout << "    Opção Invalida!!\n";
                    goto voltar3k;
                }
                if(k==1)
                {
                    erro2=0;

voltar7:
                    if(erro2==1)// IMPRIMIR OPCAO INVALIDA
                    {
                        imprimir3 (sala, n);
                        cout << "    Opção Invalida!!\n";
                    }
                    cout <<" Digite o assento que deseja reserva.. (Primeiro linha, depois coluna).\n";
                    cin >> col >> lin;
                    if( !(((col>='a' && col <='j') || (col>='A' && col<= 'J')) && (lin>0 && lin <5)))// IMPRIMIR OPCAO INVALIDA
                    {
                        erro2=1;
                        goto voltar7;
                    }
                }

            }
            else
            {
                k=1;
                imprimir3 (sala, n);
                cout << " O Assento ja esta ocupado... Escola outro\n"
                     << " Digite o assento que deseja reserva.. (Primeiro linha, depois coluna).\n";
                cin >> col >> lin;
              if( !(((col>='a' && col <='j') || (col>='A' && col<= 'J')) && (lin>0 && lin <5)))// IMPRIMIR OPCAO INVALIDA
                {
                    erro2=1;
                    goto voltar7;
                }

            }
        }
        while(k==1);

    }

}
void menuf (estrutura sala[])// PRINCIPAL FUNÇÃO SO PROGRAMA, É A FUNÇÃO MENU.
{
    system("cls");

    int menu, n, cont, z, senha=123, xsenha, lin, erro;
    char col;

    cout << " Seja Bem Vindo a Central de Reserva!\n"
         << " 1- Reservar Assento \n"
         << " 2 - Gerenciar Salas \n\n"
         << " Insira a sua opção: ";

    retornodevalores(sala);// TODA VEZ QUE VOLTA/PASSA PELO MENU RETORNA OS VALORES PARA O ARQUIVO... ASSIM TODA VEZ QUE PASSAR PELO MENU É SALVO A ALTERAÇÃO QUE FOI REALIZADA.

    do
    {
        cin >>menu;
        if(menu!=1 && menu!=2)
            cout<< "    Opção invalida! Digite Novamente: ";
    }
    while (menu!=1 && menu!=2);
    if (menu==1) // PARA MENU==1 IRA RESERVAR ASSENTOS
    {
        system("cls");
        filmes (sala);
        cout << "   Digite o numero do filme que deseja reservar lugar (Digite 0 para voltar ao menu principal): ";
        do
        {
            cin >> n;
            if(n<0 || n>7)
            {
                cout<< "    Opção invalida! Digite Novamente: ";
            }
        }
        while (n<0 || n>7);

        n=n-1;
        if(n!=-1)
        {
            int erro1 = 0;
voltar:
            system("cls");
            imprimir (sala,n);
            cout << endl << "\n    Digite o local que deseja sentar...\n"
                 << "    1 - Lateral Direita \n"
                 << "    2 - Centro \n"
                 << "    3 - Lateral Esquerda \n";
            if(erro1==1)
            {
                cout << "    Opção Invalida!!\n";
            }
            cout<< "    Insira a sua opção (0 para voltar ao menu): ";

            cin >> z;
            if(z<0 || z>3)
            {
                erro1=1;
                goto voltar;
            }


            if(z==1)
            {
                erro1=0;
voltar2:
                imprimir1(sala, n);
                if(erro1==1)
                {
                    cout << "    Opção Invalida!!";
                }
                cout<< "\n    Digite o assento que deseja reservar (Primeiro linha, depois coluna): ";

                cin>> col >> lin;
                if( !(((col>='a' && col <='j') || (col>='A' && col<= 'J')) && (lin>0 && lin <5)))
                {
                    erro1=1;
                    goto voltar2;
                }
                mudanca(sala,n,z,col,lin);

            }
            else if(z==2)
            {
                erro1=0;
voltar3:
                imprimir2(sala, n);
                if(erro1==1)
                {
                    cout << "    Opção Invalida!!";
                }
                cout<< "\n    Digite o assento que deseja reservar (Primeiro linha, depois coluna): ";
                cin>> col >> lin;
                if( !(((col>='a' && col <='j') || (col>='A' && col<= 'J')) && (lin>0 && lin < 11)))
                {
                    erro1=1;
                    goto voltar3;
                }
                mudanca(sala,n,z,col,lin);
            }
            else if (z==3)
            {
                erro1=0;
voltar4:

                imprimir3(sala, n);
                if(erro1==1)
                {
                    cout << "    Opção Invalida!!";
                }
                cout<< "\n    Digite o assento que deseja reservar (Primeiro linha, depois coluna): ";
                cin>> col >> lin;
                if( !(((col>='a' && col <='j') || (col>='A' && col<= 'J')) && (lin>0 && lin <5)))
                {
                    erro1=1;
                    goto voltar4;
                }
                mudanca(sala,n,z,col,lin);
            }
        }
    }
    if (menu==2)// IRÁ PEDIR A SENHA DE ADMINISTRADOR E ENTRAR NA PARTE DE GERENCIAMENTO DAS SALAS
    {
        do
        {
            cout<< "\n    Digite a senha de administrador: ";
            cin >> xsenha;
            if (xsenha == senha)
            {

                cont=0;
                do
                {


                    system("cls");
                    filmes (sala);
                    if(cont==0)
                    {
                        cout << "\n    Digite a sala que deseja acessar as configuraçoes (Digite 0 para voltar ao menu principal): ";
                        cont++;
                    }
                    else {
                        retornodevalores(sala);// TODA VEZ QUE VOLTA/PASSA PELO MENU RETORNA OS VALORES PARA O ARQUIVO... ASSIM TODA VEZ QUE PASSAR PELO MENU É SALVO A ALTERAÇÃO QUE FOI REALIZADA.

                            cout << "    Alteraçao realizada com sucesso!! \n\n Caso queira modificar outra sala, digite a sala que deseja acessar\n as configuraçoes ou digite 0 para voltar ao menu principal: ";
                    }
                    do
                    {
                        cin >> n;
                        if(n<0 || n>7)
                        {
                            cout<< "    Opção invalida! Digite Novamente: ";
                        }
                    }
                    while (n<0 || n>7);

                    n=n-1;
                    if(n!=-1)
                    {
                        erro=0;
                        gerenciar(sala, n, erro);
                    }
                }
                while(n!=-1);
            }
            else
            {
                do
                {
                    system("cls");
                    cout<< "    Senha incorreta! Digite 0 para voltar ao menu ou digite a senha novamente: ";
                    cin >> xsenha;
                }
                while(xsenha !=senha && xsenha!=0);

            }

            xsenha=n+1;

        }
        while(xsenha);
    }

}
int main()
{
    setlocale(LC_ALL,"Portuguese");


    int invariavel=0;// Variavel que serve para que o programa fique rodando e so feche quando aperta o X na tela inicial.
    estrutura sala[7];//Estrutura das salas
    chamadadevalores(sala);// Funcão que pega os valores no arquivo e atribui as variaveis

    do
    {
        menuf(sala);// Função principal. FUNÇÃO MENU.
    }
    while(invariavel==0);

    return 0;
}
