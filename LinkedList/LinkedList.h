#pragma once
#include <stdexcept>
#include <cstddef>
template<typename LinkedList> class LinkedListIterator
{

public:
    using Type = typename LinkedList::Type;
    using NodePointer = typename LinkedList::Node*;
    LinkedListIterator(NodePointer node) : node(node)
    {
    }


    LinkedListIterator& operator++()
    {
        node = node->next;
        return *this;
    }

    LinkedListIterator operator++(int)
    {
        LinkedListIterator list(*this);
        ++(*this);
        return list;
    }


    LinkedListIterator& operator--()
    {
        node = node->prev;
        return *this;
    }

    LinkedListIterator operator--(int)
    {
        LinkedListIterator list(*this);
        --(*this);
        return list;
    }


    Type& operator*()
    {
        return (*node).value;
    }

    bool operator==(const LinkedListIterator& it) const 
    {
        return node == it.node;
    }

    bool operator!=(const LinkedListIterator& it) const
    {
        return !(node == it.node);
    }
private:
    NodePointer node;
};



template<typename T>class LinkedList
{
    struct Node
    {
        T value;
        Node* next = nullptr;
        Node* prev = nullptr;
    };
    Node* head;
    Node* tail;
    size_t m_length;
    template<typename R> friend class LinkedListIterator;
public:
    using Type = T;
    using Iterator = LinkedListIterator<LinkedList<T>>;
    LinkedList() : head(nullptr), tail(nullptr), m_length(0) {}
    void push_back(T value)
    {
        if (m_length == 0)
        {
            head = new Node;
            tail = head;
            head->value = value;
            tail->value = value;
            m_length++;
            return;
        }
        tail->next = new Node;
        tail->next->value = value;
        tail->next->prev = tail;
        tail = tail->next;

        m_length++;



    }


    T& operator[](int index)
    {
        if (index >= m_length)
        {
            throw std::out_of_range("access out of range");
        }
        Node* temp = head;
        for (int i = 0; i < m_length; i++)
        {

            if (i == index)
            {
                return (*temp).value;
            }
            temp = temp->next;
        }
    }

    size_t length()
    {
        return m_length;
    }

    Iterator begin()
    {
        return head;
    }

    Iterator end()
    {
        return nullptr;
    }

    ~LinkedList()
    {
        Node* node = head;

        while (node != nullptr)
        {
            Node* temp = node->next;
            delete node;
            node = temp;
        }

    }
};