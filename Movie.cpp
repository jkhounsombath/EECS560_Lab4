#include "Movie.h"

Movie::Movie()
{
	m_name = "";
	m_rating = 0.0;  
}

Movie::Movie(std::string name, float rating)
{
	m_name = name;
	m_rating = rating;
}

Movie::~Movie()
{

}

std::string Movie::getName()
{
	return m_name;
}

void Movie::setName(std::string name)
{
	m_name= name;
}

float Movie::getRating()
{
	return m_rating;
}

void Movie::setRating(float rating)
{
	m_rating = rating;
}
