#pragma once

#include <deque>
#include <iostream>

using namespace std;

class bigint
{
	public:
		deque<int> q;
		bigint();
		bigint(string num);
		bigint(int num);
		void show() const;

		bigint operator+(bigint& other);
		void operator+=(bigint& other);
		bool operator==(bigint& other);
		bool operator!=(bigint& other);
		bool operator<(bigint& other);
		bool operator<=(bigint& other);
		bool operator>(bigint& other);
		bool operator>=(bigint& other);
		bigint operator<<(int n);
		bigint operator>>(int n);

};

ostream& operator<<(ostream& os, const bigint& num);
