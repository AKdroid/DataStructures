#! /usr/bin/env python

"""
Code to compute the shortest path using Dijkistra's algorithm
The slower one without using a heap
O(mn)
"""

def parse_graph(filename):
  data=open(filename,"r");
  graph=[];
  for line in data.readlines():
    row=line.split();
    row[0]=int(row[0]);
    for x in range(1,len(row)):
      y=row[x].split(',');
      row[x]=(int(y[0]),int(y[1]));
      
    graph.append(row);
  return graph;
        
def dijkstra_shortcut(graph,source):
  size=len(graph);
  checked=[0]*size;
  distances=[10000000]*size;
  distances[source-1]=0;
  
  while(checked.count(0)>0):
    minval=10000000;
    for i in range(0,size):
      if(checked[i]==0 and minval>distances[i]):
	vertex=i+1;
	minval=distances[i];
    for destination in graph[vertex-1][1:]:
      dest_vertex=destination[0];
      dest_distance=destination[1];
      if(distances[vertex-1]+dest_distance<distances[dest_vertex-1] and checked[dest_vertex-1]==0): 
	distances[dest_vertex-1]=distances[vertex-1]+dest_distance;
    else:
      checked[vertex-1]=1;
  return distances;   
if(__name__ == "__main__"):
  graph1=parse_graph("dijData.txt");
  paths=dijkstra_shortcut(graph1,1);
  
  required=[7,37,59,82,99,115,133,165,188,197];
  for x in required:
    print paths[x-1],",",;
  