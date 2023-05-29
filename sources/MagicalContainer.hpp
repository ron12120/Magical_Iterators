#pragma once
#include <vector>
using namespace std;
namespace ariel
{
    class MagicalContainer
    {

    public:
        MagicalContainer() {}
        void addElement(int number) {}
        int size() const { return 0; }
        void removeElement(int number) {}

        class AscendingIterator
        {

        public:
            AscendingIterator() {}
            AscendingIterator(const AscendingIterator &asitearator) {}
            AscendingIterator(const MagicalContainer &magicont) {}
            AscendingIterator begin() const { return *this; }
            AscendingIterator end() const { return *this; }
            AscendingIterator operator++() { return *this; }
            void operator=(const AscendingIterator &asitearator) {}
            int operator*() const { return 0; }
            bool operator!=(const AscendingIterator &asiterator) const { return false; }
            bool operator==(const AscendingIterator &asiterator) const { return false; }
            bool operator>(const AscendingIterator &asiterator) const { return false; }
            bool operator<(const AscendingIterator &asiterator) const { return false; }
            ~AscendingIterator() {}
        };
        class SideCrossIterator
        {

        public:
            SideCrossIterator() {}
            SideCrossIterator(const SideCrossIterator &scitearator) {}
            SideCrossIterator(const MagicalContainer &magicalcont) {}
            SideCrossIterator begin() const { return *this;}
            SideCrossIterator end() const { return *this; }
            SideCrossIterator operator++() { return *this; }
            void operator=(const SideCrossIterator &scitearator) {}
            int operator*() const { return 0; }
            bool operator!=(const SideCrossIterator &sciterator) const { return false; }
            bool operator==(const SideCrossIterator &sciterator) const { return false; }
            bool operator>(const SideCrossIterator &sciterator) const { return false; }
            bool operator<(const SideCrossIterator &sciterator) const { return false; }
            ~SideCrossIterator() {}
        };
        class PrimeIterator
        {

        public:
            PrimeIterator() {}
            PrimeIterator(const PrimeIterator &priterator) {}
            PrimeIterator(const MagicalContainer &magicalcont) {}
            PrimeIterator begin() const { return *this; }
            PrimeIterator end() const { return *this; }
            PrimeIterator operator++() { return *this; }
            void operator=(const PrimeIterator scitearator) {}
            int operator*() const { return 0; }
            bool operator!=(const PrimeIterator &sciterator) const { return false; }
            bool operator==(const PrimeIterator &sciterator) const { return false; }
            bool operator>(const PrimeIterator &sciterator) const { return false; }
            bool operator<(const PrimeIterator &sciterator) const { return false; }
            ~PrimeIterator() {}
        };
    };

};
