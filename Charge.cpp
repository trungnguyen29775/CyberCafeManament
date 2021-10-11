#include "Charge.h"

void Charge::computeCharge(Booking& bookingObject)
{
	cout << "\nMember ID: " << bookingObject.getMemId();
	cout << "\nComputer ID: " << bookingObject.getCompId();
	struct tm timer = bookingObject.getTimerIn(); //create a clone timerIn 
	cout << "\nLogin time: " << asctime(&timer);
	timer = bookingObject.getTimerOut(); //create a clone timerout 
	cout << "Logout time: " << asctime(&timer);
	cout << "\nCharge rate: " << CHARGE_RATE;
	cout << "\nThe charges is: " << CHARGE_RATE * ((bookingObject.computeTime(bookingObject) / 60)) << endl;
}

void Charge::takeCharge()
{
	system("cls");
	cout << "==========Take Charge==========\n";
	cout << "Enter the Id of computer you want to take charge: \n";
	string compId;
	cin >> compId;
	Booking bookin;

	int index = bookin.checkUsedComp(compId);
	if (index >= 0)
	{
		if (bookin.computeTime(BOOKING_DATA.at(index)) <= 0)
		//check the loggin of computer
		{
			cout << "This user is still logging in\n";
		}
		else
		{
			computeCharge(BOOKING_DATA.at(index));

			BOOKING_DATA.erase(BOOKING_DATA.begin() + index);
			BOOKING_DATA.shrink_to_fit();
			std::ofstream fileOutput(BOOKING_FILE_PATH);
			if (fileOutput.fail())
			{
				std::cout << "Cannot open file at " << BOOKING_FILE_PATH << std::endl;
				return;
			}
			else
			{
				fileOutput.clear();
				for (auto& element : BOOKING_DATA)
					element.outp(element, fileOutput);
				cout << "The fee has been taken.\n";

			}
			fileOutput.close();
		}
	}
	else
	{
		cout << "This computer is not in used / does not exist." << endl;

	}
	system("pause");
}

void Charge::showCharges()
{
	system("cls");
	cout << "=========Show Charges=========\n";
	Booking bookin;
	for (auto element : BOOKING_DATA)
	{
		if (bookin.computeTime(element) <= 0)
		{
			cout << "\nMember ID: " << element.getMemId();
			cout << "\nComputer ID: " << element.getCompId();
			cout << "\nThis user is still logging in\n";

		}
		else
		{
			computeCharge(element);
		}
	}
	system("pause");
}


void Charge::menu()
{
	string choice;
	choice[0] = 0;
	int c = int(choice[0]) - 48;
	do
	{
		system("cls");
		for (auto const& line : lineCharges)
		{
			cout << line << '\n';
		}
		do
		{
			cout << "Your choice: ";
			cin >> ws;
			getline(cin, choice);
			c = int(choice[0]) - 48;
			if (c < 1 || c>3 || choice.size()!=1)
			{
				cout << "Invalid number!\n";
			}
		} while (c < 1 || c>3 || choice.size()!=1);


		switch (c)
		{
		case 1:
			takeCharge();
			break;
		case 2:
			showCharges();
			break;
		default:
			break;
		}
	} while (c != 3);
}

