#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    double num, result;
    char op;
    string input;

    cout << "Enter first number: ";
    cin >> result;

    while (true)
    {
        cout << "\nCurrent result: " << result << endl;

        cout << "Enter operator (+, -, *, /, ^, %, s) or q to quit:\n";
        cin >> input;

        // Quit
        if (input == "q" || input == "Q")
        {
            cout << "Exiting program.\n";
            cout << "Final result: " << result << endl;
            break;
        }

        op = input[0];

        // sqrt does not need another number
        if (op != 's')
        {
            cout << "Enter next number:\n";
            cin >> num;
        }

        switch (op)
        {
        case '+':
            result += num;
            break;

        case '-':
            result -= num;
            break;

        case '*':
            result *= num;
            break;

        case '/':
            if (num != 0)
            {
                result /= num;
            }
            else
            {
                cout << "Division by zero is not allowed.\n";
                continue;
            }
            break;

        case '^':
            result = pow(result, num);
            break;

        case '%':
            // Better modulo for doubles
            result = fmod(result, num);
            break;

        case 's':
            if (result >= 0)
            {
                result = sqrt(result);
            }
            else
            {
                cout << "Cannot sqrt negative number.\n";
                continue;
            }
            break;

        default:
            cout << "Invalid operator.\n";
            continue;
        }

        // Show updated result immediately
        cout << "New result: " << result << endl;
    }

    return 0;
}