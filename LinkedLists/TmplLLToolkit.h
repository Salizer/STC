#ifndef TmplLLToolkit_H
#define TmplLLToolkit_H
/** \file TmplLLToolkit.h
	\brief Contains functions for a linked list.
	\author René H. Thomsen
	\date 12/02 -11
*/
// License: GPL
#include "TmplNode.h" // No list without TmplNode<Item>s

/** \brief Toolkit for a linked list.
    \warning Dynamic memory.(Use functions like 'clear')
*/
template <typename Item>
class TmplLLToolkit
{
	// Functions(static)
	public:
	/** \brief Inserts new head for the list.
	    \pre 'headPtr' points to the head of a list.
	    \post New head is inserted with data from 'entry' and 'headPtr' is updated to point to the new head.
	*/
	static void headInsert(TmplNode<Item>*& headPtr, const Item& entry)
	{
		TmplNode<Item>* newHead = new TmplNode<Item>(entry, headPtr); // New head which point to the old head
		headPtr = newHead; // Change the old head to point to the new head
	}

	/** \brief Removes the current head of the list.
	    \pre None.
	    \post Removes the head and makes 'headPtr' point to the next item in the list.
	*/
	static void headRemove(TmplNode<Item>*& headPtr)
	{
		TmplNode<Item>* tmpPtr = headPtr->getLink(); // Save next element
		delete headPtr; // Delete old head
		headPtr = tmpPtr; // Make head point to new head
	}

	/** \brief Inserts a new node to the list.
	    \pre 'prevPtr' is not NULL.
	    \post A new node is inserted after the node 'prevPtr' points to, and the the new node points to what 'prevPtr' previously pointed to.
	*/
	static void insert(TmplNode<Item>* prevPtr, const Item& entry)
	{
		TmplNode<Item>* newTmpNode = new TmplNode<Item>(entry, prevPtr->getLink()); // New TmplNode<Item>
		prevPtr->setLink(newTmpNode); // Make prevPtr link to the new TmplNode<Item> instead
	}

	/** \brief Removes a node from the list.
	    \pre 'prevPtr' is not NULL.
	    \post The node after what 'prevPtr' points to is removed and 'prevPtr' now points to what that node pointed to.
	*/
	static void remove(TmplNode<Item>* prevPtr)
	{
		TmplNode<Item>* tmpPtr = prevPtr->getLink()->getLink(); // The link after the 'target'
		delete prevPtr->getLink(); // Deletes 'target'
		prevPtr->setLink(tmpPtr); // Make prevPtr link to the link after the 'target'
	}

	/** \brief Copies the list.
	    \pre None.
	    \post Returns a pointer to a new list which is a copy of the list, head pointer('sourcePtr') pointed to.
	*/
	static TmplNode<Item>* copy(TmplNode<Item>* sourcePtr)
	{
		TmplNode<Item>* newHead = new TmplNode<Item>(sourcePtr->getData()); // New head with same value as the other head
		sourcePtr = sourcePtr->getLink(); // Head now points to its link
		TmplNode<Item>* cursorPtr = newHead; // Pointer used to add items to the new head

		// Add items
		while(sourcePtr != NULL)
		{
			cursorPtr->setLink(new TmplNode<Item>(sourcePtr->getData())); // Copy item to the new list
			cursorPtr = cursorPtr->getLink(); // Make the cursor ptr point to its next link so it´s ready to add new TmplNode<Item>
			sourcePtr = sourcePtr->getLink(); // Next TmplNode<Item> to be copied(If not NULL)
		}
		return(newHead);
	}

	/** \brief Clears the list.
	    \pre 'headPtr' points to the head of a list.
	    \post Clears the list 'headPtr' pointed to.
	*/
	static void clear(TmplNode<Item>*& headPtr)
	{
		TmplNode<Item>* tmpPtr = headPtr; // Used to hold old address that headPtr pointed to so we are able to delete the old value while going through the list

		// 'Walk' through the list by making headPtr go to next element and then delete the element it pointed to before
		while(headPtr != NULL)
		{
			headPtr = headPtr->getLink(); // Head ptr now points to the next TmplNode<Item> in the list
			delete tmpPtr; // We delete what headPtr previously pointed to
			tmpPtr = headPtr; // Tmp ptr is now ready to delete next TmplNode<Item>
		}
	}

