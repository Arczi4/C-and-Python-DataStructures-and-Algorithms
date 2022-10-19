class Node:
    def __init__(self, key: int = 0, value: int = 0):
        self.key = key
        self.value = value
        self.next = None


class SinglyLinkedList:
    def __init__(self, head: Node = None):
        self.head = head

    def find_node(self, key):
        '''
        Find node by passed key
        :param key:
        :return: if node exist returns node else None
        '''
        current_head = self.head
        while current_head is not None:
            if current_head.key == key:
                return current_head

            current_head = current_head.next

        return None

    def find_previous_and_next(self, key: int) -> (Node, Node):
        '''
        :param key: node's key between previous and next
        :return: Tuple (Node, Node) if function find node with key
        '''

        current_head = self.head
        previous_node = None

        while current_head is not None:
            if current_head.key == key:
                return previous_node, current_head.next
            else:
                previous_node = current_head
                current_head = current_head.next

    def find_last_node(self) -> Node:
        current_head = self.head

        while current_head.next is not None:
            current_head = current_head.next

        return current_head

    def check_if_node_exist(self, key: int) -> bool:
        return True if self.find_node(key) is not None else False

    def append_node(self, node: Node) -> None:
        if self.find_node(node.key) is not None:
            print(f"Node already exist with same key value!")
        else:
            if self.head is None:
                self.head = node
                print(f"Append Node with key: {node.key} successfully")
            else:
                last_node = self.find_last_node()
                last_node.next = node
                print(f"Append Node with key: {node.key} successfully")

    def prepend_node(self, node: Node) -> None:
        node_exist = self.check_if_node_exist(node.key)

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

    def insert_node_after(self, node: Node, key: int):
        node_exist = self.find_node(key)

        if node_exist:
            if self.find_node(node.key):
                print(f"Node already exist with same key value!")
            else:
                node.next = node_exist.next
                node_exist.next = node
                print(f"Inserted Node with key: {key} successfully")
        else:
            print(f"Node with key: {key} doesn't exist")

    def delete_node(self, key: int):
        current_node = self.find_node(key)

        if current_node:
            previous_node, next_node = self.find_previous_and_next(key)
            if previous_node is not None:  # if it's not head
                previous_node.next = current_node.next
            else:  # if it's head of Linked List
                self.head = self.head.next
            print(f"Node with key: {key} deleted successfully")
        else:
            print(f"Node with key: {key} doesn't exist")

    def update_node(self, key: int, new_value: int):
        current_node = self.find_node(key)

        if current_node is not None:
            current_node.value = new_value
            print(f"Node with key: {key} updated successfully with value {new_value}")
        else:
            print(f"Node with key: {key} doesn't exist")


n1 = Node(1, 1)
n2 = Node(2, 2)
n3 = Node(3, 3)
n4 = Node(4, 4)
n5 = Node(5, 5)
n6 = Node(6, 6)
n7 = Node(7, 7)
linked_list = SinglyLinkedList()
linked_list.append_node(n1)
linked_list.append_node(n2)
linked_list.prepend_node(n5)  # Head
linked_list.insert_node_after(n6, n5.key)
linked_list.append_node(n3)
linked_list.append_node(n4)
linked_list.delete_node(n4.key)
linked_list.append_node(n7)
linked_list.update_node(n7.key, 200)

# linked_list.delete_node(n3.key)
# linked_list.delete_node(n5.key)

# linked_list.delete_node(10)

linked_list.show_linked_list()
