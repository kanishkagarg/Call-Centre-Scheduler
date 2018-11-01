# Call-Centre-Scheduler
It implies Operating System Algorithms to schedule calls in a Call Centre.

Operating System & System Programming Project

CALL CENTER SCHEDULER

About Project :
Our project is about a call center running and organized according to the priority scheduling algorithms. We have a certain number of employees and certain number of customers in a day. Our program manages the customer and employees in a day of a call center. We have arranged our customer list according to their priority ie to according to company they have complain regarding to. Then we have few employees among whom few are in the night shift few in the morning and few in the evening and thus we have ensure that our call centre works 24X7. 
Employees are assigned to the customers according to their availability and free time. We are maintaining a database of employees where the information regarding each employee, which customer the have attended at what time and in what  shift they are working is stored. 
A database for customers is maintained too where information for customers like the amount of time they have to wait before they can be attended, their turn around time, burst time, arrival time etc is stored and displayed.





What does Priority Scheduling mean?
Priority scheduling is a method of scheduling processes based on priority. In this method, the scheduler chooses the tasks to work as per the priority, which is different from other types of scheduling, for example, a simple round robin.
Priority scheduling involves priority assignment to every process, and processes with higher priorities are carried out first, whereas tasks with equal priorities are carried out on a first-come-first-served (FCFS) or round robin basis. An example of a general-priority-scheduling algorithm is the shortest-job-first (SJF) algorithm.

Long Term or job scheduler
 It bring the new process to the ‘Ready State’. It controls Degree of Multi-programming, i.e., number of process present in ready state at any point of time.


2. Short term ot CPU schedule
 It is responsible for selecting one process from ready state for scheduling it on the running state. Note: Short term scheduler only selects the process to schedule it doesn’t load the process on running.
Dispatcher is responsible for loading the selected process by Short Term scheduler on the CPU (Ready to Running State) Context switching is done by dispatcher only. A dispatcher does following:
1) Switching context.
2) Switching to user mode.
3) Jumping to the proper location in the newly loaded program.

A Process Scheduler schedules different processes to be assigned to the CPU based on particular scheduling algorithms. There are six popular process scheduling algorithms which we are going to discuss in this chapter −

First-Come, First-Served (FCFS) Scheduling
Shortest-Job-Next (SJN) Scheduling
Priority Scheduling
Shortest Remaining Time
Round Robin(RR) Scheduling
Multiple-Level Queues Scheduling
These algorithms are either non-preemptive or preemptive. Non-preemptive algorithms are designed so that once a process enters the running state, it cannot be preempted until it completes its allotted time, whereas the preemptive scheduling is based on priority where a scheduler may preempt a low priority running process anytime when a high priority process enters into a ready state.

First Come First Serve (FCFS)
Jobs are executed on first come, first serve basis.
It is a non-preemptive, pre-emptive scheduling algorithm.
Easy to understand and implement.
Its implementation is based on FIFO queue.
Poor in performance as average wait time is high.


Shortest Job Next (SJN)
This is also known as shortest job first, or SJF
This is a non-preemptive, pre-emptive scheduling algorithm.
Best approach to minimize waiting time.
Easy to implement in Batch systems where required CPU time is known in advance.
Impossible to implement in interactive systems where required CPU time is not known.
The processor should know in advance how much time process will take.

Priority Based Scheduling
Priority scheduling is a non-preemptive algorithm and one of the most common scheduling algorithms in batch systems.
Each process is assigned a priority. Process with highest priority is to be executed first and so on.
Processes with same priority are executed on first come first served basis.
Priority can be decided based on memory requirements, time requirements or any other resource requirement.

Shortest Remaining Time
Shortest remaining time (SRT) is the preemptive version of the SJN algorithm.
The processor is allocated to the job closest to completion but it can be preempted by a newer ready job with shorter time to completion.
Impossible to implement in interactive systems where required CPU time is not known.
It is often used in batch environments where short jobs need to give preference.

Round Robin Scheduling
Round Robin is the preemptive process scheduling algorithm.
Each process is provided a fix time to execute, it is called a quantum.
Once a process is executed for a given time period, it is preempted and other process executes for a given time period.
Context switching is used to save states of preempted processes.

Medium term scheduler
 It is responsible for suspending and resuming the process. It mainly does swapping (moving processes from main memory to disk and vice versa).

