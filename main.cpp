#include <drogon/drogon.h>

int main() {
    // Create a simple Drogon application
    auto& app = drogon::app().addListener("0.0.0.0", 8080);

    // Add a handler for the root URL
    app.registerHandler("/", [](const drogon::HttpRequestPtr& req, std::function<void(const drogon::HttpResponsePtr&)>&& callback) {
        auto resp = drogon::HttpResponse::newHttpResponse();
        resp->setBody("Hello, World!");
        callback(resp);
        });

    // Run the application
    app.run();

    return 0;
}
