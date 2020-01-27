/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="GroupDocs" file="PostAssembleDocumentRequest.h">
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
#pragma once
#ifndef postAssembleDocument_H
#define postAssembleDocument_H 

#include "cpprest/details/basic_types.h"
#include "ReportOptionsData.h"
#include <boost/optional.hpp>

namespace groupdocs {
namespace assembly {
namespace cloud {
namespace api {
namespace models {

class PostAssembleDocumentRequest{
    public: 
     PostAssembleDocumentRequest(
        utility::string_t name,
                std::shared_ptr<ReportOptionsData> reportData,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> destFileName
        );

        utility::string_t getName() const;
        void setName(utility::string_t name);

        std::shared_ptr<ReportOptionsData> getReportData() const;
        void setReportData(std::shared_ptr<ReportOptionsData> reportData);

        boost::optional<utility::string_t> getFolder() const;
        void setFolder(boost::optional<utility::string_t> folder);

        boost::optional<utility::string_t> getDestFileName() const;
        void setDestFileName(boost::optional<utility::string_t> destFileName);
    private:
        utility::string_t m_name;
        std::shared_ptr<ReportOptionsData> m_reportData;
        boost::optional<utility::string_t> m_folder;
        boost::optional<utility::string_t> m_destFileName;
};

}
}
}
}
}

#endif
