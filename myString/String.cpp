#include "String.h"
#include <cstring>
#include <stdexcept>

std::ostream& operator<<(std::ostream& stream, String&& str)
{
    for (size_t i = 0; i < str.m_length; i++)
    {
        stream << str.string[i];
    }
    return stream;
}



std::ostream& operator<<(std::ostream& stream, String& str)
{
    for (size_t i = 0; i < str.m_length; i++)
    {
        stream << str.string[i];
    }
    return stream; 
}



String::String()
{
    m_capacity = 15;
    m_length = 0;
    string = static_cast<char*>(::operator new[](m_capacity));

}



String::String(const char* str)
{
    size_t str_length = std::strlen(str);
    m_capacity = str_length > 15 ? str_length : 15;
    m_length = str_length;
    string = static_cast<char*>(::operator new[](m_capacity));
    size_t i = 0;
    while(*str != '\0')
    {
        string[i++] = *str;
        str++;
    }
}

String::String(const char* str, size_t size)
{
    m_capacity = size > 15 ? size : 15;
    m_length = size;
    string = static_cast<char*>(::operator new[](m_capacity));
    for (size_t i = 0; i < size; i++)
    {
        string[i] = str[i];
    }
}

String::String(std::initializer_list<char> list)
{
    m_capacity = list.size() > 15 ? list.size() : 15;
    m_length = list.size();
    string = static_cast<char*>(::operator new[](m_capacity));
    size_t i = 0;
    for (auto& item : list)
    {
        string[i++] = item;
    }
}



String::String(size_t count, char r)
{
    m_capacity = count;
    m_length = count;
    string = static_cast<char*>(::operator new[](m_capacity));
    for (size_t i = 0; i < count; i++)
    {
        string[i] = r;
    }
}


String::String(size_t size)
{
    m_capacity = size > 15 ? size : 15;
    string = static_cast<char*>(::operator new[](m_capacity));
}


String::String(const String& cp_string)
{
    m_capacity = cp_string.m_capacity;
    m_length = cp_string.m_length;
    string = static_cast<char*>(::operator new[](m_capacity));
    for (size_t i = 0; i < m_length; i++)
    {
        string[i] = cp_string.string[i];
    }
}


String::String(String&& cp_string)
{
    m_capacity = cp_string.m_capacity;
    m_length = cp_string.m_length;
    // string = static_cast<char*>(::operator new[](m_capacity));

    // for (size_t i = 0; i < m_length; i++)
    // {
    //     string[i] = std::move(cp_string.string[i]);
    // }
    string = cp_string.string;

    cp_string.string = static_cast<char*>(::operator new[](0));
    cp_string.m_capacity = 0;
    cp_string.m_length = 0;
}


String& String::operator=(const String& cp_string)
{
    ::operator delete[](string);
    m_capacity = cp_string.m_capacity;
    m_length = cp_string.m_length;
    string = static_cast<char*>(::operator new[](m_capacity));
    for (size_t i = 0; i < m_length; i++)
    {
        string[i] = cp_string.string[i];
    }
    return *this;
}


String& String::operator=(String&& cp_string)
{
    ::operator delete[](string);
    m_capacity = cp_string.m_capacity;
    m_length = cp_string.m_length;
    string = static_cast<char*>(::operator new[](m_capacity));

    for (size_t i = 0; i < m_length; i++)
    {
        string[i] = std::move(cp_string.string[i]);
    }


    cp_string.m_capacity = 0;
    cp_string.m_length = 0;
    return *this;
}


void String::reserve(size_t size)
{
    size_t c_size = size;
    if (size < m_capacity)
    {
        c_size = m_length > 15 ? m_length : 15;
    }
    char* cp_string = static_cast<char*>(::operator new[](c_size));
    for (size_t i = 0; i < m_length; i++)
    {
        cp_string[i] = std::move(string[i]);
    }
    ::operator delete[](string);
    string = cp_string;
    m_capacity = c_size;
}












String String::substr(size_t pos)
{
    if (pos == m_length)
    {
        return "";
    }
    if (pos > m_length)
    {
        throw std::out_of_range("Your chosen position is greater than the size of the string");
    }
    String r_str(m_length - pos);
    /*size_t j = 0;
    for (size_t i = pos; i < m_length; i++)
    {
        my_str.string[j++] = this->string[i];
    }
    my_str.m_length = j;*/

    for (size_t i = pos; i < m_length; i++)
    {
        r_str.push_back(this->string[i]);
    }
    return r_str;
}


