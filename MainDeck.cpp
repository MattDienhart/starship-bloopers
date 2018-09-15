/*********************************************************************************************************************
 * Author: Matt Dienhart
 * Date: 3/17/2018
 * Description: (Final Project) This is the class implementation file for MainDeck (subclass of Space).
 * *******************************************************************************************************************/

#include "MainDeck.hpp"

//MainDeck::inspect()
//This method handles what happens if the player selects "look around" while in the Main Deck
void MainDeck::inspect(Player* playerPtr) {
   //check to see if the player has already looked in this room
   if (this->inspected == true && this->actionsRemaining <= 0) {
      std::cout << "You don't think there is anything left to do in this area." << std::endl;
   }
   else { //room has not yet been inspected, or it has, but the action hasn't been completed yet
      std::cout << "You are in the ship's Main Deck, and there is a huge mess!" << std::endl;
      std::cout << "Emtpy beer bottles are scattered everywhere!" << std::endl;

      //update the inspection reminder and inspection status
      this->inspected = true;
      this->inspectionReminder = "The Main Deck is littered with beer bottles.";
      this->actionLabel = "Collect the Beer Bottles";

      //inspecting the main deck takes 2 minutes
      playerPtr->addToTimer(2);
   }

   return;
}

//MainDeck::interact()
//This method handles what happens if the player selects "collect the beer bottles" while in the main deck
void MainDeck::interact(Player* playerPtr) {
   //check to see if the player has already done everything in this room
   if (this->actionsRemaining <= 0) {
      std::cout << "You don't think there is anything left to do in this area." << std::endl;
   }
   else {  //collect the beer bottles
      //add the beer bottles to the player's inventory and mark this space as "no action remaining"
      playerPtr->addToInventory("Beer Bottles");
      this->reduceActionsRemaining();
      this->inspectionReminder = "You have cleared away the beer bottles. There is nothing else to do here.";
      std::cout << "You grab a nearby trash can and fill it with all of the empty beer bottles. It take a while." << std::endl;
      std::cout << "You will need to find somewhere to dispose of the evidence. Maybe you can dump it out of the airlock?" << std::endl;

      //increment the timer by 5 minutes
      playerPtr->addToTimer(5);
   }

   return;
}
         
