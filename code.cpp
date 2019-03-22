
//------------------------------------dynamic programming---------------
#include<iostream>

//Created by Piyush,Vandit and Abhishek
// importing the  input output header
 
using namespace std;
 
int ary[10][10],completed[10],n,cost=0;
//Declaring the 2D array and the data 

//Declaring the input funciton for the cost matrix and this will decrease the cost of the trip.
void takeInput()
{
	int i,j;
 
	cout<<"Enter the number of villages: ";
	cin>>n;
 
	cout<<"\nEnter the Cost Matrix\n";
 	//Running the for loop to get the matrix of the relative costs.
	for(i=0;i < n;i++)
	{
		cout<<"\nEnter Elements of Row: "<<i+1<<"\n";
 
		for( j=0;j < n;j++)
			cin>>ary[i][j];
 
		completed[i]=0;
	}
	//While also keeping a count of completed nodes.
 
	cout<<"\n\nThe cost list is:";


 	//Displaying the cost list to get the cost idea matrix
	for( i=0;i < n;i++)
	{
		cout<<"\n";
 
		for(j=0;j < n;j++)
			cout<<"\t"<<ary[i][j];
	}
}
 
 //Now least km will be calculated using the data entered.
int least(int c)
{
	int i,nc=999;
	int min=999,kmin;
 
	for(i=0;i < n;i++)
	{
		if((ary[c][i]!=0)&&(completed[i]==0))
			if(ary[c][i]+ary[i][c] < min)
			{
				min=ary[i][0]+ary[c][i];
				kmin=ary[c][i];
				nc=i;
			}
	}
 
	if(min!=999)
		cost+=kmin;
 
	return nc;
}
 //mincost() func created for finding out the way to calculate the minimum cost
void mincost(int city)
{
	int i,ncity;
 
	completed[city]=1;
 
	cout<<city+1<<"--->";
	ncity=least(city);
 
	if(ncity==999)
	{
		ncity=0;
		cout<<ncity+1;
		cost+=ary[city][ncity];
 
		return;
	}
 
	mincost(ncity);
}

//Calling all the necessary functions to solve the travelling salesman problem 
int main()
{
	takeInput();
 
	cout<<"\n\nThe Path is:\n";
	mincost(0); //passing 0 because starting vertex
 
	cout<<"\n\nMinimum cost is "<<cost;
 
	return 0;
}