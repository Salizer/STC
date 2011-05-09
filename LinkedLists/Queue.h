#ifndef QUEUE_H
#define QUEUE_H
/** \file Queue.h
	\brief Contains a class for a Queue.
	\author René H. Thomsen
	\date 23/02 -11
*/
// License: GPL

#include "TmplLLToolkit.h"
#include "TmplNode.h"

/** \brief A queue class which uses templates to make a queue of 'any' type/class and has functions to add and remove items from the list/queue.
*/
template<typename Item>
class Queue
{
    // Private members
    private:
    TmplNode<Item>* headPtr; // Where items get out
    TmplNode<Item>* tailPtr; // Where items get in

    public:
    /** Default constructor */
    Queue()
    {
        headPtr = NULL;
        tailPtr = NULL;
    }
    /** Default destructor */
    ~Queue()
    {
        // Clear list
        while(!isEmpty())
            pop();
    }

    /** \brief Pushes an Item into the queue.
        \pre None.
        \post The Item as placed at the back of the Queue.
    */
    void push(Item n)
    {
        if(!isEmpty())
        {
            TmplLLToolkit<Item>::insert(tailPtr, n);
            tailPtr = tailPtr->getLink();
        }
        else // If first item in queue
        {
            tailPtr = new TmplNode<Item>(n);
            headPtr = tailPtr;
        }

    }

    /** \brief Pops an Item from the queue.
        \pre None.
        \post The Item in the front of the Queue is removed.
    */
    void pop()
    {
        if(!isEmpty())
            TmplLLToolkit<Item>::headRemove(headPtr);
    }

    /** \brief Returns the front of the Queue.
        \pre None.
        \post Returns a copy of the Item in the front of the Queue.(NULL if none)
    */
    Item front()
    {
        if(!isEmpty())
            return(headPtr->getData());
        else
            return(NULL);
    }

    /** \brief Checks for the Queue being empty.
        \pre None.
        \post Returns 'true' if empty else it returns 'false'.
    */
    bool isEmpty()
    {
        return(!headPtr); // If points to 'NULL'/0 then the stack is empty
    }

    /** \brief Prints the Queue and clears it.
        \pre None.
        \post Prints all the items in the Queue and removes them one by one.
    */
    void dump()
    {
        TmplLLToolkit<Item>::print(headPtr); // The 'reuse' way
    }
};

#endif // QUEUE_H
