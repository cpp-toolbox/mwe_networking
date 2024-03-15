#include <stdio.h>
#include <stdexcept>
#include "client.hpp"
#include "server.hpp"
#include <string.h>


int main(int argc, char *argv[]) {
    if (argc == 2) {
        if (!strcmp(argv[1], "c")) {
            printf("running client\n");
            run_client();
        } else if (!strcmp(argv[1], "s")) {
            printf("running server\n");
            run_server_loop();
        }
    } else {
        throw std::runtime_error("program requires exactly one argument specifying to start the server or client (s/c)");
    }
    return 0;
}