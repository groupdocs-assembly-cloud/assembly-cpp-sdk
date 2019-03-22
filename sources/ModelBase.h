/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="GroupDocs" file="ModelBase.h">
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

#ifndef _ModelBase_H_
#define _ModelBase_H_


#include "HttpContent.h"
#include "MultipartFormData.h"

#include <cpprest/details/basic_types.h>
#include <cpprest/json.h>

#include <vector>

namespace groupdocs {
namespace assembly {
namespace model {

class FormFieldCheckbox;
class FormFieldDropDown;
class FormFieldTextInput;


class  ModelBase
{
public:
    virtual ~ModelBase() = default;

    virtual void validate() = 0;

    virtual web::json::value toJson() const = 0;
    virtual void fromJson(web::json::value& json) = 0;

    virtual void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const = 0;
    virtual void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) = 0;

    ///<summary>
    ///Static methods for convertion to json
    ///</summary>
    ///<param name="value">Value to convert</param>
    ///<returns>Converted value</returns>
    static web::json::value toJson( const utility::string_t& value );
    static web::json::value toJson( const utility::datetime& value );
    static web::json::value toJson( const std::shared_ptr<HttpContent>& value );
    static web::json::value toJson( const std::shared_ptr<ModelBase>& value );
    static web::json::value toJson( int32_t value );
    static web::json::value toJson( int64_t value );
    static web::json::value toJson( double value );
    static web::json::value toJson( bool value );
    template<class T>
    static web::json::value toJson(const std::vector<T>& value);

    ///<summary>
    ///Static methods for convertions from json
    ///</summary>
    ///<param name="value">Json value to convert</param>
    ///<returns>Deserialized from json value</returns>
    static int64_t int64_tFromJson(web::json::value& val);
    static int32_t int32_tFromJson(web::json::value& val);
    static float floatFromJson(web::json::value& val);
    static utility::string_t stringFromJson(web::json::value& val);
    static utility::datetime dateFromJson(web::json::value& val);
    static double doubleFromJson(web::json::value& val);
    static bool boolFromJson(web::json::value& val);
    static std::shared_ptr<HttpContent> fileFromJson(web::json::value& val);

    ///<summary>
    ///Static methods for generating HttpContent for request
    ///</summary>
    ///<param name="name">Parameter name</param>
    ///<param name="value">Parameter value</param>
    ///<param name="contentType">Content type</param>
    ///<returns>HttpContent object</returns>
    static std::shared_ptr<HttpContent> toHttpContent( const utility::string_t& name, const utility::string_t& value, const utility::string_t& contentType = _XPLATSTR(""));
    static std::shared_ptr<HttpContent> toHttpContent( const utility::string_t& name, const utility::datetime& value, const utility::string_t& contentType = _XPLATSTR(""));
    static std::shared_ptr<HttpContent> toHttpContent( const utility::string_t& name, std::shared_ptr<HttpContent> value );
    static std::shared_ptr<HttpContent> toHttpContent( const utility::string_t& name, const web::json::value& value, const utility::string_t& contentType = _XPLATSTR("application/json") );
    static std::shared_ptr<HttpContent> toHttpContent( const utility::string_t& name, int32_t value, const utility::string_t& contentType = _XPLATSTR("") );
    static std::shared_ptr<HttpContent> toHttpContent( const utility::string_t& name, int64_t value, const utility::string_t& contentType = _XPLATSTR("") );
    static std::shared_ptr<HttpContent> toHttpContent( const utility::string_t& name, double value, const utility::string_t& contentType = _XPLATSTR("") );
    template <class T>
    static std::shared_ptr<HttpContent> toHttpContent( const utility::string_t& name, const std::vector<T>& value, const utility::string_t& contentType = _XPLATSTR("") );

    ///<summary>
    ///Static methods to extract value from HttpContent
    ///</summary>
    ///<param name="val">HttpContent object</param>
    ///<returns>Extracted value</returns>
    static int64_t int64_tFromHttpContent(const std::shared_ptr<HttpContent>& val);
    static int32_t int32_tFromHttpContent(const std::shared_ptr<HttpContent>& val);
    static float floatFromHttpContent(const std::shared_ptr<HttpContent>& val);
    static utility::string_t stringFromHttpContent(const std::shared_ptr<HttpContent>& val);
    static utility::datetime dateFromHttpContent(const std::shared_ptr<HttpContent>& val);
    static bool boolFromHttpContent(const std::shared_ptr<HttpContent>& val);
    static double doubleFromHttpContent(const std::shared_ptr<HttpContent>& val);
    static web::json::value valueFromHttpContent(const std::shared_ptr<HttpContent>& val);

    ///<summary>
    ///Static methods for encoding to Base64 string
    ///</summary>
    ///<param name="value">Value to encode</param>
    ///<returns>Encoded string</returns>
    static utility::string_t toBase64(const utility::string_t& value );
    static utility::string_t toBase64(const std::shared_ptr<std::istream>& value );
    ///<summary>
    ///Static method to decode an Base64 string
    ///</summary>
    ///<param name="value">String to decode</param>
    ///<returns>Decoded string</returns>
    static std::shared_ptr<std::istream> fromBase64( const utility::string_t& encoded );
    ///<summary>
    ///Checks that prefix starts with '.'
    ///</summary>
    ///<param name="value">prefix to check</param>
    ///<returns>Fixed prefix</returns>
    static utility::string_t fixNamePrefix(utility::string_t prefix);
};

template<class T>
web::json::value ModelBase::toJson(const std::vector<T>& value) {
    std::vector<web::json::value> ret;
    std::transform(value.begin(), value.end(), std::back_inserter(ret),
    [&](T x){
        return ModelBase::toJson(x);
    });

    return web::json::value::array(ret);
}

template <class T>
std::shared_ptr<HttpContent> ModelBase::toHttpContent( const utility::string_t& name, const std::vector<T>& value, const utility::string_t& contentType ) {
    web::json::value json_array = ModelBase::toJson(value);
    auto content = std::make_shared<HttpContent>();
    content->setName( name );
    content->setContentDisposition( _XPLATSTR("form-data") );
    content->setContentType( contentType );
    content->setData(std::make_shared<std::stringstream>( utility::conversions::to_utf8string(json_array.serialize()) ) );
    return content;
}

}
}
}

#endif /* _ModelBase_H_ */
