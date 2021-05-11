#include"countrygraph.h"
#include"countries.h"
#include<string>
#include<vector>
#include<cmath>
using namespace std;

void CountryGraph::set_title(string t) { title = t; }
void CountryGraph::set_legend(string lg) { legend = lg; }

void CountryGraph::set_unit(vector<pair<string,int>> tt){
	int x = tt[0].second, y = tt[9].second;
	int domain = max(x,y);
	unit = floor(domain / 70); 
	if (unit < 1) unit = 1;
}

string CountryGraph::get_title() { return title; }
string CountryGraph::get_legend() { return legend; }
int CountryGraph::get_unit() { return unit; }

void CountryGraph::set_graph(vector<pair<string,int>> tt){
	string lines[23];
	lines[0] = "  \n\t\t" + get_title() + '\n';

	for(int i=1; i<=19; i+=2) {
		lines[i] = "      |  \n";
	}

	int nums = 0;
	for(int i=2,j=0; i<=20; i+=2,j++){
		nums = floor(tt[j].second / get_unit());
	
		string symbol = "";
		for(int k=0; k<nums; k++){
			symbol += "#";
		}

		lines[i] = "  " + tt[j].first + "  |  " + symbol;
		lines[i] += " (" + to_string(tt[j].second) + ")\n";
	}

	string s = "";
	for(int i=0; i<90; i++){
			s += '-';
	}
	lines[21] = s + '\n';
	lines[22] = get_legend() + '\n';

	string stringify = "";
	for(int i=0; i<23; i++){
		stringify += lines[i];
	}

	country_graph = stringify; 
}

string CountryGraph::get_graph(){
	return country_graph;
}

CountryGraph::CountryGraph(string filename, int sortby, int order){
	Countries countries(filename,sortby,order);

	string sorted_by;
	switch(sortby) {
		case 1:
			sorted_by = "New Confirmed Cases";
			break;
		case 2:
			sorted_by = "New Deaths";
			break;
		case 3:
			sorted_by = "New Recovered";
			break;
		case 4:	
			sorted_by = "Total Confirmed Cases";
			break;	
		case 5:
			sorted_by = "Total Deaths";
			break;
		case 6:	
			sorted_by = "Total Recovered";
			break;			
		}

		string ordered_by = "";
		string tail = "";
		if(order == 1) { 
			ordered_by += "Ascending";
			tail = "(Bottom Ten Countries)";
		}
		if(order == 2) { 
			ordered_by += "Descending"; 
			tail = "(Top Ten Countries)";
		}

		string t = sorted_by + " in " + ordered_by + " Order " + tail + '\n';
		set_title(t);

		set_unit(countries.get_topten());

		string lg = " Each # is approx. " + to_string(get_unit()) + " cases" + '\n';
		set_legend(lg);


		set_graph(countries.get_topten());
}

CountryGraph::~CountryGraph(){
}
