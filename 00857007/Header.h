
#ifndef BIGINT_H
#define BIGINT_H

//�j���
class BigInt {
	// (�@) default: �T�w��(100) �����
	// (�G) ���N�쪺���


public:

	BigInt();								        	// default constructor, value = 0, capacity = 100, numDigits = 0
	BigInt(const int value, const int size = 100);		// assign an integer value and capacity = size
	BigInt(const char* const, const int size = 100);		// assign a string 
	BigInt(const BigInt&);				  				// copy constructor
	~BigInt();												// destructor

	void Zero();
	void Add(const BigInt&);
	void Add( int);
	void Add(const char* );
	void PrintValue();

private:
	int* _digits;							 // Array: array�C�@�Ӿ�Ʀs�@��� �s��ƥi�H�˹L�Ӧs�p������K(array�Ĥ@�Ӧs�Ӧ�� array�ĤG�Ӧs�Q��� ...)
	int _capacity;               			 // Array  �O����e�q 
	int _numDigits;							 // ��Ʀ��X���
//		int sign;							 // �X�R�����\���t�ƨϥ�
};


#endif
