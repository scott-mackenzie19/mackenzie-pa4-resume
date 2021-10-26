/**
 * Fall 2021 PA 04 - Flight Planner Template Repo.
 * Based on PA 02 Template repo
 */

#include <iostream>
#include <fstream>
#include "DSLinkedList.h"
#include "DSstack.h"
#include "CityList.h"

/**
 * catch_setup.h and catch_setup.cpp contain the #define directive for
 * the CATCH2 framework.  You can see in main below how I'm calling the
 * runCatchTests() function which is declared in this header.
 *
 * On average, this should reduce the build time for your project on your local
 * machine.
 */
#include "catch_setup.h"
using namespace std;

int main(int argc, char** argv) {
    if(argc == 2) {
        //runCatchTests();
    }
    else {
        std::cout << "Hello, 2341 students!" << std::endl;
        std::cout << "Attempting to open and write to " << argv[0] << std::endl;
        DSstack<string> stringStack;
        stringStack.push("Michael Norwood");
        stringStack.push("Aye");
        stringStack.push("Leggo");
        stringStack.print();
        stringStack.pop();
        stringStack.print();
        stringStack.pop();
        stringStack.pop();
        stringStack.pop();
        std::ofstream o(argv[3]);
        o << "Writing to output file." << std::endl;
        o.close();
    }
    //
    return 0;
}