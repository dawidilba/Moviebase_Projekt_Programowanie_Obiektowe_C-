#include "Movie.h"

Movie::Movie()
{
}
Movie::Movie(int yo, string ti, string ye, string ra, string re, string ru, string ge, string di, string wr, string ac, string pl, string la, string co, string aw, string po, string me, string imdbr, string imdbv, string imdbi)
{
	yourRating = yo;
	title = ti;
	year = ye;
	rated = ra;
	released = re;
	runtime = ru;
	genre = ge;
	director = di;
	writer = wr;
	actors = ac;
	plot = pl;
	language = la;
	country = co;
	awards = aw;
	poster = po;
	metascore = me;
	imdbRating = imdbr;
	imdbVotes = imdbv;
	imdbID = imdbi;
}
string Movie::getTitle()
{
	return title;
}
void Movie::setTitle(string s)
{
	title = s;
}
string Movie::getYear()
{
	return year;
}
void Movie::setYear(string y)
{
	year = y;
}
int Movie::getYourRating()
{
	return yourRating;
}
void Movie::setYourRating(int y)
{
	yourRating = y;
}
void Movie::movieInfo()
{
	cout << "Twoja ocena (0 jesli jeszcze nie widziales) : " << yourRating << endl;
	cout << "Tytul filmu : "<< title << endl;
	cout << "Rok premiery : " << year << endl;
	cout << "Klasyfikacja : "<< rated << endl;
	cout << "Data wydania : "<< released << endl;
	cout << "Dlugosc trwania : "<< runtime << endl;
	cout << "Gatunek : "<< genre << endl;
	cout << "Rezyser : "<< director << endl;
	cout << "Pisarz : "<< writer << endl;
	cout << "Aktorzy : "<< actors << endl;
	cout << "Fabula : "<<plot << endl;
	cout << "Jezyk : "<< language << endl;
	cout << "Produkcja : "<<country << endl;
	cout << "Nagrody : "<<awards << endl;
	cout << "Link do plakatu : "<<poster << endl;
	cout << "Srednia ocena na stronie metacritics : "<<metascore << endl;
	cout << "Ocena na imdb : " << imdbRating << endl;
	cout << "Liczba glosow : " <<imdbVotes << endl;
	cout << "ID filmu na stronie imdb : "<<imdbID << endl;
}
string Movie::getMetascore()
{
	return metascore;
}
void Movie::setMetascore(string m)
{
	metascore = m;
}
string Movie::getRated()
{
	return rated;
}
string Movie::getReleased()
{
	return released;
}
string Movie::getRuntime()
{
	return runtime;
}
string Movie::getGenre()
{
	return genre;
}
string Movie::getDirector()
{
	return director;
}
string Movie::getWriter()
{
	return writer;
}
string Movie::getActors()
{
	return actors;
}
string Movie::getPlot()
{
	return plot;
}
string Movie::getLanguage()
{
	return language;
}
string Movie::getCountry()
{
	return country;
}
string Movie::getAwards()
{
	return awards;
}
string Movie::getPoster()
{
	return poster;
}
string Movie::getImdbRating()
{
	return imdbRating;
}
string Movie::getImdbVotes()
{
	return imdbVotes;
}
string Movie::getImdbID()
{
	return imdbID;
}
Movie::~Movie()
{
}