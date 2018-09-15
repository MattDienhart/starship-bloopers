/***************************************************************************************************
 * Author: Matt Dienhart
 * Date: 3/16/2018
 * Description: (Final Project) This is the client code for the Starship Bloopers program.
 * *************************************************************************************************/

#include "Game.hpp"
#include <iostream>

int main() {
   int menuSelect = 0;

   //loop until user selects "Exit"

   while (menuSelect != 2) {
      //display welcome screen
      std::cout << " -------- Welcome to Starship Bloopers!! ------ " << std::endl;
      std::cout << " 1. Play Game" << std::endl;
      std::cout << " 2. Exit" << std::endl;
      std::cin >> menuSelect;

      //ensure input is valid
      while (std::cin.fail() || menuSelect < 1 || menuSelect > 2) {
         std::cout << "Invalid entry, please try again." << std::endl;
         std::cin.clear();
         std::cin.ignore(999, '\n');
         std::cin >> menuSelect;
      }

      std::cin.ignore(999, '\n');

      if (menuSelect == 1) {
         //run the interactive menu
         Game newGame;
         newGame.playGame();
      

         //ask if user would like to play again
         std::cout << "Would you like to play again?" << std::endl;
         std::cout << " 1. Play Again" << std::endl;
         std::cout << " 2. Exit" << std::endl;
         std::cin >> menuSelect;
   
         //ensure input is valid
         while (std::cin.fail() || menuSelect < 1 || menuSelect > 2) {
            std::cout << "Invalid entry, please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(999, '\n');
            std::cin >> menuSelect;
         }
 
         std::cin.ignore(999, '\n');

      }

   }

   return 0;
}

