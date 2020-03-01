#pragma once
#include "MovieBase.h"
#include "conio.h"
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Widget.H>

class MovieEngine
{
	static MovieEngine* instance;
	MovieEngine();
	~MovieEngine();
	MovieBase _movieBase;
	Fl_Window* window = new Fl_Window(500, 600, "Filmoteka");
	Fl_Input* inputDetails = new Fl_Input(260, 310, 50, 30, "Nr filmu : ");
	Fl_Button* enterButtonDetails = new Fl_Button(350, 310, 100, 30, "Wprowadz");
	Fl_Button* backButtonDetails = new Fl_Button(350, 310, 100, 30, "Cofnij");
	Fl_Input* inputAdd = new Fl_Input(230, 240, 125, 30, "Nazwa pliku '.xml' : ");
	Fl_Button* enterButtonAdd = new Fl_Button(350, 240, 100, 30, "Wprowadz");
	Fl_Button* enterButtonAddRating = new Fl_Button(350, 380, 100, 30, "Wprowadz");
	Fl_Input* inputAddRating = new Fl_Input(145, 380, 50, 30, "Nr filmu : ");
	Fl_Input* inputRate = new Fl_Input(280, 380, 50, 30, "Ocena : ");
	Fl_Button* startButton = new Fl_Button(50, 370, 400, 50, "START");
	Fl_Button* databaseButton = new Fl_Button(50, 160, 400, 50, "Baza Filmow");
	Fl_Button* allMoviesButton = new Fl_Button(50, 160, 400, 50, "Przegladaj filmy w bazie");
	Fl_Button* addMovieButton = new Fl_Button(50, 230, 400, 50, "Dodaj film do bazy");
	Fl_Button* yourMoviesButton = new Fl_Button(50, 230, 400, 50, "Twoje filmy");
	Fl_Button* sortButton1 = new Fl_Button(50, 90, 400, 50, "Posortuj po tytule (alfabetycznie)");
	Fl_Button* sortButton2 = new Fl_Button(50, 160, 400, 50, "Posortuj malejaco po roku premiery");
	Fl_Button* sortButton3 = new Fl_Button(50, 230, 400, 50, "Posortuj malejaco wedlug Twojej oceny");
	Fl_Button* sortButton4 = new Fl_Button(50, 230, 400, 50, "Posortuj malejaco po ocenie IMDB");
	Fl_Button* movieDetailsButton = new Fl_Button(50, 300, 400, 50, "Zobacz szczegoly filmu");
	Fl_Button* addRatingButton = new Fl_Button(50, 370, 400, 50, "Dodaj ocene filmu");
	Fl_Button* backButton = new Fl_Button(50, 440, 400, 50, "Powrot");
	Fl_Button* exitButton = new Fl_Button(50, 440, 400, 50, "Wyjscie");
	void Buttons(bool,bool,bool,bool,bool,bool,bool,bool,bool,bool,bool,bool,bool,bool,bool,bool,bool,bool,bool,bool,bool);
	static void cStart(Fl_Widget*, void*);
	inline void iStart();
	static void cDatabase(Fl_Widget*, void*);
	inline void iDatabase();
	static void cYourMovies(Fl_Widget*, void*);
	inline void iYourMovies();
	static void cAllMovies(Fl_Widget*, void*);
	inline void iAllMovies();
	static void cAddMovie(Fl_Widget*, void*);
	inline void iAddMovie();
	static void cSort1(Fl_Widget*, void*);
	inline void iSort1();
	static void cSort2(Fl_Widget*, void*);
	inline void iSort2();
	static void cSort3(Fl_Widget*, void*);
	inline void iSort3();
	static void cSort1Y(Fl_Widget*, void*);
	inline void iSort1Y();
	static void cSort2Y(Fl_Widget*, void*);
	inline void iSort2Y();
	static void cSort3Y(Fl_Widget*, void*);
	inline void iSort3Y();
	static void cEnterButtonAdd(Fl_Widget*, void*);
	inline void iEnterButtonAdd();
	static void cEnterButtonAddRating(Fl_Widget*, void*);
	inline void iEnterButtonAddRating();
	static void cMovieDetails(Fl_Widget*, void*);
	inline void iMovieDetails();
	static void cEnterButtonDetails(Fl_Widget*, void*);
	inline void iEnterButtonDetails();
	static void cEnterButtonDetailsY(Fl_Widget*, void*);
	inline void iEnterButtonDetailsY();
	static void cMovieDetailsY(Fl_Widget*, void*);
	inline void iMovieDetailsY();
	static void cAddRating(Fl_Widget*, void*);
	inline void iAddRating();
	static void cExit(Fl_Widget*, void*);
	void buttonParam(Fl_Button *x, bool hide);
	void inputButtonsParam(Fl_Button*x, bool hide);
	void inputParam(Fl_Input*x, bool hide);
	int makeWindow();
public:
	static MovieEngine* getInstance();
	MovieEngine& operator=(const MovieEngine&) = delete;
	void start();
};

