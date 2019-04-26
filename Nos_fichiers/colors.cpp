#include <iostream>
#include <iomanip>
#include "Nos_fichiers/colors.h"
#include "Correc_prof/type.h" //nos types
#include "Nos_fichiers/parametres.h" //nos parametres

using namespace std;



void ClearScreen()
{
    cout << "\033[H\033[2J";
}// ClearScreen ()

void Color (const string & Col)
{
    cout << "\033[" << Col.c_str () <<"m";
} // Color ()


void DisplaySelection (const CMat & Mat, const CMyParam & Param, const CPosition & Pos)
{
    cout << string (4, ' ');
    for (unsigned i (0); i < Mat.size (); ++i)
    {
        Color (Param.MapParamString.find("IndexColor")->second);

        cout << setw (2) << i;

        Color (Param.MapParamString.find("RowColor")->second);
        cout<< setw (2) << '|';
    }
    cout << endl;
    string Rule (4*Mat.size () + 1, '=');
    Rule = string (3, ' ') + Rule;


    Color (Param.MapParamString.find("LineColor")->second);
    cout << Rule << endl;
    unsigned LineNumber (0);
    for (const CVLine & Aline : Mat)
    {

        Color (Param.MapParamString.find("IndexColor")->second);

        cout << setw (2) << LineNumber++;
        Color (Param.MapParamString.find("RowColor")->second);

        cout << "||";
        for (unsigned i(0); i<Aline.size();++i)
        {
            if (KImpossible == Aline[i])
                cout << "  ";
            else
            {
                if(Aline[i] == 1)
                    Color (Param.MapParamString.find("MyColor")->second);
                if(Aline[i] == 2)
                {
                    Color (Param.MapParamString.find("MyColor")->second);
                    Color ("31");
                }
                if(Aline[i] == 3)
                {
                    Color (Param.MapParamString.find("MyColor")->second);
                    Color ("35");
                }
                if(Aline[i] == 4)
                {
                    Color (Param.MapParamString.find("MyColor")->second);
                    Color ("33");
                }
                if(Pos.first == LineNumber-1 || Pos.second == i)
                {
                    Color("0");
                    Color("46");
                }
                if(Pos.first == LineNumber-1 && Pos.second == i)
                {
                    Color("40");
                    Color("33");
                }
                cout << setw (2);

                cout << Aline[i];
            }
            Color (Param.MapParamString.find("MyColor")->second);
            Color (Param.MapParamString.find("RowColor")->second);

            cout<< setw (2) << '|';
        }
        Color("0");
        Color (Param.MapParamString.find("LineColor")->second);

        cout << endl << Rule << endl;
    }
    Color (KColor.find("KReset")->second);

} // DisplaySelection ()
void DisplayGridWithLineAndColumnNumbers (const CMat & Mat)
{
    cout << string (4, ' ');
    for (unsigned i (0); i < Mat.size (); ++i)
        cout << setw (2) << i << setw (2) << '|';
    cout << endl;
    string Rule (4*Mat.size () + 1, '=');
    Rule = string (3, ' ') + Rule;
    cout << Rule << endl;
    unsigned LineNumber (0);
    for (const CVLine & Aline : Mat)
    {
        cout << setw (2) << LineNumber++ << '|';
        cout << '|';
        for (auto Cel : Aline)
            cout << setw (2) << Cel << setw (2) << '|';
        cout << endl << Rule << endl;
    }
} // DisplayWithLineAndColumnNumbers ()

void DisplayGrid (const CPosition & Pos, const CMat & Mat, const CMyParam & Param, const unsigned int & Score, bool ShowLineNumber /*= true*/, bool ShowColor /*= true*/)
{
    ClearScreen();
    cout << "               Score : " << Score << " points" << endl;
    if (ShowLineNumber)
    {
        if (ShowColor)
            DisplaySelection(Mat, Param,Pos);
        else
            DisplayGridWithLineAndColumnNumbers (Mat);
        return;
    }

    string Rule (4*Mat.size () + 1, '=');
    cout << Rule << endl;
    for (const CVLine & Aline : Mat)
    {
        cout << '|';
        for (auto Cel : Aline)
            cout << setw (2) << Cel << setw (2) << '|';
        cout << endl << Rule << endl;
    }
}// DisplayGrid ()


void InitGrid (CMat & Grid, const unsigned & Size)
{
    Grid.resize (Size);
    for (auto & Line : Grid)
    {
        Line.resize (Size);
        for (auto & Cel : Line)
            Cel = Rand () +1;
    }
} // InitGrid ()
