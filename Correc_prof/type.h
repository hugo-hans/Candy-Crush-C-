#ifndef TYPE_H
#define TYPE_H
/*!
 * \file type.h
 * \brief Definition of usefull types or aliases for the project
 * \author Alain Casali
 * \author Marc Laporte
 * \version 1.0
 * \date 22 Janvier 2018
 */

#include <string>
#include <vector>
#include <map>

/**
 * @brief CVLine : alias to a line of the matrix
 */
typedef std::vector <unsigned> CVLine;

/**
 * @brief CMat : alias to a game grid type
 * @typedef std::vector <CVLine> CMat;
 */
typedef std::vector <CVLine> CMat;

/**
 * @brief CPosition : a pair gathering the coordinates in the grid
 */
typedef std::pair <unsigned, unsigned> CPosition;

/**
 * @brief Struct containing all the game's parameters
 */
struct CMyParam {
    /** List of parameters of type char*/
    std::map <std::string, char> MapParamChar;
    /** List of parameters of type unsigned*/
    std::map <std::string, unsigned> MapParamUnsigned;
    /** List of parameters of type string*/
    std::map <std::string, std::string> MapParamString;
};

/**
 * @brief Struct containing all the authorized keys in the struct CMyParam
 */
struct AuthorizedKey {
    /** List of authorized key for the type char in a struct CMyParam*/
    const std::vector <std::string> VParamChar {"KeyUp", "KeyDown", "KeyLeft", "KeyRight"};
    /** List of authorized key for the type string in a struct CMyParam*/
    const std::vector <std::string> VParamString {"LineColor", "RowColor", "IndexColor", "MyColor"};
    /** List of authorized key for the type unsigned in a struct CMyParam*/
    const std::vector <std::string> VParamUnsigned {"GridSize"};
};

/**
 * @brief KAuthorizedKey
 */
const AuthorizedKey KAuthorizedKey;

/**
  * @brief KColor : map between the "human" color and its correspondence for the Unix terminal
  */

const std::map <std::string, std::string> KColor
{
  {"KReset", "0"},
  {"KBlack", "30"},
  {"KRed", "31"},
  {"KGreen", "32"},
  {"KYellow", "33"},
  {"KBlue", "34"},
  {"KMAgenta", "35"},
  {"KCyan", "36"},

};

#endif // TYPE_H
