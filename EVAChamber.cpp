/*********************************************************************************************************************
 * Author: Matt Dienhart
 * Date: 3/17/2018
 * Description: (Final Project) This is the class implementation file for EVAChamber (subclass of Space).
 * *******************************************************************************************************************/

#include "EVAChamber.hpp"

//EVAChamber::inspect()
//This method handles what happens if the player selects "look around" while in the EVA Chamber
void EVAChamber::inspect(Player* playerPtr) {
   //check to see if the player has already looked in this room
   if (this->inspected == true && this->actionsRemaining <= 0) {
      std::cout << "You don't think there is anything left to do in this area." << std::endl;
   }
   else { //room has not yet been inspected, or it has, but the action hasn't been completed yet
      std::cout << "You are in the ship's EVA Chamber, and there are rows of EVA Suits along the walls." << std::endl;
      std::cout << "Unfortunately, there is also a substantial mess. There is beer all over the floor." << std::endl;
      std::cout << "Also, in the puddle of beer, there are a few soggy EVA Suits, some plastic tubing, and an improvised funnel." << std::endl;
      std::cout << "As you stare at this strange scene, you seem to remember Lieutenant Stein being very excited about what he called the 'Space Suit Challenge' last night." << std::endl;
      std::cout << "If you remember correctly, the idea was to put a crewmember in one of the suits, and then fill it with beer instead of oxygen." << std::endl;
      std::cout << "In hindsight, that was probably not a great idea." << std::endl;
      std::cout << "In any event, this mess will need to be cleaned up." << std::endl;

      //update the inspection reminder and inspection status
      this->inspected = true;
      this->inspectionReminder = "The EVA Chamber floor is covered in spilled beer and soggy EVA Suits";
      this->actionLabel = "Clean the Floor";

      //inspecting the room takes 2 minutes
      playerPtr->addToTimer(2);
   }

   return;
}

//EVAChamber::interact()
//This method handles what happens if the player selects "clean the floor" while in the EVA Chamber
void EVAChamber::interact(Player* playerPtr) {
   //check to see if the player has already done everything in this room
   if (this->actionsRemaining <= 0) {
      std::cout << "You don't think there is anything left to do in this area." << std::endl;
   }
   else {  //attempt to clean the floor and collect the EVA Suit
      //check to see if the player has the spill kit
      if (playerPtr->searchInventory("Spill Kit")==false) {
         std::cout << "You don't have anything to clean up the spilled beer with." << std::endl;
      }
      else { //player has the spill kit
         playerPtr->removeFromInventory("Spill Kit");
         this->reduceActionsRemaining();
         playerPtr->addToPoints(1);

         playerPtr->addToInventory("EVA Suit");
         this->reduceActionsRemaining();
         this->inspectionReminder = "You cleaned up the spill and collected an EVA Suit. There is nothing else to do here.";

         std::cout << "You use the spill kit to clean up the beer and you hang up the EVA Suits to dry out." << std::endl;
         std::cout << "Actually, you think an EVA Suit might come in handy, so you take one." << std::endl;

         //increment the timer by 15 minutes
         playerPtr->addToTimer(15);
      }
   }

   return;
}
         
