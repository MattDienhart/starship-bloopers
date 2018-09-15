/*************************************************************************************************************************
 * Author: Matt Dienhart
 * Date: 3/17/2018
 * Description: (Final Project) This is the header file for the EVAChambber class (subclass of Space).
 * ***********************************************************************************************************************/

#ifndef EVACHAMBER_HPP
#define EVACHAMBER_HPP

#include "Space.hpp"
#include "Player.hpp"

class EVAChamber: public Space {
   public:
      void inspect(Player*);
      void interact(Player*);

      //constructor
      EVAChamber(Space* fwdPtr, Space* aftPtr, Space* portPtr, Space* strbrdPtr, std::string roomName): 
         Space(fwdPtr, aftPtr, portPtr, strbrdPtr, roomName) 
      {
         actionsRemaining = 2;
      }

      //destructor


};

#endif //EVACHAMBER_HPP
