#include "NodeList.h"
#include "Node.h"
#include <iostream>
#include <cmath>
#define THRESHOLD_VOLTAGE 0.0001

using namespace std;

NodeList::NodeList() : head(NULL) {


}

NodeList::~NodeList() {

    /*
   while (head != NULL)
       {
         Node* nodes;
        nodes = head;
      head = nodes-> getNext();
     nodes->setNext(NULL);
        delete nodes;
        
    }
*/

}

Node* NodeList::findNode(int const nodeID) {

    Node* temp = head;




    while (temp != NULL) {

        if (temp->getID() == nodeID) {
            return temp;
        }

        temp = temp->getNext();

    }



    return NULL;

}

Node* NodeList::findOrInsert(int const nodeID) {

    Node* temp = head;


    if (head == NULL) {
        head = new Node(nodeID, NULL); //List is empty
        return head;
    } else {

        if (temp->getID() > nodeID) //Add behind head (MEMORY LEAK HERE)
        {

            Node* newNode = new Node(nodeID, NULL);
            newNode->setNext(head);
            head = newNode;
            return head;


        }



        while (temp->getNext() != NULL && temp->getNext()->getID() < nodeID) {


            if (temp->getID() == nodeID) {
                return temp; //Node already exists 

            }


            temp = temp->getNext();

        }



        if (temp->getID() == nodeID) { //Edge case: Duplication not found in the while. 
            return temp;

        }

        if (temp->getNext() != NULL && temp->getNext()->getID() == nodeID) //Edge case: Duplication for any other elements
        {

            return temp->getNext();

        }

        Node* newNode = new Node(nodeID, NULL);



        newNode->setNext(temp->getNext());
        temp->setNext(newNode); //Node doesn't exist; add to end of list. 
        return newNode;


    }


}

void NodeList::printList() {

    // This prints everything!

    Node* temp = head;


    if (head == NULL) {



    } else {

        while (temp != NULL) {


            temp->printResistorList();


            temp = temp->getNext();


        }

    }

}

void NodeList::printListAtID(int const nodeID) {
    Node* temp = head;

    if (head == NULL) {

    } else {
        while (temp != NULL) {
            if (temp->getID() == nodeID) {
                cout << "fOUND IT" << endl;

            }

            temp = temp->getNext();

        }


    }



}

void NodeList::deleteAllResistors() {

    Node* temp1 = head;
    if (head == NULL) {
        return;

    } else {
        while (temp1 != NULL) {
            temp1 = head ->getNext();
            delete head;
            head = temp1;


        }
    }



}

bool NodeList::deleteResistor(string name) {

    Node* temp1 = head;
    bool isItThere = false;

    while (temp1 != NULL) {

        if (temp1->deleteResistor(name)) {
            isItThere = true;

        }

        temp1 = temp1->getNext();


    }


    if (!isItThere || name == "all") {
        return false;

    }
    else {
        return true;

    }


}

Node* NodeList::getHead() {

    return head;



}

void NodeList::printResistor(string name) {
    bool isItThere = false;

    Node* temp = head;

    if (head == NULL) {

    } else {
        while (temp != NULL) {
            if ((temp->getResistorList().getResName(name))) {
                isItThere = true;
                temp->getResistorList().findAndPrint(name);
            }


            temp = temp->getNext();
            break;
        }


    }

    if (isItThere == false) {
        cout << "Error: Resistor " << name << " not found" << endl;
    }

}

void NodeList::solve() {
    bool iterationCheck = true;
    bool areAllSet = false;
    Node* bigTempN = head;
    Node* trailTemp = head;

    if (bigTempN == NULL) {
        cout << "Error: no nodes have their voltage set" << endl;

    }


    while (bigTempN != NULL) {
        if (bigTempN->isVoltageSet()) {
            areAllSet = true;
            break;

        }

        bigTempN = bigTempN->getNext();
    }





    while (iterationCheck && areAllSet) { //Iterating over all of them
        // One iteration
        Node* tempN = head;

        iterationCheck = false;
        while (tempN != NULL) {
            if (tempN->isVoltageSet() == false) { //Ignoring user-set voltages
                double denom = 0;
                double numerator = 0;

                Resistor* tempR = tempN->getResistorList().getHead();

                while (tempR != NULL) { //Traversing through each resistor within each node
                    denom += 1 / tempR->getResistance();


                    // Dealing with the voltage at different ID's
                    int impNodeID = 0;


                    if (tempR ->getEndPoint1() == tempN->getID()) { //Getting the other node ID

                        impNodeID = tempR ->getEndPoint2(); //Important node ID 
                    } else {
                        impNodeID = tempR ->getEndPoint1();

                    }

                    Node* tempV = findNode(impNodeID); //Getting a node with a voltage

                    numerator += (tempV->getVoltage()) / (tempR->getResistance());

                    tempR = tempR ->getNext();


                } //Finished traversing

                double oldVoltage = tempN->getVoltage();
                double newVoltage = numerator / denom;

                tempN ->setVoltage(newVoltage);

                if (fabs(newVoltage - oldVoltage) > THRESHOLD_VOLTAGE) {
                    iterationCheck = true;
                }

                if (fabs(newVoltage - oldVoltage) == 0) //This is to get the solver moving
                {
                    tempN = tempN->getNext();

                }


            } else {

                tempN = tempN->getNext();

            }


        }
        // End of one iteration
    } //End of all iterations

    if (areAllSet) {

        cout << "Solve: " << endl;
        while (trailTemp != NULL) {
            cout << "  Node" << trailTemp->getID() << " : " << setprecision(2) << fixed << trailTemp->getVoltage() << " V" << endl;
            trailTemp = trailTemp->getNext();
        }
    } else {
        cout << "Error: no nodes have their voltage set" << endl;


    }




}

double NodeList::modifyRes(string name, double resistance) {

    Node* temp = head;
    bool print = true;
    double oldRes;

    if (head == NULL) //No resistors
    {

    } else {
        while (temp != NULL) {

            if (temp->getResistorList().getResName(name)) {

                oldRes = temp->getResistorList().modifyRes(resistance, name);
                print = false;

            }


            temp = temp->getNext();

        }

        if (print == false) {
            cout << "Modified: resistor " << name << " from " << oldRes << " Ohms to " << resistance << " Ohms " << endl;
        }

    }







    if (print == true) {
        cout << "Error: resistor " << name << " not found" << endl;
    }

    return oldRes;

}


