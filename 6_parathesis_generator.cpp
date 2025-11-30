#include <iostream>
#include <stack>
#include <string>
using namespace std;

// //6. Implement an expression validator to check for balanced parentheses using a stack. 
// Display valid or invalid based on proper symbol matching. (Hint: Push opening brackets; 
// pop when matching closing bracket appears.)

bool isBalanced(string expr)
{
    stack<char> st;

    for (char ch : expr)
    {
        // Push opening brackets
        if (ch == '(' || ch == '{' || ch == '[')
            st.push(ch);

        // For closing brackets, check for match
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (st.empty())
                return false; // No matching opening bracket

            char top = st.top();
            st.pop();

            // Check pair matching
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
                return false;
        }
    }

    // If stack is empty, brackets are balanced
    return st.empty();
}

int main()
{
    string expression;
    cout << "Enter expression: ";
    cin >> expression;

    if (isBalanced(expression))
        cout << "Valid Expression (Balanced Parentheses)" << endl;
    else
        cout << "Invalid Expression (Unbalanced Parentheses)" << endl;

    return 0;
}


// #include <iostream>
// #include <stack>
// using namespace std;

// // Function to check if two brackets match
// bool isMatching(char open, char close) {
//     return (open == '(' && close == ')') ||
//            (open == '{' && close == '}') ||
//            (open == '[' && close == ']');
// }

// // Function to check balanced parentheses
// bool isBalanced(string expr) {
//     stack<char> s;

//     for(char ch : expr) {
//         // Push opening brackets
//         if(ch == '(' || ch == '{' || ch == '[') {
//             s.push(ch);
//         }
//         // For closing brackets
//         else if(ch == ')' || ch == '}' || ch == ']') {
//             if(s.empty() || !isMatching(s.top(), ch)) {
//                 return false;  // mismatch or nothing to match
//             }
//             s.pop();  // pop the matching opening bracket
//         }
//     }

//     return s.empty();  // valid if no unmatched brackets left
// }

// int main() {
//     string expression;
//     cout << "Enter expression to validate: ";
//     cin >> expression;

//     if(isBalanced(expression))
//         cout << "Expression is VALID (Balanced parentheses)\n";
//     else
//         cout << "Expression is INVALID (Unbalanced parentheses)\n";

//     return 0;
// }

// ✅ Algorithm
// Start
// Read the input string expression
// Create an empty stack
// Traverse each character ch of the expression
// If ch is an opening bracket ((, {, [), push it into stack
// If ch is a closing bracket (), }, ]):
// If stack is empty → return Invalid
// Pop top element from stack
// Check if popped opening bracket matches the closing bracket
// If not matching → return Invalid
// After traversal:
// If stack is empty → expression is Balanced
// Otherwise → expression is Unbalanced
// Display result
// End

// 📝 Pseudocode

// FUNCTION isBalanced(expr)
//     CREATE empty stack st

//     FOR each character ch in expr DO
//         IF ch is '(' or '{' or '[' THEN
//             PUSH ch into st
//         ELSE IF ch is ')' or '}' or ']' THEN
//             IF st is empty THEN
//                 RETURN false
//             END IF

//             top = POP from st

//             IF (ch == ')' AND top != '(') OR
//                (ch == '}' AND top != '{') OR
//                (ch == ']' AND top != '[') THEN
//                 RETURN false
//             END IF
//         END IF
//     END FOR

//     IF st is empty THEN
//         RETURN true
//     ELSE
//         RETURN false
// END FUNCTION


// MAIN
//     INPUT expression

//     IF isBalanced(expression) THEN
//         PRINT "Valid Expression (Balanced Parentheses)"
//     ELSE
//         PRINT "Invalid Expression (Unbalanced Parentheses)"
//     END IF
// END MAIN

