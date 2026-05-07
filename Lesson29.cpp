#include "PrintQueue.h"

int main()
{
    Printer p;

    try
    {
        p.request(Worker("Fidan", 2));
        p.request(Worker("Melek", 3));
        p.request(Worker("Madina", 1));

        p.start();
    }
    catch (const char* ex)
    {
        cout << "Exception: " << ex << endl;
    }

    return 0;
}