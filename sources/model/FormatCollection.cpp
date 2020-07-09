/** --------------------------------------------------------------------------------------------------------------------
* <copyright company="Aspose" file="FormatCollection.cpp">
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


#include "FormatCollection.h"

namespace groupdocs {
namespace assembly {
namespace cloud {
namespace api {
namespace models {

FormatCollection::FormatCollection()
{
    m_FormatsIsSet = false;
}

FormatCollection::~FormatCollection()
{
}

void FormatCollection::validate()
{
    // TODO: implement validation
}

web::json::value FormatCollection::toJson() const
{
    web::json::value val = web::json::value::object();

    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_Formats.begin(), m_Formats.end(), std::back_inserter(jsonArray),
			[&](std::shared_ptr<Format> item) {
			return ModelBase::toJson(item);
		});
        
        if(jsonArray.size() > 0)
        {
            val[_XPLATSTR("Formats")] = web::json::value::array(jsonArray);
        }
    }

    return val;
}

void FormatCollection::fromJson(web::json::value& val)
{
    {
        m_Formats.clear();
        if(val.has_field(_XPLATSTR("Formats")) 
                            && !val[_XPLATSTR("Formats")].is_null())
        {
        auto arr = val[_XPLATSTR("Formats")].as_array();
        std::transform(arr.begin(), arr.end(), std::back_inserter(m_Formats), [&](web::json::value& item){
            if(item.is_null())
            {
                return std::shared_ptr<Format>(nullptr);
            }
            else
            {
                std::shared_ptr<Format> newItem(new Format());
                newItem->fromJson(item);
                return newItem;
            }
        });

        }
    }
}

void FormatCollection::toMultipart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix) const
{
    auto namePrefix = ModelBase::fixNamePrefix(prefix);

    {
        std::vector<web::json::value> jsonArray;
        std::transform(m_Formats.begin(), m_Formats.end(), std::back_inserter(jsonArray), [&](std::shared_ptr<Format> item){
            return ModelBase::toJson(item);
        });
        
        if(jsonArray.size() > 0)
        {
            multipart->add(ModelBase::toHttpContent(namePrefix + _XPLATSTR("Formats"), web::json::value::array(jsonArray), _XPLATSTR("application/json")));
        }
    }
}

void FormatCollection::fromMultiPart(const std::shared_ptr<MultipartFormData>& multipart, const utility::string_t& prefix)
{
    {
        m_Formats.clear();
        if(multipart->hasContent(_XPLATSTR("Formats")))
        {

        web::json::array jsonArray = web::json::value::parse(ModelBase::stringFromHttpContent(multipart->getContent(_XPLATSTR("Formats")))).as_array();
        std::transform(jsonArray.begin(), jsonArray.end(), std::back_inserter(m_Formats), [&](web::json::value item) {
            if(item.is_null())
            {
                return std::shared_ptr<Format>(nullptr) ;
            }
            else
            {
                std::shared_ptr<Format> newItem(new Format());
                newItem->fromJson(item);
                return newItem ;
            }
        });
        }
    }
}

std::vector<std::shared_ptr<Format>>& FormatCollection::getFormats()
{
    return m_Formats;
}

void FormatCollection::setFormats(std::vector<std::shared_ptr<Format>> const& value)
{
    m_Formats = value;
    m_FormatsIsSet = true;
}
bool FormatCollection::formatsIsSet() const
{
    return m_FormatsIsSet;
}

void FormatCollection::unsetFormats()
{
    m_FormatsIsSet = false;
}

}
}
}
}
}

