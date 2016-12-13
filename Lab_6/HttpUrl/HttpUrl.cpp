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
    return "";
}

std::string CHttpUrl::GetDomain() const
{
    return "";
}

std::string CHttpUrl::GetDocument() const
{
    return "";
}

Protocol CHttpUrl::GetProtocol() const
{
    return HTTP;
}

unsigned short CHttpUrl::GetPort() const
{
    return 0;
}