#include <iostream>
using namespace std;

struct Elem
{
    Elem* link;
    int info;
};

void enqueue(Elem*& first, Elem*& last, int info) {
    Elem* tmp = new Elem;
    tmp->info = info;
    tmp->link = NULL;
    if (last != NULL)
        last->link = tmp;
    last = tmp;
    if (first == NULL)
        first = tmp;
}

void print(const Elem* first)
{
    int i = 0;
    while (first != nullptr)
    {
        cout << first->info << " ";
        i++;
        first = first->link;
    }
    cout << endl;
}

int count(const Elem* L)
{
    int k = 0;
    while (L != nullptr)
    {
        k++;
        L = L->link;
    }
    return k;
}

void remove(Elem*& first, int x)
{
    for (int i = 0; i < count(first); i++)
    {
        Elem** first1 = &first;
        while (*first1 && (*first1)->info != x)
        {
            first1 = &(*first1)->link;
        }
        if (!*first1)
        {
            return;
        }
        Elem* tmp = (*first1)->link;
        delete* first1;
        *first1 = tmp;
    }
}
int main() {
    Elem* first = nullptr, * last = nullptr;
    enqueue(first, last, 1);
    enqueue(first, last, 22);
    enqueue(first, last, 23);
    enqueue(first, last, 47);
    enqueue(first, last, 3);
    enqueue(first, last, 8);
    enqueue(first, last, 11);
    enqueue(first, last, 1);
    print(first);
    int a;
    cout << "remove number "; cin >> a;
    remove(first, a);
    print(first);
    return 0;
}