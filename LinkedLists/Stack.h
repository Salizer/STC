#ifndef STACK_H
#define STACK_H
/** \file Stack.h
	\brief Contains a Stack class.
	\author René H. Thomsen
	\date 23/02 -11
*/
// License: GPL

#include "TmplLLToolkit.h"
#include "TmplNode.h"

/** \brief A stack class which uses templates to make a stack of 'any' type/class and has functions to add and remove items from the list/stack.
*/
template<typename Item>
class Stack
{
    private:
    TmplNode<Item>* headPtr; // Points to top of stack

    public:
    /** Default constructor */
    Stack()
    {
        headPtr = NULL; // List is empty so pointing to NULL
    }
    /** Default destructor */
    ~Stack()
    {
        // Clear list
        while(!isEmpty())
            pop();
    }

    /** \brief Pushes an item onto the top of the Stack.
        \pre None.
        \post A copy of 'item' is inserted into the Stack.
    */
    void push(Item n)
    {
        TmplLLToolkit<Item>::headInsert(headPtr, n);
    }

    /** \brief Pops an item from the top of the Stack.
        \pre None.
        \post The top item is removed from the Stack.
    */
    void pop()
    {
        if(!isEmpty())
             TmplLLToolkit<Item>::headRemove(headPtr);
    }

    /** \brief Returns the top of the Stack.
        \pre None.
        \post Returns a copy of the Item of the Stack.(NULL if no Item)
    */
    Item top()
    {
        if(!isEmpty())
            return(headPtr->getData());
        else
            return(NULL);
    }

    /** \brief Checks for the Stack being empty.
        \pre None.
        \post Returns 'true' if empty else it returns 'false'.
    */
    bool isEmpty()
    {
        return(headPtr == NULL); // If points to 'NULL' then the stack is empty
    }
};
#endif