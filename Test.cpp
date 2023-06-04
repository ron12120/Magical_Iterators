#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>
using namespace ariel;
using namespace std;

bool isPrime(int number)
{
    if (number <= 1)
        return false;

    int sqrtNumber = sqrt(number);
    for (int i = 2; i <= sqrtNumber; ++i)
    {
        if (number % i == 0)
            return false;
    }

    return true;
}
TEST_CASE("class mgical")
{
    MagicalContainer containr;
    CHECK_THROWS(containr.removeElement(5));
    CHECK(containr.size() == 0);
    for (int i = 1; i <= 10; i++)
        CHECK_NOTHROW(containr.addElement(i));
    CHECK(containr.size() == 10);
    CHECK_NOTHROW(containr.removeElement(6));
    CHECK(containr.size() == 9);
    CHECK_THROWS(containr.removeElement(6));
    CHECK_NOTHROW(containr.addElement(6));
    for (int i = 1; i <= 10; i++)
        CHECK_NOTHROW(containr.removeElement(i));
    CHECK(containr.size() == 0);
    CHECK_THROWS(containr.removeElement(0));
}
TEST_CASE("class AscendingIterator")
{
    MagicalContainer containr;
    srand((unsigned)time(NULL));
    for (int i = 0; i <= 20; i++)
    {
        int temp = rand();
        containr.addElement(temp);
    }
    MagicalContainer::AscendingIterator asiterator(containr);
    vector<int> sorted;
    for (auto it = asiterator.begin(); it != asiterator.end(); ++it)
    {
        sorted.push_back(*it);
    }
    for (std::vector<int>::size_type i = 0; i < sorted.size(); ++i)
    {
        bool a = static_cast<int>(sorted[i]) > static_cast<int>(sorted[i + 1]);
        CHECK(a);
    }
}
TEST_CASE("class crossIterator")
{
    MagicalContainer containr;
    for (int i = 1; i <= 10; i = i + 2)
    {
        containr.addElement(i);
    }
    for (int i = 10; i > 0; i = i - 2)
    {
        containr.addElement(i);
    }
    MagicalContainer::SideCrossIterator sciterator(containr);
    vector<int> cross;
    for (auto it = sciterator.begin(); it != sciterator.end(); ++it)
    {
        cross.push_back(*it);
    }
    for (std::vector<int>::size_type i = 0; i < cross.size(); ++i)
    {
        bool a = static_cast<int>(cross[i]) == i + 1;
        CHECK(a);
    }
}
TEST_CASE("class PrimeIterator")
{
    MagicalContainer containr;
    srand((unsigned)time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int temp = rand();
        containr.addElement(temp);
    }
    containr.addElement(17);
    containr.addElement(13);
    containr.addElement(7);
    containr.addElement(2);
    MagicalContainer::PrimeIterator priterator(containr);
    vector<int> primes;
    for (auto it = priterator.begin(); it != priterator.end(); ++it)
    {
        primes.push_back(*it);
    }
    for (std::vector<int>::size_type i = 0; i < primes.size(); ++i)
    {
        bool a = isPrime(static_cast<int>(primes[i]));
        CHECK(a);
    }
}
TEST_CASE("operator >,<,==, ++")
{
    MagicalContainer containr;
    containr.addElement(1);
    containr.addElement(2);
    containr.addElement(4);
    containr.addElement(5);
    containr.addElement(14);

    // ascending iterator check
    MagicalContainer::AscendingIterator asiterator1(containr);
    MagicalContainer::AscendingIterator asiterator2(containr);
    asiterator1 = asiterator1.begin();
    asiterator2 = asiterator2.begin();
    CHECK(asiterator1 == asiterator2);
    ++asiterator1;
    CHECK(asiterator1 != asiterator2);
    CHECK(asiterator1 > asiterator2);
    CHECK_FALSE(asiterator1 < asiterator2);

    // cross iterator check
    MagicalContainer::SideCrossIterator sciterator1(containr);
    MagicalContainer::SideCrossIterator sciterator2(containr);
    sciterator1 = sciterator1.begin();
    sciterator2 = sciterator2.begin();
    CHECK(sciterator1 == sciterator2);
    ++sciterator1;
    CHECK(sciterator1 != sciterator2);
    CHECK(sciterator1 > sciterator2);
    CHECK_FALSE(sciterator1 < sciterator2);

    // prime iterator check
    MagicalContainer::SideCrossIterator priterator1(containr);
    MagicalContainer::SideCrossIterator priterator2(containr);
    priterator1 = priterator1.begin();
    priterator2 = priterator2.begin();
    CHECK(priterator1 == priterator2);
    ++priterator1;
    CHECK(priterator1 != priterator2);
    CHECK(priterator1 > priterator2);
    CHECK_FALSE(priterator1 < priterator2);
}

TEST_CASE(" removing function")
{
    MagicalContainer container;

    for (int i = 1; i <= 7; ++i)
    {
        container.addElement(i);
    }
    container.removeElement(6);
    MagicalContainer::AscendingIterator it(container);
    CHECK(*it == 1);
    ++it;
    CHECK(*it == 2);
    ++it;
    CHECK(*it == 3);
    ++it;
    CHECK(*it == 4);
    ++it;
    CHECK(*it == 5);
    ++it;
    CHECK(*it == 7);
    ++it;
    CHECK(it.end() == it);
}
TEST_CASE("empty container")
{
    MagicalContainer container;
    MagicalContainer::AscendingIterator it(container);
    CHECK_THROWS(*it);
}
TEST_CASE("adding the same element")
{
    MagicalContainer container;
    container.addElement(8);
    container.addElement(8);
    // check that adding only one 8
    CHECK(container.size() == 1);
}
TEST_CASE("Test geeting iterator after the end of the container")
{
    MagicalContainer container;
    for (int i = 1; i <= 10; ++i)
    {
        container.addElement(i);
    }
    MagicalContainer::AscendingIterator it(container);
    for (int i = 0; i < 10; ++i)
    {
        ++it;
    }
    CHECK_THROWS(++it);
}
