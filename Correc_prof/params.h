#ifndef PARAMS_H
#define PARAMS_H

/**
 * \file params.h
 * \brief Paramters' definition and associated functions
 * \author Alain Casali
 * \author Marc Laporte
 * \version 1.0
 * \date 22 Janvier 2018
 */

#include "Correc_prof/type.h"

/**
 * @brief KNbCandies : number of maximum candies in a grid
 */
const unsigned KNbCandies  = 4;

/**
 * @brief KMaxTimes : number of maximum allowed turns to win
 */
const unsigned KMaxTimes   = 20;

/**
 * @brief KImpossible :
 */
const unsigned KImpossible = KNbCandies + 2;

/**
 * @brief Initialize the set of parameters from scratch
 * @param[out] Param : List of usefull parameters
 * @fn void InitParams (CMyParam & Param);
 */
void InitParams (CMyParam & Param);

/**
 * @brief Load the set of parameters from a YAML file
 * @param[out] Param : List of usefull parameters
 * @fn void LoadParams (CMyParam & Param);
 */
void LoadParams (CMyParam & Param);
#endif // PARAMS_H
