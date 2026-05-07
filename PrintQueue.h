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
    SimpleQueue() = default;

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

        _front++;

        if (_front > _rear)
            _front = _rear = -1;
    }

    T peek() const
    {
        if (isEmpty())
            throw "Queue is empty";

        return _container[_front];
    }

    int size() const
    {
        if (_front == -1) return 0;
        return _rear - _front + 1;
    }

    bool isEmpty() const { return size() == 0; }
    bool isFull() const { return size() == MAX; }
};

class Worker
{
public:
    static int idCounter;
    int id;
    string name;
    int pageCount;

    Worker() {}

    Worker(string name, int pageCount)
    {
        this->id = ++idCounter;
        this->name = name;
        this->pageCount = pageCount;
    }
};

int Worker::idCounter = 0;

class Printer
{
private:
    SimpleQueue<Worker, 10> queue;

public:
    void request(Worker w)
    {
        queue.enQueue(w);
    }

    void start()
    {
        while (!queue.isEmpty())
        {
            Worker w = queue.peek();
            queue.deQueue();

            cout << "Worker ID: " << w.id
                << " | " << w.name << " printing..." << endl;

            for (int i = 1; i <= w.pageCount; ++i)
            {
                cout << w.name << " Page - " << i << endl;
            }

            cout << "Finished " << w.name << endl << endl;
        }
    }
};