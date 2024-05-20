#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

struct ucenik
{
    char imePrezime[50];
    float prosjek;
};

bool cmp(ucenik &a, ucenik &b)
{
    return a.prosjek > b.prosjek;
}

int main()
{
    struct ucenik ucenici[100];
    int brUcenika = 0;
    fstream datoteka("C:\\Users\\Ga-gama\\Downloads\\GItHub\\Imenik.bin", ios ::binary | ios ::in);
    while (datoteka.read((char *)&ucenici[brUcenika], sizeof(ucenik)))
    {
        cout << ucenici[brUcenika].imePrezime << " " << ucenici[brUcenika].prosjek << endl;
        brUcenika++;
    }
    datoteka.close();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        cin.getline(ucenici[brUcenika + i].imePrezime, 50);
        cin >> ucenici[brUcenika + i].prosjek;
    }
    sort(ucenici, ucenici + brUcenika + n, cmp);
    datoteka.open("C:\\Users\\Ga-gama\\Downloads\\GItHub\\Imenik.bin", ios ::binary | ios::out | ios ::trunc);
    datoteka.write((char *)ucenici, sizeof(ucenik) * (brUcenika + n));
    datoteka.close();
}
