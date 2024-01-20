#include "string.h"


int main(void)
{
   Utilities::String str{ "String 1" };
   std::cout << str << std::endl;
  /* str.clear();
   std::cout << str << std::endl;*/
   str.reserve(44);
   std::cout << str << std::endl;
   str.shrink_to_fit();
   std::cout << str << std::endl;
}