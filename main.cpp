/*
Mechatronika II
2023 / 2024
Sztuczna Inteligencja
"Grafy"

Miko³aj Marcinkowski 177631
Wiktor Smolski 175402
*/

#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <iterator>
#include "matplotlibcpp.h"
#include "Labirynths.h"

#define ANNOTATION_OFFSET 4

namespace plt = matplotlibcpp;

double DrawThePath(int ifFinish, std::vector<int> Path, std::vector<std::vector<double>> LabirynthCoordinates, int nodes);
void ShowLabirynth(std::vector<std::vector<int>>Labirynth, std::vector<std::vector<double>> LabirynthCoordinates, int nodes);
void DepthFirstSearch(std::vector<std::vector<int>>Labirynth, std::vector<std::vector<double>> LabirynthCoordinates, int Start, int Finish, int nodes, int &input);
void BreadthFirstSearch(std::vector<std::vector<int>> Labirynth, std::vector<std::vector<double>>LabirynthCoordinates, int Start, int Finish, int nodes, int &input);
void Menu(int& LabirynthToSolve, int& Algorithm, int& Start, int& Finish);
void AStar(std::vector<std::vector<int>> Labirynth, std::vector<std::vector<double>>LabirynthCoordinates, int Start, int Finish, int nodes, int& input);

std::vector<double> x, y;
std::vector<double> visited_x, visited_y;
std::vector<int> visited(49, 0);

int main() 
{
	int Start = 1;
	int Finish = 1;
	int LabirynthToSolve = 0;
	int Algorithm = 0;
	int input = 1;

	while (input)
	{
		std::cout << "Choose labirynth to solve out of:" << std::endl;
		std::cout << "Labirynth nr 1 (easy)"		<< std::endl
				  << "Labirynth nr 2 (medium)"		<< std::endl
				  << "Labirynth nr 3 (hard)"		<< std::endl;
		std::cout << "Type '1', '2' or '3': ";

		std::cin >> LabirynthToSolve;

		switch (LabirynthToSolve)
		{
		case 1: //LABIRYNTH NR 1

			Menu(LabirynthToSolve, Algorithm, Start, Finish);

			switch (Algorithm) {
			case 1: //Labirynth nr 1 / DFS
				ShowLabirynth(Labirynth_1, Labirynth1_Coordinates, 10);
				DepthFirstSearch(Labirynth_1, Labirynth1_Coordinates, Start, Finish, 10, input);
				break;
			case 2: //Labirynth nr 1 / BFS
				ShowLabirynth(Labirynth_1, Labirynth1_Coordinates, 10);
				BreadthFirstSearch(Labirynth_1, Labirynth1_Coordinates, Start, Finish, 10, input);
				break;
			case 3: //Labirynth nr 3 / A*
				ShowLabirynth(Labirynth_1, Labirynth1_Coordinates, 10);
				AStar(Labirynth_1, Labirynth1_Coordinates, Start, Finish, 10, input);
				break;
			default:
				std::cout << "Number must be '1', '2' or '3'. Type again." << std::endl;
				LabirynthToSolve = 1;
				break;
			}
			break;

		case 2: //LABIRYNTH NR 2
			Menu(LabirynthToSolve, Algorithm, Start, Finish);
			switch (Algorithm) {
			case 1: //Labirynth nr 2 / DFS
				ShowLabirynth(Labirynth_2, Labirynth2_Coordinates, 20);
				DepthFirstSearch(Labirynth_2, Labirynth2_Coordinates, Start, Finish, 20, input);
				break;
			case 2: //Labirynth nr 2 / BFS
				ShowLabirynth(Labirynth_2, Labirynth2_Coordinates, 20);
				BreadthFirstSearch(Labirynth_2, Labirynth2_Coordinates, Start, Finish, 20, input);
				break;
			case 3: //Labirynth nr 2 / A*
				ShowLabirynth(Labirynth_2, Labirynth2_Coordinates, 20);
				AStar(Labirynth_2, Labirynth2_Coordinates, Start, Finish, 20, input);
				break;
			default:
				std::cout << "Number must be '1', '2' or '3'. Type again." << std::endl;
				LabirynthToSolve = 2;
				break;
			}
			break;

		case 3: //LABIRYNTH NR 3
			Menu(LabirynthToSolve, Algorithm, Start, Finish);
			switch (Algorithm) {
			case 1: //Labirynth nr 3 / DFS
				ShowLabirynth(Labirynth_3, Labirynth3_Coordinates, 49);
				DepthFirstSearch(Labirynth_3, Labirynth3_Coordinates, Start, Finish, 49, input);
				break;
			case 2: //Labirynth nr 3 / BFS
				ShowLabirynth(Labirynth_3, Labirynth3_Coordinates, 49);
				BreadthFirstSearch(Labirynth_3, Labirynth3_Coordinates, Start, Finish, 49, input);
				break;
			case 3: //Labirynth nr 3 / A*
				ShowLabirynth(Labirynth_3, Labirynth3_Coordinates, 49);
				AStar(Labirynth_3, Labirynth3_Coordinates, Start, Finish, 49, input);
				break;
			default:
				std::cout << std::endl << "Number must be '1', '2' or '3'. Type again." << std::endl;
				LabirynthToSolve = 3;
				break;
			}
			
		default:
			std::cout << std::endl << "Your number must be '1', '2' or '3'. Type again." << std::endl;
			break;
		}
	}
}

