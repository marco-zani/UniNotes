# Data center networks
**High performance communication is essential** for cloud computing


#### Internet networks
The relation between networks can be of 3 types:
- **Peering**: **free exchange** between networks, this relation is used in Tier 1 networks
- **Transit**: a **network pays another to access internet**, used in Tier 2 networks
- **Customer**: a **network is paid to access internet**, used in Tier 3 networks

**IXP** are also used in networking to **exchange traffic between ISPs**

More modern services, like data streaming or cloud compiting services, have reshaped the network by **increasing the importance of the last mile** and his need to higher bandwidths

Now **datacenters** are **more distributed** to provide **services closer** and with **lower latency** to the end-user 

## Datacenters 
Their huge scales **require high bandwidth, low round trip time, limited geograpic scope and** use **planned topologies with omogenic hardware**

For easy administration, is used a **single administrative domain** with **full controll** over **network, endpoints and traffic flow**

For managing a datacenter, analizing the **data flow** is essential, both internal and external. Remember that machine-to-machine communication fills the majority of data flow

#### Costs
The main cost in datacenters is represented by **servers**, followed by **power infrastructure and netwoking costs**. 

When buying servers the **uncertainty of demand**, **long provisioning** timescales and **risk of underprovisioning** must be taken in consideration

**Networking costs** differ in **hardware and cables**. Is **important to implement** an innovative **router architecture** to optimize communications. 
Router also divide in **low-radix routers**, with a low **amount of highbandwidth ports**, and **high-radix router**, the opposite

## Interconnection networks
A network is composed by links and nodes, which are end hosts and switches. An **interconnection network** can be defined **blocking** or not if **not all permutation of sources and destination can be connected at any time**

This types of networks are **defined by**:
- **Topology**
- **Routing**
- **Flow control**

## Topology
It defines the average distance between nodes (or **network diameter**). The basic types are bus, hypercube, 2D mesh and 2D torus. All these networks are deprecated thanks to **switched networks** in an **Omega structure**

In a datacenter, **servers must be** more **uniform** as possible for easier management. This is called **location transparency**.

Data centers are also organized in layers: 
- **Core layer**, which interfaces with the internet
- **Aggregation layer**, divides layer 2 and layer 3 hardware
- **Edge layer**, where all pods are situated
- **pods**

The difference in using layer 2 or layer 3 communication stands in the **configuration complexity** and **structure scalability**

We have topologies of different kinds and working on different levels. 
**Butterfly networks** are a **blocking** type of network denoted by a **pattern of inverted triangles**. They **transfer data through the most efficient route**.
Clos networks are like a double butterfly network but with different communications direction. This allowes for a non blocking network, but at cost of latency because packets must overshoot their destination

#### Fat trees
Lastly we have fat trees, or networks with input and output sharing the same switches. The architecture is organized with **servers as leaves** and **switches as root** and internal nodes

#### Fat tree DCNs
The design principles are that the **network must be scalable**, with multiple core switches and should **support multi-path routing**

It's organized in **pods**, with **half the number of switches FOR EACH LAYER**, connected to the **half the number of servers**.

The ip addresses are organized in **_public.pod.switch.server_**, sorted left to right, bottom to top 

## Balancing workloads
**managing mice flows** (small and numerous) **and elephant flows** (large and rare) requires specific solutions

The **Hedera** solution collects information from switches and **if an elephant flow is detected computes an ad hoc path**, for all the **other flows** it **uses ECMP** (Equal-Cost Multi-Path routing)

other solutions are **CONGA** (based on **link utilization**), **DRILL** (**switch queue occupancy**),  or Per-packet Load-balanced, Low-Latency Routing for Clos-based Data Center  Networks (**spreads all packets uniformly**)

## Summary
- In designing a datacenter, **interconnection networks** are essential for providing an **efficient architecture** to applications and services
- It is used a **Layered structure** (edge, aggregation and core) with the most relevant topology being **fat tree**
- modern researches focus on obtaining **low latency**, **high throughput** and **high burst tolerance**

# Single server: basic services
**Virtualization adds complexity** in networking, it **requires internal traffic delivery beetween VMs and external delivery to the physical network**. Every VMs needs an IP address, plus network balancing, firewalls and other services

## Switching
#### Host based switching
It **uses software switch** (also known as softswtich or software bridge) for switching, which **can be inside the host OS or the Hypervisor**

This methods allowes **High bandwidth for inter-VM** traffic and **policies can be enforced earlier**. This is at the **cost of additional processing overhead** and a new component to **configure and monitor**

Thanks to the possibility to implement hardware switches features and using the same commands, **vSwitches can work as a native piece of the infrastructure** and **offload the weight** onto the effective hardware. 
Some examples are VMware vSwitch, Cisco Nexus 1000V and open vSwitch

vSwitches **require** the NIC to operate in **promiscuous mode**

#### Hairpin switching
Thanks to compatible hardware, the **frames make a U-turn after reaching** the first **physical switch**.

This way is the **hardware** which does a **more efficient switching** (thanks to **specialized components**) but makes the traffic cross twice the intermediate components, so is **not recommended on high VM-to-VM traffic**

