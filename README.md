# Vertex Coloring

The approach that consists of painting adjacent vertices in a traversal
in width, assigning valid cores 'R' or 'B'. It is correct because for every
analyzed vertex, the crossing in width visits and applies the same operation to
each vertex can be reached from the starting vertex. This approach ensures that
adjacent vertices are painted consistently, allowing a
proper coloring of the graph. Width crossing is a suitable choice
for this task, as it explores the vertices gradually and efficiently.
