#include<bits/stdc++.h>
using namespace std;
#define n 50
class SORTING{
	int c=0,count;
	int array[1000];
	public:
	
	 void generator()
    {
       
        ofstream file1;
    //CODE GENERATING  RANDOM NUMBERS
        file1.open("50 Elements.txt");
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
       
    ifstream file("50 Elements.txt");
  	
    int num;
    while (file >> num)
	{
    	
     array[count]=num;
    count++;
	}
}
	  void print()
    {
        for(int i=0;i<n;i++)
        {
            cout<<array[i]<<" ";
        }
    }


	  void mergesort(int l,int r)
   {
  
       if(l<r)
       {
           int mid=(l+r)/2;
           mergesort(l,mid);
           mergesort(mid+1,r);
           merge(l,mid,r);
           
       }
   }

   void merge(int l,int mid,int r)
   {
       int n1=mid-l+1;
       int n2=r-mid;
       int a[n1];
        int b[n2];
        
     	for(int i=0;i<n1;i++)
		 {
		 	a[i]=array[l+i];
			}   
			
		for(int i=0;i<n2;i++)
		{
			b[i]=array[mid+1+i];
		}
		
		int i=0,j=0,k=l;
		while(i<n1 && j<n2)
		{
			if(a[i]<b[j])
			{
				array[k]=a[i];
				k++;
				i++;
			}
			else{
				array[k]=b[j];
				k++;
				j++;
				
			}
		}
		while(i<n1)
		{
			array[k]=a[i];
			k++;
			i++;
		}
		 
		while(j<n2)
		{
				array[k]=b[j];
				k++;
				j++;
		}
		
    }

};
main()
{
	SORTING ELEMENTS_50;

    ELEMENTS_50.generator();
    ELEMENTS_50.filereading();
    ELEMENTS_50.print();
    cout<<endl<<"MERGE SORT"<<endl;
    ELEMENTS_50.mergesort(0,n-1);
    ELEMENTS_50.print();
}