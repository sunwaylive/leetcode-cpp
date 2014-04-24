class Solution:
    def evalRPN(self, tokens):
        operand_stack = []
        for t in tokens:
            if t == '+':
                second_operand = operand_stack.pop()
                first_operand = operand_stack.pop()
                operand_stack.append(int(float(first_operand) + second_operand))
            elif t == '-':
                second_operand = operand_stack.pop()
                first_operand = operand_stack.pop()
                operand_stack.append(int(float(first_operand) - second_operand))
            elif t == '*':
                second_operand = operand_stack.pop()
                first_operand = operand_stack.pop()
                operand_stack.append(int(float(first_operand) * second_operand))
            elif t == '/':
                second_operand = operand_stack.pop()
                first_operand = operand_stack.pop()
                if second_operand == 0.0:
                    continue;
                else:
                    operand_stack.append(int(float(first_operand) / second_operand))
            else:
                operand_stack.append(int(t))
        return operand_stack.pop()

#main function
sln = Solution()
tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
#tokens = ["18"]
#tokens = ["4","13","5","/","+"]
result = sln.evalRPN(tokens)
print(result)
