#include "binaryTree.h"

binaryTree::binaryTree()
{
	m_root= nullptr;
	size = 0;
}

binaryTree::~binaryTree()
{
	recDelete(m_root);
}

void binaryTree::recDelete(BNode<Movie>* curTree)
{
	if(curTree != nullptr)
	{
		recDelete(curTree->getLeft());
		recDelete(curTree->getRight());
		delete curTree;
	}
}

void binaryTree::add(std::string name, float rating)
{
	Movie movie(name, rating);
	if(m_root == nullptr)
	{
		m_root= new BNode<Movie>(movie);
		size++;
	}
	else if(contains(name, m_root))
	{
		throw(std::runtime_error("The value is already in our tree!\n"));
	}
	else
	{	
		addHelper(movie, m_root);
		size++;
	}
}

void binaryTree::addHelper(Movie entry, BNode<Movie>* curSubTree)
{
	Queue<BNode<Movie>*> queue;
	queue.enqueue(curSubTree);

	while(queue.isEmpty() == false)
	{
		BNode<Movie>* curSubTree = queue.peekFront();
		queue.dequeue();
		if(curSubTree->getLeft() == nullptr)
		{
			curSubTree->setLeft(new BNode<Movie>(entry));
			break;
		}
		else
		{
			queue.enqueue(curSubTree->getLeft());
		}
		if(curSubTree->getRight() == nullptr)
		{
			curSubTree->setRight(new BNode<Movie>(entry));
			break;
		}
		else
		{
			queue.enqueue(curSubTree->getRight());
		}
	}
}

bool binaryTree::contains(std::string name, BNode<Movie>* curSubTree)
{
	if(curSubTree == nullptr)
	{
		return false;
	}
	else if(curSubTree->getEntry().getName() == name)
	{
		return(true);
	}
	return(contains(name, curSubTree->getLeft()));
	return(contains(name, curSubTree->getRight()));
}

bool binaryTree::isFull()
{
	return(isFullHelper(m_root));
}

bool binaryTree::isFullHelper(BNode<Movie>* curSubTree)
{
	if(curSubTree == nullptr)
	{
		return true;
	}
	if(curSubTree->getLeft() == nullptr && curSubTree->getRight() == nullptr)
	{
		return true;
	}
	if((curSubTree->getLeft() != nullptr) && (curSubTree->getRight() != nullptr))
	{
		return (isFullHelper(curSubTree->getLeft()) && isFullHelper(curSubTree->getRight()));
	}
	return false;
}

void binaryTree::remove()
{
	if(m_root->getLeft() == nullptr && m_root->getRight() == nullptr)
	{
		delete m_root;
		m_root = nullptr;
		size--;
		return;
	}
	if(m_root != nullptr)
	{
		removeHelper(m_root);
		size--;
	}
	else
	{
		throw std::runtime_error("Attempted removal on empty binary tree!\n");
	}
}

void binaryTree::removeHelper(BNode<Movie>* curSubTree)
{
	Queue<BNode<Movie>*> queue;
	queue.enqueue(m_root);
	BNode<Movie>* temp= nullptr;
	while(queue.isEmpty() == false)
	{
		temp = queue.peekFront();
		queue.dequeue();
		if(temp->getLeft() == nullptr)
		{

		}
		else
		{
			queue.enqueue(temp->getLeft());
		}
		if(temp->getRight() == nullptr)
		{

		}
		else
		{
			queue.enqueue(temp->getRight());
		}
	}
	Queue<BNode<Movie>*> queue2;
	queue2.enqueue(m_root);
	BNode<Movie>* temp2= nullptr;
	while(queue2.isEmpty() == false)
	{
		temp2= queue2.peekFront();
		queue2.dequeue();
		if(temp2->getRight() != nullptr)
		{
			if(temp2->getRight() == temp)
			{
				temp2->setRight(nullptr);
				size--;
				delete temp;
			}
			else
			{
				queue2.enqueue(temp2->getRight());
			}
		}
		if(temp2->getLeft() != nullptr)
		{
			if(temp2->getLeft() == temp)
			{
				temp2->setLeft(nullptr);
				size--;
				delete temp;
			}
			else
			{
				queue2.enqueue(temp2->getLeft());
			}
		}
	}
}

