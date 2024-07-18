# Round-Robin
Round RObin is a process scheduling algorithm designed for time sharing systems
The Round Robin algorithm is a simple and widely used process scheduling method in operating systems. Here’s how it works in simple terms:

Fair Time Sharing: Round Robin ensures that each process (or task) gets an equal share of the CPU's time. <br><\t>It does this by assigning a fixed time slice, or "quantum," to each process in a circular order.

Process Queue: All processes are placed in a queue. The first process in the queue gets to run for a time slice.<br><\t> If it doesn't finish within this time, it's moved to the back of the queue, and the next process gets its turn.

Cyclic Execution: This cycle continues, with each process getting its fair share of CPU time, preventing any single process from monopolizing the CPU.

Efficiency: The algorithm is simple to implement and ensures that all processes are treated equally,<br><\t> making it ideal for time-sharing systems where multiple users or tasks need to be managed simultaneously.
