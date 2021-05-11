#include"country.h"
#include<string>
#include<vector>
using namespace std;

void Country::set_name(string s) { name = s; }
void Country::set_code(string s) { code = s; }
void Country::set_nc(int n) { nc = n; }
void Country::set_nd(int n) { nd = n; }
void Country::set_nr(int n) { nr = n; }
void Country::set_tc(int n) { tc = n; }
void Country::set_td(int n) { td = n; }
void Country::set_tr(int n) { tr = n; }

string Country::get_name() { return name; }
string Country::get_code() { return code; }
int Country::get_nc() { return nc; }
int Country::get_nd() { return nd; }
int Country::get_nr() { return nr; }
int Country::get_tc() { return tc; }
int Country::get_td() { return td; }
int Country::get_tr() { return tr; }

Country::Country(string line){
	line.append("\n");

	string name = "";
	string code = "";
 	
	char* ch = &line[0];
		
	//getname
	while (*ch == '"' | *ch == ',') { ch++; }
	while (*ch != '"') { name.push_back(*ch); ch++; }
	set_name(name);

	//getcode
	while (*ch == '"' | *ch == ',') { ch++; }
	while (*ch != '"') { code.push_back(*ch); ch++; }
	set_code(code);
	
	//skipdate
	while (*ch == '"' | *ch == ',') { ch++; }
	while (*ch != '"') { ch++; }
	
	string tmp = "";

	//getnewconfirmed
	while (*ch == '"' | *ch == ',') { ch++; }
	while (*ch != ',') { tmp.push_back(*ch); ch++; }
	set_nc(stoi(tmp));

	tmp = "";

	//getnewdeaths
	while (*ch == ',') { ch++; }
	while (*ch != ',') { tmp.push_back(*ch); ch++; }
	set_nd(stoi(tmp));
	
	tmp = "";

	//getnewrecovered
	while (*ch == ',') { ch++; }
	while (*ch != ',') { tmp.push_back(*ch); ch++; }
	set_nr(stoi(tmp));

	tmp = "";

	//skippremium
	while (*ch == '"' | *ch == ',') { ch++; }
	while (*ch != '"') { ch++; }

	//skipslug
	while (*ch == '"' | *ch == ',') { ch++; }
	while (*ch != '"') { ch++; }
	
	//gettotalconfirmed
	while (*ch == '"' | *ch == ',') { ch++; }
	while (*ch != ',') { tmp.push_back(*ch); ch++; }
	set_tc(stoi(tmp));

	tmp = "";

	//gettotaldeaths
	while (*ch == ',') { ch++; }
	while (*ch != ',') { tmp.push_back(*ch); ch++; }
	set_td(stoi(tmp));

	tmp = "";

	//gettotalrecovered
	while (*ch == ',') { ch++; }
	while (*ch != '\n') { tmp.push_back(*ch); ch++; }
	set_tr(stoi(tmp));
}

Country::~Country(){
}
