/*************************************************************************************************************************
 * Author: Matt Dienhart
 * Date: 3/17/2018
 * Description: (Final Project) This is the header file for the MedBay class (subclass of Space).
 * ***********************************************************************************************************************/

#ifndef MEDBAY_HPP
#define MEDBAY_HPP

#include "Space.hpp"
#include "Player.hpp"

class MedBay: public Space {
   public:
      void inspect(Player*);
      void interact(Player*);

      //constructor
      MedBay(Space* fwdPtr, Space* aftPtr, Space* portPtr, Space* strbrdPtr, std::string roomName): 
         Space(fwdPtr, aftPtr, portPtr, strbrdPtr, roomName) 
      {
         actionsRemaining = 1;
      }

      //destructor


};

#endif //MEDBAY_HPP
