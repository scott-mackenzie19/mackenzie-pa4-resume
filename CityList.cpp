//
// Created by dalla on 10/26/2021.
//

#include "CityList.h"

string CityList::getOrigin() {
    return originCity;
}

DSLinkedList<string>& CityList::getDestinations() {
    return destinationList;
}

void CityList::setOrigin(string word) {
    originCity = word;

}

void CityList::setDestination(DSLinkedList<string> &destinations) {
    destinationList = destinations;
}
