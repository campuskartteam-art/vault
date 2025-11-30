#include <iostream>
using namespace std;

// Node for polynomial term
class Node {
public:
    int coef;   // coefficient
    int pow;    // power
    Node* next;
    Node(int c, int p) {
        coef = c;
        pow = p;
        next = nullptr;
    }
};

// Insert term at end
void insert(Node*& head, int c, int p) {
    Node* n = new Node(c, p);
    if (!head) {
        head = n;
    } else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
    }
}

// Display polynomial
void display(Node* head) {
    while (head) {
        cout << head->coef << "x^" << head->pow;
        head = head->next;
        if (head) cout << " + ";
    }
    cout << endl;
}

// Add two polynomials
Node* addPoly(Node* p1, Node* p2) {
    Node* result = nullptr;
    Node *a = p1, *b = p2;

    while(a && b) {
        if(a->pow == b->pow) {
            insert(result, a->coef + b->coef, a->pow);
            a = a->next; b = b->next;
        } else if(a->pow > b->pow) {
            insert(result, a->coef, a->pow);
            a = a->next;
        } else {
            insert(result, b->coef, b->pow);
            b = b->next;
        }
    }

    while(a) { insert(result, a->coef, a->pow); a = a->next; }
    while(b) { insert(result, b->coef, b->pow); b = b->next; }

    return result;
}

int main() {
    Node *p1 = nullptr, *p2 = nullptr;

    // Example: Polynomial 1 = 3x^2 + 4x + 2
    insert(p1, 3, 2);
    insert(p1, 4, 1);
    insert(p1, 2, 0);

    // Example: Polynomial 2 = 5x^2 + 2x + 1
    insert(p2, 5, 2);
    insert(p2, 2, 1);
    insert(p2, 1, 0);

    cout << "Polynomial 1: ";
    display(p1);

    cout << "Polynomial 2: ";
    display(p2);

    Node* sum = addPoly(p1, p2);
    cout << "Sum: ";
    display(sum);

    return 0;
}


// #include <iostream>
// using namespace std;

// class Node {
// public:
//     int coef, pow;
//     Node* next;
//     Node(int c,int p){ coef=c; pow=p; next=NULL; }
// };

// void insert(Node*& head,int c,int p){
//     Node* n=new Node(c,p);
//     if(!head) head=n;
//     else{
//         Node* t=head;
//         while(t->next) t=t->next;
//         t->next=n;
//     }
// }

// Node* addPoly(Node* a,Node* b){
//     Node* res=NULL;
//     while(a && b){
//         if(a->pow==b->pow){
//             insert(res,a->coef+b->coef,a->pow);
//             a=a->next; b=b->next;
//         }
//         else if(a->pow>b->pow){
//             insert(res,a->coef,a->pow);
//             a=a->next;
//         } else{
//             insert(res,b->coef,b->pow);
//             b=b->next;
//         }
//     }
//     while(a){ insert(res,a->coef,a->pow); a=a->next; }
//     while(b){ insert(res,b->coef,b->pow); b=b->next; }

//     return res;
// }

// void show(Node* head){
//     while(head){
//         cout<<head->coef<<"x^"<<head->pow;
//         head=head->next;
//         if(head) cout<<" + ";
//     }
//     cout<<"\n";
// }

// int main(){
//     Node *p1=NULL,*p2=NULL;

//     insert(p1,3,2); insert(p1,4,1); insert(p1,2,0); // 3x²+4x+2
//     insert(p2,5,2); insert(p2,2,1); insert(p2,1,0); // 5x²+2x+1

//     cout<<"P1 = "; show(p1);
//     cout<<"P2 = "; show(p2);

//     Node* sum=addPoly(p1,p2);
//     cout<<"\nSUM = "; show(sum);
// }

// ✅ Algorithm (Polynomial Addition using Linked List)

// Start
// Initialize two polynomial linked lists p1 and p2
// Insert terms into p1 and p2 in decreasing order of power
// Display both polynomials
// To add both polynomials:
// Create a new linked list result
// Traverse lists a = p1 and b = p2
// While both lists have terms:
// If powers are equal → add coefficients, insert into result, advance both
// If power of a > power of b → insert a term into result, advance a
// Else → insert b term into result, advance b
// If remaining terms exist in a → insert all into result
// If remaining terms exist in b → insert all into result
// Display the result polynomial
// Stop

// 📌 Pseudocode
// FUNCTION Insert(head, coefficient, power)
//     CREATE new node with coefficient and power
//     IF head is NULL
//         head = new node
//     ELSE
//         temp = head
//         WHILE temp.next is not NULL
//             temp = temp.next
//         END WHILE
//         temp.next = new node
//     END IF
// END FUNCTION

// Polynomial Addition Pseudocode
// FUNCTION AddPoly(p1, p2)
//     result = NULL

//     WHILE p1 != NULL AND p2 != NULL
//         IF p1.power == p2.power
//             Insert(result, p1.coef + p2.coef, p1.power)
//             p1 = p1.next
//             p2 = p2.next

//         ELSE IF p1.power > p2.power
//             Insert(result, p1.coef, p1.power)
//             p1 = p1.next

//         ELSE
//             Insert(result, p2.coef, p2.power)
//             p2 = p2.next
//     END WHILE

//     WHILE p1 != NULL
//         Insert(result, p1.coef, p1.power)
//         p1 = p1.next
//     END WHILE

//     WHILE p2 != NULL
//         Insert(result, p2.coef, p2.power)
//         p2 = p2.next
//     END WHILE

//     RETURN result
// END FUNCTION

// Display Pseudocode
// FUNCTION Display(head)
//     WHILE head != NULL
//         PRINT head.coef, "x^", head.power
//         head = head.next
//         IF head != NULL
//             PRINT " + "
//     END WHILE
// END FUNCTION

// Main Program Pseudocode
// START
// CREATE p1 = NULL, p2 = NULL

// Insert(p1, 3, 2)
// Insert(p1, 4, 1)
// Insert(p1, 2, 0)

// Insert(p2, 5, 2)
// Insert(p2, 2, 1)
// Insert(p2, 1, 0)

// PRINT "Polynomial 1 = "
// Display(p1)

// PRINT "Polynomial 2 = "
// Display(p2)

// sum = AddPoly(p1, p2)

// PRINT "Sum = "
// Display(sum)

// STOP
