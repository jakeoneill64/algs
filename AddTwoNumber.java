import java.util.List;

public class AddTwoNumber {


      public static class ListNode {
          int val;
          ListNode next;
          ListNode() {}
          ListNode(int val) { this.val = val; }
          ListNode(int val, ListNode next) { this.val = val; this.next = next; }
      }


    public static void main(String[] args){

        ListNode head1 = new ListNode(3);
        head1 = new ListNode(4, head1);
        head1 = new ListNode(2, head1);
        ListNode head2 = new ListNode(4);
        head2 = new ListNode(6, head2);
        head2 = new ListNode(5, head2);
        ListNode head = addTwoNumbers(head1, head2);





    }

    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        boolean carry = false;
        int operand1;
        int operand2;
        int result;
        ListNode head = new ListNode();
        ListNode end = head;
        while(l1 != null || l2 != null) {
            operand1 = l1 != null ? l1.val : 0;
            operand2 = l2 != null ? l2.val : 0;
            result = operand1 + operand2 + Boolean.compare(carry, false);
            carry = false;
            if(result >= 10) {
                carry = true;
                result %= 10;
            }
            end.val = result;
            l1 = l1 != null ? l1.next : l1;
            l2 = l2 != null ? l2.next : l2;
            if(l1 != null || l2 != null) {
                end.next = new ListNode();
                end = end.next;
            }
        }
        if(carry) {
            end.next = new ListNode();
            end.next.val = 1;
        }
        return head;
    }



}
