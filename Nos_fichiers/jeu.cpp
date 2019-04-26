#include <time.h>
#include <iostream>
#include "Nos_fichiers/jeu.h"
#include "Nos_fichiers/parametres.h"
#include "Nos_fichiers/colors.h"
#include "score.h"
#include <string>
#include <fstream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <map>

using namespace std;

void Menu (CMat & Grid, CPosition & Pos, char & Direction, const CMyParam & Params, const unsigned int & Score)
{
    cout << "Saisir un indice de ligne : ";
    cin >> Pos.first;
    unsigned essai(0);
    while(Pos.first > 9)
    {
        if(essai == 3)
        {
            cout << "ERREUR INDICE" << endl;
            exit (EXIT_FAILURE);
        }
        cout <<"Mauvais indice de ligne. Saisissez un indice correct" << endl;
        cin >> Pos.first;
        ++essai;
    }
    essai = 0;
    ClearScreen();
    DisplayGrid(Pos, Grid, Params, Score);
    cout << "un indice de colonne : ";
    cin >> Pos.second;
    while(Pos.second > 9)
    {
        if(essai == 3)
        {
            cout << "ERREUR INDICE" << endl;
            exit (EXIT_FAILURE);
        }
        cout <<"Mauvais indice de colonne. Saisissez un indice correct" << endl;
        cin >> Pos.second;
        ++essai;
    }
    ClearScreen();
    DisplayGrid(Pos, Grid, Params, Score);
    cout<<   " et un sens de Deplacements : \n "
         <<  Params.MapParamChar.find("KeyLeft")->second << " pour aller à gauche, "
         <<  Params.MapParamChar.find("KeyDown")->second << " pour aller en bas, "
         <<  Params.MapParamChar.find("KeyRight")->second << " pour aller à droite, "
         <<  Params.MapParamChar.find("KeyUp")->second << " pour aller en haut "
         <<  Params.MapParamChar.find("KeyQuit")->second << " pour quitter "
         << endl;
    cin >> Direction;
    essai = 0;
    while(Direction != Params.MapParamChar.find("KeyQuit")->second && Direction != Params.MapParamChar.find("KeyLeft")->second && Direction != Params.MapParamChar.find("KeyDown")->second && Direction != Params.MapParamChar.find("KeyRight")->second && Direction != Params.MapParamChar.find("KeyUp")->second)
    {
        if(essai == 3)
        {
            cout << "ERREUR" << endl;
            exit (EXIT_FAILURE);
        }
        cout << "Mauvaise direction. Saisisssez une direction correcte" << endl;
        cin >> Direction;
        ++essai;

    }
} // Menu()

void MakeAMove (CMat & Grid, const CPosition & Pos, const char & Direction, const CMyParam & Params)
{
    unsigned NewLineNumber (Pos.first), NewColumnNumber (Pos.second);
    if (Direction == Params.MapParamChar.find("KeyLeft")->second )
        --NewColumnNumber;
    else if (Direction == Params.MapParamChar.find("KeyDown")->second)
        ++NewLineNumber;
    else if (Direction == Params.MapParamChar.find("KeyRight")->second)
        ++NewColumnNumber;
    else if (Direction == Params.MapParamChar.find("KeyUp")->second)
        --NewLineNumber;
    else
        exit (EXIT_FAILURE);
    swap (Grid [Pos.first][Pos.second], Grid [NewLineNumber][NewColumnNumber]);
} // MakeAMove ()

bool AtLeastThreeInARow (const CMat & Mat, CPosition & Pos, unsigned & HowMany, unsigned & WhatNumber)
{
    for (unsigned LineNumber = 0; LineNumber < Mat.size (); ++LineNumber)
    {
        for (unsigned ColNmber = 0; ColNmber < Mat.size () -2; ++ColNmber)
        {
            if (KImpossible == Mat[LineNumber][ColNmber]) continue;
            for (HowMany = 1; ColNmber + HowMany < Mat.size() && Mat [LineNumber][ColNmber] == Mat[LineNumber][ColNmber + HowMany]; ++HowMany);
            if (HowMany >= 3)
            {
                WhatNumber = Mat [LineNumber][ColNmber];
                Pos = make_pair (LineNumber, ColNmber);
                return true;
            }
        }
    }
    return false;
} // AtLeastThreeInARow ()

