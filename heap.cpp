#include <iostream>

using namespace std;

void swap(int a, int temp, int b)
{
    temp=a;
    a=b;
    b=temp;
}

void heapmin(int arr[], int n, int i)
{
    int min = i;
    int a = 2*i+1;
    int b = 2*i+2;
    if (a<n && arr[a]<arr[min])
        min = a;
    if (b<n && arr[b]<arr[min])
        min = b;;
    if (min != i){
        swap(arr[i], arr[min]);
        heapmin(arr, n, min);
    }
}

void heapsort(int arr[], int n)
{
    for (int i= n/2 - 1; i>=0; i--){
        heapmin(arr, n, i);
    }
    for (int i= n-1; i>0; i--){
        swap(arr[0], arr[i]);
        for (int i=0; i < n; i++){
            cout << arr[i] <<" ";
        heapmin(arr, i, 0);
        }
        cout << "\n";
    }
}

void addheapArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    cin >> arr[i];
}

void printheapArray(int arr[],int n)
{
    for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int arr[100]; 
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Nhap so N: \n";
    cin >> n ;
    cout << "Nhap day so: \n";
    addheapArray(arr,n);
    heapsort(arr, n);
    cout << "Vay day so sau khi sap xep la: \n";
    printheapArray(arr, n);
    return 0;
}
