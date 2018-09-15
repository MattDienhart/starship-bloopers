/*********************************************************************************************************************
 * Author: Matt Dienhart
 * Date: 3/17/2018
 * Description: (Final Project) This is the class implementation file for FlightDeck (subclass of Space).
 * *******************************************************************************************************************/

#include "FlightDeck.hpp"

//FlightDeck::inspect()
//This method handles what happens if the player selects "look around" while in the Flight Deck
void FlightDeck::inspect(Player* playerPtr) {
   //check to see if the player has already looked in this room
   if (this->inspected == true && this->actionsRemaining <= 0) {
      std::cout << "You don't think there is anything left to do in this area." << std::endl;
   }
   else { //room has not yet been inspected, or it has, but the action hasn't been completed yet
      std::cout << "You are in the ship's Flight Deck. There are rows of pilot and nagigation consoles." << std::endl;
      std::cout << "In the center of the room is Commander Fitzpatrick's station." << std::endl;
      std::cout << "A familiar feature is missing from Commander Fitzpatrick's desk. You realize that her prized Laurence Fishburne bobblehead is missing!" << std::endl;
      std::cout << "You don't understand the appeal of the bobblehead, but you are certain that its absence will be noticed immediately." << std::endl;
      std::cout << "The entire front of the room contains a projection of the ship's position and navigation status." << std::endl;
      std::cout << "You don't exactly know how to read the navigation projections, but there are hundreds of red error messages and warnings, so you think it is probably bad." << std::endl;
      std::cout << "Without a pilot to oversee it, the ship has begun to drift towards a nearby asteroid field. That seems to be the source of most of the warnings." << std::endl;

      //update the inspection reminder and inspection status
      this->inspected = true;
      this->inspectionReminder = "The Flight Deck projection shows an imminent encounter with asteroids, and the Commander's prized bobblehead is missing.";
      this->actionLabel = "Try to Fix It";

      //inspecting the room takes 2 minutes
      playerPtr->addToTimer(2);
   }

   return;
}

//FlightDeck::interact()
//This method handles what happens if the player selects "try to fix it" while in the Flight Deck
void FlightDeck::interact(Player* playerPtr) {
   std::string userString;

   //check to see if the player has already done everything in this room
   if (this->actionsRemaining <= 0) {
      std::cout << "You don't think there is anything left to do in this area." << std::endl;
   }
   else {  //attempt to replace the bobblehead or enter the navigation data or both
      //check the player's inventory
      if (playerPtr->searchInventory("Laurence Fishburne Bobblehead")==false && playerPtr->searchInventory("Navigation Data")==false) {
         std::cout << "You don't have what you need to resolve this situation." << std::endl;
      }
      
      //if the player has the bobblehead, they can replace it 
      if (playerPtr->searchInventory("Laurence Fishburne Bobblehead")==true) {
         playerPtr->removeFromInventory("Laurence Fishburne Bobblehead");
         this->reduceActionsRemaining();
         
         //determine how to set the inspection reminder based on whether all actions are complete
         if (this->actionsRemaining > 0) {
            this->inspectionReminder = "You have returned the bobblehead to the Commander's desk, but you still need to correct the ship's course towards the asteroids.";
         }
         else {
            this->inspectionReminder = "You have returned the bobblehead, and the ship's navigation is fixed. There is nothing more to do here.";
         }

         playerPtr->addToPoints(1);

         std::cout << "You place Laurence Fishburne back in his place next to the Commander's chair." << std::endl;
         std::cout << "His little round sunglasses glow in the light of the navigation screens." << std::endl;
         std::cout << "It occurrs to you that Commander Fitzpatrick is a strange person." << std::endl;

         //increment the timer by 5 minutes
         playerPtr->addToTimer(5);
      }

      //if the player has the navigation data, they can enter it into the autopilot
      if (playerPtr->searchInventory("Navigation Data") == true) {
         //player must answer some questions to gain access to the autopilot
         std::cout << "One of the nearby flight consoles has 'Autopilot' displayed on the screen, and it appears to be able to accept the navigation data you gathered from Propulsion." << std::endl;
         std::cout << "When you try to access the console, it appears that you need to answer some security questions." << std::endl;
         std::cout << "There is a note stuck to the side of the console in Lieutenant Aker's handwriting. It reads: 'Just say yes to everything.'" << std::endl;
         std::cout << " Security Sequence: passkey answers required." << std::endl;
         std::cout << " Security Sequence: The name of this ship is the Daedalus. (Y/N)" << std::endl;
         std::getline(std::cin, userString);
      
         if (userString == "y" || userString == "Y") {
            std::cout << " Security Sequence: There are no spoons. (Y/N)" << std::endl;
            std::getline(std::cin, userString);

            if (userString == "y" || userString == "Y") {
               std::cout << " Security Sequence passed. Please provide navigation input." << std::endl;
               playerPtr->removeFromInventory("Navigation Data");
               this->reduceActionsRemaining();

               //determine how to set the inspection reminder based on whether all actions are complete
               if (this->actionsRemaining > 0) {
                  this->inspectionReminder = "The ship's navigation is fixed, but the Commander's bobblehead is still missing.";
               }
               else {
                  this->inspectionReminder = "You have returned the bobblehead, and the ship's navigation is fixed. There is nothing more to do here.";
               }

               playerPtr->addToPoints(1);
    
               std::cout << "You enter in the navigation data, and the red messages on the navigation screen disappear one by one." << std::endl;
               std::cout << "The ship now appears to be heading slowly back to its original waypoint." << std::endl;
            }
            else {
               std::cout << " ERROR: Security Sequence reset." << std::endl;
            }
         }
         else {
            std::cout << " ERROR: Security Sequence reset." << std::endl;
         }
      }
   }

   return;
}
         
