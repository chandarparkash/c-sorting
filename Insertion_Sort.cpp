#include<bits/stdc++.h>
using namespace std;
#define n 1000
class RANDOM_generate{

 int c=0;
 int count=0;
 int i,j;
 int array[1000];
    public:
    void generator()
    {
       
        ofstream file1;
    //CODE GENERATING  RANDOM NUMBERS
        file1.open("1000 Elements.txt");
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
       
    ifstream file("1000 Elements.txt");
  	
    int num;
    while (file >> num){
    	
     array[count]=num;
    count++;
	}
  	

    }
    

      void insertion_sort()
    {
    	int curr;
        for(i=0;i<n;i++)
        {
            j=i-1;
            curr=array[i];
            while(array[j]>curr && j>=0)
            {
                array[j+1]=array[j];
                j--;
            }
            array[j+1]=curr;
        }
    }
    void print()
    {
        for(i=0;i<n;i++)
        {
            cout<<array[i]<<" ";
        }
    }

};

int main()
{
    RANDOM_generate rand;
    rand.generator();
    
    
    rand.filereading();
    rand.print();
	cout<<endl;
	rand.insertion_sort();
	cout<<"AFTER SORTING"<<endl;
rand.print();
}