#include "Rparser.h"
#include "Node.h"
#include "Resistor.h"
#include "NodeList.h"
#include "ResistorList.h"
#define MAX_NODE_NUMBER 5000
#include <cstdlib>
#include <string>
#include <iostream>

/*
 What to do next: 

 * 1. NodeList:: FindInsert -> fix the memory leak!
 * 
 
 */


int nodeCount = 0, resCount = 0;
bool checker = false;
bool deleteChecker = false;
using namespace std;

string line, command, resistorName, testName, command1, command2, command3, command4;
int errorChecker;
double resistance = 0;
int node1 = 0, node2 = 0;
int maxRes = 0, maxNode = 0;
double nodeD = 0;
int oldMaxNode = 0;
int oldResCount = 0;
double voltage = 0;

void miniDelete() {



}

void insertR(stringstream& commandStreams, stringstream& errorStream, int errorCheck, bool validCheck, NodeList& node_list) {

    commandStreams >> resistorName >> resistance >> node1 >> node2;
    errorStream >> command >> command1 >> command2 >> command3 >> command4;



    if ((node1 == node2) && ((node1 != 0) || (node2 != 0))) { //Checking if nodes are equal

        cout << "Error: both terminals of resistor connect to node 1" << endl;

    } else if (resistance < 0) { //Checking if resistance is positive
        cout << "Error: negative resistance" << endl;

    } else if (errorCheck < 5) { //Too many arguments
        cout << "Error: too few arguments" << endl;

    } else if (errorCheck > 5) { //Too few arguments
        cout << "Error: too many arguments" << endl;


    } else if ((!errorStream.fail()) && (commandStreams.fail())) //Erroneous cases #8: stupid inputs
    {
        cout << "Error: invalid argument" << endl;


    }
    else {



        Node* newNode1 = node_list.findOrInsert(node1);

        Node* newNode2 = node_list.findOrInsert(node2);


        if ((newNode1->insertResistor(resistorName, node1, node2, resistance)) &&(newNode2->insertResistor(resistorName, node1, node2, resistance))) {


            cout << "Inserted: resistor " << resistorName << " " << fixed << setprecision(2) << resistance << " " << "Ohms " << node1 << " -> " << node2 << endl;
        }
        else {
            cout << "Error: " << "resistor " << resistorName << " already exists" << endl;

        }




    }



}

void printR(stringstream& commandStreams, stringstream& errorStream, int errorCheck, NodeList& node_list) {


    commandStreams >> resistorName; // Even more string breaking :D
    errorStream >> command >> command1;

    if (errorCheck > 2) //Erroneous case #1: Too many arguments
    {
        cout << "Error: too many arguments" << endl;



    } else if (errorCheck < 2) //Erroneous case #2: Too few arguments
    {
        cout << "Error: too few arguments" << endl;



    }

    else if (resistorName == "all") { //Printing all resistors

        cout << ("Error: resistor name cannot be the keyword \"all\"") << endl;

    }
    else if ((!commandStreams.eof())&&(commandStreams.peek() != ' ')) {
        cout << "Error: invalid argument" << endl;

    } else //When this thing successfully works  
    {


        node_list.printResistor(resistorName);


    }



}

void modifyR(stringstream& commandStreams, stringstream& errorStream, int errorCheck, NodeList& node_list) {


    commandStreams >> resistorName >> resistance; // Even more string breaking :D
    errorStream >> command >> command1 >> command2;

    if (resistance < 0) //Erroneous case #1 : Negative resistance
    {
        cout << "Error: negative resistance" << endl;


    } else if (errorCheck > 3) //Erroneous case #2: Too many arguments
    {
        cout << "Error: too many arguments" << endl;



    } else if (errorCheck < 3) //Erroneous case #3: Too few arguments
    {
        cout << "Error: too few arguments" << endl;


    }

    else if (resistorName == "all") { // Erroneous case #4

        cout << ("Error: resistor name cannot be the keyword \"all\"") << endl;


    } else if ((!errorStream.fail()) && (commandStreams.fail())) //Erroneous cases #5: stupid inputs
    {
        cout << "Error: invalid argument" << endl;


    } else if ((!commandStreams.eof())&&(commandStreams.peek() != ' ')) {
        cout << "Error: invalid argument" << endl;

    }
    else //When everything works well 
 {

        double oldResis = node_list.modifyRes(resistorName, resistance);



    }



}

