import numpy as np
import networkx as nx
import matplotlib.pyplot as plt


class PathPlanning:
    def __init__(self, screws):
        self.originalScrews = screws
        self.copyScrews = np.array(screws)

    def removeAngles(self):
        self.copyScrews = np.array([[self.copyScrews[i][j] for j in range(3)] for i in range(len(self.copyScrews))])
    
    def setAdjacencyMatrix(self):
        adj_matrix = [[j for j in range(len(self.copyScrews))] for i in range(len(self.copyScrews))] 
        for i in range(len(self.copyScrews)):
            for j in range(len(self.copyScrews)):
                adj_matrix[i][j] = np.linalg.norm(self.copyScrews[i] - self.copyScrews[j])
        self.adj_matrix = np.around(np.array(adj_matrix), decimals=2)
    
    def buildGraph(self):
        self.graph = nx.from_numpy_array(self.adj_matrix)
        self.pos = nx.spring_layout(self.graph)
        self.labels = nx.get_edge_attributes(self.graph,'weight')

    def getOptimalPath(self):
        self.removeAngles()
        self.setAdjacencyMatrix()
        self.buildGraph()
        optimalPath = self.applyTSP()
        return optimalPath

    def applyTSP(self):
        tsp = nx.approximation.traveling_salesman_problem
        x = tsp(self.graph, cycle=False)
        return [self.originalScrews[i] for i in x]

    
                

        

    
if __name__ == "__main__":
    screws = [[1,2,3,5,5,5], [4,4,4,5,5,5] , [30,31,32,5,5,5], [50,55,55,5,5,5] , [2,2,3,5,5,5], [4,4,5,5,5,5]]
    pathPlanning = PathPlanning(screws=screws)
    print(pathPlanning.getOptimalPath())
