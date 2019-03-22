git.exe clone "https://github.com/groupdocs-assembly-cloud/groupdocs-assembly-cloud-cpp.git"
cd groupdocs-assembly-cloud-cpp & mkdir build & cd ../
cmake -G "Visual Studio 15 2017" -Thost=x64 -Ax64 -Dcpprestsdk_ROOT=install/cpprestsdk -S groupdocs-assembly-cloud-cpp/ -B groupdocs-assembly-cloud-cpp/build
cmake --build groupdocs-assembly-cloud-cpp/build --config Debug --target assembly-cloud-test
xcopy "C:\testdata" "C:\groupdocs-assembly-cloud-cpp\build\tests\testdata\" /Y /Q /S
copy "C:\testdata\servercreds.json" "C:\groupdocs-assembly-cloud-cpp\build\tests\servercreds.json" /Y