#include <iomanip>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include "Nos_fichiers/firstmenu.h"
#include "Correc_prof/game.h"
#include "Correc_prof/params.h"
#include "Nos_fichiers/Help.h"
#include "Correc_prof/gridmanagement.h"
#include "Nos_fichiers/Help.h"
#include "score.h"

using namespace std;

CMyParam Params;
void FirstMenu()
{

    int choice;     //menu choice


    //constantes du menu
    const int START_CHOICE = 1,
            HELP_CHOICE = 2,
            HIGHSCORE_CHOICE = 3,
            QUIT_CHOICE = 4;



    do
    {
        showMessageAccueil(); // Show Welcome screen
        sleep(1);
        cout<<endl<<endl<<"       * * * * * Menu Principal * * * * * "<<endl<<endl<<endl;
        showMenu(); // Display Menu
        cin >> choice;
        ClearScreen();

        //Validation  menu de  selection
        while (choice < START_CHOICE || choice > QUIT_CHOICE)
        {
            cout << "Entrez une valeur correcte:";
            cin >> choice;
        }

        //Si user ne veut pas quitter
        if (choice != QUIT_CHOICE)
        {
            switch (choice)
            {
            case START_CHOICE:
                ppal();
                break;

            case HELP_CHOICE:
                ClearScreen();
                showHelp();
                break;

            case HIGHSCORE_CHOICE:
                ClearScreen();
                AfficheHighScore();
                break;

            }
        }
    } while (choice != QUIT_CHOICE);


}
//Message accueil
void showMessageAccueil()
{
    cout << "* * * * * * * * * * * * * * Bienvenue sur Numbercrusher * * * * * * * * * * * *" << endl;
    sleep(1);
}



//Menu
void showMenu()
{
    cout << "       * * * * * * * * * * * * * * * * *" << endl
         << "       *         1. Start game         *" << endl
         << "       *         2. How to play        *" << endl
         << "       *         3. Highscores         *" << endl
         << "       *         4. Quit               *" << endl
         << "       * * * * * * * * * * * * * * * * *"<<endl;
}





