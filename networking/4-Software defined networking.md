# Planes
Data plane contains all activities involving the forwarding of packets. The control plane involves activities necessary to perform data plane's ones without user data, like routing tables and packet handling policies

## Paradigm
- separate data plane and control plane
	- single centralized control plane managing different data planes
	- Allowes for one expensive controller and plenty cheap switches

# Architecture
Three separated levels: applications, network OS and hardware, interfaced by the network control API and the HW open interface

The Network OS is responsible for mapping high level commands into low level HW configuration

# SDN
Separation on the forwarding plane from the network control plane, which is now able to manage several devices
SDN grants different properies like:
- virtualization and programmability
- Orchestration, automation 
- dynamic scaling and multi tenancy
- visibility, performance and openness


## OpenFlow
- stores packets headers and relative actions, in a way to respond to matches
- idle and hard timeouts for autoremoving rules
- in_port to send back to transmitter

> [!info] table insertion methods
	> proactive insertion is done by the controller before packets arrive, meanwhile reactive insertion happens when a packet doesn't trigger any policy, so the hardware sends it to the controller expecting a new policy in return

## Messages
- Hello: used during connection setup for version negotiation
- echoreq/echores: ?
- PacketIn: sends a captured packet to the controller
- PacketOut: injection done by the controller
- FlowMod: modifies the status of an OpenFlow switch

# Mininet
- network emulator
- manages vHost and vSwitches inside network namespaces managed by the kernel 