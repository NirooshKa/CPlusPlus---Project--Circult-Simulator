/* 
 * File:   NodeList.h
 * Author: kammulaa
 *
 * Created on November 4, 2016, 7:34 PM
 */

#ifndef NODELIST_H
#define	NODELIST_H
#include "Resistor.h"
#include "Node.h"
#include <string>


class Node;

class NodeList {
private:
    Node* head;

public:


    NodeList();
    ~NodeList();

    Node* findNode(int const nodeID);
    Node* findOrInsert(int const nodeID);
    void printList(); // Prints all nodes
    void printListAtID(int const nodeID);
    void deleteAllResistors();
    bool deleteResistor(string name);
    Node* getHead();
    void printResistor(string name);
    bool didYouSetVoltage();
    void solve();
    double modifyRes(string name, double resistance);

};



#endif	/* NODELIST_H */

