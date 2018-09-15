/*************************************************************************************************************************
 * Author: Matt Dienhart
 * Date: 3/17/2018
 * Description: (Final Project) This is the header file for the FlightDeck class (subclass of Space).
 * ***********************************************************************************************************************/

#ifndef FLIGHTDECK_HPP
#define FLIGHTDECK_HPP

#include "Space.hpp"
#include "Player.hpp"

class FlightDeck: public Space {
   public:
      void inspect(Player*);
      void interact(Player*);

      //constructor
      FlightDeck(Space* fwdPtr, Space* aftPtr, Space* portPtr, Space* strbrdPtr, std::string roomName): 
         Space(fwdPtr, aftPtr, portPtr, strbrdPtr, roomName) 
      {
         actionsRemaining = 2;
      }

      //destructor


};

#endif //FLIGHTDECK_HPP
