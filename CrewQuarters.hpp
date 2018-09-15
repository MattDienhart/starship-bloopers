/*************************************************************************************************************************
 * Author: Matt Dienhart
 * Date: 3/14/2018
 * Description: (Final Project) This is the header file for the CrewQuarters class (subclass of Space).
 * ***********************************************************************************************************************/

#ifndef CREWQUARTERS_HPP
#define CREWQUARTERS_HPP

#include "Space.hpp"
#include "Player.hpp"

class CrewQuarters: public Space {
   public:
      void inspect(Player*);
      void interact(Player*);

      //constructor
      CrewQuarters(Space* fwdPtr, Space* aftPtr, Space* portPtr, Space* strbrdPtr, std::string roomName): 
         Space(fwdPtr, aftPtr, portPtr, strbrdPtr, roomName) 
      {
         actionsRemaining = 1;
      }

      //destructor


};

#endif //CREWQUARTERS_HPP
