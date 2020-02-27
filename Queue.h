#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "node.h"
#include <stdexcept>

template <typename T>
class Queue
{
	public:
		/**
		* @post constructor
		**/
		Queue();

		/**
		* @post destructor
		**/
		~Queue();

		/**
		* @post returns whether or not our queue is empty
		* @return true if queue empty false otherwise
		**/
		bool isEmpty() const;

		/**
		* @post inserts a value into back of our queue
		* @param value: entry for our node we enqueue
		**/
		void enqueue(T value);

		/**
		* @post deletes the node at the front of the queue
		* @throw std::runtime_error if the queue is empty
		**/
		void dequeue();

		/**
		* @post returns the value in the front node of the queue
		* @throw std::runtime_error if the queue is empty
		**/
		T peekFront() const;

		/**
		* @post returns the number of values in our queue
		**/
		int getAmount() const;
	private:
		Node<T>* m_front;
		Node<T>* m_back;
		int itemCount;
};
#include "Queue.cpp"

#endif
