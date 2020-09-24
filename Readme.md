## Authors: Yair Koskas And Shilo Ullman
#Server Side:
Server - the server interface we used to create the servers
ClientHandler - an interface which is used for communicating the client
MySerialServer - a server which accepts one client at a time
>- has a socket for a field, does client communication through a thread
>- open: opens the server and initializes the thread
>- closeServer: closes the server
MyParallelServer - a server which accepts multiple client at a time
>- has a socket for a field, does client communication through a thread pool
>- open: opens the server and initializes the thread pool
>- closeServer: closes the server
MyClientHandler - a client handler which handles the clients input for the graph and algorithm
>- gets the client socket and uses the read() and write() methods for communication
>- handleClient: handles the client input according to the assignment paper

#Algorithm Side
Searchable - an interface for a searchable object, like a graph
Searcher - an interface for a searching class, such as DFS,BFS etc.
State - the current state of the searchable object according to the searcher object
Solution - a class which saves the information of a solution to the searching
Solver - an interface for a problem solver
GraphSolver - an implementation for the Solver interface which focuses on the graph
Algorithms we implemented-DFS,BFS,BestFS,A*
