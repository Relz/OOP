#pragma once
#include "stdafx.h"

enum Protocol
{
    HTTP,
    HTTPS
};

class CUrlParsingError : public std::invalid_argument
{
public:
    CUrlParsingError(std::string message);
    ~CUrlParsingError() = default;
};

