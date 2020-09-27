#include <iostream>
#include <string>

#include "TimePoint.hpp"
#include "Vector.hpp"

/* 
Короткевич Л. В.
github.com/anxieuse/oop_exercise_02
Создать класс TimePoint для работы с моментами времени в формате «час:минута:секунда». 
Обязательными операциями являются: 
        вычисление разницы между двумя моментами времени, 
        сумма моментов времени, 
        сложение момента времени и заданного количества секунд, 
        вычитание из момента времени заданного количества секунд, 
        вычисление во раз сколько один момент времени больше (меньше) другого, 
        сравнение моментов времени, 
        перевод в секунды и обратно, 
        перевод в минуты (с округлением до минуты) и обратно. 
Операции сложения и вычитания TimePoint, а так же сравнения (больше, меньше и равно) необходимо реализовать в виде перегрузки операторов.
Необходимо реализовать пользовательский литерал для работы с константами типа TimePoint. 
*/

const TimePoint mrn("06:00:00"), aft("12:00:00"), eve("18:00:00"), nght("00:00:00"), null("00:0:-1");

std::string operator "" _t(const char *s, size_t size)
{
	return 
		s == "morning" ? mrn.getTime() : 
        s == "afternoon" ? aft.getTime() :
        s == "evening" ? eve.getTime() :
        s == "night" ? nght.getTime() : null.getTime();
}

int main() {
    int idToDel, id, id1, id2, secs, mins;
    std::string time;
    Vector<TimePoint> tps;

    int command_idx;
    bool input = true;
    std::cout << '\n'
              << " 1  - добавить" << '\n'
              << " 2  - удалить" << '\n'
              << " 3  - сложить" << '\n'
              << " 4  - вычесть" << '\n'
              << " 5  - поделить" << '\n'
              << " 6  - сравнить" << '\n'
              << " 7  - вывести в секундах" << '\n'
              << " 8  - из секунд в час:мин:сек и вывести\n"
              << " 9  - вывести в минутах\n"
              << " 10  - из минут в час:мин:сек и вывести\n"
              << " 11 - вывести список\n"
              << " 12 - выйти" << '\n'
              << '\n';
    while (input)
    {
        std::cin >> command_idx;
        switch (command_idx)
        {
            case 1:
            {
                std::cin >> time;
                tps.push_back({time});
                break;
            }
            case 2:
            {
                std::cin >> idToDel;
                --idToDel;
                if (idToDel < tps.size() && idToDel >= 0)
                {
                    std::cout << "Временной промежуток ";
                    tps[idToDel].display();
                    std::cout << " успешно удален из списка\n";
                    tps.erase(idToDel);
                }
                else
                {
                    std::cout << "Введен некорректный индекс\n";
                }
                break;
            }
            case 3:
            {
                std::cin >> id1 >> id2;
                --id1, --id2;
                std::cout << tps[id1].getTime() << " + " << tps[id2].getTime() << " = " << (tps[id1] + tps[id2]).getTime();
                std::cout << '\n';
                break;
            }
            case 4:
            {
                std::cin >> id1 >> id2;
                --id1, --id2;
                std::cout << tps[id1].getTime() << " - " << tps[id2].getTime() << " = " << (tps[id1] - tps[id2]).getTime();
                std::cout << '\n';
                break;
            }
            case 5:
            {
                std::cin >> id1 >> id2;
                --id1, --id2;
                std::cout << tps[id1].getTime() << " / " << tps[id2].getTime() << " = " << (tps[id1]/tps[id2]);
                std::cout << '\n';
                break;
            }
            case 6:
            {
                std::cin >> id1 >> id2;
                if (tps[id1 - 1] == tps[id2 - 1])
                {
                    std::cout << "равны\n";
                }
                else
                {
                    if (tps[id1 - 1] > tps[id2 - 1])
                        std::cout << "первый больше\n";
                    else 
                        std::cout << "второй больше\n";
                }
                break;
            }
            case 7:
            {
                std::cin >> id;
                std::cout << tps[id - 1].toSecs();
                std::cout << '\n';
                break;
            }
            case 8:
            {
                std::cin >> secs;
                std::cout << fromSecs(secs);
                std::cout << '\n';
                break;
            }
            case 9:
            {
                std::cin >> id;
                std::cout << tps[id - 1].toMins();
                std::cout << '\n';
                break;
            }
            case 10:
            {
                std::cin >> mins;
                std::cout << fromMins(mins);
                std::cout << '\n';
                break;
            }
            case 11:
            {
                for(int i = 0; i < tps.size(); ++i) {
                    std::cout << i + 1 << ": ";
                    tps[i].display();
                    std::cout << "\n";
                }
                break;
            }
            case 12:
            {
                input = false;
                break;
            }
        }
    }
}

