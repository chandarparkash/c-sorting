#include<bits/stdc++.h>
using namespace std;
#define n 500
class RANDOM_generate{

 int c=0;
 int count=0;
 int i,j;
 int arr[1000];
    public:
    void generator()
    {
       
       
       
        ofstream file1;
    //CODE GENERATING RANDOM NUMBERS
        file1.open("500 Elements.txt");
        if(!file1)
        {
            cout<<"ERROR FILE MAKING";
            exit(1);
        }
        srand(time(0));
        while(c!=n)
        {
            file1<<(rand())<<endl;
            c++;
        }
        file1.close();
    }
    int val;
     void filereading()
    {
       
    ifstream file("500 Elements.txt");
  	
    int num;
    while (file >> num){
    	
     arr[count]=num;
    count++;
	}
  	

    }
    
  void print()
    {
        for(i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
    
    
    void swap(int *c, int *d) {
	int t = *c;
	*c = *d;
	*d = t;
}
 
	int pvotfind(int arr[], int l, int h) 
	{
	int pvot = arr[h];
	int i = (l - 1);
 
	for (int j = l; j < h; j++) {
		if (arr[j] < pvot) {
		swap(&arr[++i], &arr[j]);
		}
	}
 
	swap(&arr[i + 1], &arr[h]);
	return (i + 1);
}

void quickSort( int l, int h) {	
	if (l < h) {
	
		int p = pvotfind(arr, l, h);
 
		
		quickSort( l, p - 1);
 
		
		quickSort (  p + 1, h);
	}
}
 
    
};

main()
{
	RANDOM_generate obj;
	obj.generator();
	obj.filereading();
	obj.print();
	cout<<endl;
	obj.quickSort(0,n-1);
	obj.print();
}