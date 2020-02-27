#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename itemType>
class Node
{
	private:
		itemType m_entry;
		Node<itemType>* m_next= nullptr;

	public:
		/**
		* @post constructor
		**/
		Node();

		/**
		* @pre entry for a node
		* @post inserts a new node at a position with entry
		* @param entry: A new entry to put in the list
		**/
		Node(itemType entry);

		/**
		* @pre entry for a node
		* @post inserts a new node at a position with entry
		* @param entry: A new entry to put in the list
		* @param nextNode: pointer to nextNode
		**/
		Node(itemType entry, Node<itemType>* nextNode);

		/**
		* @post destructor
		**/
		~Node();

		/**
		* @pre entry for a node
		* @post sets the entry of a node
		* @param entry: the entry of a node
		**/
		void setEntry(itemType entry) ;

		/**
		* @post returns the value in a node
		**/
		itemType getEntry() const;

		/**
		* @post sets the nextNode
		* @param nextNode: pointer to nextNode
		**/
		void setNext(Node<itemType>* nextNode);

		/**
		* @post returns a ptr to the next node in a list
		**/
		Node<itemType>* getNext() const;
};
#include "node.cpp"
#endif
