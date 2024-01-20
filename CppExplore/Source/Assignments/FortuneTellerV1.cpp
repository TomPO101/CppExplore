#include <iostream>

#define MAX_LENGTH 20

int main(void)
{
   std::srand(std::time(0));

   std::cout << "What's your name dear?" << std::endl;
   char name[MAX_LENGTH];
   std::cin.getline(name, MAX_LENGTH);

   char responses[][100] {
      "you laughing your lungs out. I've never seen this before.",
      "you running away from something really scary."
   };

   while (true) {
      const int rand{ std::rand() % static_cast<int>(std::size(responses)) };
      
      std::cout << "Oh dear " << name << ", I see " << responses[rand] << std::endl;

      std::cout << "Do you want me to try again? (Y | N) : ";

      char end;
      std::cin >> end;
      if (end == 'n') break;

      std::cout << std::endl;
   }

   std::cout << "Thats all I have time for today dear. Best wishes." << std::endl;
   std::cout << "Press any key to exit...";
   std::cin.get();
}