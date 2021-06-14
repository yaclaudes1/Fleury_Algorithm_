#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <ctime>
using namespace std;




typedef vector < vector <int> > adj;
int oddvertexIndex[1];
	
void filetoArray(adj&);
void fleuryAlgorithm(adj, const int[]);
bool eulerTest(adj&, int []);
bool bridgeTest(adj, int);	 
 
 main()
{
	
	adj adjacencyMatrix;
	bool testContainer;
	
	
	
	filetoArray(adjacencyMatrix);
	
	

		cout << "Make sure to leave spaces between the numbers in the file being processed to prevent any issues." << endl;
		cout << "IE:" << endl;
		cout << "X X X X" << endl;
		cout << "X X X X" << endl;
		cout << "X X X X" << endl;
		cout << "X X X X" << endl;
		cout << "Deuces " << endl;
		
		
			for (int i=0; i <2; i++)
		oddvertexIndex[i]=0;
		
		
		cout << "The number of columns in this matrix is "<< adjacencyMatrix[0].size()<<endl;
		testContainer=eulerTest(adjacencyMatrix, oddvertexIndex );
		cout << "the value of the eulerTest is: "<< testContainer<<endl;
		
		for(int i =0; i <2; i++)
		cout<<oddvertexIndex[i]<<" ";
		
		int columnAdder[adjacencyMatrix[0].size()];
		
		for (int i=0; i < adjacencyMatrix[0].size(); i++)
			columnAdder[i]=0;
	
	for (int i = 0; i < adjacencyMatrix.size(); i++){
					
			for(int j = 0; j < adjacencyMatrix.size(); j++)		
				columnAdder[j] += adjacencyMatrix[i][j];
							
	}
						
		
			for (int i=0; i < adjacencyMatrix[0].size(); i++)
				cout << columnAdder[i];	
					cout <<endl;
				for (int i=0; i < 2; i++)
				cout << oddvertexIndex[i];
		if (testContainer){
			//Apply fleury algorithm with vector as well as the array of the existence of odd vertices
			fleuryAlgorithm(adjacencyMatrix, oddvertexIndex); 
		}	
		else
		cout << "\nThe adjacency matrix read has no EULARIAN TRAIL"<<endl;	
		
	return 0;   
} 

//grab contents of file and place in two-dimensional vector

void filetoArray(adj& dummyVector){

	int intContainer=0;
    
	int lineCount=0;
	ifstream txtFile;
	txtFile.open("file2.txt");//file must be in the same folder as source code
	if (!txtFile)
		cout << "Error opening data file \n";
	else
		{
		
			
				
			string line;
		
			while (getline(txtFile, line)){
				
					
				stringstream ss(line);
				vector <int> row;
					while (ss >> intContainer)	{
					
						row.push_back(intContainer);
						
				}
			
			dummyVector.push_back(row);	
				
					
		}	
			
		 }
					
		 for (int i = 0; i < dummyVector.size(); i++){
					
						for(int j = 0; j < dummyVector[i].size(); j++)		
						{
						
								 cout << dummyVector[i][j]<<" ";
								// cout<< endl;
							}
							cout << "\n";
							}			
			
			txtFile.close();
	}

bool eulerTest(adj& dummyVector,  int odd[])
{
	bool test;
	int flag=0;
	//initializes an array equal to the number of columns in matrix
	int columnAdder[dummyVector[0].size()];

	
	//fixes glitch in array previously found
	for (int i=0; i < dummyVector[0].size(); i++)
		columnAdder[i]=0;
	
	for (int i = 0; i < dummyVector.size(); i++){
					
			for(int j = 0; j < dummyVector.size(); j++)		
				columnAdder[j] += dummyVector[i][j];
							
	}
							
		//finds degree count of each row and tallies up the amount in array
		//only if odd
		for (int i=0; i < dummyVector[0].size(); i++){
	
		if (columnAdder[i] %2 !=0){
			
			odd[flag]=i;
			flag++;
			
		}
		//tests to see if all vertices of even degree 
		//or if exactly two vertices are of odd degree
		}	
			if (flag == 0 || flag == 2)
				return (true);
			else
				return (false);
	
	

						
}
//const
void fleuryAlgorithm(adj dummyVector, const int odd[]){
	//initialize vertex
	int currentVertex;
	int sumDegree=0;
	int edgeCount= sumDegree/2;
	
	//set up random number generator
	srand(time(NULL));
	
	//choose a random number based on the number of vertices in the array
	currentVertex = rand() % (dummyVector.size() + 1);
	
	//test random vertex chosen should show a different vertex every time program is ran
	cout << "Everytime you run this program you should get a different number" << currentVertex<<endl;
	
	//initialize current trail
	vector <int> currentTrail;
	//test random vertex chosen given correct contents
	cout <<"contents of vertex chosen"<<endl;
	
	for (int i = 0; i < dummyVector.size(); i++)	
		cout << dummyVector[i][currentVertex]<<"";
		
		

//in other words all vertices are of even degree via Euler 
	if (odd[0]==0 && odd[1]==0)
	{
		for (int i = 0; i < dummyVector.size(); i++){
					
			for(int j = 0; j < dummyVector.size(); j++)		
				dummyVector[i][currentVertex];
		}
	}
	//if there are exactly two vertices of odd degree
	//we start at either of those vertices
	else if (odd[0] && odd[1])
	{
		for (int i = 0; i < dummyVector.size(); i++){
					
			for(int j = 0; j < dummyVector.size(); j++)		
				dummyVector[i][j];
		}						

	
	
}
}
//Incomplete, idea was to use a depth first search 
//Depth First search can be implemented using a stack.

bool bridgeTest(adj dummyVector, int vertex)
{
	
	for (int i = 0; i < dummyVector.size(); i++){
					
			for(int j = 0; j < dummyVector.size(); j++)		
				dummyVector[i][vertex];
}
}
