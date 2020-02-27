#ifndef BST_H
#define BST_H

#include<iostream>
#include<string>
#include<stdexcept>

#include "BNode.h"
#include "Movie.h"
#include "Queue.h"

class binaryTree
{
	public:	

		binaryTree();
		~binaryTree();
		void recDelete(BNode<Movie>* curTree);
		void add(std::string name, float rating);
		void addHelper(Movie entry, BNode<Movie>* curSubTree);
		bool contains(std::string name, BNode<Movie>* curSubTree);
		bool isFull();
		bool isFullHelper(BNode<Movie>* curSubTree);
		void remove();
		void removeHelper(BNode<Movie>* curSubTree);
		void leaf(std::string title);
		bool leafHelper(std::string title, BNode<Movie>* curSubTree);
		void printLeaves();
		void printLeavesHelper(BNode<Movie>* curSubTree);
		void getHeight();
		int getHeightHelper(BNode<Movie>* curSubTree, int height);
		void preOrder();
		void preOrderPrint(BNode<Movie>* curSubTree);
		void postOrder();
		void postOrderPrint(BNode<Movie>* curSubTree);
		void inOrder();
		void inOrderPrint(BNode<Movie>* curSubTree);
		void levelOrder();
		void levelOrderPrint(BNode<Movie>* curSubTree);
		int getSize();

	private:
		BNode<Movie>* m_root;
		int size;
};
#endif
