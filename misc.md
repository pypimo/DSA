# postfix (reverese polish notation)
1. read exp from left to right
2. if operand append to stack
3. if operator, pop two operands from stack, but 1st pop is y, 2nd is x
4. evaluate x operator y --> append to stack
5. continue till string ends, return stack.top()
https://leetcode.com/problems/evaluate-reverse-polish-notation

## postfix to infix

## infix to postfix
