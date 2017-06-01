#include <iostream>
#include <iterator>
#include "Fibonacci.h"
#include <algorithm>
#include <vector>


using namespace std;

typedef int for_test_T;

void main()
{
	Fibonacci<for_test_T> fib(7, -5, 10);

	//vector<int> fib_vector;
	for (Fibonacci<for_test_T>::const_iterator i = fib.cbegin(); i != fib.cend(); ++i)
		cout << *i << " ";
	cout << endl;
	for (Fibonacci<for_test_T>::const_iterator i = fib.cend() - 1;; i-=1)
	{
		cout << *i << " ";
		if (i == fib.cbegin())
			break;
	}
	vector<for_test_T> fib_vector;
	fib_vector.insert(fib_vector.begin(), fib.cbegin(), fib.cend());
	sort(fib_vector.begin(), fib_vector.end());
	cout << endl;
	for (int i = 0; i < fib_vector.size(); i++)
		cout << fib_vector[i] << " ";
	cout << endl;
	//for (int i = 0; i < fib_vector.size(); i++)
	//	cout << fib_vector[i] << " ";
	//std::sort(fib_vector.begin(), fib_vector.end());
	//for (int i = 0; i < fib_vector.size(); i++)
	//	cout << fib_vector[i] << " ";
	system("pause");
}