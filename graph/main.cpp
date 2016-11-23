#include "my_graph.h"
#include <iostream>

using namespace std;

int main(){
	
	vector<int> start, end, adjacent; 
	
	start.push_back(1);	start.push_back(1); start.push_back(1);	start.push_back(5); start.push_back(5); start.push_back(4);
	
	  end.push_back(2);   end.push_back(3);   end.push_back(4);   end.push_back(4);   end.push_back(2);   end.push_back(2);
	
	Graph grafo(start, end);
	
	cout<<"\nnumber of outgoing edges: "<<grafo.numOutgoing(5)<<"\n\n";
	adjacent = grafo.adjacent(5);
	
	cout<<"\nThe adjacent elements of 2 are: \n\n";
	int i=0;
	while(i<adjacent.size()){
		cout<<adjacent[i]<<" ";
		i++;
	}
	cout<<'\n';

	return 0;
}