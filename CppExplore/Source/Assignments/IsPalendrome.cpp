#include <iostream>

#define _INT unsigned long long int

static const _INT GetNumDigits(_INT num)
{
   _INT digit{};
   _INT numDigits{};
   while (num > 0) {
      digit = num % 10;
      num /= 10;
      ++numDigits;
   }
   return numDigits;
}

static const _INT FillArrayWithDigits(_INT num, _INT* const arr)
{
   _INT digit{};
   _INT numDigits{};
   while (num > 0) {
      digit = num % 10;
      arr[numDigits] = digit;
      num /= 10;
      ++numDigits;
   }
   return numDigits;
}

static bool is_palindrome(_INT num)
{  
   _INT numDigits{ GetNumDigits(num) };

   _INT* arr{ new(std::nothrow) _INT[numDigits] };
   if (!arr)
      return false;

   FillArrayWithDigits(num, arr);

   _INT* i{ &arr[0] };
   _INT* j{ &arr[numDigits - 1]};

   while (i < j) {
      if (*i != *j)
         return false;
      ++i;
      --j;
   }

   delete[] arr;
   arr = nullptr;

   return true;
}

int main()
{
   std::cout << std::boolalpha;
   std::cout << is_palindrome(1234321);
}