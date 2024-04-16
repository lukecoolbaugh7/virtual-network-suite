# Virtual Network Suite

This project provides a lightweight implementation of virtual network interfaces and switches using Python and C. It is designed to handle Ethernet frames over UDP connections, enabling easy management and routing of network traffic between virtual ports and a central virtual switch.

## Features

- **Virtual Switch (VSwitch)**: Implemented in Python, it handles incoming Ethernet frames, manages a MAC address table, and routes the traffic accordingly.
- **Virtual Port (VPort)**: A C implementation that connects to the VSwitch, manages Ethernet frames between the network stack and the VSwitch.
- **Efficient Ethernet Frame Handling**: Supports broadcasting and specific frame forwarding based on MAC address resolution.

## Getting Started

### Prerequisites

- Python 3.x
- GCC compiler
- pthread library for threading support

## Installation

**Build by typing `make` in the command line**

## Deployment

### 1. Run VSwitch

- On the server with public IP:
`python3 vswitch.py ${SERVER_PORT}`

### 2. Run and Configure VPort on Client-1

- Run Vport
`sudo ./vport ${SERVER_IP} ${SERVER_PORT}`

- Configure TAP device
`sudo ip addr add 101.1.101/24 dev tapyuan`
`sudo ip link set tapyuan up`

### 3. Run and Configure VPort on Client-2

- Run VPort
`sudo ./vport ${SERVER_IP} ${SERVER_PORT}`

- Configure TAP device
`sudo ip addr add 10.1.1.102/24 dev tapyuan`
`sudo ip link set tapyuan up`

### 4. Ping Connectivity Test

- Ping client-2 from client-1
`ping 10.1.1.102`

- Ping client-1 from client-2
`ping 10.1.1.101`
