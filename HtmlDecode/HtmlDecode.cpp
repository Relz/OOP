#include "stdafx.h"

namespace
{
    std::string HTML_ENTITIES[5][2] =
    {
        { "&quot;", "\"" },
        { "&apos;", "’" },
        { "&lt;", "<" },
        { "&gt;", ">" },
        { "&amp;", "&" }
    };
}

std::string HtmlDecode(const std::string &text)
{
    std::string result;

    for (size_t textIndex = 0; textIndex < text.length(); ++textIndex)
    {
        bool wasReplace = false;

        if (text[textIndex] == '&')
        {
            for (size_t i = 0; i < 5; ++i)
            {
                if (text.find(HTML_ENTITIES[i][0].c_str(), textIndex, HTML_ENTITIES[i][0].length()) == textIndex)
                {
                    result += HTML_ENTITIES[i][1];
                    textIndex += HTML_ENTITIES[i][0].length() - 1;
                    wasReplace = true;
                }
            }
        }
        if (!wasReplace)
        {
            result += text[textIndex];
        }
    }
    return result;
}