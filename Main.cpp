/* 
 * File:   main.cpp
 * Author: kammulaa
 *
 * Created on November 3, 2016, 10:47 AM
 */

#include <cstdlib>
#include <iostream>
#include <string.h>
#include <iomanip>
#include "Node.h"
#include "Resistor.h"
#include "Rparser.h"
#include "ResistorList.h"
#include "NodeList.h"
#define MIN_ITERATION_CHANGE = 0.001

using namespace std;


int main(int argc, char** argv) {

   NodeList node_list;
   
   parser(node_list);
    
    
    
    return 0;
    
}



