//
// Created by dalla on 10/20/2021.
//

#ifndef INC_21F_FLIGHT_PLANNER_DSLINKEDLIST_H
#define INC_21F_FLIGHT_PLANNER_DSLINKEDLIST_H
#include <iostream>
using namespace std;

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
            if (next == nullptr) {
                delete next;
            }
        }
    }
    void append(DT data) {
        Node<DT>* node = new Node<DT>[1];
        node->data = data;
        if(head == nullptr){
            head = node;
            cout<<"new node added(firstnode) !"<<endl;
            return;
        }
        Node<DT>* temp = head;
        Node<DT>* prev;
        while(temp->next != nullptr){
            prev = temp;
            temp = temp->next; //list traversed to the end
        }
        temp->next = node;
        temp->prev = prev; //once at end, final data value is linked
        cout<<"new node added at back!"<<endl;
    }




    void insert(DT item) {

    }

};

#endif //INC_21F_FLIGHT_PLANNER_DSLINKEDLIST_H
