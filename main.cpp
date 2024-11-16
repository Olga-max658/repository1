#include <iostream>

using namespace std;

struct Kinder {
    wstring name;
    string form;
    string toyInside;
    int myRating; // оценка по 100 балльной шкале
    int cost;
};

int bestRating (const Kinder* kinders, int count)
{
    if (count <= 0) return -1;

    int Max = 0;
    for (int i = 1; i < count; ++i) {
        if (kinders[i].myRating > kinders[Max].myRating) {
            Max = i;
        }
    }
    return Max;
}

int main()
{
setlocale(LC_ALL, "Russiаn");
Kinder* kinders = new Kinder[3];

Kinder Surprise;
Surprise.name = L"Киндер-Сюрприз";
Surprise.form = "Яйцо";
Surprise.toyInside = "Есть игрушка";
Surprise.myRating = 85;
Surprise.cost = 99;
kinders [0]=Surprise;


Kinder Lomtik;
Lomtik.name = L"Молочный ломтик";
Lomtik.form = "Прямоугольная";
Lomtik.toyInside = "Нет игрушки";
Lomtik.myRating = 100;
Lomtik.cost = 70;
kinders [1]=Lomtik;


Kinder MaxiKing;
MaxiKing.name = L"Макси-Кинг";
MaxiKing.form = "Овал";
MaxiKing.toyInside = "Нет игрушки";
MaxiKing.myRating = 30;
MaxiKing.cost = 85;
kinders [2]=MaxiKing;

int MyFavourite = bestRating(kinders, 3);
if (MyFavourite != -1) {
    wcout << L"Мой любимый киндер это: " << kinders[MyFavourite].name << endl;

}
else {
    wcout << L"Киндеров не нашлось..." << endl;
}

delete[] kinders;
return 0;
}

