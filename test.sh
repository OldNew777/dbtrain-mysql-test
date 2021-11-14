#!/bin/bash

: ${CURRENT_TEST:=0}

echo -e current project "\x1b[32m${CI_PROJECT_NAME}\x1b[0m"
echo -e pipeline id "\x1b[32m${CI_PIPELINE_ID}\x1b[0m"
echo -e job id "\x1b[32m${CI_JOB_ID}\x1b[0m"
echo -e CI_COMMIT_TIMESTAMP "\x1b[32m${CI_COMMIT_TIMESTAMP}\x1b[0m"
echo -e CI_PIPELINE_CREATED_AT "\x1b[32m${CI_PIPELINE_CREATED_AT}\x1b[0m"

echo -e "\x1b[1;32mStart to compile\x1b[0m"
mkdir build && cd build
cmake .. -D Test=$CURRENT_TEST || { echo  -e "\x1b[1;31mFailed to cmake\x1b[0m" ; exit 1; }
make -j 16 -l ${MAX_LOAD_AVERAGE:-32} ||  { echo  -e "\x1b[1;31mFailed to make\x1b[0m" ; exit 1; }


if [ $CURRENT_TEST -eq 0 ]
then
    exit 0
fi

echo -e "\x1b[1;32mStart to test Test${CURRENT_TEST}\x1b[0m"
test/test${CURRENT_TEST}_test --gtest_output="json:report.json" --gtest_color="yes" || fail=1


if [ ${fail:-0} -eq 0 ]
then
    echo -e "\x1b[1;32mPassed test${CURRENT_TEST} test\x1b[0m"
else
    exit 1
fi
