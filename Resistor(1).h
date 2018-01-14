/* 
 * File:   Resistor.h
 * Author: kammulaa
 *
 * Created on October 14, 2016, 1:33 PM
 */

#ifndef RESISTOR_H
#define	RESISTOR_H
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

class Resistor
{
private:

   string name; // C++ string holding the label
   int endpointNodeIDs[2]; // IDs of nodes it attaches to
   Resistor* next;
   double resistance;

public:
    
    
    Resistor(string name, int endPoint1, int endPoint2, Resistor* next, double resistance);
    ~Resistor();
    
    string getName () const; 
    int getEndPoint1 ();
    int getEndPoint2 ();
    Resistor* getNext ();
    
    void setNext (Resistor* next);
    void setName  (string name);
    double getResistance ();
    void setResistance (double resistance);
    
    

};



#endif	/* RESISTOR_H */



