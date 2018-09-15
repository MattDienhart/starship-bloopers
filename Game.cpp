/************************************************************************************************
 * Author: Matt Dienhart
 * Date: 3/16/2018
 * Description: (Final Project) This is the class implementation file for Game.
 * **********************************************************************************************/

#include "Game.hpp"

//Game::playGame()
//This member function creates a game of fantasy combat and runs it until one player is the winner.
void Game::playGame() {
   //control variables
   int menuSelect = 0;
   std::string userString;

   //display intro dialogue
   std::cout << "Please enter your character's name: " << std::endl;
   std::getline(std::cin, userString);
   playerPtr->setName(userString);

   std::cout << "Please enter your character's date of birth (format: DDMMYYY)" << std::endl;
   std::getline(std::cin, userString);
   playerPtr->setDOB(userString);

   std::cout << "You are a Lieutenant in the Galactic Navy serving on the starship Daedalus." << std::endl;
   std::cout << "Your commanding officer, Commander Fitzpatrick, together with most of the Daedalus' crew, left the ship last night to attend a fancy banquet on a nearby station." << std::endl;
   std::cout << "The Commander left you and a few of your peers behind to watch over the Daedalus." << std::endl;
   std::cout << "Resentful at having been made to stay behind and emboldened at having the whole ship to yourselves, you decided to throw your own 'banquet' consisting mostly of alcohol." << std::endl;
   std::cout << "You awaken at 1400 with only a hazy memory of last night's events aboard the ship, and a pounding headache." << std::endl;
   std::cout << "You realize that the Commander is scheduled to return at 1600, which gives you only 2 hours (120 minutes) to clean up the mess you've made!" << std::endl;
   std::cout << std::endl;

   //start the game loop; loop until player runs out of time
   while (playerPtr->getTimer() < 120 && playerPtr->getPoints() < 6) {
      //display information about the current room on the ship
      std::cout << "Your current location is: " << currentLoc->getName() << "." << std::endl;
      std::cout << currentLoc->getInspectionReminder() << std::endl;
      
      //display options for user to choose from
      if (currentLoc->getInspected() == true && currentLoc->getActionsRemaining() > 0) { //room has been inspected and there are actions left to do, so interact() is available
         std::cout << " 1. Move" << std::endl;
         std::cout << " 2. Look Around" << std::endl;
         std::cout << " 3. Check Inventory" << std::endl;
         std::cout << " 4. Check Directory" << std::endl;
         std::cout << " 5. Check Time" << std::endl;
         std::cout << " 6. " << currentLoc->getActionLabel() << std::endl;

         //get input from user
         menuSelect = validInput(1,6);

         //process input
         if (menuSelect == 1) {
            this->movePlayer();
         }
         else if (menuSelect == 2) {
            currentLoc->inspect(playerPtr);
         }
         else if (menuSelect == 3) {
            playerPtr->checkInventory();
         }
         else if (menuSelect == 4) { 
            playerPtr->checkDirectory();
         }
         else if (menuSelect == 5) {
            playerPtr->checkTime();
         }
         else if (menuSelect == 6) {
            currentLoc->interact(playerPtr);
         }
      }
      else { //room has not yet been inspected or there is no action available, so interact() is not available
         std::cout << " 1. Move" << std::endl;
         std::cout << " 2. Look Around" <<  std::endl;
         std::cout << " 3. Check Inventory" << std::endl;
         std::cout << " 4. Check Directory" << std::endl;
         std::cout << " 5. Check Time" << std::endl;

         //get input from user
         menuSelect = validInput(1,5);

         //process input
         if (menuSelect == 1) {
            this->movePlayer();
         }
         else if (menuSelect == 2) {
            currentLoc->inspect(playerPtr);
         }
         else if (menuSelect == 3) {
            playerPtr->checkInventory();
         }
         else if (menuSelect == 4) {
            playerPtr->checkDirectory();
         }
         else if (menuSelect == 5) {
            playerPtr->checkTime();
         }

      }
      std::cout << std::endl;
   }

   //determine if player won or not
   if (playerPtr->getPoints() >=6) {
      std::cout << "You have completely cleaned the ship! All evidence of your debauchery has been disposed of." << std::endl;
      std::cout << "You win!" << std::endl;
   }
   else {
      std::cout << "You ran out of time! The ship is not completely clean, and Commander Fitzpatrick is on her way back!" << std::endl;
      std::cout << "Better luck next time!" << std::endl;
      std::cout << "You cleaned up " << playerPtr->getPoints() << " out of 6 messes." << std::endl;
   }
 
   return;
}     

