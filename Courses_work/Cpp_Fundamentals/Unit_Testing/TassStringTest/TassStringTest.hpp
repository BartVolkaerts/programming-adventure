#ifndef TASSSTRINGTEST_H
#define TASSSTRINGTEST_H

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "TassString.hpp"

class TassStringTest : public CppUnit::TestFixture {
  private:
    TassString *str1, *str2;
  public:
    void testEquality();
    void testInequality();
    void setUp();
    void tearDown();

    static CppUnit::Test* suite();
};

#endif
