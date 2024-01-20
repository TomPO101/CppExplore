
// Your job is to write a function that takes in an unsigned long long int value
// and prints out it odd digits from the least significant to the most significant.
// For example if we have 98723713 as input, your function should use std::cout to print 317379.
// Your code should just print the digits in the specified order; no spaces in between, no new lines, no nothing!

#include <iostream>

void ShowingTheOdds(unsigned long long int val)
{
   unsigned long long int digit{};
   unsigned long long int insideNum{ val };

   while (insideNum > 0) {
      digit = insideNum % 10;

      if (digit % 2 != 0)
         std::cout << digit;

      insideNum = insideNum / 10;
   }
}

int main(void)
{
   ShowingTheOdds(98723713);
}