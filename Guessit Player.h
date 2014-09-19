#ifndef __Guessit_v2__Player__
#define __Guessit_v2__Player__

#include <iostream>
#include <string>
using namespace std;
/**
* The Player class represents a single player. It keeps track of his or her
* best score (least number of guesses) worst score (most), number of games
* played and the average number of gueses over all games. Note that you can
* always calculate a new average given a new game with the number of guesses
* taken in it from just the existing statistics in a player object.
*/
class Player
{
private:
   string playerName;
   int numGamesPlayed;
   int leastGuesses;
   int mostGuesses;
   double avgGuesses;
public:
   Player(string name = ""); // Note optional param and default.
   string getPlayerName(void) const;
   int getNumGamesPlayed(void) const;
   int getMostGuesses(void) const;
   int getLeastGuesses(void) const;
   double getAvgGuesses(void) const;

   void setPlayerName(string name);
   void setNumGamesPlayed(int n);
   void setMostGuesses(int n);
   void setLeastGuesses(int n);
   void setAvgGuesses(double x);
};
// We want to pretty print the Player object with << and hence this.
ostream& operator<<(ostream& os, const Player& player);
#endif
