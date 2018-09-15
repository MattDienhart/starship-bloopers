/*************************************************************************************************************************
 * Author: Matt Dienhart
 * Date: 3/17/2018
 * Description: (Final Project) This is the header file for the Propulsion class (subclass of Space).
 * ***********************************************************************************************************************/

#ifndef PROPULSION_HPP
#define PROPULSION_HPP

#include "Space.hpp"
#include "Player.hpp"

class Propulsion: public Space {
   public:
      void inspect(Player*);
      void interact(Player*);

      //constructor
      Propulsion(Space* fwdPtr, Space* aftPtr, Space* portPtr, Space* strbrdPtr, std::string roomName): 
         Space(fwdPtr, aftPtr, portPtr, strbrdPtr, roomName) 
      {
         actionsRemaining = 1;
      }

      //destructor


};

#endif //PROPULSION_HPP
