#pragma once
#include <stdexcept>
#include <cstddef>
#include "Vector.h"
#include <initializer_list>
template<typename T>class LinkedList;

template<typename LinkedList> class LinkedListIterator
{

public:
    using Type = typename LinkedList::Type;
    using NodePointer = typename LinkedList::Node*;
    template<typename T> friend class ::LinkedList;
    LinkedListIterator(NodePointer node) : node(node) {}



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


    const Type& operator*() const
    {
        return node->value;
    }

    /* NodePointer operator + (int count)
     {
         NodePointer temp = node;
         for (int i = 0; i < count && temp != nullptr; i++)
         {
             temp = temp->next;
         }
         if (temp == nullptr)
         {
             throw std::out_of_range("out of range");
         }
         return temp;
     }*/


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
    NodePointer operator->()
    {
        return node;
    }
    operator NodePointer()
    {
        return node;
    }
};


template<typename LinkedList> class LinkedListConstIterator
{

public:
    using Type = typename LinkedList::Type;
    using NodePointer = typename LinkedList::Node*;


    LinkedListConstIterator(NodePointer node) : node(node) {}



    LinkedListConstIterator& operator++()
    {
        node = node->next;
        return *this;
    }

    LinkedListConstIterator operator++(int)
    {
        LinkedListConstIterator list(*this);
        ++(*this);
        return list;
    }




    LinkedListConstIterator& operator--()
    {
        node = node->prev;
        return *this;
    }

    LinkedListConstIterator operator--(int)
    {
        LinkedListConstIterator list(*this);
        --(*this);
        return list;
    }




    const Type& operator*()
    {
        if (node == nullptr)
        {
            throw;
        }
        return node->value;
    }


    bool operator==(const LinkedListConstIterator& it)
    {
        return node == it.node;
    }

    bool operator!=(const LinkedListConstIterator& it)
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
    template<typename C> friend class LinkedListConstIterator;
public:
    using Type = T;
    using Iterator = LinkedListIterator<LinkedList>;
    using ConstIterator = LinkedListConstIterator<LinkedList>;
    LinkedList() : head(nullptr), tail(nullptr), m_length(0) {}



    LinkedList(std::initializer_list<T> list)
    {
        m_length = 0;
        head = nullptr;
        tail = nullptr;
        for (auto& item : list)
        {
            push_back(item);
        }
    }

    LinkedList(const Vector<T>& vec)
    {
        m_length = 0;
        head = nullptr;
        tail = nullptr;

        for (auto& item : vec)
        {
            push_back(item);
        }

    }

    LinkedList(const LinkedList& list)
    {
        m_length = 0;
        head = nullptr;
        tail = nullptr;
        for (auto& item : list)
        {
            push_back(item);
        }

    }

    LinkedList(LinkedList&& list)
    {
        m_length = list.m_length;
        head = list.head;
        tail = list.tail;
        list.head = nullptr;
        list.tail = nullptr;
        list.m_length = 0;
    }

    LinkedList& operator = (const LinkedList& list)
    {
        this->~LinkedList();
        //Node* temp = list.head;
        m_length = 0;
        head = nullptr;
        tail = nullptr;
        /*for (int i = 0; i < list.m_length; i++)
        {
            push_back(temp->value);
            temp = temp->next;
        }*/

        for (auto& item : list)
        {
            push_back(item);
        }

        return *this;
    }

    LinkedList& operator =(LinkedList&& list)
    {
        this->~LinkedList();
        m_length = list.m_length;
        head = list.head;
        tail = list.tail;
        list.head = nullptr;
        list.tail = nullptr;
        list.m_length = 0;
        return *this;
    }





    void push_back(const T& value)
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

    void push_back(T&& value)
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
        tail->next->value = std::move(value);
        tail->next->prev = tail;
        tail = tail->next;

        m_length++;



    }


    void push_front(const T& value)
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
        head->prev = new Node;
        head->prev->value = value;
        head->prev->next = head;
        head = head->prev;

        m_length++;
    }

    void push_front(T&& value)
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
        head->prev = new Node;
        head->prev->value = std::move(value);
        head->prev->next = head;
        head = head->prev;

        m_length++;
    }


    void pop_back()
    {
        if (m_length == 0)
        {
            return;
        }
        Node* temp = tail->prev;
        delete tail;
        tail = temp;
        tail->next = nullptr;
        m_length--;
    }

    void pop_front()
    {
        if (m_length == 0)
        {
            return;
        }
        Node* temp = head->next;
        delete head;
        head = temp;
        temp->prev = nullptr;
        m_length--;
    }


    LinkedList operator + (const LinkedList& list)
    {
        LinkedList copy(*this);

        for (auto& item : list)
        {
            copy.push_back(item);
        }
        return copy;
    }



    LinkedList& operator += (const LinkedList& list)
    {
        for (auto& item : list)
        {
            this->push_back(item);
        }
        return *this;
    }






    T& operator[](int index)
    {
        Iterator it = begin();

        for (int i = 0; i < index; i++)
        {
            it++;
        }
        return *it;
    }

    const T& operator[](int index) const
    {
        ConstIterator it = begin();

        for (int i = 0; i < index; i++)
        {
            it++;
        }
        return *it;
    }


    void reverse()
    {
        Node* current = head;
        while (current != nullptr)
        {
            /*Node* temp = current->prev;
            current->prev = current->next;
            current->next = temp;*/
            std::swap(current->prev, current->next);
            current = current->prev;
        }

        std::swap(head, tail);
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

    ConstIterator cbegin()
    {
        return head;
    }

    ConstIterator cend()
    {
        return nullptr;
    }

    ConstIterator begin() const
    {
        return head;
    }

    ConstIterator end() const
    {
        return nullptr;
    }

    Iterator insert(Iterator it, const T& value)
    {
        Node* old_next = it->next;
        it->next = new Node;
        it->next->value = value;
        it->next->prev = it;
        it->next->next = old_next;
        if (static_cast<Node*>(it) == tail)
        {
            tail = it->next;
        }
        return it->next;
    }

    Iterator insert(Iterator it, T&& value)
    {
        Node* old_next = it->next;
        it->next = new Node;
        it->next->value = value;
        it->next->prev = it;
        it->next->next = old_next;
        if (static_cast<Node*>(it) == tail)
        {
            tail = it->next;
        }
        m_length++;
        return it->next;
    }

    Iterator erase(Iterator it)
    {
       
        if (it->prev != nullptr)
        {
            it->prev->next = it->next;
        }
        if (it->next != nullptr)
        {
            it->next->prev = it->prev;
        }
        if (static_cast<Node*>(it) == head)
        {
            head = it->next;
        }
        if (static_cast<Node*>(it) == tail)
        {
            tail = it->prev;
        }
        Node* res = it->prev;
        delete it;
        m_length--;
        return res;

    }






    /*Iterator rbegin()
    {
        return tail;
    }

    Iterator rend()
    {
        return nullptr;
    }*/

    Type& front()
    {
        return head->value;
    }

    Type& back()
    {
        return tail->value;
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