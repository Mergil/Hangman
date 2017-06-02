#include "../src/game.h"
#include "../thirdparty/ctest.h"

CTEST(suite, test1)
{
    char* str = "test";
    int term = igra(str);
    ASSERT_EQUAL(0, term);
}

CTEST(suite, test2)
{
    char* str = "test";
    int term = igra(str);
    ASSERT_EQUAL(-1, term);
}

CTEST(suite, test3)
{
    char* str = "test";
    int term = igra(str);
    ASSERT_EQUAL(-1, term);
}

CTEST(suite, test4)
{
    char* str = "test";
    int term = igra(str);
    ASSERT_EQUAL(-1, term);
}
