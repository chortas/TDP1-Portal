Overview
--------

CxxTest is a unit testing framework for C++ that is similar in
spirit to JUnit, CppUnit, and xUnit. CxxTest is easy to use because
it does not require precompiling a CxxTest testing library, it
employs no advanced features of C++ (e.g. RTTI) and it supports a
very flexible form of test discovery.

CxxTest is available under the GNU Lesser General Public Licence (LGPL).

A user guide can be downloaded from http://cxxtest.com.


### A Simple Example

1. Add the test in MyTestSuite.h:

```
#include <cxxtest/TestSuite.h>

class MyTestSuite : public CxxTest::TestSuite
  {
  public:
    void testAddition( void ) {
        TS_ASSERT( 1 + 1 > 1 );
        TS_ASSERT_EQUALS( 1 + 1, 2 );
    }
  };
```

2. Generate the tests file: `cxxtestgen --error-printer -o tests.cpp MyTestSuite.h`


3. Rebuild proyect in Clion and run the executable "Test" generated in TDP1-Portal


4. In `StageManager::run()` leave only `stage.step()` to eliminate time
