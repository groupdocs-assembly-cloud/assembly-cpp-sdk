REM clear test output dir
rmdir out /s /q
mkdir out

REM run test
docker build -f Dockerfile.tests.windows -t groupdocs-assembly-cloud-cpp-test:windows .
docker run --rm -m 2g -v "%cd%/scripts:C:/scripts" -v "%cd%/out:C:/out" -i -t groupdocs-assembly-cloud-cpp-test:windows cmd /c ".\scripts\runAll.bat