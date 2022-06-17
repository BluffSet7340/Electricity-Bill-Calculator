#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

void menu(); //main menu
void aboutProgram(); //about the program

ofstream output;

int main()
{
	double electrcityConsumed, costPerUnitofElectricity, electricityBill = 0, voltage, current, power;
	int option, deviceNo;
	char response;

	do
	{
		menu();
		cout << "Option: ";
		cin >> option;

		if (cin.fail()) //if the user enters any character for an integer variable
		{
			cin.clear();//clears cin buffer
			cin.ignore();
			cout << "Input only the options listed in the menu.... try again" << endl;
			
			continue;//moves on to the next iteration of the loop
		}

		else if (option > 5)
		{
			cout << "Please enter options within the range... returning to menu" << endl;
			continue;
		}

		else if (option == 1)
		{
			cout << "Enter the units of electricity consumed for the month (in kWh): ";
			cin >> electrcityConsumed;
			cout << "Enter the cost per unit of electrcity consumed (cost/kWh): ";
			cin >> costPerUnitofElectricity;
			electricityBill = electrcityConsumed * costPerUnitofElectricity;
			cout << "Your electricity bill is: " << electricityBill << endl;
		}

		else if (option == 2) 
		{

			if (electricityBill == 0)
			{
				cout << "You haven't calculated the electricity bill yet! Returning to option menu...." << endl;
				continue;
			}

			output.open("Electricity Bill.txt");

			output << "Your electricity bill is " << electricityBill << endl;

			cout << "Your bill has been saved to a file named 'Electricity Bill.txt'" << endl;

		}

		else if (option == 3)
		{
			cout << "First, look for the product label, usually on the back of the device and note down the voltage (in volts) and current (in amps)" << endl;
			cout << "How many devices do you want to enter: ";
			cin >> deviceNo;
			cout << "Do you want to save each device wattage to a file? (Y/N): ";
			cin >> response;

			for (int i = 1; i <= deviceNo; i++)
			{

				cout << "Enter the voltage: ";
				cin >> voltage;
				cout << "Enter the current: ";
				cin >> current;
				power = voltage * current;
				cout << "The wattage (in Watts) of device "<< i << " is = " << power << "W" << endl;

				if (response == 'Y')
				{
					output << "The wattage of device " << i <<  " is = " << power << "W" << endl;
				}
			}
		}

		else if (option == 4)
		{
			aboutProgram();
		}

		
	} while (option != 5);

	output.close();

	return 0;
}

void menu()
{
	cout << "///////////////////////////////////////////////" << endl;
	cout << "Choose any one of the below options: " << endl;
	cout << "1. Calculate electricity bill" << endl;
	cout << "2. Write bill to file and save" << endl;
	cout << "3. Calculate wattage of a device" << endl;
	cout << "4. About program" << endl;
	cout << "5. Exit the program" << endl;
	cout << "///////////////////////////////////////////////" << endl;
}

void aboutProgram()
{
	cout << "This is a simple application that calculates your electric bill. More features will be added soon....." << endl;
}