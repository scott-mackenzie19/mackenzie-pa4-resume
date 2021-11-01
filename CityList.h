//
// Created by dalla on 10/26/2021.
//

#ifndef INC_21F_FLIGHT_PLANNER_CITYLIST_H
#define INC_21F_FLIGHT_PLANNER_CITYLIST_H
using namespace std;
#include <iostream>
#include "DSLinkedList.h"

//class exists exclusively to house originating city name and potential destinations.
//I will create a linked list of cityList objects, which will essentially create a doubly linked list
class CityList {
private:
    string originCity;
    DSLinkedList<string> destinationList;
public:
    void setOrigin(string word);
    void setDestination( DSLinkedList<string>& destinations);
    string getOrigin();
    DSLinkedList<string> getDestinations();
};


#endif //INC_21F_FLIGHT_PLANNER_CITYLIST_H
