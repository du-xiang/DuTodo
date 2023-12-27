#include <iostream>

int main() {
    // 禁用缓存
    std::cout << "Cache-Control: no-store, no-cache, must-revalidate\n";
    std::cout << "Pragma: no-cache\n";
    std::cout << "Expires: 0\n";

    // 设置允许所有域访问，你也可以根据需要设置特定的域
    std::cout << "Access-Control-Allow-Origin: *\n";

    // 设置 Content-Type 为 application/json
    std::cout << "Content-Type: application/json\n\n";

    // 输出 JSON 格式的数据
    std::cout << "{ \"message\": \"Hello from the Backend! var/www/html/cgi-bin\" }";

    return 0;
}
