#ifndef SPORTOWIEC_H
#define SPORTOWIEC_H
#include <QString>
class Sportowiec
{
private:
    QString nazwisko;
    int wiek;
    int punkty;
public:
    Sportowiec();
    Sportowiec(QString nazwisko,int wiek,int punkty);

    QString getNazwisko(){return nazwisko;}
    int getWiek(){return wiek;}
    int getPunkty(){return punkty;}

};

#endif // SPORTOWIEC_H
