/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TestBase.h">
*   Copyright (c) 2020 GroupDocs.Assembly for Cloud
* </copyright>
* <summary>
*   Permission is hereby granted, free of charge, to any person obtaining a copy
*  of this software and associated documentation files (the "Software"), to deal
*  in the Software without restriction, including without limitation the rights
*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*  copies of the Software, and to permit persons to whom the Software is
*  furnished to do so, subject to the following conditions:
* 
*  The above copyright notice and this permission notice shall be included in all
*  copies or substantial portions of the Software.
* 
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
*  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
*  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
*  SOFTWARE.
* </summary> 
-------------------------------------------------------------------------------------------------------------------- **/
#ifndef TEST_BASE
#define TEST_BASE

#include <boost/filesystem/path.hpp>

#include <gtest/gtest.h>
#include "AssemblyApi.h"
#include "FileApi.h"
#include "FolderApi.h"
#include "InfoApi.h"

#define STCONVERT(s) utility::conversions::to_string_t(s)

using streambuf_t = std::basic_streambuf<utility::char_t>;

using namespace groupdocs::assembly;
using namespace groupdocs::assembly::cloud::api;

///<summary>
///Get configuration for AssemblyApi
///</summary>
std::shared_ptr<ApiConfiguration> get_config();

class InfrastructureTest : public ::testing::Test
{
protected:
	///<summary>
	///Get root folder of sdk
	///</summary>
    static boost::filesystem::path get_sdk_root();

    boost::filesystem::path LocalTestDataFolder{get_sdk_root()/"TestData"};

	///<summary>
	///Set up test
	///</summary>
	void SetUp() override
    {
		m_Config = get_config();
	};
	///<summary>
	///Combine path
	///</summary>
	///<param name="base">Base path part</param>
	///<param name="stringToAdd">Path part to combine with base</param>
	///<returns>Combined path</returns>
	static utility::string_t path_combine(const boost::filesystem::path& base, const utility::string_t& stringToAdd);
	
	///<summary>
	///Generate content for HTTP request from file
	///</summary>
	///<param name="filePath">Path to file</param>
	///<param name="filename">Filename for Content-Disposition part</param>
	///<param name="contentType">Content type of Content-Disposition part</param>
	///<returns>HTTP content</returns>
	static std::shared_ptr<HttpContent> generate_http_content_from_file(const boost::filesystem::path& filePath,
        const utility::string_t& filename = {}, const utility::string_t& contentType = {});

public:
	///<summary>
	///Upload file to storage 
	///</summary>
	///<param name="path">Path to upload</param>
	///<param name="filePath">Path to file for uploading</param>
	void UploadFileToStorage(const utility::string_t& path, const boost::filesystem::path& filePath);
	///<summary>
	///Checks that path is exists
	///</summary>
	///<param name="path">Path to check</param>
	///<returns>File exists boolean flag</returns>
	bool GetIsExists(const utility::string_t& path);

public:
	std::shared_ptr<ApiConfiguration> get_configuration() const;
	std::shared_ptr<ApiClient> get_client();
	std::shared_ptr<AssemblyApi> get_api();

protected:
    const utility::string_t baseTestOutPath{_XPLATSTR("TestOut")};
    const utility::string_t remoteBaseTestDataFolder{_XPLATSTR("Temp/SdkTests/TestData")};
    const boost::filesystem::path commonFolder{"Common"};

private:
	std::shared_ptr<ApiClient> client;
	std::shared_ptr<AssemblyApi> api;
	std::shared_ptr<ApiConfiguration> m_Config;
};
#endif
