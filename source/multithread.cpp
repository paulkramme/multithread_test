#include<iostream>
#include<boost/thread.hpp>
#include<ncurses.h>

int counter = 0;
bool loop_switch = true;

void loop()
{
     char input;
     while(loop_switch == true)
     {
          ++counter;
          mvprintw(1,1,"LOOP: %d",counter);
          refresh();
     }

}

int main()
{
     initscr();
     raw();
     boost::thread_group tgroup; //CREATE A THREAD GROUP
     tgroup.create_thread(boost::bind(&loop)); //CREATE A THREAD IN THE THREAD GROUP; USING BIND TO ASSIGN A FUNCTION TO IT
     int input;
     input = getch();
     if(input == 'q')
     {
          loop_switch = false;
          tgroup.join_all(); //LET THREAD JOIN
          printw("MULTITHREADING EXAMPLE\n");
          refresh();
     }
     endwin();
     return 0;
}
