#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure to represent a network packet
typedef struct {
    char sourceIP[16]; // Source IP address
    char destIP[16];   // Destination IP address
    int sourcePort;    // Source port
    int destPort;      // Destination port
    bool allowed;      // Whether the packet is allowed or not
} Packet;

// Function to simulate packet filtering based on firewall rules
void firewallFilter(Packet packet) {
    // Define firewall rules
    char allowedDestIP[16] = "192.168.1.100"; // Example allowed destination IP
    int allowedDestPort = 80;                  // Example allowed destination port

    // Check if the packet matches the firewall rules
    if (strcmp(packet.destIP, allowedDestIP) == 0 && packet.destPort == allowedDestPort) {
        packet.allowed = true; // Packet is allowed
    } else {
        packet.allowed = false; // Packet is not allowed
    }

    // Print the result
    printf("Packet from %s:%d to %s:%d is %s\n", packet.sourceIP, packet.sourcePort,
           packet.destIP, packet.destPort, packet.allowed ? "allowed" : "blocked");
}

int main() {
    // Create a sample packet
    Packet packet;
    strcpy(packet.sourceIP, "192.168.1.50");
    strcpy(packet.destIP, "192.168.1.100");
    packet.sourcePort = 12345;
    packet.destPort = 80;

    // Simulate packet filtering using firewall
    firewallFilter(packet);
    printf("\n\n");

    return 0;
}