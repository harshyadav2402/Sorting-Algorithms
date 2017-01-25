//all sorting operations

#include <iostream.h>
#include<process.h>
#include<stdio.h>
#include <conio.h>
#define MAX 10

class InsSort{
    int arr[MAX],n;
    public:
    void getdata();
    void showdata();
    void SortLogic();
};

void InsSort :: getdata(){
    cout<<"How many elements you require : ";
    cin>>n;
    for(int i=0;i<n;i++)
	cin>>arr[i];
}

void InsSort :: showdata(){

    cout<<"\n--Display--\n";
    for(int i=0;i<n;i++)
	cout<<arr[i]<<"   ";
}

void InsSort :: SortLogic(){
    int temp,min;
    for(int i=1;i<n;i++){
	temp = arr[i];
	for(int j=i;j>0 && arr[j-1]>temp;j--){
	    arr[j] = arr[j-1];
	}
	arr[j] = temp;
    }
}


/***********************************/

static int merge_arr[MAX+MAX],sort_arr[MAX+MAX];

class mergesort{
    int arr1[MAX],arr2[MAX],n1,n2,n3;
    public:
    void getdata();
    void showdata(int);
    void mergeLogic();
    void sortLogic();
};

void mergesort :: getdata(){
    int i;
    cout<<"\n--Data Must be Entered in Sorted Order for each Array--\n\n";
    cout<<"How many elements you require 1st -> Array: ";
    cin>>n1;
    for(i=0;i<n1;i++)
	cin>>arr1[i];
    cout<<"How many elements you require 2nd -> Array: ";
    cin>>n2;
    for(i=0;i<n2;i++)
	cin>>arr2[i];
    n3=n1+n2;
}

void mergesort :: showdata(int select){
    int i;
    if(select==1){
	cout<<"\n\n--Array 1--\n";
	for(i=0;i<n1;i++)
	    cout<<arr1[i]<<"   ";
    }
    else if(select==2){
	cout<<"\n\n--Array 2--\n";
	for(i=0;i<n2;i++)
	    cout<<arr2[i]<<"   ";
    }
    else if(select==3){
	cout<<"\n\n--Sorted Array--\n";
	for(i=0;i<n3;i++)
	    cout<<sort_arr[i]<<"   ";
    }
}



void mergesort :: mergeLogic(){
    int i,j,c;
    for(i=0;i<n1;i++)
	merge_arr[i] = arr1[i];
    for(j=i,c=0;j<n3;j++,c++)
	merge_arr[j] = arr2[c];
}


void mergesort :: sortLogic(){
    //before sort call mergeLogic
    mergeLogic();

    int i,j,first=0,second=n1,third=n3;
    i=first;
    j=second;
    static int c=0;

    while(i<second && j<third){
	if(merge_arr[i] < merge_arr[j]){
	    sort_arr[c]=merge_arr[i];
	    i++;
	}
	else{
	    sort_arr[c]=merge_arr[j];
	    j++;
	}
	c++;
    }

    if(i<second){
	while(i<second){
	    sort_arr[c]=merge_arr[i];
	    i++;
	    c++;
	}
    }

    if(j<third){
	while(j<third){
	    sort_arr[c]=merge_arr[j];
	    j++;
	    c++;
	}
    }
}

/*************************************************************************************************/

void heapSort()
{                                                  // HEAP SORT
 clrscr();
 int a[50],size;
 int p,c;
 cout<<"Enter the Size of an Array :";
 cin>>size;

 cout<<"Enter Value of A[1] :";
 cin>>a[1];
 for(int i=2;i<=size;i++)
 {
    cout<<"Enter Value of A["<<i<<"] :";
    cin>>a[i];
    p=i/2;
    c=i;
    while(1)
    {
    if( a[c] > a[p])
    {
	int t=a[c];
	a[c]=a[p];
	a[p]=t;
    }
    c=p;
    p=p/2;
    if(p<1)
    {
	break;
    }
    }
 }
 cout<<endl<<"Heap ..."<<endl;
 for(i=1;i<=size;i++)
 {
    cout<<endl;
    cout<<"Arr["<<i<<"] :"<<a[i];
 }

 int j=size;
 int lc,rc;
 while(j>1)
 {
     if(a[1] > a[j])
     {
    int t=a[1];
    a[1]=a[j];
    a[j]=t;
    j--;
     }
     else
     {
    j--;
    continue;
     }

     p=1;
     while(p < j)
     {
     lc=p*2;
     rc=p*2 + 1;
     if(lc>=j || rc >=j)
     {
	    break;
     }
     if(a[p] < a[lc] && a[lc] > a[rc])
     {
    int temp=a[lc];
    a[lc]=a[p];
    a[p]=temp;
    p=lc;
     }
     else if (a[p] < a[rc] && a[rc] > a[lc])
     {
    int temp=a[rc];
    a[rc]=a[p];
    a[p]=temp;
    p=rc;
     }
     else
     {
      break;
     }
     }
 }

 cout<<endl<<"Sorted List ..."<<endl;
 for(i=1;i<=size;i++)
 {
    cout<<endl;
    cout<<"Arr["<<i<<"] :"<<a[i];
 }

 getch();
}
/******************************************************************************************/

