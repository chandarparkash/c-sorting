#include<bits/stdc++.h>
using namespace std;
#define n 400
class randfun{

 int q=0;
 int kan=0;
 int i,j;
 int sort[1000];
    public:
 void creator()
    {
       
        ofstream f1;
    //CODE GENERATING  RANDOM NUMBERS
        f1.open("400 Elements.txt");
        if(!f1)
        {
            cout<<"ERROR FILE MAKING";
            exit(1);
        }
        srand(time(0));
        while(q!=n)
        {
            f1<<(rand())<<endl;
            q++;
        }
        f1.close();
    }
    int val;
     void f_read()
    {
       
    ifstream fi("400 Elements.txt");
  	
    int val;
    while (fi >> val){
    	
     sort[kan]=val;
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
    
    void sortQuik(int l, int r)
    {

      int i = l, j = r;

      int tmp;

      int pivot = sort[(l + r) / 2];

 

      

      while (i <= j) 
        {

            while (sort[i] < pivot)
            {
                i++;
            }

            while (sort[j] > pivot)
            {
                j--;
            }

            if (i <= j) {

                tmp = sort[i];

                  sort[i] = sort[j];

                  sort[j] = tmp;

                  i++;

                  j--;

            }

      };

 


      if (l < j)

            sortQuik(l, j);

      if (i < r)

            sortQuik( i, r);

    }

	
	
	
};
main()
{
	randfun rand;
	rand.creator();
	rand.f_read();
	rand.print();
	rand.sortQuik(0,n-1);
	cout<<endl;
	rand.print();
	
}