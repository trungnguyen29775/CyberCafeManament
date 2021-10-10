#ifndef BASE_FUNC_H
#define BASE_FUNC_H

#include<iostream>
#include<windows.h>
#include<vector>
#include<string>
#include <fstream>
#include <ctime>
#include "md5.h"


using namespace std;

static std::string MEMBER_FILE_PATH = "data_member.txt";
static std::string COMP_FILE_PATH = "data_comp.txt";
static std::string BOOKING_FILE_PATH = "data_login.txt";

static double CHARGE_RATE = 123;
static const string AdminUserName = "admin";
static const string AdminPassword = "admin";

static const vector<string> lineMenu = {
	"--------------MENU-------------",
	"|                             |",
	"|                             |",
	"|                             |",
	"|                             |",
	"|       1.Master Entry        |",
	"|       2.Cafe Management     |",
	"|       3.Exit                |",
	"|                             |",
	"|                             |",
	"|                             |",
	"|                             |",
	"-------------------------------",
};

static const vector<string> lineMasterEntry = {
	"--------MENU/MASTERENTRY-------",
	"|                             |",
	"|                             |",
	"|                             |",
	"|                             |",
	"|       1.Member Entry        |",
	"|       2.Computer Entry      |",
	"|       3.Return              |",
	"|                             |",
	"|                             |",
	"|                             |",
	"|                             |",
	"|                             |",
	"-------------------------------",
};
static const vector<string> lineMemberEntry = {
	"-MENU/MASTERENTRY/MEMBERENTRY--",
	"|                             |",
	"|                             |",
	"|                             |",
	"|       1.Add New Member      |",
	"|       2.Show Member         |",
	"|       3.Update Record       |",
	"|       4.Delete Record       |",
	"|       5.Search Record       |",
	"|       6.Return              |",
	"|                             |",
	"|                             |",
	"|                             |",
	"-------------------------------",
};

static const vector<string> lineComputerEntry = {
	"-MENU/MASTERENTRY/COMPUTERENTRY-",
	"|                             |",
	"|                             |",
	"|                             |",
	"|       1.Add New Computer    |",
	"|       2.Show Computer       |",
	"|       3.Update Record       |",
	"|       4.Delete Record       |",
	"|       5.Search Record       |",
	"|       6.Return              |",
	"|                             |",
	"|                             |",
	"|                             |",
	"-------------------------------",
};
static const vector<string> lineCafeManagement = {
	"------MENU/CAFEMANAGEMENT------",
	"|                             |",
	"|                             |",
	"|                             |",
	"|                             |",
	"|        1.Booking            |",
	"|        2.Charges            |",
	"|        3.Renewal            |",
	"|        4.Return             |",
	"|                             |",
	"|                             |",
	"|                             |",
	"|                             |",
	"-------------------------------",
};
static const vector<string> lineBooking = {
	"--MENU/CAFEMANAGEMENT/BOOKING--",
	"|                             |",
	"|                             |",
	"|                             |",
	"|   1.Member Login            |",
	"|   2.Non-Member Login        |",
	"|   3.Logout                  |",
	"|   4.Return                  |",
	"|                             |",
	"|                             |",
	"|                             |",
	"|                             |",
	"|                             |",
	"-------------------------------",
};

static const vector<string> lineCharges = {
	"--MENU/CAFEMANAGEMENT/CHARGES--",
	"|                             |",
	"|                             |",
	"|                             |",
	"|                             |",
	"|        1.Take Charges       |",
	"|        2.Show Charges       |",
	"|        3.Return             |",
	"|                             |",
	"|                             |",
	"|                             |",
	"|                             |",
	"|                             |",
	"-------------------------------",
};

void DefineColorScreen();

#endif