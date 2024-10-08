# Round-Robin
Round RObin is a process scheduling algorithm designed for time sharing systems
The Round Robin algorithm is a simple and widely used process scheduling method in operating systems. Here’s how it works in simple terms:

Fair Time Sharing: Round Robin ensures that each process (or task) gets an equal share of the CPU's time. <br>It does this by assigning a fixed time slice, or "quantum," to each process in a circular order.

Process Queue: All processes are placed in a queue. The first process in the queue gets to run for a time slice.<br> If it doesn't finish within this time, it's moved to the back of the queue, and the next process gets its turn.

Cyclic Execution: This cycle continues, with each process getting its fair share of CPU time, preventing any single process from monopolizing the CPU.

Efficiency: The algorithm is simple to implement and ensures that all processes are treated equally,<br>making it ideal for time-sharing systems where multiple users or tasks need to be managed simultaneously.


![image](https://github.com/user-attachments/assets/67581a8c-91a8-4d33-aa4c-57ef4ca30cdb)



time complexity -> O(nlogn + n*m);
where n = no of processes
m = no of rounds

space complexity -> o(n)to store the burst time remaining of eacch processes.
