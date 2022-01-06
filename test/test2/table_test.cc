#include "backend/backend.h"
#include "gtest/gtest.h"
#include "parser/SystemVisitor.h"

namespace dbtrain_mysql {

TEST(TableTest, RangeTest) {
  Instance* instance = new Instance();
  Execute(instance, "CREATE DATABASE THU;");
  Execute(instance, "USE THU;");
  Execute(instance, "CREATE TABLE student(name VARCHAR(1800), id INT);");

  for (int i = 0; i < 10; ++i)
    Execute(instance, "INSERT INTO student VALUES('Jack',20);");
  Execute(instance, "INSERT INTO student VALUES('Mike',NULL);");
  Execute(instance, "INSERT INTO student VALUES('Mike', NULL);");
  for (int i = 0; i < 10; ++i)
    Execute(instance, "INSERT INTO student VALUES(NULL,872);");

  Execute(instance, "SELECT * FROM student WHERE student.id > 30;");
  Execute(instance, "DROP DATABASE THU;");
  delete instance;
}

TEST(TableTest, IndexTest) {
  Instance* instance = new Instance();
  Execute(instance, "CREATE DATABASE THU;");
  Execute(instance, "USE THU;");
  Execute(instance, "CREATE TABLE student(name VARCHAR(1800), id INT);");

  for (int i = 0; i < 10; ++i)
    Execute(instance, "INSERT INTO student VALUES('Jack',20);");
  Execute(instance, "INSERT INTO student VALUES('Mike',NULL);");
  Execute(instance, "INSERT INTO student VALUES('Mike', NULL);");
  for (int i = 0; i < 10; ++i)
    Execute(instance, "INSERT INTO student VALUES(NULL,872);");

  Execute(instance, "ALTER TABLE student ADD INDEX(id);");
  Execute(instance, "SELECT * FROM student WHERE student.id > 30;");
  Execute(instance, "DROP DATABASE THU;");
  delete instance;
}

TEST(TableTest, CharFieldCompareTest) {
  Instance* instance = new Instance();
  Execute(instance, "CREATE DATABASE THU;");
  Execute(instance, "USE THU;");
  Execute(instance, "CREATE TABLE student(name VARCHAR(1800), id INT);");

  for (int i = 0; i < 10; ++i)
    Execute(instance, "INSERT INTO student VALUES('Jack',20);");
  Execute(instance, "INSERT INTO student VALUES('Mike',NULL);");
  Execute(instance, "INSERT INTO student VALUES('Mike', NULL);");
  for (int i = 0; i < 10; ++i)
    Execute(instance, "INSERT INTO student VALUES(NULL,872);");

  Execute(instance, "SELECT * FROM student WHERE student.name = 'Jack';");
  Execute(instance, "DROP DATABASE THU;");
  delete instance;
}

TEST(TableTest, WhereInTest) {
  Instance* instance = new Instance();
  Execute(instance, "CREATE DATABASE THU;");
  Execute(instance, "USE THU;");
  Execute(instance, "CREATE TABLE student(name VARCHAR(1800), id INT);");

  for (int i = 0; i < 10; ++i)
    Execute(instance, "INSERT INTO student VALUES('Jack',20);");
  Execute(instance, "INSERT INTO student VALUES('Mike',NULL);");
  Execute(instance, "INSERT INTO student VALUES('Mike', NULL);");
  for (int i = 0; i < 10; ++i)
    Execute(instance, "INSERT INTO student VALUES(NULL,872);");

  Execute(instance,
          "SELECT * FROM student WHERE student.name IN('Jack','Mike');");
  Execute(instance, "DROP DATABASE THU;");
  delete instance;
}

TEST(TableTest, UpdateTest) {
  Instance* instance = new Instance();
  Execute(instance, "CREATE DATABASE THU;");
  Execute(instance, "USE THU;");
  Execute(instance, "CREATE TABLE student(name VARCHAR(1800), id INT);");

  for (int i = 0; i < 10; ++i)
    Execute(instance, "INSERT INTO student VALUES('Jack',20);");
  Execute(instance, "INSERT INTO student VALUES('Mike',NULL);");
  Execute(instance, "INSERT INTO student VALUES('Mike', NULL);");
  for (int i = 0; i < 10; ++i)
    Execute(instance, "INSERT INTO student VALUES(NULL,872);");

  Execute(
      instance,
      "UPDATE student SET id = 777 WHERE student.name IN ('Jack', 'Mike');");
  Execute(instance, "DROP DATABASE THU;");
  delete instance;
}

}  // namespace dbtrain_mysql
