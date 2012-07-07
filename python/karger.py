#! /usr/bin/env python
# -*- coding: iso-8859-1 -*-

"""This module calculates the minimum cut by a random selection of two points vertices in an undirected graph"""

import random;

min=10000000;

def readinput():
  try:
    inp=open("kargerMinCut.txt","r");
    rowlist=[]
    for line in inp.readlines():
      graphrow=line.split()
      for x in range(0,len(graphrow)):
	graphrow[x]= int (graphrow[x]);
      graphrow[0]=[graphrow[0],len(graphrow)-1]
      rowlist.append(graphrow)
    inp.close();
    return rowlist;
  except:
    return "File not found"
      
    
def find_mincut(graph_und):
 try:
  while(len(graph_und)>2):
#	select a random edge  
    vertex1=random.randrange(0,len(graph_und)-1);
    vertexval=graph_und[vertex1][0][0];
    vertex2val=vertexval;
    while(vertexval==vertex2val):
      if(graph_und[vertex1][0][1]-1>1):
	vertex2=random.randrange(1,graph_und[vertex1][0][1]-1);
      else:
	vertex2=1;
      vertex2val=graph_und[vertex1][vertex2];
    
    for edge in range(0,len(graph_und)):
      if(vertex2val==graph_und[edge][0][0]):
	vertex2=edge;
	break;
#   	merge the two vertices
    graph_und[vertex1].extend(graph_und[vertex2][1:]);
    graph_und[vertex1].remove(vertex2val)
    graph_und[vertex1].remove(vertexval)
    graph_und[vertex1][0][1]=len(graph_und[vertex1])-1;
    
    graph_und.remove(graph_und[vertex2])
    
    for row in graph_und:
      while(row.count(vertex2val)>0):
	row.remove(vertex2val);
	row.append(vertexval);
  while(graph_und[1].count(graph_und[1][0][0])>0):
    graph_und[1].remove(graph_und[1][0][0]);
  while(graph_und[0].count(graph_und[0][0][0])>0):
    graph_und[0].remove(graph_und[0][0][0]);
  print graph_und[0]  	  
  return len(graph_und[1])-1,len(graph_und[0])-1;
 except:
   print "error"
   print graph_und[vertex1]
   
def testgraph():
  list_test=[];
  row1=[[1,3],2,3,4];
  row2=[[2,3],1,3,4];
  row3=[[3,3],1,2,4];
  row4=[[4,3],2,3,1];
  row5=[[5,4],3,4,6,2];
  row6=[[6,2],4,5];
  list_test.append(row1);
  list_test.append(row2);
  list_test.append(row3);
  list_test.append(row4);
  #list_test.append(row5);
  #list_test.append(row6);
  print find_mincut(list_test);
  
  
  
if(__name__=="__main__"):
  
  min=1000000000000000;
  
 
  """
   temp=readinput()
    mincut=find_mincut(temp);
    if(min>mincut):
      min=mincut;
    print min;  
  print min;
  """
  graph=readinput();
  print find_mincut(graph);
  for i in range(1,11):
    graph=readinput();
    print find_mincut(graph);