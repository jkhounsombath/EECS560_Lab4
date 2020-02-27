#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>

class Movie
{
	private:
		std::string m_name;
		float m_rating;
	public:
		Movie();
		Movie(std::string name, float rating);
		~Movie();
		std::string getName();
		void setName(std::string name);
		float getRating();
		void setRating(float rating);
};
#endif
