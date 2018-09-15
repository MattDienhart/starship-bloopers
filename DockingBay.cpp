/*********************************************************************************************************************
 * Author: Matt Dienhart
 * Date: 3/17/2018
 * Description: (Final Project) This is the class implementation file for DockingBay (subclass of Space).
 * *******************************************************************************************************************/

#include "DockingBay.hpp"

//DockingBay::inspect()
//This method handles what happens if the player selects "look around" while in the DockingBay
void DockingBay::inspect(Player* playerPtr) {
   //check to see if the player has already looked in this room
   if (this->inspected == true && this->actionsRemaining <= 0) {
      std::cout << "You don't think there is anything left to do in this area." << std::endl;
   }
   else { //room has not yet been inspected, or it has, but the action hasn't been completed yet
      std::cout << "You are in the ship's Docking Bay, where the primary airlock is located." << std::endl;
      std::cout << "The room itself is fairly clean, but there are monitors on the wall that show a live camera feed of the exterior hull of the Daedalus, and you notice something there." << std::endl;
      std::cout << "It appears that, during the events of last night, one of your crewmates created some extremely inappropriate graffiti on the outer hull of the ship." << std::endl;
      std::cout << "The linework is actually rather impressive. You figure this must be Ensign Tebata's doing." << std::endl;
      std::cout << "Unfortunately, you don't think the Commander will have the same artistic appreciation for it when she sees it. You had better find a way to clean it off." << std::endl;

      //update the inspection reminder and inspection status
      this->inspected = true;
      this->inspectionReminder = "There is vulgar graffiti on the exterior hull of the ship, according to the exterior cameras.";
      this->actionLabel = "Try to Work the Airlock";

      //inspecting the docking bay takes 2 minutes
      playerPtr->addToTimer(2);
   }

   return;
}

