template <typename itemType>
Node<itemType>::Node()
{
	m_next= nullptr;
}

template <typename itemType>
Node<itemType>::Node(itemType entry)
{
	m_entry= entry;
	m_next= nullptr;
}

template <typename itemType>
Node<itemType>::Node(itemType entry, Node* nextNode)
{
	m_entry= entry;
	m_next= nextNode;
}

template <typename itemType>
Node<itemType>::~Node()
{

}

template <typename itemType>
void Node<itemType>::setEntry(itemType entry)
{
	m_entry= entry;
}

template <typename itemType>
itemType Node<itemType>::getEntry() const
{
	return( m_entry );
}

template <typename itemType>
void Node<itemType>::setNext(Node<itemType>* nextNode)
{
	m_next= nextNode;
}

template <typename itemType>
Node<itemType>* Node<itemType>::getNext() const
{
	return ( m_next );
}
