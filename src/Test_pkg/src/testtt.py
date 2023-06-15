import rospy
tet=[]
tet.append([2,3,4])
tet.append([2,3,4])
#flat a list of lists
tet = [item for sublist in tet for item in sublist]
print(tet)