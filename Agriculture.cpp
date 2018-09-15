/*********************************************************************************************************************
 * Author: Matt Dienhart
 * Date: 3/17/2018
 * Description: (Final Project) This is the class implementation file for Agriculture (subclass of Space).
 * *******************************************************************************************************************/

#include "Agriculture.hpp"

//Agriculture::inspect()
//This method handles what happens if the player selects "look around" while in Agriculture
void Agriculture::inspect(Player* playerPtr) {
   //check to see if the player has already looked in this room
   if (this->inspected == true && this->actionsRemaining <= 0) {
      std::cout << "You don't think there is anything left to do in this area." << std::endl;
   }
   else { //room has not yet been inspected, or it has, but the action hasn't been completed yet
      std::cout << "You are in the Agriculture module of the ship, where the food supplies are grown." << std::endl;
      std::cout << "Everything seems to be in order here." << std::endl;
      std::cout << "You notice a spill kit in one of the cabinets. You think that it will probably come in handy." << std::endl;
      
      //update the inspection reminder and inspection status
      this->inspected = true;
      this->inspectionReminder = "This area looks clean, and there is a spill kit in one of the cabinets.";
      this->actionLabel = "Collect the Spill Kit";

      //increment the timer by 2 minutes
      playerPtr->addToTimer(2);
   }

   return;
}

//Agriculture::interact()
//This method handles what happens if the player selects "collect the spill kit" while in Agriculture
void Agriculture::interact(Player* playerPtr) {
   //check to see if the player has already done everything in this room
   if (this->actionsRemaining <= 0) {
      std::cout << "You don't think there is anything left to do in this area." << std::endl;
   }
   else {  //add the spill kit to the player's inventory
      //add item to inventory and mark this space as "no action remaining"
      playerPtr->addToInventory("Spill Kit");
      this->reduceActionsRemaining();
      this->inspectionReminder = "You have collected the spill kit. There is nothing else to do here.";
      std::cout << "You collect the Spill Kit." << std::endl;

      //regardless of whether the player opened the locker, increment the timer by 1 minute
      playerPtr->addToTimer(1);
   }

   return;
}
         
