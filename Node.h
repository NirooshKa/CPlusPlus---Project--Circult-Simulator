/* 
 * File:   Node.h
 * Author: kammulaa
 *
 * Created on October 14, 2016, 1:34 PM
 */

#ifndef NODE_H
#define	NODE_H
#include "ResistorList.h"
#include <string>


class Node
{
private:
    
    int const nodeID;
    ResistorList resistorList; 
    Node* next;
    double voltage;
    bool voltageSet;

public:
   Node(int const nodeID, Node* next); 
   ~Node();

   int const getID ();
   Node* getNext ();
   void setNext (Node* next);
   bool insertResistor (string name, int endPoint1, int endPoint2, double resistance);
   void printResistorList ();
   ResistorList getResistorList ();
   bool deleteResistor (string name);
   void setV (double voltagee);
   void unsetV ();
   bool isVSet ();
   double getVoltage ();
   bool isVoltageSet ();
   void setVoltageBool ();
   string getName ();
   void setVoltage (double voltagee);
   
   
};




#endif	/* NODE_H */