void Menu(int& LabirynthToSolve, int& Algorithm, int& Start, int& Finish)
{
	switch (LabirynthToSolve) {
	case 1:
		std::cout << "*** LABIRYNTH NR 1 ***" << std::endl;
		std::cout << "Select starting point. Type nr from 1 to 10: ";
		std::cin >> Start;

		std::cout << std::endl << "Select finish point. Type nr from 1 to 10: ";
		std::cin >> Finish;

		std::cout << "Select searching algorithm: " << std::endl;
		std::cout << "1 - Depth First Search" << std::endl
			<< "2 - Breadth First Search" << std::endl
			<< "3 - A*" << std::endl;
		std::cout << "Type '1', '2' or '3': ";
		std::cin >> Algorithm;
		break;
	case 2:
		std::cout << "*** LABIRYNTH NR 2 ***" << std::endl;
		std::cout << "Select starting point. Type nr from 1 to 20: ";
		std::cin >> Start;

		std::cout << std::endl << "Select finish point. Type nr from 1 to 20: ";
		std::cin >> Finish;

		std::cout << "Select searching algorithm: " << std::endl;
		std::cout << "1 - Depth First Search" << std::endl
			<< "2 - Breadth First Search" << std::endl
			<< "3 - A*" << std::endl;
		std::cout << "Type '1', '2' or '3': ";
		std::cin >> Algorithm;
		break;
	case 3:
		std::cout << "*** LABIRYNTH NR 3 ***" << std::endl;
		std::cout << "Select starting point. Type nr from 1 to 49: ";
		std::cin >> Start;

		std::cout << std::endl << "Select finish point. Type nr from 1 to 49: ";
		std::cin >> Finish;

		std::cout << "Select searching algorithm: " << std::endl;
		std::cout << "1 - Depth First Search" << std::endl
			<< "2 - Breadth First Search" << std::endl
			<< "3 - A*" << std::endl;
		std::cout << "Type '1', '2' or '3': ";
		std::cin >> Algorithm;
		break;
	default:
		std::cout << std::endl << "Number must be '1', '2' or '3'. Type again." << std::endl;
		break;
	}
}

double DrawThePath(int ifFinish, std::vector<int> Path, std::vector<std::vector<double>> LabirynthCoordinates, int nodes) {

	std::vector<double> NodeCoordinates_x { LabirynthCoordinates[(Path.front())][0] };
	std::vector<double> NodeCoordinates_y { LabirynthCoordinates[(Path.front())][1] };
	std::vector<double> VisitedPointCoordinates_x { LabirynthCoordinates[(Path.front())][0] };
	std::vector<double> VisitedPointCoordinates_y { LabirynthCoordinates[(Path.front())][1] };

	if (ifFinish) {
		for (int i = 0; i < Path.size(); i++) {
			NodeCoordinates_x.push_back(LabirynthCoordinates[Path.at(i)][0]);
			NodeCoordinates_y.push_back(LabirynthCoordinates[Path.at(i)][1]);
		}
		x = NodeCoordinates_x;
		y = NodeCoordinates_y;
	}
	else {
		for (int i = 0; i < Path.size(); i++) {
			NodeCoordinates_x.push_back(LabirynthCoordinates[Path.at(i)][0]);
			NodeCoordinates_y.push_back(LabirynthCoordinates[Path.at(i)][1]);
		}
		for (int i = 0; i < nodes; i++) {
			if (visited[i] == 1) {
				VisitedPointCoordinates_x.push_back(LabirynthCoordinates[i][0]);
				VisitedPointCoordinates_y.push_back(LabirynthCoordinates[i][1]);
			}
		}
		x = NodeCoordinates_x;
		y = NodeCoordinates_y;
		visited_x = VisitedPointCoordinates_x;
		visited_y = VisitedPointCoordinates_y;
	}
}

