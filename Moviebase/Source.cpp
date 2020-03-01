#include "MovieEngine.h" 

int main()
{
	MovieEngine*m = MovieEngine::getInstance();
	MovieEngine::getInstance()->start();
	return 0;
}