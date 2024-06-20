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


![image](https://github.com/Shilpamahour/CPU-scheduling-Project/assets/132204996/fbf3ecfd-e096-46da-a275-797a8aa7e0f3)


