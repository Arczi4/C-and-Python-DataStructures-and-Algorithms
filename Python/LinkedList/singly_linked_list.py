class Node:
    def __init__(self, key: int = 0, value: int = 0):
        self.key = key
        self.value = value
        self.next = None


class SinglyLinkedList:
    def __init__(self, head: Node = None):
        self.head = head

    def find_node(self, key):
        current_head = self.head
        while current_head is not None:
            if current_head.key == key:
                return current_head

            current_head = current_head.next

        return None

    def find_last_node(self) -> Node:
        current_head = self.head

        while current_head.next is not None:
            current_head = current_head.next

        return current_head

    def check_if_node_exist(self, node) -> bool:
        if self.find_node(node.key) is not None:
            return True
        return False

    def append_node(self, node: Node) -> None:
        if self.find_node(node.key) is not None:
            print(f"Node already exist with same key value!")
        else:
            if self.head is None:
                self.head = node
                print("append successfully")
            else:
                last_node = self.find_last_node()
                last_node.next = node
                print("append successfully")

    def prepend_node(self, node: Node) -> None:
        node_exist = self.check_if_node_exist(node)

        if not node_exist:
            node.next = self.head
            self.head = node
            print("Prepend successfully")

    def show_linked_list(self):
        current_head = self.head
        print("Linked List:")
        while current_head is not None:
            print(f"({current_head.key}: {current_head.value}) --> ", end=" ")
            current_head = current_head.next

    def insert_node_after(self):
        pass

    def delete_node(self):
        pass

    def update_node(self):
        pass

n1 = Node(1, 1)
n2 = Node(2, 2)
n3 = Node(3, 3)
n4 = Node(4, 4)
n5 = Node(5, 5)

linked_list = SinglyLinkedList()
linked_list.append_node(n1)
linked_list.append_node(n2)
linked_list.prepend_node(n5)
linked_list.append_node(n3)
linked_list.append_node(n4)

linked_list.show_linked_list()

