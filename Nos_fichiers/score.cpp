#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

void SaveHighScore (const int & score, string & PlayerName)
{
    ifstream ifsScore ("../G2_Fabre_Gaudel_Girard_Hans/Nos_fichiers/highscore");
    vector <int> VScore(10);
    vector <string> VPlayer(10);
    string LPlayer;
    string LScore;
    for (unsigned i(9) ;getline(ifsScore, LScore); --i )
    {
        int LScoreInt = atoi(LScore.c_str());
        VScore[i] = LScoreInt;
    }
    ifsScore.close();
    ifstream ifsPlayer ("../G2_Fabre_Gaudel_Girard_Hans/Nos_fichiers/topplayer");
    for (unsigned i(9) ;getline(ifsPlayer, LPlayer); --i )
    {
        VPlayer[i] = LPlayer;
    }
    ifsPlayer.close();
    for(unsigned i(0); i <= VScore.size(); ++i)
    {
        if(score >= VScore[9])
        {
            for(unsigned j(0); j < 9; ++j)
            {
                VScore[j] = VScore[j+1];
                VPlayer[j] = VPlayer[j+1];
            }
            VScore[9] = score;
            VPlayer[9] = PlayerName;
            break;
        }
        if(score < VScore[i] && i < 1 )break;
        if(score < VScore[i] && i > 1)
        {
            for(unsigned j(0); j < i; ++j)
            {
                VScore[j] = VScore[j+1];
                VPlayer[j] = VPlayer[j+1];
            }
            VScore[i-1] = score;
            VPlayer[i-1] = PlayerName;
            break;

        }

    }
    ofstream ofsScore ("../G2_Fabre_Gaudel_Girard_Hans/Nos_fichiers/highscore", ios::out | ios::trunc);
    ofstream ofsPlayer ("../G2_Fabre_Gaudel_Girard_Hans/Nos_fichiers//topplayer", ios::out | ios::trunc);
    for(unsigned i(9);; --i)
    {
        ofsScore << VScore[i] <<endl;
        ofsPlayer << VPlayer[i] << endl;
    }
    ofsScore.close();
    ofsPlayer.close();
}


void AfficheHighScore()
{
    ifstream ifsScore ("../G2_Fabre_Gaudel_Girard_Hans/Nos_fichiers//highscore");
    ifstream ifsPlayer ("../G2_Fabre_Gaudel_Girard_Hans/Nos_fichiers//topplayer");
    string LScore;
    string LPlayer;
    cout <<" _____________________________________"<<endl;
    cout <<"|                                     |"<< endl;
    for ( ;getline(ifsScore, LScore) && getline(ifsPlayer, LPlayer); )
    {

        cout << "|    " <<setw(5) << left << LScore << setw(4) <<":"<< setw(15) << LPlayer << "         " << "|" << endl;
    }
    cout <<"|_____________________________________|"<< endl;


}
