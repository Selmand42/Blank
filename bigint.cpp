#include "bigint.hpp"

string q_to_str(deque<int> q)
{
	string res = "";
	for (int i = 0; i < (int)q.size(); i++)
		res.push_back(q[i] + '0');
	return res;
}

bigint::bigint()
{
	q.push_back(0);
}

bigint::bigint(int num)
{
	while (num)
	{
		q.push_front(num % 10);
		num /= 10;
	}
}

bigint::bigint(string num)
{
	for (size_t i = 0; i < num.size(); i++)
	{
		q.push_back(num[i] - '0');
	}
}

void bigint::show() const
{
	for (int i = 0; i < (int)q.size(); i++)
	{
		cout << q[i];
	}
	cout << endl;
}

bigint bigint::operator+(bigint& other)
{
	deque<int> temp;
	deque<int> q1((*this).q);
	deque<int> q2(other.q);
	deque<int> last;

	int remain = 0;
	int num1, num2;

	while (!q1.empty() && !q2.empty())
	{
		num1 = q1.back();
		num2 = q2.back();
		q1.pop_back();
		q2.pop_back();
		temp.push_front((num1 + num2 + remain) % 10);
		remain = (num1 + num2) / 10;
	}

	last = q1;
	if (!q2.empty())
		last = q2;

	while (!last.empty())
	{
		num1 = last.back();
		last.pop_back();
		temp.push_front((num1 + remain) % 10);
		remain = (num1 + remain) / 10;
	}
	if (remain > 0)
		temp.push_front(remain);

	return bigint(q_to_str(temp));

}

bool bigint::operator==(bigint& other)
{
	if ((*this).q.size() != other.q.size())
		return 0;

	for (int i = 0; i < (int)(*this).q.size(); i++)
	{
		if ((*this).q[i] != other.q[i])
			return 0;
	}
	return 1;
}

bool bigint::operator!=(bigint& other)
{
	return !((*this) == other);
}

bool bigint::operator<(bigint& other)
{
	if ((*this).q.size() < other.q.size())
		return 1;

	for (int i = 0; i < (int)(*this).q.size(); i++)
	{
		if ((*this).q[i] < other.q[i])
			return 1;
	}
	return 0;
}

bool bigint::operator>(bigint& other)
{
	if ((*this) < other)
		return 0;
	if ((*this) == other)
		return 0;

	return 1;
}

bool bigint::operator<=(bigint& other)
{
	if ((*this) < other)
		return 1;
	if ((*this) == other)
		return 1;
	return 0;
}

bool bigint::operator>=(bigint& other)
{
	if ((*this) > other)
		return 1;
	if ((*this) == other)
		return 1;
	return 0;
}

bigint bigint::operator<<(int n)
{
	deque<int> temp((*this).q);

	for (int i = 0; i < n; i++)
		temp.push_back(0);

	if (temp.front() == 0)
		return bigint(0);

	return bigint(q_to_str(temp));
}

bigint bigint::operator>>(int n)
{
	if (n >= (int)(*this).q.size())
		return bigint(0);

	deque<int> temp((*this).q);

	for (int i = 0; i < n; i++)
		temp.pop_back();

	return bigint(q_to_str(temp));
}

void bigint::operator+=(bigint& other)
{
	(*this) = (*this) + other;
}

ostream& operator<<(ostream& os, const bigint& num)
{
	num.show();
	return os;
}
