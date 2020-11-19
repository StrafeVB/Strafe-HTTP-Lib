#include <curl/curl.h>
#include <string>
#include <stdexcept>
#include <vector>
#include <memory>
#include <sstream>
#include <iostream>

class StrafeHttpReq
{
public:
	StrafeHttpReq();
	~StrafeHttpReq();
	std::string HttpsPost(std::string url, std::string useragent, std::string postdat);
	std::string CreateSafePostData(std::string postreqname, std::string postdat);
};