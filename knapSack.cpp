#include<stdio.h> 
#include<math.h>
#include<iostream>
#include<fstream>
using namespace std;

int max(int a,int b) {  return (a>b) ?  a :  b; }
int knapsack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];
 
   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= W)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
   for(i=0;i<=n;i++) 
   {
    for(w=0;w<=W;w++)
    {
     cout<<K[i][w]<<" ";
    }
     cout<<"\n";
   }
   return K[n][W];
}
  
int main()
{

  int W,n;
  ifstream f;
  f.open("knap.txt");
  f >> W >> n;
  cout<<W<<' '<<n<<endl;
  int wt[n];
  int val[n];
  int i=0;
  while(i<n)
  { 
    f >> wt[i] >> val[i];  
    cout<< i <<" "<< wt[i] <<" "<<" "<< val[i]<<"\n ";
    i++;
  }
  cout<<"Solution to the Knapsack problem , Optimal "<<knapsack(W,wt,val,n);
}
  
