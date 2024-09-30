#include "client_networking/network.hpp"
#include "fixed_frequency_loop/fixed_frequency_loop.hpp"
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

    std::string ip_address = "localhost";
    Network network(ip_address, 7777, sinks);
    FixedFrequencyLoop wait_until_received_id_loop;

    network.initialize_network();
    network.attempt_to_connect_to_server();

    /*// todo turn this into a network thing and pass a max wait time to it, note that it blocks.*/
    /*wait_until_received_id_loop.start(2, check_for_client_id, got_client_id);*/

    return 0;
}
