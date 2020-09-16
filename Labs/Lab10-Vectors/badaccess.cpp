#include "bigint.h"
#include <iostream>

using namespace std;
int main()
{
    BigInt one("000986");
    BigInt two("124356");
    one.add(two);
    //print out part of the vector, which is private
    cout << one.top_carry << endl;
    return 0;
}
       