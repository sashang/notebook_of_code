#include <iostream>

using namespace std;

struct LL
{
    int i;
    LL* next;
};

LL* head = nullptr;

void create_ll()
{
    LL** cur = &head;
    for (int i = 0; i < 5; i++)
    {
        LL* l = new LL;
        l->i = i;
        *cur = l;
        cur = &(l->next);
        cout << i << endl;
    }
    *cur = nullptr;
}

void print_ll(LL* start)
{
    LL* cur = start;
    while (cur)
    {
        cout << cur->i << ",";
        cur = cur->next;
    }
    cout << endl;
}

LL* rev_ll(LL* start)
{
    LL* newh = start;
    while (start->next)
    {
        LL* tmp = start->next;
        start->next = tmp->next;
        tmp->next = newh;
        newh = tmp;
    }
    return newh;
}

int main(int argc, char** argv)
{
    create_ll();
    print_ll(head);
    LL* reverse = rev_ll(head);
    print_ll(reverse);
    return 0;
}
