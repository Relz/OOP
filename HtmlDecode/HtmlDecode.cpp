#include "stdafx.h"

std::string HtmlDecode(const std::string &text)
{
	std::string result;
	std::string htmlEntities[5][2] =
	{
		{ "&quot;", "\"" },
		{ "&apos;", "’" },
		{ "&lt;", "<" },
		{ "&gt;", ">" },
		{ "&amp;", "&" }
	};

	for (size_t textIndex = 0; textIndex < text.length(); ++textIndex)
	{
		bool wasReplace = false;

		if (text[textIndex] == '&')
		{
			for (size_t i = 0; i < 5; ++i)
			{
				if (text.find(htmlEntities[i][0].c_str(), textIndex, htmlEntities[i][0].length()) == textIndex)
				{
					result += htmlEntities[i][1];
					textIndex += htmlEntities[i][0].length() - 1;
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