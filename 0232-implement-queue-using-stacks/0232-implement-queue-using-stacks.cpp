class MyQueue
{
    private:
        stack<int> input;  // Stack for pushing elements
        stack<int> output; // Stack for popping/peeking elements

    public:
        MyQueue() {
            // No need for initialization as stacks are already empty
        }

        void push(int x) {
            input.push(x); // Push directly to the input stack
        }

        int pop() {
            peek(); // Ensure the output stack is ready
            int topElement = output.top();
            output.pop();
            return topElement;
        }

        int peek() {
            // If the output stack is empty, transfer elements from the input stack
            if (output.empty()) {
                while (!input.empty()) {
                    output.push(input.top());
                    input.pop();
                }
            }
            return output.top();
        }

        bool empty() {
            // Queue is empty if both stacks are empty
            return input.empty() && output.empty();
        }
};

/*
I have one input stack, onto which I push the incoming elements, and one output stack, from which I peek/pop. I move elements from input stack to output stack when needed, i.e., when I need to peek/pop but the output stack is empty. When that happens, I move all elements from input to output stack, thereby reversing the order so it's the correct order for peek/pop.

The loop in peek does the moving from input to output stack. Each element only ever gets moved like that once, though, and only after we already spent time pushing it, so the overall amortized cost for each operation is O(1).*/
/**
 *Your MyQueue object will be instantiated and called as such:
 *MyQueue* obj = new MyQueue();
 *obj->push(x);
 *int param_2 = obj->pop();
 *int param_3 = obj->peek();
 *bool param_4 = obj->empty();
 */