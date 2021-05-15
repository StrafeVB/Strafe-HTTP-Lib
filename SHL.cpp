#include "SHL.hpp"

static std::string webresponse{};

static size_t CurlToString(char* str, size_t sz, size_t nmem, std::string* strstream)
{
	webresponse.erase(webresponse.size());
	size_t acsz = sz * nmem;
	webresponse.append(str, acsz);
	return acsz;
}


std::string StrafeHttpReq::HttpsPost(std::string url, std::string useragent, std::string postdat = "")
{
	if (url.empty())
		throw std::invalid_argument("No url provided");

	if (useragent.empty())
		throw std::invalid_argument("No user-agent provided");

	CURL* postreq{};
	CURLcode postres{};

	postreq = curl_easy_init();

	if (postreq)
	{
		curl_easy_setopt(postreq, CURLOPT_URL, url.c_str());
		curl_easy_setopt(postreq, CURLOPT_USERAGENT, useragent.c_str());
		curl_easy_setopt(postreq, CURLOPT_PROTOCOLS, CURLPROTO_HTTPS);
		curl_easy_setopt(postreq, CURLOPT_POST, 1L);
		curl_easy_setopt(postreq, CURLOPT_POSTFIELDS, postdat.c_str());
		curl_easy_setopt(postreq, CURLOPT_FOLLOWLOCATION, 1L);
		curl_easy_setopt(postreq, CURLOPT_WRITEFUNCTION, CurlToString);
		curl_easy_perform(postreq);

		if (postres != CURLE_OK)
			std::cout << "Post request failed" << std::endl;
	}
	else
		std::cout << "couldnt init" << std::endl;

	curl_easy_cleanup(postreq);

	return webresponse;
}

std::string StrafeHttpReq::CreateSafePostData(std::string postreqname, std::string postdat)
{
	std::stringstream result{};

	CURL* prepreq{};
	prepreq = curl_easy_init();

	char* encoded = curl_easy_escape(prepreq, postdat.c_str(), postdat.length());

	if (encoded)
	{
		result << postreqname << encoded;
		curl_free(encoded);
	}
	else
		std::cout << "failed" << std::endl;

	curl_easy_cleanup(prepreq);

	return result.str();
}

StrafeHttpReq::StrafeHttpReq(void)
{
	curl_global_init(CURL_GLOBAL_ALL);
}

StrafeHttpReq::~StrafeHttpReq(void)
{
	curl_global_cleanup();
}
