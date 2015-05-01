/*
In this programming problem and the next you'll code up the clustering algorithm from lecture for computing a max-spacing k-clustering. Download the text file here. This file describes a distance function (equivalently, a complete graph with edge costs). It has the following format:
[number_of_nodes]
[edge 1 node 1] [edge 1 node 2] [edge 1 cost]
[edge 2 node 1] [edge 2 node 2] [edge 2 cost]
...
The clustering algorithm, where the target number k of clusters is set to 4. What is the maximum spacing of a 4-clustering?
*/
// The usual Hashtags
#include<new>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<strstream>

// The Hashtags for Data Structure 

#include<map>
#include<set>
#include<list>
#include<stack>
#include<deque>
#include<queue>
#include<vector>
#include<bitset>
#include<string>
#include<iterator>
#include<algorithm>

// Standard Namespace Inclusion
using namespace std;

int nClusters;
int *leader;
int *fellowship;

int findRoot(int vertex)
{
   while(vertex != leader[vertex])
       vertex = leader[vertex];
   return vertex;
}

bool isConnected(int f1 , int f2){

    // just check if the leaders of these 2 followers are same 
    return findRoot(f1) == findRoot(f2); // Haha, I am too lazy to figure it out here.
}

int mergeComponents(int f1 , int v2)
{
    --nClusters; // Towards our goal of K clusters

    int root1 = findRoot(f1);
    int root2 = findRoot(f2);

    if( fellowship[root1] > fellowship[root2] )
	{
        leader[root2] = root1; //always surrender oneself to the bigger group.
        fellowship[root1] += fellowship[root2];
    }
    else
	{
        fellowship[root1] = root2;
        leader[root2] += leader[root1];
    }
}

int main() 
{
   int numPoints;
   long long edgeWeight,node1,node2;
   
   ifstream myfile("kcluster.txt");
 
   priority_queue<pair<int,pair<int,int> > > vevPairs;    // Vertex1 --- Edge --- Vertex2 
   myfile >> numPoints;
   
   leader     = (int*)malloc(sizeof(int) * (numPoints + 1));  // each vertex has the potential to lead
   fellowship = (int*)malloc(sizeof(int) * (numPoints + 1));  // each vertex has to keep count of its followers
   
   for(int i = 1 ; i <= numPoints; i++)
   {
       leader = i; fellowship = 1; // to begin leading, first lead yourself. Your fellowship starts from 1.
   }
 
   while( scanf("%lld %lld %lld" , &node1 , &node2 , &edgeWeight) != -1 )
   {
        vevPairs.push_back( make_pair( edgeWeight , make_pair( node1 , node2 )) ) ;
   }
   
   sort(vevPairs);   //Sorting to get the closes points upfront.
   
   //Clustering Begins Here
   for(int i = 0; i < vevPairs.size() ; i++)
   {
      if(nClusters == 4) break;
	  if(!isConnected(vevPairs[i].second.first,vevPairs[i].second.second))
	  {
	     mergeComponents(vevPairs[i].second.first,vevPairs[i].second.second);
	  }
   }
   long long maxSpacing;
   for(int j = 0; j < vevPairs.size() ; j++)
   {
       if(!isConnected(vevPairs[i].second.first,vevPairs[i].second.second))
	   {
	      maxSpacing = vevPairs[i].first;
		  break;
	   }
   } 
   cout << "The max-spacing of 4 clustering is : " << maxSpacing << endl;
   return 0;  
}
