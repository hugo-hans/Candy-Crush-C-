

/**
 * \file main.cpp
 * \brief Main programm
 * \author Alain Casali
 * \author Marc Laporte
 * \version 1.0
 * \date 22 Janvier 2018
 */

#include <iostream>
#include "Nos_fichiers/jeu.h"
#include "Nos_fichiers/firstmenu.h"

using namespace std;
/**
 * @brief main
 * @return return 0 iff everything is OK, 1 if we have an exception, 2 if we can't load the params' file
 */
int main()
{
    try
    {
        FirstMenu();
    }
    catch (...)
    {
        cerr << "ca c'est mal passe quelque part" << endl;
        return 1;
    }
} //main ()