void deleteR(stringstream& commandStreams, stringstream& errorStream, int errorCheck, NodeList& node_list) {

    commandStreams >> resistorName;
    errorStream >> command >> command1;


    if (errorCheck > 2) //Erroneous case #1: Too many arguments
    {
        cout << "Error: too many arguments" << endl;



    } else if (errorCheck < 2) //Too little
    {
        cout << "Error: too few arguments" << endl;


    }


    else if ((!commandStreams.eof())&&(commandStreams.peek() != ' ')) {
        cout << "Error: invalid argument" << endl;

    }
    else if ((!errorStream.fail()) && (commandStreams.fail())) //Erroneous cases #5: stupid inputs
    {
        cout << "Error: invalid argument" << endl;
    }
    else { //When everything works well




        if (node_list.deleteResistor(resistorName)) {
            cout << "Deleted: resistor " << resistorName << endl;
        }

        if ((command1 == "all") && !(node_list.deleteResistor(resistorName))) {
            cout << "Deleted: all resistors" << endl;

        }
        else if (!node_list.deleteResistor(resistorName) && command1 != "all") {
            cout << "Error " << resistorName << "not found" << endl;

        }




    }


}

void printNode(stringstream& commandStreams, stringstream& errorStream, stringstream& errorStream2, int errorCheck, NodeList& node_list) {



    commandStreams >> node1; //Even more string breaking :D
    errorStream >> command >> command1; //Even more string breaking :D



    if (errorCheck > 2) //Too many arguments
    {
        cout << "Error: too many arguments" << endl;



    } else if (errorCheck < 2) //Too little arguments
    {
        cout << "Error: too few arguments" << endl;



    }
    else if (commandStreams.fail() && !errorStream.fail() && command1 != "all") //Erroneous cases #5: stupid inputs
    {
        cout << "Error: invalid argument" << endl;


    }
    else if (((commandStreams.fail())&&(errorStream.fail()))) {
        cout << "Error: invalid argument" << endl;


    } else if ((command1 == "all")) {
        cout << "Print:" << endl;
        node_list.printList();
        // Make sure it prints the resistors afterwards 


    }
    else if ((!commandStreams.eof())&&(commandStreams.peek() != ' ')) {
        cout << "Error: invalid argument" << endl;

    }
    else // When everything works out well 
    {
        Node* n1 = node_list.findNode(node1);

        if (n1 == NULL) {
            cout << "Node does not exist" << endl;

        }


        else {
            cout << "Print:" << endl;
            n1->printResistorList();

        }


    }


}

int countArg(string line) { //This counts the amount of arguments within the text.

    int count = -1;
    string temp;
    string line2 = line;
    stringstream counting(line2);



    while (!counting.fail()) {
        counting>>temp;
        count++;
    }


    return count;
}

void setV(stringstream& commandStreams, stringstream& errorStream, int errorCheck, NodeList& node_list) {

    commandStreams >> node1 >> voltage;
    errorStream >> command >> command1 >> command2;

    if (errorCheck > 3) //Too many arguments
    {
        cout << "Error: too many arguments" << endl;



    }
    else if (errorCheck < 3) //Too little arguments
    {
        cout << "Error: too few arguments" << endl;



    }
    else if (commandStreams.fail() && !errorStream.fail()) //Erroneous cases #5: stupid inputs
    {
        cout << "Error: invalid argument" << endl;


    }

    else if (((commandStreams.fail())&&(errorStream.fail()))) {
        cout << "Error: invalid argument" << endl;


    }

    else {

        Node* n1 = node_list.findNode(node1);
        n1->setV(voltage);

        cout << "Set: node " << node1 << " to " << voltage << " Volts " << endl;

    }





}

