/*
In this programming problem and the next you'll code up the knapsack algorithm from lecture. Let's start with a warm-up. Download the text file here. This file describes a knapsack instance, and it has the following format:
[knapsack_size][number_of_items]
[value_1] [weight_1]
[value_2] [weight_2]
...
For example, the third line of the file is "50074 659", indicating that the second item has value 50074 and size 659, respectively.

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

 int main()
 {
   ifstream myfile("knap.txt");
   int sackSize,nItems;
   long long value,weight;
   myfile >> size >> numItems;
   priority_queue< pair < long long, long long > > items;
   while(scanf("%lld %lld ", &value, &weight) != -1)
   {
      items.push_back(make_pair(value,weight));
   }
   int knapSackMatrix[nItems+1][sackSize+1];
   for(int i = 0; i <=  nItems ; i++)
   {
    for(int j = 0; j <= sackSize ; j++)
    {
      if(i==0 || j == 0)
                knapSackMatrix[i][j] = 0;
      else if(j - items[i].second  <= 0)
                knapSackMatrix[i][j] = max(knapSackMatrix[i-1][j],knapSackMatrix[i-1][j - items[i].second] + items[i].first);
      else      knapSackMatrix[i][j] = knapSackMatrix[i-1][j];
    }
  }
  cout <<"The optimal value for the knapsack problem is : " << knapsackMatrix[nItems][sackSize] << endl;
  return 0;
 }

