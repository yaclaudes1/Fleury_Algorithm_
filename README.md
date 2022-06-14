# Fleury_Algorithm_
#

Allows for the arbitrary eularian trail to be outputted by the algorithm. The input file included takes the following graph as an adjacency matrix:  

                        
                        
                                                                      A
                                                                    /    \ 
                                                                   /      \
                                                                  B  ____  D  
                                                                 / \      /  \
                                                                /   \    /    \
                                                               /      C        \
                                                              /                 \
                                                             E                   I 
                                                          /  |  \             /  |  \   
                                                         /   |   \           /   |   \
                                                        F    |    H         J    |    L    
                                                         \   |   /           \   |   /
                                                          \  |  /             \  |  /
                                                             G _________________ K  
                 
                 
    Special care must be taken to account for bridge cases. A bridge in a connected graph is an edge when removed produces a disconnected graph:  
    
    
                                D  
                                 \               Removing edge DI produces two disconnected graphs:   D              
                                  \                              
                                   \
                                    \
                                     I                                                                            I  
    
    
    The solution provided takes care of bridges using the feature known as an ear decomposition, a byproduct of a depth first search utilizing a stack.
    
