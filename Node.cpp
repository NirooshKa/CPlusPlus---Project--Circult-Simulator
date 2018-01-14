#include "Node.h"
#include <iostream>
using namespace std;

 Node::Node (int const nodeID, Node* next) : nodeID(nodeID), next(next)
{
     voltage = 0; 
     voltageSet = false;
   
}

 Node::~Node ()
 {
   /*
    resistorList.deleteResistor("all");
    delete next;
    */
    
     
 }

 int const Node::getID ()
 {
     
     return nodeID;
     
     
 } 
 
 Node* Node::getNext ()
 {
     return next;
     
     
 }
 
 void Node:: setNext (Node* next)
 {
     this->next = next; 
     
     
 }

 bool Node::insertResistor(string name, int endPoint1, int endPoint2, double resistance)
 {
    return resistorList.insertResistor(name, endPoint1, endPoint2, NULL, resistance);
      
    
    
    
 }
 
 bool Node::deleteResistor (string name)
 {
     if (resistorList.deleteResistor(name));
     {
         return true;
         
     }
     
         return false;
         
     
     
 }
 
 
 void Node::printResistorList() 
 {
     cout << "Connections at node " << nodeID << ": " << resistorList.getResCount() << " resistor(s)" << endl;
     resistorList.printList();
     
 }
 
 ResistorList Node::getResistorList()
 {
     
     return resistorList;
     
     
 }
 
 void Node::setV (double voltagee)
 {
     
     voltageSet = true;
     this->voltage = voltagee; 
     
     
 }
 
 void Node:: setVoltage (double voltagee) //This is only used for solve
 {
     
     this->voltage = voltagee;
     
 }
 
 
 double Node:: getVoltage () 
 
 {
     
         return voltage; 
     
 }
 
 void Node::unsetV()
 {
     voltageSet = false;
     voltage = 0;
     
     
 }
 
    bool Node::isVoltageSet()
 {
     
     return voltageSet; 
     
 }
    
    
    /*string Node:: getName ()
    {
        return resistorList.getName();
    }*/