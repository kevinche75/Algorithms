#include <iostream>
#include <set>
#include <utility>
#include <map>
#include "functional"

using namespace std;

struct City {
    long long money;
    int days;
} city[60000];

struct Person {
    long long money;
    City *location;
} person[10000];

map<string, Person *> person_list;
map<string, City *> city_list;
set<pair<long long, City *>, greater<>> score;

int main() {

    int n;
    cin >> n;
    string name_person;
    string name_city;
    long long money;
    int city_nums = 0;
    for (int i = 0; i < n; i++) {
        cin >> name_person >> name_city >> money;

        if (!city_list[name_city]) {
            city[city_nums].money = money;
            city_list[name_city] = &city[city_nums];
            city_nums++;
        } else {
            city_list[name_city]->money += money;
        }

        person[i].money = money;
        person[i].location = city_list[name_city];
        person_list[name_person] = &person[i];
    }

    for (auto &item : city_list) {
        score.insert({item.second->money, item.second});
    }

    int m, k, today = 0;
    cin >> m >> k;
    
    int day;

    for (int i = 0; i < k; i++) {
        cin >> day >> name_person >> name_city;

        int count = day - today;
        today = day;

        auto second_city = score.begin();
        auto first_city = second_city++;

        if (second_city == score.end() || first_city->first > second_city->first) {
            first_city->second->days += count;
        }

        City *to_city = city_list[name_city];
        Person *current_p = person_list[name_person];

        if (to_city == nullptr) {
            city_list[name_city] = &city[city_nums];
            city_nums++;
            to_city = city_list[name_city];
        }

        score.erase({current_p->location->money, current_p->location});
        score.erase({to_city->money, to_city});
        current_p->location->money -= current_p->money;
        score.insert({current_p->location->money, current_p->location});
        current_p->location = to_city;
        to_city->money += current_p->money;
        score.insert({to_city->money, to_city});
    }

    int count = m - today;
    auto second_city = score.begin();
    auto first_city = second_city++;
    if (second_city == score.end() || first_city->first > second_city->first) {
        first_city->second->days += count;
    }

    for (auto &item : city_list) {
        if (item.second->days > 0) {
            cout << item.first << " " << item.second->days << endl;
        }
    }

    return 0;
}