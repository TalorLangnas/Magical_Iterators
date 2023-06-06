#include "MagicalContainer.hpp"


using namespace std;
using namespace ariel;

bool is_prime(int elem)
    {
        if (elem == 1)
        {
            return false;
        }
        else if (elem == 2)
        {
            return true;
        }
        else
        {
            for (int i = 2; i < sqrt(elem) + 1; i++)
            {
                if (elem % i == 0)
                {
                    return false;
                }
            }
            return true;
        }
    }

void MagicalContainer::update_prime()
{   
    for (auto it = container.begin(); it != container.end(); ++it) {
        if (is_prime(*it)) {
            prime_container.push_back(&(*it));
        }
    }
};
void MagicalContainer::addElement(int val)
{
    container.insert(lower_bound(container.begin(), container.end(), val), val); // adding the element to the main container

        prime_container.clear(); // delete all the pointers in the vector
        update_prime();
       

};





void MagicalContainer::removeElement(int val)
{   
    auto it = find(container.begin(), container.end(), val);
    if(it == container.end())
    {
        throw std::runtime_error("The value is not in the container");
    }
    
       prime_container.clear();
       container.erase(it);
       update_prime();      
    
};


int MagicalContainer::size()
{
    return container.size();
};

// --------------- AscendingIterator --------------

// Constructor:
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &other) : magical_container(other), iter(other.container.begin()), curr(0){};

// Copy constructor:
MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : magical_container(other.magical_container), iter(other.iter), curr(other.curr){};

// operator (=):
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
{
    if (this == &other)
        return *this;

    if (&other.magical_container != &(this->magical_container))
    {
        throw std::runtime_error("Containers are different");
    }
    
    
        magical_container = other.magical_container;
        curr = other.curr;
        iter = other.iter;
        return *this;
    
};

// Equality comparison (operator==)
bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
{
    // check if it is the same type of container:
    if (!(is_same<decltype(iter), decltype(other.iter)>::value))
    {
        throw std::invalid_argument("Iterators are not the same type");
    }
    return curr == other.curr;
};
// Inequality comparison (operator!=)
bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
{
    return !(curr == other.curr);
};

// Greater Then: (operator>)
bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other)
{
    // check if it is the same type of container:
    if (!(is_same<decltype(iter), decltype(other.iter)>::value))
    {
        throw std::invalid_argument("Iterators are not the same type");
    }
    return curr > other.curr;
};
// Lower Then: (operator>)
bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other)
{
    // check if it is the same type of container:
    if (!(is_same<decltype(iter), decltype(other.iter)>::value))
    {
        throw std::invalid_argument("Iterators are not the same type");
    }
    return curr < other.curr;
};
// Dereference operator (operator*)
int MagicalContainer::AscendingIterator::operator*()
{
    if (iter == magical_container.container.end())
    {
        throw std::runtime_error("Iterator is out of range");
    }
    return *iter;
};
// Pre-increment operator (operator++)
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
{
    if (iter == magical_container.container.end())
    {
        throw std::runtime_error("Iterator is out of range");
    }
    ++curr;
    ++iter;

    return *this;
};

// begin(type): Returns the appropriate iterator
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
{
    curr = 0;
    iter = magical_container.container.begin();

    return *this;
};
// end(type): Returns the appropriate iterator
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
{
    curr = magical_container.container.size();
    iter = magical_container.container.end();

    return *this;
};

// --------------------------- SideCrossIterator -------------------------------------

//  Default constructor
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &other) : magical_container(other), reg_iter(other.container.begin()), riter(other.container.rbegin()), curr_left(0),
                                                                                  curr_right(other.container.size() - 1), counter(0){};

// Copy constructor
MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : magical_container(other.magical_container), reg_iter(other.reg_iter), riter(other.riter), curr_left(other.curr_left), curr_right(other.curr_right), counter(other.counter){};

// Assignment operator
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
{
    if (this == &other)
        return *this;

    if (&other.magical_container != &(this->magical_container))
    {
        throw std::runtime_error("Containers are different");
    }
        magical_container = other.magical_container;
        curr_left = other.curr_left;
        curr_right = other.curr_right;
        reg_iter = other.reg_iter;
        riter = other.riter;
        counter = other.counter;
        return *this;
    
};

