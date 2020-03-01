#include "MovieEngine.h"

MovieEngine *MovieEngine::instance = 0;
MovieEngine::MovieEngine()
{
}
MovieEngine::~MovieEngine()
{
}
void MovieEngine::Buttons(bool inDetails, bool enterBDetails, bool backBDetails, bool inAdd, bool enterBAdd, bool enterBAddRating, bool inAddRating, bool inRate, bool startB, bool databaseB, bool allMoviesB, bool addMovieB, bool yourMoviesB, bool sortB1, bool sortB2, bool sortB3, bool sortB4, bool movieDetailsB, bool addRatingB, bool backB, bool exitB)
{
	if (inDetails==true)
		inputDetails->show();
	else if (inDetails==false)
		inputDetails->hide();
	if (enterBDetails == true)
		enterButtonDetails->show();
	else if (enterBDetails == false)
		enterButtonDetails->hide();
	if (backBDetails == true)
		backButtonDetails->show();
	else if (backBDetails == false)
		backButtonDetails->hide();
	if (inAdd == true)
		inputAdd->show();
	else if (inAdd == false)
		inputAdd->hide();
	if (enterBAdd == true)
		enterButtonAdd->show();
	else if (enterBAdd == false)
		enterButtonAdd->hide();
	if (enterBAddRating == true)
		enterButtonAddRating->show();
	else if (enterBAddRating == false)
		enterButtonAddRating->hide();
	if (inAddRating == true)
		inputAddRating->show();
	else if (inAddRating == false)
		inputAddRating->hide();
	if (inRate == true)
		inputRate->show();
	else if (inRate == false)
		inputRate->hide();
	if (startB == true)
		startButton->show();
	else if (startB == false)
		startButton->hide();
	if (databaseB == true)
		databaseButton->show();
	else if (databaseB == false)
		databaseButton->hide();
	if (allMoviesB == true)
		allMoviesButton->show();
	else if (allMoviesB == false)
		allMoviesButton->hide();
	if (addMovieB == true)
		addMovieButton->show();
	else if (addMovieB == false)
		addMovieButton->hide();
	if (yourMoviesB == true)
		yourMoviesButton->show();
	else if (yourMoviesB == false)
		yourMoviesButton->hide();
	if (sortB1 == true)
		sortButton1->show();
	else if (sortB1 == false)
		sortButton1->hide();
	if (sortB2 == true)
		sortButton2->show();
	else if (sortB2 == false)
		sortButton2->hide();
	if (sortB3 == true)
		sortButton3->show();
	else if (sortB3 == false)
		sortButton3->hide();
	if (sortB4 == true)
		sortButton4->show();
	else if (sortB4 == false)
		sortButton4->hide();
	if (movieDetailsB == true)
		movieDetailsButton->show();
	else if (movieDetailsB == false)
		movieDetailsButton->hide();
	if (addRatingB == true)
		addRatingButton->show();
	else if (addRatingB == false)
		addRatingButton->hide();
	if (backB == true)
		backButton->show();
	else if (backB == false)
		backButton->hide();
	if (exitB == true)
		exitButton->show();
	else if (exitB == false)
		exitButton->hide();

}
void MovieEngine::cStart(Fl_Widget *, void *v)
{
	((MovieEngine*)v)->iStart();
}
inline void MovieEngine::iStart()
{
	system("cls");
	Buttons(false, false, false, false, false, false, false, false, false, true, false, false, true, false, false, false, false, false, false, false, true);
	databaseButton->callback(cDatabase);
	yourMoviesButton->callback(cYourMovies);
}
void MovieEngine::cDatabase(Fl_Widget *, void *v)
{
	((MovieEngine*)v)->iDatabase();
}
inline void MovieEngine::iDatabase()
{
	Buttons(false, false, false, false, false, false, false, false, false, false, true, true, false, false, false, false, false, false, false, true, false);
	backButton->callback(cStart,this);
	allMoviesButton->callback(cAllMovies, this);
	addMovieButton->callback(cAddMovie, this);
}
void MovieEngine::cYourMovies(Fl_Widget *, void *v)
{
	((MovieEngine*)v)->iYourMovies();
}
inline void MovieEngine::iYourMovies()
{
	system("cls");
	_movieBase.ratedMovies();
	Buttons(false, false, false, false, false, false, false, false, false, false, false, false, false, true, true, true, false, true, false, true, false);
	backButton->callback(cStart, this);
	sortButton1->callback(cSort1Y, this);
	sortButton2->callback(cSort2Y, this);
	sortButton3->callback(cSort3Y, this);
	movieDetailsButton->callback(cMovieDetailsY, this);
}
void MovieEngine::cAllMovies(Fl_Widget *, void *v)
{
	((MovieEngine*)v)->iAllMovies();
}
inline void MovieEngine::iAllMovies()
{
	system("cls");
	_movieBase.baseInfo();
	Buttons(false, false, false, false, false, false, false, false, false, false, false, false, false, true, true, false, true, true, true, true, false);
	backButton->callback(cDatabase, this);
	sortButton1->callback(cSort1, this);
	sortButton2->callback(cSort2, this);
	sortButton4->callback(cSort3, this);
	movieDetailsButton->callback(cMovieDetails, this);
	addRatingButton->callback(cAddRating, this);
}
void MovieEngine::cAddMovie(Fl_Widget *, void *v)
{
	((MovieEngine*)v)->iAddMovie();
}
inline void MovieEngine::iAddMovie()
{
	Buttons(false, false, false, true, true, false, false, false, false, false, true, false, false, false, false, false, false, false, false, true, false);
	backButton->callback(cStart, this);
	enterButtonAdd->callback(cEnterButtonAdd, this);
}
void MovieEngine::cSort1(Fl_Widget *, void *v)
{
	((MovieEngine*)v)->iSort1();
}
inline void MovieEngine::iSort1()
{
	backButtonDetails->hide();
	enterButtonDetails->hide();
	inputDetails->hide();
	enterButtonAddRating->hide();
	inputAddRating->hide();
	inputRate->hide();
	movieDetailsButton->show();
	addRatingButton->show();
	system("cls");
	_movieBase.setSortType(0);
	_movieBase.sortMovies();
	_movieBase.baseInfo();
}
void MovieEngine::cSort2(Fl_Widget *, void *v)
{
	((MovieEngine*)v)->iSort2();
}
inline void MovieEngine::iSort2()
{
	backButtonDetails->hide();
	addRatingButton->show();
	enterButtonAddRating->hide();
	inputAddRating->hide();
	inputRate->hide();
	enterButtonDetails->hide();
	inputDetails->hide();
	movieDetailsButton->show();
	system("cls");
	_movieBase.setSortType(1);
	_movieBase.sortMovies();
	_movieBase.baseInfo();
}
void MovieEngine::cSort3(Fl_Widget *, void *v)
{
	((MovieEngine*)v)->iSort3();
}
inline void MovieEngine::iSort3()
{
	backButtonDetails->hide();
	addRatingButton->show();
	enterButtonAddRating->hide();
	inputAddRating->hide();
	inputRate->hide();
	enterButtonDetails->hide();
	inputDetails->hide();
	movieDetailsButton->show();
	system("cls");
	_movieBase.setSortType(2);
	_movieBase.sortMovies();
	_movieBase.baseInfo();
}
void MovieEngine::cSort1Y(Fl_Widget *, void *v)
{
	((MovieEngine*)v)->iSort1Y();
}
inline void MovieEngine::iSort1Y()
{
	backButtonDetails->hide();
	enterButtonDetails->hide();
	inputDetails->hide();
	movieDetailsButton->show();
	system("cls");
	_movieBase.setSortType(0);
	_movieBase.sortMovies();
	_movieBase.ratedMovies();
}
void MovieEngine::cSort2Y(Fl_Widget *, void *v)
{
	((MovieEngine*)v)->iSort2Y();
}
inline void MovieEngine::iSort2Y()
{
	backButtonDetails->hide();
	enterButtonDetails->hide();
	inputDetails->hide();
	movieDetailsButton->show();
	system("cls");
	_movieBase.setSortType(1);
	_movieBase.sortMovies();
	_movieBase.ratedMovies();
}
void MovieEngine::cSort3Y(Fl_Widget *, void *v)
{
	((MovieEngine*)v)->iSort3Y();
}
inline void MovieEngine::iSort3Y()
{
	backButtonDetails->hide();
	enterButtonDetails->hide();
	inputDetails->hide();
	movieDetailsButton->show();
	system("cls");
	_movieBase.setSortType(3);
	_movieBase.sortMovies();
	_movieBase.ratedMovies();
}
void MovieEngine::cEnterButtonAdd(Fl_Widget *, void *v)
{
	((MovieEngine*)v)->iEnterButtonAdd();
}
inline void MovieEngine::iEnterButtonAdd()
{
	const char* x = inputAdd->value();
	string y = x;
	if (y != "")
	{
		_movieBase.loadXmlMovie(y);
		_movieBase.saveXML();
		_movieBase.loadXml();
	}
	iAllMovies();
}
void MovieEngine::cEnterButtonAddRating(Fl_Widget *, void *v)
{
	((MovieEngine*)v)->iEnterButtonAddRating();
}
inline void MovieEngine::iEnterButtonAddRating()
{
	const char* z = inputRate->value();
	const char* x = inputAddRating->value();
	int nr = atoi(x);
	int r = atoi(z);
	if (nr != 0 && r !=0)
	{
		_movieBase.addRating((nr - 1), r);
		_movieBase.saveXML();
		iYourMovies();
	}
	else
	{
		iAllMovies();
	}
}
void MovieEngine::cMovieDetails(Fl_Widget *, void *v)
{
	((MovieEngine*)v)->iMovieDetails();
}
inline void MovieEngine::iMovieDetails()
{
	Buttons(true, true, false, false, false, false, false, false, false, false, false, false, false, true, true, false, true, false, true, true, false);
	backButton->callback(cStart, this);
	sortButton1->callback(cSort1, this);
	sortButton2->callback(cSort2, this);
	sortButton3->callback(cSort3, this);
	enterButtonDetails->callback(cEnterButtonDetails, this);
	addRatingButton->callback(cAddRating, this);
}
void MovieEngine::cEnterButtonDetails(Fl_Widget *, void *v)
{
	((MovieEngine*)v)->iEnterButtonDetails();
}
inline void MovieEngine::iEnterButtonDetails()
{
	const char* x = inputDetails->value();
	int y = atoi(x)-1;
	system("cls");
	_movieBase.movieInfo(y);
	enterButtonDetails->hide();
	inputDetails->hide();
	backButtonDetails->show();
	backButtonDetails->callback(cAllMovies, this);
}
void MovieEngine::cEnterButtonDetailsY(Fl_Widget *, void *v)
{
	((MovieEngine*)v)->iEnterButtonDetailsY();
}
inline void MovieEngine::iEnterButtonDetailsY()
{
	const char* x = inputDetails->value();
	int y = atoi(x);
	if (y != 0)
	{
		system("cls");
		_movieBase.ratedMovieInfo(y);
	}
	enterButtonDetails->hide();
	inputDetails->hide();
	backButtonDetails->show();
	backButtonDetails->callback(cYourMovies,this);
}
void MovieEngine::cMovieDetailsY(Fl_Widget *, void *v)
{
	((MovieEngine*)v)->iMovieDetailsY();
}
inline void MovieEngine::iMovieDetailsY()
{
	Buttons(true, true, false, false, false, false, false, false, false, false, false, false, false, true, true, true, false, false, false, true, false);
	backButton->callback(cStart, this);
	sortButton1->callback(cSort1Y, this);
	sortButton2->callback(cSort2Y, this);
	sortButton3->callback(cSort3Y, this);
	enterButtonDetails->callback(cEnterButtonDetailsY, this);
}
void MovieEngine::cAddRating(Fl_Widget *, void *v)
{
	((MovieEngine*)v)->iAddRating();
}
inline void MovieEngine::iAddRating()
{
	Buttons(false, false, false, false, false, true, true, true, false, false, false, false, false, true, true, false, true, true, false, true, false);
	backButton->callback(cStart, this);
	sortButton1->callback(cSort1, this);
	sortButton2->callback(cSort2, this);
	sortButton3->callback(cSort3, this);
	enterButtonAddRating->callback(cEnterButtonAddRating, this);
}
void MovieEngine::cExit(Fl_Widget *, void *v)
{
	exit(0);
}
void MovieEngine::buttonParam(Fl_Button * x,bool hide)
{
	x->labelsize(23);
	x->color(FL_GRAY);
	x->labelfont(FL_TIMES_BOLD_ITALIC);
	x->box(FL_SHADOW_BOX);
	if (hide == true)
		x->hide();
	else
		x->show();
}
void MovieEngine::inputButtonsParam(Fl_Button * x, bool hide)
{
	x->labelsize(20);
	x->color(FL_GRAY);
	x->labelfont(FL_TIMES_BOLD_ITALIC);
	x->box(FL_SHADOW_BOX);
	if (hide == true)
		x->hide();
	else
		x->show();
}
void MovieEngine::inputParam(Fl_Input* x, bool hide)
{
	x->labelsize(20);
	x->color(FL_GRAY);
	x->labelfont(FL_TIMES_BOLD_ITALIC);
	x->box(FL_SHADOW_BOX);
	if (hide == true)
		x->hide();
	else
		x->show();
}
MovieEngine *MovieEngine::getInstance()
{
	if (instance == 0)
		instance = new MovieEngine();
	else
		return instance;
}
int MovieEngine::makeWindow()
{
	window->color(FL_WHITE);
	inputButtonsParam(backButtonDetails, true);
	inputButtonsParam(enterButtonAddRating, true);
	inputParam(inputAddRating, true);
	inputParam(inputRate, true);
	inputButtonsParam(enterButtonDetails, true);
	inputButtonsParam(enterButtonAdd, true);
	inputParam(inputDetails, true);
	inputParam(inputAdd, true);
	buttonParam(startButton,false);
	buttonParam(databaseButton, true);
	buttonParam(allMoviesButton, true);
	buttonParam(addMovieButton, true);
	buttonParam(sortButton1, true);
	buttonParam(sortButton2, true);
	buttonParam(sortButton3, true );
	buttonParam(sortButton4, true);
	buttonParam(movieDetailsButton, true);
	buttonParam(addRatingButton, true);
	buttonParam(yourMoviesButton,true);
	buttonParam(backButton, true);
	buttonParam(exitButton,false);
	startButton->callback(cStart, this);
	databaseButton->callback(cDatabase, this);
	yourMoviesButton->callback(cYourMovies, this);
	exitButton->callback(cExit, this);
	window->redraw();
	window->show();
	return Fl::run();
}
void MovieEngine::start()
{
	_movieBase.loadXml();
	while (true)
	{
		makeWindow();
	}
}

