#include <malloc.h>
#include <iostream>
#include <string.h>
#include "Header.h"

using namespace std;


void BigInt::PrintValue() {
	//int flag = 0;
	if (_numDigits == 0)
		cout << '0';
	else
		for (int i = _numDigits - 1; i >= 0; i--)
		{
			cout << _digits[i];
		}
	/*else
		for (int i = _numDigits - 1; i >= 0; i--)
		{
			cout << _digits[i];
			continue;
			if (_digits[i] != 0 || (flag == 1 && _digits[i] == 0)) {
				flag = 1;
				cout << _digits[i];

			}
		}*/
	cout << endl;
}

void BigInt::Zero() {
	for (int i = 0; i < _capacity; i++)
		_digits[i] = 0;
	_numDigits = 0;
}

BigInt::BigInt() {								        // default constructor, value = 0, capacity = 100, numDigits = 0
	_capacity = 100;
	_digits = (int*)malloc(_capacity * sizeof(int));
	Zero();
}

BigInt::~BigInt() {												// destructor
	if (_digits) free(_digits);
	_digits = 0;
	_capacity = _numDigits = 0;
}

//////////////////////////////////////////////////////////////////////////////
// BUG
//////////////////////////////////////////////////////////////////////////////

BigInt::BigInt(const char* const s, const int size) {			// assign a string 
	_digits = 0;							 // Array: 儲存整數
	_capacity = _numDigits = 0;             // Array 大小 // 整數位數
	int cout = 0;
	int strSize = strlen(s);

	for (int i = 0; i < strSize; i++) {
		if (s[i] == '0')
			cout++;
		else
			break;
	}
	if (strSize > size)
		return;

	_capacity = size;
	_digits = (int*)malloc(_capacity * sizeof(int));
	Zero();

	for (_numDigits = 0; _numDigits < strSize - cout; _numDigits++) {
		if (s[_numDigits] < '0' || s[_numDigits] > '9')
			;//break;
		_digits[_numDigits] = s[strSize - _numDigits - 1] - 48;
	}
}


BigInt::BigInt(const int value, const int size  ) {
	_digits = 0;							 // Array: 儲存整數
	_capacity = _numDigits = 0;             // Array 大小 // 整數位數
	
	int valuesize = 0;
	int temp = value;

	while (temp > 0)
	{
		valuesize++;
		temp = temp / 10;
	}
	_capacity = valuesize;
	(*this)._digits = (int*)malloc((_capacity) * sizeof(int));
	Zero();
	temp = value;

	for (_numDigits = 0; _numDigits < valuesize; _numDigits++) {
		_digits[_numDigits] = temp % 10;
		temp = temp / 10;
	}


}
BigInt::BigInt(const BigInt& p) {
	(*this)._capacity = p._capacity;
	(*this)._numDigits = p._numDigits;
	(*this)._digits = (int*)malloc((_capacity) * sizeof(int));
	for (int i = 0; i < _numDigits; i++) {
		(*this)._digits[i] = p._digits[i];
	}

}
void  BigInt::Add( int a) {
	BigInt temp(a);
	(*this).Add(temp);
}
void  BigInt::Add(const char* a) {
	BigInt temp(a);
	(*this).Add(temp);
}

void BigInt::Add(const BigInt& z) {
	BigInt temp(*this);
	int carry = 0;
	if (_capacity < z._capacity) {
		_capacity = z._capacity;
		_digits = (int*)malloc((_capacity + 1) * sizeof(int));
		for (int i = 0; i < _capacity; i++)
		{
			if (i >= temp._numDigits)
				_digits[i] = 0;
			else
				_digits[i] = temp._digits[i];
		}
	}
	if (this->_numDigits < z._numDigits)
		this->_numDigits = z._numDigits;
	//PrintValue();

	for (int i = 0; i < _numDigits; i++)
	{
		int z_digit;
		if (i >= z._numDigits)
			z_digit = 0;
		else
			z_digit = z._digits[i];

		(*this)._digits[i] = (*this)._digits[i] + z_digit + carry;


		if (_digits[i] > 9)
		{
			carry = 1;
			this->_digits[i] -= 10;
		}
		else
			carry = 0;
	}
	if (carry == 1) {
		this->_numDigits += 1;
		this->_digits[_numDigits - 1] = 1;
	}

}


int main() {
	//加法的計算邏輯可以用人計算的方法 
	BigInt x, y("1234"), z("000009876054321"),a(y);
	
	x.PrintValue();
	y.PrintValue();
	z.PrintValue();
	//a.PrintValue();

	//TEST		
	
			y.Add(z);
			y.PrintValue( );
		
			BigInt i(444, 2);
			i.PrintValue( );
			BigInt j(i);
			j.PrintValue( );
			i.Add(78);
			i.PrintValue( );
			i.Add("98765");
			i.PrintValue( );
			i.Add(j);
			i.PrintValue( );
			
	
			return 0;
}