#include<bits/stdc++.h>
#define n 300
using namespace std;
class ranfun{


 int Q=0;
 int kan=0;
 int i,j;
 int sort[1000];
    public:
    	void swap(int *d, int *f)
{
	int temp; 
	temp = *d;
	*d = *f;
	*f = temp;
}
 void creator()
    {
       
        ofstream f1;
    //CODE GENERATING RANDOM NUMBERS
        f1.open("300 Elements.txt");
        if(!f1)
        {
            cout<<"ERROR FILE MAKING";
            exit(1);
        }
        srand(time(0));
        while(Q!=n)
        {
            f1<<(rand())<<endl;
            Q++;
        }
        f1.close();
    }
    int h;
     void filereading()
    {
       
    ifstream file("300 Elements.txt");
  	
    int v;
    while (file >> v){
    	
     sort[kan]=v;
    kan++;
	}
	}
	
	   void print()
    {
        for(i=0;i<n;i++)
        {
            cout<<sort[i]<<" ";
        }
    }
    
    int median(int sort[], int down, int up) {
	
	int pivot;
	int mid = ( down+ up) / 2;
	if (sort[mid] < sort[down]) 
		swap(&sort[mid], &sort[down]);
	if (sort[up] < sort[down])
		swap(&sort[up], &sort[down]);
	if (sort[up] < sort[mid])
		swap(&sort[up], &sort[mid]);
	swap(&sort[mid], &sort[up-1]);
	
	pivot = sort[up-1];
 
	return median_end(sort, down, up);
}
int median_end(int sort[], int down, int up) {
	int pivot = sort[up];
	int i = (down - 1);
 
	for (int j = down; j < up; j++) {
		if (sort[j] < pivot) {
		swap(&sort[++i], &sort[j]);
		}
	}
 
	swap(&sort[i + 1], &sort[up]);
	return (i + 1);
}
 
void SortQuik(int down, int up) {	
	if (down < up) {
	
		int m = median(sort, down, up);
 
	
		SortQuik( down, m - 1);
 
	
		SortQuik(m + 1, up);
	}
}
    
    
};
main()
{
	ranfun obj;
	obj.creator();
	obj.filereading();
	obj.print();
	cout<<endl;
	obj.SortQuik(0,n-1);
cout<<"AFTER SORT:" <<endl;
	obj.print();
}