//Game::movePlayer()
//This method asks the user to enter a direction to move the player, then moves the player to the 
//adjacent space in that direction
void Game::movePlayer() {
   std::vector<std::string> options;
   int moveSelect = 0;

   //check each direction in the current space to see which ones it is possible to move in
   if (currentLoc->getForward() != NULL) {
      options.push_back("Forward");
   }
   if (currentLoc->getAft() != NULL) {
      options.push_back("Aft");
   }
   if (currentLoc->getPort() != NULL) {
      options.push_back("Port");
   }
   if (currentLoc->getStarboard() != NULL) {
      options.push_back("Starboard");
   }

   //Display menu to user asking which direction to move in; menu only shows possible moves
   if (options.empty()) {
      std::cout << "ERROR: There are no possible moves." << std::endl;
   }
   else {
      std::cout << "Please select a direction to move." << std::endl;
      for (int i=0; i<options.size(); i++) {
         std::cout << (i+1) << ". " << options[i] << std::endl;
      }
     
      //read input from user
      moveSelect = validInput(1, options.size());

      //process move in selected direction
      if (options[moveSelect-1] == "Forward") { 
         currentLoc = currentLoc->getForward();
      }
      else if (options[moveSelect-1] == "Aft") {
         currentLoc = currentLoc->getAft();
      }
      else if (options[moveSelect-1] == "Port") {
         currentLoc = currentLoc->getPort();
      }
      else if (options[moveSelect-1] == "Starboard") {
         currentLoc = currentLoc->getStarboard();
      }

      //Moving takes 1 minute
      playerPtr->addToTimer(1);
   }


   return;
}

//Game::validInput()
//This member function is similar to validInput(int, int), but it has no boundaries 
int Game::validInput() {
   int checkValue = 0;

   //get input from user
   std::cin >> checkValue;

   //loop to ensure checkValue is valid
   while (std::cin.fail()) {
      std::cout << "Invalid entry, please try again." << std::endl;
      std::cin.clear();
      std::cin.ignore(999, '\n');
      std::cin >> checkValue;
   }

   //clear the input buffer
   std::cin.ignore(999, '\n');

   return checkValue;
}

//Game::validInput(int, int)
//This member function prompts the user to enter a number, and then checks that that number is an integer
//within the specified bounds. If the number is not an integer, or cannot be converted to one, or it
//is not within the specified bounds, the user will be prompted again until a valid input is given.
int Game::validInput(int lowerBound, int upperBound) {
   int checkValue = 0;

   //get input from user
   std::cin >> checkValue;

   //loop to ensure checkValue is valid
   while (std::cin.fail() || checkValue < lowerBound || checkValue > upperBound) {
      std::cout << "Invalid entry, please try again." << std::endl;
      std::cin.clear();
      std::cin.ignore(999, '\n');
      std::cin >> checkValue;
   }

   //clear the input buffer
   std::cin.ignore(999, '\n');

   //return validated input
   return checkValue;
}

