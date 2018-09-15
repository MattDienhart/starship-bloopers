/*********************************************************************************************************************
 * Author: Matt Dienhart
 * Date: 3/17/2018
 * Description: (Final Project) This is the class implementation file for LifeSupport (subclass of Space).
 * *******************************************************************************************************************/

#include "LifeSupport.hpp"

//LifeSupport::inspect()
//This method handles what happens if the player selects "look around" while in Life Support
void LifeSupport::inspect(Player* playerPtr) {
   //check to see if the player has already looked in this room
   if (this->inspected == true && this->actionsRemaining <= 0) {
      std::cout << "You don't think there is anything left to do in this area." << std::endl;
   }
   else { //room has not yet been inspected, or it has, but the action hasn't been completed yet
      std::cout << "You are in the ship's Life Support module." << std::endl;
      std::cout << "There is a lot of smoke in the air, which is making it difficult to see." << std::endl;
      std::cout << "You eventually find the source of the fire. There is a trash can burning in the corner of the room." << std::endl;
      std::cout << "You seem to recall Ensign Wakinona trying to impress Ensign Diaz with a card trick last night." << std::endl;
      std::cout << "Apparently, when he guessed her card, it was supposed to burst into flames, but he had been frustrated when it hadn't worked and threw the cards in the trash can." << std::endl;
      std::cout << "He would be happy to know that it eventually worked after all." << std::endl;

      //update the inspection reminder and inspection status
      this->inspected = true;
      this->inspectionReminder = "The Life Support module is filled with smoke from a trash can burning in the corner.";
      this->actionLabel = "Try to Put Out the Fire";

      //inspecting the room takes 5 minutes
      playerPtr->addToTimer(5);
   }

   return;
}

//LifeSupport::interact()
//This method handles what happens if the player selects "try to put out the fire" while in Life Support
void LifeSupport::interact(Player* playerPtr) {
   //check to see if the player has already done everything in this room
   if (this->actionsRemaining <= 0) {
      std::cout << "You don't think there is anything left to do in this area." << std::endl;
   }
   else {  //attempt to put out the fire
      //check to see if the player has the fire extinguisher
      if (playerPtr->searchInventory("Fire Extinguisher")==false) {
         std::cout << "You don't have anything to put the fire out with." << std::endl;
      }
      else { //player has the spill kit
         playerPtr->removeFromInventory("Fire Extinguisher");
         this->reduceActionsRemaining();
         this->inspectionReminder = "You put the fire out and vented the smoke. There is nothing else to do in this area.";
         playerPtr->addToPoints(1);

         std::cout << "You use the fire extinguisher to put out the fire." << std::endl;
         std::cout << "You turn the vent fans on to full blast, and the room is clear of smoke after a few minutes." << std::endl;

         //increment the timer by 5 minutes
         playerPtr->addToTimer(5);
      }
   }

   return;
}
         
