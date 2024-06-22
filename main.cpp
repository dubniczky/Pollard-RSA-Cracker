// To speed up the process of finding prime factors of a number, Pollard's p-1 algorithm is used.
// Pollard's p-1 algorithm is an integer factorization algorithm, which is used to find prime factors of a number.
// The algorithm is based on the fact that if a number n is a prime number, then n-1 is a composite number.
// C libraries are used because they are faster than C++ libraries.

// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif


using namespace std;


int findGCD(int a, int b) {
  // because, gcd(0, b) = b
    if (a == 0)
        return b;
    // using the euclidean algorithm for finding GCD
    return findGCD(b % a, a);
}

bool checkPrime(int num) {
	if (num <= 1 || num % 2 == 0)
		return false;

	for (int itr = 3; itr * itr <= num; itr += 2)
	if (num % itr == 0)
		return false;
	return true;
}

// Implementation of the pollard p-1 algorithm to find prime factors of the number
int pollardPMO(int n) {
	long long base = 10000003;
	int itr = 2;

	// Run operation till a prime factor is obtained
	while (true) {
		base = ((long long) pow(base, itr)) % n;
		base += n;
		base %= n;

	int d = findGCD(base - 1, n);
	if (d > 1) {
		return d;
		break;
    }

	// Increment exponent
	itr += 1;
  }
}



int main() {
	int num;
	cout << "Enter N: ";
	cin >> num;
	int temp = num;
	vector <int> factors;

	// Run operation till the provided number is exhausted or factors are obtained
	while (true) {
		int p = pollardPMO(temp);
		factors.push_back(p);

		// Exhausting the provided number
		int r = (temp / p);

		// Primality check
		if (checkPrime(r)) {
			factors.push_back(r);
			break;
		}
		else {
			temp = r;
		}
 	}
	cout << "Prime factors of " << num << " are:" << endl;
  	for (int x: factors) cout << x << endl;

  	return 0;
}