#include<iostream>
#include<boost/thread.hpp>
#include<string>

int counter = 0;

void loop()
{
     std::string input;
     while(true)
     {
          std::getline(std::cin, input);
          switch(input)
          {
               case 'stop':
                    goto exitloop;
          }
          ++counter
          std::cout << counter << std::endl;
     }

}


int main()
{
     boost::thread t(&loop);
     std::cout << "THREAD 'T' STARTED" << std::endl;
     exitloop:
     return 0;
}
