#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include<cstdlib>
#include <iostream>
#include <vector>
#include <cmath>
using namespace ariel;
using namespace std;



bool isPrime(int number) {
    if (number <= 1)
        return false;
        
    int sqrtNumber = sqrt(number);
    for (int i = 2; i <= sqrtNumber; ++i) {
        if (number % i == 0)
            return false;
    }
    
    return true;
}
TEST_CASE("class mgical"){
    MagicalContainer containr;
    CHECK_THROWS(containr.removeElement(5));
    CHECK(containr.size()==0);
    for(int i =1; i<=10;i++)
        CHECK_NOTHROW(containr.addElement(i));
    CHECK(containr.size()==10);
    CHECK_NOTHROW(containr.removeElement(6));
    CHECK(containr.size()==9);
    CHECK_THROWS(containr.removeElement(6));
    CHECK_NOTHROW(containr.addElement(6));
    for(int i =1; i<=10;i++)
        CHECK_NOTHROW(containr.removeElement(i));
    CHECK(containr.size()==0);
    CHECK_THROWS(containr.removeElement(0));
}
TEST_CASE("class AscendingIterator"){
    MagicalContainer containr;
    srand((unsigned) time(NULL));
    for(int i=0;i<20;i++)
    {
        int temp=rand();
        containr.addElement(temp); 
    }
    MagicalContainer::AscendingIterator asiterator(containr);
    vector<int> sorted;
    for (auto it = asiterator.begin(); it != asiterator.end(); ++it) {
        sorted.push_back(*it);
    }
    for(int i=0;i<sorted.size()-1;i++){
        bool a= sorted[i] < sorted[i+1];
        CHECK(a);
    }
}
TEST_CASE("class crossIterator"){
    MagicalContainer containr;
    for(int i=1;i<=10;i=i+2)
    {
       containr.addElement(i);
    }
    for(int i=10;i>0;i=i-2)
    {
       containr.addElement(i);
    }
    MagicalContainer::SideCrossIterator sciterator(containr);
    vector<int> cross;
    for (auto it = sciterator.begin(); it != sciterator.end(); ++it) {
        cross.push_back(*it);
    }
    for(int i=0;i<10;i++){
        CHECK(cross[i]==i+1);
    }
}
TEST_CASE("class PrimeIterator"){
    MagicalContainer containr;
    srand((unsigned) time(NULL));
    for(int i=0;i<10;i++)
    {
        int temp=rand();
        containr.addElement(temp); 
    }
    containr.addElement(17);
    containr.addElement(13);
    containr.addElement(7);
    containr.addElement(2);
    MagicalContainer::PrimeIterator priterator(containr);
    vector<int> primes;
    for (auto it = priterator.begin(); it != priterator.end(); ++it) {
        primes.push_back(*it);
    }
    for(int i=0;i<primes.size();i++){
        CHECK(isPrime(primes[i]));
    }
}
TEST_CASE("operator >"){
    // MagicalContainer containr;
    // MagicalContainer::AscendingIterator asiterator(containr);
    // MagicalContainer::PrimeIterator priterator(containr);
    // MagicalContainer::PrimeIterator priterator(containr);

}