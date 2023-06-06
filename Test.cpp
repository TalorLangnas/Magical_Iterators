#include "doctest.h"
#include <stdexcept>
#include "sources/MagicalContainer.hpp"


using namespace ariel;

// -------------- addElement Test --------------
TEST_CASE("addElement Test")
{
    MagicalContainer container;
    MagicalContainer::AscendingIterator it(container);
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    CHECK(container.size() == 3);
    CHECK(*it == 1);
    ++it;
    CHECK(*it == 2);
    ++it;
    CHECK(*it == 3);


}
TEST_CASE("addElement by checking the size")
{

}

// -------------- removeElement Test -------------- 
TEST_CASE("element does not in the container")
{   
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);

    CHECK_THROWS_AS(container.removeElement(4), std::runtime_error);
    CHECK_NOTHROW(container.removeElement(2));
    CHECK(container.size() == 2);
}
TEST_CASE("remove from empty container")
{
    MagicalContainer container;
    CHECK(container.size() == 0);
    CHECK_THROWS_AS(container.removeElement(1), std::runtime_error);
}
TEST_CASE("remove the correct element")
{
    MagicalContainer container;
    MagicalContainer::AscendingIterator it(container);
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    CHECK_NOTHROW(container.removeElement(2));
    CHECK(*it == 1);
    ++it;
    CHECK_FALSE(*it == 2);
    CHECK(*it == 3);    

}
TEST_CASE("remove all the elements with for loop and throw error")
{
    MagicalContainer container;
    int i = 0;
    while(i < 10)
    {
        container.addElement(i);
        i++;
    }
    
    CHECK(container.size() == 10);
    while(i <= 0)
    {
        container.removeElement(i);
        i--;
    }
    CHECK(container.size() == 0);
    CHECK_THROWS_AS(container.removeElement(i), std::runtime_error);
}

// -------------- size Test -------------- 
TEST_CASE("size() Test")
{
    MagicalContainer container;
    CHECK(container.size() == 0);
    
    for(int i = 0; i < 10; i++)
    {
        container.addElement(i);
        CHECK(container.size() == i);
    }
    CHECK(container.size() == 10);
}

// ------------------------ AscendingIterator Test --------------

TEST_CASE("check if the iteration is in the same order") 
{
    MagicalContainer container;
    MagicalContainer::AscendingIterator it(container);
    int i = 10;
    while(i <= 0)
    {
        container.addElement(i);
        i--;
    }
    for(int i = 0; i < 10; i++)
    {
        container.addElement(i);
        CHECK(*it == i);
        ++it;
    }    
}

TEST_CASE("Check the iteration after remove element") 
{
    MagicalContainer container;
    MagicalContainer::AscendingIterator it(container);
    container.addElement(10);
    container.addElement(2);
    container.addElement(5);
    container.addElement(1);
    
    container.removeElement(5);
    CHECK(*it == 1);
    ++it;
    CHECK(*it == 2);
    ++it;
    CHECK(*it == 10);
}

