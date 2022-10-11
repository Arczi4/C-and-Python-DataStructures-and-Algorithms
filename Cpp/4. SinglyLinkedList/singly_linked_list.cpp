# include <iostream>
using namespace std;

class Node{
    public:
        int key;
        int data;
        Node *next;

        Node(){
            key = 0;
            data = 0;
            next = NULL;
        }

        Node(int k, int d){
            key = k;
            data = d;
        }
};


class SinglyLikedList{
    public:
        Node *head;

        SinglyLikedList(){
            head = NULL;
        }

        SinglyLikedList(Node *n){ // Passing an address of object
            head = n; // Storing an adress of the node
        }

        // Checks if node exists using key value
        // method that returns a pointer
        Node *nodeExists(int k){
            Node *tmp = NULL;
            Node *ptr = head;

            while(ptr != NULL){
                if(ptr->key == k){
                    tmp = ptr;
                }
                ptr = ptr->next;
            }
            return tmp;
        }

        // Append a node
        void appendNode(Node *n){
            if(nodeExists(n->key) != NULL){
                cout << "Node exists with key value: " << n->key << endl;
            }else{
                // If there is no node in list
                if(head == NULL){
                    head = n;
                    cout << "Append successfull" << endl;
                }else{
                    Node *ptr = head;
                    while(ptr->next != NULL){
                        ptr = ptr->next;
                    }
                    
                    ptr->next = n;
                    cout << "Append successfull" << endl;
                }
            }
        }

        void prependNode(Node* n){
            if(nodeExists(n->key) != NULL){
                cout << "Node exists with key value: " << n->key << endl;
            }else{
                n->next = head;
                head = n;
                cout << "Prepend successfully" << endl;
            }
        }
        
        // Inserting node after:
        void insertNode(Node* n, int k){
            Node* ptr = nodeExists(k);
            
            if(ptr != NULL){
                if(nodeExists(n->key) != NULL){
                    cout << "Node exists with key value: " << n->key << endl;
                }else{
                    n->next = ptr->next;
                    ptr->next = n; 
                }

            }else{
                cout << "Node doesn't exist with key = " << k << endl;
            }
        }

        void deleteNodeByKey(int k){
            if(head == NULL){
                cout << "SLL is already empty" << endl;
            } else if (head != NULL){
                if (head->key == k){
                    head = head->next;
                    cout << "Unliked node with key value: " << k << endl;
                } else{
                    Node *temp = NULL;
                    Node *previousPtr = head;
                    Node *currentPtr = head->next;

                    while(currentPtr != NULL){
                        if(currentPtr->key == k){
                            temp = currentPtr;
                            currentPtr = NULL;
                        } else{
                            previousPtr = previousPtr->next;
                            currentPtr = currentPtr->next;
                        }
                    }

                    if(temp != NULL){
                        previousPtr->next = temp->next;
                        cout << "Unliked node with key value: " << k << endl;

                    }else {
                        cout << "Node doesn't exist with key = " << k << endl;
                    }
                }
            }
        }

        void updateNodeByKey(int k, int new_data){
            Node *ptr = nodeExists(k);

            if(ptr != NULL){
                ptr->data = new_data;
                cout << "Node data with key: " << k << " has been updated successfully with value: " << new_data << endl;
            }else {
                cout << "Node doesn't exist with key = " << k << endl;
            }
        }

        void printList(){
            if(head == NULL){
                cout << "No Nodes" << endl;
            }else{
                cout << "SS values:" << endl;
                Node *temp = head;

                while(temp != NULL){
                    cout << temp->key << ":" << temp->data << "--->";
                    temp = temp->next;
                }
                cout << endl;
            }

        }
};


int main(){

    SinglyLikedList s;
    int op;
    int key1, k1, data1;

    do{
        cout << "1. append node" << endl; 
        cout << "2. prepend node" << endl;
        cout << "3. insert node after" << endl;
        cout << "4. delete node by key"<< endl;
        cout << "5. update node by key" << endl;
        cout << "6. print nodes" << endl;
        cout << "7. clear screen" << endl;

        Node *n1 = new Node();

        cin >> op;
        switch (op)
        {
        case 1:
            cout << "Enter node data: " << endl;;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;

            s.appendNode(n1);
            break;
        
        case 2:
            cout << "Enter node data: " << endl;;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;

            s.prependNode(n1);
            break;
        
        case 3:
            cout << "key: ";
            cin >> k1;
            
            cout << "Enter node data: " << endl;;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;

            s.insertNode(n1, k1);
            break;
        
        case 4:
            cout << "key: ";
            cin >> k1;
            s.deleteNodeByKey(k1);
            break;
        
        case 5:
            cout << "key: ";
            cin >> key1;
            cin >> data1;

            s.updateNodeByKey(key1, data1);
            break;
        
        case 6:
            s.printList();
            break;
        
        case 7:
            system("cls");
            break;
        
        case 0:
            return 0;
        
        default:
            cout << "Eneter proper number" << endl;
            break;
        }
        
    }while(op != 0);

    return 0;
}