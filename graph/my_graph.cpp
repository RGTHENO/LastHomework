#include <stdexcept>
#include "my_graph.h"
using namespace std;

/*********************************** Directed Graph ********************************************/

Graph::Graph(const vector<int> &startPoints, const vector<int> &endPoints){

	if(startPoints.size() != endPoints.size()){
		throw invalid_argument("\n\nLos vectores difieren en tamanio\n\n");
	
	}
	
	for(int i=0; i<startPoints.size(); i++){
		int start = startPoints[i], end= endPoints[i];
		outgoing[start].push_back(end);
		outgoing[end]; //Permite hacer que el nodo exista, sin embargo su valor mapeado es asignado por default
		
		/** Remember that "operator[]" If k matches the key of an element in the container,
		 * the function returns a reference to its mapped value. OJO: If the key doesnt exist
		 * inserts a new element in the map with that key and initialized to its default value
		**/
	}
}

int Graph::numOutgoing(const int nodeID) const{
	return adjacent(nodeID).size();
}

const vector<int> &Graph::adjacent(const int nodeID) const{
		map<int, vector<int> >::const_iterator i = outgoing.find(nodeID);
		
		/** "find()" --> Searches the container for an element with a key equivalent to k
		 *  and returns an iterator to it if found, otherwise it returns an 
		 *  iterator to map::end.   **/
		 
		 /** OJO!: If the map object is const-qualified, the function returns a
		  *  const_iterator. Otherwise, it returns an iterator**/
		 
		if(i==outgoing.end() ){  /** "end()" --> Returns an iterator referring to the 
								 *	  past-the-end element in the map container.      
								 *    It does not point to any element, and thus shall not be dereferenced.
								 *    **/
			throw invalid_argument("Invalid node ID");
		}
		
		return i->second; 
		/** a std::map<X, Y> stores a whole bunch of std::pair<const X, Y>
		 * When you dereference one of these iterators, you get a std::pair containing the key and its associated value.
		 * you can then access its elements with first and second
		 * (*it).first or it->first will give you the key and (*it).second or  it->second will give you the value
		 **/

}