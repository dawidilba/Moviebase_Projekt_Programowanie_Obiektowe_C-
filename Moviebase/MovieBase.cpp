#include "MovieBase.h"

MovieBase::MovieBase()
{
}
MovieBase::~MovieBase()
{
}
void MovieBase::baseInfo()
{
	cout << "Obecnie w bazie znajduje sie " << amountOfMovies << " filmow\n";
	for (int i = 0; i < _movies.size(); i++)
	{
		cout << " * " << i + 1 << ". " << _movies[i].getTitle() << " | Rok premiery : " << _movies[i].getYear() << " | Srednia ocena na stronie IMDB : " << _movies[i].getImdbRating() <<" *\n";
	}
}
void MovieBase::loadXml()
{
	string rate;
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
	string name = "movie0";
	string tmp;
	TiXmlDocument xml;
	xml.LoadFile("xml/baza.xml");
	TiXmlElement* pointerRootElement = xml.FirstChildElement("root");
	if (pointerRootElement != 0)
	{
		for (int i = 1; i < 100000; i++)
		{
			int y = _movies.size();
			tmp = to_string(i);
			name.replace(5, 10, tmp);
			TiXmlElement* pointerMovie = pointerRootElement->FirstChildElement(name.c_str());
			if (pointerMovie != 0)
			{
				title = pointerMovie->Attribute("title");
				rate = pointerMovie->Attribute("yourRating");
				year = pointerMovie->Attribute("year");
				rated = pointerMovie->Attribute("rated");
				released = pointerMovie->Attribute("released");
				runtime = pointerMovie->Attribute("runtime");
				genre = pointerMovie->Attribute("genre");
				director = pointerMovie->Attribute("director");
				writer = pointerMovie->Attribute("writer");
				actors = pointerMovie->Attribute("actors");
				plot = pointerMovie->Attribute("plot");
				language = pointerMovie->Attribute("language");
				country = pointerMovie->Attribute("country");
				awards = pointerMovie->Attribute("awards");
				poster = pointerMovie->Attribute("poster");
				metascore = pointerMovie->Attribute("metascore");
				imdbRating = pointerMovie->Attribute("imdbRating");
				imdbVotes = pointerMovie->Attribute("imdbVotes");
				imdbID = pointerMovie->Attribute("imdbID");
				yourRating = atoi(rate.c_str());
				if (y == 0)
				{
					
					addMovie(Movie(yourRating, title, year, rated, released, runtime, genre, director, writer, actors, plot, language, country, awards, poster, metascore, imdbRating, imdbVotes, imdbID));
				}
				else
				{
					bool powtorzenie = false;
					for (int i = 0; i < _movies.size(); i++)
					{
						if (_movies[i].getTitle() == title)
						{
							powtorzenie = true;
							break;
						}
					}
					if (powtorzenie == false)
					{
						addMovie(Movie(yourRating, title, year, rated, released, runtime, genre, director, writer, actors, plot, language, country, awards, poster, metascore, imdbRating, imdbVotes, imdbID));
					}
				}
			}
			else
				break;
		}
	}
}
void MovieBase::loadXmlMovie(string fileName)
{
	int yourRating=0;
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
	string tmp="xml/";
	string tmpp = fileName;
	tmpp.insert(0,tmp);
	TiXmlDocument xml;
	xml.LoadFile(tmpp.c_str());
	TiXmlElement* pointerRootElement = xml.FirstChildElement("root");
	if (pointerRootElement != 0)
	{
		TiXmlElement*pointerMovie = pointerRootElement->FirstChildElement("movie");
		if (pointerMovie != 0)
		{
			title=pointerMovie->Attribute("title");
			year = pointerMovie->Attribute("year");
			rated = pointerMovie->Attribute("rated");
			released = pointerMovie->Attribute("released");
			runtime = pointerMovie->Attribute("runtime");
			genre = pointerMovie->Attribute("genre");
			director = pointerMovie->Attribute("director");
			writer = pointerMovie->Attribute("writer");
			actors = pointerMovie->Attribute("actors");
			plot = pointerMovie->Attribute("plot");
			language = pointerMovie->Attribute("language");
			country = pointerMovie->Attribute("country");
			awards = pointerMovie->Attribute("awards");
			poster = pointerMovie->Attribute("poster");
			metascore = pointerMovie->Attribute("metascore");
			imdbRating = pointerMovie->Attribute("imdbRating");
			imdbVotes = pointerMovie->Attribute("imdbVotes");
			imdbID = pointerMovie->Attribute("imdbID");
			int y = _movies.size();
			if (y == 0)
			{
				addMovie(Movie(yourRating, title, year, rated, released, runtime, genre, director, writer, actors, plot, language, country, awards, poster, metascore, imdbRating, imdbVotes, imdbID));
			}
			else
			{
				bool powtorzenie = false;
				for (int i = 0; i < _movies.size(); i++)
				{
					if (_movies[i].getTitle() == title)
					{
						powtorzenie = true;
						break;
					}
				}
				if (powtorzenie == false)
				{
					addMovie(Movie(yourRating, title, year, rated, released, runtime, genre, director, writer, actors, plot, language, country, awards, poster, metascore, imdbRating, imdbVotes, imdbID));
				}
			}
		}
	}
}
void MovieBase::saveXML()
{
	string name = "movie0";
	int x=0;
	TiXmlDocument xml;
	TiXmlDeclaration *pointerHeaderNode = new TiXmlDeclaration("1.0", "UTF-8", "");
	xml.LinkEndChild(pointerHeaderNode);
	TiXmlElement *pointerRootElement = new TiXmlElement("root");
	for (int i = 0; i < _movies.size(); i++)
	{
		x = i + 1;
		string tmp = to_string(x);
		name.replace(5, 10, tmp);
		TiXmlElement *pointerMovieElement = new TiXmlElement(name.c_str());
		pointerMovieElement->SetAttribute("title", _movies[i].getTitle().c_str());
		pointerMovieElement->SetAttribute("yourRating", _movies[i].getYourRating());
		pointerMovieElement->SetAttribute("year", _movies[i].getYear().c_str());
		pointerMovieElement->SetAttribute("rated", _movies[i].getRated().c_str());
		pointerMovieElement->SetAttribute("released", _movies[i].getReleased().c_str());
		pointerMovieElement->SetAttribute("runtime", _movies[i].getRuntime().c_str());
		pointerMovieElement->SetAttribute("genre", _movies[i].getGenre().c_str());
		pointerMovieElement->SetAttribute("director", _movies[i].getDirector().c_str());
		pointerMovieElement->SetAttribute("writer", _movies[i].getWriter().c_str());
		pointerMovieElement->SetAttribute("actors", _movies[i].getActors().c_str());
		pointerMovieElement->SetAttribute("plot", _movies[i].getPlot().c_str());
		pointerMovieElement->SetAttribute("language", _movies[i].getLanguage().c_str());
		pointerMovieElement->SetAttribute("country", _movies[i].getCountry().c_str());
		pointerMovieElement->SetAttribute("awards", _movies[i].getAwards().c_str());
		pointerMovieElement->SetAttribute("poster", _movies[i].getPoster().c_str());
		pointerMovieElement->SetAttribute("metascore", _movies[i].getMetascore().c_str());
		pointerMovieElement->SetAttribute("imdbRating", _movies[i].getImdbRating().c_str());
		pointerMovieElement->SetAttribute("imdbVotes", _movies[i].getImdbVotes().c_str());
		pointerMovieElement->SetAttribute("imdbID", _movies[i].getImdbID().c_str());
		pointerRootElement->LinkEndChild(pointerMovieElement);
	}
	xml.LinkEndChild(pointerRootElement);
	xml.SaveFile("xml/baza.xml");
}
void MovieBase::addMovie(Movie movie)
{
	_movies.push_back(movie);
	amountOfMovies++;
}
void MovieBase::sortMovies()
{
	sort(_movies.begin(), _movies.end(), _sort);
}
void MovieBase::setSortType(int a)
{
	_sort.set(a);
}
void MovieBase::movieInfo(int x)
{
	for (int i = 0; i < _movies.size(); i++)
	{
		if (i == x)
			_movies[i].movieInfo();
	}
}
void MovieBase::addRating(int x, int r)
{
	for (int i = 0; i < _movies.size(); i++)
	{
		if ((i == x)&& (r<=10) && (r>0))
			_movies[i].setYourRating(r);
	}
}
void MovieBase::ratedMovies()
{
	int j = 1;
	if (_movies.size() > 0)
	{
		cout << "Obecnie poogladales nastepujace filmy : \n";
		for (int i = 0; i < _movies.size(); i++)
		{
			if (_movies[i].getYourRating() != 0)
			{
				cout << " * " << j << ". " << _movies[i].getTitle() << " | Rok premiery : " << _movies[i].getYear() << " | Twoja ocena (1-10): " << _movies[i].getYourRating() << " *\n";
				j++;
			}
		}
	}
	else
		cout << "Nie oceniles jeszcze zadnego filmu !\n";
}
void MovieBase::ratedMovieInfo(int x)
{
	int j = 0;
	for (int i = 0; i < _movies.size(); i++)
	{
		if ((_movies[i].getYourRating() != 0))
		{
			j++;
			if (j == x)
				_movies[i].movieInfo();
		}
	}
}