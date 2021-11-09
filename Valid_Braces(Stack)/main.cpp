#include <iostream>
#include "Stack.h"
#include <string>

bool open(char brace)
{
    return brace == '(' || brace == '[' || brace == '{';
}

bool close(char brace)
{
    return brace == ')' || brace == ']' || brace == '}';
}

bool check(char brace1, char brace2)
{
    if (brace1 == ')')
    {
        return brace1 != brace2 + 1; ; // ) == ( + 1
    }
    return brace1 != brace2 + 2; // } == { + 2 [ == [ + 2
}


bool valid_braces(const std::string& braces)
{
    
    Stack<char> stack;
    for (const auto& item : braces)
    {
        if (open(item)) stack.push(item);
        
        if (close(item))
        {
            if (stack.size() == 0) // закрывающая скобка у которой нету открывающей
            {
                return false;
            }
            char temp = stack.top();
            stack.pop();
            if (check(item, temp)) // проверка на то что являются ли скобки не одинаковами, если да, то возращаем false
            {
                return false;
            }

            
            
        }
        
        
    }


    if (stack.size() > 0) // если в стеке есть еще что-то, то значит у какой-то скобки нету своей пары
    {
        return false;
    }


    return true;
    
}






int main()
{
    std::cout << std::boolalpha;
    std::cout << valid_braces(" ( ( (salam){[salam]} ) { I'm a programmer () } [1,2,3,4,5,6,7,8,9] (YOOO!!!) )") << '\n';
    std::cout << valid_braces("({[]})") << '\n';
    std::cout << valid_braces("({ [} ] )") << '\n';
    std::cout << valid_braces("({ [] } ]") << '\n';


}