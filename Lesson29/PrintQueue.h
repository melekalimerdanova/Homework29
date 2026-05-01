#pragma once
#include <iostream>
using namespace std;

template<typename T, int MAX = 10>
class SimpleQueue
{
    T _container[MAX]{};
    int _front = -1;
    int _rear = -1;

public:
    void enQueue(T element)
    {
        if (isFull())
            throw "Queue overflow";

        if (isEmpty())
            _front = 0;

        _container[++_rear] = element;
    }

    void deQueue()
    {
        if (isEmpty())
            throw "Queue underflow";

        if (_front == _rear)
            _front = _rear = -1;
        else
            _front++;
    }

    T peek() const
    {
        if (isEmpty())
            throw "Queue empty";

        return _container[_front];
    }

    bool isEmpty() const
    {
        return _front == -1;
    }

    bool isFull() const
    {
        return _rear == MAX - 1;
    }
};

class Worker
{
public:
    static int idCounter;
    int id;
    string name;
    string surname;
    int age;
    int pageCount;

    Worker() {}

    Worker(string name, string surname, int age, int pageCount)
    {
        id = ++idCounter;
        this->name = name;
        this->surname = surname;
        this->age = age;
        this->pageCount = pageCount;
    }
};

int Worker::idCounter = 0;

class Printer
{
private:
    SimpleQueue<Worker, 10> workerQueue;

public:
    void request(Worker w)
    {
        workerQueue.enQueue(w);
    }

    void start()
    {
        while (!workerQueue.isEmpty())
        {
            Worker w = workerQueue.peek();

            for (int i = 1; i <= w.pageCount; i++)
            {
                cout << w.name << " " << w.surname
                    << " (Age: " << w.age << ") "
                    << "Page - " << i << endl;
            }

            cout << "Finished: " << w.name << " " << w.surname << endl << endl;

            workerQueue.deQueue();
        }
    }
};