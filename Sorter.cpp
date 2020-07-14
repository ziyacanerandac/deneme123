#include <iostream>
using namespace std;
template<class T>
class Sorter
{
public:
	Sorter()
	{
		data = new T[5];
	}
	Sorter(T*b, int a)
	{
		size = a;
		data = b;
	}
	void setarray(T*b, int a)
	{
		size = a;
		data = b;
	}
	void sort()
	{
		T temp;
		int i, j;

		for (i = 1; i <size; i++)
		{
			for (j = 0; j < size - i; j++)
			{
				if (data[j] > data[j + 1])
				{
					temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
			}
		}
	}


private:
	T* data;
	int size;
};

int main(void)
{
	Sorter<int> a;
	int  intarr[10] = { 5,53,54,0,63,65,4,14,40,60 };
	cout << "integer: ";
	for (int i = 0; i < 10; i++)
	{
		cout << intarr[i]<<" ";
	}
	cout << endl;
	a.setarray(intarr,10);
	a.sort();
	cout << "sorted: ";
	for (int i = 0; i < 10; i++)
	{
		cout << intarr[i] << " ";
	}
	cout << endl;
	//
	Sorter<double> b;
	double doublearr[6] = { 68.03, 70.75, 57.26, 70.3 ,65.82, 1.69 };
	cout << "double: ";
	for (int i = 0; i < 6; i++)
	{
		cout << doublearr[i] << " ";
	}
	cout << endl;
	b.setarray(doublearr, 6);
	b.sort();
	cout << "sorted: ";
	for (int i = 0; i < 6; i++)
	{
		cout << doublearr[i] << " ";
	}
	cout << endl;
	//
	Sorter<char> c;
	char chararr[10] = { 'q', 'j', 's', 'z', 'e', 'g', 'w' ,'j' ,'z', 'u' };
	cout << "chars: ";
	for (int i = 0; i < 10; i++)
	{
		cout << chararr[i] << " ";
	}
	cout << endl;
	c.setarray(chararr, 10);
	c.sort();
	cout << "sorted: ";
	for (int i = 0; i < 10; i++)
	{
		cout << chararr[i] << " ";
	}
	cout << endl;
	getchar();
	return 0;
}

