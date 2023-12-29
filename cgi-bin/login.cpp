#include <iostream>
#include <cstdlib>

int main() {
    std::string requestMethod = getenv("REQUEST_METHOD");

    if (requestMethod == "OPTIONS") {
        // 处理 OPTIONS 预检请求
        std::cout << "Content-type: text/plain\r\n";
        std::cout << "Access-Control-Allow-Origin: http://127.0.0.1:5500\r\n";
        std::cout << "Access-Control-Allow-Methods: POST, OPTIONS\r\n";
        std::cout << "Access-Control-Allow-Headers: Content-Type\r\n";
        std::cout << "\r\n";
    } else if (requestMethod == "POST") {
        // 处理 POST 请求
        std::cout << "Content-type: application/json\r\n";
        std::cout << "Access-Control-Allow-Origin: http://127.0.0.1:5500\r\n\r\n";

        // 获取从前端传递的 JSON 数据
        std::string contentLengthStr = getenv("CONTENT_LENGTH");
        if (!contentLengthStr.empty()) {
            int contentLength = std::stoi(contentLengthStr);

            // 读取 POST 数据
            std::string postData;
            postData.resize(contentLength);
            std::cin.read(&postData[0], contentLength);

            //需要对接收到的 JSON 数据进行处理
            std::cout << postData << std::flush;
        } else {
            std::cout << "Error: No content length provided" << std::endl;
        }
    }

    return 0;
}
