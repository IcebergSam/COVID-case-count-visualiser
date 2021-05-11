#ifndef COUNTRIES_H
#define COUNTRIES_H
#include<vector>
#include<string>
#include"country.h"

class Countries{
	int size_v;
	std::vector<Country> countries;
	
	std::vector<std::pair<int, std::string>> codevalpairs;
	std::vector<std::pair<std::string, int>> topten;

	public:
		void set_size_v(int s);
		void set_countries(std::string filename);

		int get_size_v();
		std::vector<Country> get_countries();

		void set_codevalpairs(int sortby);
		void set_codevalpairs_again(std::vector<std::pair<int,std::string>> cvp);
		std::vector<std::pair<int, std::string>> get_codevalpairs();

		void set_topten(int order);
		std::vector<std::pair<std::string, int>> get_topten();

		Countries(std::string filename, int sortby, int order);
		~Countries();
};
#endif