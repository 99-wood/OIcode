#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    while (1)
    {
        system("maker.exe > in.txt");
        system("test.exe < in.txt > test.txt");
        system("std.exe < in.txt > std.txt");
        if (system("fc std.txt test.txt"))
            break;
    }
    return 0;
}