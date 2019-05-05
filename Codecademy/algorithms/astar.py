'''
A*
> Dijkstra not the best when we are just looking for the shortest distance from a single start vertex to a single end vertex

* we shoudln't consider train stations in Canada because it would be inefficient to look in that direction
* modification to Dijkstra

* check the distance up to the current vertex + the estimated distance from the current vertex to the end vertex
=> heuristic

1. add a target for the search
    - clear destination for a heuristic
2. gather possible optimal paths and identifiy a single shortest path
    - find a path that has the shortest distance for the least cost
3. implement a heuristic that determines the likely distance remaining

* greedy algorithm
* introductory example of AI
'''