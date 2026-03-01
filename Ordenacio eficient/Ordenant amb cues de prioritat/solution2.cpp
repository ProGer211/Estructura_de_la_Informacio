#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

// Function to heapify a subtree rooted with node i which is an index in arr[]
void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < n && arr[left] < arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] < arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        maxHeapify(arr, n, largest);
    }
}

// Function to build a max heap


// Function to perform the sorting based on frequency using Max Heap
void sortByFrequency(vector<int>& arr) {
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    // Extract elements from the heap in decreasing order of frequency
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
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
sortByFrequency(v1);   

for(int i = 0;i<v1.size();i++)
  {
  cout << v1[i] << " ";
  }
  cout << endl;
  
 

}
