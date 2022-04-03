#include<bits/stdc++.h>
using namespace std;
#define N 100
class randfun{


 int q=0;
 int kan=0;
 int i,j;
 int sort[1000];
    public:
 void creator()
    {
       
        ofstream f1;
    //CODE GENERATING FOR 50 RANDOM NUMBERS
        f1.open("100 Elements.txt");
        if(!f1)
        {
            cout<<"ERROR FILE MAKING";
            exit(1);
        }
        srand(time(0));
        while(q!=N)
        {
            f1<<(rand())<<endl;
        q++;
        }
        f1.close();
    }
    int val;
     void f_read()
    {
       
    ifstream f2("100 Elements.txt");
  	
    int val;
    while (f2 >> val){
    	
     sort[kan]=val;
    kan++;
	}
	}
	
	   void print()
    {
        for(i=0;i<N;i++)
        {
            cout<<sort[i]<<" ";
        }
    }
	

	int partis(int l, int h)
{
	int pi, ind, i;
	ind = l;
	pi = h;
 

	for(i=l; i < h; i++)
	{
		if(sort[i] < sort[pi])
		{
			swap(&sort[i], &sort[ind]);
			ind++;
		}
	}

	swap(&sort[pi], &sort[ind]);
 
	return ind;
}
 

int randpi( int l, int h)
{
	int pvt, n, temp;
	n = rand();

	pvt = l + n%(h-l+1);
 

	swap(&sort[h], &sort[pvt]);
 
	return partis(l, h);
}
 

int sortQuik( int l, int h)
{
	int pind;
	if(l < h)
	{
		
		pind = randpi(l, h);
	
		sortQuik(l, pind-1);
		sortQuik(pind+1, h);
	}
	return 0;
}
void swap(int *d, int *f)
{
	int temp; 
	temp = *d;
	*d = *f;
	*f = temp;
}
	
};
main()
{
	randfun rand;
	rand.creator();
	rand.f_read();
	rand.print();
	rand.sortQuik(0,N-1);
	cout<<endl;
	rand.print();
	
}