#include "Movie.h"
#include "Sort.h"
#include "tinystr.h"
#include "tinyxml.h"
#include <vector>
#include <algorithm>

using namespace std;

class MovieBase
{
	int amountOfMovies;
	vector<Movie>_movies;
	Sort _sort;
public:
	MovieBase();
	~MovieBase();
	void baseInfo();
	void loadXml();
	void loadXmlMovie(string fileName);
	void saveXML();
	void addMovie(Movie movie);
	void sortMovies();
	void setSortType(int a);
	void movieInfo(int x);
	void addRating(int x, int r);
	void ratedMovies();
	void ratedMovieInfo(int x);
};

