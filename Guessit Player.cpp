#include "Player.h"
#include "Game.h"

#include <iomanip>

using namespace std;
/**
* name is an optional param (See the class decl). It defaults to ""
*/

// constructor
Player::Player(string name)
{
   playerName = name;
   numGamesPlayed = 0;
   mostGuesses = leastGuesses = avgGuesses = INT_MAX;
}

// getters
string Player::getPlayerName(void) const
{
   return playerName;
}
int Player::getNumGamesPlayed(void) const
{
   return numGamesPlayed;
}
int Player::getMostGuesses(void) const
{
   return mostGuesses;
}
int Player::getLeastGuesses(void) const
{
   return leastGuesses;
}
double Player::getAvgGuesses(void) const
{
   return avgGuesses;
}

// setters
void Player::setPlayerName(string name)
{
   playerName = name;
}
void Player::setNumGamesPlayed(int n)
{
   numGamesPlayed = n;
}
void Player::setMostGuesses(int n)
{
   mostGuesses = n;
}
void Player::setLeastGuesses(int n)
{
   leastGuesses = n;
}
void Player::setAvgGuesses(double x)
{
   avgGuesses = x;
}

/**
* The output operator << on the Player data type. It
* pretty prints the members of this player.
*/
ostream& operator<<(ostream& os, const Player& player) {
   return os << player.getPlayerName() << ": "
      << player.getNumGamesPlayed() << " Games. Guesses: "
      << setprecision(2) << player.getAvgGuesses() << " (avg) "
      << player.getLeastGuesses() << " (best) "
      << player.getMostGuesses() << " (worst) "
      ;
}
