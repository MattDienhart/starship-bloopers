/*************************************************************************************************************************
 * Author: Matt Dienhart
 * Date: 3/17/2018
 * Description: (Final Project) This is the header file for the LifeSupport class (subclass of Space).
 * ***********************************************************************************************************************/

#ifndef LIFESUPPORT_HPP
#define LIFESUPPORT_HPP

#include "Space.hpp"
#include "Player.hpp"

class LifeSupport: public Space {
   public:
      void inspect(Player*);
      void interact(Player*);

      //constructor
      LifeSupport(Space* fwdPtr, Space* aftPtr, Space* portPtr, Space* strbrdPtr, std::string roomName): 
         Space(fwdPtr, aftPtr, portPtr, strbrdPtr, roomName) 
      {
         actionsRemaining = 1;
      }

      //destructor


};

#endif //LIFESUPPORT_HPP
