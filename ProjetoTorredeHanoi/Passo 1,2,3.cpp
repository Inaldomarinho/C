#include <iostream>
#include <stdlib.h>

using namespace std;

int n;

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

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int dificuldade;

    do
    {
        system("cls");
        menu();

        if(n==1)
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
                cin>> dificuldade;
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
