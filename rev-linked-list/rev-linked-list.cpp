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
    LL* cur = start;
    LL* next_list = cur->next;
    cur->next = nullptr;
    while (next_list)
    {
        LL* temp = next_list->next;
        next_list->next = cur;
        cur = next_list;
        next_list = temp;
    }
    return cur;
}

int main(int argc, char** argv)
{
    create_ll();
    print_ll(head);
    LL* reverse = rev_ll(head);
    print_ll(reverse);
    return 0;
}
