/*************************************************************************************************************************
 * Author: Matt Dienhart
 * Date: 3/17/2018
 * Description: (Final Project) This is the header file for the MainDeck class (subclass of Space).
 * ***********************************************************************************************************************/

#ifndef MAINDECK_HPP
#define MAINDECK_HPP

#include "Space.hpp"
#include "Player.hpp"

class MainDeck: public Space {
   public:
      void inspect(Player*);
      void interact(Player*);

      //constructor
      MainDeck(Space* fwdPtr, Space* aftPtr, Space* portPtr, Space* strbrdPtr, std::string roomName): 
         Space(fwdPtr, aftPtr, portPtr, strbrdPtr, roomName) 
      {
         actionsRemaining = 1;
      }

      //destructor


};

#endif //MAINDECK_HPP
