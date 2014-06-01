#define _QUEUE_H_
#include <iostream>
#include <string>
 
/**
@brief Класс для работы c очередью
@detailed с функциями вставк в конец очереди, удаление из начала очереди
получение значение элемента в начале очереди
*/

template<class T>
class NodeQueue
{
public:

/**
@brief Конструктор
*/

        NodeQueue():head(0), tail(0)
        {
        }
 
        ~NodeQueue()
        {
             while(head)
             {
                 tail=head->next;
                 delete head;
                 head=tail;
             }
        }
 
        void enqueue(T val)
        {
                Node* Temp=new Node;
                Temp->elem=val;
                if(head==0)
                {
                        head=Temp;
                        tail=Temp;
                        return;
                }
                tail->next=Temp;
                tail=Temp;
        }
 
        void dequeue()
        {
                if (empty())
                {
                        throw std::string("Queue is empty");
                }
                Node* delPtr=head;
                std::cout<<"Element "<< head->elem <<" is deleted from the queue\n";
                head=head->next;
                delete delPtr;
        }
 
        const T& front() const
        {
                if (empty())
                {
                        throw std::string("Queue is empty");
                }
                return head->elem;
        }
 
/**
@brief Функция вывода
*/

        void print() const
        {
                if (empty())
                {
                        throw std::string("Queue is empty");
                }
                for(Node* ptr=head; ptr!=0; ptr=ptr->next)
                        std::cout<<ptr->elem<<' ';
                std::cout<<'\n';
        }
 
        bool empty() const
        {
                return head==0;
        }
private:
        struct Node
        {
                Node():next(0), elem(0)
                {
                }
                Node* next;
                T elem;
        };
        Node* head;
        Node* tail;
};