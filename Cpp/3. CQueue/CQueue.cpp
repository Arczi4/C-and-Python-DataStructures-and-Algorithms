# include <iostream>
#define ARRAYSIZE(array) (sizeof(array)/sizeof(array[0]))

using namespace std;

class CircularQueue{
    private:
        int f;
        int r;
        int arr[5];
        int itemCount;
    
    public:
        CircularQueue(){
            itemCount = 0;
            f = -1;
            r = -1;
            for(int i=0; i<5; i++){
            arr[i] = 0;
            } 
        }

        bool isEmpty(){
            if (f == -1 && r == -1){
                return true;
            }else{
                return false;
            }
        }

        bool isFull(){
            if ((r + 1) % ARRAYSIZE(arr) == f){
                return true;
            }else{
                return false;
            }
        }

        void enqueue(int val){
            if (isFull()){
                cout << "Queue is full" << endl;
                return;
            }else if (isEmpty()){
                r = 0;
                f = 0;
                arr[r] = val;
                itemCount++;
            }
            else {
                r = (r + 1) % ARRAYSIZE(arr);
                arr[r] = val;
                itemCount++;

            }
        }

        int dequeue(){
            int deq;
            if (isEmpty()){
                cout << "Queue is empty" << endl;
                return 0;
            }else if (r == f){
                deq = arr[r];
                r = -1;
                f = -1;
                itemCount--;
                return deq;
            }else{
                deq = arr[f];
                arr[f] = 0;
                f = (f + 1) % ARRAYSIZE(arr);
                itemCount--;
                return deq;
            }
        }

        int count(){
            return itemCount;
        }

        void display(){
            for (int i=0; i<ARRAYSIZE(arr); i++){
                cout << arr[i] << ", ";
            }
            cout << endl;
        }
};


int main(){

    CircularQueue q;
    int op, val;
    do{
        cout << "1. enqueue" << endl;
        cout << "2. dequeue" << endl;
        cout << "3. isEmpty" << endl;
        cout << "4. isFull" << endl;
        cout << "5. count" << endl;
        cout << "6. display" << endl;
        cout << "7. clear screen" << endl;

        cin >> op;
        switch (op)
        {
        case 1:
            cin >> val;
            q.enqueue(val);
            break;
        
        case 2:
            cout << "Dequeued value " << q.dequeue() << endl;
            break;
        
        case 3:
            if (q.isEmpty()){
                cout << "Empty" << endl;
            }else{
                cout << "Not empty" << endl;
            }
            break;
        
        case 4:
        if (q.isFull()){
                cout << "Full" << endl;
            }else{
                cout << "Not full" << endl;
            }
            break;
        
        case 5:
            cout << "Count " << q.count() << endl;
            break;
        
        case 6:
            q.display();
            break;
        
        case 7:
            system("cls");
            break;
        
        case 0:
            return 0;
        
        default:
            cout << "Enter proper option" << endl;
            break;
        }
        
    }while(op != 0);

    return 0;
}