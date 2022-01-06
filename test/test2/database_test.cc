#include "backend/backend.h"
#include "gtest/gtest.h"
#include "parser/SystemVisitor.h"

namespace dbtrain_mysql {

TEST(DatabaseTest, SaveTest) {
  Clear();
  Init();
  Instance* instance = new Instance();
  Execute(instance, "CREATE DATABASE THU;");
  Execute(instance, "USE THU;");
  Execute(instance, "CREATE TABLE student(name VARCHAR(2000), id INT);");
  delete instance;
  instance = new Instance();
  Execute(instance, "USE THU;");
  Execute(instance, "DESC student;");
  Execute(instance, "DROP DATABASE THU;");
  delete instance;
  Clear();
}

}  // namespace dbtrain_mysql
