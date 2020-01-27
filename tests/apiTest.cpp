/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="GroupDocs" file="apiTest.cpp">
*   Copyright (c) 2019 GroupDocs.Assembly for Cloud
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
#include "TestBase.h"
#include <boost/filesystem/string_file.hpp>

/// <summary>
/// Example of Assembly API usage
/// </summary>
class AssemblyApiTest : public InfrastructureTest {
protected:
};

///<summary>
///Builds a document using document template and XML or JSON data passed in request
///</summary>
TEST_F(AssemblyApiTest, TestPostAssembleDocument){
	utility::string_t fileName = _XPLATSTR("TestAllChartTypes.docx");
	utility::string_t remoteName = fileName;

	std::shared_ptr<HttpContent> fileData = std::make_shared<HttpContent>();
	fileData->setContentType(_XPLATSTR("application/json"));
	fileData->setName(_XPLATSTR("TestAllChartTypes"));
	fileData->setFileName(fileName);
	fileData->setData(std::make_shared<std::ifstream>(path_combine(LocalTestDataFolder, fileName), std::ifstream::binary));

	std::shared_ptr<UploadFileRequest> sp_request =
		std::make_shared<UploadFileRequest>(
			fileData, 
			remoteBaseTestDataFolder + _XPLATSTR("GroupDocs.Assembly/") + fileName,
			boost::none
	);

	
	auto sp_result = get_api()->uploadFile(sp_request).get();

	ASSERT_TRUE(sp_result.httpResponse->status_code() == 200);

	std::shared_ptr<ReportOptionsData> saveOptions = std::make_shared<ReportOptionsData>();
	saveOptions->setSaveFormat(_XPLATSTR("pdf"));

	std::string reportData;
	boost::filesystem::load_string_file(path_combine(LocalTestDataFolder, _XPLATSTR("Teams.json")), reportData);
	saveOptions->setReportData(utility::conversions::to_string_t(reportData));

	std::shared_ptr<PostAssembleDocumentRequest> request = 
		std::make_shared<PostAssembleDocumentRequest>(
			fileName, 
			saveOptions,
			boost::none,
			boost::none
			);
	HttpContent result = get_api()->postAssembleDocument(request).get();

	ASSERT_TRUE(result.getData()->peek());
}
