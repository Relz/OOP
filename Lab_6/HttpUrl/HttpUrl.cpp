#include "HttpUrl.h"

CHttpUrl::CHttpUrl(std::string const& url)
{
}

CHttpUrl::CHttpUrl(
    std::string const& domain,
    std::string const& document,
    Protocol = HTTP,
    unsigned short port = 80)
{

}

std::string CHttpUrl::GetURL() const
{

}

std::string CHttpUrl::GetDomain() const
{

}

std::string CHttpUrl::GetDocument() const
{

}

Protocol CHttpUrl::GetProtocol() const
{

}

unsigned short CHttpUrl::GetPort() const
{

}