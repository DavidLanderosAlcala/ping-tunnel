# Ping-Tunnel
C++ [ICMP tunnel](https://en.wikipedia.org/wiki/ICMP_tunnel) implementation

This tool is based on [ptunnel](https://www.mit.edu/afs.new/sipb/user/golem/tmp/ptunnel-0.61.orig/web/), it allows you to reliably tunnel TCP connections to a remote host using ICMP echo request and reply packets, commonly known as ping requests and replies

such feature can be used to bypass TCP filters

in contrast with ptunnel, this tool supports multiple tunnels forwarded to different destinations at the same time.

## Supported platforms
- Windows
- Linux

## Usage
#### As Proxy:
create a file called **ping-tunnel.json** with the following content:
```json
{
    "run_as_proxy"      : true,
    "network_interface" : "eth0",
}
```
Replace the field *network_interface* with the interface you want the proxy to listen for pings.  
In the same folder run the program ```./ping-tunnel``` (you need to run it as root/administrator)

#### As forwarder:
create a file called **ping-tunnel.json** with a content like this:
```json
{
    "run_as_proxy"      : false,
    "proxy_address"     : "192.168.0.9",
    "network_interface" : "eth0",
    "port_mappings" : [
        {
            "__comments"          : "SMTP server",
            "local_port"          : 25,
            "destination_port"    : 25,
            "destination_address" : "otherserver.com"
        },
        {
            "__comments"          : "IMAP server",
            "local_port"          : 143,
            "destination_port"    : 143,
            "destination_address" : "otherserver.com"
        },
        {
            "__comments"          : "Mysql server",
            "local_port"          : 3306,
            "destination_port"    : 3306,
            "destination_address" : "192.168.0.9"
        }
    ]
}
```
Replace the field *network_interface* with the interface you want the forwarder to listen for pings.  
In the same folder run the program ```./ping-tunnel``` (you need to run it as root/administrator)

Once you have both facets up and running, you can use your forwarder address/ports as if they were your destination address/port, since the TCP conections will be forwarded

## Compilation
#### Windows
For Windows you can use the Visual Studio 2019 project located at ```/win/vs2019```

#### Linux
install dependencies
```
sudo apt install libpcap-dev
```
and compile
```
make
```

## License
MIT

## Credits
This project uses:
- [json](https://github.com/nlohmann/json) JSON library for Modern C++
- [popl](https://github.com/badaix/popl) Program options parser library
- [npcap](https://nmap.org/npcap/) Packet sniffing library for Windows 10

## Author
David Landeros <dh.landeros08@gmail.com>
