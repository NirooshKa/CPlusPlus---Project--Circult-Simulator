/* 
 * File:   Rparser.h
 * Author: kammulaa
 *
 * Created on October 16, 2016, 7:27 PM
 */

#ifndef RPARSER_H
#define	RPARSER_H
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "NodeList.h"
#define MAX_NODE_NUMBER 5000
using namespace std;


void parser (NodeList &node_list);

void insertR(stringstream& commandStreams, stringstream& errorStream, int errorCheck, bool checkValid, NodeList& node_list);

void printR(stringstream& commandStreams, stringstream& errorStream, int errorCheck, NodeList& node_list);

void modifyR(stringstream& commandStreams, stringstream& errorStream, int errorCheck, NodeList& node_list);

void deleteR (stringstream& commandStreams, stringstream& errorStream, int errorCheck, NodeList& node_list);

void printNode (stringstream& commandStreams, stringstream& errorStream, stringstream& errorStream2, int errorCheck, NodeList& node_list);

void setV (stringstream& commandStreams, stringstream& errorStream, int errorCheck, NodeList& node_list);

void unsetV (stringstream& commandStreams, stringstream& errorStream, int errorCheck, NodeList& node_list);

void solve (stringstream& commandStreams, stringstream& errorStream, int errorCheck, NodeList& node_list);

int countArg(string line);

#endif	/* RPARSER_H */

