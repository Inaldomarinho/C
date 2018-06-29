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
        }

        else
        {
            if(n==2)
            {
                system("cls");

            }
        }

    }
    while(n!=3);

    system("cls");

}
