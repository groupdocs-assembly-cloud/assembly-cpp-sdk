
REM Generate credentials
echo { "AppKey" : "%1", > groupdocs-assembly-cloud-cpp\servercreds.json
echo  "AppSid" : "%2", >> groupdocs-assembly-cloud-cpp\servercreds.json
echo  "BaseUrl" : "%3" >> groupdocs-assembly-cloud-cpp\servercreds.json
echo } >> groupdocs-assembly-cloud-cpp\servercreds.json

REM remove build directory
rmdir groupdocs-assembly-cloud-cpp\build /s /q

REM Compile aw
mkdir groupdocs-assembly-cloud-cpp\build
cmake -G "Visual Studio 15 2017" -Thost=x64 -Ax64 -Dcpprestsdk_ROOT=install/cpprestsdk -S groupdocs-assembly-cloud-cpp -B groupdocs-assembly-cloud-cpp/build || goto end
cmake --build groupdocs-assembly-cloud-cpp/build --config Debug --target all_unity || goto end

REM Run tests
cmake -E chdir groupdocs-assembly-cloud-cpp/build ctest -V -C Debug --gtest_output=xml:test_result.xml || goto end

REM Run code check
cppcheck groupdocs-assembly-cloud-cpp  --quiet --xml -iboost/ -iinstall/ -ithirdparty/ -iCMakeFiles/ --platform=win32W --enable=all --force --std=c++11 --suppress=useInitializationList --suppress=unusedFunction -Igroupdocs-assembly-cloud-cpp/sources/ -Igroupdocs-assembly-cloud-cpp/sources/model -Igroupdocs-assembly-cloud-cpp/sources/model/requests --suppress=missingIncludeSystem --suppress=missingInclude --suppress=unmatchedSuppression --output-file=checkResult.xml  || goto end

:end
if exist .\groupdocs-assembly-cloud-cpp\build\tests\test_result.xml copy .\groupdocs-assembly-cloud-cpp\build\tests\test_result.xml c:\out
if exist checkResult.xml copy checkResult.xml c:\out
exit /b %ERRORLEVEL%