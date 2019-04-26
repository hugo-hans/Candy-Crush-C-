#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include "Nos_fichiers/Help.h"
#include "Correc_prof/game.h"
#include "Correc_prof/gridmanagement.h"
#include "Nos_fichiers/Help.h"

using namespace std;


//AIDE
void showHelp(){
    cout << "Choisir une option" <<endl << endl
         <<" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl
         <<" *  -Aligner 3 chiffres identiques ou plus pour les convertir en points.                   *"<<endl
         <<" *  -Si 4 chiffres identiques sont alignés, vous gagnez (chiffre*4)/2 points et un bonus   *"<<endl
         <<" *  -Si 5 chiffres identiques ou plus sont alignés, la ligne ou la colonne est entièrement *"<<endl
         <<" *  convertie en points et vous gagnez un bonus de points conséquent.                      *"<<endl
         <<" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl<<endl
         <<"2. Return Game" << endl << endl
         <<"3. Quit" <<endl;
    int choice;
    cin>>choice;

    switch (choice)
    {
    case 2:
        ppal();
        break;

    case 3:
        exit(0);
        break;

    }
    ClearScreen();
}