This method is **deprecated**

#### NIC switching
Is the intermediate solution, and it **takes advantage of specialized hardware** called **SmartNICs**, which are Intelligent Server Adapters (ISA)

**SmartNICs can implement complex server-based functions** and can work indipendelty to the OS

They are used because **they offload the cpu** in favour of the processing unit on the SmartNIC. This is **more effective with consuming protocols like** vlan **tunneling**, complex functions like **load balancing** and can help mitigate DDoS attacks

### Summary
**hardware switches** are more suited for **networks with little VM-to-VM traffic**, meanwhile **host switches** are more **flexible** at the cost of CPU cycles.  This makes **host switches** the most **common solution**

# Software bridges in linux
Software bridges are used to **provide intra-host connectivity** and **handle IP addresses differently from the official model**

**Linux allowes to create** a bridge across interfaces and **an unique virtual interface** valid for the entire host

The main linux software bridges are:
- Linuxbridge
- macvlan
- Open vSwitch

#### Linuxbridge
The most common and simple software bridge, it **behaves like a traditional hardware switch**. It uses the NIC in promiscuous mode. It uses for traffic both interfaces, which are reachable with the same IP address

#### macvlan
Uses a **Vlan** like behavior **using MAC addresses instead of tags**. Behaves like a **sub interface** of the NIC, which is then **binded to applications**.
It also allowes the NIC to filter packets based on MAC addresses

The operating modes are: private, VEPA (default), bridge and pass-through. 

The **private mode blocks inter-macvlan traffic** and allowes traffic comming only from a different MAC address. In **VEPA mode, blocks intra-host traffic** and in **bridge mode allowes all type of traffic**.
Lastly, **passthrough mode** is used only for **one macvlan device** but allowes it to **use any MAC address**, avoiding also MAC filtering

#### Bridge vs macvlan
**macvlan is simpler, faster**, uses less CPU and avoids the need of ARP (it already knows all MAC addresses). **Bridge** instead **is recommended for complex topologies**, presence of multiple VMs talking to each other on the same host or if advanced switch features are needed

#### Open vSwitch
OVS works as a **virtual multilayer switch** capable of network automation through **extensions**. It **supports advanced management interfaces and protocols** which also **allowes the creation of cross-server switches**.
It can work both as a softSwitch and as a **control stack for HW switches**

it's ported for multiple platforms and integrated into kernels and virtualization management systems like OpenStack

# Single server: complex services
### IP address assignment
To provide IP addresses can be used **direct routing**, or using the same **addresses of the physical network**. 
The **second option** is use private addresses and access the network through **NAT**. This option is more elastic but might complicate the network scheme

### Feature-rich network connectivity
To provide for private addresses, the **hypervisor must also provide router, NAT and DHCP services**.  To accomplish this, we can **leverage the linux kernel or** use **additional containers**

### Multi-tenancy
To provide strong network isolation, like preventing IP address conflicts, **multiple vSwitches** and **vRouters** are used

### Tenant-defined network services
To **provide complex topologies to the client** (like **DMZ** and isolated networks in the same server) we implement **cloud controllers** (ex: OpenStack), which provide pre-defined services for networking and security

### Co-existence of virtual services and host applications
To **disinguish traffic towards VMs or the host**, the linux kernel networking has **evolved, allowing the kernel to support virtual networks** and to **invoke the IP Stack** 

An example of forwarding a package to the Internet

![[ForwardingToTheInternet.png]]


# Datacenter wide services
The challenge in data centers is to provide the same services of a single server but "at scale"

#### Tenant view
The user doesn't need to know the physical infrastructure, only the logical arrangement. But making coincide the logical and physical view can be difficult for the cloud manager, all more when trying to optimize the physical architecture

#### Providing L2 connectivity
**To provide a logical L2 network spanning beetween servers, the traffic is tunneled**

![[tunnelingBetweenServers.png]]

Vlans could't substitute tunneling because they are limited to layer 2 and can't communicate with servers in other networks

#### Providing L3 connectivity
In a layer 3 case, we have more elasticity for managing clusters of servers and we can use two solutions: Tunneling and direct routing

Tunneling
![[L3Tunneling.png]]

Direct routing
![[L3DirectRouting.png]]

Because **point-to-point tunnels do not scale**, tunneling tecnologies are required to manage a full mesh. **VxLAN** is one of this technologies which **offers full-mesh solutions** for all the hosts in the same VxLAN, and **frames wrapped in UDP** segments, allowing traffic to flow through **parallel links**

#### Overlay vs Direct routing
The main difference is the **necessity to interact with the infrastructure**. The **overlay model may reduce the performance** on the network, meanwhile the **direct routing requires collaboration with the infrastructure** provider. 
Overlay is preferred with OpenStack, and direct routing with Kubernetes

NB: The overlay model allowes the virtual network to be indipendent from the physical topology

## Summary
The **challenges** of virtual networking are the **implementation of the different models** and **mixing virtual and real networking**. Another detail is that virtual networks rarely fail, but when it happens debbugging might be challenging


Next -> [[5-Cloud storage]]