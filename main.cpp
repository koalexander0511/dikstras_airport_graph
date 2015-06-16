//Test

/*
    CIS 22C Team 4 Project: Dijkstra's algorithm (shortest path)

    12 June 2015
*/

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.
//
// Program Edited by Ko Outlaw-Spruell, James Hinds, and Victoriia Petrusha


#include <iostream>
#include <string>
#include <cstdlib>
#include "LinkedGraph.h"
#include "Dijkstra.h"
#include "Airport.h"

using namespace std;

typedef Dijkstra<Airport> *T;

void displayMenu();
void createGraph(T &t);

void readAirportsFromFile(string filename, Dijkstra<Airport> &graph){
	ifstream infile;
	infile.open(filename.c_str());
	if (infile.fail()){
		exit(1);
	}
	// not sure exactly what goes in here

	infile.close();
}
void display(string& anItem)
{
   cout << "Displaying item - " << anItem << endl;
}

int main()
{
   T g1;
   bool done = false;
   int choice;
   T sname, ename;
   T weight;

   createGraph(g1); //create a graph from input file

	do {
		displayMenu();
		cin >> choice;

		switch (choice)
		{
		case 1: //display help menu
			displayMenu();
			break;

		case 2: //add a vertex
			cout << "Enter the start vertex: ";
			cin >> sname;
			cout << "Enter the end vertex: ";
			cin >> ename;
			cout << "Enter the weight: ";
			cin >> weight;
			g1.add(sname, ename, weight);
			break;
		case 3: //display vertices in the graph
			g1.DisplayVertices();
			break;
		case 4: //display the graph
			g1.DisplayGraph();
			break;
		case 5: //remove an edge
			cout << "Enter the starting vertex: ";
			cin >> sname;
			cout << "Enter the ending vertex: ";
			cin >> ename;
			g1.remove(sname, ename);
			break;
		case 6: //get the number of vertices
			cout << "The number of vertices in the graph = " << g1.GetSize() << endl; // ???????
			break;
		case 7: //search for a certain vertex
		{
					 cout << "Enter a vertex: ";
					 cin >> sname;
					 int result = g1.Search(sname);
					 if (result == -1)
						 cout << "Vertex " << sname << " does not exist in the graph";
					 else
						 cout << "Vertex " << sname << " found in the graph";
					 cout << endl;
					 break;
		}


		case 8: //find the shorted path between two vertices
		{
					 cout << "Enter the starting vertex: ";
					 cin >> vname;
					 cout << "Enter the ending vertex: ";
					 cin >> vname2;
					 int result1 = g1.Search(vname);
					 int result2 = g1.Search(vname2);
					 if (result1 == -1 || result2 == -1){
						 cout << "Error: Invalid vertices" << endl;
					 }
					 else{
						 g1.FindShortestPath(vname, vname2);
					 }
					 break;
		}

		case 9: // undo

			break;

		case 10: // write to file
			cout << "Enter the file name: ";
			cin >> fName;
			writeToFile(fName, g1);
			break;

		case 11: //exit testing
			done = true;
			break;

		default:
			cout << "Invalid choice\n";
			break;
		} //end of switch


	} while (!done);

	cout << "Done with testing!" << endl;
	cin.get();
	cin.get();
	return 0;
}


   return 0;
}  // end main

// display menu
void displayMenu()
{

	int order = 0;

	cout << order++ << ": Show the menu." << endl;
	cout << order++ << ": Add to Graph." << endl;
	cout << order++ << ": Display vertices." << endl;
	cout << order++ << ": Display the graph." << endl;
	cout << order++ << ": Remove from graph." << endl;
	cout << order++ << ": Get the number of vertices in the graph." << endl;
	cout << order++ << ": Search for a certain vertex." << endl;
	cout << order++ << ": Find the shortest path between two vertices." << endl;
	cout << order++ << ": Undo last chnge." << endl;
	cout << order++ << ": Write graph to file." << endl;
	cout << 11 << ": Exit the program." << endl << endl;

}




