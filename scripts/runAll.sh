git clone https://github.com/Microsoft/cpprestsdk.git

mkdir -p groupdocs-assembly-cloud-cpp/out
rm groupdocs-assembly-cloud-cpp/build -R -f

# Compile cppcheck
cd /usr/bin/cppcheck-sources
make SRCBUILD=build CFGDIR=/usr/bin/cppcheck-sources
make install CFGDIR=/usr/bin/cppcheck-sources
cp cppcheck /usr/bin/cppcheck./

# Compile cpprestsdk
cd /
mkdir build
mkdir install
cmake -DCPPREST_EXCLUDE_WEBSOCKETS=ON -DCPPREST_EXCLUDE_COMPRESSION=ON -DCPPREST_EXCLUDE_BROTLI=ON -DBUILD_TESTS=OFF -DBUILD_SAMPLES=OFF -DCMAKE_INSTALL_PREFIX=install/cpprestsdk -S cpprestsdk -B build
cmake --build build --config Debug --target install
cmake --build build --config Release --target install

# Compile aw
mkdir groupdocs-assembly-cloud-cpp/build
cmake -Dcpprestsdk_ROOT=install/cpprestsdk -DCMAKE_BUILD_TYPE=Debug -S groupdocs-assembly-cloud-cpp -B groupdocs-assembly-cloud-cpp/build 
cmake --build groupdocs-assembly-cloud-cpp/build --config Debug --target all_unity -- VERBOSE=1

# Run tests
cmake -E chdir groupdocs-assembly-cloud-cpp/build ctest -V -C Debug

# Run code check
cppcheck groupdocs-assembly-cloud-cpp  --quiet --xml -iboost/ -iinstall/ -ithirdparty/ -iCMakeFiles/ \
--platform=win32W --enable=all --force --std=c++11 --suppress=useInitializationList --suppress=unusedFunction \
-Igroupdocs-assembly-cloud-cpp/sources/ -Igroupdocs-assembly-cloud-cpp/sources/model -Igroupdocs-assembly-cloud-cpp/sources/model/requests --suppress=missingIncludeSystem --suppress=missingInclude \
--suppress=unmatchedSuppression --output-file=checkResult.xml

cp groupdocs-assembly-cloud-cpp/build/tests/test_result.xml groupdocs-assembly-cloud-cpp/out/test_result.xml
cp checkResult.xml groupdocs-assembly-cloud-cpp/out/checkResult.xml
