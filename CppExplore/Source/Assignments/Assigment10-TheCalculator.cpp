#include <iostream>

#define MAX_RAND 199

int main(void)
{
   std::srand(std::time(0));

   const char operators[]{ '+', '-', '*' };   

   std::cout << "Welcome to the greatest calculator on Earth!" << std::endl;

   while (true)
   {
      const int leftOperand{ std::rand() % MAX_RAND };
      const int rightOperand{ std::rand() % MAX_RAND };
      const char randOperator{ operators[std::rand() % std::size(operators)] };

      std::cout << "What is the result of " << leftOperand << " " << randOperator << " " << rightOperand << " : ";

      int userAnswer;
      std::cin >> userAnswer;

      int answer;
      if (randOperator == '+') {
         answer = leftOperand + rightOperand;
      }
      else if (randOperator == '-') {
         answer = leftOperand - rightOperand;
      }
      else if (randOperator == '*') {
         answer = leftOperand * rightOperand;
      }

      if (userAnswer == answer) {
         std::cout << "Congradulations! You got the result " << answer << " right!" << std::endl;
      }
      else {
         std::cout << "Naah! the correct result is : " << answer << std::endl;
      }

      std::cout << "Do you want me to try again? (Y | N) : ";

      char end;
      std::cin >> end;
      if (end == 'n') break;

      std::cout << std::endl;
   }

   std::cout << "See you later!" << std::endl;
}
