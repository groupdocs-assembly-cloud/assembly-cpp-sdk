/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="GroupDocs" file="AssemblyApi.h">
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

#ifndef _AssemblyApi_H_
#define _AssemblyApi_H_


#include "../ApiClient.h"


#include "requests/PostAssembleDocumentRequest.h"

#include "HttpContent.h"
#include "LoadSaveOptionsData.h"
#include <cpprest/details/basic_types.h>
#include <boost/optional.hpp>
namespace groupdocs {
namespace assembly {
namespace api {

using namespace groupdocs::assembly::model;
class  AssemblyApi
{
public:
    ///<summary>
    ///Builds a document using document template and XML or JSON data passed in request
    ///</summary>
    ///<remarks>
    ///
    ///</remarks>
    /// <param name="name">File name of template, which is located on a storage</param>
    /// <param name="data">Report data in JSON or XML format</param>
    /// <param name="saveOptions">Save options in json format</param>
    /// <param name="folder">Folder path where template file is located(on a storage) (optional)</param>
    /// <param name="destFileName">Result name of built document (optional)</param>
    pplx::task<HttpContent> postAssembleDocument(
        std::shared_ptr<PostAssembleDocumentRequest> request
        );

public:
    explicit AssemblyApi(std::shared_ptr<ApiClient> apiClient );
    virtual ~AssemblyApi() = default;
    
protected:
    std::shared_ptr<ApiClient> m_ApiClient;
};

}
}
}

#endif /* _AssemblyApi_H_ */


