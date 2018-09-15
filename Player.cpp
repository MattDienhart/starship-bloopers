/*****************************************************************************************************
 * Author: Matt Dienhart
 * Date: 3/13/2018
 * Description: (Final Project) This is the class implementation file for Player.
 * ***************************************************************************************************/

#include "Player.hpp"

//Player::setName()
//This method sets the player's name to the argument value
void Player::setName(std::string charName) {
   this->name = charName;
   return;
}

//Player::addToInventory()
//This method adds an item (string object) to the character's inventory vector
void Player::addToInventory(std::string item) {
   this->inventory.push_back(item);
   return;
}

//Player::removeFromInventory()
//This method removes the target item (string object) from the player's inventory, if it is there
void Player::removeFromInventory(std::string target) {
   if (inventory.empty()) {
      std::cout << "Error: Inventory is empty." << std::endl;
   }
   else if (!this->searchInventory(target)) {
      std::cout << "Error: Item not found in inventory." << std::endl;
   }
   else {
      for (int i=0; i<inventory.size(); i++) {
         if (inventory[i] == target) {
            inventory.erase(inventory.begin()+i);
         }
      }
   }
 
   return;
}
      

//Player::setDOB()
//This method sets the player's date of birth to the argument value (DDMMYYYY)
void Player::setDOB(std::string DOB) {
   this->dateOfBirth = DOB;
   return;
}

//Player::addToTimer()
//This method takes an amount of time (int) and adds it to the timer data member
void Player::addToTimer(int elapsed) {
   //check to see if the player has taken medicine yet
   if (this->medicated) { //if player has taken medicine, things take a normal amount of time
      this->timer += elapsed;
   }
   else {  //if player has not taken medicine, things take twice as long
      this->timer += (2*elapsed);
   }

   return;
}

//Player::addToPoints()
//This method adds the specified value to the player's points total
void Player::addToPoints(int earned) {
   this->points += earned;
   return;
}

//Player::takeMedicine()
//This method sets the "medicated" variable to true, indicating that the player has taken medicine
void Player::takeMedicine() {
   this->medicated = true;
   return;
}

//Player::checkInventory()
//This method prints all of the objects in the player's current inventory
void Player::checkInventory() {
   //check to see if inventory is empty
   if (inventory.empty()) {
      std::cout << "The inventory is empty." << std::endl;
   }
   else {
      std::cout << "Inventory: ";
      for (int i= 0; i<inventory.size(); i++) {
         std::cout << "[" << inventory[i] << "] ";
      }
      std::cout << std::endl;
   }

   return;
}

//Player::checkDirectory()
//This method prints a map of the ship.
void Player::checkDirectory() {
   std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
   std::cout << "|      Fwd                                                                                             |" << std::endl;
   std::cout << "| Port     Strbrd                                                                                      |" << std::endl;
   std::cout << "|      Aft                                ____________________                                         |" << std::endl;
   std::cout << "|                                         |                  |                                         |" << std::endl;
   std::cout << "|                                         |   Flight Deck    |                                         |" << std::endl;
   std::cout << "|                     ____________________|__________________|____________________                     |" << std::endl;
   std::cout << "|                     |                   |                  |                   |                     |" << std::endl;
   std::cout << "|                     |   Crew Quarters   |    Main Deck     |   Life Support    |                     |" << std::endl;
   std::cout << "|                     |___________________|__________________|___________________|                     |" << std::endl;
   std::cout << "|                     |                   |                  |                   |                     |" << std::endl;
   std::cout << "|                     |    Agriculture    |     Kitchen      |    EVA Chamber    |                     |" << std::endl;
   std::cout << "|                     |___________________|__________________|___________________|                     |" << std::endl;
   std::cout << "|                     |                   |                  |                   |                     |" << std::endl;
   std::cout << "|                     |     Med Bay       |    Propulsion    |    Docking Bay    |                     |" << std::endl;
   std::cout << "|                     |___________________|__________________|___________________|                     |" << std::endl;
   std::cout << "|                                                                                                      |" << std::endl;
   std::cout << "|                                                                                                      |" << std::endl;
   std::cout << "|______________________________________________________________________________________________________|" << std::endl;

   return;
}

//Player::checkTime()
//This method returns the value in the timer variable, as well as the amount of time remaining
void Player::checkTime() {
   std::cout << timer << " minutes have elapsed since you woke up." << std::endl;
   std::cout << "You have " << (120-timer) << " minutes remaining to get the ship cleaned up before the Commander returns." << std::endl;
   
   return;
}

//Player::searchInventory()
//This method searches the player's inventory for the target string and returns "true" if found, "false" if not found
bool Player::searchInventory(std::string target) {
   if (inventory.empty()) { //return false if inventory is empty
      return false;
   }
   else { //search inventory vector for target string
      for (int i=0; i<inventory.size(); i++) {
         if (inventory[i] == target) {
            return true;
         }
      }
      return false;
   }
}

