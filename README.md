When you want to send a packet with the client network, the method that we use looks something like this:
```cpp
        T x;
        client.reliable_send(client_id, &x, sizeof(T));
```
and then on the receiving end, you have a `const void *data` containing the received packets data, and you can get back your object like this:
```cpp
        const T* x = reinterpret_cast<const PacketHeader*>(data);
```
Note that the roles of client and server can be swapped, and additionally see the `mwe_packet_handling` to see a more robust way to handle types.
