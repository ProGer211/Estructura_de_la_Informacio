// Heapify a subtree rooted with node i which is an index in arr[]
void maxHeapify(std::vector<Phone>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].frequencia() > arr[largest].frequencia())
        largest = left;

    if (right < n && arr[right].frequencia() > arr[largest].frequencia())
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Build a max heap
void buildMaxHeap(std::vector<Phone>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

// Heap sort
void heapSort(std::vector<Phone>& arr) {
    int n = arr.size();

    // Build max heap
    buildMaxHeap(arr);

    // Extract elements from the heap in decreasing order of frequency
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

// Function to sort the vector by frequency using heap sort
void sortByFrequency(std::vector<Phone>& arr) {
    heapSort(arr);
}