void ShowLabirynth(std::vector<std::vector<int>>Labirynth, std::vector<std::vector<double>> LabirynthCoordinates, int nodes)
{
	std::string NodeNameString[50] = { "v1",  "v2",  "v3", "v4",  "v5",  "v6",  "v7",  "v8",  "v9",  "v10", "v11", "v12", "v13", "v14", "v15", "v16", "v17", "v18", "v19", "v20",
									  "v21", "v22", "v23", "v24", "v25", "v26", "v27", "v28", "v29", "v30", "v31", "v32", "v33", "v34", "v35", "v36", "v37", "v38", "v39", "v40",
									  "v41", "v42", "v43", "v44", "v45", "v46", "v47", "v48", "v49", "v50" };
	std::vector<double> LabirynthCoordinates_x {LabirynthCoordinates[0][0]}, LabirynthCoordinates_y{ LabirynthCoordinates[0][1] };
	std::vector<double> vEdge_x(2), vEdge_y(2);
	std::vector<double> Wall_x(2), Wall_y(2);
	std::vector<double> NodeNameCoordinates_x {LabirynthCoordinates[0][0] - ANNOTATION_OFFSET}, NodeNameCoordinates_y{ LabirynthCoordinates[0][1] - ANNOTATION_OFFSET };

	plt::figure_size(800, 600);
	plt::xlim(-1.0, 100.0);				//Set X axle start and end limits.
	plt::ylim(-1.0, 100.0);				//Set Y axle start and end limits.

	/* Defining annotation coordinates and passing vrtexes (nodes) coordinates to vector, beacuse function "plt::scatter" needs vectors as parameters. */
	for (int i = 1; i < nodes; i++) {
		NodeNameCoordinates_x.push_back(LabirynthCoordinates[i][0] - ANNOTATION_OFFSET);
		NodeNameCoordinates_y.push_back(LabirynthCoordinates[i][1] - ANNOTATION_OFFSET);
		LabirynthCoordinates_x.push_back(LabirynthCoordinates[i][0]);
		LabirynthCoordinates_y.push_back(LabirynthCoordinates[i][1]);
	}

	double Distance_x = LabirynthCoordinates[5][0] - LabirynthCoordinates[0][0];
	double Distance_y = LabirynthCoordinates[1][1] - LabirynthCoordinates[0][1];

	//Pass coordinates to vectors and plot the edges one by one.
	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < nodes; j++) {
			if (Labirynth[i][j] == 1) {
				vEdge_x.at(0) = LabirynthCoordinates[i][0];
				vEdge_y.at(0) = LabirynthCoordinates[i][1];
				vEdge_x.at(1) = LabirynthCoordinates[j][0];
				vEdge_y.at(1) = LabirynthCoordinates[j][1];
				plt::plot(vEdge_x, vEdge_y, "c-");
			}
		}
	}

	//Plot points/nodes/vertexes & annotations.
	for (int i = 0; i < nodes; i++) {
		plt::scatter(LabirynthCoordinates_x, LabirynthCoordinates_y, 20);
		plt::annotate(NodeNameString[i], NodeNameCoordinates_x.at(i), NodeNameCoordinates_y.at(i));
	}
}

