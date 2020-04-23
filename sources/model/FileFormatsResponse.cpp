/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FileFormatsResponse.cpp">
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


#include "FileFormatsResponse.h"

namespace groupdocs {
namespace assembly {
namespace cloud {
namespace api {
namespace models {

FileFormatsResponse::FileFormatsResponse()
{
    m_FileFormatsIsSet = false;
    m_Code = 0;
    m_CodeIsSet = false;
    m_Status = utility::conversions::to_string_t("");
    m_StatusIsSet = false;
}

FileFormatsResponse::~FileFormatsResponse()
{
}

void FileFormatsResponse::validate()
{
    // TODO: implement validation
}

web::json::value FileFormatsResponse::toJson() const
{
    web::json::value val = this->AssemblyResponse::toJson();

    if(m_FileFormatsIsSet)
    {
        val[_XPLATSTR("FileFormats")] = ModelBase::toJson(m_FileFormats);
    }
    if(m_CodeIsSet)
    {
        val[_XPLATSTR("Code")] = ModelBase::toJson(m_Code);
    }
    if(m_StatusIsSet)
    {
        val[_XPLATSTR("Status")] = ModelBase::toJson(m_Status);
    }

    return val;
}

void FileFormatsResponse::fromJson(web::json::value& val)
{
    this->AssemblyResponse::fromJson(val);

    if(val.has_field(_XPLATSTR("FileFormats")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("FileFormats")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<FormatCollection> newItem(new FormatCollection());
            newItem->fromJson(fieldValue);
            setFileFormats( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("Code")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Code")];
        if(!fieldValue.is_null())
        {
            setCode(ModelBase::int32_tFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("Status")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Status")];
        if(!fieldValue.is_null())
        {
            setStatus(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void FileFormatsResponse::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_RequestIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("RequestId"), m_RequestId));
        
    }
    if(m_FileFormatsIsSet)
    {
        if (m_FileFormats.get())
        {
            m_FileFormats->toMultipart(multipart, _XPLATSTR("FileFormats."));
        }
        
    }
    if(m_CodeIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Code"), m_Code));
    }
    if(m_StatusIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Status"), m_Status));
        
    }
}

void FileFormatsResponse::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("RequestId")))
    {
        setRequestId(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("RequestId"))));
    }
    if(multipart->hasContent(_XPLATSTR("FileFormats")))
    {
        if(multipart->hasContent(_XPLATSTR("FileFormats")))
        {
            std::shared_ptr<FormatCollection> newItem(new FormatCollection());
            newItem->fromMultiPart(multipart, _XPLATSTR("FileFormats."));
            setFileFormats( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("Code")))
    {
        setCode(ModelBase::int32_tFromHttpContent(multipart->getContent(_XPLATSTR("Code"))));
    }
    if(multipart->hasContent(_XPLATSTR("Status")))
    {
        setStatus(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Status"))));
    }
}

std::shared_ptr<FormatCollection> FileFormatsResponse::getFileFormats() const
{
    return m_FileFormats;
}


void FileFormatsResponse::setFileFormats(std::shared_ptr<FormatCollection> value)
{
    m_FileFormats = value;
    m_FileFormatsIsSet = true;
}
bool FileFormatsResponse::fileFormatsIsSet() const
{
    return m_FileFormatsIsSet;
}

void FileFormatsResponse::unsetFileFormats()
{
    m_FileFormatsIsSet = false;
}

int32_t FileFormatsResponse::getCode() const
{
    return m_Code;
}


void FileFormatsResponse::setCode(int32_t value)
{
    m_Code = value;
    m_CodeIsSet = true;
}
bool FileFormatsResponse::codeIsSet() const
{
    return m_CodeIsSet;
}

void FileFormatsResponse::unsetCode()
{
    m_CodeIsSet = false;
}

utility::string_t FileFormatsResponse::getStatus() const
{
    return m_Status;
}


void FileFormatsResponse::setStatus(utility::string_t value)
{
    m_Status = value;
    m_StatusIsSet = true;
}
bool FileFormatsResponse::statusIsSet() const
{
    return m_StatusIsSet;
}

void FileFormatsResponse::unsetStatus()
{
    m_StatusIsSet = false;
}

}
}
}
}
}

