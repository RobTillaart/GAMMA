//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2020-12-24
// PURPOSE: unit tests for the GAMMA library
//          https://github.com/RobTillaart/
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// https://github.com/Arduino-CI/arduino_ci/blob/master/cpp/unittest/Assertion.h#L33-L42
// ----------------------------
// assertEqual(expected, actual)
// assertNotEqual(expected, actual)
// assertLess(expected, actual)
// assertMore(expected, actual)
// assertLessOrEqual(expected, actual)
// assertMoreOrEqual(expected, actual)
// assertTrue(actual)
// assertFalse(actual)
// assertNull(actual)
// assertNotNull(actual)

#include <ArduinoUnitTests.h>

#define assertEqualFloat(arg1, arg2, arg3)  assertOp("assertEqualFloat", "expected", fabs(arg1 - arg2), compareLessOrEqual, "<=", "actual", arg3)
#define assertEqualINF(arg)  assertOp("assertEqualINF", "expected", INFINITY, compareEqual, "==", "actual", arg)
#define assertEqualNAN(arg)  assertOp("assertEqualNAN", "expected", true, compareEqual, "==", "actual", isnan(arg))


#include "Arduino.h"
#include "gamma.h"



unittest_setup()
{
}

unittest_teardown()
{
}

/*
unittest(test_new_operator)
{
  assertEqualINF(exp(800));
  assertEqualINF(0.0/0.0);
  assertEqualINF(42);
  
  assertEqualNAN(INFINITY - INFINITY);
  assertEqualNAN(0.0/0.0);
  assertEqualNAN(42);
}
*/

unittest(test_constructor)
{
  GAMMA gt0;  // uses default 32 size
  assertEqual(32, gt0.size());
  assertEqual(0,  gt0.getGamma());
  assertEqual(1,  gt0.distinct());

  GAMMA gt1(256);
  assertEqual(256, gt1.size());
  assertEqual(0,   gt1.getGamma());
  assertEqual(1,   gt1.distinct());

  GAMMA gt2(128);
  assertEqual(128, gt2.size());
  assertEqual(0,  gt2.getGamma());
  assertEqual(1,  gt2.distinct());
  
  GAMMA gt3(64);
  assertEqual(64, gt3.size());
  assertEqual(0,  gt3.getGamma());
  assertEqual(1,  gt3.distinct());
  
  GAMMA gt4(32);    // default
  assertEqual(32, gt4.size());
  assertEqual(0,  gt4.getGamma());
  assertEqual(1,  gt4.distinct());
  
  GAMMA gt5(16);
  assertEqual(16, gt5.size());
  assertEqual(0,  gt5.getGamma());
  assertEqual(16, gt5.distinct());
  
  GAMMA gt6(8);
  assertEqual(8, gt6.size());
  assertEqual(0, gt6.getGamma());
  assertEqual(8, gt6.distinct());
}

unittest(test_get_set)
{
  GAMMA gt;  // uses default 32 size

  for (int i = 1; i < 20; i++)
  {
     gt.setGamma(i * 0.1);
     assertEqualFloat(i * 0.1, gt.getGamma(), 0.001);
  }
}

unittest_main()

// --------
