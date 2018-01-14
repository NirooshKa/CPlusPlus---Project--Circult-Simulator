#include "Resistor.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

Resistor::Resistor(string name, int endPoint1, int endPoint2, Resistor* next, double resistance){
    this->name=name;
    this->endpointNodeIDs[0] = endPoint1;
    this->endpointNodeIDs[1] = endPoint2;
    this->next = next; 
    this->resistance = resistance;
}


string Resistor::getName() const {
    
    return name; 
    
    
    
}


Resistor* Resistor::getNext() {
    
    return next;
    
    
    
} 


void Resistor::setNext(Resistor* next){
    
    this->next = next;
    
    
}

double Resistor :: getResistance ()
{
    return resistance;
    
    
}



Resistor :: ~Resistor () 
{
    /*
     delete next;
      */   
    
}

void Resistor::setResistance(double resistance) {
    
    this->resistance = resistance;
    
    
    
}

int Resistor:: getEndPoint1()
{
    return endpointNodeIDs[0];
    
       
}

int Resistor:: getEndPoint2()
{
    return endpointNodeIDs[1];
    
}