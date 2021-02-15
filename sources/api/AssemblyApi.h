/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="AssemblyApi.h">
*   Copyright (c) 2021 GroupDocs.Assembly for Cloud
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

#ifndef GROUPDOCS_ASSEMBLY_CLOUD_API_AssemblyApi_H_
#define GROUPDOCS_ASSEMBLY_CLOUD_API_AssemblyApi_H_


#include "../ApiClient.h"

#include "requests/AssembleDocumentRequest.h"
#include "requests/CopyFileRequest.h"
#include "requests/CopyFolderRequest.h"
#include "requests/CreateFolderRequest.h"
#include "requests/DeleteFileRequest.h"
#include "requests/DeleteFolderRequest.h"
#include "requests/DownloadFileRequest.h"
#include "requests/GetFilesListRequest.h"
#include "requests/GetSupportedFileFormatsRequest.h"
#include "requests/MoveFileRequest.h"
#include "requests/MoveFolderRequest.h"
#include "requests/UploadFileRequest.h"

#include "AssembleOptions.h"
#include "FileFormatsResponse.h"
#include "FilesList.h"
#include "FilesUploadResult.h"
#include "HttpContent.h"
#include <cpprest/details/basic_types.h>
#include <boost/optional.hpp>
namespace groupdocs {
namespace assembly {
namespace cloud {
namespace api {

using namespace groupdocs::assembly::cloud::api::models;

template<class T>
struct GroupDocsResponse
{
	std::shared_ptr<web::http::http_response> httpResponse;
    std::shared_ptr<T> body;
};

class  AssemblyApi
{
public:
    ///<summary>
    ///Builds a document using document template and XML or JSON data passed in request.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="assembleOptions">Assemble Options. It should be JSON or XML with TemplateFileInfo, SaveFormat, ReportData and etc.             </param>
    	pplx::task<HttpContent> assembleDocument(
		std::shared_ptr<AssembleDocumentRequest> request
	);
    ///<summary>
    ///Copy file
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="destPath">Destination file path</param>
        /// <param name="srcPath">Source file&#39;s path e.g. &#39;/Folder 1/file.ext&#39; or &#39;/Bucket/Folder 1/file.ext&#39;</param>
        /// <param name="srcStorageName">Source storage name (optional)</param>
        /// <param name="destStorageName">Destination storage name (optional)</param>
        /// <param name="versionId">File version ID to copy (optional)</param>
    	pplx::task<std::shared_ptr<web::http::http_response>> copyFile(
		std::shared_ptr<CopyFileRequest> request
	);
    ///<summary>
    ///Copy folder
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="destPath">Destination folder path e.g. &#39;/dst&#39;</param>
        /// <param name="srcPath">Source folder path e.g. /Folder1</param>
        /// <param name="srcStorageName">Source storage name (optional)</param>
        /// <param name="destStorageName">Destination storage name (optional)</param>
    	pplx::task<std::shared_ptr<web::http::http_response>> copyFolder(
		std::shared_ptr<CopyFolderRequest> request
	);
    ///<summary>
    ///Create the folder
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="path">Target folder&#39;s path e.g. Folder1/Folder2/. The folders will be created recursively</param>
        /// <param name="storageName">Storage name (optional)</param>
    	pplx::task<std::shared_ptr<web::http::http_response>> createFolder(
		std::shared_ptr<CreateFolderRequest> request
	);
    ///<summary>
    ///Delete file
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="path">Path of the file including file name and extension e.g. /Folder1/file.ext</param>
        /// <param name="storageName">Storage name (optional)</param>
        /// <param name="versionId">File version ID to delete (optional)</param>
    	pplx::task<std::shared_ptr<web::http::http_response>> deleteFile(
		std::shared_ptr<DeleteFileRequest> request
	);
    ///<summary>
    ///Delete folder
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="path">Folder path e.g. /Folder1s</param>
        /// <param name="storageName">Storage name (optional)</param>
        /// <param name="recursive">Enable to delete folders, subfolders and files (optional, default to false)</param>
    	pplx::task<std::shared_ptr<web::http::http_response>> deleteFolder(
		std::shared_ptr<DeleteFolderRequest> request
	);
    ///<summary>
    ///Download file
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="path">Path of the file including the file name and extension e.g. /folder1/file.ext</param>
        /// <param name="storageName">Storage name (optional)</param>
        /// <param name="versionId">File version ID to download (optional)</param>
    	pplx::task<HttpContent> downloadFile(
		std::shared_ptr<DownloadFileRequest> request
	);
    ///<summary>
    ///Get all files and folders within a folder
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="path">Folder path e.g. /Folder1</param>
        /// <param name="storageName">Storage name (optional)</param>
    	pplx::task<GroupDocsResponse<FilesList>> getFilesList(
		std::shared_ptr<GetFilesListRequest> request
	);
    ///<summary>
    ///Retrieves list of supported file formats.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
	pplx::task<GroupDocsResponse<FileFormatsResponse>> getSupportedFileFormats(
		std::shared_ptr<GetSupportedFileFormatsRequest> request
	);
    ///<summary>
    ///Move file
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="destPath">Destination file path e.g. &#39;/dest.ext&#39;</param>
        /// <param name="srcPath">Source file&#39;s path e.g. &#39;/Folder 1/file.ext&#39; or &#39;/Bucket/Folder 1/file.ext&#39;</param>
        /// <param name="srcStorageName">Source storage name (optional)</param>
        /// <param name="destStorageName">Destination storage name (optional)</param>
        /// <param name="versionId">File version ID to move (optional)</param>
    	pplx::task<std::shared_ptr<web::http::http_response>> moveFile(
		std::shared_ptr<MoveFileRequest> request
	);
    ///<summary>
    ///Move folder
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="destPath">Destination folder path to move to e.g &#39;/dst&#39;</param>
        /// <param name="srcPath">Source folder path e.g. /Folder1</param>
        /// <param name="srcStorageName">Source storage name (optional)</param>
        /// <param name="destStorageName">Destination storage name (optional)</param>
    	pplx::task<std::shared_ptr<web::http::http_response>> moveFolder(
		std::shared_ptr<MoveFolderRequest> request
	);
    ///<summary>
    ///Upload file
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="fileContent">File to upload</param>
        /// <param name="path">Path where to upload including filename and extension e.g. /file.ext or /Folder 1/file.ext              If the content is multipart and path does not contains the file name it tries to get them from filename parameter              from Content-Disposition header.</param>
        /// <param name="storageName">Storage name (optional)</param>
    	pplx::task<GroupDocsResponse<FilesUploadResult>> uploadFile(
		std::shared_ptr<UploadFileRequest> request
	);

public:
    explicit AssemblyApi(std::shared_ptr<ApiConfiguration> configuration);
    virtual ~AssemblyApi() = default;
    
protected:
    std::shared_ptr<ApiClient> m_ApiClient;
};

}
}
}
}

#endif /* GROUPDOCS_ASSEMBLY_CLOUD_API_AssemblyApi_H_ */