	/** \brief Prints the items in the list.
	    \pre None.
	    \post All the items from the start of the list('headPtr') to the end is printed out.
	*/
	static void print(TmplNode<Item>* headPtr)
	{
		// Go trough the list
		while(headPtr != NULL)
		{
			std::cout << headPtr->getData() << " - "; // Print value
			headPtr = headPtr->getLink(); // Go through next element in list
		}
		std::cout << "\\\n"; // Print to indicate end of list plus adding newline
	}

	/** \brief Splits the list in two parts.
	    \pre
	    \post The list is splitted in two parts. It returns a address to the the node after what 'splitPtr' pointed to and the node 'splitPtr' pointed to is now the last node in the list before the split.
	*/
	static TmplNode<Item>* split(TmplNode<Item>* splitPtr)
	{
		TmplNode<Item>* newHead = splitPtr->getLink(); // Gets TmplNode<Item> for the new head(After split)
		splitPtr->setLink(NULL); // End the old list at split point
		return(newHead); // Returns the new head for the list after the split
	}

	/** \brief Makes a list.
	    \pre 'values' is atleast of the size 'n' and 'n' > 0.
	    \post Returns a pointer to a new list with 'n' items from the array('values').
	*/
	static TmplNode<Item>* build(Item* values, size_t n)
	{
		// Note: Doesn´t work if 'n' == 0
		TmplNode<Item>* newHead = new TmplNode<Item>(values[0]); // The new list head with the first value from the array
		TmplNode<Item>* iteratePtr = newHead; // Used to build the new list while going through the array
		for(size_t i = 1; i < n; i++)
		{
			iteratePtr->setLink(new TmplNode<Item>(values[i])); // Add TmplNode<Item> to list
			iteratePtr = iteratePtr->getLink(); // Go to next TmplNode<Item> to ready to add new TmplNode<Item>
		}
		return(newHead); // Returning head of the new list
	}

	/** \brief Joint the 2 lists.
	    \pre Each pointer points to a list.
	    \post 'head2' is now connected with the end node from the list 'head1' pointed to.
	*/
	static void join(TmplNode<Item>* head1, TmplNode<Item>* head2)
	{
		// Find end of first list
		while(head1->getLink() != NULL)
		{
			head1 = head1->getLink();
		}
		head1->setLink(head2); // Combine the list
	}

	/** \brief Rotates the list one time to the left.
	    \pre None.
	    \post The nodes are rotated one time to the left, so the head is now the last node. 'head' points to the new head.
	*/
	static void rotateLeft(TmplNode<Item>*& head)
	{
		// In case of no elements or only one element
		if(head == NULL || head->getLink() == NULL)
			return;

		TmplNode<Item>* oldHead = head; // To contain info for old head location
		TmplNode<Item>* searchPtr = head; // Ptr used to search for end of list

		// Search for end of list
		while(searchPtr->getLink() != NULL)
			searchPtr = searchPtr->getLink();

		head = head->getLink(); // Makes head point to the new head(After rotation)
		searchPtr->setLink(oldHead); // Connect end with the old head
		oldHead->setLink(NULL); // End the new list so the old head is now the end of the list
	}

	/** \brief Rotates the list one time to the right.
	    \pre None.
	    \post The nodes are rotated one time to the right, so the last node is now the head. 'head' points to the new head.
	*/
	static void rotateRight(TmplNode<Item>*& head)
	{
		// In case of only one element
		if(head->getLink() == NULL)
			return;

		TmplNode<Item>* searchPtr = head; // Ptr used to search for end of list

		// Search for TmplNode<Item> before the last TmplNode<Item>
		while(searchPtr->getLink()->getLink() != NULL)
			searchPtr = searchPtr->getLink();

		searchPtr->getLink()->setLink(head); // Connects end of list with head
		head = searchPtr->getLink(); // Head now point to the new head
		searchPtr->setLink(NULL); // End the new list
	}
};

#endif