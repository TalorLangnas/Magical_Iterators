#ifndef MAGICL_CONTAINER_HPP
#define MAGICL_CONTAINER_HPP
#include <map>
#include <cstdlib>
#include <iostream>
#include <type_traits>
#include <set>
#include <vector>
#include <list>
#include <cmath>

using namespace std;

namespace ariel
{

    class MagicalContainer
    {
    public:
        vector<int> container;
        vector<int *> prime_container;

        void addElement(int);
        int size();
        void removeElement(int);
        void update_prime();

        // --------------- AscendingIterator --------------

        class AscendingIterator
        {
        private:
            MagicalContainer &magical_container;
            vector<int>::iterator iter;
            size_t curr;

        public:
            //  Default constructor
            AscendingIterator(MagicalContainer &);
            // Copy constructor
            AscendingIterator(const AscendingIterator &);
            // Destructor
            ~AscendingIterator() = default;
            // Assignment operator
            AscendingIterator &operator=(const AscendingIterator &other);                      // Copy assignment operator
            AscendingIterator(AscendingIterator &&other) noexcept = default;                   // Move constructor
            AscendingIterator &operator=(AscendingIterator &&other) noexcept { return *this; } // Move assignment operator

            // Equality comparison (operator==)
            bool operator==(const AscendingIterator &other) const;
            // Inequality comparison (operator!=)
            bool operator!=(const AscendingIterator &other) const;

            bool operator>(const AscendingIterator &other);
            bool operator<(const AscendingIterator &other);
            // Dereference operator (operator*)
            int operator*();
            // Pre-increment operator (operator++)
            AscendingIterator &operator++();
            // Post-increment operator (operator++)
            // AscendingIterator operator++(int);
            // begin(type): Returns the appropriate iterator
            AscendingIterator begin();
            // end(type): Returns the appropriate iterator
            AscendingIterator end();
        };

        class SideCrossIterator
        {
        private:
            MagicalContainer &magical_container;
            vector<int>::iterator reg_iter;
            vector<int>::reverse_iterator riter;
            size_t curr_left;
            size_t curr_right;
            int counter;

        public:
            //  Default constructor
            SideCrossIterator(MagicalContainer &);
            // Copy constructor
            SideCrossIterator(const SideCrossIterator &);
            // Destructor
            ~SideCrossIterator() = default;
            // Assignment operator
            SideCrossIterator &operator=(const SideCrossIterator &other);                      // Copy assignment operator
            SideCrossIterator(SideCrossIterator &&other) noexcept = default;                   // Move constructor
            SideCrossIterator &operator=(SideCrossIterator &&other) noexcept { return *this; } // Move assignment operator

            // Equality comparison (operator==)
            bool operator==(const SideCrossIterator &other) const;
            // Inequality comparison (operator!=)
            bool operator!=(const SideCrossIterator &other) const;

            bool operator>(const SideCrossIterator &other);
            bool operator<(const SideCrossIterator &other);
            // Dereference operator (operator*)
            int operator*();
            // Pre-increment operator (operator++)
            SideCrossIterator &operator++();
            // Post-increment operator (operator++)
            // SideCrossIterator operator++(int);
            // begin(type): Returns the appropriate iterator
            SideCrossIterator begin();
            // end(type): Returns the appropriate iterator
            SideCrossIterator end();
        };

        class PrimeIterator
        {
        private:
            MagicalContainer &magical_container;
            vector<int *>::iterator iter;
            size_t curr;

        public:
            //  Default constructor
            PrimeIterator(MagicalContainer &);
            // Copy constructor
            PrimeIterator(const PrimeIterator &);
            // Destructor
            ~PrimeIterator() = default;
            // Assignment operator
            PrimeIterator &operator=(const PrimeIterator &other);                      // Copy assignment operator
            PrimeIterator(PrimeIterator &&other) noexcept = default;                   // Move constructor
            PrimeIterator &operator=(PrimeIterator &&other) noexcept { return *this; } // Move assignment operator

            // Equality comparison (operator==)
            bool operator==(const PrimeIterator &other) const;
            // Inequality comparison (operator!=)
            bool operator!=(const PrimeIterator &other) const;

            bool operator>(const PrimeIterator &other);
            bool operator<(const PrimeIterator &other);
            // Dereference operator (operator*)
            int operator*();
            // Pre-increment operator (operator++)
            PrimeIterator &operator++();
            // Post-increment operator (operator++)
            // PrimeIterator operator++(int);
            // begin(type): Returns the appropriate iterator
            PrimeIterator begin();
            // end(type): Returns the appropriate iterator
            PrimeIterator end();
        };
    };
};
#endif