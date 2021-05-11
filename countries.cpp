#include"countries.h"
#include"country.h"
#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

void Countries::set_size_v(int s) { size_v = s; }

void Countries::set_countries(string filename){
	ifstream inf;
	inf.open(filename);
	if (!inf.is_open()){
		cout << "Error: Unable to open file. ";
		cout << "Action aborted." << endl;
		exit(1);
	} 
	else {
		string line;
		getline(inf, line);

		while (getline(inf, line)){
			Country country(line);
			countries.push_back(country);
		}
		inf.close();
	}

	set_size_v(countries.size());
}

int Countries::get_size_v() { return size_v; }
vector<Country> Countries::get_countries() { return countries; }

void Countries::set_codevalpairs(int sortby){
	switch(sortby) {
		//new cases
		case 1:
			for (int i=0; i<get_size_v(); i++){
				codevalpairs.push_back(make_pair(
					get_countries()[i].get_nc(),get_countries()[i].get_code()));
			}
			break;

		//new deaths
		case 2:
			for (int i=0; i<get_size_v(); i++){
				codevalpairs.push_back(make_pair(
					get_countries()[i].get_nd(),get_countries()[i].get_code()));
			}
			break;

		//new recovered
		case 3:
			for (int i=0; i<get_size_v(); i++){
				codevalpairs.push_back(make_pair(
					get_countries()[i].get_nr(),get_countries()[i].get_code()));
			}
			break;

		//total cases
		case 4:
			for (int i=0; i<get_size_v(); i++){
				codevalpairs.push_back(make_pair(
					get_countries()[i].get_tc(),get_countries()[i].get_code()));
			}
			break;

		//total deaths
		case 5:
			for (int i=0; i<get_size_v(); i++){
				codevalpairs.push_back(make_pair(
					get_countries()[i].get_td(),get_countries()[i].get_code()));
			}
			break;

		//total recovered
		case 6:
			for (int i=0; i<get_size_v(); i++){
				codevalpairs.push_back(make_pair(
					get_countries()[i].get_tr(),get_countries()[i].get_code()));
			}
			break;
	}
}

void Countries::set_codevalpairs_again(
	std::vector<std::pair<int,std::string>> cvp) { codevalpairs = cvp; }

vector<pair<int, string>> Countries::get_codevalpairs(){ return codevalpairs; }

void Countries::set_topten(int order){

	vector<pair<int,string>> tmp = get_codevalpairs();
	sort(tmp.begin(),tmp.end());
	set_codevalpairs_again(tmp);

	//order ascending
	if (order==1) {
		for (int i=0; i<10; i++){
			topten.push_back(make_pair(
				get_codevalpairs()[i].second,get_codevalpairs()[i].first));
		}
	}
	//order descending
	else {
		for (int j=get_size_v()-1; j>get_size_v()-11; j--){
			topten.push_back(make_pair(
				get_codevalpairs()[j].second,get_codevalpairs()[j].first));
		}
	}
}

vector<pair<string, int>> Countries::get_topten() { return topten; }

Countries::Countries(string filename, int sortby, int order) {

	set_countries(filename);
	set_codevalpairs(sortby);
	set_topten(order);
}

Countries::~Countries(){
}
