#include "stdafx.h"

std::string HtmlDecode(const std::string &text)
{
	std::string result = "";
	const std::map<std::string, char> htmlEntities =
	{
		{ "quot", '"' },
		{ "apos", '’' },
		{ "lt", '<' },
		{ "gt", '>' },
		{ "amp", '&' }
	};

	const std::vector<std::string> htmlEntitiesKeys =
	{
		{ "quot" },
		{ "apos" },
		{ "lt" },
		{ "gt" },
		{ "amp" }
	};

	for (unsigned textIndex = 0; textIndex < text.length(); ++textIndex)
	{
		if (text[textIndex] == '&')
		{
			std::vector<std::string> htmlEntitiesKeysCopy(htmlEntitiesKeys);
			unsigned charPos = 0;
			std::string savedStr = "";
			savedStr += text[textIndex];
			textIndex++;
			while (textIndex < text.length() && text[textIndex] != ';' && text[textIndex] != '&' && htmlEntitiesKeysCopy.size() > 0)
			{
				savedStr += text[textIndex];
				for (unsigned htmlEntitiesKeyIndex = 0; htmlEntitiesKeyIndex < htmlEntitiesKeysCopy.size(); ++htmlEntitiesKeyIndex)
				{
					if (text[textIndex] != htmlEntitiesKeysCopy.at(htmlEntitiesKeyIndex)[charPos])
					{
						htmlEntitiesKeysCopy.erase(htmlEntitiesKeysCopy.begin() + htmlEntitiesKeyIndex);
						htmlEntitiesKeyIndex--;
					}
				}
				charPos++;
				textIndex++;
			}

			if (text[textIndex] == '&')
			{
				textIndex--;
			}
			else if (textIndex < text.length())
			{
				savedStr += text[textIndex];
			}

			if (htmlEntitiesKeysCopy.size() == 1 && text[textIndex] == ';')
			{
				result += htmlEntities.at(htmlEntitiesKeysCopy.at(0));
			}
			else
			{
				result += savedStr;
			}
		}
		else
		{
			result += text[textIndex];
		}
	}
	return result;
}