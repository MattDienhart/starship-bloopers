/*********************************************************************************************************************
 * Author: Matt Dienhart
 * Date: 3/17/2018
 * Description: (Final Project) This is the class implementation file for Propulsion (subclass of Space).
 * *******************************************************************************************************************/

#include "Propulsion.hpp"

//Propulsion::inspect()
//This method handles what happens if the player selects "look around" while in Propulsion
void Propulsion::inspect(Player* playerPtr) {
   //check to see if the player has already looked in this room
   if (this->inspected == true && this->actionsRemaining <= 0) {
      std::cout << "You don't think there is anything left to do in this area." << std::endl;
   }
   else { //room has not yet been inspected, or it has, but the action hasn't been completed yet
      std::cout << "You are in the ship's Propulsion module. Everything seems normal." << std::endl;
      std::cout << "It seems that last night's party didn't make it back to this area of the ship." << std::endl;
      std::cout << "One of the wall-mounted data screens is flashing with a set of coordinates and burn times. You've never seen it do that before." << std::endl;

      //update the inspection reminder and inspection status
      this->inspected = true;
      this->inspectionReminder = "The Propulsion module is clean. There is a flashing data screen with coordinates and burn times.";
      this->actionLabel = "Investigate the Flashing Data Screen";

      //inspecting this room takes 2 minutes
      playerPtr->addToTimer(2);
   }

   return;
}

//Propulsion::interact()
//This method handles what happens if the player selects "investigate the flashing data screen" while in Propulsion
void Propulsion::interact(Player* playerPtr) {
   //check to see if the player has already done everything in this room
   if (this->actionsRemaining <= 0) {
      std::cout << "You don't think there is anything left to do in this area." << std::endl;
   }
   else {  //collect the navigation data
      std::cout << "On closer inspection, the data screen is displaying navigation data." << std::endl;
      std::cout << "You have a feeling this is important for something." << std::endl;

      //add the beer bottles to the player's inventory and mark this space as "no action remaining"
      playerPtr->addToInventory("Navigation Data");
      this->reduceActionsRemaining();
      this->inspectionReminder = "You took the navigation data. There doesn't seem to be anything else to do here.";
      std::cout << "You enter the data into your standard-issue data pad." << std::endl;

      //increment the timer by 5 minutes
      playerPtr->addToTimer(5);
   }

   return;
}
         
