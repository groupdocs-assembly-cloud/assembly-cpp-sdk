/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="GroupDocs" file="AssemblyApi.cpp">
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

#include "AssemblyApi.h"
#include "IHttpBody.h"
#include "JsonBody.h"
#include "MultipartFormData.h"

#include <unordered_set>

#include <boost/algorithm/string/replace.hpp>
#include <utility>

namespace groupdocs 
{
namespace assembly 
{
namespace cloud 
{
namespace api 
{

///<summary>
///Method to cast json to descendant class
///</summary>
///<param name="json">JSON representation of answer</param>
///<param name="response">Response instance to configure</param>
///<returns>void</returns>
void postInitializeResponse(web::json::value json, void* response)
{

}

///<summary>
///Method to replace parameter in URL path
///</summary>
///<param name="path">Templated path</param>
///<param name="paramName">Name of parameter to replace</param>
///<param name="value">Parameter value to set</param>
///<returns>utility::string_t</returns>
utility::string_t replacePathParameter(utility::string_t path, const utility::string_t& paramName, const utility::string_t& value)
{
    if (!value.empty())
    {
        boost::replace_all(path, _XPLATSTR("{") + paramName + _XPLATSTR("}"),
            ApiClient::parameterToString(value));
    }
    else
    {
        boost::replace_all(path, _XPLATSTR("/{") + paramName + _XPLATSTR("}"),
            value);
    }
    return path;
}

///<summary>
///Method extract optional value
///</summary>
///<param name="parameter">Parameter to extract</param>
///<returns>utility::string_t</returns>
template <class T> 
utility::string_t extractOptional(const boost::optional<T>& parameter)
{
	if (parameter.has_value())
		return ApiClient::parameterToString(parameter.value());

    return {};
}
using namespace groupdocs::assembly::cloud::api::models;

AssemblyApi::AssemblyApi(std::shared_ptr<ApiClient> apiClient)
    : m_ApiClient(std::move(apiClient))
{
}

pplx::task<std::shared_ptr<web::http::http_response>> AssemblyApi::fileCopyFile(std::shared_ptr<FileCopyFileRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/assembly/storage/file/copy/{srcPath}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("srcPath"),
        ApiClient::parameterToString(request->getSrcPath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("AssemblyApi->fileCopyFile does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));

    {
        queryParams[_XPLATSTR("DestPath")] = ApiClient::parameterToString((request->getDestPath()));
    }
    if (request->getSrcStorageName())
    {
        queryParams[_XPLATSTR("SrcStorageName")] = ApiClient::parameterToString(*(request->getSrcStorageName()));
    }
    if (request->getDestStorageName())
    {
        queryParams[_XPLATSTR("DestStorageName")] = ApiClient::parameterToString(*(request->getDestStorageName()));
    }
    if (request->getVersionId())
    {
        queryParams[_XPLATSTR("VersionId")] = ApiClient::parameterToString(*(request->getVersionId()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("AssemblyApi->fileCopyFile does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			throw ApiException(response.status_code()
                , _XPLATSTR("error calling postAssembleDocument: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> AssemblyApi::fileDeleteFile(std::shared_ptr<FileDeleteFileRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/assembly/storage/file/{path}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("path"),
        ApiClient::parameterToString(request->getPath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("AssemblyApi->fileDeleteFile does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));

    if (request->getStorageName())
    {
        queryParams[_XPLATSTR("StorageName")] = ApiClient::parameterToString(*(request->getStorageName()));
    }
    if (request->getVersionId())
    {
        queryParams[_XPLATSTR("VersionId")] = ApiClient::parameterToString(*(request->getVersionId()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("AssemblyApi->fileDeleteFile does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			throw ApiException(response.status_code()
                , _XPLATSTR("error calling postAssembleDocument: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<HttpContent> AssemblyApi::fileDownloadFile(std::shared_ptr<FileDownloadFileRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/assembly/storage/file/{path}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("path"),
        ApiClient::parameterToString(request->getPath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));

    if (request->getStorageName())
    {
        queryParams[_XPLATSTR("StorageName")] = ApiClient::parameterToString(*(request->getStorageName()));
    }
    if (request->getVersionId())
    {
        queryParams[_XPLATSTR("VersionId")] = ApiClient::parameterToString(*(request->getVersionId()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("AssemblyApi->fileDownloadFile does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			throw ApiException(response.status_code()
                , _XPLATSTR("error calling postAssembleDocument: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
		}

        return response.extract_vector();
    })
    .then([=](std::vector<unsigned char> response)
    {
        HttpContent result;
        std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
        result.setData(stream);
        return result;
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> AssemblyApi::fileMoveFile(std::shared_ptr<FileMoveFileRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/assembly/storage/file/move/{srcPath}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("srcPath"),
        ApiClient::parameterToString(request->getSrcPath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("AssemblyApi->fileMoveFile does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));

    {
        queryParams[_XPLATSTR("DestPath")] = ApiClient::parameterToString((request->getDestPath()));
    }
    if (request->getSrcStorageName())
    {
        queryParams[_XPLATSTR("SrcStorageName")] = ApiClient::parameterToString(*(request->getSrcStorageName()));
    }
    if (request->getDestStorageName())
    {
        queryParams[_XPLATSTR("DestStorageName")] = ApiClient::parameterToString(*(request->getDestStorageName()));
    }
    if (request->getVersionId())
    {
        queryParams[_XPLATSTR("VersionId")] = ApiClient::parameterToString(*(request->getVersionId()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("AssemblyApi->fileMoveFile does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			throw ApiException(response.status_code()
                , _XPLATSTR("error calling postAssembleDocument: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<GroupDocsResponse<FilesUploadResult>> AssemblyApi::fileUploadFile(std::shared_ptr<FileUploadFileRequest> request)
{

    // verify the required parameter 'fileData' is set
    if (request->getFileData() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'fileData' when calling AssemblyApi->fileUploadFile"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/assembly/storage/file/{path}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("path"),
        ApiClient::parameterToString(request->getPath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("AssemblyApi->fileUploadFile does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("multipart/form-data"));

    if (request->getFileData() != nullptr)
    {
        fileParams.push_back(make_pair(_XPLATSTR("FileData"), (request->getFileData())));
    }
    if (request->getStorageName())
    {
        queryParams[_XPLATSTR("StorageName")] = ApiClient::parameterToString(*(request->getStorageName()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("AssemblyApi->fileUploadFile does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			throw ApiException(response.status_code()
                , _XPLATSTR("error calling postAssembleDocument: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		GroupDocsResponse<FilesUploadResult> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FilesUploadResult>(new FilesUploadResult())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling fileUploadFile: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> AssemblyApi::folderCopyFolder(std::shared_ptr<FolderCopyFolderRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/assembly/storage/folder/copy/{srcPath}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("srcPath"),
        ApiClient::parameterToString(request->getSrcPath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("AssemblyApi->folderCopyFolder does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));

    {
        queryParams[_XPLATSTR("DestPath")] = ApiClient::parameterToString((request->getDestPath()));
    }
    if (request->getSrcStorageName())
    {
        queryParams[_XPLATSTR("SrcStorageName")] = ApiClient::parameterToString(*(request->getSrcStorageName()));
    }
    if (request->getDestStorageName())
    {
        queryParams[_XPLATSTR("DestStorageName")] = ApiClient::parameterToString(*(request->getDestStorageName()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("AssemblyApi->folderCopyFolder does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			throw ApiException(response.status_code()
                , _XPLATSTR("error calling postAssembleDocument: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> AssemblyApi::folderCreateFolder(std::shared_ptr<FolderCreateFolderRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/assembly/storage/folder/{path}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("path"),
        ApiClient::parameterToString(request->getPath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("AssemblyApi->folderCreateFolder does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));

    if (request->getStorageName())
    {
        queryParams[_XPLATSTR("StorageName")] = ApiClient::parameterToString(*(request->getStorageName()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("AssemblyApi->folderCreateFolder does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			throw ApiException(response.status_code()
                , _XPLATSTR("error calling postAssembleDocument: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> AssemblyApi::folderDeleteFolder(std::shared_ptr<FolderDeleteFolderRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/assembly/storage/folder/{path}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("path"),
        ApiClient::parameterToString(request->getPath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("AssemblyApi->folderDeleteFolder does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));

    if (request->getStorageName())
    {
        queryParams[_XPLATSTR("StorageName")] = ApiClient::parameterToString(*(request->getStorageName()));
    }
    if (request->getRecursive())
    {
        queryParams[_XPLATSTR("Recursive")] = ApiClient::parameterToString(*(request->getRecursive()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("AssemblyApi->folderDeleteFolder does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, _XPLATSTR("DELETE"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			throw ApiException(response.status_code()
                , _XPLATSTR("error calling postAssembleDocument: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<GroupDocsResponse<FilesList>> AssemblyApi::folderGetFilesList(std::shared_ptr<FolderGetFilesListRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/assembly/storage/folder/{path}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("path"),
        ApiClient::parameterToString(request->getPath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("AssemblyApi->folderGetFilesList does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));

    if (request->getStorageName())
    {
        queryParams[_XPLATSTR("StorageName")] = ApiClient::parameterToString(*(request->getStorageName()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("AssemblyApi->folderGetFilesList does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			throw ApiException(response.status_code()
                , _XPLATSTR("error calling postAssembleDocument: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		GroupDocsResponse<FilesList> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FilesList>(new FilesList())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling folderGetFilesList: unsupported response type"));
        }

        return result;
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> AssemblyApi::folderMoveFolder(std::shared_ptr<FolderMoveFolderRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/assembly/storage/folder/move/{srcPath}"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("srcPath"),
        ApiClient::parameterToString(request->getSrcPath()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("AssemblyApi->folderMoveFolder does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));

    {
        queryParams[_XPLATSTR("DestPath")] = ApiClient::parameterToString((request->getDestPath()));
    }
    if (request->getSrcStorageName())
    {
        queryParams[_XPLATSTR("SrcStorageName")] = ApiClient::parameterToString(*(request->getSrcStorageName()));
    }
    if (request->getDestStorageName())
    {
        queryParams[_XPLATSTR("DestStorageName")] = ApiClient::parameterToString(*(request->getDestStorageName()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("AssemblyApi->folderMoveFolder does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, _XPLATSTR("PUT"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			throw ApiException(response.status_code()
                , _XPLATSTR("error calling postAssembleDocument: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<GroupDocsResponse<FormatCollection>> AssemblyApi::getSupportedFileFormats(std::shared_ptr<GetSupportedFileFormatsRequest> request)
{

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/assembly/formats"),
    path = bPath;

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/json"));
    responseHttpContentTypes.insert(_XPLATSTR("application/xml"));

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(400, _XPLATSTR("AssemblyApi->getSupportedFileFormats does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("application/json"));
    consumeHttpContentTypes.insert(_XPLATSTR("application/xml"));


    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
    }
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("AssemblyApi->getSupportedFileFormats does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, _XPLATSTR("GET"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			throw ApiException(response.status_code()
                , _XPLATSTR("error calling postAssembleDocument: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		GroupDocsResponse<FormatCollection> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FormatCollection>(new FormatCollection())
		};

        if (responseHttpContentType == _XPLATSTR("application/json"))
        {
            web::json::value json = response.extract_json().get();
            result.body->fromJson(json);
            postInitializeResponse(json, result.body.get());
        }
        // else if (responseHttpContentType == _XPLATSTR("multipart/form-data"))
        // {
        // TODO multipart response parsing
        // }
        else
        {
            throw ApiException(500
                , _XPLATSTR("error calling getSupportedFileFormats: unsupported response type"));
        }

        return result;
    });
}
pplx::task<HttpContent> AssemblyApi::postAssembleDocument(std::shared_ptr<PostAssembleDocumentRequest> request)
{

    // verify the required parameter 'data' is set
    if (request->getData() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'data' when calling AssemblyApi->postAssembleDocument"));
    }

    // verify the required parameter 'saveOptions' is set
    if (request->getSaveOptions() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'saveOptions' when calling AssemblyApi->postAssembleDocument"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/assembly/{name}/build"),
    path = bPath;
    path = replacePathParameter(path, _XPLATSTR("name"),
        ApiClient::parameterToString(request->getName()));

    std::map<utility::string_t, utility::string_t> queryParams;
    std::map<utility::string_t, utility::string_t> headerParams(apiConfiguration->getDefaultHeaders());
    std::map<utility::string_t, utility::string_t> formParams;
    std::vector<std::pair<utility::string_t, std::shared_ptr<HttpContent>>> fileParams;

    std::unordered_set<utility::string_t> responseHttpContentTypes;
    responseHttpContentTypes.insert(_XPLATSTR("application/octet-stream"));

    utility::string_t responseHttpContentType;

    // use JSON if possible
    if (responseHttpContentTypes.empty())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // JSON
    else if (responseHttpContentTypes.find(_XPLATSTR("application/json")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("application/json");
    }
    // multipart formdata
    else if (responseHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != responseHttpContentTypes.end())
    {
        responseHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("multipart/form-data"));

    if (request->getData() != nullptr)
    {
        fileParams.push_back(make_pair(_XPLATSTR("Data"), (request->getData())));
    }
    if (request->getSaveOptions() != nullptr)
    {
        formParams[_XPLATSTR("SaveOptions")] = (request->getSaveOptions()->toJson().to_string());
    }
    if (request->getFolder())
    {
        queryParams[_XPLATSTR("Folder")] = ApiClient::parameterToString(*(request->getFolder()));
    }
    if (request->getDestFileName())
    {
        queryParams[_XPLATSTR("DestFileName")] = ApiClient::parameterToString(*(request->getDestFileName()));
    }

    std::shared_ptr<IHttpBody> httpBody;
    utility::string_t requestHttpContentType;

    // use JSON if possible
    if (consumeHttpContentTypes.empty() || consumeHttpContentTypes.find(_XPLATSTR("application/json")) != 
    consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("application/json");
        web::json::value json;

        json = ModelBase::toJson(request->getSaveOptions());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("AssemblyApi->postAssembleDocument does not consume any supported media type"));
    }


    return m_ApiClient->callApi(path, _XPLATSTR("POST"), queryParams, httpBody, headerParams, formParams, fileParams,
    requestHttpContentType)
    .then([=](web::http::http_response response)
    {
        // 1xx - informational : OK
        // 2xx - successful       : OK
        // 3xx - redirection   : OK
        // 4xx - client error  : not OK
        // 5xx - client error  : not OK
		if (response.status_code() >= 400)
		{
			throw ApiException(response.status_code()
                , _XPLATSTR("error calling postAssembleDocument: ") + response.reason_phrase()
                , std::make_shared<std::stringstream>(response.extract_utf8string(true).get()));
		}

        return response.extract_vector();
    })
    .then([=](std::vector<unsigned char> response)
    {
        HttpContent result;
        std::shared_ptr<std::stringstream> stream = std::make_shared<std::stringstream>(std::string(response.begin(), response.end()));
        result.setData(stream);
        return result;
    });
}

}
}
}
}


