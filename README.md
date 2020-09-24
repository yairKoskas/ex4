### Authors: Yair Koskas And Shilo Ullman.
## Server Side:

# Server - the server interface we used to create the servers.

# ClientHandler - an interface which is used for communicating the client.

# MySerialServer - a server which accepts one client at a time.

>- has a socket for a field, does client communication through a thread.
>- open: opens the server and initializes the thread.
>- closeServer: closes the server.

# MyParallelServer - a server which accepts multiple client at a time.

>- has a socket for a field, does client communication through a thread pool.
>- open: opens the server and initializes the thread pool.
>- closeServer: closes the server.

# MyClientHandler - a client handler which handles the clients input for the graph and algorithm.

>- gets the client socket and uses the read() and write() methods for communication.
>- handleClient: handles the client input according to the assignment paper.

## Algorithm Side

# Searchable - an interface for a searchable object, like a graph.
>-an interface to things that can be searched (currently only Graph class)

# Searcher - an interface for a searching class, such as DFS,BFS etc.
>- an interface to the algorithmes of find a pass in the graph (BFS, DFS, BestFS, A*).

# State - the current state of the searchable object according to the searcher object.
a state save data of a vertex- uint32_t row, uint32_t col, double cost and a state* cameFrom. 
>- every vertex that the algorithm pass, a state with an information on the vertex is enter to the data structure of the algorithem. thw algorithm uses this information and need him also to and can recover solution.

# Solution - a class which saves the information of a solution to the searching.
>- a Solution have a list of states. the goal of this object is to keep the information about the solution of the algorithm and the pass he made in the graph.

# Solver - an interface for a problem solver.
>- for instance a GraphSolver that know to use an algorithm to find a path in a graph.

# GraphSolver - an implementation for the Solver interface which focuses on the graph.

# Algorithms we implemented-DFS,BFS,BestFS,A*.
