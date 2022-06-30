
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    def __lt__(self, listNode):
        return listNode.val < self.val

class Solution:

    # for each iteration create a 
    def mergeKLists(self, lists: list[ListNode]) -> ListNode:
        if len(lists) < 1:
            return None
        while len(lists) > 1: 
            odd = True if len(lists) % 2 == 1 else False
            last_item = lists[-1] if odd else None
            number_of_pairs = int(len(lists) / 2) if odd else (int(len(lists) / 2))
            lists = [self.merge(lists[x*2], lists[(x*2)+1]) for x in range(number_of_pairs)]
            if odd :
                lists.append(last_item)
        return lists[0]

        
    def merge(self, head1: ListNode, head2: ListNode) -> ListNode:
        if head1 is None:
            return head2
        if head2 is None:
            return head1
        if head1.val < head2.val:
            merged_current = head1
            head1 = head1.next
        else:
            merged_current = head2
            head2 = head2.next
        merged_head = merged_current
        while head1 is not None or head2 is not None:
            if head1 is None:
                merged_current.next = head2
                merged_current = merged_current.next
                head2 = head2.next
                continue
            if head2 is None:
                merged_current.next = head1
                merged_current = merged_current.next
                head1 = head1.next
                continue
            if head1.val <= head2.val:
                merged_current.next = head1
                head1 = head1.next
            else:
                merged_current.next = head2
                head2 = head2.next
            merged_current = merged_current.next
        return merged_head
            
                


#[[],[-1,5,11],[],[6,10]]


if __name__ == '__main__':
    sol = Solution()
    head1 = ListNode(1, ListNode(4, ListNode(5)))
    head2 = ListNode(1, ListNode(3, ListNode(4)))
    head3 = ListNode(2, ListNode(6))
    resultHead = sol.mergeKLists([None, ListNode(-1, ListNode(5, ListNode(11))), None, ListNode(6, ListNode(10))])
    resultList = []
    while resultHead is not None:
        resultList.append(resultHead.val)
        resultHead = resultHead.next
    print(resultList)

