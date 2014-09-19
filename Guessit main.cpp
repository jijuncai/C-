#include<iostream>
#include <sstream>

#include "Game.h"
using namespace std;

string getPlayerName(void);
void updatePlayerRecord(Game& game, Player& player, int numGuesses);

/**
* The number guessing game with a leaderboard. Everyone can play this game.
* Everyone, that is, except, apparently, Mr. Q (Is he a character in
* Star Trek TNG? I never liked him, I think. Serves him right.)
*/
int main(int argc, const char * argv[])
{
   while (true)
   {
      string playerName = getPlayerName();
      if (playerName.compare("Q") == 0 || playerName.compare("q") == 0)
         break;
      if (!Game::addPlayer(playerName))
      {
         cerr << "Sorry. No more new players. Only accepting known players.\n";
         continue;
      }

      Player player;
      if (!Game::findPlayer(playerName, player))
      {
         cerr << "Sorry! Something's wrong. I can't find a player who ought to "
            << "exist!\nWe'll look into this, I promise\n";
         continue;
      }

      // At this point the player exists and we hold variable player's record.
      Game game(playerName);
      game.play();

      if (game.isWon())
      {
         cout << "Congratulations, " << game.getPlayerName() << ". "
            << "You have won the game. You took " << game.getNumGuesses()
            << (game.getNumGuesses() > 1 ? " guesses.\n" : " guess.\n");
         Game::updateLeaderboard(player, game.getNumGuesses());
      }
      else
      {
         cout << "I'm sorry, " << game.getPlayerName() << ". "
            << "You did not win the game after " << game.getNumGuesses()
            << (game.getNumGuesses() > 1 ? " guesses.\n" : " guess.\n");
         Game::updateLeaderboard(player, Game::MAX_GUESSES);
      }
   }
   cout << "Bye!\n";
   return 0;
}

string getPlayerName()
{
   string name = "";
   while (name.length() == 0)
   {
      cout << "Hello playa, whatcha name ('Q' to quit)? ";
      getline(cin, name);
   }
   return name;
}
