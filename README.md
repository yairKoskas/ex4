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

# SearchAlgorithm - an interface for a search Algorithm
>-an interface to an algorithm which uses a data structure for seaching, like dfs,bfs

# Node - a Node in the Graph
saves index's of row,column,src row and column,weight and distance (for the A* heuristic) 
>- every vertex that the algorithm pass, a state with an information on the vertex is enter to the data structure of the algorithem. thw algorithm uses this information and need him also to and can recover solution.

# Graph - a Graph
implemented using a vector of vectors of nodes

# Algorithms we implemented-DFS,BFS,BestFS,A*.
