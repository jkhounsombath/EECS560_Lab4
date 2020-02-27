template <typename T>
Queue<T>::Queue()
{
	itemCount= 0;
	m_front= nullptr;
	m_back= nullptr;
}

template <typename T>
Queue<T>::~Queue()
{
	while (m_back != nullptr && m_front != nullptr)
	{
		Node<T>* temp= m_front;
		m_front= m_front->getNext();
		delete temp;
	}
}

template <typename T>
bool Queue<T>::isEmpty() const
{
	return(itemCount == 0);
}

template <typename T>
void Queue<T>::enqueue(T value)
{
	if(itemCount == 0)
	{
		m_front= new Node<T>(value);
		m_back= m_front;
	}
	else
	{
		m_back->setNext(new Node<T>(value));
		m_back= m_back->getNext();
	}
	itemCount++;
}

template <typename T>
void Queue<T>::dequeue()
{
	if (itemCount == 0)
	{
		throw std::runtime_error("Dequeue attempted on an empty queue\n");
		return;
	}
	else if(m_front == m_back)
	{
		delete m_front;
		m_front= m_back= nullptr;
		itemCount--;
	}
	else
	{
		Node<T>* temp= m_front;
		m_front= m_front->getNext();
		delete temp;
		itemCount--;
	}
}

template <typename T>
T Queue<T>::peekFront() const
{
	if (itemCount == 0)
	{
		throw std::runtime_error("Peek attempted on an empty queue.\n");
		
	}
	else
	{
		return(m_front->getEntry());
	}
}

template <typename T>
int Queue<T>::getAmount() const
{
	return(itemCount);
}
