#include <iostream>
#include <ctime>
#include <cstdlib>
#include<iomanip>
#include<math.h>
#include<fstream>

using namespace std;
int *ins_el;
int *bubble_el;
int *sel_el;
int *heap_el;
int *quick_el;
int *merge_el;

void insertionSort(int n)
{
int i, j;
int temp;
for (i = 1; i <= n; i++)
{
temp = ins_el[i];
j = i - 1;
while (j > 0 && ins_el[j] > temp)
{
ins_el[j + 1] = ins_el[j];
j = j - 1;
}
ins_el[j + 1] = temp;
}
}

void bubbleSort(int n)
{
int i, j;
for (i = 0; i < n - 1; i++)
{

for (j = 0; j < n - i - 1; j++)

{

if (bubble_el[j] > bubble_el[j + 1])

{

int t = bubble_el[j];

bubble_el[j] = bubble_el[j + 1];

bubble_el[j + 1] = t;

}

}

}

}

void selectionSort(int n)
{
int i, j;
for (i = 0; i < n; i++)
{
for (j = i; j < n; j++)
{
if (sel_el[i] > sel_el[j])
{
int temp = sel_el[i];
sel_el[i] = sel_el[j];
sel_el[j] = temp;
}
}
}
}

void heapify(int n, int i)
{
int largest = i;
int l = 2 * i + 1;
int r = 2 * i + 2;
if (l < n && heap_el[l] > heap_el[largest])
largest = l;
if (r < n && heap_el[r] > heap_el[largest])
largest = r;
if (largest != i)

{

int temp = heap_el[i];

heap_el[i] = heap_el[largest];

heap_el[largest] = temp;

heapify(n, largest);

}

}

void heapSort(int n)
{
int i = 0;
for (i = n; i >= 0; i--)
heapify(n, i);
for (i = n; i > 0; i--)

{
int temp = heap_el[0];
heap_el[0] = heap_el[i];
heap_el[i] = temp;
heapify(i, 0);
}
}

int partition(int low, int high)
{
int pivot = quick_el[high];
int i = (low - 1), j;
for (j = low; j <= high - 1; j++)
{
if (quick_el[j] <= pivot)
{
i++;
int temp = quick_el[i];
quick_el[i] = quick_el[j];
quick_el[j] = temp;
}
}

int temp = quick_el[i + 1];
quick_el[i + 1] = quick_el[high];
quick_el[high] = temp;
return (i + 1);
}

void quickSort(int low, int high)
{
if (low < high)
{
int pi = partition(low, high);
quickSort(low, pi - 1);
quickSort(pi + 1, high);
}
}

void merge(int l, int m, int r)
{
int i, j, k;
int n1 = m - l + 1;
int n2 = r - m;
/* create temp arrays */
int *L = new int[n1];
int *R = new int[n2];
/* Copy data to temp arrays L[] and R[] */
for (i = 0; i < n1; i++)
L[i] = merge_el[l + i];
for (j = 0; j < n2; j++)
R[j] = merge_el[m + 1 + j];
/* Merge the temp arrays back into arr[l..r]*/
i = 0; // Initial index of first subarray
j = 0; // Initial index of second subarray
k = l; // Initial index of merged subarray
while (i < n1 && j < n2)
{
if (L[i] <= R[j])
{
merge_el[k] = L[i];
i++;
}
else
{
merge_el[k] = R[j];
j++;
}
k++;
}

while (i < n1)
{
merge_el[k] = L[i];
i++;
k++;
}
while (j < n2)
{
merge_el[k] = R[j];
j++;
k++;
}
}

void mergeSort(int l, int r)
{
if (l < r)
{
int m = l + (r - l) / 2;
// Sort first and second halves
mergeSort(l, m);
mergeSort(m + 1, r);
merge(l, m, r);

}

}
 ///// ************************MAIN*******************/////
int main()
{
	ofstream fout;
	fout.open(" suva.txt");
srand(time(NULL));

cout << left << setw(20) << "Data Size"
<< setw(15) << "Heap Sort"
<< setw(15) <<"Merge Sort"
<< setw(15) << "Quick Sort"
<< setw(15) << "Bubble Sort"
<< setw(15) <<"Selection Sort"
<< setw(16) << "Insertion Sort"
<< endl;
fout << left << setw(20) << "Data Size"
<< setw(15)<< "Heap Sort"
<< setw(15) <<"Merge Sort"
<< setw(15) <<"Quick Sort"
<< setw(15) << "Bubble Sort"
<< setw(15) << "Selection Sort"
<< setw(16) <<"Insertion Sort"
<< endl;
int rand_val;

/**Loop for 10000 to 120000*/

for (int i = 10000; i <= 120000; i += 20000)

{
ins_el = new int[i];
bubble_el = new int[i];
sel_el = new int[i];
heap_el = new int[i];
quick_el = new int[i];
merge_el = new int[i];
for (int j = 0; j < i; j++)

{
rand_val = rand() % 100;
ins_el[j] = rand_val;
bubble_el[j] = rand_val;
heap_el[j] = rand_val;
quick_el[j] = rand_val;
merge_el[j] = rand_val;
}

clock_t start, finish;
start = clock(); //time in milliseconds
heapSort(i);
finish = clock();
double heap_duration = (double)((finish - start) / (double)CLOCKS_PER_SEC); //time in secs.
start = clock(); //time in milliseconds
mergeSort(0, i - 1);
finish = clock(); //time in milliseconds
double merge_duration = (double)((finish - start) / (double)CLOCKS_PER_SEC); //time in secs.
start = clock(); //time in milliseconds
quickSort(0, i - 1);
finish = clock(); //time in milliseconds
double quick_duration = (double)((finish - start) / (double)CLOCKS_PER_SEC); //time in secs.
start = clock(); //time in milliseconds
bubbleSort(i);
finish = clock(); //time in milliseconds
//the constant CLOCKS_PER_SEC below is equal to 1000
double bubble_duration = (double)((finish - start) / (double)CLOCKS_PER_SEC); //time in secs.
start = clock(); //time in milliseconds
selectionSort(i);
finish = clock(); //time in milliseconds
//the constant CLOCKS_PER_SEC below is equal to 1000
double selection_duration = (double)((finish - start) / (double)CLOCKS_PER_SEC); //time in secs.
start = clock(); //time in milliseconds
insertionSort(i);
finish = clock(); //time in milliseconds
//the constant CLOCKS_PER_SEC below is equal to 1000
double insertion_duration = (double)((finish - start) / (double)CLOCKS_PER_SEC); //time in secs.

cout << left << setw(20) << i
<< setw(15) << heap_duration
<< setw(15) << merge_duration
<< setw(15) <<quick_duration
<< setw(15) <<bubble_duration
<< setw(15) <<selection_duration
<< setw(16) << insertion_duration
<< endl;

fout << left <<setw(20) << i
<< setw(15) <<heap_duration
<< setw(15) <<merge_duration
<< setw(15) <<quick_duration
<< setw(15) <<bubble_duration
<< setw(15) <<selection_duration
<< setw(16) << insertion_duration
<< endl;

}

system("pause");
fout.close();
return 0;

}


