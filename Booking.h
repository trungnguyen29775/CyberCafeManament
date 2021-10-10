//this file is used for declaring class Booking

#ifndef BOOKING_H
#define BOOKING_H


#include "ComputerEntry.h"
#include "MemberEntry.h"
#include "BaseFunc.h"
#pragma warning(disable:4996)
class Booking
{
private:
    string memId, compId;
    struct tm timerIn, timerOut;
public:
    Booking();
    ~Booking() { ; }
    //the Menu need to have in Booking
    void memberLogin();
    void nonMemberLogin();
    void logout();
    
    //some function for convenient in solving

    void menu();
    //void menu to solve the Booking's Menu
    void login();
    //this void use for logging of a user
    void outp(Booking& bookin, ofstream& file); 
    //output in to file to update the changes
    int checkUsedComp(string);
    // check the id computer whether of its exist or was used by other user
    void verify(int& index);
    //check the username and password when logging in
    string getMemId() { return memId; }
    //get memId of class Booking
    friend void InitializeBooking();
    //read the data file and save the data in vector BOOKING_DATA
    double computeTime(Booking&);
    //calculate the time loggin and out
    string getCompId() { return compId; }
    //get compId of class Booking
    tm getTimerIn() { return timerIn; }
    //get timerIn of class Booking
    tm getTimerOut() { return timerOut; }
    //get timerOut of class Booking
    int checkLoginMem(string str);
    //check whether the user logged in
};


extern vector <Booking> BOOKING_DATA;


#endif