class Point:
    def __init__(self, a = 0, b = 0):
        self.x = a
        self.y = b
    
class Solution:
    def maxPoints(self, points):
        if len(points) <= 1:
            return len(points)
            
        max_num = 0
        for i in range(len(points)):            
            p1 = points[i]
            islope = {}
            iVertical = 0
            iSame = 0
            iMax = 0
            for j in range(i+1, len(points)):
                p2 = points[j]
                if p1.x == p2.x:
                    if p1.y == p2.y:
                        iSame += 1
                    else:
                        iVertical += 1                    
                else:
                    k = (p1.y - p2.y) * 1.0 / (p1.x - p2.x)
                    if k in islope.keys():
                        islope[k] += 1
                    else:
                        islope[k] = 1
                    iMax = max(iMax, islope[k])
            iMax = max(iMax, iVertical) + iSame
            max_num = max(iMax, max_num)
        return max_num + 1

#main function
sln = Solution()
input_list = [(-54,-297),(-36,-222),(3,-2),(30,53),(-5,1),(-36,-222),(0,2),(1,3),(6,-47),(0,4),(2,3),(5,0),(48,128),(24,28),(0,-5),(48,128),(-12,-122),(-54,-297),(-42,-247),(-5,0),(2,4),(0,0),(54,153),(-30,-197),(4,5),(4,3),(-42,-247),(6,-47),(-60,-322),(-4,-2),(-18,-147),(6,-47),(60,178),(30,53),(-5,3),(-42,-247),(2,-2),(12,-22),(24,28),(0,-72),(3,-4),(-60,-322),(48,128),(0,-72),(-5,3),(5,5),(-24,-172),(-48,-272),(36,78),(-3,3)]
point_list = []
for e in input_list:
    p = Point(e[0], e[1])
    point_list.append(p)
result = sln.maxPoints(point_list)
print(result)
