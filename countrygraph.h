#ifndef COUNTRYGRAPH_H
#define COUNTRYGRAPH_H
#include<string>
#include<vector>

class CountryGraph{
	std::string title;
	std::string legend;
	int unit;
	std::string country_graph;

	public:
		void set_title(std::string t);
		void set_legend(std::string lg);
		void set_unit(std::vector<std::pair<std::string,int>> tt);

		std::string get_title();
		std::string get_legend();
		int get_unit();

		void set_graph(std::vector<std::pair<std::string,int>> tt);
		
		CountryGraph(std::string filename, int sortby, int order);
		~CountryGraph();

		std::string get_graph();
};
#endif
