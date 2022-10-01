//Homework 10

/*
 *  Filename:           main.cpp
 * 
 *  Purpose:            The purpose of this program is to gouge innocent
 *                      civilians and low income residents out of all their
 *                      money, forcing them to spend more than they need to
 *                      in order to survive. This money will then skip 3 tiers
 *                      of management and go straight to the owner's pocket.
 *                      The rich get richer, and the poor get poorer. It's 
 *                      practically win-win. This program will determine
 *                      how many apartment units should be rented and the
 *                      price that they should be rented at in order to
 *                      maximize profit. The program will prompt the user for 
 *                      the number of apartments, the rent for each apartment,
 *                      the rent increase that leads to a vacant unit, and the 
 *                      maintenance costs for each rented apartment. The 
 *                      program will then output the determined rent that 
 *                      will maximize the profit, the maximum number of units 
 *                      to be rented, and the maximum profit. 
 * 
 * 
 *  Author:             Zachary Charles Stewart
 *  Student ID:         105903414
 *  Date:               1/25/2017 20:12 PST
 */

#include<iostream>
#include<iomanip>       //get_money/put_money function
#include<cstdlib>

using namespace std;

int main(int argc, char** argv)
{
    
    //Declare variables
    int apt_num, ideal_num;
    double apt_upRent, apt_maintenance; 
    double apt_profit;
    long double ideal_rent = 0; 
    long double apt_rent = 0;
    long double ideal_profit = 0;
    char junk;
    
    //Imbue correct local
    cout.imbue(locale("en_US.UTF-8"));
   
    //Prompt user for input
    cout << "Enter the number of apartments: " << endl;
    cin >> apt_num;
    cout << "Enter the rent for each apartment: " << endl;
    cin >> junk >> apt_rent;
    cout << "Enter the rent increase that leads to a vacant unit: " << endl;
    cin >> junk >> apt_upRent;
    cout << "Enter the maintenance costs for each rented apartment: " << endl;
    cin >> junk >> apt_maintenance;
    cout << endl;
    
    //While loop to calculate each rent
    while(apt_num > 0)
    {
        apt_profit = (apt_num * apt_rent) - (apt_num * apt_maintenance);
        
        //Test profit to see if it is max value
        if(apt_profit > ideal_profit)
        {
            ideal_profit = apt_profit;
            ideal_num = apt_num;
            ideal_rent = apt_rent;
        }
        //Decrease apt
        apt_num--;
        
        //Increase rent
        apt_rent += apt_upRent;
    }
    
    //Convert money to be in pennies format for put_money()
    ideal_rent *= 100;
    ideal_profit *= 100;
    
    //Output data to user
    cout << "The monthly rent should be set to " 
         << put_money(ideal_rent, false) << "." << endl;
    cout << "The maximum number of units to be rented is: "
         << ideal_num << "." << endl;
    cout << "The maximum profit is "
         << put_money(ideal_profit, false) << endl;
    
    exit(EXIT_SUCCESS);
}
