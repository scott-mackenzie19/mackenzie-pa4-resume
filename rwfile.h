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

    void printList() {
        for (int i = 0; i < adjacencyList.length(); i++) {
            cout << adjacencyList.get(i).getOrigin() << endl;
            adjacencyList.get(i).getDestinations().displayAll();
        }
    }

    DSLinkedList<DSLinkedList<string>> backtrack(string start, string end) {
        DSstack<string> cityStack;
        DSLinkedList<string> cityList;
        DSLinkedList<DSLinkedList<string>> pathList;
        DSLinkedList<int> iterList;
        cityStack.push(start);
        cityList.append(start);
        this->printList();
        for (int i = 0; i < adjacencyList.length(); i++) {
            int num = 0;
            iterList.append(num); //for each list in adjacency list, index initialized to 0
        }
        LOOP: while (!cityStack.isEmpty()) {
            if (cityStack.getTop() == end ) { // if stack.top == destination
                pathList.append(cityList);
                cityStack.pop();
                cityList.pop();
            }
            else { //if stack.top not destination
                for (int i = 0; i < adjacencyList.length(); i++) {
                    if (adjacencyList.get(i).getOrigin() == cityStack.getTop()) {
                        while (adjacencyList.get(i).getDestinations().iterateTo(iterList.iterateTo(i)->data) != nullptr) { // for connection in stack.top
                            if (cityList.contains(adjacencyList.get(i).getDestinations().iterateTo(iterList.get(i))->data)) { // if connection on stack
                                iterList.iterateTo(i)->data++;
                            }
                            else { //if connection not on stack
                                cityStack.push(adjacencyList.get(i).getDestinations().iterateTo(iterList.get(i))->data);
                                cityList.append(adjacencyList.get(i).getDestinations().iterateTo(iterList.get(i))->data);
                                iterList.iterateTo(i)->data++;
                                goto LOOP;
                            }
                        }
                        if (adjacencyList.get(i).getDestinations().iterateTo(iterList.get(i)) == nullptr) { //if connection is null
                            cityStack.pop();
                            cityList.pop();
                            iterList.iterateTo(i)->data = 0;
                            i = 0;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < pathList.length(); i++) {
            pathList.get(i).displayAll();
        }
        int storeindex = 0;
        return pathList;
    }

    void shortestPath( string& filename , string& filena) {
        ifstream file;
        file.open(filename);
        string throwawy;
        getline(file, throwawy);
        DSLinkedList<DSLinkedList<string>> commandList;
        while (file.good()) {
            string line;
            DSLinkedList<string> wordList;
            getline(file, line);
            stringstream ss(line);
            while(ss.good()) {
                string word;
                getline(ss, word, ' ');
                wordList.append(word);
            }
            commandList.append(wordList);
        }
        file.close();
        ofstream ofss;
        ofss.open(filena);
        ofss.clear();
        for (int i = 0; i < commandList.length(); i++) {
            ofss << "Flight " << i + 1 << ": " << commandList.get(i).get(0) << "," << commandList.get(i).get(1) << " (" << commandList.get(i).get(2) << ")" << endl;
            int count = 0;
            for (int j = 0; j < backtrack(commandList.get(i).get(0), commandList.get(i).get(1)).length(); j++) {
                if (count < 3) {
                    ofss << "  " << "Itinerary " << j + 1 << ":" << endl;
                   for (int q = 0; q < backtrack(commandList.get(i).get(0), commandList.get(i).get(1)).get(j).length() - 1; q++) {
                       ofss << "    " << backtrack(commandList.get(i).get(0), commandList.get(i).get(1)).get(j).get(q) << "->" << backtrack(commandList.get(i).get(0), commandList.get(i).get(1)).get(j).get(q + 1) << endl;
                   }
                }
                count++;

            }
        }
        ofss.close();


    }
};


#endif //INC_21F_FLIGHT_PLANNER_RWFILE_H
