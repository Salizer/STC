#ifndef TMPLNODE_H
#define TMPLNODE_H
/** \file  TmplNode.h
	\brief Contains a node Class for linkeds list.
	\author René H. Thomsen
	\date 24/04 -11
*/
// License: GPL

#include <cstdlib>
#include<iostream>

/** \brief Node for a linked list.
*/
template<typename Item>
class TmplNode
{
    // Private members
    private:
	Item dataField;
	TmplNode* linkField;

    // Functions
	public:
	// -Constructors
	/** \brief Default constructor.
	    \pre None.
	    \post A node is created.
	*/
	TmplNode(const Item& d = Item(), TmplNode* l = NULL) : dataField(d), linkField(l)
	{
	    // Nothing
	}

	/** \brief Returns the Node´s data.
	    \pre None.
	    \post Returns a copy of the data the Node holds.
	*/
    Item getData()
	{
		return dataField;
	}

    /** \brief Sets the Node´s data.
	    \pre None.
	    \post Sets the data the Node holds.
	*/
	void setData(const Item& d = Item())
	{
		dataField = d;
	}

    /** \brief Gets the next Node.
        \pre None.
        \post Returns the adress for the next Node in the list.(NULL if no more nodes)
    */
	TmplNode* getLink()
	{
		return linkField;
	}

    /** \brief Sets the next Node.
        \pre None.
        \post Sets the next Node in the list.
    */
	void setLink(TmplNode* l)
	{
		linkField = l;
	}
};
#endif