#pragma once
#include <iostream>
#include <string>
using namespace std;
class Movie
{
	int yourRating;
	string title;
	string year;
	string rated; 
	string released;
	string runtime;
	string genre;
	string director;
	string writer;
	string actors; 
	string plot; 
	string language;
	string country;
	string awards;
	string poster;
	string metascore;
	string imdbRating;
	string imdbVotes;
	string imdbID;
public:
	Movie();
	Movie(int yo, string ti, string ye, string ra, string re, string ru, string ge, string di, string wr, string ac, string pl, string la, string co, string aw, string po, string me, string imdbr, string imdbv, string imdbi);
	string getTitle();
	void setTitle(string s);
	string getYear();
	void setYear(string y);
	int getYourRating();
	void setYourRating(int y);
	void movieInfo();
	string getMetascore();
	void setMetascore(string m);
	string getRated();
	string getReleased();
	string getRuntime();
	string getGenre();
	string getDirector();
	string getWriter();
	string getActors();
	string getPlot();
	string getLanguage();
	string getCountry();
	string getAwards();
	string getPoster();
	string getImdbRating();
	string getImdbVotes();
	string getImdbID();
	~Movie();
};
