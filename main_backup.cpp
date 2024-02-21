#include <iostream>
#include <vector>
#include "matplotlibcpp.h"

#define ANNOTATION_OFFSET 4

namespace plt = matplotlibcpp;
const int nodes = 20;

double DrawThePath(int ifFinish, std::vector<int> Path, std::vector<std::vector<double>> LabirynthCoordinates);
void ShowLabirynth(std::vector<std::vector<double>> LabirynthCoordinates, int Labirynth[nodes][nodes]);
void DFS(int Labirynth[nodes][nodes], int Start, int Finish, std::vector<std::vector<double>> LabirynthCoordinates);

std::vector<double> x, y;
std::vector<double> visited_x, visited_y;
int visited[nodes]{};


int main() 
{
	
	int Start = 20;
	int Finish = 13;

	int Labirynth_1[nodes][nodes] =
	{ { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },  	//v1
	  { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0 },  	//v2
	  { 0, 1, 0, 1, 0, 0, 0, 1, 0, 0 },  	//v3
	  { 0, 0, 1, 0, 1, 0, 1, 0, 0, 0 },  	//v4
	  { 0, 0, 0, 1, 0, 1, 0, 0, 0, 0 },  	//v5
	  { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },  	//v6
	  { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },  	//v7
	  { 0, 0, 1, 0, 0, 0, 0, 0, 1, 0 },  	//v8
	  { 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 },  	//v9
	  { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 } };   //v10
	// v1 v2 v3 v4 v5 v6 v7 v8 v9 v10

	/* Points coordinates for visualization */
	std::vector<std::vector<double>> Labirynth1_Coordinates 
	{ { 10, 80 },		//v1
	  { 30, 80 },		//v2
	  { 30, 60 },		//v3
	  { 60, 60 },		//v4
	  { 60, 80 },		//v5
	  { 80, 80 },		//v6
	  { 60, 40 },		//v7
	  { 30, 30 },		//v8
	  { 45, 30 },		//v9
	  { 45, 20 } };		//v10

	int Labirynth_2[nodes][nodes] =
	{ { 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//v1
	  { 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//v2
	  { 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//v3
	  { 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//v4
	  { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//v5
	  { 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//v6
	  { 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//v7
	  { 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},	//v8
	  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},	//v9
	  { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0},	//v10
	  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},	//v11
	  { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},	//v12
	  { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0},	//v13
	  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},	//v14
	  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0},	//v15
	  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1},	//v16
	  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},	//v17
	  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0},	//v18
	  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0},	//v19
	  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}, };	//v20

	std::vector<std::vector<double>> Labirynth2_Coordinates 
	{ { 16, 10 },		//v1
	  { 16, 35 },		//v2
	  { 16, 70 },		//v3
	  { 16, 90 },		//v4
	  { 32, 10 },		//v5
	  { 32, 35 },		//v6
	  { 32, 70 },		//v7
	  { 32, 90 },		//v8
	  { 48, 10 },		//v9
	  { 48, 35 },		//v10
	  { 48, 70 },		//v11
	  { 48, 90 },		//v12
	  { 64, 10 },		//v13
	  { 64, 35 },		//v14
	  { 64, 70 },		//v15
	  { 64, 90 },		//v16
	  { 80, 10 },		//v17
	  { 80, 35 },		//v18
	  { 80, 70 },		//v19
	  { 80, 90 }};		//v20
	

	//ShowLabirynth(Labirynth1_Coordinates, Labirynth_1);
	ShowLabirynth(Labirynth2_Coordinates, Labirynth_2);

	//DFS(Labirynth_1, Start, Finish, Labirynth1_Coordinates);
	DFS(Labirynth_2, Start, Finish, Labirynth2_Coordinates);

	
}

