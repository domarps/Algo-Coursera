/*
  In this programming problem and the next you'll code up the greedy algorithms from lecture for minimizing the weighted sum    of completion times.. Download the text file here. This file describes a set of jobs with positive and integral weights and   lengths. It has the format :
   [number_of_jobs]
   [job_1_weight] [job_1_length]
   [job_2_weight] [job_2_length]
   .....
   
  Greedy algorithm implementation that schedules jobs in decreasing order of the difference (weight - length).
  
  Author : domarps <-> Pramod S
*/  

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() 
{
   int numJobs;
   pair<int,int> wl;  //weight length tuple
   pair<double, pair<int,int> > item;
   ifstream myfile("wl.txt");
   myfile >> numJobs;
   priority_queue<pair<double,pair<int,int> > > heap ;
   
   for(int i = 0; i < numJobs ; i++)
   {
     
      myfile >> wl.first >> wl.second;
      double diff = wl.first -  wl.second;
      item.first = diff;
      item.second = wl;
      heap.push(item);
   }

   int elapsedDuration = 0;
   double minWeightSum = 0;
   while(!heap.empty())
   {
          item         = heap.top();
          int weight   = item.second.first;
          int length   = item.second.second;
          minWeightSum  += weight *(length + elapsed_duration);
          elapsedDuration+= length;
          heap.pop();
   }
   cout<<std::fixed<<min_wt_sum<<endl;   
}
