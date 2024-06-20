# CPU-scheduling-Project
# Description
With the help of this project, users will be able to simulate several CPU scheduling algorithms and assess how well they perform. Numerous well-known scheduling algorithms are implemented, including Round Robin, SJF (Shortest Job First), SRTF (Shortest Remaining Time First), FCFS (First-Come, First-Served), and LJF (Longest Job First).
# how to run
1.Clone the repository: git clone 
2.Compile the code: g++ -o scheduler scheduler.cpp
3.Run the executable: ./scheduler input.text output.txt
#working
#Round Robin Scheduling Algorithm:
Round Robin (RR) is a preemptive scheduling algorithm where each process gets executed for a fixed time slice (quantum) in a cyclic order.
1.Arrival: Maintain a ready queue.
2.Execution: Execute each process for a fixed time quantum.
3.Preemption: If the process's quantum expires, move it to the end of the queue.
4.Completion: Calculate waiting time and turnaround time for each process.
5.Output: Output average waiting time and turnaround time.

![image](https://github.com/Shilpamahour/CPU-scheduling-Project/assets/132204996/67e1d107-85a0-48e5-8e46-e5f608c24656)
#explanation
1.Initialization:

i)Read the processes and their attributes (PID, burst time, arrival time).
ii)Initialize the remaining burst time for each process.
iii)Use a queue to maintain the ready queue of processes.
2.Queue Maintenance:

i)Add processes to the ready queue as they arrive.
ii)After executing a process for the given quantum, if it still has remaining burst time, add it back to the ready queue.
3.Execution Loop:

i)Continuously check the ready queue and execute processes for a fixed time slice (quantum).
ii)If a process finishes within the time slice, remove it from the ready queue.
iii)If the ready queue is empty, move to the next time unit until new processes arrive.
4.Calculate Waiting and Turnaround Times:

i)After all processes are executed, calculate the waiting time and turnaround time for each process.
ii)Waiting time = Total time spent in the ready queue (excluding burst time).
iii)Turnaround time = Waiting time + Burst time.



