# include <iostream>
# include <string>

using namespace std;

class Stack{
    private:
        int top;
        int arr[5];

    public:
        Stack(){
            // Initialization
            top = -1;

            // Set all values in arr to 0
            for(int i=0; i<5; i++){
                arr[i] = 0;
            }
        }

        bool isEmpty(){
            if(top == -1)
                return true;
            else
                return false;
        }

        bool isFull(){
            if(top == 4)
                return true;
            else
                return false;
        }

        void push(int value){
            if(!isFull()){
                top++;
                arr[top] = value;
            }else{
                cout << "Stack overflow!" << endl;
            }
        }

        int pop(){
            if(isEmpty()){
                cout << "Stack underflow" << endl;
                return 0;
            }else{
                int popValue = arr[top];
                arr[top] = 0;
                top--;
                return popValue;
            }
        }

        int peek(int pos){
            if(isEmpty()){
                cout << "Stack underflow" << endl;
                return 0;
            }else{
                return arr[pos];
            }
        }

        void change(int pos, int value){
            arr[pos] = value;
            cout << "Changed item on position " << pos << "to " << value << endl;
        }

        void display(){
            for(int i=4; i>=0; i--){
                cout << arr[i] << endl;
            }
        }

        int count(){
            return top + 1;
        }
};

int main(){

    Stack s;
    int op, pos, val;
    do{
        cout << "1. push" << endl;
        cout << "2. pop" << endl;
        cout << "3. isEmpty" << endl;
        cout << "4. isFull" << endl;
        cout << "5. peek" << endl;
        cout << "6. count" << endl;
        cout << "7. change" << endl;
        cout << "8. display" << endl;
        cout << "9. clear" << endl;
        cout << "0. EXIT" << endl;

        cin >> op;
        switch (op)
        {
        case 1:
            cout << "Push new value to the stack"<< endl;
            cin >> val;
            s.push(val);
            break;
        
        case 2:
            cout << "Pop value from the stack"<< s.pop() << endl;
            break;
        
        case 3:
            if(s.isEmpty()){
                cout << "Empty" << endl;
            }else{
                cout << "Not empty" << endl;
            }

            break;
        
        case 4:
            if(s.isFull()){
                cout << "Full" << endl;
            }else{
                cout << "Not full" << endl;
            }
            break;
        
        case 5:
            cout << "Enter pos of item: " << endl;
            cin >> pos;
            cout << pos << "->" << s.peek(pos) << endl;
            break;
        
        case 6:
            cout << "Number of items in the stack: " << s.count() << endl;
            break;
        
        case 7:
            cout << "Enter the pos of item to change" << endl;
            cin >> pos;
            cout << endl;

            cout << "Enter new value" << endl;
            cin >> val;
            s.change(pos, val);

            break;
        
        case 8:
            cout << "Items in the stack" << endl;
            s.display();
            break;
        
        case 9:
            system("cls");
            break;
        
        case 0:
            return 0;
        
        default:
            cout << "Enter proper number" << endl;
            break;
        }
        
    }while(op != 0);

    return 0;
}