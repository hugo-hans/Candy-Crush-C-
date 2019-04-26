
#ifndef GAME_H
#define GAME_H

/*!
 * \file jeu.h
 * \brief Set of usefull functions for the game
 * \author Alain Casali
 * \author Marc Laporte
 * \version 1.0
 * \date 22 Janvier 2018
 */

#include "Correc_prof/type.h"

/**
 * @brief Display the menu according to the set of parameters.
 * @param[out] Pos : Position of the token to move
 * @param[out] Direction : Direction of wanted movement
 * @param[in] Params : List of usefull parameters
 * @param[in] Score : Player's score
 * \fn void Menu (CPosition & Pos, char & Direction, const CMyParam & Params);
 */
void Menu (CPosition & Pos, char & Direction, const CMyParam & Params, const unsigned int & Score);

/**
 * @brief Swap the token from its inital place to its final destination
 * @param[in|out] Grid : Game grid
 * @param[in] Pos : Position of the token to move
 * @param[in] Direction : : Direction of wanted movement
 * @param[in] Params : List of usefull parameters
 * \fn void MakeAMove (CMat & Grid, const CPosition & Pos, const char & Direction, const CMyParam & Params);
 * \bug No control is provided as to the validity of the move
 */
void MakeAMove (CMat & Grid, const CPosition & Pos, const char & Direction, const CMyParam & Params);

/**
 * @brief Chek if there is at least 3 token in the same row
 * @param[in] Mat : Game grid
 * @param[out] Pos : Position of the first token from wich there is at least 3 times the same token in the same row
 * @param[out] HowMany : How many the same token appears consecutivelly in this row
 * @return True if there is at least 3 times the same token in the same row, false otherwise
 * \fn bool AtLeastThreeInARow (const CMat & Mat, CPosition & Pos, unsigned & HowMany);
 */
bool AtLeastThreeInARow (const CMat & Mat, CPosition & Pos, unsigned & HowMany, unsigned & WhatNumber);

/**
 * @brief Chek if there is at least 3 token in the same column
 * @param[in] Mat : Game grid
 * @param[out] Pos : Position of the first token from wich there is at least 3 times the same token in the same column
 * @param[out] HowMany : How many the same token appears consecutivelly in this column
 * @param[out] WhatNumber : size of the number's sequence
 * @return True if there is at least 3 times the same token in the same column, false otherwise
 * \fn bool AtLeastThreeInAColumn (const CMat & Mat, CPosition & Pos, unsigned & HowMany);
 */
bool AtLeastThreeInAColumn (const CMat & Mat, CPosition & Pos, unsigned & HowMany, unsigned & WhatNumber);

/**
 * @brief Remove "Howmany" same tokens starting from "Pos"
 * @param[in|out] Mat : Game grid
 * @param[in] Pos : Position of the first token from wich there is at least 3 times the same token in the same column
 * @param[in] HowMany : How many the same token appears consecutivelly in this column
 * @fn void RemovalInColumn (CMat & Mat, const CPosition & Pos, const unsigned & HowMany);
 */
void RemovalInColumn (CMat & Mat, const CPosition & Pos, const unsigned & HowMany);

/**
 * @brief Remove "Howmany" same tokens starting from "Pos"
 * @param[in|out] Mat : Game grid
 * @param[in] Pos : Position of the first token from wich there is at least 3 times the same token in the same row
 * @param[in] HowMany : How many the same token appears consecutivelly in this row
 * @fn void RemovalInRow (CMat & Mat, const CPosition & Pos, const unsigned & HowMany);
 */
void RemovalInRow (CMat & Mat, const CPosition & Pos, const unsigned & HowMany);

/**
 * @brief Computer the score
 * @param[in] HowMany : Number of candidies removed
 * @fn unsigned ComputeScore (const unsigned & HowMany)
 */
int ComputeScore (const unsigned & HowMany, unsigned & WhatNumber);

/**
 * @brief new main
 * @return 0 if everything is OK
 * @fn int ppal ();
 */
int ppal ();
#endif // GAME_H
