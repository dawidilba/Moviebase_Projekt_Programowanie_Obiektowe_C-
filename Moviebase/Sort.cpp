#include "Sort.h"

Sort::Sort()
{
}
Sort::~Sort()
{
}
void Sort::set(int a)
{
	sortType = a;
}
bool Sort::operator()(Movie i, Movie j)
{
	switch (sortType)
	{
	case typesOfSort::title:
		return i.getTitle() < j.getTitle();
		break;
	case typesOfSort::year:
		return i.getYear() > j.getYear();
		break;
	case typesOfSort::imdbRating:
		return i.getImdbRating() > j.getImdbRating();
		break;
	case typesOfSort::yourRating:
		return i.getYourRating() > j.getYourRating();
		break;
	}
}
