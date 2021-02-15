/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="TemplateFileInfo.cpp">
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


#include "TemplateFileInfo.h"

namespace groupdocs {
namespace assembly {
namespace cloud {
namespace api {
namespace models {

TemplateFileInfo::TemplateFileInfo()
{
    m_FilePath = utility::conversions::to_string_t("");
    m_FilePathIsSet = false;
    m_StorageName = utility::conversions::to_string_t("");
    m_StorageNameIsSet = false;
    m_VersionId = utility::conversions::to_string_t("");
    m_VersionIdIsSet = false;
    m_Password = utility::conversions::to_string_t("");
    m_PasswordIsSet = false;
}

TemplateFileInfo::~TemplateFileInfo()
{
}

void TemplateFileInfo::validate()
{
    // TODO: implement validation
}

web::json::value TemplateFileInfo::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_FilePathIsSet)
    {
        val[_XPLATSTR("FilePath")] = ModelBase::toJson(m_FilePath);
    }
    if(m_StorageNameIsSet)
    {
        val[_XPLATSTR("StorageName")] = ModelBase::toJson(m_StorageName);
    }
    if(m_VersionIdIsSet)
    {
        val[_XPLATSTR("VersionId")] = ModelBase::toJson(m_VersionId);
    }
    if(m_PasswordIsSet)
    {
        val[_XPLATSTR("Password")] = ModelBase::toJson(m_Password);
    }

    return val;
}

void TemplateFileInfo::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("FilePath")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("FilePath")];
        if(!fieldValue.is_null())
        {
            setFilePath(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("StorageName")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("StorageName")];
        if(!fieldValue.is_null())
        {
            setStorageName(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("VersionId")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("VersionId")];
        if(!fieldValue.is_null())
        {
            setVersionId(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("Password")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("Password")];
        if(!fieldValue.is_null())
        {
            setPassword(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void TemplateFileInfo::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_FilePathIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("FilePath"), m_FilePath));
        
    }
    if(m_StorageNameIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("StorageName"), m_StorageName));
        
    }
    if(m_VersionIdIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("VersionId"), m_VersionId));
        
    }
    if(m_PasswordIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Password"), m_Password));
        
    }
}

void TemplateFileInfo::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("FilePath")))
    {
        setFilePath(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("FilePath"))));
    }
    if(multipart->hasContent(_XPLATSTR("StorageName")))
    {
        setStorageName(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("StorageName"))));
    }
    if(multipart->hasContent(_XPLATSTR("VersionId")))
    {
        setVersionId(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("VersionId"))));
    }
    if(multipart->hasContent(_XPLATSTR("Password")))
    {
        setPassword(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Password"))));
    }
}

utility::string_t TemplateFileInfo::getFilePath() const
{
    return m_FilePath;
}


void TemplateFileInfo::setFilePath(utility::string_t value)
{
    m_FilePath = value;
    m_FilePathIsSet = true;
}
bool TemplateFileInfo::filePathIsSet() const
{
    return m_FilePathIsSet;
}

void TemplateFileInfo::unsetFilePath()
{
    m_FilePathIsSet = false;
}

utility::string_t TemplateFileInfo::getStorageName() const
{
    return m_StorageName;
}


void TemplateFileInfo::setStorageName(utility::string_t value)
{
    m_StorageName = value;
    m_StorageNameIsSet = true;
}
bool TemplateFileInfo::storageNameIsSet() const
{
    return m_StorageNameIsSet;
}

void TemplateFileInfo::unsetStorageName()
{
    m_StorageNameIsSet = false;
}

utility::string_t TemplateFileInfo::getVersionId() const
{
    return m_VersionId;
}


void TemplateFileInfo::setVersionId(utility::string_t value)
{
    m_VersionId = value;
    m_VersionIdIsSet = true;
}
bool TemplateFileInfo::versionIdIsSet() const
{
    return m_VersionIdIsSet;
}

void TemplateFileInfo::unsetVersionId()
{
    m_VersionIdIsSet = false;
}

utility::string_t TemplateFileInfo::getPassword() const
{
    return m_Password;
}


void TemplateFileInfo::setPassword(utility::string_t value)
{
    m_Password = value;
    m_PasswordIsSet = true;
}
bool TemplateFileInfo::passwordIsSet() const
{
    return m_PasswordIsSet;
}

void TemplateFileInfo::unsetPassword()
{
    m_PasswordIsSet = false;
}

}
}
}
}
}

