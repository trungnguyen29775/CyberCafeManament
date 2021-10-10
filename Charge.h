#ifndef CHARGE_H
#define CHARGE_H

#include "Booking.h"


class Charge
{
public:
    Charge() { ; }
    ~Charge() { ; }

    //service of charge
    void takeCharge();
    void showCharges();

    //function for solving
    void menu();
    void computeCharge(Booking& bookingObject);
};





#endif