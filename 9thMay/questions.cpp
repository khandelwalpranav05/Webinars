#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <stack>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

int factorial(int n) {
	// //BASE CASE
	if (n == 0) {
		return 1;
	}

	//RECURSIVE
	int subProblem = factorial(n - 1); //recursion

	int ans = subProblem * n;
	return ans;
}

int fib(int n) {
	//BASE CASE
	if (n == 0 or n == 1) {
		return n;
	}

	//RECURSIVE
	int fibn1 = fib(n - 1);
	int fibn2 = fib(n - 2);

	int fibn = fibn1 + fibn2;
	return fibn;
}

int pairingProblem(int n) {
	//BASE CASE
	if (n == 1 or n == 2) {
		return n;
	}

	int alone = pairingProblem(n - 1);
	int pair = pairingProblem(n - 2);

	int total = alone + pair * (n - 1);
	return total;
}

int countBinaryStrings(int n) {
	if (n == 1 or n == 2) {
		return n + 1;
	}

	// RECURSIVE
	int withZero = countBinaryStrings(n - 1); // leftCALL
	int withOne = countBinaryStrings(n - 2); // rightCALL

	int total = withOne + withZero;
	return total;
}

int countBoardPath(int start, int end) {
	// BASE CASE
	if (start == end) {
		return 1;
	}

	if (start > end) {
		return 0;
	}

	// RECURSIVE
	int count = 0;

	for (int jump = 1; jump <= 6; jump++) {
		count += countBoardPath(start + jump, end);
	}

	// count += countBoardPath(start + 1, end);
	// count += countBoardPath(start + 2, end);
	// count += countBoardPath(start + 3, end);
	// count += countBoardPath(start + 4, end);
	// count += countBoardPath(start + 5, end);
	// count += countBoardPath(start + 6, end);

	return count;
}

int main() {

	// cout << factorial(5) << endl;
	// cout << fib(7) << endl;

	// cout << pairingProblem(4) << endl;

	// cout << countBinaryStrings(4) << endl;

	// cout << countBoardPath(0, 10) << endl;

	return 0;
}