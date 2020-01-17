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
    // multipart formdata
    else if (consumeHttpContentTypes.find(_XPLATSTR("multipart/form-data")) != consumeHttpContentTypes.end())
    {
        requestHttpContentType = _XPLATSTR("multipart/form-data");
        std::shared_ptr<MultipartFormData> multipart = std::make_shared<MultipartFormData>();

        if (request->getSaveOptions().get())
        {
            (request->getSaveOptions())->toMultipart(multipart, _XPLATSTR("saveOptions"));
        }

        httpBody = multipart;
        requestHttpContentType += _XPLATSTR("; boundary=") + multipart->getBoundary();
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


