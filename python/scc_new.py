#! /usr/bin/env python
# -*- coding: iso-8859-1 -*-

nx=875714  		# number of vertices in the original graph 69.3MB  text file.
nx=13 			# testcase size.
graphmarks=[0]*nx; 	# a global matrix to keep track of vertices traversed
finishing_time=[];	# finishing_time is the order i.e. stack after complete traversing the graph by DFS 
stack=[];		# A list representing the function call stack. pyhton recursion stack not enough.  
sizes=[];		# the final list to store the size of SCC's


"""
Implement the Kosaraju's algorithm to compute the SCCs present in a graph.
Algorithm -- 
1) Traverse the graph with reversed edges using DFS in decreasing order of vertex number
2) Store the order in which edges were traversed like a stack in a list
3) Traverse the graph with proper edges using DFS starting from the last entry in the above list.
4) Every time the subroutine i.e DFS routines corresponds to a SCC. 

Finishing time

O(m+n) => m =  no.of edges and n= no. of vertices

"""

def initialize():	#initialize the graph to untraversed
    global graphmarks;
    graphmarks=[0]*nx;

def parse_graph(filename,reverse):
    """
    This function creates a row adjacency list of graph from directed edges information
    Usage: parse_graph("name_of_the_file.txt",boolean reverse)
    returns a graph
    """
    graph=[];
    for i in range (0,nx):
      graph.append([]);
    inputfile=open(filename,"r");
    for line in inputfile.readlines():
      row=line.split();
      row[0]=int (row[0])
      row[1]=int (row[1])
      if(reverse):
	graph[row[1]-1].append(row[0]);
      else:
	graph[row[0]-1].append(row[1]);
    inputfile.close();
    return graph;

def DFS_start(graph,flag):	#Start the DFS search,each run will result in a single SCC
  global graphmarks;
  global finishing_time;
  global stack
  global sizes;
  initialize();
  if(flag):
    for x in range(len(graph),0,-1):
      if(graphmarks[x-1]==0):
	DFS(graph,x,flag);
  else:
    for x in finishing_time:
      if(graphmarks[x-1]==0):
#	print "dfs",len(finishing_time)
	DFS(graph,x,flag);
  
def DFS(graph_dir,vertex,flag):	#Actual DFS traversal
  global graphmarks;
  global finishing_time;
  global stack
  global sizes;
  cnt=0;
  graphmarks[vertex-1]=1;
  stack.append(vertex);
  number=vertex;
  while(True):
    for x in graph_dir[number-1]:
      if(len(graph_dir[number-1])==0):
	break;
      if(graphmarks[x-1]==0):
	graphmarks[x-1]=1;
	stack.append(x);	#push the vertex to stack and traverse the edges of x
	number=x;
	break;
    else:
      if(len(stack)==0):
	break;	  
      num=stack.pop();
      if(flag):
	finishing_time.append(num);	#store the order of traversal in stack
      else:
#	finishing_time.remove(num);
	cnt=cnt+1;
      if(len(stack)!=0):		# count the size of SCC and store in reverse traversal i.e second pass
         number=stack[len(stack)-1];
  if(not flag):
	sizes.append(cnt);    
#  print "exited"	
   	  
if(__name__=="__main__"):
  graph1=parse_graph("testcase.txt",True);  	#parse the graph in reverse order   - row adjacency list
  graph2=parse_graph("testcase.txt",False); 	#parse the grpah in straight order  - row adjacency list
  DFS_start(graph1,True);		    	#first pass	
  finishing_time.reverse();			#reverse the finsihing times so as to start from last.
  DFS_start(graph2,False);			#second pass
  sizes.sort();					
  print sizes
  