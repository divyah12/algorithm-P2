//**************************************************************
//                   Project #1 Sorting
//                    
//                    Data Structures Date: 02/08/2016
//***************************************************************
//      This program calculates the time complexity of two sorting 
//      algorithms, Insertion and Merge Sort with complexity O(n^2) 
//      and O(nlog(n)). The comparison of this time is plotted on 
//      the graph below.
//*****************************************************************

//*******************************************************************
//                     ObjectName::insertion_sort(double *arr, int length)
//                     Parameters: double *arr, int length
//                     Complexity: O(N^2)
//   The method implemented for inseertion sort is retrived from the textbook
//
//                      ObjectName::merge(double* A, int p, int q, int r)
//						Parameters: double* A, int p, int q, int r
//						ObjectName::mergesort(double *a, int p, int r)
//						Parameters: double* a, int p, int r                     
//						Complexity: O(Nlog(N))
//   The method implemented for inseertion sort is retrived from the textbook
//         
//    The main function runs with Complexity: O(N^2) where N is the size 
//********************************************************************
#include <iostream>
#include <time.h>
#include <string>
using namespace std;

void insertion_sort(double *arr, int length) {
	double key; 
	int i;

	for (int j = 2; j < length; j++) {
		key = arr[j];
		i = j - 1;
		while (i > 0 && arr[i] > key) {
			arr[i + 1] = arr[i];
			i = i - 1;
		}
		arr[i + 1] = key;
	}
}
void merge(double* A, int p, int q, int r) {      
	int n1 = q - p + 1;                           
	int n2 = r - q;                               

	int i, j, k;
	double *L = new double[n1 + 1], *R = new double[n2 + 1];  

	for (i = 0; i<n1; i++)                       
		L[i] = A[p + i];                         
												
	for (j = 0; j<n2;j++)  
		R[j] = A[q+1+ j];          

	L[n1] = 99999; 
	R[n2] = 99999;
	i = 0;                            
	j = 0;                            
	for (k = p; k <= r; k++) {        
		if (L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else                        
			A[k] = R[j++];          
	}

	delete(L);
	delete(R);
}

void mergesort(double *a, int p, int r) {   
	if (p<r) {                              
		int q =(p + r) / 2;   
		mergesort(a, p, q);                 
		mergesort(a, q + 1, r);             
		merge(a, p, q, r);                  
	}
}
int main()
{
	clock_t iT, mT;
	for (int i = 10000; i <= 100000;i = i + 10000){
	
		double *mArray = new double[i];
		double *iArray = new double[i];
		for (int j = 0;j < i; j++)
			iArray[j] = mArray[j] = rand() / double(RAND_MAX);
		iT = clock();
		insertion_sort(iArray, i);
		iT = clock() - iT;
		mT = clock();
		mergesort(mArray, 0, i - 1);
		mT = clock()-mT;
		cout <<( ((float)iT) / CLOCKS_PER_SEC) <<"\t"<<(((float)mT) / CLOCKS_PER_SEC) << endl;
		delete [] mArray;
		delete [] iArray;
	}
		return 0;
}


	
