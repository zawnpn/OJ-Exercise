#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

const int DIGITS = 20100;
string int_to_string(int n)
{
	ostringstream stream;

	stream << n; //n为int类型

	return stream.str();
}
struct BigInt {
	BigInt() { memset(digits, 0, sizeof(digits)); }
	BigInt(string x) {
		memset(digits, 0, sizeof(digits));
		for (int i = 1; i <= x.length(); i++) {
			digits[i] = x[x.length() - i] - '0';
		}
	}

	string toString() {
		string str;
		int back = 0;
		for (int i = DIGITS; i >= 1; i--) {
			if (digits[i] != 0) {
				back = i;
				break;
			}
		}
		for (int i = back; i >= 1; i--)
			str += int_to_string(digits[i]);
		if (str == "")
			str = "0";
		return str;
	}

	short digits[DIGITS + 2];

};

// 高精度比较的三种结果
enum Result {
	Less,   // X小于Y
	Equal,  // X等于Y
	Greater // X大于Y
};

Result compare(BigInt x, BigInt y) {
	int backX = 0, backY = 0;

	for (int i = DIGITS; i >= 1; i--) {
		if (x.digits[i] != 0) {
			backX = i;
			break;
		}
	} 
	for (int i = DIGITS; i >= 1; i--) {
		if (y.digits[i] != 0) {
			backY = i;
			break;
		}
	}

	if (backX > backY)
		return Greater;

	else if (backX < backY)
		return Less;

	else {
		for (int i = backX; i >= 1; i--) {
			if (x.digits[i] > y.digits[i])
				return Greater;
			else if (x.digits[i] < y.digits[i])
				return Less;
		}
		return Equal;
	}
}

BigInt minusX(BigInt x, BigInt y) {
	BigInt sum;
	int inc = 0; 

	for (int i = 1; i <= DIGITS; i++) {

		sum.digits[i] = x.digits[i] - y.digits[i] + inc;

		if (sum.digits[i] < 0) {
			inc = -1; 
			sum.digits[i] += 10; 
		}
		else
			inc = 0;
	}
	return sum;
}

string s1, s2;
BigInt x, y;

int main()
{
	cin >> s1 >> s2;
	x = BigInt(s1);
	y = BigInt(s2);

	if (compare(x, y) == Less)
	{
		cout << "-";
		swap(x, y);
	}
	cout << minusX(x, y).toString() << endl;
	return 0;
}