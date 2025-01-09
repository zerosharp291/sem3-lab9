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
    void addLast(int x);
    bool delNode(int valueToDelete);
    void printList() const;       // функция для вывода списка
    bool search(int value) const; // функция для поиска элемента
    int size() const;             // функция для получения размера списка
    bool addBefore(int newVal, int beforVal);
    bool addAfter(int newVal, int afterVal);
    bool addAtPosition(int newVal, int position);
    bool isEmpty() const;
    // ………………………………………………………………..
private:
    Node *head; // голова списка
    Node *tail; // хвост списка
    int count;
};

LinearSingleList::LinearSingleList()
{
    head = nullptr;
    tail = nullptr;
    count = 0;
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
    count++;
}

void LinearSingleList::addLast(int x)
{
    Node *tmp = new Node(x); // создаем новый узел
    if (head == nullptr)     // если список пуст
    {
        head = tmp; // новый узел становится головой
        tail = tmp; // новый узел становится хвостом
    }
    else // если список не пуст
    {
        tail->next = tmp; // добавляем новый узел в конец списка
        tail = tmp;       // обновляем хвост
    }
    count++; // увеличиваем счетчик
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
                count--;
            }
        }
    }
    return found;
}

void LinearSingleList::printList() const // функция для вывода списка
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->info << " ";
        current = current->next;
    }
    cout << endl;
}

bool LinearSingleList::search(int value) const // функция для поиска элемента
{
    Node *current = head;
    while (current != nullptr)
    {
        if (current->info == value)
            return true; // элемент найден
        current = current->next;
    }
    return false; // элемент не найден
}

int LinearSingleList::size() const { return count; }

// Добавление элемента перед элементом с заданным значением
// Добавление элемента перед элементом с заданным значением
bool LinearSingleList::addBefore(int newValue, int beforeValue)
{
    if (head == nullptr) // если список пуст
        return false;

    if (head->info == beforeValue)
    { // если искомый элемент первый
        addFirst(newValue);
        return true;
    }

    Node *current = head;
    while (current->next != nullptr)
    {
        if (current->next->info == beforeValue)
        {
            Node *newNode = new Node(newValue);
            newNode->next = current->next;
            current->next = newNode;
            count++;
            return true;
        }
        current = current->next;
    }
    return false; // элемент не найден
}

// Добавление элемента после элемента с заданным значением
bool LinearSingleList::addAfter(int newValue, int afterValue)
{
    Node *current = head;
    while (current != nullptr)
    {
        if (current->info == afterValue)
        {
            Node *newNode = new Node(newValue);
            newNode->next = current->next;
            current->next = newNode;
            if (current == tail)
            {
                tail = newNode;
            }
            count++;
            return true;
        }
        current = current->next;
    }
    return false; // элемент не найден
}

// Добавление элемента по номеру (позиции)
bool LinearSingleList::addAtPosition(int newValue, int position)
{
    if (position < 0 || position > count)
        return false;

    if (position == 0)
    {
        addFirst(newValue);
        return true;
    }

    if (position == count)
    {
        addLast(newValue);
        return true;
    }

    Node *current = head;
    for (int i = 0; i < position - 1; i++)
    {
        current = current->next;
    }

    Node *newNode = new Node(newValue);
    newNode->next = current->next;
    current->next = newNode;
    count++;
    return true;
}

bool LinearSingleList::isEmpty() const // метод для проверки пустоты списка
{
    return head == nullptr; // возвращает true, если список пуст
}
