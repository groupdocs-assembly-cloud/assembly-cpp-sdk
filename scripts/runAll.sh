# Compile aw
mkdir -p groupdocs-assembly-cloud-cpp/build

# start test section
set -e

export CC=gcc 
export CXX=g++
cmake -Dcpprestsdk_ROOT=install/cpprestsdk -DCMAKE_BUILD_TYPE=Debug -S groupdocs-assembly-cloud-cpp -B groupdocs-assembly-cloud-cpp/build 
cmake --build groupdocs-assembly-cloud-cpp/build --config Debug --target all_unity -- VERBOSE=1

# Generate credentials
echo "{
        \"AppKey\" : \"$1\",
        \"AppSid\" : \"$2\",
        \"BaseUrl\" : \"$3\"
      }" > groupdocs-assembly-cloud-cpp/servercreds.json

# Run tests
cmake -E chdir groupdocs-assembly-cloud-cpp/build ctest -V -C Debug --gtest_output=xml:test_result.xml

# Run code check
cppcheck groupdocs-assembly-cloud-cpp  --quiet --xml -iboost/ -iinstall/ -ithirdparty/ -iCMakeFiles/ \
--platform=win32W --enable=all --force --std=c++11 --suppress=useInitializationList --suppress=unusedFunction \
-Igroupdocs-assembly-cloud-cpp/sources/ -Igroupdocs-assembly-cloud-cpp/sources/model -Igroupdocs-assembly-cloud-cpp/sources/model/requests --suppress=missingIncludeSystem --suppress=missingInclude \
--suppress=unmatchedSuppression --output-file=checkResult.xml

cp groupdocs-assembly-cloud-cpp/build/tests/test_result.xml /out
cp checkResult.xml /out

# end test section
set +e

chmod 777 -R out
