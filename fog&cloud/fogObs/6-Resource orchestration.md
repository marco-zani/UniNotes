The challenge with resource allocation is to **provide resources** to *n* activities **in the most efficient way possible**

# NP shit I don't have time to study

# Approximation 

Approximation algorithms:
- Approximation guarantees  
- Approximation proof  
- General case  
- Efficient

Heuristics  
- No approximation guarantees  
- Experimental proof of approximation  
- Specific case (most of the time)

# Resource allocation in cloud
Becouse energy consumption is one of the highest operational cost for a datacenter,
the objective is to **minimize the energy cost**, which translates to **minimizing** the number of **active servers**

#### Static allocation
By assuming that the workloads patterns are know, we can approach the issue in two ways:
- **Mathematical programming**: Uses mathematical formalization to efficiently obtain the problem solution. The issue is that is not scalable and is useless for NP-hard problems
- Approximation

#### Dynamic allocation
It's used a controller to respond to over/under-load at runtime and reallocates resources thanks to **live migration**

Live migration corresponds to the **movement of VMs** from one physical machine to the other **without service disruption**. This is done by minimizing downtime and the number of Service Level Agreement violations

A migration is triggerd when server utilization exceeds or falls under a certain threshold. The condition of a server is monitored in seconds intervals and data sent to a buffer. Then, a control process, checks every 5 minutes if there is an overload or underload situation. If detected, it migrates to other servers selected by their volume.
This mechanism is called **reactive control**

An extension of reactive control is **proactive control** which, for **avoiding unnecessary migrations**, tries to **forecasts** if the server's usage anomaly could continue or is unforseen spike. It uses double exponential smoothing on data collected at one minute intervals to forecast the server usage

#### Dynamic vs Static
The best solution is to combine the two mechanism, applying static allocation for long term allocations and dynamic to manage workload peaks


# Resource allocation in the Fog
Working in the cloud has various challenges:
- high latency
- high cost
- privacy issues
- network congestions

But Fog computing aims to solver the issues by moving the computation closer to the source

When allocating resources in the fog, the balance must be achieved between resource utilization and application requirements. In addition to the Static and dynamic approaches, we must count two players, the infrastructure owner (which aims to maximize revenue) and the application owner (which aims to minimize deployment cost)


