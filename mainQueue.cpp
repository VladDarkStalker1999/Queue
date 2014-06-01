#include <iostream>
#include "Queue.h"
 
/**
@mainQueue Очередь
Состоит из следующих частей:
- @ref Queue очередь
*/

int main()
{
        try
        {
        NodeQueue<int> Queue;
        Queue.enqueue(10);
        Queue.enqueue(20);
        Queue.enqueue(30);
        std::cout<<"Top is: "<<Queue.front()<<'\n';
        Queue.dequeue();
        Queue.print();
        }
        catch(const std::string& e)
        {
             std::cout<<e<<'\n';
        }
		system("pause");
}