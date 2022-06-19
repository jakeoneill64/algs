
from typing import List


class ListNode:
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next

class Solution:

    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        end = head
        end_index = 0
        pointer = head
        pointer_index = 0
        while end.next is not None:
            end_index += 1
            end = end.next
            if not end_index - pointer_index <= n: 
                pointer_index += 1
                pointer = pointer.next
        if not end_index - n + 1 > 0:
            return head.next
        pointer.next = pointer.next.next
        return head

        
                
if __name__ == '__main__':
    sol = Solution()
    items = [1,2]
    items.reverse()
    head = None
    for item in items:
        head = ListNode(item, head)
    new_head = sol.removeNthFromEnd(head, 2)
    output = [new_head.val]
    while new_head.next is not None:
        new_head = new_head.next
        output.append(new_head.val)
    print(output)
    



            


























        

    
    

