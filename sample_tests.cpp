//
// Created by MARK FONTENOT on 9/14/21.
//

/**
 * This file contains some simple tests.
 *
 * DO NOT add the #define CATCH_CONFIG_RUNNER to this file.
 * It is already in catch_setup.cpp
 *
 * Note that you can have more than one cpp file with tests in them.
 * For example, you could have a test file for your DSString and a
 * separate one for your DSVector.
 */

#include "catch.hpp"
#include "DSLinkedList.h"
#include "DSstack.h"

TEST_CASE("Linked List", "[DSLinkedList]") {
    SECTION("Destuctor") {
        Node<string>* aye = new Node<string>[1];
        delete[] aye;
        aye = nullptr;
        Node<string>* aye1 = new Node<string>[2];
        delete[] aye1;
        aye1 = nullptr;
        REQUIRE(aye == nullptr);
        REQUIRE(aye1 == nullptr);
    }
    SECTION("Equality Operator") {
        DSLinkedList<string> list;
        DSLinkedList<string> list2;
        list.append("LEss gooo");
        list.append("score some fookin");
        list.append("Goalssss!!!!");
        list = list2;
        //list2.displayAll();
        REQUIRE(list.get(1) == list2.get(1));
        REQUIRE(list.get(0) == list.get(0));
    }
    SECTION("Append Function") {
        DSLinkedList<string> list;
        list.append("AYE");
        list.append("WHY");
        list.append("HELLO");
        REQUIRE(list.get(0) == "AYE");
        REQUIRE(list.get(1) == "WHY");
        REQUIRE(list.get(2) == "HELLO");
    }
}

TEST_CASE("Stack", "[DSstack]") {
    SECTION("Return Top") {
        DSstack<string> list;
        list.push("AYE");
        list.push("WHY");
        list.push("HELLO");
        REQUIRE(list.getTop() == "HELLO");
    }
}