void DepthFirstSearch(std::vector<std::vector<int>>Labirynth, std::vector<std::vector<double>> LabirynthCoordinates, int Start, int Finish, int nodes, int &input)
{
	//Classes defined in oreder to plot path and visited points in different colors and styles.
	plt::Plot points("DFS", "r*");
	plt::Plot edges("DFS", "r");
	plt::Plot finish_points("DFS", "g*");
	plt::Plot finish_edges("DFS", "g");

	int DeadEnd = 1;					//Set the flag of DeadEnd (If actual node is not dead end then the flag will be set to "0").
	std::vector<int> Path {Start - 1};	//First element of Path is of course Start.
	int Steps = 0;

	//Main loop of Depth First Search
	for (int i = Start - 1; i < nodes;) {						//Start analyzing graph from the defined Start point.
		int ifFinish = 0;
		DeadEnd = 1;											//Set the flag of DeadEnd (If actual node is not dead end then the flag will be set as "0".
		visited.at(i) = 1;										//Mark "i-ty wêze³" as visited.
		std::cout << "I am at node: " << i + 1 << std::endl;	//Tell me where you are currently.

		for (int j = 0; j < (int)Path.size(); j++) {			//Tell me about path you've been through :P
			std::cout << Path.at(j) + 1 << "->";
		}

		std::cout << std::endl;

		if (i == Finish - 1) {									//Check if current node is the final one.
			ifFinish = 1;										//Set finish flag, just to inform "DrawThePath" function to draw final path (green path).
			std::cout << "Found Finish point!" << std::endl;

			//Update the display.
			DrawThePath(ifFinish, Path, LabirynthCoordinates, nodes);
			finish_edges.update(x, y);
			finish_points.update(x, y);
			plt::pause(1);

			std::cout << "Nr of steps: " << Steps << std::endl;
			std::cout << "**********************" << std::endl << std::endl;
			std::cout << "If You want to close - type '0', if not - type '1': ";
			std::cin >> input;
			break;
		}
		else {
			//Update the image.
			DrawThePath(ifFinish, Path, LabirynthCoordinates, nodes);
			edges.update(x, y);
			points.update(visited_x, visited_y);
			plt::pause(1);

			for (int j = 0; j < nodes; j++) {								//For every graph node...
				if (Labirynth.at(i).at(j) == 1 && visited.at(j) == 0) {		//If the node is adjacent - if it's possible to go there && the node is NOT visited yet...
					DeadEnd = 0;											//It is not dead end.
					i = j;													//Set j-th node as new, current node.
					Path.push_back(j);										//Add current node to the Path.
					break;													//Break the loop as you already found possible way and change current node.
				}
			}

			if (DeadEnd == 1) {		//If DeadEnd == 1 - it means that there was no possible way or every adjacent nodes were visited previously.
				Path.pop_back();	//Hence, delete actual node from path and...
				i = Path.back();	//Go back to previous node. -> Check possibilities again for previuous node. (and so on if next-previous node will also be "dead end".
			}
		}
		Steps++;
		std::cout << "Nr of steps: " << Steps << std::endl;
		std::cout << "**********************" << std::endl;
	}
}

