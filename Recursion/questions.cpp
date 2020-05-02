#include <iostream>

using namespace std;

int factorial(int n) {
	if (n == 1 or n == 0) {
		return 1;
	}

	int subProblem = factorial(n - 1); // subproblem is solved by recursion

	int ans = n * subProblem;
	return ans;
}

void printDecreasing(int n) {
	//BASE CASE
	if (n == 1) {
		// cout << 1 << endl;
		cout << n << endl;
		return;
	}

	// SUBPROBLEM or RECURSIVE CASE
	cout << n << endl;
	printDecreasing(n - 1);
}

int power(int n, int p) {
	//BASE
	if (p == 0) {
		return 1;
	}

	int subproblem = power(n, p - 1);
	int ans = n * subproblem;
	return ans;
}

int fib(int n) {
	//BASE
	if (n == 0 or n == 1) {
		return n;
	}

	//RECURSIVE CASE
	int fibn1 = fib(n - 1);
	int fibn2 = fib(n - 2);

	int ans = fibn1 + fibn2;
	return ans;
}

int countBinaryStrings(int n) {
	//BASE
	if (n == 1 or n == 2) {
		return n + 1;
	}

	int withZero = countBinaryStrings(n - 1);
	int withOne = countBinaryStrings(n - 2);

	int total = withOne + withZero;
	return total;
}

int pairingProblem(int n) {
	//BASE
	if (n == 1 or n == 2) {
		return n;
	}

	int stag = pairingProblem(n - 1);
	int pair = pairingProblem(n - 2);

	int total = stag + (n - 1) * pair;
	return total;
}

int countBoardPath(int start, int end) {
	//BASE
	if (start == end) {
		return 1;
	}

	if (start > end) {
		return 0;
	}

	int count = 0;

	for (int i = 1; i <= 6; i++) {
		count += countBoardPath(start + i, end);
	}

	return count;
}

int main() {

	// int n = 5;

	// cout << factorial(n) << endl;
	// printDecreasing(n);

	// cout << power(2, 5) << endl;

	// cout << fib(6) << endl;

	// cout << countBinaryStrings(3) << endl;

	// cout << pairingProblem(4) << endl;

	// cout << countBoardPath(0, 10) << endl;

	return 0;
}

// NOTES -