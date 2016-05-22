#include<iostream>
#include<boost/thread.hpp>

int counter = 0;
bool loop_switch = true;

void loop()
{
     char input;
     while(loop_switch == true)
     {
          ++counter;
          std::cout << counter << std::endl;
     }

}


int main()
{
     boost::thread_group tgroup;
     std::cout << "THREAD 'T' STARTED" << std::endl;
     tgroup.create_thread(boost::bind(&loop));
     std::cout << "THREAD 'T' STOPPED" << std::endl;
     tgroup.join_all();
     return 0;
}
