#pragma once

#include <string>
#include <iostream>
using namespace std;

class Appliance {
private:
	string name;
	double voltage;
	double current;
	double power;
public:
	Appliance();
	
	Appliance(double v, double c, double p);
	

	void set_v(double v);
	
	void set_c(double c);
	
	void set_p(double p);
	

	double get_v();
	
	double get_c();
	
	double get_p();
	

	double getWatts();
	
};