void quickSort()
{
 void srt(int[],int,int);                                                         //QUICK SORT
 int a[10],count=0,n;
 clrscr();
 cout<<"Ener 10 values in unsorted order : \n";
 for (n=0;n<10;n++)
     {
      cout<<"value no.: "<<(n+1)<<"\t";
      cin>>a[n];
      count++;
     }
 n=0;
 clrscr();
 srt(a,n,count-1);
 clrscr();
 cout<<"\t\tThe Sorted order is : \n";
 for (n=0;n<10;n++)
     {
      cout<<"\t\tposition : "<<(n+1)<<"\t"<<a[n]<<"\n";
     }
 getch();
}
void srt(int k[20],int lb,int ub)
{
 int i,j,key,flag=0,temp;
 clrscr();
 if (lb<ub)
    {
     i=lb;
     j=ub+1;
     key=k[i];
     while(flag!=1)
      {
       i++;
       while(k[i]<key)
	{
	 i++;
	}
       j--;
       while(k[j]>key)
	{
	 j--;
	}
       if (i<j)
	  {
	   temp=k[i];
	   k[i]=k[j];
	   k[j]=temp;
	  }
       else
	  {
	   flag=1;
	   temp=k[lb];
	   k[lb]=k[j];
	   k[j]=temp;
	  }
      }
     srt(k,lb,j-1);
     srt(k,j+1,ub);
    }
}

/******************************************************************************************************************/

class bubsort{
    int arr[MAX],n;
    public:
    void getdata();
    void showdata();
    void sortLogic();
};

void bubsort :: getdata(){
    cout<<"How many elements you require : ";
    cin>>n;
    for(int i=0;i<n;i++)
	cin>>arr[i];
}

void bubsort :: showdata(){
    cout<<"\n--Display--\n";
    for(int i=0;i<n;i++)
	cout<<arr[i]<<"   ";
}

void bubsort :: sortLogic(){
    int temp;
    for(int i=0;i<n;i++){
	for(int j=0,exchange=0;j<n;j++){
	    if(arr[j] > arr[j+1]){
		temp = arr[j];
		arr[j] = arr[j+1];
		arr[j+1] = temp;
		exchange++;
		cout<<"\n arr[j] = "<<arr[j]<<"  arr[j+1] = "<<arr[j+1];
	    }
	}
	cout<<endl;
	if(exchange==0)
	    break;
    }
}

/**************************/

void main()
{
    clrscr();
    int choice;
    do{
       cout<<"\n   Enter the sorting technique u wanna perform : \n1. Insertion Sort \n2. Merge Sort \n3. Heap Sort \n4. Quick Sort \n5. Bubble Sort \n6. Exit\n\t=> ";
       cin>>choice;

       switch(choice)
       {

	 case 1:  {

			 cout<<"\n*****Insertion Sort*****\n";
			 InsSort obj;
			 obj.getdata();
			 obj.SortLogic();
			 obj.showdata();
			 break;
		  }
	 case 2:  {

			 cout<<"\n*****Merge Sort*****\n";
			 mergesort obj;
			 obj.getdata();
			 obj.sortLogic();
			 obj.showdata(1);
			 obj.showdata(2);
			 obj.showdata(3);
			 break;
		  }
	 case 3:  heapSort(); break;
	 case 4:  quickSort() ; break ;
	 case 5:  {
			 cout<<"\n*****Bubble Sort*****\n";
			 bubsort obj;
			 obj.getdata();
			 obj.sortLogic();
			 obj.showdata();
			 break;
		  }
	 case 6:   exit(0);
	 default:  cout<<"Yeah... Wrong choice dude!";
	 cout << " \n Continue??? ... " ;
	char choice = 'n' ;
	cin >> choice ;
       }
     } while ( choice == 'y' || choice == 'Y');
     getch();
}