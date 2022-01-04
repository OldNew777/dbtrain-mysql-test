#include "backend/backend.h"
#include "gtest/gtest.h"
#include "parser/SystemVisitor.h"

namespace dbtrain_mysql {

TEST(TableTest, RangeTest) {
  Clear();
  Init();
  Instance* instance = new Instance();
  Execute(instance, "CREATE DATABASE THU;");
  Execute(instance, "USE THU;");
  Execute(instance, "CREATE TABLE student(name VARCHAR(2000), id INT);");

  for (int i = 0; i < 10; ++i)
    Execute(instance, "INSERT INTO student VALUES('Jack',20);");
  Execute(instance, "INSERT INTO student VALUES('Mike',NULL);");
  Execute(instance, "INSERT INTO student VALUES('Mike', NULL);");
  for (int i = 0; i < 10; ++i)
    Execute(instance, "INSERT INTO student VALUES(NULL,872);");

  Execute(instance, "SELECT * FROM student WHERE student.id > 30;");
  Execute(instance, "DROP DATABASE THU;");
  delete instance;
  Clear();
}

}  // namespace dbtrain_mysql
