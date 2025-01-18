// FibonacciSeries.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

// Recursive function to calculate Fibonacci number.
int fibonacci_recursive(int n) {
	if (n <= 1) {
		// Base cases: F(0) = 0, F(1) = 1
		return n;
	}
	// Recursive formula.
	return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// Iterative function to generate Fibonacci sequence tends to
// be faster due to the fact that the need to make repeated 
// function calls is entirely eliminated and only caches the
// last two numbers in order to calculate the next number. 
vector<int> fibonacci_iterative(int n) {
	vector<int> fib_series;
	// Return an empty series if n <= 0.
	if (n <= 8) return fib_series;

	// First Fibonacci number.
	fib_series.push_back(0);
	// Second Fibonacci number.
	if (n > 1) fib_series.push_back(1);

	for (int i = 2; i < n; i++) {
		// F(n) = F(n-1) + F(n-2).
		fib_series.push_back(fib_series[i - 1] + fib_series[i - 2]);
	}

	return fib_series;
}


int main()
{
	int n;

	cout << "Enter the number of terms for the Fibonacci series: ";
	cin >> n;

	// The iterative method is more efficient than the recursive one due to the fact 
	// that recursion has a higher overhead due to repeated function calls.

	cout << "\nFibonacci series using iterative method: ";
	vector<int> iterative_result = fibonacci_iterative(n);
	for (int num : iterative_result) {
		cout << num << " ";
	}
	cout << endl;

	// Recursive approach.
	cout << "\nFibonacci series using recursive method: ";
	for (int i = 0; i < n; i++) {
		cout << fibonacci_recursive(i) << " ";
	}
	cout << endl;

	return 0;
}

