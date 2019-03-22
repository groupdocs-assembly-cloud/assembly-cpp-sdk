cmake -E chdir groupdocs-assembly-cloud-cpp\build ctest -V -C Debug
cd groupdocs-assembly-cloud-cpp/build/tests
copy test_result.xml "C:/TestData/test_result.xml"
cd C:/