void DFS(int Labirynth[nodes][nodes], int Start, int Finish, std::vector<std::vector<double>> LabirynthCoordinates)
{
	int DeadEnd = 1;											//Set the flag of DeadEnd (If actual node is not dead end then the flag will be set to "0").
	std::vector<int> Path {Start - 1};							//First element of Path is of course Start.
	int Steps = 0;
	int input = 0;

	plt::Plot points("DFS", "r*");
	plt::Plot edges("DFS", "r");
	plt::Plot finish_points("DFS", "g*");
	plt::Plot finish_edges("DFS", "g");

	//Main loop of Depth First Search
	for (int i = Start - 1; i < nodes;) {						//Start analyzing graph from the defined Start point.
		int ifFinish = 0;
		DeadEnd = 1;											//Set the flag of DeadEnd (If actual node is not dead end then the flag will be set to "0".
		visited[i] = 1;											//Mark "i-ty wêze³" as visited 
		std::cout << "I am at node: " << i + 1 << std::endl;	//Tell me where you are

		for (int j = 0; j < (int)Path.size(); j++) {					//Tell me about path you've been through :P
			std::cout << Path.at(j) + 1 << "->";
		}

		std::cout << std::endl;

		if (i == Finish - 1) {
			ifFinish = 1;
			std::cout << "Found Finish point!" << std::endl;
			DrawThePath(ifFinish, Path, LabirynthCoordinates);
			finish_edges.update(x, y);
			finish_points.update(x, y);
			plt::pause(1);
			std::cout << "Nr of steps: " << Steps << std::endl;
			std::cout << "**********************" << std::endl;
			std::cin >> input;
		}
		else {
			DrawThePath(ifFinish, Path, LabirynthCoordinates);
			edges.update(x, y);
			points.update(visited_x, visited_y);
			plt::pause(1);
			for (int j = 0; j < nodes; j++) {
				if (Labirynth[i][j] == 1 && visited[j] == 0) {
					DeadEnd = 0;
					i = j;
					Path.push_back(j);
					break;
				}
			}

			if (DeadEnd == 1) {									//If DeadEnd == 1 - it means that there was no possible way or not yet visited option for actual position/node.
				Path.pop_back();								//Hence, delete actual node from path and:
				i = Path.back();								//Go back to previous node. -> Check possibilities again for previuous node.
			}
		}
		Steps++;
		std::cout << "Nr of steps: " << Steps << std::endl;
		std::cout << "**********************" << std::endl;
	}
}


double DrawThePath(int ifFinish, std::vector<int> Path, std::vector<std::vector<double>> LabirynthCoordinates) {

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

void ShowLabirynth(std::vector<std::vector<double>> LabirynthCoordinates, int Labirynth[nodes][nodes])
{
	std::string NodeNameString[20] = { "v1", "v2", "v3", "v4", "v5", "v6", "v7", "v8", "v9", "v10", "v11", "v12", "v13", "v14", "v15", "v16", "v17", "v18", "v19", "v20"};
	std::vector<double> LabirynthCoordinates_x {LabirynthCoordinates[0][0]}, LabirynthCoordinates_y {LabirynthCoordinates[0][1]}, vEdge_x(2), vEdge_y(2);
	std::vector<double> NodeNameCoordinates_x {LabirynthCoordinates[0][0] - ANNOTATION_OFFSET}, NodeNameCoordinates_y{ LabirynthCoordinates[0][1] - ANNOTATION_OFFSET};

	plt::figure_size(1000, 700);
	plt::xlim(-1.0, 100.0);				//Set X axle start and end limits.
	plt::ylim(-1.0, 100.0);				//Set Y axle start and end limits.

	/* Defining annotation coordinates and passing vrtexes (nodes) coordinates to vector, beacuse function "plt::scatter" needs vectors as parameters. */
	for (int i = 1; i < nodes; i++) {
		NodeNameCoordinates_x.push_back(LabirynthCoordinates[i][0] - ANNOTATION_OFFSET);
		NodeNameCoordinates_y.push_back(LabirynthCoordinates[i][1] - ANNOTATION_OFFSET);
		LabirynthCoordinates_x.push_back(LabirynthCoordinates[i][0]);
		LabirynthCoordinates_y.push_back(LabirynthCoordinates[i][1]);
	}

	//Pass coordinates to vectors and plot the edges one by one of labirynth nr 1.
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
		//plt::scatter(LabirynthCoordinates_x, LabirynthCoordinates_y, 10);
		plt::annotate(NodeNameString[i], NodeNameCoordinates_x.at(i), NodeNameCoordinates_y.at(i));
	}
}


