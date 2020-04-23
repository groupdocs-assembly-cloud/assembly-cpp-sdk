/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="AssemblyApi.cpp">
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

AssemblyApi::AssemblyApi(std::shared_ptr<ApiConfiguration> configuration)
    : m_ApiClient(std::make_shared<ApiClient>(configuration))
{
}

pplx::task<HttpContent> AssemblyApi::assembleDocument(std::shared_ptr<AssembleDocumentRequest> request)
{

    // verify the required parameter 'assembleOptions' is set
    if (request->getAssembleOptions() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'assembleOptions' when calling AssemblyApi->assembleDocument"));
    }

    std::shared_ptr<ApiConfiguration> apiConfiguration(m_ApiClient->getConfiguration());
    utility::string_t bPath = _XPLATSTR("/") + apiConfiguration->getApiVersion() + _XPLATSTR("/assembly/assemble"),
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
        //It's going to be binary, so just use the first one.
        responseHttpContentType = *responseHttpContentTypes.begin();
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
        web::json::value json;

        json = ModelBase::toJson(request->getAssembleOptions());
        

        httpBody = std::shared_ptr<IHttpBody>(new JsonBody(json));
    }
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getAssembleOptions().get())
        {
            (request->getAssembleOptions())->toMultipart(multipart, _XPLATSTR("assembleOptions"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
    }
    else
    {
        throw ApiException(415, _XPLATSTR("AssemblyApi->assembleDocument does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

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
			web::json::value error_json = response.extract_json().get();
			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase());
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
pplx::task<std::shared_ptr<web::http::http_response>> AssemblyApi::copyFile(std::shared_ptr<CopyFileRequest> request)
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
        throw ApiException(400, _XPLATSTR("AssemblyApi->copyFile does not produce any supported media type"));
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
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("AssemblyApi->copyFile does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

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
			web::json::value error_json = response.extract_json().get();
			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase());
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> AssemblyApi::copyFolder(std::shared_ptr<CopyFolderRequest> request)
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
        throw ApiException(400, _XPLATSTR("AssemblyApi->copyFolder does not produce any supported media type"));
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
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("AssemblyApi->copyFolder does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

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
			web::json::value error_json = response.extract_json().get();
			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase());
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> AssemblyApi::createFolder(std::shared_ptr<CreateFolderRequest> request)
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
        throw ApiException(400, _XPLATSTR("AssemblyApi->createFolder does not produce any supported media type"));
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
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("AssemblyApi->createFolder does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

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
			web::json::value error_json = response.extract_json().get();
			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase());
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> AssemblyApi::deleteFile(std::shared_ptr<DeleteFileRequest> request)
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
        throw ApiException(400, _XPLATSTR("AssemblyApi->deleteFile does not produce any supported media type"));
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
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("AssemblyApi->deleteFile does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

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
			web::json::value error_json = response.extract_json().get();
			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase());
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> AssemblyApi::deleteFolder(std::shared_ptr<DeleteFolderRequest> request)
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
        throw ApiException(400, _XPLATSTR("AssemblyApi->deleteFolder does not produce any supported media type"));
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
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("AssemblyApi->deleteFolder does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

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
			web::json::value error_json = response.extract_json().get();
			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase());
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<HttpContent> AssemblyApi::downloadFile(std::shared_ptr<DownloadFileRequest> request)
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
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("AssemblyApi->downloadFile does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

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
			web::json::value error_json = response.extract_json().get();
			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase());
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
pplx::task<GroupDocsResponse<FilesList>> AssemblyApi::getFilesList(std::shared_ptr<GetFilesListRequest> request)
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
        throw ApiException(400, _XPLATSTR("AssemblyApi->getFilesList does not produce any supported media type"));
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
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("AssemblyApi->getFilesList does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

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
			web::json::value error_json = response.extract_json().get();
			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase());
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
                , _XPLATSTR("error calling getFilesList: unsupported response type"));
        }

        return result;
    });
}
pplx::task<GroupDocsResponse<FileFormatsResponse>> AssemblyApi::getSupportedFileFormats(std::shared_ptr<GetSupportedFileFormatsRequest> request)
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
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("AssemblyApi->getSupportedFileFormats does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

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
			web::json::value error_json = response.extract_json().get();
			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase());
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
		GroupDocsResponse<FileFormatsResponse> result = {
			std::make_shared<web::http::http_response>(response),
			std::shared_ptr<FileFormatsResponse>(new FileFormatsResponse())
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
pplx::task<std::shared_ptr<web::http::http_response>> AssemblyApi::moveFile(std::shared_ptr<MoveFileRequest> request)
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
        throw ApiException(400, _XPLATSTR("AssemblyApi->moveFile does not produce any supported media type"));
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
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("AssemblyApi->moveFile does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

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
			web::json::value error_json = response.extract_json().get();
			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase());
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<std::shared_ptr<web::http::http_response>> AssemblyApi::moveFolder(std::shared_ptr<MoveFolderRequest> request)
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
        throw ApiException(400, _XPLATSTR("AssemblyApi->moveFolder does not produce any supported media type"));
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
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("AssemblyApi->moveFolder does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

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
			web::json::value error_json = response.extract_json().get();
			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase());
		}

        return response;
    })
    .then([=](web::http::http_response response)
    {
        return std::make_shared<web::http::http_response>(response);
    });
}
pplx::task<GroupDocsResponse<FilesUploadResult>> AssemblyApi::uploadFile(std::shared_ptr<UploadFileRequest> request)
{

    // verify the required parameter 'file' is set
    if (request->getFile() == nullptr)
    {
        throw ApiException(400, _XPLATSTR("Missing required parameter 'file' when calling AssemblyApi->uploadFile"));
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
        throw ApiException(400, _XPLATSTR("AssemblyApi->uploadFile does not produce any supported media type"));
    }

    headerParams[_XPLATSTR("Accept")] = responseHttpContentType;

    std::unordered_set<utility::string_t> consumeHttpContentTypes;
    consumeHttpContentTypes.insert(_XPLATSTR("multipart/form-data"));

    if (request->getFile() != nullptr)
    {
        fileParams.push_back(make_pair(_XPLATSTR("File"), (request->getFile())));
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
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
    }
    else
    {
        throw ApiException(415, _XPLATSTR("AssemblyApi->uploadFile does not consume any supported media type"));
    }

    // authentication (JWT) required
    // oauth2 authentication is added automatically as part of the http_client_config

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
			web::json::value error_json = response.extract_json().get();
			throw ApiException(response.status_code()
				, _XPLATSTR("request error: ") + response.reason_phrase());
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
                , _XPLATSTR("error calling uploadFile: unsupported response type"));
        }

        return result;
    });
}

}
}
}
}
