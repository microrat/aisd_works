#include <iostream>


using namespace std;
//--СОРТИРОВКА ВЫБОРОМ--//
void selection_sort(int a[],int size){
    int i,min,j;
    for(i=0;i<size-1;i++){
        min=i;
        for(j=i+1;j<size;j++){
            if(a[j]<a[min]){min=j;}
        }
        swap(a[min],a[i]);
    }
}
//--СОРТИРОВКА ВСТАВКАМИ--//
void ins_sort(int a[],int size){
    int i,j,key;
    for(i=1;i<size;i++){
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j=j-1;
            a[j+1]=key;
        }
    }
}
//--СОРТИРОВКА ПУЗЫРЬКОМ--//
void bubble_sort(int a[],int size){
    int i,j;
    for(i=0;i<size;i++){
        for(j=0;j<size-1;j++){
            if(a[j+1]<a[j])swap(a[j+1],a[j]);
        }
    }
}
//--СОРТИРОВКА БЫСТРАЯ--//
void quick_sort(int *a, int first, int last){
    int mid;
    int f=first, l=last;
    mid=a[(f+l) / 2];
    do
    {
        while (a[f]<mid) f++;
        while (a[l]>mid) l--;
    if (f<=l)
    {
 swap(a[f],a[l]);
    f++;
    l--;
    }
} while (f<l);
    if (first<l) quick_sort(a, first, l);
    if (f<last) quick_sort(a, f, last);
}
//--СЛИЯНИЕ--//
void my_merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int* L = new int[n1];
	int* R = new int[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)	{
		if (L[i] <= R[j])		{
			arr[k] = L[i];
			i++;
		}
		else		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)	{
		arr[k] = R[j];
		j++;
		k++;
	}
}
//--СОРТИРОВКА СЛИЯНИЕ--//
void merge_sort(int arr[], int l, int r){
	if (l < r)	{

		int m = l + (r - l) / 2;

		merge_sort(arr, l, m);
		merge_sort(arr, m + 1, r);

		my_merge(arr, l, m, r);
	}
}



int main()
{
    int n,number;
    int first=0,
        last=n-1;
	cout << "enter N: ";
	cin >> n;
	int* array = new int[n];
	cout << "enter mas elem:\n";
	for (int i = 0; i < n; i++)
		cin >> array[i];

	cout<<"Selection sort = 1"<<endl;
	cout<<"Insertion sort = 2"<<endl;
	cout<<"Bubble sort = 3"<<endl;
	cout<<"Quick sort = 4"<<endl;
	cout<<"Merge sort = 5"<<endl;
	cout<<"Enter number"<<endl;

	cin>>number;

	switch(number){
        case 1:selection_sort(array,n);break;
        case 2:ins_sort(array,n);break;
        case 3:bubble_sort(array,n);;break;
        case 4:quick_sort(array, first, last);break;
        case 5:merge_sort(array,0,n-1);;break;
        default:cout<<"nothing";break;
	}
    for (int i = 0; i < n; i++)
		cout<< array[i]<<" ";

    return 0;
}
