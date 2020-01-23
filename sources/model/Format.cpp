/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="GroupDocs" file="Format.cpp">
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


#include "Format.h"

namespace groupdocs {
namespace assembly {
namespace cloud {
namespace api {
namespace models {

Format::Format()
{
    m_FileFormat = utility::conversions::to_string_t("");
    m_FileFormatIsSet = false;
    m_Extension = utility::conversions::to_string_t("");
    m_ExtensionIsSet = false;
}

Format::~Format()
{
}

void Format::validate()
{
    // TODO: implement validation
}

web::json::value Format::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_FileFormatIsSet)
    {
        val[_XPLATSTR("FileFormat")] = ModelBase::toJson(m_FileFormat);
    }
    if(m_ExtensionIsSet)
    {
        val[_XPLATSTR("Extension")] = ModelBase::toJson(m_Extension);
    }

    return val;
}

void Format::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("FileFormat")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("FileFormat")];
        if(!fieldValue.is_null())
        {
            setFileFormat(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("Extension")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Extension")];
        if(!fieldValue.is_null())
        {
            setExtension(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void Format::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_FileFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("FileFormat"), m_FileFormat));
        
    }
    if(m_ExtensionIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Extension"), m_Extension));
        
    }
}

void Format::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("FileFormat")))
    {
        setFileFormat(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("FileFormat"))));
    }
    if(multipart->hasContent(_XPLATSTR("Extension")))
    {
        setExtension(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Extension"))));
    }
}

utility::string_t Format::getFileFormat() const
{
    return m_FileFormat;
}


void Format::setFileFormat(utility::string_t value)
{
    m_FileFormat = value;
    m_FileFormatIsSet = true;
}
bool Format::fileFormatIsSet() const
{
    return m_FileFormatIsSet;
}

void Format::unsetFileFormat()
{
    m_FileFormatIsSet = false;
}

utility::string_t Format::getExtension() const
{
    return m_Extension;
}


void Format::setExtension(utility::string_t value)
{
    m_Extension = value;
    m_ExtensionIsSet = true;
}
bool Format::extensionIsSet() const
{
    return m_ExtensionIsSet;
}

void Format::unsetExtension()
{
    m_ExtensionIsSet = false;
}

}
}
}
}
}

