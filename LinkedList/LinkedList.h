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

    Type& operator + (int count)
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
        return (*temp).value;
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
        m_length = list.m_length;
        head = list.head;
        tail = list.tail;
        list.head = nullptr;
        list.tail = nullptr;
        list.m_length = 0;
        return *this;
    }





    void push_back(T& value)
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


    void push_front(T& value)
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


    //LinkedList& operator + (const LinkedList& list)
    //{
    //    LinkedList copy(*this);
    //    
    //    return copy;
    //}

    


    /*T& operator[](int index)  Please use iterators
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
    }*/

    size_t length()
    {
        return m_length;
    }

    Iterator begin() const
    {
        return head;
    }

    Iterator end() const
    {
        return nullptr;
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