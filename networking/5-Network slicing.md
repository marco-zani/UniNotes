Allows for multiple logical networks on the same physical infrastructure. It also offers the possibility to define dedicated, flexible and on-demand resources based on the network slice

# LifeCycle
1. Preparation, design and templating
	1. design, pre-provision and network environment preparation
2. Activation
	1. instatiation and configuration
3. Monitoring
	1. supervision, reporting and modification
4. Deactivation and termination

This is performed at high level by the use of network functions, and at infrastructure level through virtualization. Both are managed by an orchestrator

# Architecture
The principal components are:
- the network slices
- The virtualized infrastructure platform
	- it contains physical and virtualized resources divided through a virtualization layer
- Management and orchestration (MANO)
The mano is the most important component, as it contains:
- the Virtual Network Function Manager (VNFM), the interface for network slices
- the Virtual Infrastructure Manager (VIM), which interfaces the VIP
- The SDN and NFV Orchestrators

The SDN controller can be organized in different ways depending on the use case:
- With the VIM (Generic architecture), allowing for better control of the networking softwarization 
- On both the VIM and the SDN Orchestrator (single owner, single controller). This gives to the controller the most capabilities to manage both the virtual infrastructure and the  slices. This requires that only one owner company manages the entire infrastructure
- multiple controller in the SDN Orchestrator (single owner, multiple tenants), each one managing a single slice. This requires an SND proxy to manage request from both controller towards the virtual infrastructure. 

# FlowVisor
Uses OpenFlow as hardware abstraction layer, which means that openFlow works as middleman so that different openflow controller connect to flowvisor thinking they are connecting to openflow switches.

## Concept
FV intercepts OF messages from guest controller, applies the related slicing policy and forwards it to the network. It also intercept OF switches to send back to the correct OF controller