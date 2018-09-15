# Author: Matt Dienhart
# Date: 3/17/2018
# Description: This is the makefile for the final project

CXX = g++
CFLAGS = -g -std=c++11

output: main.o Game.o Player.o Space.o CrewQuarters.o Agriculture.o MedBay.o FlightDeck.o MainDeck.o Kitchen.o Propulsion.o LifeSupport.o EVAChamber.o DockingBay.o
	${CXX} main.o Game.o Player.o Space.o CrewQuarters.o Agriculture.o MedBay.o FlightDeck.o MainDeck.o Kitchen.o Propulsion.o LifeSupport.o EVAChamber.o DockingBay.o -o output

main.o: main.cpp
	${CXX} ${CFLAGS} -c main.cpp

Game.o: Game.cpp Game.hpp
	${CXX} ${CFLAGS} -c Game.cpp

Player.o: Player.cpp Player.hpp
	${CXX} ${CFLAGS} -c Player.cpp

Space.o: Space.cpp Space.hpp
	${CXX} ${CFLAGS} -c Space.cpp

CrewQuarters.o: CrewQuarters.cpp CrewQuarters.hpp
	${CXX} ${CFLAGS} -c CrewQuarters.cpp

Agriculture.o: Agriculture.cpp Agriculture.hpp
	${CXX} ${CFLAGS} -c Agriculture.cpp

MedBay.o: MedBay.cpp MedBay.hpp
	${CXX} ${CFLAGS} -c MedBay.cpp

FlightDeck.o: FlightDeck.cpp FlightDeck.hpp
	${CXX} ${CFLAGS} -c FlightDeck.cpp

MainDeck.o: MainDeck.cpp MainDeck.hpp
	${CXX} ${CFLAGS} -c MainDeck.cpp

Kitchen.o: Kitchen.cpp Kitchen.hpp
	${CXX} ${CFLAGS} -c Kitchen.cpp

Propulsion.o: Propulsion.cpp Propulsion.hpp
	${CXX} ${CFLAGS} -c Propulsion.cpp

LifeSupport.o: LifeSupport.cpp LifeSupport.hpp
	${CXX} ${CFLAGS} -c LifeSupport.cpp

EVAChamber.o: EVAChamber.cpp EVAChamber.hpp
	${CXX} ${CFLAGS} -c EVAChamber.cpp

DockingBay.o: DockingBay.cpp DockingBay.hpp
	${CXX} ${CFLAGS} -c DockingBay.cpp

clean:
	rm *.o output

