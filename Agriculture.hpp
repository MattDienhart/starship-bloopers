/*************************************************************************************************************************
 * Author: Matt Dienhart
 * Date: 3/17/2018
 * Description: (Final Project) This is the header file for the Agriculture class (subclass of Space).
 * ***********************************************************************************************************************/

#ifndef AGRICULTURE_HPP
#define AGRICULTURE_HPP

#include "Space.hpp"
#include "Player.hpp"

class Agriculture: public Space {
   public:
      void inspect(Player*);
      void interact(Player*);

      //constructor
      Agriculture(Space* fwdPtr, Space* aftPtr, Space* portPtr, Space* strbrdPtr, std::string roomName): 
         Space(fwdPtr, aftPtr, portPtr, strbrdPtr, roomName) 
      {
         actionsRemaining = 1;
      }

      //destructor


};

#endif //AGRICULTURE_HPP