void unsetV(stringstream& commandStreams, stringstream& errorStream, int errorCheck, NodeList& node_list) {
    commandStreams >> node1;
    errorStream >> command >> command1;

    if (errorCheck > 2) //Too many arguments
    {
        cout << "Error: too many arguments" << endl;



    }
    else if (errorCheck < 2) //Too little arguments
    {
        cout << "Error: too few arguments" << endl;



    }
    else if (commandStreams.fail() && !errorStream.fail()) //Erroneous cases #5: stupid inputs
    {
        cout << "Error: invalid argument" << endl;


    }

    else if (((commandStreams.fail())&&(errorStream.fail()))) {
        cout << "Error: invalid argument" << endl;


    }

    else {

        Node* n1 = node_list.findNode(node1);
        n1->unsetV();

        cout << "Unset: the solver will determine the voltage of node " << node1 << endl;

    }




}

void solve(stringstream& commandStreams, stringstream& errorStream, int errorCheck, NodeList& node_list) {

    errorStream << command;

    if (errorCheck > 1) //Too many arguments
    {
        cout << "Error: too many arguments" << endl;



    }
    else if (errorCheck < 1) //Too little arguments
    {
        cout << "Error: too few arguments" << endl;



    }
    else if (errorStream.fail()) //Erroneous cases #5: stupid inputs
    {
        cout << "Error: invalid argument" << endl;


    }

    else if ((!errorStream.fail())) // The voltages will be solved for 
    {
        node_list.solve();


    }





}

void parser(NodeList &node_list) {
    string line, command, resistorName, testName, command1, command2, command3, command4;
    int errorChecker;
    double resistance = 0;
    double voltage = 0;
    int node1 = 0, node2 = 0;
    int maxRes = 0, maxNode = 0; //Checks if node is a double or not
    bool checkValid = true;

    cout << "> ";
    getline(cin, line); //The user picks the command that the program has to do.


    while (!cin.eof()) {

        stringstream commandStream(line); //This is where the stringstream is defined.
        stringstream errorCheck(line); //This will check for proper integer values 
        stringstream errorCheck2(line);

        errorChecker = countArg(line);
        commandStream >> command; //Breaking up of string


        if (command == "insertR") { //Function #1


            insertR(commandStream, errorCheck, errorChecker, checkValid, node_list);

            cout << "> ";
            getline(cin, line);


        } else if (command == "modifyR") { //Function #2


            modifyR(commandStream, errorCheck, errorChecker, node_list);

            cout << "> ";
            getline(cin, line);

        } else if (command == "printR") { //Function #3


            printR(commandStream, errorCheck, errorChecker, node_list);

            cout << "> ";
            getline(cin, line);

        } else if (command == "printNode") { //Function #4

            printNode(commandStream, errorCheck, errorCheck2, errorChecker, node_list);

            cout << "> ";
            getline(cin, line);

        } else if (command == "deleteR") { //Function #5 
            // Even more string breaking :D


            deleteR(commandStream, errorCheck, errorChecker, node_list);

            cout << "> ";
            getline(cin, line);

        } else if (command == "setV") //Function #6
        {

            setV(commandStream, errorCheck, errorChecker, node_list);

            cout << "> ";
            getline(cin, line);

        } else if (command == "unsetV") //Function #7
        {
            unsetV(commandStream, errorCheck, errorChecker, node_list);

            cout << "> ";
            getline(cin, line);

        } else if (command == "solve") //Function #8
        {

            solve(commandStream, errorCheck, errorChecker, node_list);

            cout << "> ";
            getline(cin, line);

        } else //This is for any additional errors 
        {

            cout << "Error: invalid command" << endl;
            cout << "> ";
            commandStream.clear();
            getline(cin, line);

        }

        command = "c";

        errorCheck.clear();

    };

    cout << "\n";

}