/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="GroupDocs" file="PostAssembleDocumentRequest.cpp">
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
#include "PostAssembleDocumentRequest.h"
namespace groupdocs{
namespace assembly{
namespace cloud{
namespace api{
namespace models{
PostAssembleDocumentRequest::PostAssembleDocumentRequest(
        utility::string_t name,
                std::shared_ptr<ReportOptionsData> reportData,
                boost::optional<utility::string_t> folder,
                boost::optional<utility::string_t> destFileName
        ) : 
            m_name(std::move(name)),
            m_reportData(std::move(reportData)),
            m_folder(std::move(folder)),
            m_destFileName(std::move(destFileName))
        {
            
        }

        utility::string_t PostAssembleDocumentRequest::getName() const
        {
            return m_name;
        }
        void PostAssembleDocumentRequest::setName(utility::string_t name){
            m_name = std::move(name);
        }
        std::shared_ptr<ReportOptionsData> PostAssembleDocumentRequest::getReportData() const
        {
            return m_reportData;
        }
        void PostAssembleDocumentRequest::setReportData(std::shared_ptr<ReportOptionsData> reportData){
            m_reportData = std::move(reportData);
        }
        boost::optional<utility::string_t> PostAssembleDocumentRequest::getFolder() const
        {
            return m_folder;
        }
        void PostAssembleDocumentRequest::setFolder(boost::optional<utility::string_t> folder){
            m_folder = std::move(folder);
        }
        boost::optional<utility::string_t> PostAssembleDocumentRequest::getDestFileName() const
        {
            return m_destFileName;
        }
        void PostAssembleDocumentRequest::setDestFileName(boost::optional<utility::string_t> destFileName){
            m_destFileName = std::move(destFileName);
        }

}
}
}
}
}

