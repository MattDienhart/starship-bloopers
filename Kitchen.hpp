/*************************************************************************************************************************
 * Author: Matt Dienhart
 * Date: 3/17/2018
 * Description: (Final Project) This is the header file for the Kitchen class (subclass of Space).
 * ***********************************************************************************************************************/

#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include "Space.hpp"
#include "Player.hpp"

class Kitchen: public Space {
   public:
      void inspect(Player*);
      void interact(Player*);

      //constructor
      Kitchen(Space* fwdPtr, Space* aftPtr, Space* portPtr, Space* strbrdPtr, std::string roomName): 
         Space(fwdPtr, aftPtr, portPtr, strbrdPtr, roomName) 
      {
         actionsRemaining = 1;
      }

      //destructor


};

#endif //KITCHEN_HPP
