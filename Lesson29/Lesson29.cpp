#include "PrintQueue.h"

int main()
{
    Printer printer;

    try
    {
        printer.request(Worker("Aysel", "Quliyeva", 22, 2));
        printer.request(Worker("Orxan", "Kerimov", 18, 3));
        printer.request(Worker("Nigar", "Rzayeva", 25, 1));

        printer.start();
    }
    catch (const char* ex)
    {
        cout << "Exception: " << ex << endl;
    }

    return 0;
}