
/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="AssembleOptions.h">
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

#ifndef GROUPDOCS_ASSEMBLY_CLOUD_API_MODELS_AssembleOptions_H_
#define GROUPDOCS_ASSEMBLY_CLOUD_API_MODELS_AssembleOptions_H_


#include "../ModelBase.h"

#include <cpprest/details/basic_types.h>
#include "TemplateFileInfo.h"

namespace groupdocs {
namespace assembly {
namespace cloud {
namespace api {
namespace models {

/// <summary>
/// Assemble options data which is using for specifying assemble options, like template name, save format, report data and etc.
/// </summary>
class  AssembleOptions
    : public ModelBase
{
public:
    AssembleOptions();
    virtual ~AssembleOptions();

    /////////////////////////////////////////////
    /// ModelBase overrides

    void validate() override;

    web::json::value toJson() const override;
    void fromJson(web::json::value& json) override;

    void toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) const override;
    void fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& namePrefix) override;

    /////////////////////////////////////////////
    /// AssembleOptions members

    /// <summary>
    /// Gets or sets the template name which is located on storage.
    /// </summary>
    std::shared_ptr<TemplateFileInfo> getTemplateFileInfo() const;
    bool templateFileInfoIsSet() const;
    void unsetTemplateFileInfo();
    void setTemplateFileInfo(std::shared_ptr<TemplateFileInfo> value);
    /// <summary>
    /// Gets or sets a save format for assembled document.
    /// </summary>
    utility::string_t getSaveFormat() const;
    bool saveFormatIsSet() const;
    void unsetSaveFormat();
    void setSaveFormat(utility::string_t value);
    /// <summary>
    /// Gets or sets a data for report.
    /// </summary>
    utility::string_t getReportData() const;
    bool reportDataIsSet() const;
    void unsetReportData();
    void setReportData(utility::string_t value);
    /// <summary>
    /// Gets or sets result path of a built document.
    /// </summary>
    utility::string_t getOutputPath() const;
    bool outputPathIsSet() const;
    void unsetOutputPath();
    void setOutputPath(utility::string_t value);

protected:
    std::shared_ptr<TemplateFileInfo> m_TemplateFileInfo;
    bool m_TemplateFileInfoIsSet;
    utility::string_t m_SaveFormat;
    bool m_SaveFormatIsSet;
    utility::string_t m_ReportData;
    bool m_ReportDataIsSet;
    utility::string_t m_OutputPath;
    bool m_OutputPathIsSet;
};

}
}
}
}
}

#endif /* GROUPDOCS_ASSEMBLY_CLOUD_API_MODELS_AssembleOptions_H_ */
