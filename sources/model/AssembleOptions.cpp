/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="AssembleOptions.cpp">
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


#include "AssembleOptions.h"

namespace groupdocs {
namespace assembly {
namespace cloud {
namespace api {
namespace models {

AssembleOptions::AssembleOptions()
{
    m_TemplateFileInfoIsSet = false;
    m_SaveFormat = utility::conversions::to_string_t("");
    m_SaveFormatIsSet = false;
    m_ReportData = utility::conversions::to_string_t("");
    m_ReportDataIsSet = false;
    m_OutputPath = utility::conversions::to_string_t("");
    m_OutputPathIsSet = false;
}

AssembleOptions::~AssembleOptions()
{
}

void AssembleOptions::validate()
{
    // TODO: implement validation
}

web::json::value AssembleOptions::toJson() const
{
    web::json::value val = web::json::value::object();

    if(m_TemplateFileInfoIsSet)
    {
        val[_XPLATSTR("TemplateFileInfo")] = ModelBase::toJson(m_TemplateFileInfo);
    }
    if(m_SaveFormatIsSet)
    {
        val[_XPLATSTR("SaveFormat")] = ModelBase::toJson(m_SaveFormat);
    }
    if(m_ReportDataIsSet)
    {
        val[_XPLATSTR("ReportData")] = ModelBase::toJson(m_ReportData);
    }
    if(m_OutputPathIsSet)
    {
        val[_XPLATSTR("OutputPath")] = ModelBase::toJson(m_OutputPath);
    }

    return val;
}

void AssembleOptions::fromJson(web::json::value& val)
{
    if(val.has_field(_XPLATSTR("TemplateFileInfo")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("TemplateFileInfo")];
        if(!fieldValue.is_null())
        {
            std::shared_ptr<TemplateFileInfo> newItem(new TemplateFileInfo());
            newItem->fromJson(fieldValue);
            setTemplateFileInfo( newItem );
        }
    }
    if(val.has_field(_XPLATSTR("SaveFormat")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("SaveFormat")];
        if(!fieldValue.is_null())
        {
            setSaveFormat(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("ReportData")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("ReportData")];
        if(!fieldValue.is_null())
        {
            setReportData(ModelBase::stringFromJson(fieldValue));
        }
    }
    if(val.has_field(_XPLATSTR("OutputPath")))
    {
        web::json::value& fieldValue = val[_XPLATSTR("OutputPath")];
        if(!fieldValue.is_null())
        {
            setOutputPath(ModelBase::stringFromJson(fieldValue));
        }
    }
}

void AssembleOptions::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    if(m_TemplateFileInfoIsSet)
    {
        if (m_TemplateFileInfo.get())
        {
            m_TemplateFileInfo->toMultipart(multipart, _XPLATSTR("TemplateFileInfo."));
        }
        
    }
    if(m_SaveFormatIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("SaveFormat"), m_SaveFormat));
        
    }
    if(m_ReportDataIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("ReportData"), m_ReportData));
        
    }
    if(m_OutputPathIsSet)
    {
        multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("OutputPath"), m_OutputPath));
        
    }
}

void AssembleOptions::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    if(multipart->hasContent(_XPLATSTR("TemplateFileInfo")))
    {
        if(multipart->hasContent(_XPLATSTR("TemplateFileInfo")))
        {
            std::shared_ptr<TemplateFileInfo> newItem(new TemplateFileInfo());
            newItem->fromMultiPart(multipart, _XPLATSTR("TemplateFileInfo."));
            setTemplateFileInfo( newItem );
        }
    }
    if(multipart->hasContent(_XPLATSTR("SaveFormat")))
    {
        setSaveFormat(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("SaveFormat"))));
    }
    if(multipart->hasContent(_XPLATSTR("ReportData")))
    {
        setReportData(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("ReportData"))));
    }
    if(multipart->hasContent(_XPLATSTR("OutputPath")))
    {
        setOutputPath(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("OutputPath"))));
    }
}

std::shared_ptr<TemplateFileInfo> AssembleOptions::getTemplateFileInfo() const
{
    return m_TemplateFileInfo;
}


void AssembleOptions::setTemplateFileInfo(std::shared_ptr<TemplateFileInfo> value)
{
    m_TemplateFileInfo = value;
    m_TemplateFileInfoIsSet = true;
}
bool AssembleOptions::templateFileInfoIsSet() const
{
    return m_TemplateFileInfoIsSet;
}

void AssembleOptions::unsetTemplateFileInfo()
{
    m_TemplateFileInfoIsSet = false;
}

utility::string_t AssembleOptions::getSaveFormat() const
{
    return m_SaveFormat;
}


void AssembleOptions::setSaveFormat(utility::string_t value)
{
    m_SaveFormat = value;
    m_SaveFormatIsSet = true;
}
bool AssembleOptions::saveFormatIsSet() const
{
    return m_SaveFormatIsSet;
}

void AssembleOptions::unsetSaveFormat()
{
    m_SaveFormatIsSet = false;
}

utility::string_t AssembleOptions::getReportData() const
{
    return m_ReportData;
}


void AssembleOptions::setReportData(utility::string_t value)
{
    m_ReportData = value;
    m_ReportDataIsSet = true;
}
bool AssembleOptions::reportDataIsSet() const
{
    return m_ReportDataIsSet;
}

void AssembleOptions::unsetReportData()
{
    m_ReportDataIsSet = false;
}

utility::string_t AssembleOptions::getOutputPath() const
{
    return m_OutputPath;
}


void AssembleOptions::setOutputPath(utility::string_t value)
{
    m_OutputPath = value;
    m_OutputPathIsSet = true;
}
bool AssembleOptions::outputPathIsSet() const
{
    return m_OutputPathIsSet;
}

void AssembleOptions::unsetOutputPath()
{
    m_OutputPathIsSet = false;
}

}
}
}
}
}

