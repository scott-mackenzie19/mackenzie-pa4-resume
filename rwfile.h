//
// Created by dalla on 10/31/2021.
//

#ifndef INC_21F_FLIGHT_PLANNER_RWFILE_H
#define INC_21F_FLIGHT_PLANNER_RWFILE_H
#include "DSLinkedList.h"
#include <fstream>
#include <sstream>
#include "CityList.h"


class rwfile {
private:
DSLinkedList<CityList> adjacencyList;
DSLinkedList<DSLinkedList<string>> flights;
public:
    DSLinkedList<CityList> getAdjacency() {
        return adjacencyList;
    }
    void loadAdjacency( string& filename) {
        ifstream file;
        string number;
        file.open(filename);
        DSLinkedList<string> locations;
        if (file.is_open()) {
            cout <<"OPEN" << endl;
        }
        getline(file, number);
        while (file.good()) {
            string line;
            getline(file, line);
            stringstream ss(line);
            //cout << line << endl;
            DSLinkedList<string> tempList;
            for (int i = 0; i < 5; i++) {
                string word;
                getline(ss, word, ' ');
                //cout << word << endl;
                tempList.append(word);
            }
            flights.append(tempList);
            //cout << tempList.get(0) << endl;
            if (!locations.contains(tempList.get(0))) {
                locations.append(tempList.get(0));
            }
            if (!locations.contains(tempList.get(1))) {
                locations.append(tempList.get(1));
            }
            //cout << tempList.get(1) << endl;
        }
        for (int i = 0; i < locations.length(); i++) {
            CityList cityItem;
            DSLinkedList<string> temp;
            for (int j = 0; j < flights.length(); j++) {
                if (flights.get(j).contains(locations.get(i))) {
                    if (flights.get(j).get(0) != locations.get(i) && !temp.contains(flights.get(j).get(0))) {
                        temp.append(flights.get(j).get(0));
                    }
                    if (flights.get(j).get(1) != locations.get(i)&& !temp.contains(flights.get(j).get(1))) {
                        temp.append(flights.get(j).get(1));
                    }
                }
            }
            cityItem.setOrigin(locations.get(i));
            cityItem.setDestination(temp);
            adjacencyList.append(cityItem);
        }

    }
    void shortestPath(string start, string end) {
        DSstack<string> cityStack;
        DSLinkedList<string> cityList;
        DSLinkedList<DSstack<string>> pathList;
        cityStack.push(start);
        cityList.append(start);
        for (int i = 0; i < adjacencyList.length(); i++) {
            adjacencyList.get(i).getDestinations().Iterator(); //iterators initialized
        }
        LOOP: while (!cityStack.isEmpty()) {
        cout << "here" << endl;
            if (cityStack.getTop() == end) {
                cout << "New Path!" << endl;
                pathList.append(cityStack);
                cityStack.pop();
                cityList.pop();
            }
            else {
                for (int i = 0; i < adjacencyList.length(); i++) {
                    cout << "OK" << endl;
                    if (adjacencyList.get(i).getOrigin() == cityStack.getTop()) {
                        for (int j = 0; j < adjacencyList.get(i).getDestinations().length(); j ++) {
                            cout << "woa" << endl;
                            if (adjacencyList.get(i).getDestinations().getNext() == nullptr) {
                                cityStack.pop();
                                cityList.pop();
                                adjacencyList.get(i).getDestinations().decrement();
                            }
                            if (cityList.contains(adjacencyList.get(i).getDestinations().dereference())) {
                                adjacencyList.get(i).getDestinations().increment();
                            }
                            else if (!cityList.contains(adjacencyList.get(i).getDestinations().dereference())) {
                                cityStack.push(adjacencyList.get(i).getDestinations().dereference());
                                cityList.append(adjacencyList.get(i).getDestinations().dereference());
                                adjacencyList.get(i).getDestinations().increment();
                                goto LOOP;
                            }
                        }

                    }
                }
            }
        }
    }
};


#endif //INC_21F_FLIGHT_PLANNER_RWFILE_H
