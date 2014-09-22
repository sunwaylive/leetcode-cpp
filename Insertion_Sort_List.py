class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @return a ListNode
    def insertionSortList(self, head):
        p1 = head
        while p1 != None:
            p2 = p1
            min = p2
            
            while p2.next != None:
                if p2.next.val < min.val:                    
                    min = p2.next
                    min_pre = p2
                p2 = p2.next

            min_pre.next = min.next
            min.next = p1.next
            p1.next = min
            p1 = p1.next
        
#main function
sln = Solution()
result = sln.insertionSortList()        
