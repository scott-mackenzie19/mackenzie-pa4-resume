//
// Created by dalla on 10/26/2021.
//

#include "CityList.h"

string CityList::getOrigin() {
    return originCity;
}

DSLinkedList<CityList> CityList::getDestinations() {
    return destinationList;
}

void CityList::setOrigin(string &word) {
    originCity = word;

}

void CityList::setDestination(DSLinkedList<CityList> &destinations) {
    destinationList = destinations;
}
