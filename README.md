# Strafe-HTTP-Lib (x64-release only atm)
This is just a basic wrapper for libcurl to make it relatively easier to create HTTPS POST requests in C++, most credits go to the libcurl, and curl project https://curl.se/libcurl/

I'll add more to this later, for now this only has the ability to make HTTPS POST requests and nothing else but I will add more later.

## How to setup:
1. Take the pre-built "curl" folder and place it in your project file in the same location as the source files

2. Right click project properties and go to Linker->Input and paste this in "Additional Dependencies":  libcurl_a.lib;Ws2_32.lib;Crypt32.lib;Wldap32.lib;Normaliz.lib;kernel32.lib;user32.lib;gdi32.lib;winspool.lib;comdlg32.lib;advapi32.lib;shell32.lib;ole32.lib;oleaut32.lib;uuid.lib;odbc32.lib;odbccp32.lib;

3. In project properties go to C/C++-> Preprocessor and paste put this into the "Preprocessor Definitions" _CRT_SECURE_NO_WARNINGS;CURL_STATICLIB;

4. In project properties go to Linker->General and paste the complete directory to the curl/lib folder in "Additional Library Directories"

5. In project properties go to C/C++->General and paste the complete directory to the curl/include folder in "Additional Include Directories"

6. Profit

## Usage:
(Include the "SHL.hpp" file in your source file), and make sure to use both SHL.cpp, and SHL.hpp in your project
```cpp
std::unique_ptr<StrafeHttpReq> shr = std::make_unique<StrafeHttpReq>();
std::string response = shr->HttpsPost("https://strafe.gov/mostwanted.php", "Your user-agent", shr->CreateSafePostData("name=", "922fire"));
```

### License:
Free use MIT do whatever the hell you want whenever the hell you want with this I only take credits for the two source files "SHL.hpp, SHL.cpp" everything else is created by the libcurl/curl team more information about that can be found here https://curl.se/libcurl/
