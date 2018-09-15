/*********************************************************************************************************************
 * Author: Matt Dienhart
 * Date: 3/17/2018
 * Description: (Final Project) This is the class implementation file for Kitchen (subclass of Space).
 * *******************************************************************************************************************/

#include "Kitchen.hpp"

//Kitchen::inspect()
//This method handles what happens if the player selects "look around" while in the Kitchen
void Kitchen::inspect(Player* playerPtr) {
   //check to see if the player has already looked in this room
   if (this->inspected == true && this->actionsRemaining <= 0) {
      std::cout << "You don't think there is anything left to do in this area." << std::endl;
   }
   else { //room has not yet been inspected, or it has, but the action hasn't been completed yet
      std::cout << "You are in the ship's Kitchen." << std::endl;
      std::cout << "Thankfully, everything looks relatively clean here." << std::endl;
      std::cout << "You suspect that a large quantity of the ship's potato wedges might be missing, but you don't think anyone will notice right away." << std::endl;
      std::cout << "A fire extinguisher is sitting in a cabinet near the door." << std::endl;

      //update the inspection reminder and inspection status
      this->inspected = true;
      this->inspectionReminder = "The Kitchen is clean, and there is a fire extinguisher near the door.";
      this->actionLabel = "Collect the Fire Extinguisher";

      //inspecting the room takes 2 minutes
      playerPtr->addToTimer(2);
   }

   return;
}

//Kitchen::interact()
//This method handles what happens if the player selects "collect the fire extinguisher" while in the Kitchen
void Kitchen::interact(Player* playerPtr) {
   //check to see if the player has already done everything in this room
   if (this->actionsRemaining <= 0) {
      std::cout << "You don't think there is anything left to do in this area." << std::endl;
   }
   else {  //collect the fire extinguisher
      //add the beer bottles to the player's inventory and mark this space as "no action remaining"
      playerPtr->addToInventory("Fire Extinguisher");
      this->reduceActionsRemaining();
      this->inspectionReminder = "You took the fire extinguisher, and there doesn't seem to be anything else to do here.";
      std::cout << "You grab the fire extinguisher." << std::endl;
      
      //increment the timer by 2 minutes
      playerPtr->addToTimer(2);
   }

   return;
}
         