bool AtLeastThreeInAColumn (const CMat & Mat, CPosition & Pos, unsigned & HowMany, unsigned & WhatNumber)
{
    for (unsigned ColNmber = 0; ColNmber < Mat.size (); ++ColNmber)
    {
        for (unsigned LineNumber = 0; LineNumber < Mat.size () -2; ++LineNumber)
        {
            if (KImpossible == Mat[LineNumber][ColNmber]) continue;
            for (HowMany = 1; LineNumber + HowMany < Mat.size() && Mat [LineNumber][ColNmber] == Mat[LineNumber + HowMany][ColNmber]; ++HowMany);
            if (HowMany >= 3)
            {
                WhatNumber = Mat [LineNumber][ColNmber];
                Pos = make_pair (LineNumber, ColNmber);
                return true;
            }
        }
    }
    return false;
} // AtLeastThreeInAColumn ()

void RemovalInColumn (CMat & Mat, const CPosition & Pos, const unsigned & HowMany)
{
    unsigned Nb (0);
    unsigned Strike(0);

    for (; Pos.first + Nb + HowMany < Mat.size (); ++Nb)
    {
        Mat [Pos.first + Nb][Pos.second] = Mat [Pos.first + Nb + HowMany][Pos.second];
    }
    if (HowMany >= 5)
    {
        for(; Strike < 10; ++Strike)
        {
            Mat [Strike][Pos.second] = KImpossible;
        }
    }
    for (; Pos.first + Nb < Mat.size (); ++Nb)
        Mat [Pos.first + Nb][Pos.second] = KImpossible;

}



void RemovalInRow (CMat & Mat, CPosition & Pos, unsigned & HowMany)
{
    CPosition PosToRemove (Pos);
    if (HowMany >= 5)
    {
        PosToRemove.second = 0;
        for (unsigned i (0); i < Mat.size(); ++i)
        {
            RemovalInColumn (Mat, PosToRemove, 1);
            ++PosToRemove.second;
        }
        HowMany = 0;
    }
    for (unsigned i (0); i < HowMany; ++i)
    {
        RemovalInColumn (Mat, PosToRemove, 1);
        ++PosToRemove.second;
    }
}


int ComputeScore (const unsigned & HowMany, unsigned & WhatNumber)
{
    unsigned Buffer(0);
    Buffer = WhatNumber;
    WhatNumber = 0;
    if (HowMany == 4)
    {
        return (Buffer * 8);
    }
    else if (HowMany >= 5)
    {
        return (Buffer * 20);
    }
    else
    {
        return (Buffer * 2);
    }
}

int ppal ()
{
    srand (time (NULL));
    CMyParam Params;
    InitParams2(Params);
    LoadParams2 (Params);

    CMat Grid;
    InitGrid(Grid, 10);
    CPosition Pos;
    unsigned HowMany, WhatNumber (0);
    int Score(0);
    char Dirrection;
    string PlayerName;
    cout << "Pseudo : ";
    cin >> PlayerName;
    for (unsigned Count (0); Count < KMaxTimes; ++Count)
    {
        Pos.first=15;
        Pos.second=15;
        ClearScreen();
        DisplayGrid(Pos, Grid, Params, Score);
        Menu (Grid, Pos, Dirrection, Params, Score);
        cout << endl << "il vous reste " << KMaxTimes - Count << " tour(s)." << endl << endl;
        if (Params.MapParamChar.find("KeyQuit")->second == Dirrection) break;
        MakeAMove (Grid, Pos, Dirrection, Params);

        while (AtLeastThreeInAColumn (Grid, Pos, HowMany, WhatNumber))
        {
            RemovalInColumn (Grid, Pos, HowMany);
            Score += ComputeScore (HowMany, WhatNumber);
        }
        while (AtLeastThreeInARow (Grid, Pos, HowMany, WhatNumber))
        {
            RemovalInRow (Grid, Pos, HowMany);
            Score += ComputeScore (HowMany, WhatNumber);
        }

    }
    if (Score <= 50)
    {
        cout << "Your score is : " << Score << endl << "That's not so bad for a dummy ;)" << endl;
    }
    else if (Score <= 100)
    {
        cout << "Your score is : " << Score << endl << "That's an average performance, you have room for improvement." << endl;
    }
    else if (Score <= 150)
    {
        cout << "Your score is : " << Score << endl << "That's nice, keep it up!" << endl;
    }
    else if (Score <= 200)
    {
        cout << "Your score is : " << Score << endl << "You are becoming really good at this game!" << endl;
    }
    else if (Score <= 250)
    {
        cout << "Your score is : " << Score << endl << "WOW! GOD LIKE!" << endl;
    }
    SaveHighScore(Score, PlayerName);
    return 0;
}
