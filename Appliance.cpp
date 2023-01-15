#include <iostream>
#include "Appliance.h"
using namespace std;

Appliance::Appliance()
{
	voltage = 0.0;
	current = 0.0;
	power = 0.0;
}
Appliance::Appliance(double v, double c, double p)
{
	voltage = v;
	current = c;
	power = p;
}

void Appliance::set_v(double v)
{
	voltage = v;
}
void Appliance::set_c(double c)
{
	current = c;
}
void Appliance::set_p(double p)
{
	power = p;
}

double Appliance::get_v()
{
	return voltage;
}
double Appliance::get_c()
{
	return current;
}
double Appliance::get_p()
{
	return power;
}

double Appliance::getWatts()
{
	power = voltage * current;
	return power;
}