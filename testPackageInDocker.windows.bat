mkdir out

docker build -f Dockerfile.tests.windows -t groupdocs-assembly-cloud-cpp-tests:windows .
docker run --rm -m 2g -v "%cd%/scripts:C:/scripts" -v "%cd%/out:C:/out" groupdocs-assembly-cloud-cpp-tests:windows cmd /c ".\scripts\testPackage.bat %1 %2 %3
exit /b %ERRORLEVEL%