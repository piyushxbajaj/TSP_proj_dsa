#include <iostream>
#include <cstdlib>
using namespace std;

int queue[100], stack[100], alt[100], v[100];
int sp,head,tail,i,n,g,j,s,path,weight,weight_matrix[4][4];

int main()
{
  cout<<"Number of cities:";
  cin>>n;
  cout<<"Max weight:";
  cin>>weight;
  srand(0);

// Generating the connection matrix randomly
 for (i=0; i<n;i++) {
    for (j=i+1;j<n;j++) {
       weight_matrix[i][j]= rand() % (weight+1);
       weight_matrix[j][i]=weight_matrix[i][j]+ rand() % (weight+1);
      }
    for (j=0;j<n;j++) cout<<weight_matrix[i][j]<<" ";
    cout<<endl;
  }
//Start with an initial solution from city 1
 for (i=0 ; i<n ; i++) {
    queue[i]=i;
  }

// Set route length to high value
   path=weight*n;
   stack[0]=queue[0];
   alt[0]=0;
   sp=0;
   head=0;
   tail=n-1;
   s=0;

// Explore a branch of the factorial tree
   while(1) {
      while(sp<n-1 && s<path)  {
          sp++;
          head++; if (head==n) head=0;
          stack[sp]=queue[head];
          s=s+weight_matrix[stack[sp]][stack[sp-1]];
          alt[sp]=n-sp-1;
       }

// Save a better solution
      if (s+weight_matrix[stack[sp]][stack[0]]<path) {
        path=s+weight_matrix[stack[sp]][stack[0]];
        for (i=0 ; i<n ; i++)
            v[i]=stack[i]+1;
      }

// Leaving nodes when there is no more  branches
      while (alt[sp]==0 && sp>=0) {
        tail++; if (tail==n) tail=0;
        queue[tail]=stack[sp];
        s=s-weight_matrix[stack[sp]][stack[sp-1]];
        sp--;
      }

// If Bottom of stack is reached then stop
      if (sp<0) break;
      tail++; if (tail==n) tail=0;
      queue[tail]=stack[sp];
      s=s-weight_matrix[stack[sp]][stack[sp-1]];

// Explore an alternate branch
      alt[sp]=alt[sp]-1;
      head++; if (head==n) head=0;
      stack[sp]=queue[head];
      s=s+weight_matrix[stack[sp]][stack[sp-1]];
  }

  cout<<"best route: "<<path<<endl;
  for (i=0 ; i<n ; i++) cout<<v[i]<<"-->";
  cout<<stack[0]+1<<endl;
  return 0;
}
