/*************************************************************************************************************************
 * Author: Matt Dienhart
 * Date: 3/17/2018
 * Description: (Final Project) This is the header file for the DockingBay class (subclass of Space).
 * ***********************************************************************************************************************/

#ifndef DOCKINGBAY_HPP
#define DOCKINGBAY_HPP

#include "Space.hpp"
#include "Player.hpp"

class DockingBay: public Space {
   public:
      void inspect(Player*);
      void interact(Player*);

      //constructor
      DockingBay(Space* fwdPtr, Space* aftPtr, Space* portPtr, Space* strbrdPtr, std::string roomName): 
         Space(fwdPtr, aftPtr, portPtr, strbrdPtr, roomName) 
      {
         actionsRemaining = 2;
      }

      //destructor


};

#endif //DOCKINGBAY_HPP
