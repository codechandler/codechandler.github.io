
#include "graph.h"
#include "vertex.h"
#include "list.h"
#include "set.h"
#include "vector.h"
#include "queue.h"
using namespace std;

Graph :: Graph(const Graph & rhs) throw (const char *)
{   
   try 
   {
      *this = rhs;
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate memory for the graph";
   }
}

Graph & Graph :: operator = (const Graph & rhs) throw (const char *)
{
	// if nothing, rhs is invalid
	if (rhs.numVertices == 0)
		return *this;
   numVertices = rhs.numVertices;
   int size = numVertices * numVertices;
   data = rhs.data;
   try
   {
      adjMatrix = new bool[size];
      for (int i = 0; i < size; i++)
         adjMatrix[i] = rhs.adjMatrix[i];
   }
   catch(std::bad_alloc)
   {
      throw "ERROR: Unable to allocate memory for the graph";
   }
   return *this;
}


void Graph :: add(const Vertex & v1, const Vertex & v2)
{
   // insert into the data set
   data.insert(v1);
   data.insert(v2);
   
   // add the edge: width * row + col
   adjMatrix[v1.index() * numVertices + v2.index()] = true;
}

void Graph :: add(const Vertex & v1, const Set <Vertex> & set)
{
   data.insert(v1);
   
   SetConstIterator <Vertex> it;   
   for (it = set.cbegin(); it != set.cend(); ++it)
   {
      data.insert(*it);
      int col = (*it).index();
      adjMatrix[v1.index() * numVertices + col] = true;
   }
}

bool Graph :: isEdge(const Vertex & v1, const Vertex & v2) const
{
   return adjMatrix[v1.index() * numVertices + v2.index()];
}

Set <Vertex> Graph :: findEdges(const Vertex & v1) const
{
   Set <Vertex> rSet;
   // iterate through data set
   SetConstIterator <Vertex> it;   
   for (it = data.cbegin(); it != data.cend(); ++it)
   {
      if (isEdge(v1, *it))
         rSet.insert(*it);
   }
   
   return rSet;
}

Vector <Vertex> Graph :: findPath(const Vertex & vFrom, const Vertex & vTo) const
{
	// create an array representing the shortest path to each item. Mark
	// the distance to vFrom as zero
	int distance = 0;

	int * distances = new int[numVertices];

	Vertex * predecessor = new Vertex[numVertices];

	for (int i = 0; i < numVertices; i++)

		distances[i] = -1;

	distances[vFrom.index()] = distance;

	// create a queue of the ones to visit. Start with vFrom

	Queue <Vertex> toVisit;

	toVisit.push(vFrom);

	// while we have not found the destination and the list of places

	// we still have to go is not empty

	while (!toVisit.empty() && distances[vTo.index()] == -1)

	{

		// grab the next item off the head of the queue

		Vertex v = toVisit.front();

		toVisit.pop();

		// increment the distance as necessary

		if (distances[v.index()] > distance)

			distance++;

		// go through all the edges and add them as necessary

		Set <Vertex> s(findEdges(v));

		for (SetConstIterator <Vertex> it = s.cbegin(); it != s.cend(); ++it)

			if (distances[(*it).index()] == -1)

			{
				distances[(*it).index()] = distance + 1;
				predecessor[(*it).index()] = v;
				toVisit.push((*it));
			}

	}

	distance++;

	// now reconstruct the shortest path

	Vector <Vertex> path(distance + 1);

	if (distances[vTo.index()] == -1)

	{
		cout << "No path found\n";
		return path;
	}

	path.push_back(vTo);

	for (int i = 1; i <= distance; i++)

		path.push_back(predecessor[path[i - 1].index()]);

	delete[] distances;
	delete[] predecessor;
	return path;
}
