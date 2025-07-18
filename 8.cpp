#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int findHeatingSeasonStart(const vector<double>& dayTemps, const vector<double>& nightTemps) {
    for (int i = 2; i < dayTemps.size(); i++) {
        double avg1 = (dayTemps[i - 2] + nightTemps[i - 2]) / 2;
        double avg2 = (dayTemps[i - 1] + nightTemps[i - 1]) / 2;
        double avg3 = (dayTemps[i] + nightTemps[i]) / 2;

        if (avg1 < 8.0 && avg2 < 8.0 && avg3 < 8.0) {
            return i - 1;
        }
    }
    return -1;
}

int main() {
    setlocale(LC_ALL, "Russian");

    vector<double> dayTemps = { 12.5, 11.8, 10.2, 9.5, 8.7, 7.9, 7.5, 7.2, 6.8,
                              6.5, 6.2, 5.9, 5.5, 5.3, 5.1, 4.9, 4.7, 4.5,
                              4.3, 4.1, 3.9, 3.7, 3.5, 3.3, 3.1, 2.9, 2.7,
                              2.5, 2.3, 2.1, 1.9 };

    vector<double> nightTemps = { 8.5, 8.2, 7.8, 7.2, 6.8, 6.2, 5.8, 5.5, 5.2,
                                4.9, 4.6, 4.3, 4.0, 3.8, 3.6, 3.4, 3.2, 3.0,
                                2.8, 2.6, 2.4, 2.2, 2.0, 1.8, 1.6, 1.4, 1.2,
                                1.0, 0.8, 0.6, 0.4 };

    int startDay = findHeatingSeasonStart(dayTemps, nightTemps);

    if (startDay != -1) {
        cout << "Отопительный сезон начался " << startDay + 1 << " октября" << endl;
        cout << "Температуры за 3 дня:" << endl;
        cout << fixed << setprecision(1);

        for (int i = startDay; i < startDay + 3; i++) {
            double avg = (dayTemps[i] + nightTemps[i]) / 2;
            cout << i + 1 << " октября: день=" << dayTemps[i]
                << "°C, ночь=" << nightTemps[i]
                    << "°C, средняя=" << avg << "°C" << endl;
        }
    }
    else {
        cout << "Отопительный сезон еще не начался" << endl;
    }

    return 0;
}