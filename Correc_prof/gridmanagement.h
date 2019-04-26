#ifndef GRIDMANAGEMENT_H
#define GRIDMANAGEMENT_H

/*!
 * \file gridmanagement.h
 * \brief Set of usefull functions for the grid management
 * \author Alain Casali
 * \author Marc Laporte
 * \version 1.0
 * \date 22 Janvier 2018
 */

#include <string>

#include "Correc_prof/type.h" //nos types
#include "Correc_prof/nsutil.h"

/**
 * @brief Clear the current terminal
 * @fn void ClearScreen ();
 */
void ClearScreen ();

/**
 * @brief Set the color of the future input in the terminal
 * @param[in] Col : Next color to be used
 * @fn void Color (const std::string & Col);
 */
void Color (const std::string & Col);

/**
 * @brief Display the grid showing the line and the column numbers. Everything is colored according to the
 * set of parameters.
 * @param[in] Mat : Game grid
 * @param[in] Params : List of usefull parameters
 * @fn void DisplayGridWithLineAndColumnNumbersAndColor (const CMat & Mat, const CMyParam & Params);
 */
void DisplayGridWithLineAndColumnNumbersAndColor (const CMat & Mat, const CMyParam & Params);

/**
 * @brief Display the grid showing the line and the column numbers.
 * @param[in] Mat : Game grid
 * @deprecated Do not use this function, it's just for debugging
 * @fn void DisplayGridWithLineAndColumnNumbers (const CMat & Mat);
 */
void DisplayGridWithLineAndColumnNumbers (const CMat & Mat);

/**
 * @brief Display the grid according to the parameters
 * @param[in] Mat : Game grid
 * @param[in] Params : : List of usefull parameters
 * @param[in] ShowLineNumber : true if we want to show line and color numbers, false otherwise.
 * @param[in] ShowColor : true if we want to color the grid, false otherwise.
 * @fn void DisplayGrid (const CMat & Mat, const CMyParam & Params, bool ShowLineNumber = true, bool ShowColor = true);
 */
void DisplayGrid (const CMat & Mat, const CMyParam & Params, bool ShowLineNumber = true, bool ShowColor = true);


/**
 * @brief Initialize the grid according to the size
 * @param[out] Grid: Game grid to be initalized
 * @param[in] Size : Number of rows / columns of the grid (supposed to be squared)
 * @fn void InitGrid (CMat & Grid, const unsigned & Size);
 */
void InitGrid (CMat & Grid, const unsigned & Size);

#endif // GRIDMANAGEMENT_H
