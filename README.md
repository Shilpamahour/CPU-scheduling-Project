# CPU-scheduling-Project
# Description
With the help of this project, users will be able to simulate several CPU scheduling algorithms and assess how well they perform. Numerous well-known scheduling algorithms are implemented, including Round Robin, SJF (Shortest Job First), SRTF (Shortest Remaining Time First), FCFS (First-Come, First-Served), and LJF (Longest Job First).
# how to run
1.Clone the repository: git clone <br>
2.Compile the code: g++ -o scheduler scheduler.cpp<br>
3.Run the executable: ./scheduler input.text output.txt<br>
#working<br>
#Round Robin Scheduling Algorithm:
Round Robin (RR) is a preemptive scheduling algorithm where each process gets executed for a fixed time slice (quantum) in a cyclic order.<br>
1.Arrival: Maintain a ready queue.<br>
2.Execution: Execute each process for a fixed time quantum.<br>
3.Preemption: If the process's quantum expires, move it to the end of the queue.<br>
4.Completion: Calculate waiting time and turnaround time for each process.<br>
5.Output: Output average waiting time and turnaround time.<br>

![image](https://github.com/Shilpamahour/CPU-scheduling-Project/assets/132204996/67e1d107-85a0-48e5-8e46-e5f608c24656)
#explanation<br>
1.Initialization:<br>

i)Read the processes and their attributes (PID, burst time, arrival time).<br>
ii)Initialize the remaining burst time for each process.<br>
iii)Use a queue to maintain the ready queue of processes.<br>
2.Queue Maintenance:<br>

i)Add processes to the ready queue as they arrive.<br>
ii)After executing a process for the given quantum, if it still has remaining burst time, add it back to the ready queue.<br>
3.Execution Loop:<br>

i)Continuously check the ready queue and execute processes for a fixed time slice (quantum).<br>
ii)If a process finishes within the time slice, remove it from the ready queue.<br>
iii)If the ready queue is empty, move to the next time unit until new processes arrive.<br>
4.Calculate Waiting and Turnaround Times:<br>

i)After all processes are executed, calculate the waiting time and turnaround time for each process.<br>
ii)Waiting time = Total time spent in the ready queue (excluding burst time).<br>
iii)Turnaround time = Waiting time + Burst time.<br>



