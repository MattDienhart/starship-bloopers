/*****************************************************************************************************
 * Author: Matt Dienhart
 * Date: 3/10/2018
 * Description: (Final Project) This is the header file for the Player class.
 * ***************************************************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <iostream>
#include <vector>

class Player {
   private:
      std::string name;
      std::vector<std::string> inventory;      
      std::string dateOfBirth;
      bool medicated;
      int timer;
      int points;

   public:
      //setters
      void setName(std::string);
      void addToInventory(std::string);
      void removeFromInventory(std::string);
      void setDOB(std::string);
      void addToTimer(int);
      void takeMedicine();
      void addToPoints(int);

      //getters
      std::string getName() const
         { return name; }
      std::string getDOB() const
         { return dateOfBirth; }
      int getTimer() const
         { return timer; }
      int getPoints() const
         { return points; }

      //member functions
      void checkInventory();
      void checkDirectory();
      void checkTime();
      bool searchInventory(std::string);

      //constructor with parameters
      Player(std::string charName, std::string DOB) {
         this->name = charName;
         this->dateOfBirth = DOB;
         this->medicated = false;
         this->timer = 0;
         this->points = 0;
      }

      //destructor

};

#endif //PLAYER_HPP

