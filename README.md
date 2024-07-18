# Round-Robin
Round RObin is a process scheduling algorithm designed for time sharing systems
The Round Robin algorithm is a simple and widely used process scheduling method in operating systems. Here’s how it works in simple terms:

Fair Time Sharing: Round Robin ensures that each process (or task) gets an equal share of the CPU's time. <br>It does this by assigning a fixed time slice, or "quantum," to each process in a circular order.

Process Queue: All processes are placed in a queue. The first process in the queue gets to run for a time slice.<br> If it doesn't finish within this time, it's moved to the back of the queue, and the next process gets its turn.

Cyclic Execution: This cycle continues, with each process getting its fair share of CPU time, preventing any single process from monopolizing the CPU.

Efficiency: The algorithm is simple to implement and ensures that all processes are treated equally,<br>making it ideal for time-sharing systems where multiple users or tasks need to be managed simultaneously.


img<src ="https://imgs.search.brave.com/e7hZpFIrhOQEa5JdB1whauOjOUUmbqjrtvzv8avkPhI/rs:fit:860:0:0:0/g:ce/aHR0cHM6Ly91cGxv/YWQud2lraW1lZGlh/Lm9yZy93aWtpcGVk/aWEvY29tbW9ucy81/LzUwL1JvdW5kUm9i/aW4uanBn">
