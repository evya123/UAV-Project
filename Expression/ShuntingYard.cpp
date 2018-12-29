
#include "ShuntingYard.h"

/**
 * get numbers and return after the algorithm the result in dubble
 * @param tokens - a string seperated by spaces
 */
ShuntingYard::ShuntingYard(const string &tokens) : tokens(tokens) {}

/**
 * Function to find precedence of operators.
 * @param op the operation
 * @return nothing
 */
double ShuntingYard::precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

/**
 * function that uses Expressions to calculate the values
 * @param first Expression
 * @param second  Expression
 * @param op - operation
 * @return the result in double
 */
double ShuntingYard::applyOp(double first, double second, char op) {
    Expression *aEx = new Num(first);
    Expression *bEx = new Num(second);
    switch (op) {

        case '+':
            return (new Plus(aEx, bEx))->calculate();
        case '-':
            return (new Minus(aEx, bEx))->calculate();
        case '*':
            return (new Mult(aEx, bEx))->calculate();
        case '/':
            return (new Div(aEx, bEx))->calculate();
    }
}

/**returns value of expression after evaluation
 *
 * @return value of expression after evaluation
 */
double ShuntingYard::evaluate() {
    int i = 0;
    bool wasOperation = false;

    // stack to store integer values.
    stack<double> values;

    // stack to store operators.
    stack<char> ops;
    double isNeg = 1;

    for (i = 0; i < tokens.length(); i++) {

        // Current token is a whitespace,
        // skip it.
        if (tokens[i] == ' ')
            continue;

            // Current token is an opening
            // brace, push it to 'ops'
        else if (tokens[i] == '(') {
            ops.push(tokens[i]);
        }

            // Current token is a number, push
            // it to stack for numbers.
        else if (isdigit(tokens[i]) || !wasOperation) {
            double val = 0;
            double decimal = 10;
            bool afterPoint = false;

            if (tokens[i] == '-') {
                isNeg *= -1;
                continue;
            }

            // There may be more than one
            // digits in number.
            while (i < tokens.length() &&
                   (isdigit(tokens[i]) || tokens[i] == '.')) {
                if (tokens[i] == '.') {
                    afterPoint = true;
                } else {
                    if (!afterPoint)
                        val = (val * 10) + (tokens[i] - '0');
                    else {
                        val += (tokens[i] - '0') / decimal;
                        decimal *= 10;
                    }
                }
                i++;
            }
            wasOperation = true;
            val *= isNeg;
            values.push(val);
            isNeg = 1;
        }
            // Closing brace encountered, solve
            // entire brace.
        else if (tokens[i] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                double val2 = values.top();
                values.pop();
                double val1 = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            // pop opening brace.
            ops.pop();
        }
            // Current token is an operator.
        else {
            // there wasn't operation before
            wasOperation = false;
            // While top of 'ops' has same or greater
            // precedence to current token, which
            // is an operator. Apply operator on top
            // of 'ops' to top two elements in values stack.
            while (!ops.empty() && precedence(ops.top())
                                   >= precedence(tokens[i])) {
                double val2 = values.top();
                values.pop();

                double val1 = values.top();
                values.pop();


                char op = ops.top();
                ops.pop();

                values.push(applyOp(val1, val2, op));
            }

            // Push current token to 'ops'.
            ops.push(tokens[i]);
        }
    }
    // Entire expression has been parsed at this
    // point, apply remaining ops to remaining
    // values.
    while (!ops.empty()) {
        double val2 = values.top();
        values.pop();

        double val1 = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOp(val1, val2, op));
    }

    // Top of 'values' contains result, return it.
    return values.top();
}
