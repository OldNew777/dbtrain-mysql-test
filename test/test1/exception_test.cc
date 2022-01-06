#include "exception/exceptions.h"
#include "gtest/gtest.h"

namespace dbtrain_mysql {

TEST(ExceptionTest, InheritTest) {
  Exception* a = new NullptrException();
  EXPECT_EQ("NullptrException: Info unknown", String(a->what()));
  try {
    throw *a;
  } catch (Exception& e) {
    EXPECT_EQ("NullptrException: Info unknown", String(e.what()));
  }
  delete a;

  TableException* b = new TableExistException("student");
  try {
    throw *b;
  } catch (Exception& e) {
    EXPECT_EQ("TableExistException: Table 'student' already exists",
              String(e.what()));
  }
  delete b;
}

}  // namespace dbtrain_mysql
