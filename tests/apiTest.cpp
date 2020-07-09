/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="apiTest.cpp">
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
#include "TestBase.h"

/// <summary>
/// Example of Assembly API usage
/// </summary>
class AssemblyApiTest : public InfrastructureTest {
protected:
};

///<summary>
///Builds a document using document template and XML or JSON data passed in request
///</summary>
TEST_F(AssemblyApiTest, TestAssembleDocument){
	utility::string_t fileName = _XPLATSTR("TestAllChartTypes.docx");
	utility::string_t remoteName = fileName;

	UploadFileToStorage(remoteBaseTestDataFolder + _XPLATSTR("GroupDocs.Assembly/") + fileName,
		path_combine(LocalTestDataFolder, fileName)
	);
	std::shared_ptr<AssembleOptions> assembleOptions = std::make_shared<AssembleOptions>();
	std::shared_ptr<TemplateFileInfo> fileInfo = std::make_shared<TemplateFileInfo>();
    fileInfo->setFilePath(fileName);
	assembleOptions->setSaveFormat(_XPLATSTR("docx"));
    assembleOptions->setTemplateFileInfo(fileInfo);
    assembleOptions->setReportData(get_file_text_as_string(path_combine(LocalTestDataFolder, _XPLATSTR("Teams.json"))));

	std::shared_ptr<AssembleDocumentRequest> request = 
		std::make_shared<AssembleDocumentRequest>(assembleOptions);
	HttpContent result = get_api()->assembleDocument(request).get();

	ASSERT_TRUE(result.getData()->peek());
}
