#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <string>
#include <fstream>
#include "BNode.h"
#include "binaryTree.h"
#include <algorithm>

class Executive
{
	private:
		binaryTree BTree;
	public:
		Executive(std::string fileName);
		void run();
};
#endif
