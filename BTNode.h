#ifndef BTNODE_H
#define BTNODE_H
/** \file BTNode.h 
	\brief Contains class for a Node to be used for a binary tree.
	\author René H. Thomsen
	\date 30/03 -10
*/
// License: GPL
#include <iostream>
#include <cstdlib>


/** \brief A Node for a binary tree.
*/
template<typename Item>
class BTNode
{
    // Fields
	private:
    Item data;
    BTNode* left, *right;

	public:
	// Functions
	// -Constructors and deconstructors
	/** \brief Default constructor.
	    \pre NULL for BTNode arguments if no children.
	    \post Constructs a Binary Node with the children specified.
	*/
	BTNode(BTNode* argLeft, BTNode* argRight, Item argData)
	{
	    // Set data
        setLeft(argLeft);
        setRight(argRight);
        setData(argData);
	}

	/** \brief Destructor.
	    \pre None.
	    \post Cleans up.
	*/
	~BTNode()
	{
	    // Cleaning
	}

	// -Get and set
	/** \brief Returns the data that the node holds.
	    \pre None.
	    \post Returns a copy of the data the Node holds.
	*/
    Item getData()
    {
        return(data);
    }
    /** \brief Sets the data that the node holds.
	    \pre None.
	    \post Changes the data the Node holds.
	*/
    void setData(Item argData)
    {
        data = argData;
    }
    /** \brief Returns left child.
        \pre None.
        \post Returns the address of the left child. (NULL if none)
    */
    BTNode* getLeft()
    {
        return(left);
    }
    /** \brief Sets left child.
        \pre 'argLeft' is the adress of a BTNode or NULL.
        \post The Nodes left child is set to the address of 'argLeft'.
    */
    void setLeft(BTNode* argLeft)
    {
        left = argLeft;
    }
    /** \brief Returns right child.
        \pre None.
        \post Returns the address of the right child. (NULL if none)
    */
    BTNode* getRight()
    {
        return(right);
    }
    /** \brief Sets right child.
        \pre 'argRight' is the adress of a BTNode or NULL.
        \post The Nodes rihgt child is set to the address of 'argRight'.
    */
    void setRight(BTNode* argRight)
    {
        right = argRight;
    }
};

// Extra functions
/** \brief Returns the sum of all the nodes.
    \pre The type of 'Item' should be able to added together with their own type.
    \post Returns the sum of the data all the nodes in the tree holds.
*/
template<typename Item>
unsigned int sum(BTNode<Item>* root)
{
    // Base case: Not a node
    if(root == NULL)
        return(0);

    // Recursive case: Returns sum of 'root' and subtree sum of 'left' and 'right'.
    return(sum(root->getLeft()) + sum(root->getRight()) + 1);
}

/** \brief Prints the tree´s nodes.
    \pre 'depth' should be 0 at first call for proper output.
    \post The tree is printed like seen laying down on it´s left side.
*/
template<typename Item>
void printTree(BTNode<Item>* root, unsigned int depth = 0)
{
    // BC
    if(root == NULL)
        return;

    // RC
    printTree(root->getRight(), depth + 1);
    for(unsigned int i = 0; i < depth; i++)
        cout << "    ";
    cout << root->getData() << '\n';
    printTree(root->getLeft(), depth + 1);
}

// -Helper function
template<typename Item>
void insertItem(BTNode<Item>* root, Item data)
{
    // Find location
    BTNode<Item>* cursor = root;

    while(cursor != NULL)
    {
        if(cursor->getData() < data)
        {
            if(cursor->getRight() == NULL)
            {
                cursor->setRight(new BTNode<Item>(NULL, NULL, data));
                return;
            }
            else
                cursor = cursor->getRight();
        }
        else
        {
            if(cursor->getLeft() == NULL)
            {
                cursor->setLeft(new BTNode<Item>(NULL, NULL, data));
                return;
            }
            else
                cursor = cursor->getLeft();
        }
    }
    return; // Nothing inserted
}

/** \brief Generates a binary tree from an array.
    \pre 'root' is not already pointing to other data.(Except NULL) 'array' should be atleast the size of 'size'.
    \post A tree is generated from the array, with a total number of nodes equal to 'size'.
    \warning dynamic memory should be released later.
*/
// The function
template<typename Item>
void generateBST(BTNode<Item>* root, Item* array, size_t size)
{
    for(size_t i = 0; i < size; i++)
    {
        insertItem(root, array[i]);
    }
}
#endif
