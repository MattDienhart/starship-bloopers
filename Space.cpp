/*****************************************************************************************************
 * Author: Matt Dienhart
 * Date: 3/10/2018
 * Description: (Final Project) This is the class implementation file for Space.
 * ***************************************************************************************************/

#include "Space.hpp"

//Space::setForward()
//This member function sets the pointer for the space that is forward of this space
void Space::setForward(Space* forwardSpace) {
   this->forward = forwardSpace;
   return;
}

//Space::setAft()
//This member function sets the pointer for the space that is aft of this space
void Space::setAft(Space* aftSpace) {
   this->aft = aftSpace;
   return;
}

//Space::setPort()
//This member function sets the pointer for the space that is left of this space
void Space::setPort(Space* portSpace) {
   this->port = portSpace;
   return;
}

//Space::setStarboard()
//This member function sets the pointer for hte space that is right of this space
void Space::setStarboard(Space* starboardSpace) {
   this->starboard = starboardSpace;
   return;
}

//Space::setName()
//This member function sets the name of the space
void Space::setName(std::string inputName) {
   this->name = inputName;
   return;
}

//Space::setInspected()
//This method sets the status whether the space has been inspected yet or not
void Space::setInspected(bool status) {
   this->inspected = status;
   return;
}

//Space::setActionsRemaining()
//This method sets the number of actions left to be performed in the space
void Space::setActionsRemaining(int status) {
   this->actionsRemaining = status;
   return;
}

//Space::setInspectionReminder()
//This method changes the inspection reminder message that appears when the player moves to this space
void Space::setInspectionReminder(std::string message) {
   this->inspectionReminder = message;
   return;
}

//Space::reduceActionsRemaining()
//This method decrements the number of actions remaining for this space
void Space::reduceActionsRemaining() {
   this->actionsRemaining --;
   return;
}
