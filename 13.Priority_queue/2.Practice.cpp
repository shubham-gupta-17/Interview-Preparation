#include <bits/stdc++.h>
using namespace std;
class person
{
public:
    int age;

    person()
    {
    }
    person(int a)
    {
        this->age = a;
    }

    bool operator<(person const &p2)
    {
        return this->age < p2->age;
    }
};

// class compare
// {
// public:
//     bool operator()(person a, person b)
//     {
//         return a.age > b.age;
//     }
// };

// struct compare
// {
//     bool operator()(person p1, person p2)
//     {
//         return p1.age > p2.age;
//     }
// };

int main()
{
    person p;
    // priority_queue<person, vector<person>, compare> pq;
    priority_queue<person> pq;
    p.age = 10;
    pq.push(p);
    p.age = 19;
    pq.push(p);
    p.age = 20;
    pq.push(p);

    while (!pq.empty())
    {
        person p1 = pq.top();
        cout << p1.age;
        pq.pop();
    }
    return 0;
}