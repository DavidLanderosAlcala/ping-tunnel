#pragma once
#include <stdint.h>

#if !defined(PACKED)
#ifdef __GNUC__
#define PACKED __attribute__((__packed__))
#else
#define PACKED /* nothing */
#endif
#endif

#define ETHERNET_ADDRESS_LENGTH 6
#define ETHERTYPE_IP 0x0800

#define ICMP_ECHOREPLY 0
#define ICMP_ECHO 8
#define ICMP_PAYLOAD_MAX_SIZE 2048

extern "C" {
#pragma pack(push, 1)
struct ethernet_header_t {
    uint8_t destination_host[ETHERNET_ADDRESS_LENGTH];
    uint8_t source_host[ETHERNET_ADDRESS_LENGTH];
    uint16_t ether_type;
} PACKED;

struct ip_header_t {
    uint8_t ip_verlen;       // 4-bit IPv4 version 4-bit header length (in 32-bit words)
    uint8_t ip_tos;          // IP type of service
    uint16_t ip_totallength; // Total length
    uint16_t ip_id;          // Unique identifier
    uint16_t ip_offset;      // Fragment offset field
    uint8_t ip_ttl;          // Time to live
    uint8_t ip_protocol;     // Protocol(TCP,UDP etc)
    uint16_t ip_checksum;    // IP checksum
    uint32_t ip_srcaddr;     // Source address
    uint32_t ip_destaddr;    // Source address
} PACKED;

struct icmp_packet_t {
    struct {
        uint8_t type;
        uint8_t code;
        uint16_t checksum;
        uint16_t id;
        uint16_t sequence;
    } header;
    uint8_t payload[ICMP_PAYLOAD_MAX_SIZE];
} PACKED;

#pragma pack(pop)
}