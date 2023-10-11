#include <iostream>

using namespace std;

int sqrt(int num)
{
    int result = 0;
    if (num <= 1)
    {
        return num;
    }
    int i = 2;
    while (i <= num / 2)
    {
        if (num == i * i)
        {
            return num / i;
        }
        else if(num > i * i) {
            result = i;
        }
        i++;
    }
    return result;
}


int main()
{

    int result = sqrt(21);
    cout << result << endl;
    return 0;
}