void binaryTree::leaf(std::string title)
{
	if(leafHelper(title, m_root))
	{
		std::cout<<title<<" is a leaf in the tree\n";
	}
	else
		std::cout<<title<<" is not a leaf in the tree\n";
}

bool binaryTree::leafHelper(std::string title, BNode<Movie>* curSubTree)
{
	if(curSubTree == nullptr)
	{
		return false;
	}
	if(curSubTree->getEntry().getName() == title)
	{
		if(curSubTree->getLeft() == nullptr && curSubTree->getRight() == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return(leafHelper(title, curSubTree->getLeft()) || leafHelper(title, curSubTree->getRight()));
		
}

void binaryTree::printLeaves()
{
	printLeavesHelper(m_root);
}

void binaryTree::printLeavesHelper(BNode<Movie>* curSubTree)
{
	if(curSubTree->getLeft() == nullptr && curSubTree->getRight() == nullptr)
	{
		std::cout<<curSubTree->getEntry().getName()<<std::endl;
	}
	if(curSubTree->getLeft() != nullptr)
		printLeavesHelper(curSubTree->getLeft());
	if(curSubTree->getRight() != nullptr)
		printLeavesHelper(curSubTree->getRight());
}

void binaryTree::getHeight()
{
	std::cout<<"The height of the tree is: "<<getHeightHelper(m_root, -1)<<std::endl;
}

int binaryTree::getHeightHelper(BNode<Movie>* curSubTree, int height)
{
	if(curSubTree != nullptr)
	{
		return(getHeightHelper(curSubTree->getLeft(), height+1));
	}
	return(height);
}

void binaryTree::preOrder()
{
	std::cout<<"preOrder print: \n";
	preOrderPrint(m_root);
}

void binaryTree::preOrderPrint(BNode<Movie>* curSubTree)
{
	if(curSubTree == nullptr)
	{
		return;
	}
	std::cout<< curSubTree->getEntry().getRating() <<std::endl;
	preOrderPrint(curSubTree->getLeft());
	preOrderPrint(curSubTree->getRight());
}

void binaryTree::postOrder()
{
	std::cout<<"postOrder print: \n";
	postOrderPrint(m_root);
}

void binaryTree::postOrderPrint(BNode<Movie>* curSubTree)
{
	if(curSubTree == nullptr)
	{
		return;
	}
	postOrderPrint(curSubTree->getLeft());
	postOrderPrint(curSubTree->getRight());
	std::cout<< curSubTree->getEntry().getRating() << std::endl;
}

void binaryTree::inOrder()
{
	std::cout<<"Inorder print: \n";
	inOrderPrint(m_root);
}

void binaryTree::inOrderPrint(BNode<Movie>* curSubTree)
{
	if(curSubTree == nullptr)
	{
		return;
	}
	inOrderPrint(curSubTree->getLeft());
	std::cout<< curSubTree->getEntry().getRating() << std::endl;
	inOrderPrint(curSubTree->getRight());
}

void binaryTree::levelOrder()
{
	std::cout<<"LevelOrder print: \n";
	levelOrderPrint(m_root);
}

void binaryTree::levelOrderPrint(BNode<Movie>* curSubTree)
{
	Queue<BNode<Movie>*> queue;
	queue.enqueue(curSubTree);
	while(queue.isEmpty() == false)
	{
		BNode<Movie>* curSubTree = queue.peekFront();
		std::cout<< curSubTree->getEntry().getName() << std::endl;
		queue.dequeue();
		if(curSubTree->getLeft() != nullptr)
		{
			queue.enqueue(curSubTree->getLeft());
		}
		if(curSubTree->getRight() != nullptr)
		{
			queue.enqueue(curSubTree->getRight());
		}
	}
}

int binaryTree::getSize()
{
	return size;
}

