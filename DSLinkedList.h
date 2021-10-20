//
// Created by dalla on 10/20/2021.
//

#ifndef INC_21F_FLIGHT_PLANNER_DSLINKEDLIST_H
#define INC_21F_FLIGHT_PLANNER_DSLINKEDLIST_H
#include <iostream>

template <typename DT> class Node {

private:
    DT data;
    Node<DT> *prev; //pointer to previous node
    Node<DT> *next; //pointer to next node
    template<typename D2> friend
    class DSLinkedList; //friend class of DSLinkedList now
public:
    Node() {
        prev = nullptr;
        next = nullptr;
    }

    ~Node() {
        delete prev;
        delete next;
    }
};

template<typename DT>class DSLinkedList{
private:
    Node<DT>* head;
public:
    DSLinkedList() {
        head = nullptr;
    }
    ~DSLinkedList() {
        while (head->next != nullptr) {
            Node<DT>* next = head->next;
            delete head;
            head = next;
        }
    }


    void append(DT item) {

    }

};

#endif //INC_21F_FLIGHT_PLANNER_DSLINKEDLIST_H
