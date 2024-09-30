#include "server_networking/network.hpp"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <memory>

int main() {

    // Create console and file sinks
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    console_sink->set_level(spdlog::level::debug);

    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("network_logs.txt", true);
    file_sink->set_level(spdlog::level::info);

    std::vector<spdlog::sink_ptr> sinks = {console_sink, file_sink};

    Network server(7777, sinks);

    std::function<void(unsigned int)> on_client_connect = [&](unsigned int client_id) {
        /*physics.create_character(client_id);*/
        /*connected_character_data[client_id] = {client_id};*/
        spdlog::info("just registered a client with id {}", client_id);
        // TODO no need to broadcast this to everyone, only used once on the connecting client
        server.reliable_send(client_id, &client_id, sizeof(unsigned int));
    };

    server.set_on_connect_callback(on_client_connect);
    server.initialize_network();

    while (true) {
        server.get_network_events_since_last_tick();
    }

    return 0;
}
