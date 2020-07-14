
#include <iostream>
#include<string>
#include <iomanip>
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

		for (i = 1; i < size; i++)
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
class person
{
public:
	person()
	{
		
		name = "0";
		surname = "0";
		age = 0;
		occupation = "0";
	}
	person(string isim, string soyisim, int yas, string durum)
	{
		name = isim;
		surname = soyisim;
		age = yas;
		occupation = durum;
	}
	void set(string isim, string soyisim, int yas, string durum)
	{

		name = isim;
		surname = soyisim;
		age = yas;
		occupation = durum;
	}
	
	bool operator <(const person&a)
	{
		return (age < a.age);
	}
	bool operator >(const person&a)
	{
		return (age > a.age);
	}
	void print()
	{
		cout << left << setw(12) << name;
		cout << left << setw(12) << surname;
		cout << left << setw(12) << age;
		cout << left << setw(12) << occupation<<endl;

	}
	


private:
	string name;
	string surname;
	int age;
	string occupation;
};
int main(void)
{
	Sorter<person>obj;
	person *arr = new person[5];
	arr[0].set("Anakin", "Skywalker", 41, "Dark Lord of the Sith");
	arr[1].set("Sheev", "Palpatine", 84, "Emperor");
	arr[2].set("Luke", "Skywalker", 19, "Jedi Knight");
	arr[3].set("Obi-Wan", " Kenobi", 57, "Jedi Master");
	arr[4].set("Han", "Solo", 32, " Smuggler");
	cout << "People:" << endl;
	cout << left << setw(12) << "name";
	cout << left << setw(12) << "surname";
	cout << left << setw(12) << "age";
	cout << left << setw(12) << "occupation" << endl;
	for (int i = 0; i < 5; i++)
	{
		arr[i].print();
	}
	obj.setarray(arr, 5);
	obj.sort();
	cout << "Sorted People:"<<endl;
	cout << left << setw(12) << "name";
	cout << left << setw(12) << "surname";
	cout << left << setw(12) << "age";
	cout << left << setw(12) << "occupation" << endl;
	for (int i = 0; i < 5; i++)
	{
		arr[i].print();
	}
	getchar();
	return 0;
}
