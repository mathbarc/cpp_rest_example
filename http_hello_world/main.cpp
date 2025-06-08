#include <cpprest/http_listener.h>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

void handle_get(http_request request)
{
    json::value response;
    response[U("message")] = json::value::string(U("Hello, World!"));
    request.reply(status_codes::OK, response);
}

int main()
{
    http_listener listener(U("http://0.0.0.0:8080/hello"));
    listener.support(methods::GET, handle_get);
    listener.open().wait();
    std::cout << "Press ENTER to exit." << std::endl;
    std::string line;
    std::getline(std::cin, line);
    return 0;
}
