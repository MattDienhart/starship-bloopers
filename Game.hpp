/*******************************************************************************************************
 * Author: Matt Dienhart
 * Date: 3/16/2018
 * Description: (Final Project) This is the header file for the Game class.
 * *****************************************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Space.hpp"
#include "CrewQuarters.hpp"
#include "Agriculture.hpp"
#include "MedBay.hpp"
#include "FlightDeck.hpp"
#include "MainDeck.hpp"
#include "Kitchen.hpp"
#include "Propulsion.hpp"
#include "LifeSupport.hpp"
#include "EVAChamber.hpp"
#include "DockingBay.hpp"

#include <iostream>
#include <string>

class Game {
   private:
      //ship space containers
      Space* currentLoc;
      Space* nextLoc;
      Space* crewQuartersPtr;  //keeps track of where crew quarters is, kind of like the head of a linked list

      //player container
      Player* playerPtr;

   public:
      //member functions
      void playGame();
      void movePlayer();
      int validInput();
      int validInput(int, int);
      
      //constructor
      Game();

      //destructor
      ~Game();

};

#endif //GAME_HPP
