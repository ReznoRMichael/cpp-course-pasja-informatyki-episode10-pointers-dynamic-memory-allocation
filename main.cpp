#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

long long int ile;

clock_t start, stop;    // zmienne do obliczania czasu
double czas;    // zmienna do przechowywania czasu

int main()
{
    cout << "Ile liczb w tablicy: ";
    cin >> ile;

    long long int *tablica;   // wskaznik tablica - dynamiczna alokacja pamieci
    tablica = new long long int[ile];

    start = clock();  // rozpoczecie odliczania czasu procesora

    for (long long int i=0; i<ile; i++)
    {
        tablica[i] = i;
        tablica[i] += 50;
    }

    stop = clock();
    czas = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << "Czas zapisu (bez wskaznika): " << czas << endl;
    cout << "Tablica pokazuje na: " << tablica[ile-1] << endl;

    delete [] tablica;

    tablica = new long long int[ile]; // ponowna alokacja
    long long int *wskaznik = tablica;

    start = clock();

    for (long long int i=0; i<ile; i++)
    {
        *wskaznik = i;
        *wskaznik += 50;
        wskaznik++;
    }

    stop = clock();
    czas = (double)(stop - start) / CLOCKS_PER_SEC;
    cout << "Czas zapisu (ze wskaznikiem): " << czas << endl;
    cout << "Wskaznik pokazuje na: " << tablica[ile-1] << endl;
    cout << "CLOCKS_PER_SEC: " << CLOCKS_PER_SEC << endl;

    delete [] tablica;

/*    for (int i=0; i<ile; i++)
    {
        cout << (int)tablica << endl;   // (int) rzutowanie zmiennej
        tablica++;
    }
*/

    return 0;
}
