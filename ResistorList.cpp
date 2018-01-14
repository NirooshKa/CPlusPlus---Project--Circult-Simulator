#include "ResistorList.h"
#include <iostream>
#include <cstdlib>
#include <string>


using namespace std;

ResistorList::ResistorList() : head(NULL) {

    resCount = 0;

}

ResistorList::~ResistorList() {
  /* 
    while (head != NULL)
    {
    Resistor* resis;
        resis = head;
        head = resis->getNext();
        resis->setNext(NULL);
        delete resis;
        
    }
    resCount = 0;
    */
}

bool ResistorList::insertResistor(string name, int endpoint1, int endpoint2, Resistor* next, double resistance) {

    Resistor* newRes = new Resistor(name, endpoint1, endpoint2, NULL, resistance);

    Resistor* temp = head;

    if (head == NULL) {
        head = newRes; //If list is empty 


    }


    else {

        while (temp->getNext() != NULL) {
            if (temp->getName() == newRes->getName()) { //Finds duplicate resistor name
                delete newRes;
                return false;


            }

            temp = temp->getNext();

        }


        if (temp->getName() == newRes->getName()) { // Another check
            delete newRes;
            return false;
        }


        temp->setNext(newRes);


    }

    resCount++;
    return true;

}

void ResistorList::printList() {

  

    Resistor* temp = head;

    
    if (head == NULL) {

        cout << "Empty list" << endl;

    }
    
    else {


        while (temp != NULL) {

           
            
          
            
            cout.width(2);
            cout << " " ;
            cout << left << temp->getName();
            cout.width(25);

            cout << right << fixed << temp->getResistance() << " Ohms " << temp->getEndPoint1() << " -> " << temp->getEndPoint2() << endl;



            temp = temp ->getNext();
            
        }

    }




}

bool ResistorList::deleteResistor(string name) {




    if (name == "all") //This is when the person types in deleteR all
    {
        Resistor* temp1 = head;


        if (head == NULL) {
            return false;

        }
        else {
            while (temp1 != NULL) {
                temp1 = head ->getNext();
                delete head;
                head = temp1;


            }
        }

      
        return true;
    }

    else { // This is when the person doesn't type in deleteR all 

        if (head == NULL) //This is when the list is empty
        {
            return false;

        }

        Resistor* forwardPoint = head;
        Resistor* behindPoint = NULL;



        while (forwardPoint != NULL) {
            if ((forwardPoint->getName()) == name)break;

            behindPoint = forwardPoint;

            forwardPoint = forwardPoint->getNext();


        }

        if (forwardPoint == NULL) {
            return false;

        }

        if (forwardPoint == head) {
            head = head->getNext();
            delete forwardPoint;
            resCount--;


            return true;

        }


        behindPoint->setNext(forwardPoint->getNext());
        delete forwardPoint;
        resCount--;
        return true;

    }




}

void ResistorList::printResistor(string name)
 {
    Resistor* temp = head;

    if (head == NULL) {
        cout << "List is empty" << endl;
    }
    else {
        while (temp != NULL) {
            if (temp->getName() == name) {
                cout << "fOUND IT" << endl;

            }

            temp = temp->getNext();

        }


    }


}

Resistor* ResistorList::getHead() {

    return head;



}

bool ResistorList::getResName(string name) {
    Resistor* temp = head;

    if (temp->getNext() == NULL) {
        if (temp->getName() == name) {
            return true;

        }
        else {
            return false;

        }

    }

    while (temp != NULL) {
        if (temp->getName() == name) {
            return true;

        }
        temp -> getName();
        temp = temp->getNext();


    }
    return false;

}

double ResistorList::modifyRes(double resistance, string name)
 {

    Resistor* temp = head;
  double oldRes = 0;
    if (head == NULL) {
        cout << "List is empty" << endl;
    }
    else {
        while (temp != NULL) {
            if (temp->getName() == name) {
              
                oldRes = temp->getResistance();
                temp->setResistance(resistance);
                
               
                
            }

            temp = temp->getNext();

        }


    }

 return oldRes;
}

void ResistorList::findAndPrint(string name) {

    Resistor* temp = head;
    cout << "Print: " << endl;
    if (head == NULL) {
        cout << "Resistor doesn't exist." << endl;
    }
    else {
        while (temp != NULL) {
            if (temp->getName() == name) {
                cout.width(20);
                cout << left << temp->getName();
                cout << " ";
                cout.width(8);

                   
                cout << right << fixed << temp->getResistance() << " Ohms " << temp->getEndPoint1() << " -> " << temp->getEndPoint2() << endl;


        
                

            }

            temp = temp->getNext();

        }


    }


}

int ResistorList::getResCount() {
    return this->resCount;



}