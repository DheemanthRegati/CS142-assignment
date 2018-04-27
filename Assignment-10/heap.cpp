#include <iostream>
using namespace std;

int l = 0;
int heap[100];

void insert(int data)
{
	if (l == 0)
	{
		heap[0] = data;
	}
	else
	{
		heap[l] = data;
		int i = l;
		int p = (i - 1) / 2;
		while (heap[i] >= heap[p])
		{
			int t = heap[i];
			heap[i] = heap[p];
			heap[p] = t;
			i = p;
			p = (i - 1) / 2;
			if (i == p || i == 0)
			{
				break;
			}
		}
	}
	l++;
}

void deleter(){
	heap[0] = heap[l-1];
	l--;
	int i = 0;
	while ((2 * i) + 1 <= l-1)
	{
		if ((2 * i) + 2 > l-1 && heap[i] < heap[(2 * i) + 1])
		{
			int t = heap[i];
			heap[i] = heap[(2 * i) + 1];
			heap[(2 * i) + 1] = t;
			i = (2 * i) + 1;
		}
		else
		{
			if((heap[(2*i)+1]>heap[(2*i)+2])&&heap[i]<heap[(2*i)+1]){
				int t = heap[i];
			heap[i] = heap[(2 * i) + 1];
			heap[(2 * i) + 1] = t;
			i = (2 * i) + 1;
			}
			else if(heap[i]<heap[(2*i)+2]){
				int t = heap[i];
			heap[i] = heap[(2 * i) + 2];
			heap[(2 * i) + 2] = t;
			i = (2 * i) + 2;
			}
		}
	}
}
	

		int main()
		{
			int f;
			while(true){
			cout<<"insert-1\n delete-2\n display-3\n exit\n";
			cin>>f;
			if(f==1){
				 int b;
            cout<<"data?";
            cin>>b;
            insert(b);
			}
			else if(f==2){
				deleter();
			}
			else if(f==3){
			for (int j = 0; j < l; j++)
			{
				cout << heap[j] << " ";
			}
			}
			else{
			return 0;
			}
			}
		}
