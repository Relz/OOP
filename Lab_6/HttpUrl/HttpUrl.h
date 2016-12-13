#pragma once
#include "stdafx.h"

enum Protocol
{
    HTTP,
    HTTPS
};

class CHttpUrl
{
public:
    CHttpUrl(std::string const& url);
    ~CHttpUrl() = default;

    CHttpUrl(
        std::string const& domain,
        std::string const& document,
        Protocol,
        unsigned short port);

    std::string GetURL() const;
    std::string GetDomain() const;
    std::string GetDocument() const;
    Protocol GetProtocol() const;
    unsigned short GetPort() const;
};
