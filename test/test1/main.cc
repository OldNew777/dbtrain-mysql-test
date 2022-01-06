#include <stdio.h>

#include "backend/backend.h"
#include "gtest/gtest.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  auto res = RUN_ALL_TESTS();
  return res;
}

namespace dbtrain_mysql {

TEST(StartTest, InitDB) {
  printf("InitDB by hand\n");
  Clear();
  Init();
}

}  // namespace dbtrain_mysql