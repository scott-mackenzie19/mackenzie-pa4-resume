//
// Created by dalla on 10/24/2021.
//
#include "DSLinkedList.h"

#ifndef INC_21F_FLIGHT_PLANNER_DSSTACK_H
#define INC_21F_FLIGHT_PLANNER_DSSTACK_H
template <typename DT> class DSstack {
private:
    DSLinkedList<DT> stack;
    int top;
public:
    DSstack() {
        top = -1; //in empty stack top initialized to -1
    }
    bool isEmpty() {
        if (top == -1) {
            return true; //if top = -1, stack has not been filled
        }
        else {
            return false;
        }
    }
    void push(DT item) {
        stack.append(item);
        ++top;
    }
    DT pop() {
        if ( this->isEmpty()) {
            cout << "Stack is empty" << endl;
            DT useless;
            return useless;
        }
        DT holder = stack.get(top); //variable initiated to top value of stack
        stack.pop();
        --top;
        return holder;

    }
    DT getTop() {
        if (this->isEmpty()) {
            cout << "Stack is empty" << endl;
            return this->stack.get(0);
        }
        DT holder = stack.get(top );
        return holder;

    }
    void print() {
        stack.displayAll();
    }
};
#endif //INC_21F_FLIGHT_PLANNER_DSSTACK_H
