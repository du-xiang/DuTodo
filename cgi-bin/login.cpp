#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

// 简化的 JSON 解析函数
std::string getJsonValue(const std::string& jsonString, const std::string& key) {
    size_t keyPos = jsonString.find("\"" + key + "\":");
    if (keyPos == std::string::npos) {
        // 没找到键
        return "";
    }

    // 找到键后的冒号后面的位置
    size_t colonPos = jsonString.find(":", keyPos);

    // 找到值的起始位置
    size_t valueStart = jsonString.find_first_not_of(" \t\n{[\"", colonPos + 1);

    // 找到值的结束位置
    size_t valueEnd = jsonString.find_first_of(",}\"]", valueStart);

    // 提取值
    return jsonString.substr(valueStart, valueEnd - valueStart);
}

void setCookie() {
    // 获取当前时间
    std::time_t now = std::time(0);

    // 设置 Cookie 的过期时间为一天后的当前时间
    std::tm expirationTime = *std::localtime(&now);
    expirationTime.tm_mday += 1;

    // 将时间转换成 Cookie 格式字符串
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%a, %d %b %Y %H:%M:%S GMT", &expirationTime);

    // 输出 Set-Cookie 头部
    std::cout << "Set-Cookie: cookieStatus=OK; expires=" << buffer << "; SameSite=None; Secure\r\n";
    std::cout << "\r\n";
}

int main() {
    std::string requestMethod ;
    if(getenv("REQUEST_METHOD") != nullptr)
        requestMethod = getenv("REQUEST_METHOD");

    std::string username = "admin";
    std::string keyword = "1234";

    if (requestMethod == "OPTIONS") {
        // 处理 OPTIONS 预检请求
        std::cout << "Content-type: text/plain\r\n";
        std::cout << "Access-Control-Allow-Origin: *\r\n";
        std::cout << "Access-Control-Allow-Methods: POST, OPTIONS\r\n";
        std::cout << "Access-Control-Allow-Headers: Content-Type\r\n";
        std::cout << "\r\n";
    } else if (requestMethod == "POST") {
        // 处理 POST 请求
        std::cout << "Content-type: application/json\r\n";
        std::cout << "Access-Control-Allow-Origin: *\r\n";

        // 获取从前端传递的 JSON 数据
        std::string contentLengthStr;
        if(getenv("CONTENT_LENGTH") != nullptr)
            contentLengthStr = getenv("CONTENT_LENGTH");

        if (!contentLengthStr.empty()) {
            int contentLength = std::stoi(contentLengthStr);

            // 读取 POST 数据
            std::string postData;
            postData.resize(contentLength);
            std::cin.read(&postData[0], contentLength);

            // 对接收到的 JSON 数据进行处理
            std::string username_get = getJsonValue(postData, "username");
            std::string keyword_get = getJsonValue(postData, "password");

            if(username_get == username && keyword_get == keyword){
                setCookie();
                std::cout << "{\"status\": \"OK!\"}";
            }
            else
            {
                std::cout << "{\"status\":\"ERROR!\"}";
            }
        } 
        else 
        {
            std::cout << "Error: No content length provided" << std::endl;
        }
    }
    else
    {
        std::cout << "request bad";
    }

    return 0;
}
