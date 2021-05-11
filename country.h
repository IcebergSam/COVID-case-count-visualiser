#ifndef COUNTRY_H
#define COUNTRY_H
#include<string>

class Country{
		std::string name;
		std::string code;
		int nc,nd,nr,tc,td,tr;

	public:
		void set_name(std::string s);
		void set_code(std::string s);
		void set_nc(int n);
		void set_nd(int n);
		void set_nr(int n);
		void set_tc(int n);
		void set_td(int n);
		void set_tr(int n);

		Country(std::string line);
		~Country();

		std::string get_name();
		std::string get_code();
		int get_nc();
		int get_nd();
		int get_nr();
		int get_tc();
		int get_td();
		int get_tr();
};
#endif