/*********************************************************************************************************************
 * Author: Matt Dienhart
 * Date: 3/17/2018
 * Description: (Final Project) This is the class implementation file for MedBay (subclass of Space).
 * *******************************************************************************************************************/

#include "MedBay.hpp"

//MedBay::inspect()
//This method handles what happens if the player selects "look around" while in the Med Bay
void MedBay::inspect(Player* playerPtr) {
   //check to see if the player has already looked in this room
   if (this->inspected == true && this->actionsRemaining <= 0) {
      std::cout << "You don't think there is anything left to do in this area." << std::endl;
   }
   else { //room has not yet been inspected, or it has, but the action hasn't been completed yet
      std::cout << "You are in the ship's Med Bay, and thankfully everything looks pristine as usual." << std::endl;
      std::cout << "There is a drawer on the far side of the room with the label 'Acetaminophen'." << std::endl;
      std::cout << "Your head is really pounding, and that drawer tempts you with sweet relief, as if it were surrounded with a glowing aura." << std::endl;

      //update the inspection reminder and inspection status
      this->inspected = true;
      this->inspectionReminder = "The Med Bay looks clean, and there is a drawer labeled 'Acetaminophen'.";
      this->actionLabel = "Take the Medicine";

      //inspecting the med bay takes 2 minutes
      playerPtr->addToTimer(2);
   }

   return;
}

//MedBay::interact()
//This method handles what happens if the player selects "take the medicine" while in the med bay
void MedBay::interact(Player* playerPtr) {
   //check to see if the player has already done everything in this room
   if (this->actionsRemaining <= 0) {
      std::cout << "You don't think there is anything left to do in this area." << std::endl;
   }
   else {  //take the medicine to relieve the headache
      //mark the player as having taken medicine and mark this space as "no action remaining"
      playerPtr->takeMedicine();
      this->reduceActionsRemaining();
      this->inspectionReminder = "You took some medicine and your headache has subsided. There isn't much else to do here.";
      std::cout << "You take two doses of Acetaminophen with a big glass of water, and you start to feel better almost immediately!" << std::endl;

      //increment the timer by 5 minutes
      playerPtr->addToTimer(5);
   }

   return;
}
         
