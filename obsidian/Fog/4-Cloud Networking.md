# Data center networks
High performance communication is essential for cloud computing


#### Internet networks
The relation between networks can be of 3 types:
- Peering: free exchange between networks, this relation is used in Tier 1 networks
- Transit: a network pays another to access internet, used in Tier 2 networks
- Customer: a network is paid to access internet, used in Tier 3 networks

IXP are also used in networking to exchange traffic between ISPs

More modern services, like data streaming or cloud compiting services, have reshaped the network by increasing the importance of the **last mile** and his need to higher bandwidths

Now datacenters are more distributed to provide services closer and with lower latency to the end-user 

## Datacenters 
Their huge scales require high bandwidth, low round trip time, limited geograpic scope and use planned topologies with omogenic hardware

For easy administration, is used a **single administrative domain** with **full controll** over network, endpoints and traffic flow

For managing a datacenter, analizing the **data flow** is essential, both internal and external. Remember that machine-to-machine communication fills the majority of data flow

#### Costs
The main cost in datacenters is represented by servers, followed by power infrastructure and netwoking costs. 

When buying servers the uncertainty of demand, log provisioning timescales and risk of underprovisioning must be taken in consideration

Networking costs differ in hardware and cables. Is important to implement an innovative router architecture to optimize communications. 
Router also divide in **low-radix routers**, with a low amount of highbandwidth ports, and **high-radix router**, the opposite

## Interconnection networks
A network is composed by links and nodes, which are end hosts and switches. An interconnection network can be defined **blocking** or not if not all permutation of sources and destination can be connected at any time

This types of networks are defined by:
- Topology
- Routing
- Flow control

## Topology
It defines the average distance between nodes (or **network diameter**). The basic types are bus, hypercube, 2D mesh and 2D torus. All these networks are deprecated thanks to **switched networks** in an **Omega structure**

In a datacenter, servers must be more uniform as possible for easier management. This is called **location transparency**.

Data centers are also organized in layers: 
- Core layer, which interfaces with the internet
- Aggregation layer, divides layer 2 and layer 3 hardware
- Edge layer, where all pods are situated
- pods

The difference in using layer 2 or layer 3 communication stands in the **configuration complexity** and **structure scalability**

We have topologies of different kinds and working on different levels. 
**Butterfly networks** are a blocking type of network denoted by a pattern of inverted triangles. They transfer data through the most efficient route
Clos networks are like a double butterfly network but with different communications direction. This allowes for a non blocking network, but at cost of latency because packets must overshoot their destination



# Networking in virtualized environments

## Single server

#### Host based switching

#### Hairpin switching

#### NIC switching


# Software bridges in linux


# Single server: complex services

## IP address assignment

## Multi-tenancy

# Datacenter wide services