void BreadthFirstSearch(std::vector<std::vector<int>> Labirynth, std::vector<std::vector<double>>LabirynthCoordinates, int Start, int Finish, int nodes, int &input)
{
	//Classes defined in oreder to plot path and visited points in different colors and styles.
	plt::Plot points("DFS", "r*");
	plt::Plot edges("DFS", "r");
	plt::Plot finish_points("DFS", "g*");
	plt::Plot finish_edges("DFS", "g");

	std::vector<int> Visited = {};			//This will contain every visited node. It will be used to traverse the shortest possible path.
	std::vector<int> ToVisit = {};			//This will contain every possible node, adjacent to the current one.
	std::vector<int> Path = { Finish - 1 };	//First point is user defined.
	int previous_node = Finish - 1;			//The node from which traversing the shortest path will start.
	int ifFinish = 0;
	int Steps = 0;

	//Main loop of BFS:
	for (int i = Start - 1; i < nodes;) {

		std::cout << std::endl << "I am at: " << i + 1 << std::endl;

		Visited.push_back(i);	//Mark i-th node as visited;
		visited.at(i) = 1;		//Mark i-th node as visited;

		if ((int)ToVisit.size() != 0)		//If it is not the first step in general.
			ToVisit.erase(ToVisit.begin());	//Delete the first one from "ToVisit" because it is now the current one.

		//If found finish point, then set the path
		if (i == Finish - 1) {
			//Set finish flag, just to inform "DrawThePath" function to draw final path (green path).
			ifFinish = 1;

			//Print every visited node.
			std::cout << std::endl << "Visited:";
			for (int j = 0; j < (int)Visited.size(); j++) {
				std::cout << "->" << Visited.at(j) + 1;
			}

			//Set point to which "Visited" has to be searched out.
			int cut_off = (int)Visited.size() - 1; 

			for (int k = 0; k < cut_off;) {
				if (Labirynth[previous_node][Visited.at(k)] == 1) {		//If nodes are adjacent...
					previous_node = Visited.at(k);						//Set first one found in "Visited" as the previous one. 
					Path.push_back(previous_node);						//Add it to the path.
					cut_off = k;										//there is no need to search further than to the actual one in Visited.
					k = 0;
				}
				else {
					k++;
				}
				/* example:
				* Visited = { 1, 3, 4, 5, 8 }; previous_node = 8; 
				* nodes nr 4 and 5 are adjacent to 8.
				* As first found was "4" -> set it as "previous_node", because it took less steps to reach "4" than to reach "5".
				* And set cut_off = 2 as it is only needed to search from first visited node to the current one whis is "4".
				*/
			}

			//Print the Path.
			std::cout << std::endl << "Path: ";
			for (int j = 0; j < (int)Path.size(); j++) {
				std::cout << "->" << Path.at(j) + 1;
			}

			//Update the display.
			DrawThePath(ifFinish, Path, LabirynthCoordinates, nodes);
			finish_edges.update(x, y);
			finish_points.update(x, y);
			plt::pause(1);

			std::cout << std:: endl << "If You want to close - type '0', if not - type '1': ";
			std::cin >> input;
			break;

		}
		else {

			//Update the display.
			DrawThePath(ifFinish, Visited, LabirynthCoordinates, nodes);
			points.update(visited_x, visited_y);
			plt::pause(1);

			for (int j = 0; j < nodes; j++) {
				if (Labirynth[i][j] == 1 && visited[j] == 0) {		//If the nodes are adjacent...
					ToVisit.push_back(j);							//Add j-th node to the queue called "ToVisit".

					//Check if you could reach already added node earlier:
					for (int j = 0; j < ((int)ToVisit.size()) - 1; j++) {
						if ((int)ToVisit.size() > 1) {
							if (ToVisit.back() == ToVisit.at(j)) {	//if it is already in the queue - you could visit it earlier (in less number of steps), then...
								ToVisit.pop_back();					//...delete its "redundant twin" from the end of queue.
							}
						}
					}
				}
			}

			std::cout << "ToVisit:";
			for (int j = 0; j < (int)ToVisit.size(); j++) {
				std::cout << "  " << ToVisit.at(j) + 1;
			}

			i = ToVisit.front(); //Set first one to visit as current one and go on...
		}

		Steps++;

		std::cout << std::endl << "Visited: " << std::endl;
		for (int j = 0; j < (int)Visited.size(); j++) {
			std::cout << "->" << Visited.at(j) + 1;
		}
		std::cout << std::endl << "Nr of steps: " << Steps << std::endl;
		std::cout << std::endl << "*************" << std::endl;
	}


}

