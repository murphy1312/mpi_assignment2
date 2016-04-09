# mpi_assignment2
In this assignment you will be tasked with performing a statistical analysis of a set
of numbers. You are required to calculate the mean and then calculate the standard
deviation of the set of numbers. However in this case you will be required to generate all
numbers on the first node and using the broadcast and scatter commands you will
distribute this data to all nodes that are participating.
Once the numbers have been scattered you will be required to calculate an overall
mean for the dataset. However, as there are multiple mean values you must use a reduce
command to recieve those values on a coordinator node. It will calculate the overall mean
and once calculated will broadcast this back to all nodes for calculating the standard
deviation. The results are then reduced on the coordinator node again to compute an
overall standard deviation.
