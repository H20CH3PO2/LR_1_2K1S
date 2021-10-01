/*
*	SorterInsertion_binaryLinkedListSequence.h
*	Version 0.1
*	Author: Nosov Artiom
*	Company:
*	Email: artiom-nj@mail.ru
*/

#pragma once
#include "SorterInsertion_binary.h"
#include "SwaperLinkedListSequence.h"
template <class T, class SeqType = LinkedListSequence<T>>
class SorterInsertion_binaryLinkedListSequence : public SorterInsertion_binary<SeqType, T> {
private:
    SwaperLinkedListSequence<T> Swaper;
    void Swap(SeqType* Sequence, int i, int j) override {
        Swaper.Swap((SeqType*)Sequence, i, j);
    }
    using SorterInsertion_binary<SeqType, T>::Insertion_binary;
public:
    SeqType* Sort(SeqType* Sequence, int startIndex, int EndIndex) override {
        auto newSeq = Sequence->GetSubsequence(startIndex, EndIndex);
        Insertion_binary(newSeq);
        return newSeq;
    }
    SeqType* Sort(SeqType* Sequence) override {
        auto newSeq = new SeqType(Sequence);
        Insertion_binary(newSeq);
        return newSeq;
    }
};