String String::substr(size_t pos, size_t end)
{
    if (pos == m_length)
    {
        return "";
    }
    if (pos > m_length)
    {
        throw std::out_of_range("Your chosen position is greater than the size of the string");
    }
    size_t length = pos + end;
    if (length > m_length)
    {
        length = m_length - pos;
    }
    /*String my_str(length);
    size_t j = 0;
    for (size_t i = pos; i < end && i < m_length; i++)
    {
        my_str.string[j++] = this->string[i];
    }
    my_str.m_length = j;
    return my_str;*/
    String r_str(length);
    for (size_t i = pos; i < end && i < m_length; i++)
    {
        r_str.push_back(this->string[i]);
    }
    return r_str;
}



int String::compare(const String& str2) const
{
    if (this->m_length > str2.m_length)
    {
        return 1;
    }
    if (this->m_length < str2.m_length)
    {
        return -1;
    }
    for (size_t i = 0; i < this->m_length; i++)
    {
        if (this->string[i] != str2.string[i])
        {
            return this->string[i] > str2.string[i] ? 1 : -1;
        }
    }
    return 0;     
}

bool String::operator>(const String& str2)const
{
    return compare(str2) == 1;
}

bool String::operator<(const String& str2)const
{
    return compare(str2) == -1;
}

bool String::operator==(const String& str2) const
{
    return compare(str2) == 0;
}


void String::reverse()
{
    for (size_t i = 0; i < m_length / 2; i++)
    {
        std::swap(this->string[i], this->string[m_length - i - 1]);
    }
}






void String::append(const char* str)
{
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        this->push_back(str[i]);
    }
}


void String::append(const String& str)
{
    for (size_t i = 0; i < str.m_length; i++)
    {
        this->push_back(str.string[i]);
    }
}

String String::operator + (const char* str)
{
    String r_str(*this);
    r_str.append(str);
    return r_str;
}

String String::operator + (const String& str)
{
    String r_str(*this);
    r_str.append(str);
    return r_str;
}

String& String::operator+=(const char* str)
{
    this->append(str);
    return *this;
}

String& String::operator+=(const String& str)
{
    this->append(str);
    return *this;
}

String String::operator*(size_t count)
{
    String r_str;
    for (size_t i = 0; i < count; i++)
    {
        r_str.append(*this);
    }
    return r_str;
}






char& String::operator[](size_t index)
{
    return string[index];
}


const char& String::operator[](size_t index) const
{
    return string[index];
}



void String::push_back(char chr)
{
    if (m_length == m_capacity)
    {
        reserve(m_capacity * 2);
    }
    string[m_length] = chr;
    m_length++;
}


void String::pop_back()
{
    if (m_length == 0)
    {
        return;
    }
    m_length--;
}

void String::erase(size_t index)
{
    if (m_length == 0)
    {
        return;
    }
    for (size_t i = index; i < m_length - 1; i++)
    {
        string[i] = string[i + 1];
    }
    m_length--;
}


void String::erase(size_t st_index, size_t end_index)
{
    if (m_length == 0)
    {
        return;
    }
    size_t new_index = 0;
    for (int i = 0; i < m_length; i++)
    {
        if (!(i >= st_index && i <= end_index))
        {
            string[new_index] = string[i];
            new_index++;
        }
    }
    m_length -= ((end_index - st_index) + 1);
}

char* String::data() const
{
    char* copy_str = string;
    copy_str[m_length] = '\0';
    return copy_str;
}


size_t String::find(char chr) const
{
    for (int i = 0; i < m_length; i++)
    {
        if (string[i] == chr)  
        {
            return i;
        }
    }
    return -1;
}


size_t String::find(const String& str) const
{
    const char* str1 = data();
    for (int i = 0; i < m_length; i++)
    {
        bool flag = false;
        for (int j = 0; j < str.size(); j++)
        {
            if (str1[j] == str.string[j])
            {
                flag = true;
            }
            else
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            return i;
        }
        str1++;
    }
    return -1;
}











size_t String::size() const
{
    return m_length;
}


size_t String::length() const 
{
    return m_length;
}

size_t String::capacity() const 
{
    return m_capacity;
}








String::~String()
{
    ::operator delete[](string);
}
