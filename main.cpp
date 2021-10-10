#include "BaseFunc.h"
#include "Navigator.h"


void InitializeMember()
{
	std::ifstream fileInput(MEMBER_FILE_PATH);

	if (fileInput.fail())
	{
		std::cout << "Failed to initialize!" << std::endl;
	}
	else
	{
		MemberEntry memb;
		char temp[255];
		fileInput.getline(temp, 255);
		memb.id = temp;
		while (memb.id != "") {
			memb.id = temp;
			fileInput.getline(temp, 255);
			memb.name = temp;
			fileInput.getline(temp, 255);
			memb.address = temp;
			fileInput.getline(temp, 255);
			memb.phone = temp;
			fileInput.getline(temp, 255);
			memb.email = temp;
			fileInput.getline(temp, 255);
			memb.username = temp;
			fileInput.getline(temp, 255);
			memb.password = temp;
			MEMBER_DATA.push_back(memb);
			fileInput.getline(temp, 255);
			memb.id = temp;
		}
	}
	fileInput.close();
}

void InitializeComputer()
{
	std::ifstream fileInput(COMP_FILE_PATH);

	if (fileInput.fail())
	{
		std::cout << "Failed to initialize!" << std::endl;
	}
	else
	{
		ComputerEntry comp;
		char temp[255];
		fileInput.getline(temp, 255);
		comp.id = temp;
		while (comp.id != "")
		{
			fileInput.getline(temp, 255);
			comp.typeCPU = temp;
			fileInput.getline(temp, 255);
			comp.memory = temp;

			COMP_DATA.push_back(comp);
			fileInput.getline(temp, 255);
			comp.id = temp;
		}
	}
	fileInput.close();
}


void InitializeBooking()
{
	std::ifstream fileInput(BOOKING_FILE_PATH);

	if (fileInput.fail())
	{
		std::cout << "Failed to initialize!" << std::endl;
	}
	else
	{

		Booking book;
		char temp[255];
		fileInput.getline(temp, 255);
		book.memId = temp;

		while (book.memId != "")
		{
			fileInput.getline(temp, 255);
			book.compId = temp;

			fileInput >> book.timerIn.tm_hour;
			fileInput >> book.timerIn.tm_min;
			fileInput >> book.timerIn.tm_sec;
			fileInput >> book.timerIn.tm_year;
			fileInput >> book.timerIn.tm_mon;
			fileInput >> book.timerIn.tm_mday;

			fileInput >> book.timerOut.tm_hour;
			fileInput >> book.timerOut.tm_min;
			fileInput >> book.timerOut.tm_sec;
			fileInput >> book.timerOut.tm_year;
			fileInput >> book.timerOut.tm_mon;
			fileInput >> book.timerOut.tm_mday;
			fileInput.getline(temp, 255);

			mktime(&book.timerIn);
			mktime(&book.timerOut);

			BOOKING_DATA.push_back(book);

			fileInput.getline(temp, 255);
			book.memId = temp;


		}
	}
	fileInput.close();
}



int main()
{
	DefineColorScreen();
	InitializeMember();
	InitializeComputer();
	InitializeBooking();
	login();
	StartMenu();
	return 0;
}