#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;




typedef vector < vector <int> > adj;


int oddvertexIndex[1];
	
void filetoArray(adj&);
void fleuryAlgorithm(adj&, const int &);
bool eulerTest(adj, int []);
bool bridgeTest(adj, int);	 
 
 main()
{
	
	adj adjacencyMatrix;
	bool testContainer;
	
	
	
	filetoArray(adjacencyMatrix);
	
	

		cout << "Make sure to leave spaces between the numbers in the file being processed to prevent any issues." << endl;
		cout << "IE:" << endl;

		

		

					
				
							
			
		for (int i = 0; i<adjacencyMatrix.size(); i++){

			for (int j = 0; j< adjacencyMatrix.size(); j++){
						
				cout << "X ";
						
			}
			cout << "\n";
		}		

	
			
	//initialize values of odd vertex index
			for (int i=0; i <2; i++){
				oddvertexIndex[i]=0;
			}
		
	//	cout << "\nThe number of columns in this matrix is "<< adjacencyMatrix[0].size()<<endl;

	



		testContainer=eulerTest(adjacencyMatrix, oddvertexIndex );
		//This portion of code confirms a properly working euler Test.
		//cout << "\nThe value of the euler Test is: "<< testContainer<<endl;//According to the logic of the euler test a graph is eulerian if and only if there exist even degree count for all vertices or exactly two vertices are of odd degree count.
		/*
		//Test the values in array containing indices that are odd
		for(int i =0; i <2; i++){
			cout<<oddvertexIndex[i]<<" ";
		}*/


		int degreeCount[adjacencyMatrix[0].size()];
		
		for (int i=0; i < adjacencyMatrix[0].size(); i++)
			degreeCount[i]=0;//Initialize global array degreeCount
	

		for (int i = 0; i < adjacencyMatrix.size(); i++){
					
			for(int j = 0; j < adjacencyMatrix.size(); j++)		
				degreeCount[j] += adjacencyMatrix[i][j];
							
		}
						
		
			for (int i=0; i < adjacencyMatrix[0].size(); i++)
				cout << degreeCount[i];	
					cout <<endl;
				/*
				for (int i=0; i < 2; i++)
					cout << oddvertexIndex[i];
*/
        //Logical Test for Euler test. Everything Looks correct as of July 7, 2021.

		if (testContainer)
			cout << "True"<<endl;
		
		if (testContainer){
			//Apply fleury algorithm with vector as well as the array of the existence of odd vertices
			fleuryAlgorithm(adjacencyMatrix, oddvertexIndex); 
		}	
		else 
		cout << "\nThe adjacency matrix read has no EULARIAN TRAIL"<<endl;	
		


	return 0;   
} //end of main



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
			/* Print contents of adjacency matrix once	
		 for (int i = 0; i < dummyVector.size(); i++){
					
						for(int j = 0; j < dummyVector[i].size(); j++)		
						{
						
								 cout << dummyVector[i][j]<<" ";
								// cout<< endl;
							}
							cout << "\n";
							}		*/	
			
			txtFile.close();
	}

bool eulerTest(adj dummyVector,   int odd [])
{
	bool test;
	int flag=0;
	//initializes an array equal to the number of columns in matrix
	int degreeCount[dummyVector[0].size()];

	
	//fixes glitch in array previously found
	for (int i=0; i < dummyVector[0].size(); i++)
		degreeCount[i]=0;
	
	for (int i = 0; i < dummyVector.size(); i++){
					
			for(int j = 0; j < dummyVector.size(); j++)		
				degreeCount[j] += dummyVector[i][j];
							
	}
							
		//finds degree count of each row and tallies up the amount in array
		//only if odd
		for (int i=0; i < dummyVector[0].size(); i++){
	
		if (degreeCount[i] %2 !=0){
			//TODO: Logical Error Here 
			odd[flag]=i;
			flag++;
			
		}
		
		}


			//tests to see if all vertices of even degree 
		//or if exactly two vertices are of odd degree
		//

			if (flag == 0 || flag == 2)
				return (true);
			else
				return (false);
	
	

						
}

void fleuryAlgorithm(adj& dummyVector,  const int( & odd)){
	//initialize vertex
	int currentVertex;
	int sumDegree=0;
	int edgeCount= sumDegree/2;
	//cout << edgeCount << endl;//TODO: Contents of edgecount = zero due to null sumDegree; Must accumulate the degree of the vertex current.
	//int currentTrail[edgeCount];//TODO: Double check correctness.
	vector <int> currentTrail;
	//set up random number generator
	srand(time(NULL));
	
	//choose a random number based on the number of vertices in the array
	currentVertex = rand() % (dummyVector.size() + 1);
	
	//test random vertex chosen should show a different vertex every time program is ran
	cout << "Everytime you run this program you should get a different number" <<"\nVertex Number chosen:"<< currentVertex <<endl;
	
	//initialize current trail
	
	//test random vertex chosen given correct contents
	cout <<"Contents of vertex chosen:\n"<<endl;
	
	for (int i = 0; i < dummyVector.size(); i++){
		if (dummyVector[i][currentVertex] == 1){
			cout << "Vertex "<<currentVertex  << " Connects to Vertex "<< i  <<endl;
 
		}	
		
	}	
		
cout << "\n";
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

	//TODO: ISOLATE AND PACKAGE ODD DEGREE TEST INTO INDEPENDENT METHOD AS OF 7/8/2021: Test for two odd degree vertices is done inside of euler test && Fleury Algorithm method.
	else if (odd[0] && odd[1])
	{
		for (int i = 0; i < dummyVector.size(); i++){
					
			for(int j = 0; j < dummyVector.size(); j++)		
				dummyVector[i][j];
		}						

	
	
}
}
//Incomplete, idea was to use a depth first search 
//TODO: Depth First search can be implemented using a stack.
//

bool bridgeTest(adj& dummyVector, int vertex)
{

	
	for (int i = 0; i < dummyVector.size(); i++){
					
			for(int j = 0; j < dummyVector.size(); j++)		
				dummyVector[i][vertex];
	}

}//end of bridgeTest

void depthFirstSearch (adj& dummyVector, int vertex ){
	//Vector Stack Ops: vectorStack.push_back()//push element onto stack
	//                  vectorStack.pop_pack()//pop an element off the stack
	//                  vectorStack.back()//return value of top element




	bool visited[dummyVector.size()];//Declare size of visited nodes

	int currentVertex;
	vector <int> vectorStack ; // declare vector to be used as stack 

	vectorStack.push_back(vertex);

	//Iterate until stack is empty
	while(vectorStack.size() !=0){

		currentVertex = vectorStack.pop_back();//TODO: check here
		if (currentVertex != vistited[currentVertex])
			vistited[currentVertex] = true;//set visited vertex in array to true
			for(all edges from vertex to w in dummyVector.adjacent(v)){
				vectorStack.push_back(w);
			}

	}


}