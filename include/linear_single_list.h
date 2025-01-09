#include <iostream>
using namespace std;

struct Node // структура для описания узла в списке
{
    int info;
    Node *next;
    Node(int x)
    {
        info = x;
        next = nullptr;
    }
};

class LinearSingleList // сам класс «Линейный список»
{
public:
    LinearSingleList();
    ~LinearSingleList();
    void addFirst(int x);
    bool delNode(int valueToDelete);
    // ………………………………………………………………..
private:
    Node *head; // голова списка
    Node *tail; // хвост списка
};
LinearSingleList::LinearSingleList()
{
    head = nullptr;
    tail = nullptr;
}
LinearSingleList::~LinearSingleList()
{
    Node *tmp = nullptr;
    while (head != nullptr)
    {
        tmp = head;
        head = head->next;
        delete tmp;
    }
    tail = nullptr;
    cout << "Список удален";
}
void LinearSingleList::addFirst(int x)
{
    Node *tmp = new Node(x);
    tmp->next = head;
    if (head == nullptr)
    {
        tail = tmp;
    }
    head = tmp;
}
bool LinearSingleList::delNode(int valueToDelete) // удаление заданного узла
{
    Node *p; // указатель на удаляемое из списка звено
    // вспомогательный указатель для поиска звена списка,
    // предшествующего удаляемому
    Node *p1;
    bool found; // признак, найден ли удаляемый элемент в списке
    found = false;
    if (head != nullptr)
    {                                    // если список не пуст
        if (head->info == valueToDelete) // если первое звено является удаляемым
        {
            found = true;
            p = head; // запомнаем указатель на удаляемое звено
            head = head->next;
            delete p;
            if (head == nullptr)
                tail = nullptr;
        }
        else
        {
            // ищем звено, предшествующее удаляемому
            p1 = head;
            while ((!found) && (p1->next != nullptr))
            {
                if (p1->next->info == valueToDelete)
                    found = true;
                else
                    p1 = p1->next;
            }
            if (found) // если найдено удаляемое звено
            {
                // запоминаем указатель на удаляемое звено
                p = p1->next;
                p1->next = p->next;
                if (p == tail)
                    tail = p1;
                delete p;
            }
        }
    }
    return found;
}
int main()
{
    LinearSingleList myList;
    for (int i = 0; i < 7; i++)
    {
        myList.addLast(i);
    }
    // ……………………………………………..
    return 0;
}