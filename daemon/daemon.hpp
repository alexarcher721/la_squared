#pragma once
#ifndef LA2_DAEMON
#define LA2_DAEMON 

#include <string>
#include <vector>

#include <sys/socket.h>

#include "request.hpp"
#include "virtual_core.hpp"

namespace laa {

class Daemon {

public:

    /**
     * @brief Construct a new la2 daemon object
     * @todo  Should initialize the sockets or queues needed for comms
     */
    Daemon();
    
    /**
     * @brief Destroy the la2 daemon object
     * @todo Should destroy any open sockets or queues.
     */
    ~Daemon();

    /**
     * @todo Calling this should start listening on the socket / queue and 
     *        begin a message-handling loop that does not end until the 
     *        current system is shut down.
     */
    void run();

private:

    /**
     * @brief Handles a new request
     * @todo  Should use the message to create a new request at the end of 
     *         the queued_jobs vector.
     */
    void handle_request();

    std::vector<laa::request> queued_jobs;


};

}

#endif 
