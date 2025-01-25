When you want to send a packet with the client network, the method that we use looks something like this:
```cpp
        T x;
        client.reliable_send(client_id, &x, sizeof(T));
```
and then on the receiving end, you have a `const void *data` containing the received packets data, and you can get back your object like this:
```cpp
        std::vector<PacketWithSize> received_packets = network.get_network_events_since_last_tick();
        std::vector<int> received_ids;
        for (const auto &packet : received_packets) {
            const T *received_object = reinterpret_cast<const T *>(packet.data.data());
            ... actually do stuff now
        }
```
Note that the roles of client and server can be swapped, and additionally see the `mwe_packet_handling` to see a more robust way to handle types.