TEST_CASE("Equality comparison (operator==) Test") 
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(10);
    MagicalContainer::AscendingIterator it_1(container);
    MagicalContainer::AscendingIterator it_2(container);
    CHECK(*it_1 == 1);
    CHECK(*it_2 == 1);
    CHECK(it_1 == it_2);
}
TEST_CASE("Equality comparison (operator!=) Test") 
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(10);
    MagicalContainer::AscendingIterator it_1(container);
    MagicalContainer::AscendingIterator it_2(container);
    CHECK(it_1 != it_2);
}
TEST_CASE("Equality comparison (operator>) Test") 
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(10);
    MagicalContainer::AscendingIterator it_1(container);
    MagicalContainer::AscendingIterator it_2(container);
    ++it_2;
    CHECK(it_2 > it_1);

}
TEST_CASE("Equality comparison (operator<) Test") 
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(10);
    MagicalContainer::AscendingIterator it_1(container);
    MagicalContainer::AscendingIterator it_2(container);
    ++it_2;
    CHECK(it_1 < it_2);
}
TEST_CASE("Equality comparison (operator*) Test") 
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(10);
    MagicalContainer::AscendingIterator it_1(container);
    CHECK(*it_1 == 1);
}
TEST_CASE("Post-increment operator (operator++) Test") 
{
    MagicalContainer container;
    MagicalContainer::AscendingIterator it(container);
    container.addElement(5);
    container.addElement(1);
    container.addElement(8);
    container.addElement(6);
    CHECK(*it == 1);
    ++it;
    CHECK(*it == 5);
    ++it;
    CHECK(*it == 6);
    ++it;
    CHECK(*it == 8);
}
TEST_CASE("begin() Test") 
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(1);
    container.addElement(2);
    MagicalContainer::AscendingIterator it(container);
    MagicalContainer::AscendingIterator iter(container);
    ++it;
    ++it;
    it = iter.begin();
    CHECK(*it == 1);
}
TEST_CASE("end() Test") 
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(1);
    container.addElement(2);
    MagicalContainer::AscendingIterator it(container);
    MagicalContainer::AscendingIterator iter(container);
    ++it;
    ++it;
    ++it;
    
    CHECK(it == iter.end());
    
}


// ------------------------ SideCrossIterator Test --------------

TEST_CASE("check if the iteration is in the correct order") 
{
    MagicalContainer container;
    MagicalContainer::AscendingIterator it(container);
    int i = 0;
    while(i < 4)
    {
        container.addElement(i);
        i++;
    }
    // 1, 2, 3, 4
    // 1, 4, 2, 3
    CHECK(*it == 0);
    ++it;
    CHECK(*it == 4);
    ++it;
    CHECK(*it == 2);
    ++it;
    CHECK(*it == 3);

}

TEST_CASE("Check the iteration after remove element") 
{
MagicalContainer container;
MagicalContainer::AscendingIterator it(container);
int i = 0;
while(i < 4)
{
    container.addElement(i);
    i++;
}
container.removeElement(4);
// 1, 2, 3, 4
// 1, 4, 2, 3
CHECK(*it == 0);
    ++it;
    CHECK(*it == 3);
    ++it;
    CHECK(*it == 2);
    ++it;
    CHECK(*it == NULL);
}

TEST_CASE("Equality comparison (operator==) Test") 
{
    MagicalContainer container;
    MagicalContainer::AscendingIterator it_1(container);
    MagicalContainer::AscendingIterator it_2(container);
    container.addElement(1);
    container.addElement(10);    
    CHECK(*it_1 == 1);
    CHECK(*it_2 == 1);
    CHECK(it_1 == it_2);
}
TEST_CASE("Equality comparison (operator!=) Test") 
{
    MagicalContainer container;
    MagicalContainer::AscendingIterator it_1(container);
    MagicalContainer::AscendingIterator it_2(container);
    container.addElement(1);
    container.addElement(10); 
    ++it_2;   
    CHECK(*it_1 == 1);
    CHECK_FALSE(*it_2 == 1);
    CHECK(it_1 != it_2);
}
TEST_CASE("Equality comparison (operator>) Test") 
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(10);
    MagicalContainer::AscendingIterator it_1(container);
    MagicalContainer::AscendingIterator it_2(container);
    ++it_2;
    CHECK(it_2 > it_1);
}
TEST_CASE("Equality comparison (operator<) Test") 
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(10);
    MagicalContainer::AscendingIterator it_1(container);
    MagicalContainer::AscendingIterator it_2(container);
    ++it_2;
    CHECK(it_1 < it_2);
}
TEST_CASE("Equality comparison (operator*) Test") 
{
    MagicalContainer container;
    container.addElement(10);
    container.addElement(1);
    container.addElement(9);
    MagicalContainer::AscendingIterator it_1(container);
    CHECK(*it_1 == 1);
}
TEST_CASE("begin() Test") 
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(1);
    container.addElement(2);
    MagicalContainer::AscendingIterator it(container);
    MagicalContainer::AscendingIterator iter(container);
    ++it;
    ++it;
    it = iter.begin();
    CHECK(*it == 1);
}
TEST_CASE("end() Test") 
{
    MagicalContainer container;
    container.addElement(5);
    container.addElement(1);
    container.addElement(2);
    MagicalContainer::AscendingIterator it(container);
    MagicalContainer::AscendingIterator iter(container);
    ++it;
    ++it;
    ++it;
    
    CHECK(it == iter.end());
}

