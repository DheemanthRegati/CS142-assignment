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
	heap[0] = heap[l];
	l--;
	int i = 0;
	while ((2 * i) + 1 <= l)
	{
		if ((2 * i) + 2 > l && heap[i] < heap[(2 * i) + 1])
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
			insert(65);
			insert(45);
			insert(35);
			insert(55);
			insert(15);
			insert(25);
			insert(75);
			insert(85);
			insert(95);
			insert(19);
			for (int j = 0; j < l; j++)
			{
				cout << heap[j] << " ";
			}
			deleter();
			deleter();
			deleter();
			deleter();
			cout<<endl;
			for (int j = 0; j < l; j++)
			{
				cout << heap[j] << " ";
			}
			return 0;
		}
