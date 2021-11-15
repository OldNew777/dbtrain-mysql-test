#include "field/fields.h"
#include "gtest/gtest.h"

namespace dbtrain_mysql {

TEST(FieldTest, IntFieldTest) {
  // test IntField
  IntField a0(27);
  IntField a1 = a0;
  a1.Add();

  EXPECT_EQ(a0.GetIntData(), 27);
  EXPECT_EQ(a1.GetIntData(), 28);
  EXPECT_TRUE(a0 < a1);
}

TEST(FieldTest, FloatFieldTest) {
  // test FloatField
  FloatField a0(64.25);
  FloatField a1 = a0;
  a1.Add();

  EXPECT_EQ(a0.GetFloatData(), 64.25);
  EXPECT_EQ(a1.ToString(), "64.25");
  EXPECT_TRUE(a0 != a1);
}

TEST(FieldTest, CharFieldTest) {
  // test CharField
  char buffer[128] = "123z5\0";
  buffer[3] = 126;
  CharField a0;
  a0.SetData((const uint8_t*)buffer, 4);
  CharField a1 = a0;
  a1.Add();

  EXPECT_EQ(a0.GetString() + " ", a1.GetString());
  EXPECT_TRUE(a0 < a1);
}

}  // namespace dbtrain_mysql