// ------------------------ PrimeIterator Test --------------

TEST_CASE("check if the iteration is in the same order") 
{   
    MagicalContainer container;
    MagicalContainer::PrimeIterator it(container);
    int i = 0;
    while(i < 10)
    {
        container.addElement(i);
        i++;
    }
    //2, 3, 4, 5, 6, 7, 8, 9, 
   CHECK(*it == 2);
   ++it;
   CHECK(*it == 3);
   ++it;
   CHECK(*it == 5);
   ++it;
   CHECK(*it == 7);
}

TEST_CASE("Check the iteration after remove element") 
{
    MagicalContainer container;
    MagicalContainer::PrimeIterator it(container);
    int i = 0;
    while(i < 10)
    {
        container.addElement(i);
        i++;
    }
    container.removeElement(3);
    //2, 3, 4, 5, 6, 7, 8, 9, 
   CHECK(*it == 2);
   ++it;
   CHECK(*it == 5);
}

TEST_CASE("Equality comparison (operator==) Test") 
{

    MagicalContainer container;
    MagicalContainer::PrimeIterator it_1(container);
    MagicalContainer::PrimeIterator it_2(container);
    container.addElement(2);
    container.addElement(3);    
    CHECK(*it_1 == 2);
    CHECK(*it_2 == 2);
    CHECK(it_1 == it_2);
}
TEST_CASE("Equality comparison (operator!=) Test") 
{
    MagicalContainer container;
    MagicalContainer::PrimeIterator it_1(container);
    MagicalContainer::PrimeIterator it_2(container);
    container.addElement(2);
    container.addElement(3);    
    ++it_2;
    CHECK(it_1 != it_2);
}
TEST_CASE("Equality comparison (operator>) Test") 
{
    MagicalContainer container;
    MagicalContainer::PrimeIterator it_1(container);
    MagicalContainer::PrimeIterator it_2(container);
    container.addElement(2);
    container.addElement(3);    
    ++it_2;
    CHECK(it_2 > it_1);
}
TEST_CASE("Equality comparison (operator<) Test") 
{
    MagicalContainer container;
    MagicalContainer::PrimeIterator it_1(container);
    MagicalContainer::PrimeIterator it_2(container);
    container.addElement(2);
    container.addElement(3);    
    ++it_2;
    CHECK(it_1 < it_2);
}
TEST_CASE("Equality comparison (operator*) Test") 
{
    MagicalContainer container;
    container.addElement(10);
    container.addElement(1);
    container.addElement(9);
    MagicalContainer::AscendingIterator it_1(container);
    CHECK(*it_1 == 1);
}
TEST_CASE("Post-increment operator (operator++) Test") 
{
    MagicalContainer container;
    MagicalContainer::PrimeIterator it(container);
    int i = 0;
    while(i < 10)
    {
        container.addElement(i);
        i++;
    }
    //2, 3, 4, 5, 6, 7, 8, 9, 
   CHECK(*it == 2);
   ++it;
   CHECK(*it == 3);
   ++it;
   CHECK(*it == 5);
}
TEST_CASE("begin() Test") 
{
    MagicalContainer container;
    MagicalContainer::PrimeIterator it(container);
    int i = 4;
    while(i < 10)
    {
        container.addElement(i);
        i++;
    }
    //2, 3, 4, 5, 6, 7, 8, 9, 
   auto iter = it.begin();
   CHECK(*iter == 5);
}
TEST_CASE("end() Test") 
{
    MagicalContainer container;
    MagicalContainer::PrimeIterator it(container);
    int i = 4;
    while(i < 10)
    {
        container.addElement(i);
        i++;
    }
    //2, 3, 4, 5, 6, 7, 8, 9, 
   auto iter = it.end();
   CHECK(*iter == NULL);
}