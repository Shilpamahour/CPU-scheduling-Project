# CPU-scheduling-Project
# Description
With the help of this project, users will be able to simulate several CPU scheduling algorithms and assess how well they perform. Numerous well-known scheduling algorithms are implemented, including Round Robin, SJF (Shortest Job First), SRTF (Shortest Remaining Time First), FCFS (First-Come, First-Served), and LJF (Longest Job First).
# how to run
1.Clone the repository: git clone <br>
2.Compile the code: g++ -o scheduler scheduler.cpp<br>
3.Run the executable: ./scheduler input.text output.txt<br>
# working<br>
# Round Robin Scheduling Algorithm:
Round Robin (RR) is a preemptive scheduling algorithm where each process gets executed for a fixed time slice (quantum) in a cyclic order.<br>
1.Arrival: Maintain a ready queue.<br>
2.Execution: Execute each process for a fixed time quantum.<br>
3.Preemption: If the process's quantum expires, move it to the end of the queue.<br>
4.Completion: Calculate waiting time and turnaround time for each process.<br>
5.Output: Output average waiting time and turnaround time.<br>

![image](https://github.com/Shilpamahour/CPU-scheduling-Project/assets/132204996/67e1d107-85a0-48e5-8e46-e5f608c24656)

# explanation<br>
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
#FCFS (First-Come, First-Served)<br>
i)Arrival: Sort processes by arrival time.<br>
ii)Execution: Execute processes in the order they arrive.<br>
iii)Completion: Calculate waiting time and turnaround time for each process.<br>
iv)Output: Output average waiting time and turnaround time.<br>

Function Explanation<br>

1.Sorting Processes:<br>

i)The function begins by sorting the processes based on their arrival times to ensure they are scheduled in the order they arrive.<br>
2.Initializing Variables:<br>

i)A list is created to store the execution order, including start and end times.<br>
ii)The current time is initialized to 0.<br>

3.Scheduling Each Process:<br>

i)For each process, if the current time is less than the process's arrival time, the current time is updated to the process's arrival time (simulating idle CPU time).<br>
ii)The waiting time for each process is calculated as the difference between the current time and the arrival time.<br>
iii)The execution details (process ID, start time, end time) are recorded, and the current time is updated after the process's burst time (execution duration).<br>

4.Calculating Metrics and Writing Results:<br>

i)The function calculates the waiting and turnaround times for each process.<br>
ii)It writes the scheduling results, including the average waiting time, average turnaround time, and a Gantt chart (visual representation of the process execution order), to the output file.<br>

# SRTF (Shortest Remaining Time First)<br>
i)Arrival: Sort processes by arrival time.<br>
ii)Execution: Select the process with the shortest remaining time among the arrived processes.<br>
iii)Preemption: If a shorter job arrives, preempt the current job.<br>
iv)Completion: Calculate waiting time and turnaround time for each process.<br>
v)Output: Output average waiting time and turnaround time.<br>
Function Explanation<br>

1.Initializing Variables:<br>

i)executions is a list to store the execution order with start and end times.<br>
ii)curr tracks the current time in the scheduling simulation.<br>
iii)comp counts the number of completed processes.<br>
iv)n is the total number of processes.<br>
2.Scheduling Each Process:<br>

i)The main loop continues until all processes are completed.<br>
ii)For each time unit, the process with the shortest remaining time that has arrived by the current time is selected.<br>
iii)If no such process is found, the current time is incremented.<br>
iv)The selected process is executed for one time unit, and its remaining time is decremented.<br>
v)Execution details (process ID, start time, end time) are recorded.<br>
vi)If a process completes (remaining time becomes zero), its waiting time is calculated as the difference between the current time (plus one), its arrival time, and its burst time.<br>
vii)The current time is incremented after each time unit of execution.<br>

3.Calculating Metrics and Writing Results:<br>

i)The function calculates the waiting and turnaround times for each process.<br>
ii)It writes the scheduling results, including the average waiting time, average turnaround time, and a Gantt chart (visual representation of the process execution order), to the output file.<br>
