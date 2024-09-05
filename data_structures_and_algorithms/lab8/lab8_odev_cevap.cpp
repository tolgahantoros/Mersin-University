#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include <stdio.h>

	using namespace std;
	int sayac=0;

	int swap(int* a,int* b)
	{
	sayac++;
    int t = *a;
    *a = *b;
    *b = t;
	}
 

	int quick_buyuk (int arr[], int low, int high)
	{ 
	sayac++;
    int pivot = arr[high];    
    int i = (low - 1); 
    for (int j = low; j <= high- 1; j++)
    { sayac++;
      
        if (arr[j] >= pivot)
        { sayac++;
            i++;    
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
	}
	
	
	
	int quick_kucuk (int arr[], int low, int high)
	{  
  		sayac++;
    int pivot = arr[high];    
    int i = (low - 1);  
 
    for (int j = low; j <= high- 1; j++)
    {
    sayac++;
       
        if (arr[j] <= pivot)
        {
        sayac++;
            i++;    
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
	}
  

	int quickSortkucuk(int arr[], int low, int high)
	{
   sayac++;
	  if (low < high)
    {
    	sayac++;
        
        int pi = quick_kucuk(arr, low, high);
 
        
        quickSortkucuk(arr, low, pi - 1);
        quickSortkucuk(arr, pi + 1, high);
    }
    return sayac;
	}
	
	
	
	int quickSortbuyuk(int arr[], int low, int high)
	{ sayac++;
    if (low < high)
    { sayac++;
    int pi = quick_buyuk(arr, low, high);
        quickSortbuyuk(arr, low, pi - 1);
        quickSortbuyuk(arr, pi + 1, high);
    }
    return sayac;
	}

	int merge(int arr[], int l, int m, int r)
	{ 
	sayac++;
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++){
    	sayac++;
    	 L[i] = arr[l + i];
		}
       
    for (j = 0; j < n2; j++){
		sayac++;
		R[j] = arr[m + 1+ j];
 
		}
        

    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {sayac++;
        if (L[i] <= R[j])
        {sayac++;
            arr[k] = L[i];
            i++;
        }
        else
        {sayac++;
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    
    while (i < n1)
    {sayac++;
        arr[k] = L[i];
        i++;
        k++;
    }
 
    
    while (j < n2)
    {sayac++;
        arr[k] = R[j];
        j++;
        k++;
    }
	}

	int heapify(int arr[], int n, int i)
	{
	sayac++;
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
 

    if (l < n && arr[l] > arr[largest])
		{
    	sayac++;
    	largest = l;
		}
		
    if (r < n && arr[r] > arr[largest])
		{
    	sayac++;
    	largest = r;
		}
		
    if (largest != i)
	 	{
    	sayac++;
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    	}
	}
 
 
	int heapSort(int arr[], int n)
	{
    sayac++;
    
    for (int i = n / 2 - 1; i >= 0; i--)
		{
    	sayac++;
    	heapify(arr, n, i);
		}
        
 
    
    for (int i = n - 1; i >= 0; i--) {
    	sayac++;
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
    
    return sayac;
	}
 

	void printArray(int arr[], int n)
	{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    	cout << "\n";
	}


	int mergeSort(int arr[], int l, int r)
	{	
		sayac++;
    if (l < r)
    {	
		sayac++;
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
    return sayac;
	}
  
	int main ()
	{

	int secim;
	while(1)
	{
			int  arr[]  = {2,3,4,5,6,7,8,9,15};
			int arr3[] = {2,3,4,5,6,7,8,9,15};
			int arr2[] = {2,3,4,5,6,7,8,9,15};
			int arr4[] = {2,3,4,5,6,7,8,9,15};
			 
			 
    	int n = sizeof(arr)/sizeof(arr[0]);
		
		cout<<"Lutfen istdeginiz siralamayi giriniz:"<<endl;
		cout<<"1. Hizli  siralama"<<endl;
		cout<<"2. Birlesme siralama"<<endl;
		cout<<"3. Kumeleme siralama"<<endl;
		cin>>secim;
	
		switch(secim)
		{
			case 1:
				
			system("cls");
			
			cout<<"Sayac sayisi :";	 
			cout<<quickSortkucuk(arr, 0,n-1)<<endl;
				sayac=0;
			cout<<"Hizli  siralama Kucukten buyuge "<<endl;
			printArray(arr , n );
		 
			cout<<"Sayac sayisi :";	
			cout<<quickSortbuyuk(arr2, 0,n-1)<<endl;
				sayac=0;
		  	cout<<"Hizli siralama buyukten kucuge "<<endl;
			printArray(arr2, n);
			
			break;
			
			case 2:
			system("cls");
			
			cout<<"Sayac sayisi :";	 
			cout<<mergeSort(arr3, 0,n-1)<<endl;
				sayac=0;
			cout<<"Birlesme siralama kucukten buyuge "<<endl;
			printArray(arr3 , n );
		  
			break;
			
		  case 3:
			system("cls");
			
			cout<<"adim sayisi :";	 
			cout<<heapSort(arr4,n)<<endl;
				sayac=0;
			cout<<"Kumeleme siralama kucukten buyuge "<<endl;
			printArray(arr4 , n ); 
		  
			break;
		}
	}
}

