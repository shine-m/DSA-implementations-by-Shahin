#include <cassert>

int main()
{
    int x = 5;
    assert(x > 0); // OK, does nothing
    assert(x < 0); // Fails, prints error and aborts
}
