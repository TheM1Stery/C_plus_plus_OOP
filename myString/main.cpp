#include <iostream>
#include <string>
#include <vector>
int order_type(std::vector<int> order)
{
    if (order.size() == 1 || order.size() == 0)
    {
        return 0;
    }
    int check = order[0] - order[1];
    for (int i = 1; i < order.size(); i++)
    {
        if (check > 0 && order[i] - order[i - 1] > 0)
        {
            
        }
    }
    return 0;
}

int main()
{
   
}