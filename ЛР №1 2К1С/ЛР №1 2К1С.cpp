﻿#include <iostream>
#include "Integer.h"
#include "LinkedListSequence.h"
#include "SorterQuickSortLinkedListSequence.h"
#include "ArraySequence.h"
const int globalLengthOfArray = 10;
int arrInt[globalLengthOfArray] = { 1, 4, 5, 5, 3, 6, 4, 1, 9, 7 };
int arrIntSorted[globalLengthOfArray] = { 1, 1, 3, 4, 4, 5, 5, 6, 7, 9 };

class MyInt {
private:
	int data;
public:
	MyInt(int a) : data(a)
	{
	}
	~MyInt() {}
	bool operator < (const MyInt& right) {
		return this->data < right.data;
	}

	bool operator <= (const MyInt& right) {
		return this->data <= right.data;
	}

	bool operator == (const MyInt& right) {
		return this->data == right.data;
	}
};

int* newInt(int n) {
	int* r = new int;
	*r = n;
	return r;
}

auto genArrPtrInt(int* arr, const int l) {
	int** r = new int* [l];
	for (int i = 0; i < l; i++)
		r[i] = newInt(arr[i]);
	return r;
}

auto genArrPtrMyInt(int* arr, const int l) {
	MyInt** r;
	r = new MyInt*[l];
	for (int i = 0; i < l; i++)
		r[i] = new MyInt((arr[i]));
	return r;
}

auto genArrPtrInteger(int* arr, const int l) {
	Integer** r = new Integer * [l];
	for (int i = 0; i < l; i++)
		r[i] = new Integer(arr[i]);
	return r;
}

LinkedListSequence<int>* genListFromArray() {
	auto arr = genArrPtrInt(arrInt, globalLengthOfArray);
	return new LinkedListSequence<int>(arr, globalLengthOfArray);
}

LinkedListSequence<int>* genListFromSortedArray() {
	auto arr = genArrPtrInt(arrIntSorted, globalLengthOfArray);
	return new LinkedListSequence<int>(arr, globalLengthOfArray);
}

LinkedListSequence<MyInt>* genListFromArrayMyInt() {
	auto arr = genArrPtrMyInt(arrInt, globalLengthOfArray);
	return new LinkedListSequence<MyInt>(arr, globalLengthOfArray);
}

LinkedListSequence<MyInt>* genListFromSortedArrayMyInt() {
	auto arr = genArrPtrMyInt(arrIntSorted, globalLengthOfArray);
	return new LinkedListSequence<MyInt>(arr, globalLengthOfArray);
}

ArraySequence<Integer>* genListFromArrayInteger() {
	auto arr = genArrPtrInteger(arrInt, globalLengthOfArray);
	return new ArraySequence<Integer>(arr, globalLengthOfArray);
}

ArraySequence<Integer>* genListFromSortedArrayInteger() {
	auto arr = genArrPtrInteger(arrIntSorted, globalLengthOfArray);
	return new ArraySequence<Integer>(arr, globalLengthOfArray);
}

int main()
{
	auto ASeq = genListFromArrayInteger();


	auto ASeq_1 = genListFromArrayInteger();
	auto ASeq_2 = new ArraySequence<Integer>(*ASeq_1);


	ASeq = genListFromArrayInteger();


	ASeq = genListFromArrayInteger();


	ASeq = genListFromArrayInteger();



	ASeq = genListFromArrayInteger();
	auto SubASeq = ASeq->GetSubsequence(1, ASeq->GetLength() / 2);



	ASeq = genListFromArrayInteger();

	ASeq->Resize(0);


	ASeq = genListFromArrayInteger();
	ASeq->Set(0, ASeq->GetLast());



	ASeq = genListFromArrayInteger();
	ASeq->Append(ASeq->GetFirst());


	 ASeq = genListFromArrayInteger();
	ASeq->Prepend(ASeq->GetFirst());


	ASeq = genListFromArrayInteger();
	auto elemInsert = new Integer((ASeq->GetLast()->GetNumber() + ASeq->GetFirst()->GetNumber()));
	auto elem0 = ASeq->GetFirst();
	auto elem1 = ASeq->Get(1);

	ASeq->InsertAt(elemInsert, 1);


	ASeq_1 = genListFromArrayInteger();
	ASeq_2 = ASeq_1->GetSubsequence(1, ASeq_1->GetLength() / 2);

	auto ASeq_concat = ASeq_1->Concat(ASeq_2);


	ASeq_concat = ASeq_2->Concat(ASeq_1);


	ASeq_1 = genListFromArrayInteger();
	for (int i = 0; i < ASeq_1->GetLength() - 1; i++) {
		ASeq_1->Resize(globalLengthOfArray - 1 - i);
	}
}