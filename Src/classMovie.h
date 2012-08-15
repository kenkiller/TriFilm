#ifndef DEF_CLASS_MOVIE
#define DEF_CLASS_Movie
#include <string>
 

class movie
{
    public:
	
	//Les constructeurs
	movie(std::string name, std::string director, int year , double IMDBrating);
	movie(std::string IMDB_id);
	movie

	//Le destructeur
	//~movie();

	// Les accesseurs
	std::string getName() const;
	std::string getDirector() const;
	int getYear() const;
	double getIMDBrating() const;
	
	
	//Les fonctions membres
	
	//Les attributs
		private:

		std::string m_name;
		std::string m_director
    	int m_year;
		double m_IMDBrating;
		
	
}; //END_CLASS_MOVIE




#endif 
