#include "TassStringTest.hpp"
#include <cppunit/ui/text/TestRunner.h>

int main() {
  CppUnit::TextUi::TestRunner runner;
  runner.addTest(TassStringTest::suite());
  runner.run();
}
