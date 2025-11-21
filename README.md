# Tower-of-Hanoi
Tower of Hanoi
The Tower of Hanoi is a classic mathematical puzzle and recursion problem. It consists of three rods (or pegs) and a number of disks of different sizes that can slide onto any rod. The puzzle starts with all disks stacked in ascending order of size on one rod, the smallest at the top, forming a conical shape.
🎯 Objective
Move the entire stack of disks from the source rod to the destination rod, following these rules:
- Only one disk can be moved at a time.
- Each move consists of taking the top disk from one rod and placing it on top of another rod.
- No disk may be placed on top of a smaller disk.
 Recursive Insight
The Tower of Hanoi is often used to teach recursion:
- To move n disks:
- Move n-1 disks from the source rod to the auxiliary rod.
- Move the largest disk directly to the destination rod.
- Move the n-1 disks from the auxiliary rod to the destination rod.
The minimum number of moves required is:
M(n)=2^n-1
where n is the number of disks.
