#ifndef SCORE_H
#define SCORE_H
/*!
 * \brief Set of function for the score
 * \file score.h
 * \author Alexandre Girard
 * \version 1.0
 */
#include <string>
/**
 * @brief Save the top 10 highscores
 * @param player's score
 * @param player's name
 */
void SaveHighScore(const int & score, std::string & PlayerName);

/**
 * @brief display the top 10 highscores' tab
 */
void AfficheHighScore();

#endif // SCORE_H
