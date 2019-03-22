# groupdocs-assembly-cloud-cpp
This repository contains GroupDocs.Assembly Cloud SDK for C++ source code. This SDK allows you to work with GroupDocs.Assembly Cloud REST APIs in your C++ applications quickly and easily, with zero initial cost.

See [API Reference](https://apireference.groupdocs.cloud/) for full API specification.

## How to use the SDK?
The complete source code is available in this repository folder. You can either directly use it in your project via source code or get [nuget distribution](https://www.nuget.org/packages/GroupDocs.Assembly-Cloud/) (recommended)

### Prerequisites

To use GroupDocs.Assembly for Cloud C++ SDK you need to register an account with [GroupDocs Cloud](https://www.groupdocs.cloud/) and lookup/create App Key and SID at [Cloud Dashboard](https://dashboard.groupdocs.cloud/#/apps). There is free quota available. For more details, see [GroupDocs Cloud Pricing](https://purchase.groupdocs.cloud/pricing).

### Installation


### Sample usage

The examples below show how your application have to assemble document using GroupDocs.Assembly-Cloud library:
``` C++
std::shared_ptr<Configuration> config = std::make_shared<Configuration>();
config->setAppKey(_XPLATSTR("APPKEY"));
config->setBaseUrl(_XPLATSTR("BASEURL"));
config->setAppSid(_XPLATSTR("APPSID"));

std::shared_ptr<ApiClient> client = std::make_shared<ApiClient>();
client->setConfiguration(config);

std::shared_ptr<AssemblyApi> assemblyApi = std::make_shared<AssemblyApi>(client)

std::shared_ptr<LoadSaveOptionsData> saveOptions = std::make_shared<LoadSaveOptionsData>();
saveOptions->setSaveFormat(_XPLATSTR("docx"));

std::shared_ptr<PostAssembleDocumentRequest> request = 
    std::make_shared<PostAssembleDocumentRequest>(
        fileName, 
        "TestData/Data.json",
        saveOptions, 
        boost::none,
        boost::none
        );
HttpContent result = assemblyApi->postAssembleDocument(request).get();

```


## How to build on Windows

1. Build [Microsoft/cpprestsd](https://github.com/Microsoft/cpprestsdk)
```cmd
git clone https://github.com/Microsoft/cpprestsdk
mkdir build
mkdir install
cmake -G "Visual Studio 15 2017" -Thost=x64 -Ax64 -DCPPREST_EXCLUDE_WEBSOCKETS=ON -DCPPREST_EXCLUDE_COMPRESSION=ON -DCPPREST_EXCLUDE_BROTLI=ON -DBUILD_TESTS=OFF -DBUILD_SAMPLES=OFF -DCMAKE_INSTALL_PREFIX=install\cpprestsdk -S cpprestsdk -B build
cmake --build build --config Debug --target install
cmake --build build --config Release --target install
```

2. Build groupdocs-assembly-cloud-cpp
```cmd
git clone https://github.com/groupdocs-assembly-cloud/groupdocs-assembly-cloud-cpp
mkdir groupdocs-assembly-cloud-cpp\build
cmake -G "Visual Studio 15 2017" -Thost=x64 -Ax64 -DBOOST_ROOT=<path-to-boost> -Dcpprestsdk_ROOT=install\cpprestsdk -S groupdocs-assembly-cloud-cpp -B groupdocs-assembly-cloud-cpp\build
cmake --build groupdocs-assembly-cloud-cpp\build --config Debug --target all_unity
```

3. Create servercreds.json in the root SDK directory:
````
{
	"AppKey" : "xxxxx",
	"AppSid" : "xxxx",
	"BaseUrl" : "xxx" 
}
````

4. Run tests
```cmd
cmake -E chdir groupdocs-assembly-cloud-cpp\build ctest -V -C Debug
```

## How to run tests in Windows Docker container

1. Create a base container
```cmd
docker build -f Dockerfile.windows -t groupdocs-assembly-cloud-cpp:windows .
```

2. Run tests
```cmd
runInDocker.windows
```

Reports are saved in out directory.

## How to run tests in Linux Docker container

1. Create a base container
```cmd
docker build -f Dockerfile.linux -t groupdocs-assembly-cloud-cpp:linux .
```

2. Set CPPWC_AK, CPPWC_AS, CPPWC_BU environment variables to aplication key, application SID, and base URL respectively.

3. Run tests
```cmd
runinDocker.linux
```

Reports are saved in out directory.