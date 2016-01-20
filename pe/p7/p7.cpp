/******************************************************************************
Copyright (C), 2016, dploop
FileName: p7.cpp
Author: dploop
Date: 2016/1/20
Description: https://projecteuler.net/problem=7
******************************************************************************/
#include <iostream>
#include <cstdint>
#include <vector>
using namespace std;

template<typename T> class PrimeTable {
private:
	vector<uint32_t> array; vector<T> plist;
	int setf(T n) {array[n/32] &= ~(1<<(n%32)); return 0;}
	int sett(T n) {array[n/32] |=  (1<<(n%32)); return 0;}
	int flip(T n) {array[n/32] ^=  (1<<(n%32)); return 0;}
public:
	bool isPrime(T n) {return (array[n/32]&(1<<(n%32)));}
	T getPrime(T idx) {return plist[idx];}
	T getLimit() {return (array.size() * 32);}
	T getCount() {return (plist.size() - 1);}
	PrimeTable(T limit) {T x, y, xx, yy, n; // sieve of atkin
		limit = (limit + 31) / 32 * 32;
		array.resize(limit/32, 0); sett(2); sett(3);
		for(x=1;(xx=x*x)<limit;++x) for(y=1;(yy=y*y)<limit;++y) {
			((n=4*xx+yy)<limit) && (n%12==1||n%12==5) && flip(n);
			((n=3*xx+yy)<limit) && (n%12==7) && flip(n);
			((x>y)&&((n=3*xx-yy)<limit) && (n%12==11) && flip(n));
		}
		for (x=5; (xx=x*x) < limit; ++x) if (isPrime(x)) {
			for (n=xx; n < limit; n += xx) {setf(n);}
		}
		plist.push_back(0); for (n=1; n < limit; ++n) {
			if (isPrime(n)) {plist.push_back(n);}
		}
	}
};

int main() {
	PrimeTable<int> pt(1000000);
	cout << pt.getPrime(10001) << endl;
	return 0;
}

