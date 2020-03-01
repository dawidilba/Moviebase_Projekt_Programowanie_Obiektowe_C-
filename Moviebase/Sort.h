#include"Movie.h"
#include <map>
#include <memory>

enum typesOfSort
{
	title,
	year,
	imdbRating,
	yourRating,
};

class Sort
{
	int sortType;
public:
	Sort();
	~Sort();
	void set(int a);
	bool operator()(Movie i, Movie j);
};

