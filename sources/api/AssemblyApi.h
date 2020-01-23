/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="GroupDocs" file="AssemblyApi.h">
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

#ifndef GROUPDOCS_ASSEMBLY_CLOUD_API_AssemblyApi_H_
#define GROUPDOCS_ASSEMBLY_CLOUD_API_AssemblyApi_H_


#include "../ApiClient.h"

#include "requests/FileCopyFileRequest.h"
#include "requests/FileDeleteFileRequest.h"
#include "requests/FileDownloadFileRequest.h"
#include "requests/FileMoveFileRequest.h"
#include "requests/FileUploadFileRequest.h"
#include "requests/FolderCopyFolderRequest.h"
#include "requests/FolderCreateFolderRequest.h"
#include "requests/FolderDeleteFolderRequest.h"
#include "requests/FolderGetFilesListRequest.h"
#include "requests/FolderMoveFolderRequest.h"
#include "requests/GetSupportedFileFormatsRequest.h"
#include "requests/PostAssembleDocumentRequest.h"

#include "FilesList.h"
#include "FilesUploadResult.h"
#include "FormatCollection.h"
#include "HttpContent.h"
#include "LoadSaveOptionsData.h"
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
    	pplx::task<std::shared_ptr<web::http::http_response>> fileCopyFile(
		std::shared_ptr<FileCopyFileRequest> request
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
    	pplx::task<std::shared_ptr<web::http::http_response>> fileDeleteFile(
		std::shared_ptr<FileDeleteFileRequest> request
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
    	pplx::task<HttpContent> fileDownloadFile(
		std::shared_ptr<FileDownloadFileRequest> request
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
    	pplx::task<std::shared_ptr<web::http::http_response>> fileMoveFile(
		std::shared_ptr<FileMoveFileRequest> request
	);
    ///<summary>
    ///Upload file
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="fileData">File to upload</param>
        /// <param name="path">Path where to upload including filename and extension e.g. /file.ext or /Folder 1/file.ext              If the content is multipart and path does not contains the file name it tries to get them from filename parameter              from Content-Disposition header.</param>
        /// <param name="storageName">Storage name (optional)</param>
    	pplx::task<GroupDocsResponse<FilesUploadResult>> fileUploadFile(
		std::shared_ptr<FileUploadFileRequest> request
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
    	pplx::task<std::shared_ptr<web::http::http_response>> folderCopyFolder(
		std::shared_ptr<FolderCopyFolderRequest> request
	);
    ///<summary>
    ///Create the folder
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="path">Target folder&#39;s path e.g. Folder1/Folder2/. The folders will be created recursively</param>
        /// <param name="storageName">Storage name (optional)</param>
    	pplx::task<std::shared_ptr<web::http::http_response>> folderCreateFolder(
		std::shared_ptr<FolderCreateFolderRequest> request
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
    	pplx::task<std::shared_ptr<web::http::http_response>> folderDeleteFolder(
		std::shared_ptr<FolderDeleteFolderRequest> request
	);
    ///<summary>
    ///Get all files and folders within a folder
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="path">Folder path e.g. /Folder1</param>
        /// <param name="storageName">Storage name (optional)</param>
    	pplx::task<GroupDocsResponse<FilesList>> folderGetFilesList(
		std::shared_ptr<FolderGetFilesListRequest> request
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
    	pplx::task<std::shared_ptr<web::http::http_response>> folderMoveFolder(
		std::shared_ptr<FolderMoveFolderRequest> request
	);
    ///<summary>
    ///Retrieves list of supported file formats.
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
	pplx::task<GroupDocsResponse<FormatCollection>> getSupportedFileFormats(
		std::shared_ptr<GetSupportedFileFormatsRequest> request
	);
    ///<summary>
    ///Builds a document using document template and XML or JSON data passed in request
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">File name of template, which is located on a storage</param>
        /// <param name="data">Report data in JSON or XML format</param>
        /// <param name="saveOptions">Save options in json format</param>
        /// <param name="folder">Folder path where template file is located(on a storage) (optional)</param>
        /// <param name="destFileName">Result name of built document (optional)</param>
    	pplx::task<HttpContent> postAssembleDocument(
		std::shared_ptr<PostAssembleDocumentRequest> request
	);

public:
    explicit AssemblyApi(std::shared_ptr<ApiClient> apiClient );
    virtual ~AssemblyApi() = default;
    
protected:
    std::shared_ptr<ApiClient> m_ApiClient;
};

}
}
}
}

#endif /* GROUPDOCS_ASSEMBLY_CLOUD_API_AssemblyApi_H_ */


