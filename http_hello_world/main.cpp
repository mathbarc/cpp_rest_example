#include <cpprest/containerstream.h>
#include <cpprest/filestream.h>
#include <cpprest/http_listener.h>
#include <fstream>
#include <ios>
#include <sstream>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

void handle_get(http_request request)
{
    std::cout << request.to_string() << std::endl;
    json::value response;
    response[U("message")] = json::value::string(U("Hello, World!"));

    std::cout << "loading file leonmusha.jpg" << std::endl;
    std::ifstream file("leonmusha.jpg", std::ios::binary);
    std::stringstream fileStream;
    fileStream << file.rdbuf();

    auto stream = concurrency::streams::stringstream::open_istream(fileStream.str()).streambuf();
    request.reply(status_codes::OK, stream, U("image/jpg"));
}

int main()
{
    http_listener listener(U("http://0.0.0.0:8080"));
    listener.support(methods::GET, handle_get);
    listener.open().wait();
    std::cout << "Press ENTER to exit." << std::endl;
    std::string line;
    std::getline(std::cin, line);
    return 0;
}