//default constructor
Game::Game() {
   //build the ship spaces, as shown in the directory
   currentLoc = new CrewQuarters(NULL, NULL, NULL, NULL, "Crew Quarters");
   nextLoc = new Agriculture(currentLoc, NULL, NULL, NULL, "Agriculture");
   currentLoc->setAft(nextLoc);
   currentLoc = nextLoc; //moved to Agriculture
   nextLoc = new MedBay(currentLoc, NULL, NULL, NULL, "Med Bay");
   currentLoc->setAft(nextLoc);
   currentLoc = nextLoc; //moved to Med Bay
   nextLoc = new Propulsion(NULL, NULL, currentLoc, NULL, "Propulsion");
   currentLoc->setStarboard(nextLoc);
   currentLoc = nextLoc; //moved to Propulsion
   nextLoc = new Kitchen(NULL, currentLoc, NULL, NULL, "Kitchen");
   currentLoc->setForward(nextLoc);
   currentLoc = currentLoc->getPort()->getForward(); //moved to Agriculture
   nextLoc->setPort(currentLoc);
   currentLoc->setStarboard(nextLoc);
   currentLoc = nextLoc; //moved to Kitchen
   nextLoc = new MainDeck(NULL, currentLoc, NULL, NULL, "Main Deck");
   currentLoc->setForward(nextLoc);
   currentLoc = currentLoc->getPort()->getForward(); //moved to crew quarters
   nextLoc->setPort(currentLoc);
   currentLoc->setStarboard(nextLoc);
   currentLoc = nextLoc; //moved to Main Deck
   nextLoc = new FlightDeck(NULL, currentLoc, NULL, NULL, "Flight Deck");
   currentLoc->setForward(nextLoc);
   nextLoc = new LifeSupport(NULL, NULL, currentLoc, NULL, "Life Support");
   currentLoc->setStarboard(nextLoc);
   currentLoc = nextLoc; //moved to Life Support
   nextLoc = new EVAChamber(currentLoc, NULL, NULL, NULL, "EVA Chamber");
   currentLoc->setAft(nextLoc);
   currentLoc = currentLoc->getPort()->getAft(); //moved to Kitchen
   nextLoc->setPort(currentLoc);
   currentLoc->setStarboard(nextLoc);
   currentLoc = nextLoc; //moved to EVA Chamber
   nextLoc = new DockingBay(currentLoc, NULL, NULL, NULL, "Docking Bay");
   currentLoc->setAft(nextLoc);
   currentLoc = currentLoc->getPort()->getAft(); //moved to Propulsion
   nextLoc->setPort(currentLoc);
   currentLoc->setStarboard(nextLoc);
   
   //return currentLoc to crew quarters
   currentLoc = currentLoc->getPort()->getForward()->getForward();
   crewQuartersPtr = currentLoc;
   nextLoc = NULL;

   //create the player character
   playerPtr = new Player("Mike", "00112222");

}

//destructor
Game::~Game() {
   //move through the ship as shown in the directory, and deallocate memory
   currentLoc = crewQuartersPtr;
   nextLoc = currentLoc->getAft();
   delete currentLoc; //delete crew quarters
   currentLoc = nextLoc;
   nextLoc = currentLoc->getAft();
   delete currentLoc; //delete agriculture
   currentLoc = nextLoc;
   nextLoc = currentLoc->getStarboard();
   delete currentLoc; //delete Med Bay
   currentLoc = nextLoc;
   nextLoc = currentLoc->getForward();
   delete currentLoc; //delete Propulsion
   currentLoc = nextLoc;
   nextLoc = currentLoc->getForward();
   delete currentLoc; //delete Kitchen
   currentLoc = nextLoc;
   nextLoc = currentLoc->getForward();
   delete nextLoc; //delete flight deck
   nextLoc = currentLoc->getStarboard();
   delete currentLoc; //delete main deck
   currentLoc = nextLoc;
   nextLoc = currentLoc->getAft();
   delete currentLoc; //delete life support
   currentLoc = nextLoc;
   nextLoc = currentLoc->getAft();
   delete currentLoc; //delete EVA Chamber
   delete nextLoc; //delete Docking Bay

   //delete player character
   delete playerPtr;

   //set pointers to NULL
   currentLoc = NULL;
   nextLoc = NULL;
   crewQuartersPtr = NULL;
   playerPtr = NULL;
}




