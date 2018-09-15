/************************************************************************************************************
 * Author: Matt Dienhart
 * Date: 3/10/2018
 * Description: (Final Project) This is the header file for the Space class.
 * **********************************************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include "Player.hpp"

#include <iostream>
#include <string>

class Space {
   protected: 
      Space* forward;
      Space* aft;
      Space* port;
      Space* starboard;
      std::string name;
      bool inspected;
      int actionsRemaining;
      std::string inspectionReminder;
      std::string actionLabel;
   
   public:
      //setters
      void setForward(Space*);
      void setAft(Space*);
      void setPort(Space*);
      void setStarboard(Space*);
      void setName(std::string);
      void setInspected(bool);
      void setActionsRemaining(int);
      void setInspectionReminder(std::string);
      void reduceActionsRemaining();   
 
      //getters
      Space* getForward() const
         { return forward; }
      Space* getAft() const
         { return aft; }
      Space* getPort() const
         { return port; }
      Space* getStarboard() const
         { return starboard; }
      std::string getName() const
         { return name; }
      bool getInspected() const
         { return inspected; }
      int getActionsRemaining() const
         { return actionsRemaining; }
      std::string getInspectionReminder() const
         { return inspectionReminder; }
      std::string getActionLabel() const
         { return actionLabel; } 

      //member functions
      virtual void inspect(Player*) = 0;
      virtual void interact(Player*) = 0;

      //constructor with parameters
      Space(Space* fwdPtr, Space* aftPtr, Space* portPtr, Space* strbrdPtr, std::string roomName)
      {
         this->forward = fwdPtr;
         this->aft = aftPtr;
         this->port = portPtr;
         this->starboard = strbrdPtr;
         this->name = roomName;
         inspected = false;
         actionsRemaining = 0;
         inspectionReminder = "You haven't looked around in this room yet.";
         actionLabel = "Interact";
         
      }

      //destructor
      ~Space() {}

};

#endif //SPACE_HPP
