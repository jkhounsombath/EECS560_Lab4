#include "Executive.h"

Executive::Executive(std::string fileName)
{
	std::ifstream inFile(fileName);
	std::string name = "";
	float rating;
	while(inFile>>name)
	{
		name.pop_back();
		inFile>>rating;
		BTree.add(name, rating);
	}
}

void Executive::run()
{
	std::cout<<"WELCOME TO JUSTIN'S LAB 4\n---------------------------------\n";
	int choice;
	do
	{
		std::cout<<"Choose one of the following commands:\n\n1)isFull\n2)addMovie\n3)removeMovie\n4)Leaf\n5)printLeaves\n6)PrintTreeHeight\n7)PreOrder\n8)PostOrder\n9)Inorder\n10)levelOrder\n11)Exit\n\nChoice: ";
		std::cin>>choice;
		if(choice == 1)
		{
			if(BTree.isFull())
			{
				std::cout<<"The tree is full.\n";
			}
			else
			{
				std::cout<<"The tree is not full. \n";
			}
		}
		else if(choice == 2)
		{
			std::string name;	
			int rating= 0;
			std::string tname = "";
			std::cout<<"Enter a name for a movie to add: ";
			std::cin>>name;
			std::cout<<"What was its rating: ";
			std::cin>>rating;
			BTree.add(name, rating);
		}
		else if(choice == 3)
		{
			std::cout<<"Removing last added node.\n";
			BTree.remove();
			std::cout<<"Remove successful.\n";
		}
		else if(choice == 4)
		{
			std::string name;
			std::cout<<"Enter a name of a movie to check if it is a leaf: ";
			std::cin>>name;
			BTree.leaf(name);
		}
		else if(choice == 5)
		{
			BTree.printLeaves();
		}
		else if(choice == 6)
		{
			BTree.getHeight();
		}
		else if(choice == 7)
		{
			BTree.preOrder();
		}
		else if(choice == 8)
		{
			BTree.postOrder();
		}
		else if(choice == 9)
		{
			BTree.inOrder();
		}
		else if(choice == 10)
		{
			BTree.levelOrder();
		}
		else if(choice == 11)
		{
			std::cout<<"Goodbye!\n";
		}
		else
		{
			std::cout<<"Invalid choice! (must be vaue between 1-6)\n\n\n";
		}
	}while(choice != 11);
}