void AStar(std::vector<std::vector<int>> Labirynth, std::vector<std::vector<double>>LabirynthCoordinates, int Start, int Finish, int nodes, int& input)
{
	//Classes defined in oreder to plot path and visited points in different colors and styles.
	plt::Plot points("DFS", "r*");
	plt::Plot edges("DFS", "r");
	plt::Plot finish_points("DFS", "g*");
	plt::Plot finish_edges("DFS", "g");

	int previous_node = Finish - 1;
	int ifFinish = 0;
	int Steps = 0;
	int CurrentCost = INT32_MAX;

	std::vector<int> PossibleSuccesor = {};
	std::vector<int> CurrentPath = {Start - 1};
	std::vector<int> Heuristics = { INT32_MAX };	//Heuristics equals to Manhattan geometry distance between current node and finish node.
	std::vector<int> BasicCost = { INT32_MAX };		//Basic cost equals to the distance between two adjacent nodes.
	std::vector<int> TotalCost = { INT32_MAX };		//Total cost = BasicCost + Heuristics
	std::vector<std::vector<int>> PotentialPaths;	//2D vector to conatin every possible path.

	PotentialPaths.push_back(CurrentPath);

	//Main loop of A*
	for (int i = Start - 1; i < nodes;) 
	{
		visited.at(i) = 1;

		if(i != Start - 1)
			Steps++;

		if (i == Finish - 1)
		{
			ifFinish = 1;
			DrawThePath(ifFinish, CurrentPath, LabirynthCoordinates, nodes);
			finish_edges.update(x, y);
			finish_points.update(x, y);
			plt::show();
		}
		else {

			DrawThePath(ifFinish, CurrentPath, LabirynthCoordinates, nodes);
			//edges.update(x, y);
			points.update(visited_x, visited_y);
			plt::pause(0.0001);

			//For current node chceck and remember every possible successor:
			for (int j = 0; j < nodes; j++) {
				if (Labirynth[i][j] == 1 && visited[j] == 0) {
					PossibleSuccesor.push_back(j);
				}
			}
			//As many possible paths as many possible successors:
			for (int j = 0; j < (int)PossibleSuccesor.size(); j++) {
				PotentialPaths.push_back(CurrentPath);
				PotentialPaths.back().push_back(PossibleSuccesor.at(j));
				TotalCost.push_back(INT32_MAX);
				BasicCost.push_back(INT32_MAX);
				Heuristics.push_back(INT32_MAX);
			}

			PossibleSuccesor.clear();

			//Delete current path from possible paths as it has already been gone through.
			for (int j = 0; j < (int)PotentialPaths.size(); j++) {
				if (PotentialPaths.at(j) == CurrentPath) {
					PotentialPaths.erase(PotentialPaths.begin() + j);
					TotalCost.erase(TotalCost.begin() + j);
					BasicCost.erase(BasicCost.begin() + j);
					Heuristics.erase(Heuristics.begin() + j);
				}
			}

			CurrentCost = INT32_MAX;

			//For every potential path calculate basic cost, heuristics, total cost...
			for (int j = 0; j < (int)PotentialPaths.size(); j++) {
				BasicCost.at(j) = 0; // HERE IS THE REVISION
				for (int k = 1; k < (int)PotentialPaths.at(j).size(); k++) {
					int from_node = PotentialPaths.at(j).at(k - 1);
					int to_node = PotentialPaths.at(j).at(k);
					//BasicCost.at(j) = 0; <--------------------HERE WAS THE MISTAKE - it was not calculating basic cost from Start to current point but from previous point to current point. 
					BasicCost.at(j) += abs(LabirynthCoordinates[from_node][0] - LabirynthCoordinates[to_node][0]) +
						 abs(LabirynthCoordinates[from_node][1] - LabirynthCoordinates[to_node][1]);
				}
				
				Heuristics.at(j) = abs(LabirynthCoordinates[PotentialPaths.at(j).back()][0] - LabirynthCoordinates[Finish - 1][0]) +
					abs(LabirynthCoordinates[PotentialPaths.at(j).back()][1] - LabirynthCoordinates[Finish - 1][1]);

				TotalCost.at(j) = BasicCost.at(j) + Heuristics.at(j);
				//... find the possible with lowest total cost and set it at current one.
				if (TotalCost.at(j) < CurrentCost) {
					CurrentCost = TotalCost.at(j);
					CurrentPath = PotentialPaths.at(j);
					i = PotentialPaths.at(j).back();
				}
			}
			
			for (int j = 0; j < (int)TotalCost.size(); j++) {
				std::cout << "************************" << std::endl;
				std::cout << std::endl <<"Potential Path nr " << j + 1 << " is:" << std::endl;
				for (int k = 0; k < (int)PotentialPaths.at(j).size(); k++) {
					std::cout << PotentialPaths.at(j).at(k) + 1 << " ";
				}
				std::cout << std::endl << "Cost: " << TotalCost.at(j) << std::endl;
				std::cout << "Heuristics: " << Heuristics.at(j) << std::endl;
				std::cout << "Basic cost: " << BasicCost.at(j) << std::endl;
			}
		}
	}
}




