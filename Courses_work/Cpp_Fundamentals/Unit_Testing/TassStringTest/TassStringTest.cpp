#include "TassStringTest.hpp"

void TassStringTest::setUp() {
  str1 = new TassString("Hallo");
  str2 = new TassString("Hallo");
}

void TassStringTest::tearDown() {
  delete(str2);
  delete(str1);
}

void TassStringTest::testEquality() {
  CPPUNIT_ASSERT(*str1 == *str2);
}

void TassStringTest::testInequality() {
  CPPUNIT_ASSERT(*str1 != *str2);
}

CppUnit::Test* TassStringTest::suite()
{
  CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("TassStringTest");
  suiteOfTests->addTest( new CppUnit::TestCaller<TassStringTest>( 
        "testEquality", 
        &TassStringTest::testEquality ) );
  suiteOfTests->addTest( new CppUnit::TestCaller<TassStringTest>( 
        "testInequality", 
        &TassStringTest::testInequality ) );
  return suiteOfTests;
}