//DockingBay::interact()
//This method handles what happens if the player chooses to interact with the docking bay
void DockingBay::interact(Player* playerPtr) {
   std::string userString;

   //check to see if the player has already done everything in this room
   if (this->actionsRemaining <= 0) {
      std::cout << "You don't think there is anything left to do in this area." << std::endl;
   }
   else {  //attempt to clean the graffiti or flush the beer bottles, or both, depending on what is in the players inventory
      //check the player's inventory
      if (playerPtr->searchInventory("Beer Bottles")==false && playerPtr->searchInventory("EVA Suit")==false) {
         std::cout << "You don't have what you need to resolve this situation." << std::endl;
      }

      //if the player has beer bottles, they can try to dump them out the airlock
      if (playerPtr->searchInventory("Beer Bottles")==true) {
         std::cout << "You think you can set up the airlock to dump these beer bottles out to space." << std::endl;
         std::cout << "The data screen on the wall seems to have instructions on how to work the airlock." << std::endl;
         std::cout << " Sequence RA1326B: Open Inner Bulkhead" << std::endl;
         std::cout << " Sequence BY1449C: Open Outer Bulkhead" << std::endl;
         std::cout << " Sequence CH1002A: Close Inner Bulkhead" << std::endl;
         std::cout << " Sequence UT8844Z: Close Outer Bulkhead" << std::endl;
         std::cout << " Sequence AAA49T2: Automated EVA Sequence" << std::endl;
         std::cout << " Standing by for manual sequence..." << std::endl;
         std::getline(std::cin, userString);

         //player must enter the airlock manual control codes in the correct order
         if (userString == "RA1326B") {
            std::cout << "The inner airlock door opens, and you place the beer bottles in the chamber." << std::endl;
            std::cout << "You return to the data screen." << std::endl;
            std::cout << " Standing by for manual sequence..." << std::endl;
            std::getline(std::cin, userString);
            
            if (userString == "CH1002A") {
               std::cout << "The inner airlock door closes." << std::endl;
               std::cout << " Standing by for manual sequence..." << std::endl;
               std::getline(std::cin, userString);
            
               if (userString == "BY1449C") {
                  //remove beer bottles from inventory and reduce actions remaining
                  playerPtr->removeFromInventory("Beer Bottles");
                  this->reduceActionsRemaining();
                  
                  //determine how to set the inspection reminder based on how many actions have been completed
                  if (this->actionsRemaining > 0) {
                     this->inspectionReminder = "You have disposed of the beer bottles, but the graffiti is still on the ship's hull.";
                  }
                  else {
                     this->inspectionReminder = "You have disposed of the beer bottles and cleaned the graffiti. There is nothing else that needs to be done here.";
                  }

                  playerPtr->addToPoints(1);
              
                  std::cout << "An alarm starts blaring, and the outer airlock door opens." << std::endl;
                  std::cout << "You are really not a fan of that alarm. It is not helping your headache at all." << std::endl;
                  std::cout << "The emtpy beer bottles are sucked violently out into the vacuum of space." << std::endl;
                  std::cout << "You feel guilty for creating a lot of space trash, but it's better than being made to run extra laps around the ship." << std::endl;
                  std::cout << "After a minute, the outer door shuts again and the alarm stops." << std::endl;
               }
               else {
                  std::cout << "An error message appears on the data screen and nothing happens." << std::endl;
                  std::cout << "After a minute, the inner airlock door opens again and you retrieve the bottles." << std::endl;
               }
            }
            else {
               std::cout << "An error message appears on the data screen and nothing happens." << std::endl;
               std::cout << "You retrieve the bottles, and after a minute, the inner airlock door closes again." << std::endl;
            }
         }
         else {
            std::cout << "An error message appears on the data screen and nothing happens." << std::endl;
         }
         //increment the timer by 5 minutes
         playerPtr->addToTimer(5);
      }

      //if the player has the EVA Suit, they can go outside and clean up the graffiti
      if (playerPtr->searchInventory("EVA Suit")==true) {
         std::cout << "You put on the EVA Suit and prepare to pass through the airlock with some cleaning supplies." << std::endl;
         std::cout << "The data screen on the wall seems to have instructions on how to work the airlock." << std::endl;
         std::cout << " Sequence RA1326B: Open Inner Bulkhead" << std::endl;
         std::cout << " Sequence BY1449C: Open Outer Bulkhead" << std::endl;
         std::cout << " Sequence CH1002A: Close Inner Bulkhead" << std::endl;
         std::cout << " Sequence UT8844Z: Close Outer Bulkhead" << std::endl;
         std::cout << " Sequence AAA49T2: Automated EVA Sequence" << std::endl;
         std::cout << " Standing by for manual sequence..." << std::endl;
         std::getline(std::cin, userString);

         if (userString == "AAA49T2") {
            playerPtr->removeFromInventory("EVA Suit");
            this->reduceActionsRemaining();

            //determine how to set the inspection reminder based on how many actions have been completed
            if (this->actionsRemaining > 0) {
               this->inspectionReminder = "You have cleaned off the graffiti, but you may still need to use the airlock for other things.";
            }
            else {
               this->inspectionReminder = "You have disposed of the beer bottles and cleaned the graffiti. There is nothing else that needs to be done here.";
            }

            playerPtr->addToPoints(1);

            std::cout << "You exit through the airlock, tether yourself outside the ship, and spend a long time cleaning off the graffiti with a brush and some degreaser." << std::endl;            
            std::cout << "When you are finished, you reenter the ship via the Docking Bay airlock." << std::endl;
 
            //increment the timer by  minutes
            playerPtr->addToTimer(15);
         }
         else {
            std::cout << "An error message appears on the data screen and nothing happens." << std::endl;
            std::cout << "You think you remember EVA Officer Nguyen saying something about an automated airlock sequence for people with EVA suits." << std::endl;
           
            //increment the timer by 2 minutes
            playerPtr->addToTimer(2);
         }
      }
   }

   return;
}
         
