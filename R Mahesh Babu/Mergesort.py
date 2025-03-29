class Node:
    def _init_(self, val):
        self.val = val
        self.next = None

def merge_sort(head):
    if not head or not head.next:
        return head
    
    slow, fast = head, head.next
    while fast and fast.next:
        slow, fast = slow.next, fast.next.next
    mid, right = slow, slow.next
    slow.next = None 
    return merge(merge_sort(head), merge_sort(right))

def merge(l, r):
    dummy = Node(0)
    tail = dummy
    while l and r:
        if l.val <= r.val:
            tail.next, l = l, l.next
        else:
            tail.next, r = r, r.next
        tail = tail.next
    tail.next = l or r
    return dummy.next

def print_list(head):
    while head:
        print(head.val, end=" -> ")
        head = head.next
    print("None")


head = Node(8)
head.next = Node(3)
head.next.next = Node(1)
head.next.next.next = Node(7)
head.next.next.next.next = Node(0)
head.next.next.next.next.next = Node(10)
head.next.next.next.next.next.next = Node(2)

print("Original Linked List:")
print_list(head)

head = merge_sort(head)

print("Sorted Linked List:")
print_list(head)
