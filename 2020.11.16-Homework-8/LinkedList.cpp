#include "LinkedList.h"

LinkedList::LinkedList(const LinkedList& list)
{
    tail = head = nullptr;
    count = 0;

    Node* temp = list.head;
    while (temp != nullptr)
    {
        addToTail(temp->data);
        temp = temp->next;
    }
}

LinkedList::~LinkedList()
{
    Node* temp = head;
    while (temp != nullptr)
    {
        Node* node = temp;
        temp = temp->next;
        delete node;
    }
}

bool LinkedList::indexValid(int index)
{
    return (index >= 0 && index < count);
}

int LinkedList::length()
{
    return count;
}

bool LinkedList::addToHead(int element)
{
    if (head == nullptr)
    {
        head = tail = new Node(element);
    }
    else
    {
        /*
        Node* newHead = new Node(element, head);
        head = newHead;
        */
        head = new Node(element, head);
    }
    ++count;
    return true;
}

bool LinkedList::addToTail(int element)
{
    if (tail == nullptr)
    {
        head = tail = new Node(element);
    }
    else
    {
        /*
        Node* newTail = new Node(element);
        (*tail).next = newTail;
        tail = (*tail).next;
        */
        tail->next = new Node(element);
        tail = tail->next;
    }
    ++count;
    return true;
}

bool LinkedList::add(int index, int element)
{
    if (index == 0)
    {
        return addToHead(element);
    }
    if (index == count)
    {
        return addToTail(element);
    }
    if (!indexValid(index))
    {
        return false;
    }

    Node* temp = head;
    for (int i = 0; i < index - 1; ++i)
    {
        temp = temp->next;
    }
    temp->next = new Node(element, temp->next);
    ++count;

    return true;
}

int LinkedList::get(int index)
{
    if (!indexValid(index))
    {
        return -1;
    }
    if (index == 0)
    {
        return head->data;
    }
    if (index == count - 1)
    {
        return tail->data;
    }

    Node* temp = head;
    for (int i = 0; i < index; ++i)
    {
        temp = temp->next;
    }
    return temp->data;

}

bool LinkedList::set(int index, int element)
{
    if (!indexValid(index))
    {
        return false;
    }
    if (index == 0)
    {
        head->data = element;
    }
    else if (index == count - 1)
    {
        tail->data = element;
    }
    else
    {
        Node* temp = head;
        for (int i = 0; i < index; ++i)
        {
            temp = temp->next;
        }
        temp->data = element;
    }
    return true;
}

int& LinkedList::operator[](int index)
{
    if (head == nullptr)
    {
        addToHead(0);
        return head->data;
    }
    if (index <= 0)
    {
        return head->data;
    }
    if (index >= count)
    {
        addToTail(0);
        return tail->data;
    }
    if (index == count - 1)
    {
        return tail->data;
    }
    Node* temp = head;
    for (int i = 0; i < index; ++i)
    {
        temp = temp->next;
    }
    return temp->data;
}

std::ostream& operator<<(std::ostream& stream, const LinkedList list)
{
    stream << "[" << list.count << "]{";
    if (list.head == nullptr)
    {
        stream << "EMPTY";
    }
    else
    {
        Node* temp = list.head;
        while (temp != nullptr)
        {
            stream << temp->data;
            if (temp->next != nullptr)
            {
                stream << ", ";
            }
            temp = temp->next;
        }
    }
    stream << "}";

    return stream;
}

int LinkedList::extractHead()
{
    if (head == nullptr)
    {
        return 0;
    }
    int result = head->data;
    Node* begin = head;
    head = head->next;
    count--;
    delete begin;
    return result;
}

int LinkedList::extractTail()
{
    if (head == nullptr)
    {
        return 0;
    }
    int result = tail->data;
    Node* end = tail;
    Node* temp = head;
    for (int i = 1; i < length() - 1; i++)
    {
        temp = temp->next;
    }
    tail = temp;
    tail->next = nullptr;
    count--;
    delete end;
    return result;
}

int LinkedList::extract(int index)
{
    if (!indexValid(index))
    {
        std::cout << "Wrong index" << std::endl;
        return -1;
    }
    if (index == 0)
    {
        return extractHead();
    }
    if (index == length() - 1)
    {
        return extractTail();
    }
    Node* temp = head;
    for (int i = 1; i < index; i++)
    {
        temp = temp->next;
    }
    Node* current = temp->next;
    temp->next = current->next;
    int result = current->data;
    count--;
    delete current;
    return result;
}

void LinkedList::operator-=(int index)
{
    extract(index);
}

LinkedList& LinkedList::operator=(LinkedList list)
{
    /*head = list.head;
    tail = list.tail;
    count = list.count;
    return *this;*/
    head = list.head;
    count = list.count;
    Node* temp = list.head->next;
    list.extractHead();
    while (temp != nullptr)
    {
        list.extractHead();
        addToTail(temp->data);
        temp = temp->next;
    }
    return *this;
}

/*int LinkedList::indexOf(int element)
{
    Node* temp = head;
    for (int i = 0; i < count; i++)
    {
        if (temp->data == element)
        {
            return i;
        }
        temp = temp->next;
    }
    return -1;
}*/

int LinkedList::indexOf(int element)
{
    Node* temp = head;
    int index = 0;
    while (temp != nullptr)
    {
        if (temp->data == element)
        {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

bool LinkedList::contains(int element)
{
    return indexOf(element) == -1 ? false : true;
}

bool LinkedList::swap(int index1, int index2)
{
    if (index1 > index2)
    {
        index1 = index1 ^ index2;
        index2 = index1 ^ index2;
        index1 = index1 ^ index2;
    }
    if (!indexValid(index1) || !indexValid(index2))
    {
        std::cout << "Wrong indexes" << std::endl;
        return false;
    }
    if (index1 == index2)
    {
        std::cout << "Nothing to swap" << std::endl;
        return false;
    }
    Node* current = head;
    if (index1 == 0)
    {
        Node* n2Previous = head;
        Node* n2 = head;
        Node* temp = head;
        for (int i = 1; i < count; i++)
        {
            if (i == index2)
            {
                n2Previous = temp;
                n2 = temp->next;
            }
            temp = temp->next;
        }
        temp = head->next;
        n2Previous->next = current;
        current->next = n2->next;
        n2->next = temp;
        head = n2;
        return true;
    }
    else
    {
        Node* n1Previous = head;
        Node* n1 = head;
        Node* n2Previous = head;
        Node* n2 = head;
        Node* temp = head;
        for (int i = 1; i < count; i++)
        {
            if (i == index1)
            {
                n1Previous = temp;
                n1 = temp->next;
            }
            if (i == index2)
            {
                n2Previous = temp;
                n2 = temp->next;
            }
            temp = temp->next;
        }
        current = n2->next;
        n1Previous->next = n2;
        n2Previous->next = n1;
        n2->next = n1->next;
        n1->next = current;        
        return true;
    }

}
