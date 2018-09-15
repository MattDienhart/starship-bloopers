/*********************************************************************************************************************
 * Author: Matt Dienhart
 * Date: 3/14/2018
 * Description: (Final Project) This is the class implementation file for CrewQuarters (subclass of Space).
 * *******************************************************************************************************************/

#include "CrewQuarters.hpp"

//CrewQuarters::inspect()
//This method handles what happens if the player selects "look around" while in the crew quarters
void CrewQuarters::inspect(Player* playerPtr) {
   //check to see if the player has already looked in this room
   if (this->inspected == true && this->actionsRemaining <= 0) {
      std::cout << "You don't think there is anything left to do in this area." << std::endl;
   }
   else { //room has not yet been inspected, or it has, but the action hasn't been completed yet
      std::cout << "You are standing amidst a bunch of very incapacitated crew members." << std::endl;
      std::cout << "They are sleeping soundly in their bunks, blissfully unaware of your collective predicament." << std::endl;
      std::cout << "Even if you could awaken them, it's unlikely that they would be functional enough to aid you." << std::endl;
      std::cout << "You notice that your locker seems to have been tampered with recently. Probably an attempt at a prank." << std::endl;
      std::cout << "On closer inspection of your locker, sure enough, you see that Commander Fitzpatrick's prized Laurence Fishburne Bobblehead has been hastily stuffed inside." << std::endl;
      std::cout << "It seems that one of your colleages had planned to frame you for its theft." << std::endl;

      //update the inspection reminder and inspection status
      this->inspected = true;
      this->inspectionReminder = "Your fellow crew members are sleeping soundly, and the Laurence Fishburne Bobblehead is stil stuck in your locker.";
      this->actionLabel = "Try to Collect the Bobblehead";

      //inspecting takes 2 minutes
      playerPtr->addToTimer(2);
   }

   return;
}

//CrewQuarters::interact()
//This method handles what happens if the player selects "collect the bobblehead" while in the crew quarters
void CrewQuarters::interact(Player* playerPtr) {
   std::string guess = "";

   //check to see if the player has already done everything in this room
   if (this->actionsRemaining <= 0) {
      std::cout << "You don't think there is anything left to do in this area." << std::endl;
   }
   else {  //try to open the locker and add the bobblehead to the player's inventory
      std::cout << "You attempt to open the locker, but your mind is foggy, and you can't quite remember your passcode." << std::endl;
      std::cout << "You think it was something to do with your birthday? It can't have been very complicated if your saboteur was able to guess it correctly." << std::endl;
      std::cout << "Please enter your passcode: " << std::endl;
      
      //get input from user and compare to known Date of Birth
      std::getline(std::cin, guess);

      if (guess == playerPtr->getDOB()) {
         //test passed, so add item to inventory and mark this space as "no action remaining"
         playerPtr->addToInventory("Laurence Fishburne Bobblehead");
         this->reduceActionsRemaining();
         this->inspectionReminder = "You have retrieved the bobblehead. There is nothing else to do here.";
         std::cout << "The lock pops open and you retrieve the Laurence Fishburne Bobblehead." << std::endl;
      }
      else {
         //the test failed, so the lock does not open
         std::cout << "The lock does not open. You will need to try again." << std::endl;
      }

      //regardless of whether the player opened the locker, increment the timer by 5 minutes
      playerPtr->addToTimer(5);
   }

   return;
}
         