// Equality comparison (operator==)
bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
{
    // check if it is the same type of container:
    if (!(is_same<decltype(reg_iter), decltype(other.reg_iter)>::value))
    {
        throw std::invalid_argument("Iterators are not the same type");
    }
    if (!(is_same<decltype(riter), decltype(other.riter)>::value))
    {
        throw std::invalid_argument("Iterators are not the same type");
    }
    return (curr_left == other.curr_left) && (curr_right == other.curr_right);
};
// Inequality comparison (operator!=)
bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
{
    return !((curr_left == other.curr_left) && (curr_right == other.curr_right));
};

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other)
{
    // check if it is the same type of container:
    if (!(is_same<decltype(reg_iter), decltype(other.reg_iter)>::value))
    {
        throw std::invalid_argument("Iterators are not the same type");
    }
    if (!(is_same<decltype(riter), decltype(other.riter)>::value))
    {
        throw std::invalid_argument("Iterators are not the same type");
    }
    return curr_left > other.curr_left;
};
bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other)
{
    // check if it is the same type of container:
    if (!(is_same<decltype(reg_iter), decltype(other.reg_iter)>::value))
    {
        throw std::invalid_argument("Iterators are not the same type");
    }
    return curr_left < other.curr_left;
};
// Dereference operator (operator*)
int MagicalContainer::SideCrossIterator::operator*()
{
    if (magical_container.container.size() != 0)
    {
        
            if (curr_left > curr_right)
            {
                throw std::runtime_error("Iterator is out of range");
            }
        
    }
    if (counter % 2 == 0)
    {
        return *reg_iter;
    }
    return *riter;
};
// Pre-increment operator (operator++)
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
{
    if (magical_container.container.size() != 0)
    {
            if (curr_left > curr_right)
            {
                throw std::runtime_error("Iterator is out of range");
            }
    }
    if (counter % 2 == 0)
    {
        ++reg_iter;
        curr_left++;
        counter++;
        return *this;
    }
    ++riter;
    curr_right--;
    counter++;
    return *this;
};
// begin(type): Returns the appropriate iterator
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
{
    curr_left = 0;
    reg_iter = magical_container.container.begin();
    curr_right = magical_container.container.size() - 1;
    // reverse_iterator r_container = magical_container.container.rbegin();
    riter = magical_container.container.rbegin();
    return *this;
};
// end(type): Returns the appropriate iterator
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
{
    // if container size is even:
    if (magical_container.container.size() % 2 == 0)
    {
        curr_right = (magical_container.container.size() / 2) -1;
        curr_left = (magical_container.container.size() / 2);
        std::advance(reg_iter, curr_left);
        std::advance(riter, curr_right);
        return *this;
    }
    // if container size is odd:
    curr_right = magical_container.container.size() / 2 ;
    curr_left = (magical_container.container.size() / 2) + 1;
    std::advance(reg_iter, curr_left);
    std::advance(riter, curr_right);
    return *this;
};

// --------------------------- PrimeIterator -------------------------------------

//  Default constructor
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &other) : magical_container(other), iter(other.prime_container.begin()), curr(0){};
// Copy constructor
MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : magical_container(other.magical_container), iter(other.iter), curr(other.curr){};

// Assignment operator
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
{
    if (this == &other)
        return *this;

    if (&other.magical_container != &(this->magical_container))
    {
        throw std::runtime_error("Containers are different");
    }
    
        magical_container = other.magical_container;
        curr = other.curr;
        iter = other.iter;
     return *this;
};

// Equality comparison (operator==)
bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
{
    // check if it is the same type of container:
    if (!(is_same<decltype(iter), decltype(other.iter)>::value))
    {
        throw std::invalid_argument("Iterators are not the same type");
    }
    return curr == other.curr;
};
// Inequality comparison (operator!=)
bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
{
    return !(curr == other.curr);
};

// GT (operator>):
bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other)
{
    // check if it is the same type of container:
    if (!(is_same<decltype(iter), decltype(other.iter)>::value))
    {
        throw std::invalid_argument("Iterators are not the same type");
    }
    return curr > other.curr;
};
// LT (operator<):
bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other)
{
    // check if it is the same type of container:
    if (!(is_same<decltype(iter), decltype(other.iter)>::value))
    {
        throw std::invalid_argument("Iterators are not the same type");
    }
    return curr < other.curr;
};
// Dereference operator (operator*)
int MagicalContainer::PrimeIterator::operator*()
{
    if (iter == magical_container.prime_container.end())
    {
        throw std::runtime_error("Iterator is out of range");
    }
    return **iter;
};
// Pre-increment operator (operator++)
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
{
    if (iter == magical_container.prime_container.end())
    {
        throw std::runtime_error("Iterator is out of range");
    }
    ++curr;
    ++iter;

    return *this;
};
// begin(type): Returns the appropriate iterator
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
{
    iter = magical_container.prime_container.begin();
    curr = 0;
    return *this;
};
// end(type): Returns the appropriate iterator
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
{
    iter = magical_container.prime_container.end();
    curr = magical_container.prime_container.size();
    return *this;
};
