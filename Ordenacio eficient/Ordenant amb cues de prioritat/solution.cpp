#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;


void enfosar(int i,vector<int> &v1,int size)
{
int j = (2*i) + 1;
 if(size != 0 and j + 1 < size)
 {
 	if(v1[j] >= v1[j+1] and v1[i] < v1[j])
 	{
 	swap(v1[j],v1[i]);
 	enfosar(j,v1,size);
	}
 	else if(v1[j] < v1[j+1] and v1[i] < v1[j + 1])
 	{
 	swap(v1[j+1],v1[i]);
 	enfosar(j + 1,v1,size);
 	}
 }
 else if(j< size and j + 1 >= size)
 {
 	if(v1[i] < v1[j]) 
 	{
 	swap(v1[j],v1[i]);
 	enfosar(j,v1,size);
 	}
 
 }

}

void heapsort(vector<int> &v1)
{
int n = v1.size();
for(int i = 0;i<v1.size();i++)
{
swap(v1[n - 1],v1[0]);
n--;
enfosar(0,v1,n);
}
}


int main()
{
int n;
string linea;
vector<int> v1;
getline(cin, linea);
istringstream ss1(linea);
  while (ss1 >> n) {
    v1.push_back(n);
 }
 if(v1.size() == 0) return 0;
 for(int i = (v1.size() - 2) / 2;i >= 0;i--)
 {
 enfosar(i,v1,v1.size());
 }
  heapsort(v1);
  for(int i = 0;i<v1.size() - 1;i++)
  {
  cout << v1[i] << " ";
  }
  cout << v1[v1.size() - 1] << endl;
  
  
  for(int i = v1.size()-1;i>0;i--)
  {
  cout<< v1[i] << " ";
  }
  cout << v1[0] << endl;
}


