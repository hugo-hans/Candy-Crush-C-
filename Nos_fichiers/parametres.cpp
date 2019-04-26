#include <string>
#include <fstream>
#include <iostream>
#include "Nos_fichiers/parametres.h"
#include "Nos_fichiers/jeu.h"

using namespace std;

template<class InputIterator, class T>
  InputIterator find (InputIterator first, InputIterator last, const T& val)
{
  while (first!=last) {
    if (*first==val) return first;
    ++first;
  }
  return last;
}

void InitParams2 (CMyParam & Param)
{
    //Move Keys
    Param.MapParamChar["KeyUp"]   = 'z';
    Param.MapParamChar["KeyDown"] = 's';
    Param.MapParamChar["KeyLeft"] = 'q';
    Param.MapParamChar["KeyRight"] = 'd';
    Param.MapParamChar["KeyQuit"] = 'q';


    //Size of grid -- suppose to be squared
    Param.MapParamUnsigned["GridSize"] = 10;

    //Display Colors
    Param.MapParamString["LineColor"] = KColor.find("KBlue")->second ;
    Param.MapParamString["RowColor"] = KColor.find("KGreen")->second ;
    Param.MapParamString["IndexColor"] = KColor.find("KBlue")->second ;
    Param.MapParamString["MyColor"] = KColor.find("KBack")->second ;
}

void LoadParams2 (CMyParam & Param)
{
    ifstream ifs ("../G2_Fabre_Gaudel_Girard_Hans/Nos_fichiers/config.yaml");
    if (!ifs.is_open())
    {
        cerr << "Pas le bon fichier de configuration" << endl;
        exit (2);
    }
    string Key;
    while (ifs >> Key)
    {
        char tmp;
        ifs >> tmp;
        if (find (KAuthorizedKey.VParamChar.begin(), KAuthorizedKey.VParamChar.end(), Key) != KAuthorizedKey.VParamChar.end())
            ifs >> Param.MapParamChar[Key];
        else if (find (KAuthorizedKey.VParamUnsigned.begin(), KAuthorizedKey.VParamUnsigned.end(), Key) != KAuthorizedKey.VParamUnsigned.end())
            ifs >> Param.MapParamUnsigned[Key];
        else if (find (KAuthorizedKey.VParamString.begin(), KAuthorizedKey.VParamString.end(), Key) != KAuthorizedKey.VParamString.end())
        {
            string Val;
            ifs >> Val;
            Param.MapParamString[Key] = KColor.find(Val)->second;
        }
    }
}
